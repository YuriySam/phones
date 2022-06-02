<?php
/*
inserto.inc
додати запис
 */
include_once('../base.inc');
//перевірка на похибки
if (isset($_POST['number'])) {
	if (! strlen($_POST['number'])){}
    //$err = 'Вкажіть номер телефону.';
  elseif (strlen($_POST['number']) > 6)
    $err = $la_150; //'Номер телефон не має перевищувати 6 символів.'
  elseif (preg_match("/[^\d_]+/", $_POST['number']))
    $err = $la_150_1;//'Номер телефону має складатися з цифр'
  elseif (! strlen($_POST['house']))
    $err = $la_150_2;//'Необхідно вказати номер будинку.'
  elseif (strlen($_POST['house']) > 8)
    $err = $la_150_3;//'Номер будинку не має містити більше 8 символів.'
  elseif (strlen($_POST['note']) > 250)
    $err = $la_150_4;//'Примітки не мають містити більше 250 символів.'
	elseif (strlen($_POST['sortindex']) > 4)
    $err = $la_150=_5;//'Індекс Сортування не повинен містити більше 4 цифр.'
  elseif (preg_match("/[^\d_]+%/", $_POST['sortindex']))
    $err = $la_150_6;//'Індекс сортування має бути цілим числом'
 
  if (! isset($err)) { 
  
	$input_surname = addslashes($_POST['surname']);//екранування спецсимволів (\)
	
    $sql = "INSERT INTO ophone SET
	number='{$_POST['number']}', 
	number1='{$_POST['number1']}',
	offid='{$_POST['offid']}', 
	strid='{$_POST['strid']}', 
	funid='{$_POST['funid']}',
	branid='{$_POST['branid']}',
	surname='{$input_surname}',
    name='{$_POST['name']}',
    patronymic='{$_POST['patronymic']}',
    birthday='{$_POST['birthday']}',
	house='{$_POST['house']}', 
	flat='{$_POST['flat']}', 
	note='{$_POST['note']}',
	sortindex='{$_POST['sortindex']}',
	userMail='{$_POST['userMail']}'
	";
	
	
    $res = mysqli_query($link, $sql) or exit( $la_151_2."inserto.inc line30".$sql);//"Похибка при виконанні запиту до БД. "
	
    header("Location: phone.php?x={$_SESSION['x']}");
    exit;
  }
}

//отримання даних обраного запису
$sql = "SELECT * FROM
ophone WHERE
id = '{$_GET['id']}'";

$res = mysqli_query($link,$sql) or exit($la_151_2.' updateo.inc lin '. $sql);//"Похибка при виконанні запиту до БД. "
if (! mysqli_num_rows($res)) {
  header("Location: phone.php?x={$_SESSION['x']}");
  exit;
}
$row = mysqli_fetch_assoc($res);



//список вулиць 
$sql_street = "SELECT strid, town_pre, town, street_pre, street FROM street ORDER BY street";
$res_street = mysqli_query($link,$sql_street) or exit($la_151_2.' '.$sql_street);//"Похибка при виконанні запиту до БД. "
$lst_street = '<SELECT NAME="strid">';
$val_street = (isset($_POST['strid'])) ? $_POST['strid'] : $row['strid'];
while ($row_street = mysqli_fetch_assoc($res_street)) {
  $sel_street = ($row_street['strid'] == $val_street) ? ' SELECTED' : '';
  $lst_street .= "<OPTION VALUE=\"{$row_street['strid']}\"{$sel_street}>{$row_street['town_pre']} {$row_street['town']}, {$row_street['street_pre']} {$row_street['street']} </OPTION>";
}
$lst_street .= '</SELECT>';

//список організацій
$sql2 = "SELECT offid, office FROM office ORDER BY office";
$res2 = mysqli_query($link,$sql2) or exit($la_151_2.' '.$sql2);//"Похибка при виконанні запиту до БД. "
$lst2 = '<SELECT NAME="offid">';
$val = (isset($_POST['offid'])) ? $_POST['offid'] : $row['offid'];
while ($row2 = mysqli_fetch_assoc($res2)) {
  $sel = ($row2['offid'] == $val) ? ' SELECTED' : '';
  $lst2 .= "<OPTION VALUE=\"{$row2['offid']}\"{$sel}>{$row2['office']}</OPTION>";
}
$lst2 .= '</SELECT>';

