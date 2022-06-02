<?php
/*
exportp.inc

 */
include_once('../lang_ua.php');
include_once('../base.inc');
//Зняти обмеження часу виконання
@set_time_limit(0);
//відкрити файл
$f = '../install/phones_export.csv';
$fp = fopen($f, 'w');
$cnt = 0;


//відібрати записи по офисних номерах
$sql = "SELECT number, number1, surname, name, patronymic, birthday, office, branindex, branch, func, town_pre, town, street_pre, street, house, flat , note, sortindex, userMail
FROM ophone, office, street, func, branch
WHERE office.offid = ophone.offid
AND street.strid = ophone.strid
AND func.funid = ophone.funid
AND branch.branid = ophone.branid
ORDER BY branindex";
$res = mysqli_query($link, $sql) or $err = '[exportp.inc line 34 ] '.$la_151_2." " .$sql.' ';

//"Похибка при виконанні запиту до БД. "
while ($row = mysqli_fetch_assoc($res)) {
		
  //list($town, $street) = explode(', ', $row['street'], 2); //отделить населенный пункт от улицы
  $flat = ($row['flat']) ? $row['flat'] : ''; //замінити 0 на пусту строку
  
  fwrite($fp, "{$row['number']};{$row['number1']};{$row['birthday']};{$row['surname']};{$row['name']};{$row['patronymic']};{$row['office']};{$row['branindex']};{$row['branch']};{$row['funindex']};{$row['func']};{$row['town_pre']};{$row['town']};{$row['street_pre']};{$row['street']};{$row['house']};{$row['flat']};{$row['sortindex']};{$row['userMail']};{$row['note']}\n");
}
$cnt += mysqli_num_rows($res);
fclose($fp);
$title = $la_115;//"Вивантажити базу даних"
include('header.inc');
if (isset($err)) {
?>
<P>
	<?php echo $la_174_1?> <!--"Вивантаження бази данних в файл пройшло <STRONG>невдало</STRONG>."-->
</P>
<P CLASS="error">
	<?php echo $la_142?> <!--"Увага!"-->
	<?php echo $err ?>
</P>
<P ALIGN="right">
	<?php echo $la_173_2?>  <!--"Ще раз спопробувати."-->
	<A HREF="loading.php?export=p">
		<?php echo $la_174_2 ?> <!--"Вивантажити базу данних в файл"-->
	</A>
	
</P>
<?php
} else {
?>
<P>
<?php echo $la_120 ?> <!--"Вивантаження базы данных пройшла <STRONG>успішно</STRONG>. В файл "-->
	<STRONG><?php echo $f ?></STRONG>
	<?php echo $la_121 ?> <!--"було вивантажено "-->
	<STRONG><?php echo $cnt ?></STRONG>
<?php echo $la_122 ?></P> <!--"записів. "-->
<P ALIGN="right">
	<A HREF="loading.php">
		<?php echo $la_73 ?> <!--"Завантажити файли"-->
	</A>
</P>
<?php
}
include('footer.inc');
?>