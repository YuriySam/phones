<?php
/*
searchn.inc
*/
include_once('base.inc');
$sql = "SELECT id, number, number1, func,  office, branch, branindex, surname, name, patronymic, street, house, flat, note, userMail, sortindex
FROM ophone, func, office, street, branch
WHERE office.offid= ophone.offid
AND street.strid = ophone.strid
AND func.funid = ophone.funid
AND branch.branid = ophone.branid
AND (NOT trim(number1)='' OR NOT trim(number)='')
AND surname LIKE '%{$value}%' 
ORDER BY branindex, sortindex ";

$res = mysqli_query($link, $sql) or exit($la_151_2." ".$sql);//"Похибка при виконанні запиту до БД. "
$title = $la_11;//"Результати пошуку"
include('header.inc');
if (mysqli_num_rows($res)) {
?>
<P>
	<?php echo $la_42." (".$la_4 ?> "<!--"За Вашим запитом" "Пошук за ім'ям"-->
	<STRONG>
		<?php echo $value ?>
	</STRONG>
	") 
	<?php echo $la_31?>: <!--"знайдено наступні записи"-->
</P> 	<!--"За Вашим запитом" "Пошук за ім'ям" "знайдено наступні записи"-->




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
	<?php echo $la_150_20?> <!--"Записи впорядковані за ім'ям абонента."-->
</P> 
<?php
} else {
?>
<P>
	<?php echo $la_42." (". $la_4?> "<!--"За Вашим запитом" "Пошук за ім'ям" -->
	<STRONG>
		<?php echo $value ?>
	</STRONG>
	") <?php echo $la_151_7?> <!-- "записи не знайдені"-->
</P> 
<?php
include('notfnd.inc');
}
include('footer.inc');
?>