//створити список <!-- Відділ -->
$sql_branch = "SELECT branid, branch FROM branch ORDER BY branid";
$res_branch = mysqli_query($link,$sql_branch) or exit($la_151_2.' sql_branch = '.$sql_branch);//"Похибка при виконанні запиту до БД. "
$lst_branch = '<SELECT NAME="branid">';
$val_branch = (isset($_POST['branid'])) ? $_POST['branid'] : $row['branid'];
while ($row_branch = mysqli_fetch_assoc($res_branch)) {
  $sel_branch = ($row_branch['branid'] == $val_branch) ? ' SELECTED' : '';
  $lst_branch .= "<OPTION VALUE=\"{$row_branch['branid']}\"{$sel_branch}>{$row_branch['branch']}</OPTION>";
}
$lst_branch .= '</SELECT>';

//створити список <!-- Посада -->
$sql_func = "SELECT funid, func FROM func ORDER BY func";
$res_func = mysqli_query($link,$sql_func) or exit('Похибка виконання запиту до БД.'. $sql_func);
$lst_func = '<SELECT NAME="funid">';
$val_func = (isset($_POST['funid'])) ? $_POST['funid'] : $row['funid'];
while ($row_func = mysqli_fetch_assoc($res_func)) {
  $sel_func = ($row_func['funid'] == $val_func) ? ' SELECTED' : '';
  $lst_func .= "<OPTION VALUE=\"{$row_func['funid']}\"{$sel_func}>{$row_func['func']}</OPTION>";
}
$lst_func .= '</SELECT>';


include_once('../lang_ua.php');
$title = $la_140;//<!--Додавання запису-->
include_once('header.inc');
?>

<P><?php echo $la_141 ?></P><!--  Зараз вы можете додати новий запис (<STRONG>офісний номер</STRONG>):-->

<FORM ACTION="phone.php?insert=o" METHOD="post">
<TABLE WIDTH="100%" CELLPADDING="2" CELLSPACING="1" BORDER="0">

<TR> <!-- ВАТС-->
	<TD ALIGN="right" WIDTH="50%">
		<?php echo $la_34 ?>:
	</TD> <!-- ВАТС-->
	<TD>
		<INPUT TYPE="text" NAME="number" SIZE="6"
		VALUE="<?php if (isset($_POST['number']))
          echo $_POST['number'];
        else echo $row['number']; ?>">
	</TD> <!-- ВАТС-->
</TR> <!-- ВАТС-->


<TR>  <!-- МАТС-->
	<TD ALIGN="right" WIDTH="50%">
		<?php echo $la_35 ?>:
	</TD>  <!-- МАТС-->
	<TD><INPUT TYPE="text" NAME="number1" SIZE="6"
		VALUE="<?php if (isset($_POST['number1']))
          echo $_POST['number1'];
        else echo $row['number1']; ?>">
	</TD> <!-- МАТС-->
</TR>  <!-- МАТС-->

<TR>  <!-- Підприємство-->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_37 ?>:  <!-- Підприємство-->
  </TD>
  <TD><?php echo $lst2 ?></TD>  <!-- Підприємство-->
</TR>  <!-- Підприємство-->

<TR><!-- Відділ/Підрозділ -->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_36 ?> <!-- Відділ/Підрозділ -->
  </TD>
	<TD>
       <?php echo $lst_branch ?>
  </TD> <!-- Відділ/Підрозділ -->
</TR> <!-- Відділ/Підрозділ -->

<TR>  <!-- Посада-->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_45 ?>:  <!-- Посада-->
  </TD>
  <TD><?php echo $lst_func ?></TD>  <!-- Посада-->
</TR>  <!-- Посада-->

<TR>  <!-- Прізвище -->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_132 ?>:  <!-- Прізвище-->
  </TD>
  <TD>
  <INPUT TYPE="text" NAME="surname" SIZE="12" VALUE="<?php if (isset($_POST['surname'])) echo $_POST['surname']; else echo $row['surname']; ?>">
  </TD>  <!-- Прізвище-->
</TR>  <!-- Прізвище-->

<TR>  <!-- Ім'я -->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_133 ?>:  <!-- Ім'я-->
  </TD>
  <TD>
  <INPUT TYPE="text" NAME="name" SIZE="12" VALUE="<?php if (isset($_POST['name'])) echo $_POST['name']; else echo $row['name']; ?>">
  </TD>  <!-- Ім'я-->
