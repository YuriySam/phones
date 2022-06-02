<?php
/*
quote.php

*/

session_start();
//перевірка реєстрації
if (! isset($_SESSION['logdate'])) {
  header('Location: login.php');
  exit;
}
$current_file_name= "quote.php";
include_once('../lang_ua.php');
include_once('../base.inc');
//додати цитату
if (isset($_POST['quote'])) {
  if (! strlen($_POST['quote']))
    $err = $la_156; //"Необходимо ввести текст цитаты."
  elseif (strlen($_POST['quote']) > 2000)
    $err = $la_157;//"Текст цитати не повинен перевищувати 2000 знаків."
  if (! isset($err)) {
    $quote = htmlspecialchars($quote);
    $sql = "INSERT INTO quote SET quote = '{$quote}'";
    mysqli_query($link, $sql) or $err =$la_151." 25"." ".$current_file_name;//"Похибка виконання запиту до БД на оновлення записів."
  }
} elseif (isset($_GET['delete'])) { //удалить цитату
  $sql = "DELETE FROM quote WHERE id = '{$_GET['delete']}'";
  mysqli_query($link, $sql) or $err = $la_151." 29"." ".$current_file_name;//"Похибка виконання запиту до БД на оновлення записів."
}

//знайти кількість сторінок
define('NUM', 10); //кількість цитат на сторінці
$sql = "SELECT COUNT(*) AS cnt FROM quote";
$res = mysqli_query($link, $sql) or exit($la_151." 34"." ".$current_file_name);//"Похибка виконання запиту до БД на оновлення записів."
$row = mysqli_fetch_assoc($res);
$cnt = $row['cnt'];

//обрати сторінку
if (isset($_GET['page'])) {
  if ($_GET['page'] < 1 or $_GET['page'] > ceil($cnt / NUM)) {
    header('Location: quote.php');
    exit;
  }
  $page = $_GET['page'];
} else {
  $page = 1;
}

//створити посилання на сторінки
$lnk = '';
for ($i = 1; $i <= ceil($cnt / NUM); $i++) {
  $lnk .= ($i == $page) ? "[<STRONG>{$i}</STRONG>] " : "[<A HREF=\"quote.php?page={$i}\">{$i}</A>] ";
}

//відобразити записи
$ofs = ($page - 1) * NUM;
$sql = "SELECT * FROM quote LIMIT {$ofs}, ".NUM;
$res = mysqli_query($link, $sql) or exit($la_151." 34"." ".$current_file_name.mysqli_error());

$title = $la_108;//"Оновлення цитат"
include('header.inc');

if (mysqli_num_rows($res)) {
?>
<P><?php echo $la_109 ?><!--"Всього цитат:"-->
  <STRONG>
    <?php echo $cnt ?>

    </STRONG>.
  </P>
<P>
  <?php echo $la_109 ?><!--"Всього цитат:"-->
 <?php echo $lnk ?>
 </P>
<TABLE WIDTH="100%" CELLPADDING="2" CELLSPACING="1" BORDER="0">
<TR CLASS="head">
  <TD>№</TD>
  <TD><?php echo $la_82 ?></TD><!--"Текст"-->
  <TD><?php echo $la_111 ?></TD><!--"Дія"-->
</TR>
<?php
  $n = $ofs + 1;
  while ($row = mysqli_fetch_assoc($res)) {
?>
<TR CLASS="data">
  <TD>
    <?php echo $n++ ?>
    </TD>
    <TD>
      <?php echo $row['quote'] ?>
      </TD>
      <TD>
        <A HREF="quote.php?delete=<?php echo $row['id'] ?>&page=<?php echo $page ?>">
        <?php echo $la_96 ?><!--"Видалити"-->
        </A>
      </TD>
    </TR>
<?php
  }
?>
</TABLE>
<?php
} else {
?>
<P><?php $la_158?></P> <!--"Цитат немає."-->
<?php
}
//форма для додавання цитат
?>
<P>
<?php echo $la_112 ?><!--"Для того, щоб <STRONG>додати нову цитату</STRONG>, введіть текст в поле й натисніть кнопку:"-->
</P>
<FORM ACTION="quote.php?page=<?php echo $page ?>" METHOD="post">
<P ALIGN="CENTER">
	<TEXTAREA NAME="quote" COLS="48" ROWS="4" WRAP="soft" WIDTH="50%">
		<?php if (isset($err) and isset($_POST['quote'])) echo $_POST['quote'] ?>
	</TEXTAREA></P>
<P ALIGN="CENTER">
	<INPUT TYPE="submit" value="<?php echo $la_131?>"> <!--"Додати"-->
		
</P>
</FORM>

<?php
	if (isset($err)) echo "<P CLASS=\"error\">".$la_149." {$err}</P>\r\n"; // "Увага!"
	include('footer.inc');
?>