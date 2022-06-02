<?php
/*
*searchp2.inc
*знайдемо телефон по адресі
*/
include_once('base.inc');


$sql = "SELECT number, number1, surname, name, patronymic, note, house, flat, func, office, street
FROM ophone, func, office, street
WHERE ophone.strid='{$value}'
AND ophone.house LIKE '{$house}'
AND ophone.offid=office.offid
AND ophone.funid=func.funid
AND ophone.strid=street.strid
ORDER BY flat";


$res = mysqli_query($link,$sql) or exit($la_151_2.$sql);//"Похибка при виконанні запиту до БД. "
$title = $la_11;//"Результати пошуку"
include('header.inc');
if (mysqli_num_rows($res)) {
?>
<P>
	<?php echo $la_125 ?><!--"За Вашим запитом (пошук за номером будинку"-->
	"<STRONG><?php echo $house ?></STRONG>")
	<?php echo $la_31 ?>:<!--"знайдено наступні записи"-->
</P>
<TABLE WIDTH="100%" CELLPADDING="2" CELLSPACING="1" BORDER="0">
<TR CLASS="head">
	<TD><?php echo $la_34 ?></TD> <!-- ВАТС-->
	<TD><?php echo $la_35 ?></TD> <!-- МАТС-->
	<TD><?php echo $la_130?></TD> <!-- ПІБ -->
	<TD><?php echo $la_36 ?></TD> <!-- Відділ/Підрозділ-->
	<TD><?php echo $la_45 ?></TD> <!-- Посада-->
	<TD><?php echo $la_37 ?></TD> <!-- Підприємство-->
	<TD><?php echo $la_38 ?></TD> <!-- Адреса-->
</TR>
<?php
	while ($row = mysqli_fetch_assoc($res)) {
?>
<TR CLASS="data">
	<TD><?php echo $row['number'] ?></TD> <!-- ВАТС-->
	<TD><?php echo $row['number1'] ?></TD> <!-- МАТС-->
	<TD><?php echo $row['surname']." ".$row['name']." ".$row['patronymic'] ?></TD> <!-- ПІБ -->
	<TD><?php echo $row['func'] ?></TD> <!-- Посада-->
	<TD><?php echo "{$row['note']}"?></TD> <!-- Відділ/Підрозділ-->
	<TD><?php echo $row['office'] ?></TD> <!-- Підприємство-->
	<TD><?php echo $row['street'].", ".$row['house'] ?></TD> <!-- Адреса-->
</TR>
<?php
}
?>
</TABLE>
<P>
	<?php echo $la_46 ?><!--"Записи впорядковані за адресою"-->
</P>
<?php
} else {
?>
<P><?php echo $la_126 ?>.</P><!--"За Вашим запитом записів не зняйдено"-->
<?php
  include('notfnd.inc');
}
include('footer.inc');
?>