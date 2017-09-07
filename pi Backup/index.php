<html>
<head>
<link rel="icon" href="./icon.gif" type="image/gif" />
<link rel="stylesheet" type="text/css" href="./style.css">
<title>Room #330A Lighting</title>
</head>
<body>
<?php
system('raspistill -w 1920 -h 1080 -t 10 -vf -hf -o /var/www/html/room.jpg');
?>
<h1>Room #330A Lighting</h1>
<form name="opt" action="./light.php" method="post">
<fieldset>
<legend>Lights</legend>
<input type="radio" name="opt" value="off" checked>All Off</input><br />
<input type="radio" name="opt" value="main">Main On</input><br />
<input type="radio" name="opt" value="sink">Main On</input><br />
<input type="radio" name="opt" value="bath">Main On</input><br />
<input type="radio" name="opt" value="main&sink">Main On</input><br />
<input type="radio" name="opt" value="main&bath">Main On</input><br />
<input type="radio" name="opt" value="sink&bath">Main On</input><br />
<input type="radio" name="opt" value="all">All On</input><br />
</fieldset>
<fieldset>
<legend>RGB LED</legend>
<input type="radio" name="led" value="off" checked>Off</input><br />
<input type="radio" name="led" value="on">On</input><br />
R:<input type="text" name="ledr" value=0 /><br />
G:<input type="text" name="ledg" value=0 /><br />
B:<input type="text" name="ledb" value=0 /><br />
<input type="submit" value="Submit" />
</fieldset>
</form>
<br />
<img src="./room.jpg" alt="filler text" width=100% />
</body>
</html>
