<?php
/*
password.php
змінити пароль
 */
session_start();
//перевірити реєстрацію
if (! isset($_SESSION['logdate'])) {
  header('Location: login.php');
  exit;
}
//echo "12-[password.php] _SESSION['logdate']= ".$_SESSION['logdate'] ;
//print_r($_SESSION);

include_once('../lang_ua.php');
include_once('../base.inc');
include('../lang_ua.php');

if (isset($_POST['pswd']) and isset($_POST['pswd2'])) { 
  if (! strlen($_POST['pswd']))
    $err =   $la_143  ; // Необхідно ввести новий пароль
  elseif (strlen($_POST['pswd']) < 6)
    $err =  $la_144 ;// Пароль не повинен бути коротше 6 символів.
  elseif (strlen($_POST['pswd']) > 16)
    $err =  $la_145 ;//Пароль не повинен бути довшим за 16 символів.
  elseif (preg_match("/\W+/", $_POST['pswd']))
    $err =  $la_146 ;//Пароль не має містити інших знаків, крім букв, цифр та символів підкреслення.
  elseif (! strlen($_POST['pswd2']))
    $err = ' $la_147' ; // Необхідно двічі ввести новий пароль
  elseif ($_POST['pswd'] !== $_POST['pswd2'])
    $err = '$la_148'; // При повторному введенні введено інший пароль
  if (! isset($err)) { // помилок немає
    $sql = "UPDATE auth SET pswd = MD5('{$_POST['pswd']}') WHERE authid = '{$_SESSION['authid']}'";
    mysqli_query($link, $sql) or $err = $la_151.'33';
    if (! isset($err)) {
      header('Location: index.php');
      exit;
    }
  }
}
$title = $la_70; //"Змінити пароль"
include('header.inc');
?>
<P><?php echo $la_86 ?></P> <!--"Увага! Для забезпечення надійного захисту додатку обраний Вами пароль має відповідати наступним вимогам:"-->
<UL>
<LI><?php echo $la_87 ?></LI> <!--Дозволяється використовувати тільки букви, цифри й символ підкреслення-->
<LI><?php echo $la_88 ?></LI><!--"Мінімальная довжина - 6 символів."-->
<LI><?php echo $la_89 ?></LI><!--"Максимальна довжина - 16 символів."-->
</UL>
<P><?php echo $la_90 ?></P><!--"З метою запобігання випадкових помилок, Ви маєте ввести свій новий пароль двічі:"-->

<FORM ACTION="password.php" METHOD="post">
<INPUT TYPE="hidden" NAME="post" VALUE="yes">
<TABLE BORDER="0" WIDTH="100%" CELLSPACING="1">
<TR>
  <TD ALIGN="right" WIDTH="50%">
  <?php echo $la_91 ?></TD>
  <TD><INPUT TYPE="password" NAME="pswd" SIZE="16" VALUE=""></TD>
</TR>
<TR>
  <TD ALIGN="right" WIDTH="50%"><?php echo $la_92 ?></TD>
  <TD><INPUT TYPE="password" NAME="pswd2" SIZE="16" VALUE=""></TD>
</TR>
<TR>
  <TD COLSPAN="2" ALIGN="center"><INPUT TYPE="submit" VALUE="<?php echo $la_93 ?>"></TD>
</TR>
</TABLE>
</FORM>
<?php
if (isset($err)) echo "<P CLASS=\"error\">".$la_142." {$err}</P>\r\n"; // "Увага!"
include('footer.inc');
?>