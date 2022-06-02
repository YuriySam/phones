<?php
/*
searchn.php
*/
if (isset($_GET['n'])) {
  $value = urldecode($_GET['n']);
  //перевірка параметрів запиту
  if (empty($value))
    $err = $la_150_15;//"Необхідно вказати ім'я абонента"
  elseif (strlen($value) < 2)
    $err = $la_150_16;//"Ім'я абонента не може бути меньше за 2 букви "
  elseif (strlen($value) > 25)
    $err = $la_150_17;//"Ім'я абонента не може містити більше 25 символів."
  //preg_match("/[^\xC0-\xFF]+/", $value))
  elseif (!preg_match("/^[а-яА-ЯїЇєЄіІ']+$/u", $value))
   $err = $la_150_18;//"В строці запиту допустимі тільки символи українського алфавіту"
  if (! isset($err)) { //похибок немає
    include('searchn.inc');
    exit;
  }
}
$title = $la_150_13;//"Пошук за ім'ям."
include('header.inc');
?>
<P><?php echo $la_150_19?></P> <!--"В полі введіть <STRONG>призвище абонента</STRONG> (повністю чи декілька перших букв) й натисніть кнопку:"-->
<FORM ACTION="searchn.php" METHOD="get">
	<P ALIGN="CENTER"><INPUT TYPE="text" NAME="n" SIZE="20" MAXLENGTH="25" VALUE="<?php if (isset($value)) echo htmlspecialchars($value) ?>">
	</P>
	<P ALIGN="CENTER"><INPUT TYPE="submit" VALUE=" Поиск ">
	</P>
</FORM>
<?php
if (isset($err)) {
?>
<P CLASS="error"> <?php echo $la_142." ".$err ?></P><!--"Увага!"-->
<?php
}
include('footer.inc');
?>