<?php
/*
phone.inc
список записів на екран
 */

//echo " $ x= ".$x." GET= ".$_GET['x']."  $ value= ".$value."  $ _SESSION['x']=". $_SESSION['x'] ;

	include_once('../lang_ua.php');
	include_once('../base.inc');
	$title = $la_11;//<!-- Результати пошуку-->
	include_once('header.inc');

//шукати
	$sql = "SELECT id, number, number1, func,  office, branch, branindex, surname, name, patronymic, birthday, street, house, flat, note, userMail, sortindex
	FROM ophone, func, office, street, branch
	WHERE office.offid = ophone.offid
	AND street.strid = ophone.strid
	AND func.funid = ophone.funid
	AND branch.branid = ophone.branid
	AND number LIKE '{$_SESSION['x']}'
	ORDER BY branindex, sortindex";
	
	
	
	$res = mysqli_query($link,$sql) or exit('phone.inc 59 '.$la_151_2."  ".$la_151_9);//"Похибка при виконанні запиту до БД. " "або база даних не має записів"
	if (mysqli_num_rows($res)) {

?>
<P>
	<?php echo $la_30 ?> <!-- За Вашим запитом (пошук за номером -->
	"<STRONG>
		<?php if ($_SESSION['x']=="%")  {echo "Всі записи";}else echo $_SESSION['x']; ?>
	</STRONG>")
		<?php echo $la_31 ?>
	(<STRONG>
		<?php echo $la_33 ?>
	</STRONG>)
</P>
<TABLE WIDTH="100%" CELLPADDING="2" CELLSPACING="1" BORDER="0" >
	
<TR CLASS="head">
	<TD><?php echo $la_34 ?></TD> <!-- ВАТС-->
	<TD><?php echo $la_35 ?></TD> <!-- МАТС-->
	<TD><?php echo $la_130?></TD> <!-- ПІБ -->
	<TD><?php echo $la_137?></TD> <!-- Дата Народження -->
	<TD><?php echo $la_36 ?></TD> <!-- Відділ/Підрозділ-->
	<TD><?php echo $la_45 ?></TD> <!-- Посада-->
	<!-- <TD><?php //echo $la_37 ?></TD>  Підприємство-->
	<TD><?php echo $la_38 ?></TD> <!-- Адреса-->
	<TD ><?php echo $la_139 ?></TD> <!-- Внутрішня поштова адреса-->
	<TD><?php echo $la_136 ?></TD> <!-- Примітки-->
	<TD><?php echo $la_39 ?></TD> <!-- Оберіть-->
</TR>

<?php
  while ($row = mysqli_fetch_assoc($res)) {
?>
<TR CLASS="data">
	<TD><?php echo $row['number'] ?></TD> <!-- ВАТС-->
	<TD><?php echo $row['number1'] ?></TD> <!-- МАТС-->
	<TD><?php echo $row['surname']." ".$row['name']." ".$row['patronymic'] ?></TD> <!-- ПІБ -->
	<TD><?php echo $row['birthday'] ?></TD> <!-- Дата народження-->
	<TD><?php echo $row['branch'] ?></TD> <!-- Відділ/Підрозділ-->
	<TD><?php echo $row['func'] ?></TD> <!-- Посада-->
	<!--<TD><?php //echo $row['office'] ?> </TD>  Підприємство-->
	<TD><?php echo "{$row['street']}, {$row['house']}"; if ($row['flat']) echo " - ".$row['flat'] ?></TD> <!-- Адреса-->
	<TD><!-- Внутрішня поштова адреса-->
		<a href="mailto:<?php echo $row['userMail'] ?>"><?php echo $row['userMail'] ?>
		</a>
	</TD> <!-- Внутрішня поштова адреса-->
	<TD><?php echo $row['note'] ?></TD> <!-- Примітки-->
	<TD><A HREF="phone.php?update=o&id=<?php echo $row['id'] ?>"><?php echo $la_95?>
		</A> <!-- Змінити-->
		<A HREF="phone.php?insert=o&id=<?php echo $row['id'] ?>"><?php echo $la_131?>
		</A>
		<!--Додати-->

		<A HREF="phone.php?delete=o&id=<?php echo $row['id'] ?>"><?php echo $la_96?>
		</A><!-- Видалити-->
	</TD>
</TR>
<?php
  }
?>
</TABLE>


<?php
}
if ( isset($row)) {
?>
<P>
	<?php echo $la_30 ?> "<STRONG>
	<?php echo $_GET['x'] ?></STRONG>")
	 <?php echo $la_99 ?><!-- записів не знайдено. Наразі Ви можете <STRONG>додати новий запис</STRONG> з таким номером:-->
</P>
<P ALIGN="right">
<!--
<A HREF="phone.php?insert=p">Добавить частный номер</A><BR>
-->
<A HREF="phone.php?insert=o"><?php echo $la_97 ?></A>
</P>
<?php
}
?>
<P><?php echo $la_100 ?></P>
<P ALIGN="right">
<A HREF="phone.php"><?php echo $la_98 ?></A>
</P>
<?php
include('footer.inc');
?>