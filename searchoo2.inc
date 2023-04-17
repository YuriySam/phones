<?php
/*
searchoo2.inc
 */
include('base.inc');
include('lang_ua.php');

$input_note_branch = addslashes($note_branch);//Екрануємо спецсимволи (\)

$sql = "SELECT number, number1, surname, name, patronymic, branch, func, office, street, house, userMail
FROM ophone, func, office, street,branch
WHERE ophone.offid='{$value}'
AND branch.branch LIKE '{$input_note_branch}'
AND ophone.offid=office.offid
AND ophone.funid=func.funid
AND ophone.strid=street.strid
AND branch.branid = ophone.branid
	ORDER BY func";



$res = mysqli_query($link,$sql) or exit($la_151_2.'searchoo2.inc стр23 '.$sql); //Похибка при виконанні запиту до БД. "
$title = $la_11; //"Результати пошуку"
include('header.inc');



if (mysqli_num_rows($res)) {

?>
	<P><?php echo $la_44 ?> "<STRONG><?php echo $note_branch ?></STRONG>") <?php echo $la_31 ?>:</P>
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
	<?php
	while ($row = mysqli_fetch_assoc($res)) {
	?>
		<TR CLASS="data">
			<TD>
				<?php echo $row['number'] ?>
			</TD> <!-- ВАТС-->
			<TD>
				<?php echo $row['number1'] ?>
			</TD> <!-- МАТС-->
			<TD>
				<?php echo $row['surname']." ".$row['name']." ".$row['patronymic'] ?>
			</TD> <!-- ПІБ -->
			<TD>
				<?php echo "{$row['branch']}"?>
			</TD> <!-- Відділ/Підрозділ-->
			<TD>
				<?php echo $row['func'] ?>
			</TD> <!-- Посада-->
			<TD>
				<?php echo $row['office'] ?>
			</TD> <!-- Підприємство-->
			<TD>
				<?php echo $row['street'].", ".$row['house'] ?>
			</TD> <!-- Адреса-->
			<TD><!-- Внутрішня поштова адреса-->
				<a href="mailto:<?php echo $row['userMail'] ?>"><?php echo $row['userMail'] ?>
				</a>
			</TD> <!-- Внутрішня поштова адреса-->
		</TR>
<?php
	}
?>
	</TABLE>
	<P>
		<?php echo $la_46 ?>. <!--"Записи впорядковані за адресою"-->
	</P>
<?php
} else {
	?>
	<P>
		<?php echo $la_48?>.  <!--"За Вашим запитом записів не знайдено"-->
		<?php echo "26 [searchoo2.inc] ".$sql; ?>
	</P>
<?php
	include('notfnd.inc');
}
	include('footer.inc');
?>