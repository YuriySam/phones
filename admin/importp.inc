<?php
/*
importp.inc

 */
 
 function debug_to_console($data) {//вивід в консоль
    $output = $data;
    if (is_array($output))
        $output = implode(',', $output);

    echo "<script>console.log('Debug Objects: " . $output . "' );</script>";
}

//пошук ключа (strid) по строці
//+ додаваня запису, якщо строка не знайдена
function get_street($link, $t_p, $t, $s_p, $s) {
  $sql = "SELECT strid
  FROM street
  WHERE town_pre= '{$t_p}'
  AND town = '{$t}'
  AND street_pre = '{$s_p}'
  AND street = '{$s}'
   ";
  $res = mysqli_query($link, $sql) or exit($la_151_2." (i.i-01) ".$sql."  ".mysqli_error($link)."]");//"Похибка при виконанні запиту до БД. "
  if (mysqli_num_rows($res)) { //строка знайдена
    $row = mysqli_fetch_assoc($res);
    return $row['strid'];
  } else { //добавить запись
    $sql = "INSERT INTO street (town_pre, town, street_pre, street )
    VALUES ('{$t_p}','{$t}','{$s_p}','{$s}')";
    mysqli_query($link, $sql) or exit($la_151_2." ".$sql.mysqli_error());//"Похибка при виконанні запиту до БД. "
    return mysqli_insert_id($link);
  }
}

//пошук ключа (funid) по строці
//+ додаванння запису, якщо строка не знайдена
function get_func($link, $f, $findex) {
  $f = mysqli_real_escape_string($link, $f );//екрануємо апострофи
  $sql = "SELECT funid FROM func WHERE func = '{$f}'";
  $res = mysqli_query($link, $sql) or exit($la_151_2." (i.i-02) ".$sql." ".mysqli_error($link)."]");//"Похибка при виконанні запиту до БД. "
  if (mysqli_num_rows($res)) { //строка знайдена
    $row = mysqli_fetch_assoc($res);
    return $row['funid'];
  } else { //додати запись
    $sql = "INSERT INTO func (func, funindex) VALUES ('{$f}', '{$findex}')";
    mysqli_query($link, $sql) or exit($la_151_2." ".$sql. " ".mysqli_error());//"Похибка при виконанні запиту до БД. "
    return mysqli_insert_id($link);
  }
}


//пошук ключа (offid) по строці
//+ додаванння запису, якщо строка не знайдена
function get_office($link, $o) {
  $sql = "SELECT offid
  FROM office
  WHERE office = '{$o}'";
  $res = mysqli_query($link, $sql) or exit($la_151_2." (i.i-02) ".$sql." ".mysqli_error($link)."]");//"Похибка при виконанні запиту до БД. "
  if (mysqli_num_rows($res)) { //строка знайдена
    $row = mysqli_fetch_assoc($res);
    return $row['offid'];
  } else { //добавить запись
    $sql = "INSERT INTO office (office) VALUES ('{$o}')";
    mysqli_query($link, $sql) or exit($la_151_2." ".$sql. " ".mysqli_error());//"Похибка при виконанні запиту до БД. "
    return mysqli_insert_id($link);
  }
}

//пошук ключа Відділу (branid) по строці
//+додаванння запису, якщо строка не знайдена
function get_branid($link, $br, $branindex) {
  $br = mysqli_real_escape_string($link, $br );//екрануємо апострофи
  //$bi = mysqli_real_escape_string($link, 	$bi );//екрануємо апострофи
  $sql = "SELECT branid FROM branch WHERE branch = '{$br}'";
  $res = mysqli_query($link, $sql) or exit($la_151_2." ".$sql. " ".mysqli_error());//"Похибка при виконанні запиту до БД. "
  if (mysqli_num_rows($res)) { //строка найдена
    $row = mysqli_fetch_assoc($res);
    return $row['branid'];
  } else { //добавить запись
    $sql = "INSERT INTO branch ( branch, branindex ) VALUES ('{$br}', '{$branindex}')";
    mysqli_query($link, $sql) or exit($la_151_2." ".$sql. " ".mysqli_error());//"Похибка при виконанні запиту до БД. "
    return mysqli_insert_id($link);
  }
}



