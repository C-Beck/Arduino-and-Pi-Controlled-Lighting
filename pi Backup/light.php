<html>
<head>
<title>CCCB0C6C2466A2F2E8031C152881EAA982443F585B64DE66F8D2D6FBCAB04010A7C43C922D5AE7D742E66F2C729BA5374698A25A3FBCE194337B2714CCE8362F</title>
<link rel="icon" href="./icon.gif" type="image/gif" />
<link rel="stylesheet" type="text/css" href="./style2.css" />
</head>
<body>
<?php
$light = 0;

if($_POST['opt'] == 'off'){
	$light = 0;
} elseif($_POST['opt'] == 'main'){
	$light = 1;
} elseif($_POST['opt'] == 'sink'){
	$light = 2;
} elseif($_POST['opt'] == 'bath'){
	$light = 3;
} elseif($_POST['opt'] == 'main&sink'){
	$light = 4;
} elseif($_POST['opt'] == 'main&bath'){
	$light = 5;
} elseif($_POST['opt'] == 'sink&bath'){
	$light = 6;
} elseif($_POST['opt'] == 'all'){
	$light = 7;
}

//$file = fopen('/home/pi/log.txt', 'a');

//$time = date('d/m/Y Hie');
//fwrite($file, 'Time: '.$time.' :: ');

//fwrite( $file, 'Ip Address: '.$_SERVER['REMOTE_ADDR'].' :: ');

//fclose($file);

if($_POST['led'] == 'off'){
	$cmd = 'echo '.$light.',0,0,0 > /home/pi/log.txt';
	system($cmd,$return_value);
	($return_value == 0) or die("returned an error: $cmd $return_value");
} elseif($_POST['led'] == 'on'){
	$cmd = 'echo '.$light.','.escapeshellarg($_POST['ledr']).','.escapeshellarg($_POST['ledg']).','.escapeshellarg($_POST['ledb']).' > /home/pi/log.txt';
	system($cmd,$return_value);
	($return_value == 0) or die("returned an error: $cmd $return_value");
}

?>
<h1>CCCB0C6C2466A2F2E8031C152881EAA982443F585B64DE66F8D2D6FBCAB04010A7C43C922D5AE7D742E66F2C729BA5374698A25A3FBCE194337B2714CCE8362F</h1>
<a href="index.php">Back</a>
</body>
</html>
