<?php
/*
searchoo1.inc

*/

include('base.inc');

$sql = "SELECT query.branch FROM (SELECT DISTINCT branindex,branch
FROM branch, ophone
WHERE ophone.offid='{$value}'
ORDER BY branindex) AS query";
echo $value;
$res = mysqli_query($link, $sql) or exit($la_151_2.' searchoo1.inc стр16'.$sql);//"Похибка при виконанні запиту до БД. "
$title = $la_8; //"Пошук за адресою"
include('header.inc');


if (mysqli_num_rows($res)) {
	?>
	<P>
		<?php echo $la_43 ?>:<!--"На разі оберіть відділ/підрозділ що до обраного Вами підприємства"-->
	</P>

	<FORM ACTION="searchoo.php" METHOD="get">
	<INPUT TYPE="hidden" NAME="oo" VALUE="<?php echo $value ?>">
	<P ALIGN="center">
	<SELECT NAME="o" SIZE="1">
	<?php
  	while ($row = mysqli_fetch_assoc($res)) {
		?>
		<OPTION VALUE="<?php echo urlencode($row['branch']) ?>">
			<?php echo $row['branch'] ?>
		</OPTION>
		<?php
  	}
	?>
	</SELECT>
	</P>
	<P ALIGN="center">
		<INPUT TYPE="submit" VALUE=" <?php echo $la_29 ?> "> <!--"Пошук"-->
	</P>
	</FORM>

	<?php
} else {
	?>
	<P>
		<?php echo $la_48 ?> .<?php echo "30  [searchoo1.php] ".$sql; ?> <!--"За Вашим запитом записів не знайдено"-->
	</P>
	<?php
  	include('notfnd.inc');
}
include('footer.inc');
?>
