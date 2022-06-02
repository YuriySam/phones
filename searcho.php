<?php
/*
* searcho.php
"Пошук за підприємством"
*/
if (isset($_GET['o'])) {
  $value = $_GET['o'];
  settype($value, 'integer');
  //перевірка параметрів запиту
  if (empty($value))
    $err = $la_150_26; //"Необхідно обрати назву організації "
  if (! isset($err)) { //похибок немає
    include('searcho.inc');
    exit;
  }
}
include('base.inc');
$sql = "SELECT offid, office FROM office ORDER BY office";
$res = mysqli_query($link, $sql) or exit($la_151_2); //"Похибка при виконанні запиту до БД. "
$title = $la_6; //<!-- Пошук за підприємством -->
include('header.inc');
?>
<P><?php echo $la_39 ?> <!-- Оберіть --> <STRONG><?php echo $la_40 ?></STRONG> <!-- назву підприємства -->

 <?php echo $la_41 ?>:
</P> <!-- зі списку та нитисніть кнопку Пошук -->

<FORM ACTION="searcho.php" METHOD="get">
	<P ALIGN="center">
	<SELECT NAME="o" SIZE="1">
		<?php
			while ($row = mysqli_fetch_assoc($res)) {
		?>
			<OPTION
				VALUE="<?php echo $row['offid']?>">
				<?php echo $row['office'] ?>
			</OPTION>
		<?php
			}
		?>
	</SELECT>
	</P>
	<P ALIGN="center"><INPUT TYPE="submit" VALUE="
		<?php echo $la_29 ?> "> <!--"Пошук"-->
	</P>
</FORM>
<?php
if (isset($err)) { ?>
<P CLASS="error">
	<?php echo $la_142?> <!--"Увага!"-->
	<?php echo $err ?>
</P>
<?php
}
include('footer.inc');
?>
