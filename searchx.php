<?php
/*
searchx.php
пошук за номером
 */

if (isset($_GET['x'])) {
  $value = urldecode($_GET['x']);
  //проверка параметров запроса
  if (empty($_GET['x']))
    $err = $la_150_24; //<!--"Необхідно вказати номер телефону для пошуку."-->
  elseif (preg_match("/[^\d_]+/", $value))
    $err =  $la_150_25; //<!--"В строці запиту слід вводити тільки цифри без пробілів "--?
  elseif (strlen($_GET['x']) > 6)
    $err = $la_150 ; //<!--"Номер телефон не має перевищувати 6 символів."-->
  //elseif (substr_count($value, '_') > 1)
    //$err = 'Допускается только одна произвольная цифра в номере.';
  if (! isset($err)) { //ошибок нет
    include('searchx.inc');
    exit;
  }
}
include('lang_ua.php');
$title = $la_3;//"Пошук за номером"
include('header.inc');

?>
<P>
	<?php echo $la_25 ?> 
	<STRONG>
		<?php echo $la_26 ?>
	</STRONG> 
	<?php echo $la_27 ?> "
	<STRONG>
		_
	</STRONG>
	" 
	<?php echo $la_28 ?>
</P>
<FORM ACTION="searchx.php" METHOD="get">
	<P ALIGN="CENTER">
		<INPUT TYPE="text" NAME="x" SIZE="10" MAXLENGTH="10" VALUE="<?php if (isset($value)) echo htmlspecialchars($value) ?>">
	</P>
	<P ALIGN="CENTER">
		<INPUT TYPE="submit" value="
		<?php echo $la_29 ?> "><!--"Пошук"-->
	</P>
</FORM>
<?php
if (isset($err)) {
?>
<P CLASS="error">
	<?php echo $la_142 ?> <!--"Увага!"--> 
	<?php echo $err ?>	
</P>
<?php
}
include('footer.inc');
?>