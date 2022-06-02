
<?php
include_once('lang_ua.php');//добавить коментарии
//define('SUBTITLE', ''. echo $la_2 ;.'');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<HTML>
<HEAD>

<META HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=UTF-8">

<TITLE>
	phones : 
	<?php echo $la_2?>
	<!-- Довідка -->
</TITLE> 
<LINK REL=stylesheet HREF="style.css" TYPE="text/css">
<SCRIPT language="javascript">

function Bookmark() {window.external.AddFavorite(location.href, 'phones = <?php echo $la_11 ?>')} <--"Результати пошуку"-->

</SCRIPT>
</HEAD>
<BODY BGCOLOR="#FFFFFF">
<TABLE BORDER="0" CELLSPACING="0" CELLPADDING="4" WIDTH="100%">
<TR BGCOLOR="#000099">
<TD WIDTH="30%" VALIGN="TOP" NOWRAP>
<P CLASS="nav">
<A CLASS="nav" HREF="index.php"><?php echo $la_0 ?></A><BR><!--"Додому"-->
<A CLASS="nav" HREF="dovidka.php"><?php echo $la_2 ?></A><BR><!--"Довідка"-->
<A CLASS="nav" HREF="searchx.php">
	<?php echo $la_3 ?>
</A>
<BR><!--"Пошук за номером"-->
<!--
<A CLASS="nav" HREF="searchn.php"><?php echo $la_4 ?></A><BR> "Пошук за ім'ям"
<A CLASS="nav" HREF="searcha.php"><?php echo $la_5 ?></A><BR> "Пошук за алфавитом"
-->
<A CLASS="nav" HREF="searcho.php"><?php echo $la_6 ?></A><BR><!--"Пошук за підприємством"-->
<A CLASS="nav" HREF="searchoo.php"><?php echo $la_7 ?></A><BR><!--"Пошук за підприємством та відділом"-->
<A CLASS="nav" HREF="searchp.php"><?php echo $la_8 ?></A><!--"Пошук за адресою"-->
</P>
<P CLASS="nav"><A CLASS="nav" HREF="javascript:Bookmark()"><?php echo $la_9 ?></A><BR></P><!--"Додати у обране"-->
</TD>
<TD ALIGN="center" VALIGN="top">
<IMG SRC="phone.png" WIDTH="150" HEIGHT="150" ALT="phone">
</TD>
<TD WIDTH="30%" ALIGN="right" VALIGN="top">
<P CLASS="nav"><?php echo $la_1 ?>
	<!--КНП "Центр екстреної медичної допомоги та медицини катастроф міста Києва" -->
</P>
<P CLASS="big"><?php echo $la_10 ?><!--"Телефоний довідник:"-->
	<BR><?php echo $la_11 ?> <!--"Результати пошуку"-->
</P>
</TD>
</TR>
<TR>
</TR>
<TR><TD COLSPAN="3">