include_once('../base.inc');
//зняти обмеження часу виконання
@set_time_limit(0);
//видалити старі записи
$sql = "DELETE FROM ophone";
mysqli_query($link, $sql) or $err = $la_151_2.'importp.inc 115 '.$sql;
$sql = "DELETE FROM street";
mysqli_query($link, $sql) or $err = $la_151_2.'importp.inc 119 '.$sql;
$sql = "DELETE FROM office";
mysqli_query($link, $sql) or $err = $la_151_2.'importp.inc 117 '.$sql;
$sql = "DELETE FROM branch";
mysqli_query($link, $sql) or $err = $la_151_2.'importp.inc 123 '.$sql;
$sql = "DELETE FROM func";
mysqli_query($link, $sql) or $err = $la_151_2.'importp.inc 121 '.$sql;

//відкрити файл
$f = '../install/phones.csv';
if (file_exists($f)) {

  $fp = fopen($f, 'r');
	$cnt = 0;
  while ($row = fgetcsv($fp, 1024, ';')) {
    list($number, $number1, $birthday, $surname, $name, $patronymic,  $office, $branindex, $branch, $funindex, $func, $town_pre, $town, $street_pre, $street, $house, $flat, $sortindex, $userMail, $note) = $row;
    $strid = get_street($link,$town_pre, $town, $street_pre, $street);
    $funid = get_func($link, $func, $funindex);
    //$branid= get_branid($link, $branindex, $branch);
	$branid= get_branid($link, $branch, $branindex);//$branindex cut there adding to other table

	//перетворимо дату на правильний формат
	//$date='12.12.2012'
		
	
	$birthday=@date('Y-m-d', strtotime($birthday));
	$surname=mysqli_real_escape_string($link, $surname);
	
      $offid = get_office($link, $office);
	  
      $sql = "INSERT INTO ophone (number, number1, 	birthday, surname, name, patronymic, offid,  strid, funid, branid, house, flat, note, sortindex, userMail)
      VALUES ('{$number}', '{$number1}', '{$birthday}', '{$surname}', '{$name}', '{$patronymic}', '{$offid}', '{$strid}','{$funid}', '{$branid}', '{$house}', '{$flat}', '{$note}', '{$sortindex}', '{$userMail}')";

    //}
    mysqli_query($link, $sql) or exit("При выполнении запроса [{$sql}] в строці [{$cnt}] произошла ошибка [".mysqli_error()."]");
    $cnt++;
  }
  fclose($fp);
} else {
  $err = $la_151_5;//"Файл '{$f}' не знайдено. Переконайтеся, що файл знаходится в потрібному каталозі."
}
$title = $la_151_8;//"Загрузка бази данних"
include('header.inc');
if (isset($err)) {
?>
<P>
	<?php echo $la_173_1 ?> <!--"Загрузка бази данних з файлу пройшла <STRONG>невдало</STRONG>."-->
</P>
<P CLASS="error">
	<?php echo $la_142 ?> <!--"Увага!"-->
	<?php echo $err ?>
</P>
<P ALIGN="right">
	<?php echo $la_173_1 ?> <!--"Ще раз спопробувати."--> 
		<STRONG>
			<?php $la_174_3?> <!--"невдало"-->		
		</STRONG>.
	<A HREF="loading.php?import=p">
		<?php echo $la_173_3?>  <!--"Загрузити базу данних"-->
	</A>
	<?php echo $la_173_4?> <!--"З файлу"-->
</P>
<?php
} else {
?>
<P>
	<?php echo $la_173_5 ?> <!--"Загрузка бази данних пройшла"--> 
	<STRONG>
		<?php echo $la_173_6 ?> <!--"успішно"-->
	</STRONG>
	. 
	<?php echo $la_173_7 ?>  <!--"Всі старі записи були видалені, потім було додано"--> 
	<STRONG>
		<?php echo $cnt ?>
	</STRONG>
	<?php echo $la_173_4 ?>  <!--"З файлу"	-->
	<STRONG>
		<?php echo $f ?>
	</STRONG>.
</P>
<P ALIGN="right">
	<A HREF="loading.php">
		<?php echo $la_166 ?>  <!--"Загрузка файлів"-->
	</A>
</P>
<?php
}
include('footer.inc');
?>