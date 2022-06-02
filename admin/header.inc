<!--
	header.inc
	Верхнє меню
-->
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<HTML>
	<HEAD>
		<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=windows-1251">
		<TITLE>
			phones/admin : <?php echo $title ?>
		</TITLE>
		<LINK REL=stylesheet HREF="../style.css" TYPE="text/css">
	</HEAD>
<BODY BGCOLOR="#FFFFFF">
<?php  include_once('../lang_ua.php'); ?>
<TABLE BORDER="0" CELLSPACING="0" CELLPADDING="4" WIDTH="100%">
	<TR BGCOLOR="#000099">
		<TD WIDTH="30%" VALIGN="top" NOWRAP>
			<P CLASS="nav">
				<A CLASS="nav" HREF="login.php">
					<?php echo $la_63 ?>
				</A>
				<BR><!--"Вихід"-->
				<A CLASS="nav" HREF="index.php">
					<?php echo $la_0 ?>
				</A>
				<BR><!--"Додому"-->
				<A CLASS="nav" HREF="info.php">
					<?php echo $la_129?>
				</A>
				<BR><!--"Інформація"-->
				<A CLASS="nav" HREF="message.php">
					<?php echo $la_69 ?>
				</A>
				<BR><!--"Подивитись повідомлення"-->
				<A CLASS="nav" HREF="password.php">
					<?php echo $la_70 ?>
				</A>
				<BR><!--"Змінити пароль"-->
				<A CLASS="nav" HREF="phone.php">
					<?php echo $la_71 ?>
				</A>
				<BR><!--"Оновити запис"-->
				<A CLASS="nav" HREF="quote.php">
					<?php echo $la_72 ?>
				</A>
				<BR><!--"Оновити цитати"-->
				<A CLASS="nav" HREF="loading.php">
					<?php echo $la_73 ?>
				</A>
				<BR><!--"Завантажити файли"-->
			</P>
		</TD>
		<TD WIDTH="70%" ALIGN="right" VALIGN="top">
			<P CLASS="nav">
				<?php echo $la_65 ?>
			</P>
			<P CLASS="big">
				<?php echo $la_10 ?>
				<BR>
				<?php echo $title ?>
			</P>
		</TD>
	</TR>
	<TR>
<TD COLSPAN="2">
