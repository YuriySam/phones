<?php

/*
base.inc
підключення бо БД
*/

define('BASENAME', 'phones');
define('HOSTNAME', 'localhost');
define('USERNAME', 'root');
define('PASSWORD', '');




$link=mysqli_connect(HOSTNAME, USERNAME, PASSWORD, BASENAME) or exit($la_151_1.(BASENAME).  mysqli_connect_error());//"Похибка при підключенні до БД ";
// Check connection
if (!$link) {
  die("Connection failed: " . mysqli_connect_error());
}


?>