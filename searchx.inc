<?php
/*
searchx.inc
пошук за номером
 */
include_once('base.inc');

//пошук по ophone
$sql2 = "SELECT
number, number1, office, street, surname, name, patronymic, house, func, branch, userMail
FROM ophone, office, func, street , branch
WHERE office.offid = ophone.offid
AND func.funid=ophone.funid
AND street.strid = ophone.strid
AND branch.branid = ophone.branid
AND number LIKE '{$value}' ORDER BY number";
$res2 = mysqli_query($link, $sql2) or exit($la_151_2.'searchx.inc 19 '.$sql2);//"Похибка при виконанні запиту до БД. "
$title = $la_11;//"Результати пошуку"
include('header.inc');
if (mysqli_num_rows($res2)) {

  //офісні номери
  if (mysqli_num_rows($res2)) {
?>
<P>
	<?php echo $la_30 ?><!--"За Вашим запитом пошук за номером "-->
	<STRONG>
	("<?php echo $value ?>")
	</STRONG>
	<?php echo $la_31 ?><!--"знайдено наступні записи";-->
	<STRONG>
	(<?php echo $la_33 ?>)<!--"офісні номери"-->
	</STRONG>:</P>
<TABLE WIDTH="100%" CELLPADDING="2" CELLSPACING="1" BORDER="0">
<TR CLASS="head">
	<TD><?php echo $la_34 ?></TD> <!-- ВАТС-->
	<TD><?php echo $la_35 ?></TD> <!-- МАТС-->
	<TD><?php echo $la_130?></TD> <!-- ПІБ -->
	<TD><?php echo $la_36 ?></TD> <!-- Відділ/Підрозділ-->
	<TD><?php echo $la_45 ?></TD> <!-- Посада-->
	<TD><?php echo $la_37 ?></TD> <!-- Підприємство-->
	<TD><?php echo $la_38 ?></TD> <!-- Адреса-->
	<TD ><?php echo $la_139 ?></TD> <!-- Внутрішня поштова адреса-->
</TR>
<?php while ($row = mysqli_fetch_assoc($res2)) { ?>
<TR CLASS="data">
	<TD><?php echo $row['number'] ?></TD> <!-- ВАТС-->
	<TD><?php echo $row['number1'] ?></TD> <!-- МАТС-->
	<TD><?php echo $row['surname']." ".$row['name']." ".$row['patronymic'] ?></TD> <!-- ПІБ -->
	<TD><?php echo $row['branch'] ?></TD>  <!-- Відділ/Підрозділ-->
	<TD><?php echo $row['func'] ?></TD> <!-- Посада-->
	<TD><?php echo $row['office'] ?></TD> <!-- Підприємство-->
	<TD><?php echo "{$row['street']},{$row['house']}" ?></TD> <!-- Адреса-->
	<TD><!-- Внутрішня поштова адреса-->
		<a href="mailto:<?php echo $row['userMail'] ?>"><?php echo $row['userMail'] ?>
		</a>
	</TD> <!-- Внутрішня поштова адреса-->
</TR>
<?php } ?>
</TABLE>
<?php
  }
?>
<P>
	<?php echo $la_123 ?>
	<!--"Записи впорядковані за номером абонента."-->
</P>
<?php
} else {
?>
<P>
	<?php echo $la_30 ?>  <!--"За Вашим запитом пошук за номером "-->
	<STRONG>
		"<?php echo $value ?>"
	</STRONG>)
	<?php echo $la_127 ?>. <!--"записів не зняйдено"-->
</P>
<?php
	include('notfnd.inc');
}
	include('footer.inc');
?>