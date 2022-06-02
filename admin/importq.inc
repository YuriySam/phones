<?php
/*
importq.inc
*/
include_once('../base.inc');
//зняти обмеження часу виконання
@set_time_limit(0);
//видалити старі записи
$sql = "DELETE FROM quote";
mysqli_query($link, $sql) or $err = $la_151_3; //"Похибка виконання запиту до БД на видалення записів."
//відкрити  файл
$f = '../install/quotes.csv';
if (file_exists($f)) {
  $fp = fopen($f, 'r');
  $cnt = 0;
  while ($row = fgetcsv($fp, 1024, ';')) {
    //додавати по одному запису
    $q = mysqli_escape_string($link, $row[0]);
    if (strlen($q)) {
      $sql = "INSERT INTO quote SET quote = '{$q}'";
      mysqli_query($link, $sql) or $err = $la_151_4;//"Похибка виконання запиту до БД на додавання записів."
      $cnt++;
    }
  }
  fclose($fp);
} else {
  $err = $la_151_5;//"Файл '{$f}' не знайдено. Переконайтеся, що файл знаходится в потрібному каталозі."
}
$title = $la_159;//'Завантаження цитат'
include('header.inc');
if (isset($err)) {
?>
<P><?php echo $la_160 ?></P> <!--"Завантаження цитат з файлу пройшла <STRONG>невдало</STRONG>."-->
<P CLASS="error">
	<?php echo $la_149." ".$err ?>
</P><!--"Увага!"-->
<P ALIGN="right">
	<?php echo $la_161 ?>
	<A HREF="loading.php?import=q">
		<?php echo $la_162 ?> <!--"Ще раз спробувати"  -->
	</A> <?php echo $la_163 ?> <!--  "Загрузити цитати"-->
</P> 
<?php
} else {
?>
<P>
	<?php $la_164 ?>
	<STRONG>
		<?php echo $cnt ?>
	</STRONG> 
	<?php echo $la_165 ?> 
	<STRONG>
		<?php echo $f ?>
	</STRONG>.
</P><!--Загрузка цитат пройшла <STRONG>успішно</STRONG>. Всі старі записи були видалені, затем було додано" записей из файла  -->
<P ALIGN="right">
	<A HREF="loading.php">
		<?php echo $la_166?>
	</A>
</P> <!-- "Загрузка файлів"-->
<?php
}
include('footer.inc');
?>