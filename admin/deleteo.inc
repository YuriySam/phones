<?php
/*
deleteo.inc
*/
include_once('../base.inc');
$sql = "DELETE FROM ophone WHERE id = '{$_GET['id']}'";
mysqli_query($link, $sql) or exit('Похибка виконання запиту до БД. 4 deleteo.inc '.$sql);
header("Location: phone.php?x={$_SESSION['x']}");
?>