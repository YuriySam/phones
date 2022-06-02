<?php
session_start();
//перевірити реєстрацію
if (! isset($_SESSION['logdate'])) {
  header('Location: login.php');
  exit;
}

include_once('../lang_ua.php');


//виконати дії
if (isset($_GET['import'])) {
  if ($_GET['import'] == 'p') {
    include('importp.inc');
    exit;
  } elseif ($_GET['import'] == 'q') {
    include('importq.inc');
    exit;
  }
}
if (isset($_GET['export'])) {
  if ($_GET['export'] == 'p') {
    include('exportp.inc');
    exit;
  } elseif ($_GET['export'] == 'q') {
    include('exportq.inc');
    exit;
  }
}

$title = $la_73; //Завантажити файли
include('header.inc');
?>
<P>
  <?php echo $la_113 ?> <!--База данных довідника може бути завантажена з текстового файлу спеціального формату - <STRONG>CSV</STRONG> (Comma Separated Values). Цей файл з ім'ям <STRONG>phones.csv</STRONG> повинен бути разміщений в тому же каталозі, де знаходятся скрипти інтерфейсу адміністратора (подивиться URL цієї сторінки в адресній строці браузера).</P>
<P>Цей файл Ви можете створити чи змінити в будь-якому табличному редакторі. Розмістити файл в потрібному каталозі сервера вы можете й через <STRONG>ftp</STRONG> чи будь-яким іншим доступним способом.</P>
<P>Відомості про файл <STRONG>phones.csv</STRONG> (размір, дата й час останньої зміни):-->
</P>
<?php
$f = '../install/phones.csv';
if (file_exists($f)) {
  $info = filesize($f).' байт<BR>'.date('d.m.Y H:i:s', filemtime($f));
} else {
  $info = 'Файл не найден';
}
?>
<P ALIGN="right">
	<STRONG>
		<?php echo $info ?>
	</STRONG>
</P>
<P ALIGN="right">
	<A HREF="loading.php?import=p">
		<?php echo $la_114 ?> <!--Завантажити базу даних-->
	</A>
		<?php echo $la_163 ?><BR> <!--"з файлу"-->
	<A HREF="loading.php?export=p">
		<?php echo $la_115 ?> <!--Вивантажити базу даних-->
	</A> 
	<?php echo $la_169 ?> <BR><!--"у файл"-->
</P>
<P>
	<?php echo $la_116 ?> <!--Цитати можуть бути завантажені з файлу <STRONG>quotes.csv</STRONG>.-->
</P>
<P>
	<?php echo $la_117 ?> <!--Відомості про файл <STRONG>quotes.csv</STRONG> (размір, дата й час останьої зміни):-->
</P>
<?php
$f = 'quotes.csv';
if (file_exists($f)) {
  $info = filesize($f).' байт<BR>'.date('d.m.Y H:i:s', filemtime($f));
} else {
  $info = 'Файл не найден';
}
?>
<P ALIGN="right"><STRONG><?php echo $info ?></STRONG></P>
<P ALIGN="right">
<A HREF="loading.php?import=q">
<?php echo $la_118 ?> <!--Завантажити цитати-->
</A> <?php echo $la_163 ?><BR> <!--"з файлу"-->
<A HREF="loading.php?export=q">
<?php echo $la_119 ?> <!--Вивантажити цитати-->
</A> <?php echo $la_169 ?> <BR><!--"у файл"-->
</P>
<?php
include('footer.inc');
?>