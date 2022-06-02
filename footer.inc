				</TD>
			</TR>
			<?php
				include_once('base.inc');
				$sql = "SELECT quote FROM quote ORDER BY RAND() LIMIT 1";
				//$res = mysql_query($sql) or exit('Ошибка при выполнении запроса к базе данных.');
				$res = mysqli_query($link, $sql) or exit('Ошибка при выполнении запроса к базе данных.');
				$row = mysqli_fetch_assoc($res);
				$str = ($row) ? $row['quote'] : $la_151_10; //'(іншим разом)'
			?>
			<TR BGCOLOR="#000099">
				<TD COLSPAN="2" VALIGN="top">
					<P CLASS="nav">
						<?php echo $la_60 ?>
					</P>
					<P CLASS="nav">
						<?php echo $str ?>
					</P>
				</TD>
				<TD ALIGN="right" VALIGN="top">
					<P CLASS="nav">
						&copy;&nbsp;2020, 
						<A CLASS="nav" HREF="http://ssmp.health.kiev.ua/index.php">
							<?php echo $la_1 ?>
						</A>
					</P>	
				</TD>
			</TR>
		</TABLE>
	</BODY>
</HTML>