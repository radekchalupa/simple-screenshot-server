<?php
$retval = 0;
exec("./rc-screenshot");
$cesta = 'screenshot.jpeg';
$data = file_get_contents($cesta);
header('Content-type: image/jpeg');
echo($data);
