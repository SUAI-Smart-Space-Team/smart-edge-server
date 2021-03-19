<?php
require_once 'db.php'; // подключаем скрипт
$db = new dbInterface("frontData");


$array = array(
	"pumpColor" => $db->selectValue("frontdata","pumpColor"), 
	"coolerColor" => $db->selectValue("frontdata","coolerColor"), 
	"pumpSpeed" => $db->selectValue("frontdata","pumpSpeed"), 
	"coolerSpeed" => $db->selectValue("frontdata","coolerSpeed"), 
	"temp"=>"49.173",
	"CPU"=>"5",
	"memUsed"=>"1174276",
);

 

$json = json_encode($array);

echo "[$json]";
?>
