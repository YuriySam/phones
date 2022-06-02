<?php
/*
phone.php
змінити запис
 */
session_start();
//перевірити регістрацію
if (! isset($_SESSION['logdate'])) {
  header('Location: login.php');
  exit;
}

//додати запис
if (isset($_GET['insert'])) {
   if ($_GET['insert'] == 'o') { 
    include('inserto.inc');
    exit;
  }
//редагувати запис
} elseif (isset($_GET['update'])) {
   if ($_GET['update'] == 'o') {
    include('updateo.inc');
    exit;
  }
//видалити запис
} elseif (isset($_GET['delete'])) {
   if ($_GET['delete'] == 'o') {
    include('deleteo.inc');
    exit;
  }
} if (isset($_GET['x'])) {//обробка оновлення запису
  $value = urldecode($_GET['x']);
  if (preg_match("/[^\d]+%/", $_GET['x']))
    $err = $la_151_6;//'У рядку запиту слід вводити лише цифри номера - без пробілів та інших сторонніх символів'
  //elseif (! strlen($_GET['x']))
    //$err = 'Вкажіть номер телефону для пошуку.';
  elseif (strlen($_GET['x']) > 8)
    $err = $la_150_7;//'Номер не повинен перевищувати 8 цифр.'
  if (! isset($err)) { 
    $_SESSION['x'] = $_GET['x']; 
    include('phone.inc');
    exit;
  }
}
include('../lang_ua.php');
$title = $la_71; //Оновити запис
include('header.inc');
?>
<P>
  <?php //форма для введення номера для пошуку запису з номером для Оновлення запису ?>
  <?php echo $la_94 ?> <!-- В текстовому полі введіть... -->
</P>
<FORM ACTION="phone.php" METHOD="get">
 <P ALIGN="CENTER"><INPUT TYPE="text" NAME="x" SIZE="10" MAXLENGTH="10" VALUE="<?php if (isset($value)) echo htmlspecialchars($value) ?>"></P>
 <P ALIGN="CENTER"><INPUT TYPE="submit" VALUE=" <?php echo $la_29 ?> "> <!-- Пошук-->
 </P>
</FORM>
<?php
if (isset($err)) {
  ?>  <P CLASS="error"><?php echo $err ?></P>  <?php
}
include('footer.inc');
?>