</TR>  <!-- Ім'я-->

<TR>  <!-- По батькові -->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_134 ?>:  <!-- По батькові-->
  </TD>
  <TD>
    <INPUT TYPE="text" NAME="patronymic" SIZE="12" VALUE="<?php if (isset($_POST['patronymic'])) echo $_POST['patronymic']; else echo $row['patronymic']; ?>">
	</TD> <!-- По батькові-->
</TR>  <!-- По батькові-->

<TR>  <!-- Дата Народження -->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_137 ?>:  <!-- Дата народження-->
  </TD>
  <TD>
    <INPUT TYPE="date" NAME="birthday" SIZE="12" VALUE="<?php if (isset($_POST['birthday'])) echo $_POST['birthday']; else echo $row['birthday']; ?>">
	</TD> <!-- Дата народження-->
</TR>  <!-- Дата народження-->

<TR> <!-- Населений пункт та вулиця:-->
  <TD ALIGN="right" WIDTH="50%" SIZE= "20">
  <?php echo $la_103 ?> <!-- Населений пункт та вулиця:-->
  </TD><!-- Населений пункт та вілиця:-->
  <TD><?php echo $lst_street ?></TD> <!-- Населений пункт та вулиця:-->
</TR> <!-- Населений пункт та вулиця:-->

<TR> <!-- Будинок-->
  <TD ALIGN="right" WIDTH="50% SIZE="4"">
    <?php echo $la_104 ?> <!-- Будинок-->
  </TD> <!-- Будинок-->
  <TD>
    <INPUT TYPE="text" NAME="house" SIZE="8" VALUE="<?php if (isset($_POST['house'])) echo $_POST['house']; else echo $row['house']; ?>"> <!-- Будинок-->
  </TD> <!-- Будинок-->
</TR> <!-- Будинок-->

<TR><!-- Квартира (кімната, офіс):-->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_105 ?><!-- Квартира (кімната, офіс):-->
  </TD><!-- Квартира (кімната, офіс):-->
  <TD><!-- Квартира (кімната, офіс):-->
    <INPUT TYPE="text" NAME="flat" SIZE="4" VALUE="<?php if (isset($_POST['flat'])) echo $_POST['flat']; else echo $row['flat']; ?>"> (0 = нет значения)
  </TD><!-- Квартира (кімната, офіс):-->
</TR><!-- Квартира (кімната, офіс):-->

<TR>  <!-- Примітки -->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_136 ?>:  <!-- Примітки-->
  </TD>
  <TD>
    <INPUT TYPE="text" NAME="note" SIZE="50" VALUE="<?php if (isset($_POST['note'])) echo $_POST['note']; else echo $row['note']; ?>">
  </TD> <!-- Примітки-->
</TR>  <!-- Примітки-->

<TR>  <!-- Порядковий номер для сортування записів -->
  <TD ALIGN="right" WIDTH="50%">
    <?php echo $la_138 ?>:  <!-- Порядковий номер для сортування записів-->
  </TD>
  <TD>
    <INPUT TYPE="text" NAME="sortindex" SIZE="50" VALUE="<?php if (isset($_POST['sortindex'])) echo $_POST['sortindex']; else echo $row['sortindex']; ?>">
  </TD> <!-- Порядковий номер для сортування записів-->
</TR>  <!-- Порядковий номер для сортування записів-->

<TR>  <!-- Внутрішня поштова адреса -->
  <TD ALIGN="right" WIDTH="50%">
	
    <?php echo $la_139 ?>:  <!-- Внутрішня поштова адреса-->
  </TD>
<TD>
    <INPUT TYPE="text" NAME="userMail" SIZE="50" VALUE="<?php if (isset($_POST['userMail'])) echo $_POST['userMail']; else echo $row['userMail']; ?>">
	(Наприклад: example@ambulance.kiev.ua)
  </TD> <!-- Внутрішня поштова адреса-->
</TR>  <!-- Внутрішня поштова адреса-->

<TR> <!-- Додати -->
    <TD COLSPAN="2" ALIGN="center"><INPUT TYPE="submit" VALUE=" <?php echo $la_131 ?>"> <!-- Додати -->
    </TD> <!-- Додати -->
  </TR> <!-- Додати -->

</TABLE>
</FORM>
<?php
if (isset($err)) {
?>
<P CLASS="error">Увага! <?php echo $err ?></P>
<?php
}
include ('footer.inc');
?>