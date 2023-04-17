<?php
/*
* searcho.inc
выводим страничку поиска на экран
*
*/
include_once('base.inc');
include_once('header.inc');

 $filename="searcho.inc";

function day_to_ua($day_en){
	if($day_en==0) return "Неділя";
	elseif ($day_en==1) return "Понеділок";
	elseif ($day_en==2) return "Вівторок";
	elseif ($day_en==3) return "Середа";
	elseif ($day_en==4) return "Четверг";
	elseif ($day_en==5) return "П'ятниця";
	elseif ($day_en==6) return "Субота";
	else return $day_en."- Невідомий день";
	

}

//рахуемо всього співробітників
$sql_b_today = "SELECT COUNT(*) AS b_today FROM ophone";
$res_b_today = mysqli_query($link, $sql_b_today) or exit('Похибка виконання запиту до БД.25.'.$filename);
$row_b_today = mysqli_fetch_assoc($res_b_today);
$b_today = $row_b_today['b_today'];

//дни рождения сотрудников сегодня 
$sql_birthday = "SELECT *, CURDATE() as today, WEEKDAY(`birthday`) as day, DAYNAME(`birthday`) as dayname   
	FROM ophone, func, office, street, branch
	WHERE office.offid= ophone.offid
	AND street.strid = ophone.strid
	AND func.funid = ophone.funid
	AND branch.branid = ophone.branid
	AND TIMESTAMPDIFF(
		DAY, 
		DATE_ADD(`birthday`, INTERVAL YEAR(NOW())-YEAR(`birthday`) YEAR), 
		NOW()
	) BETWEEN -1 AND 0 ORDER BY MONTH(birthday), DAY(birthday)" ;
	

$res_birthday = mysqli_query($link, $sql_birthday) or exit('Похибка виконання запиту до БД..'.$filename);


//дни рождения сотрудников сегодня и +7 дней от сегодня
$sql_birthday7 = "SELECT *, CURDATE() as today, WEEKDAY(`birthday`) as day, DAYNAME(`birthday`) as dayname   
	FROM ophone, func, office, street, branch
	WHERE office.offid= ophone.offid
	AND street.strid = ophone.strid
	AND func.funid = ophone.funid
	AND branch.branid = ophone.branid
	AND TIMESTAMPDIFF(
		DAY, 
		DATE_ADD(`birthday`, INTERVAL YEAR(NOW())-YEAR(`birthday`) YEAR), 
		NOW()
	) BETWEEN -7 AND -1 ORDER BY MONTH(birthday), DAY(birthday)" ;

$res_birthday7	 = mysqli_query($link, $sql_birthday7) or exit('Похибка виконання запиту до БД..'.$filename);



//название и адрес организации
$sql_office = "SELECT office FROM office WHERE offid='{$value}'";
$res_office = mysqli_query($link, $sql_office) or exit('Похибка виконання запиту до БД..'.$filename);
$row_office = mysqli_fetch_assoc($res_office);
$off = $row_office['office'];


//номера служебных телефонов
$sql = "SELECT id, number, number1, func,  office, branch, branindex, surname, name, patronymic, street, house, flat, note, userMail, sortindex
FROM ophone, func, office, street, branch
WHERE office.offid='{$value}'
AND street.strid = ophone.strid
AND func.funid = ophone.funid
AND branch.branid = ophone.branid
AND (NOT trim(number1)='' OR NOT trim(number)='')
ORDER BY branindex, sortindex ";
//ORDER BY note

?>
<P>
	<?php echo "Сьогодні, ".date('d/m/Y ')." Вітаємо(або готуємось вітати) з " ?>
	<STRONG>
		<?php echo "Днем народження" ?> 
	</STRONG>
	
	: 
</P>
<TABLE WIDTH="100%" CELLPADDING="2" CELLSPACING="1" BORDER="0">
	<TR CLASS="head">
		<TD><?php echo "ПІБ"; ?></TD> <!-- День народження ПІБ-->
		<TD><?php echo "Дата народження" ?></TD> <!--День народження Дата народження-->
		<!--
			<TD><?php //echo "Повних років" ?></TD> <!--День народження Повних років
		-->
		<TD><?php echo "Відділ" ?></TD> <!--День народження Відділ-->
		<TD><?php echo "Посада " ?></TD> <!--День народження Посадада-->
		<!-- <TD><?php echo date('d/m/Y ', strtotime(date('Y/m/d ').'+ 5 days')) ?></TD>  Посадада-->
		<!-- <TD><?php echo date('d/m/Y ', strtotime(date('Y/m/d ').'+ 6 days')) ?></TD>  Посадада-->
		<!-- <TD><?php echo date('d/m/Y ', strtotime(date('Y/m/d ').'+ 7 days')) ?></TD> -->
		</TR>
	<?php
	
  	while ($row_birthday = mysqli_fetch_assoc($res_birthday)) {
	?>	
<TR CLASS="data">
		<TD><!-- День народження ПІБ-->
			<?php echo $row_birthday['surname']." "
				.$row_birthday['name']." "
				.$row_birthday['patronymic']; ?>
		</TD> <!-- День народження ПІБ-->
		
		<TD><!-- День народження Дата народження-->
		<?php echo date('d/m ', strtotime($row_birthday['birthday'])) ?>
		</TD> <!-- День народження Дата народження-->
		
		<!--
		<TD><!-- День народження Повних років
		<?php //echo date('Y/m/d ')-$row_birthday['birthday'] ?>
		</TD> <!-- День народження Повних років
		-->
		
		<TD><!-- День народження Відділ-->
		<?php 
			echo $row_birthday['branch'];
		?>
		</TD> <!-- День народження Відділ-->
		
		<TD><!-- День народження Посада-->
		<?php 
			echo $row_birthday['func'];
		?>
		</TD> <!-- День народження Посада-->
		
		<!--
		<TD><!-- День народження День тиждня
		<?php //echo $row_birthday['day'] ?>
		</TD> <!-- День народження день тиждня
		-->
				
		<!-- День народження День тиждня
		<TD>
		<?php //echo date('Y/m/d ', strtotime(date('Y/m/d ').'+ 1 year')) ?>
		</TD>  
		-->
		
	</TR>
	<?php
  	}
