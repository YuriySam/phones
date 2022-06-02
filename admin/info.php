<?php
/*
info.php
заходимо в адмінку
 */
session_start();
//превірка реєстрації
if (! isset($_SESSION['logdate'])) {
  header('Location: login.php');
  exit;
}
//$title = 'Керування';
include_once('../lang_ua.php');
include_once('header.inc');


?>
<P><?php echo $la_74 ?>:</P><!--"Відомості про попередній вхід (дата, час та місце)"-->
<P ALIGN="right"><STRONG><?php echo $_SESSION['logdate'] ?><BR><?php echo $_SESSION['logaddr'] ?></STRONG></P>
<P><?php echo $la_64 ?>:</P> <!--"Оберіть дію"-->
<P ALIGN="right">
<A HREF="message.php"><?php echo $la_69 ?></A><BR><!--"Подивитись повідомлення"-->
<A HREF="password.php"><?php echo $la_70 ?></A><BR><!--"Змінити пароль"-->
<A HREF="phone.php"><?php echo $la_71 ?></A><BR><!--"Оновити запис"-->
<A HREF="quote.php"><?php echo $la_72 ?></A><BR><!--"Оновити цитати"-->
<A HREF="loading.php"><?php echo $la_73 ?></A><BR>
</P><!--"Завантажити файли"-->
<?php
include('footer.inc');
?>