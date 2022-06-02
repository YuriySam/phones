<?php
/****************
searchp.php
*Пошук по адресі
*вибір вулицы зі списку, вибір номера будинку зі списку
****************/
if (isset($_GET['h']) and isset($_GET['s'])) {
  $value = $_GET['s'];
  settype($value, 'integer');
  $house = urldecode($_GET['h']);
  //echo "11-[serchp.php] value=".$value."  house=".$house;
  //перевіерка параметрів запиту
  if (empty($value))
    $err = $la_150_8; //"Необхідно вибрати населений пункт та вулицю."
  elseif (empty($house))
    $err = $la_150_2; //"Необхідно вказати номер будинку."
  elseif (strlen($house) > 8)
    $err = $la_150_3;//"Номер будинку не має містити більше 8 символів."
  elseif (preg_match("/['\"%_]+/", $house))
    $err = $la_150_9;//"В запросі присутні недопустимі символи."
  if (! isset($err)) { //ошибок нет
    include('searchp2.inc');
    exit;
  } else {
    header("Location: searchp.php?s={$value}");
    exit;
  }
} elseif (isset($_GET['s'])) {
  $value = $_GET['s'];
  echo "29-[serchp.php] ".$value."   err=".$err;
   settype($value, 'integer');
  //проверка параметров запроса
  if (empty($value))
    $err = $la_150_8;//"Необхідно вибрати населений пункт та вулицю."
  if (! isset($err)) { //ошибок нет
    include('searchp1.inc');
    exit;
  }
}

include('base.inc');
$sql = "SELECT strid, street FROM street ORDER BY street";
$res = mysqli_query($link, $sql) or exit('Ошибка при выполнении запроса к базе данных.'.$sql);
//$title = 'Поиск по адресу';
include('header.inc');
?>
<P><?php echo $la_39 ?> <STRONG>
  <?php echo $la_47 ?></STRONG>
  <?php echo $la_41 ?>:</P>

<FORM ACTION="searchp.php" METHOD="get">
  <P ALIGN="center">
  <SELECT NAME="s" SIZE="1" required>
  <?php
    while ($row = mysqli_fetch_assoc($res)) {
  ?>
  <OPTION VALUE="<?php echo $row['strid'] ?>"><?php echo $row['street'] ?></OPTION>
  <?php
    }
  ?>
  </SELECT>
  </P>
  <P ALIGN="center"><INPUT TYPE="submit" VALUE="
    <?php echo $la_29 ?> "></P> <!--"Пошук"-->
</FORM>
<?php
if (isset($err)) {
?>
<P CLASS="error">Внимание! <?php echo $err ?></P>
<?php
}
include('footer.inc');
?>
