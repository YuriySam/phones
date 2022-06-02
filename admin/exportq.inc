<?php
/*
exportq.inc

*/
include('../base.inc');
//снять ограничение времени выполнения
@set_time_limit(0);
//открыть файл
$f = '../install/quotes_export.csv';
$fp = fopen($f, 'w');
//отобрать все записи
$sql = "SELECT quote FROM quote ORDER BY id";
$res = mysqli_query($link, $sql) or $err = $la_151_2.' exportq.inc ';//"Похибка при виконанні запиту до БД. "
while ($row = mysqli_fetch_assoc($res)) {
  fwrite($fp, "{$row['quote']}\r\n");
}
fclose($fp);
$title = $la_168; //"Вигрузка цитат";
include('header.inc');
if (isset($err)) {
?>
<P>
	<?php echo $la_167?><!--"Вигрузка цитат в файл пройшла <STRONG> невдало </STRONG>"-->
</P> 
<P CLASS="error">
	<?php echo $la_149 ?><!--"Увага!"-->
	<?php echo $err ?>
</P>
<P ALIGN="right">
	<?php echo $la_161 ?>
	<A HREF="loading.php?export=q">
		<?php echo $la_168 ?> <!--"Вигрузка цитат"-->
	</A>
	<?php echo $la_169?> <!--"у файл";-->
</P>
<?php
} else {
?>
<P>
	<?php echo $la_170 ?> <!--"Выгрузка цитат пройшла <STRONG>успіно</STRONG>. У файл " -->
	<STRONG>
		<?php echo $f ?>
	</STRONG> 
	<?php echo $la_171 ?> <!-- "було вигружено" -->
	<STRONG>
		<?php echo mysqli_num_rows($res) ?>
	</STRONG> 
	<?php echo $la_172?> <!--"записів"-->
</P> 
<P ALIGN="right">
	<A HREF="loading.php">
		<?php echo $la_166?><!--"Загрузка файлів"-->
	</A>
</P> 
<?php
}
include('footer.inc');
?>