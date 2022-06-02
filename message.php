<?php
/*
message.php
*/
if (isset($_POST['note'])) { //
  $note = htmlspecialchars($_POST['note'], ENT_QUOTES);
  if (empty($note))
    $err = $la_175_1; //'Необхідно ввести текст повідомлення.'
  elseif (strlen($note) > 2000)
    $err = $la_175_2;//'Текст повідомлення не повинен бути більший за 2000 символів.'
  if (! isset($err)) { 
    include('base.inc');
    $sql = "INSERT INTO message (message, date, host) VALUES ('{$note}', NOW(), '{$REMOTE_ADDR}')";
    mysqli_query($link, $sql) or $err = $la_175_3;//'Не вдалося відправити повідомлення.'
    if (! isset($err)) { 
      header('Location: index.php');
      exit;
    }
  }
}
$title = $la_175_4;//'Повідомлення адміністратору'
include('header.inc');
?>
<P>
  <?php echo $la_61?> <!--"Побажання й пропозиції щодо покращення даного додатку направляйте <STRONG> розробнику додатка </STRONG> за допомогою цієї форми зворотнього зв'язку. "-->
 </P>
<!--
<P ALIGN="right">
	<A HREF="mailto:@ukr.net?subject=phones">@ukr.net
</A></P>
-->
<P>
	<?php echo $la_66?> <!--"Зауваження з приводу  <STRONG> змісту </STRONG> довідника (наприклад, якщо Ви не знайшли потрібного номера в довіднику, яле впевнені, що він існує) направляйте <STRONG>адміністратору додатка</STRONG>, заповнюйте форму на цій сторінці. Якщо Ви хочете отримати відповідь на свое повідомлення, вкажіть в тексті свої координати (ім'я, e-mail, телефон)."-->
</P>
<P>
	<?php echo $la_67?> <!--"Текст повідомлення для адміністратора додатка (не більше 2000 знаків)"-->
	:
</P>
<FORM ACTION="message.php" METHOD="post">
	<P ALIGN="CENTER">
		<TEXTAREA NAME="note" COLS="48" ROWS="4" WRAP="soft">
			<?php if (isset($_POST['note'])) echo $_POST['note'] ?>
		</TEXTAREA>
	</P>
	<P ALIGN="CENTER">
		<INPUT TYPE="submit" value= <?php echo $la_68?> "> <!--"Надіслати"-->
	 </P>
</FORM>
<?php
if (isset($err)) {
?>
<P CLASS="error">
	<?php echo $la_142?> 	<!--"Увага!" -->
	<?php echo $err ?>
</P>
<?php
}
include('footer.inc');
?>