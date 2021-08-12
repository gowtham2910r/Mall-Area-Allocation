<html>
	<body>
		<form name="frm" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post">
		<label>Name: </label><input type="text" name="shop_name" /><br/>
		<label>Area: </label><input type="number" name="req_area" min=100 max=1000/><br/>
		<input type="submit"/>
		</form>
	</body>
</html>

<?php
   
   $dbhost = 'localhost';
   $dbuser = 'root';
   $dbpass = '';
   $conn = mysqli_connect($dbhost, $dbuser, $dbpass,'test');   
   if(mysqli_connect_errno()) {
	  die('Could not connect: ' . mysqli_connect_errno());
   }   
   if($_SERVER["REQUEST_METHOD"] == "POST"){	
	   //echo "<script>alert('EN')</script>";
	   $shopName = $_POST["shop_name"];
	   $area = $_POST["req_area"];
	   $shopName = str_replace(' ', '_', $shopName);
	   $sql = "SELECT Type,Rating FROM data_db WHERE Shop_Name = '" . $shopName."'";
	   $result = mysqli_query( $conn, $sql );   
	   $row = mysqli_fetch_assoc($result); 
	   $check1 = true;
	   $myfile = fopen("data.txt", "w") or die("Unable to open file!");
	   fwrite($myfile,$shopName);
	   fwrite($myfile," ");
	   fwrite($myfile, $row["Type"]);
	   fwrite($myfile," ");
	   fwrite($myfile, $row["Rating"]);
	   fwrite($myfile," ");
	   fwrite($myfile,date("Y"));
	   fwrite($myfile," ");
	   fwrite($myfile,date("m"));
	   fwrite($myfile," ");
	   fwrite($myfile,date("d"));
	   fwrite($myfile," ");
	   fwrite($myfile,$area);
	   fclose($myfile);
	   shell_exec("setPriority.exe");
	   echo "<script>alert('Your data has been entered')</script>";
   }
	   

   
   
   
   mysqli_close($conn);
?>