?>


<?php  // дні народження найближчі 7 днів
	
  	while ($row_birthday7 = mysqli_fetch_assoc($res_birthday7)) {
	?>	
<TR CLASS="data7">
		<TD><!-- День народження ПІБ-->
			<?php echo $row_birthday7['surname']." "
				.$row_birthday7['name']." "
				.$row_birthday7['patronymic']; ?>
		</TD> <!-- День народження ПІБ-->
		
		<TD><!-- День народження Дата народження-->
		<?php echo date('d/m ', strtotime($row_birthday7['birthday'])) ?>
		</TD> <!-- День народження Дата народження-->
		
		<!--
		<TD><!-- День народження Повних років
		<?php //echo date('Y/m/d ')-$row_birthday7['birthday'] ?>
		</TD> <!-- День народження Повних років
		-->
		
		<TD><!-- День народження Відділ-->
		<?php 
			echo $row_birthday7['branch'];
		?>
		</TD> <!-- День народження Відділ-->
		
		<TD><!-- День народження Посада-->
		<?php 
			echo $row_birthday7['func'];
		?>
		</TD> <!-- День народження Посада-->
		
		<TD><!-- День народження День тиждня-->
		<?php //echo $row_birthday['day'] ?>
		</TD> <!-- День народження день тиждня-->
		
				
		<!-- День народження День тиждня
		<TD>
		<?php //echo date('Y/m/d ', strtotime(date('Y/m/d ').'+ 1 year')) ?>
		</TD>  
		-->
		
	</TR>
	<?php
  	}
?>
</TABLE>


<br />




<?php //список співробітників з телефонами



$res = mysqli_query($link, $sql) or exit($la_151_2 ." ". $la_151_9);//"Похибка при виконанні запиту до БД. " "або база даних не має записів"
$title = $la_11; //Результати пошуку



if (mysqli_num_rows($res)) {
	//include serchtab.view
?>

	
<P>
	<?php echo $la_42 ?> ( <!--"За Вашим запитом"-->
	<STRONG>
		<?php echo $off ?>
	</STRONG>) 
		<?php echo $la_31 ?> : <!--"знайдено наступні записи"-->
</P>
	
	<TABLE WIDTH="100%" CELLPADDING="2" CELLSPACING="1" BORDER="0">
	<TR CLASS="head">
		<TD><?php echo $la_36 ?></TD> <!-- Відділ/Підрозділ-->
		<TD><?php echo $la_45 ?></TD> <!-- Посадада-->
		<TD><?php echo $la_130?></TD> <!-- ПІБ -->
		<TD><?php echo $la_34 ?></TD> <!-- ВАТС-->
		<TD><?php echo $la_35 ?></TD> <!-- МАТС-->
		<!-- <TD><?php echo $la_37 ?></TD>  Підприємство-->
		<TD><?php echo $la_38 ?></TD> <!-- Адреса-->
		<TD><?php echo $la_139 ?></TD> <!-- Внутрішня поштова адреса-->
		<TD><?php echo $la_136 ?></TD><!-- Примітки-->
	</TR>
	<?php
  	while ($row = mysqli_fetch_assoc($res)) {
	?>
	<TR CLASS="data">
		<TD><?php echo $row['branch'] ?></TD> <!-- Відділ/Підрозділ-->
		<TD><?php echo $row['func'] ?></TD> <!-- Посада-->
		<TD><?php echo $row['surname']." ".$row['name']." ".$row['patronymic'] ?></TD> <!-- ПІБ -->
		<TD><?php echo $row['number'] ?></TD> <!-- ВАТС-->
		<TD><?php echo $row['number1'] ?></TD> <!-- МАТС-->
		<!-- <TD><?php echo $row['office'] ?></TD> Підприємство-->
		<TD><?php echo "{$row['street']}, {$row['house']}, {$row['flat']}" ?></TD> <!--  Адреса-->
		<TD><!-- Внутрішня поштова адреса-->
			<a href="mailto:<?php echo $row['userMail'] ?>"><?php echo $row['userMail'] ?>
			</a>
		</TD> <!-- Внутрішня поштова адреса-->
		<TD><?php echo $row['note'] ?></TD> <!-- Примітки-->
	</TR>
	<?php
  	}
?>
</TABLE>


<P>
	<?php echo $la_128 ?> <!--Записи впорядковані за Відділом/Підрозділом-->
</P>
<?php
} else {
?>
<P><?php echo $la_48 ?>.</P><!--За Вашим запитом записів не знайдено-->
<?php
  include('notfnd.inc');
}
include('footer.inc');
?>