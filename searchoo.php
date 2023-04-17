<?php
/****************
searchoo.php
*
****************/
if (isset($_GET['o']) and isset($_GET['oo'])) {
  //echo "7 [searchoo.php] ".isset($_GET['o']) and isset($_GET['oo']);
  $value = $_GET['oo'];
  settype($value, 'integer');
  $note_branch = urldecode($_GET['o']);
  //перевірка параметрів запиту
  if (empty($value))
    $err = $la_150_27;//"Необхідно обрати назву відділу "

  if (! isset($err)) { //без похибок
    include('searchoo2.inc');

    exit;
  } else {
    header("Location: searchoo.php?oo={$value}");
    exit;
  }
} elseif (isset($_GET['oo'])) {
  $value = $_GET['oo'];
 settype($value, 'integer');
 //перевірка параметрів запиту
  if (empty($value))
    $err = $la_150_26;//"Необхідно обрати назву організації "
  if (! isset($err)) { //без похибок
    include('searchoo1.inc');
    exit;
  }
}

include('base.inc');
include('lang_ua.php');
$sql = "SELECT offid, office FROM office ORDER BY (office+0)";
$res = mysqli_query($link, $sql) or exit($la_151_2.'  searchoo.php стр47'.$sql);//"Похибка при виконанні запиту до БД. "
$title = $la_150_28;//"Пошук по організації "
include('header.inc');


$num_rows = mysqli_num_rows($res);
?>
<P><?php echo $la_39 /*"Оберіть назву підприємства зі списку та нитисніть кнопку Пошук"*/ ?> :</P>

<FORM ACTION="searchoo.php" METHOD="get">
  <P ALIGN="center">
  <SELECT NAME="oo" SIZE="1">
  <?php
  
	

    while ($row = mysqli_fetch_assoc($res)) {
  ?>
	<OPTION VALUE="<?php echo $row['offid'] ?>">
		<?php echo $row['office'] ?>
	</OPTION>
  <?php
    }
  ?>
  </SELECT>
  </P>
  <P ALIGN="center">
	<INPUT TYPE="submit" VALUE=" <?php echo $la_29 /*"Пошук"*/?> ">
	</P><!--"Пошук"-->
</FORM>
<?php
if (isset($err)) {
?>
<P CLASS="error">
	$la_142 <!--"Увага!"-->
	<?php echo $err ?>
</P>
<?php
}
include('footer.inc');
?>
