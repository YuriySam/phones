<?php
/*
message.php
адмінка
- перевірка повідомлень
 */
session_start();
//перевірка реєстрації
if (! isset($_SESSION['logdate'])) {
  header('Location: login.php');
  exit;
}
include_once('../lang_ua.php');
include_once('../base.inc');
if (isset($_POST['delete'])) {
  //видалити записи
  foreach ($_POST['delete'] as $del) {
    $sql = "DELETE FROM message WHERE id = '{$del}'";
    mysqli_query($link, $sql) or $err = 'Похибка виконання запиту до БД. на видення записів. 19';
  }
}
//кількість сторінок
define('NUM', 5); //кількість повідомлень на сторінці
$sql = "SELECT COUNT(*) AS cnt FROM message";
$res = mysqli_query($link, $sql) or exit('Похибка виконання запиту до БД.25.');
$row = mysqli_fetch_assoc($res);
$cnt = $row['cnt'];

//обрати сторінку
if (isset($_GET['page'])) {
  if ($_GET['page'] < 1 or $_GET['page'] > ceil($cnt / NUM)) {
    header('Location: message.php');
    exit;
  }
  $page = $_GET['page'];
} else {
  $page = 1;
}
//ярлики сторінок
$lnk = '';
for ($i = 1; $i <= ceil($cnt / NUM); $i++) {
  $lnk .= ($i == $page) ? "[<STRONG>{$i}</STRONG>] " : "[<A HREF=\"message.php?page={$i}\">{$i}</A>] ";
}
//відібрати записи
$ofs = ($page - 1) * NUM;
$sql = "SELECT * FROM message ORDER BY date DESC LIMIT {$ofs}, ".NUM;
$res = mysqli_query($link, $sql) or exit('Похибка виконання запиту до БД.46.'.mysqli_error());
$title = "".$la_77 ; //Подивитись повідомлення
include('header.inc');
if (mysqli_num_rows($res)) {
?>
<P>
  <?php echo $la_78 ?>: <!--Повідомлення показани в порядку їх отримання, починаючи з нових. Всього отримано повідомлень -->
  <STRONG> 
	<?php echo $cnt ?> <!--Видалити відмічені-->
  </STRONG>.
</P>
<FORM ACTION="message.php?page=<?php echo $page ?>" METHOD="post">
<TABLE WIDTH="100%" CELLPADDING="2" CELLSPACING="1" BORDER="0">
<TR CLASS="head">
  <TD>№</TD> <!--№-->
  <TD><?php echo $la_80 ?></TD> <!--Дата-->
  <TD><?php echo $la_81 ?></TD> <!--Адреса-->
  <TD><?php echo $la_82 ?></TD> <!--Текст-->
  <TD><?php echo $la_83 ?></TD> <!--Відмітка-->
</TR>
<?php
  $n = $ofs + 1;
  while ($row = mysqli_fetch_assoc($res)) {
?>
<TR CLASS="data">
  <TD><?php echo $n++ ?></TD>
  <TD><?php echo $row['date'] ?></TD>
  <TD><?php echo $row['host'] ?></TD>
  <TD><?php echo $row['message'] ?></TD>
  <TD><INPUT TYPE="checkbox" NAME="delete[]" VALUE="<?php echo $row['id'] ?>"></TD>
</TR>
<?php
  }
?>
<TR>
  <TD COLSPAN="4" ALIGN="center"><INPUT TYPE="submit" VALUE="<?php echo $la_79 ?>"></TD> <!--Повідомлення показани в порядку їх отримання, починаючи з нових. Всього отримано повідомлень-->
</TR>
</TABLE>
</FORM>
<P><?php echo $la_84 ?>: <?php echo $lnk ?></P> <!--Сторінки-->
<?php
} else {
?>
<P><?php echo $la_84 ?></P> <!--Сторінки-->
<?php
}
if (isset($err)) echo "<P CLASS=\"error\">".$la_142." {$err}</P>\r\n"; // Увага!
include('footer.inc');
?>