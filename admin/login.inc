<?php
/*
login.inc
модуль реєстрація
*/

include_once('../base.inc');
include_once('../lang_ua.php');


//отримати данні
$login = preg_replace("/[^\w_\.\-]/", "", $_POST['login']);
$pswd = trim($_POST['pswd']);
//відбити хакерів ;-)
if (strlen($_POST['login']) > 16) {
  $err = $la_149_0;//"Занадто довгий логін. Введіть не більше 16 символів."
} elseif (strlen($_POST['pswd']) > 16) {
  $err = $la_149_1;//"Занадто довгий пароль. Введіть не більше 16 символів."
} elseif (preg_match("/\W+/", $pswd)) {
  $err =  $la_149_2;//"Строка паролю містить недопустимі символи. Введіть коректний пароль."
} else {
  //порівняти зі значенням б БД
  $sql = "SELECT authid, logdate, logaddr FROM auth WHERE login = '{$login}' AND pswd = MD5('{$pswd}')";
  $res = mysqli_query($link,$sql) or exit( $la_151_2); //'Похибка при виконанні запиту до БД. Похибка авторизації.'
  if (mysqli_num_rows($res) == 1) {
    $row = mysqli_fetch_assoc($res);
    $_SESSION['authid'] = $row['authid']; //для зміни паролю
    $_SESSION['logdate'] = $row['logdate']; //дата попереднього входу
    $_SESSION['logaddr'] = $row['logaddr']; //місце попереднього входу
	//REMOTE_ADDR  REMOTE_HOST
	
    //оновити значения
    $sql = "UPDATE auth SET logdate = NOW(), logaddr = '{$_SERVER["REMOTE_ADDR"]}' WHERE login = '{$login}'";
    $res = mysqli_query($link, $sql) or exit($la_149_3); //'Похибка при виконанні запиту до БД. Похибка зміни паролю.'
    header('Location: index.php');
    exit;
  } else {
    $err = $la_149_4;//' Похибка авторизаціє. Перевірте логін та пароль та спробуйте ще раз.'
  }
}
?>