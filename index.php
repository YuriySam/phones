<?php
/*
index.php
*/
include_once('base.inc');
$filename="index.php";
//отримаємо код першої по ссписку організації та виведемо її телефони
$sql = "SELECT offid FROM office LIMIT 1";
$res = mysqli_query($link, $sql) or exit($la_151_2." ".$filename.'index.php 9'. $sql);//"Похибка при виконанні запиту до БД. "
$row = mysqli_fetch_assoc($res);
$value = $row['offid'];

include('searcho.inc');
?>




<?php
//include('footer.inc');
?>