<?php
	/*
index.php
заход в адмінку
 */
session_start();
//перевірити регістрацію
if (! isset($_SESSION['logdate'])) {
  header('Location: login.php');
  exit;
}

?>

<?php
$_SESSION['x']= "%";//для відображення всіх записів
include('phone.inc');
//$_SESSION['x']= "";//для відображення всіх записів
?>


<?php
//include('footer.inc');
?>