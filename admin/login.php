<?php
/*
login.php
*/
include_once('../lang_ua.php');
session_start();
//реєстрація є, - виходимо
if (isset($_SESSION['logdate'])) {
  session_unset();
  header('Location: login.php');
  exit;
}

//перевірка паролю
if (isset($_POST['login']) and isset($_POST['pswd'])) {
  include('login.inc');
}



$title = $la_152_1;//'Вхід для адміністратора'
include('header1.inc');


?>
<P>
	<?php echo $la_152 ?> <!--Для доступу до інтерфейсу адміністратора необхідно зареєструватися, вказавши логін та пароль.-->

</P>
<FORM ACTION="login.php" METHOD="post">
<TABLE BORDER="0" WIDTH="100%" CELLSPACING="1">
<TR>
	<TD ALIGN="right" WIDTH="50%"><!--Логін-->
		<?php echo $la_153 ?> : 
	</TD><!--Логін-->
	<TD>
		<INPUT TYPE="text" NAME="login" SIZE="16">
	</TD>
</TR>
<TR>
	<TD ALIGN="right" WIDTH="50%"><!--Пароль-->
		<?php echo $la_154 ?> :  
	</TD><!--Пароль-->
	<TD>
		<INPUT TYPE="password" NAME="pswd" SIZE="16">
	</TD>
</TR>
<TR>
	<TD COLSPAN="2" ALIGN="center">
		<INPUT TYPE="submit" VALUE=<?php echo $la_155 ?> <!--"Зареєструватися."-->
	</TD>
</TR>
</TABLE>
</FORM>
<?php
if (isset($err)) echo "<P CLASS=\"error\">". $la_149 ." {$err}</P>\r\n";
include('footer1.inc');
?>