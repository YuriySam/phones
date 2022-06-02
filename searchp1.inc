<?php
/*
serchp1.inc
дивимось номер будинку по обраній вулиці
 */
include('base.inc');
//список домов
$sql = "SELECT DISTINCT street, house 
FROM ophone, street 
WHERE 
street.strid=ophone.strid 
AND 
ophone.strid='{$value}' 
ORDER BY house";
$res = mysqli_query($link, $sql) or exit($la_151_2.'serchp1.inc 15'.$sql);//"Похибка при виконанні запиту до БД. "
$title = $la_150_10;//"Пошук по адресі."
include('header.inc');
if (mysqli_num_rows($res)) {
?>
<P><?php echo $la_75 ?>:</P> <!--"Наразі оберіть номер будинку на обраній Вами вулиці"-->

<FORM ACTION="searchp.php" METHOD="get">
<INPUT TYPE="hidden" NAME="s" VALUE="<?php echo $value ?>">
<P ALIGN="center">
<SELECT NAME="h" SIZE="1">
<?php
  while ($row = mysqli_fetch_assoc($res)) {
?>
	<OPTION VALUE="<?php echo urlencode($row['house']) ?>"><?php echo $row['street'].", ".$row['house'] ?></OPTION>
<?php
  }
?>
</SELECT>
</P>
<P ALIGN="center"><INPUT TYPE="submit" VALUE="<?php echo $la_29 ?> "></P><!--"Пошук"-->
</FORM>
<?php
} else {
?>
<P><?php echo $la_48 ?>.</P><!--"За Вашим запитом записів не знайдено"-->
<?php
  include('notfnd.inc');
}
include('footer.inc');
?>
