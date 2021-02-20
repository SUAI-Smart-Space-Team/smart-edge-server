<?php
require_once 'db.php'; // подключаем скрипт
$db = new dbInterface("frontData");


$array = array(
	"pumpColor" => $db->selectValue("frontData","pumpColor"), 
	"coolerColor" => $db->selectValue("frontData","coolerColor"), 
	"pumpSpeed" => $db->selectValue("frontData","pumpSpeed"), 
	"coolerSpeed" => $db->selectValue("frontData","coolerSpeed"), 
	"temp"=>"49.173",
	"CPU"=>"5",
	"memUsed"=>"1174276",
);

 

$json = json_encode($array);

echo "[$json]";
?>
