<?php
/**
 *searcha.php
 *
 */

if (isset($_GET['a'])) {
  $value = urldecode($_GET['a']);
  //проверка параметров запроса
  //if (!preg_match("/[^\xC0-\xFF]+/", $value))
  if (!preg_match("/^[а-яА-Я ]+$/u", $value))
    $err = $la_150_18;// "В строці запиту допустимі тільки символи українського алфавіту"
  //elseif (! strlen($_GET['а']))
    //$err = 'Необходимо выбрать первую букву имени абонента для поиска.';
  //elseif (strlen($_GET['a']) > 1)
    //$err = 'Необходимо указывать только первую букву имени абонента.';
  if (! isset($err)) { //ошибок нет
    include('searcha.inc');
    exit;
  }
} elseif (isset($_GET['s'])) {
  $value = urldecode($_GET['s']);
  //проверка параметров запроса
  if (! strlen($_GET['s']))
    $err = $la_150_21;//"Необхідно вибрати першу букву призвища абонента для пошуку."
  if (! isset($err)) { //похибок немає
    include('searcha2.inc');
    exit;
  }
}
$title = $la_5;//"Пошук за алфавитом"
include('header.inc');
?>
<P>
	<?php echo $la_150_22?> <!--"Оберіть <STRONG>першу літеру</STRONG> призвища абонента:"-->
</P>
<TABLE ALIGN="CENTER" CELLPADDING="4" CELLSPACING="1" BORDER="0">
<TR>
<?php
	$alpha = 'А-Б-В-Г-Д-Е-Ж-З-И-К-Л-М-Н-О-|-П-Р-С-Т-У-Ф-Х-Ц-Ч-Ш-Щ-Э-Ю-Я';
	$arr = explode('-', $alpha);
	foreach($arr as $a) {
		if ($a == '|') {
			echo "</TR>\r\n<TR>";
		} else {
?>
		<TD>
			<A HREF="searcha.php?a=<?php echo urlencode($a) ?>">
			<?php echo $a ?>
			</A></TD>
<?php
		}
	}
?>
</TR>
</TABLE>
<P>
	<?php echo $la_150_23 ?> <!--"... і просто клікніть по ній"-->
</P>
<?php
if (isset($err)) {
?>
<P CLASS="error"><?php echo $la_142." ".$err ?><!--"Увага!"-->
</P>
<?php
}
include('footer.inc');
?>