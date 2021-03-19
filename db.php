<?php
ini_set('error_reporting', E_ALL);
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);


require_once 'connection.php'; // подключаем скрипт 

class dbInterface{
	public $nameTable;
	private $link;
function __construct($nameTable){
	$this->$nameTable=$nameTable;
	$this->link = mysqli_connect($GLOBALS["host"], $GLOBALS["user"], $GLOBALS["password"], $GLOBALS["database"]) 
    or die("error " . mysqli_error($this->link)); 
}
function __destruct(){
	mysqli_close($this->link);
}
function selectValue($nameTable,$nameVarible){
	$query ="select value FROM $nameTable $nameTable WHERE nameVarible=\"$nameVarible\"";
	$result = mysqli_query($this->link, $query) or die("error" . mysqli_error($this->link)); 
	if($result)
	{
		$row = mysqli_fetch_row($result);
		return "$row[0]"; 
		mysqli_free_result($result);
	}	
}
function updateValue($nameTable,$nameVarible,$value){
	$value=htmlentities($value);
	$query ="UPDATE $nameTable SET value = \"$value\" WHERE nameVarible=\"$nameVarible\"";
	mysqli_query($this->link, $query) or die("error" . mysqli_error($this->link)); 
}
function insertIntoTemp($idDevice,$temp,$CPU,$RAM){
	$idDevice=htmlentities($idDevice);
	$temp=htmlentities($temp);
	$CPU=htmlentities($CPU);
	$RAM=htmlentities($RAM);
	$query = "INSERT INTO TEMP(ID,idDevice, date, temp, CPU, RAM) VALUES(NULL,\"$idDevice\",\"21:29 20.02.2021\",\"$temp\",\"$CPU\",\"$RAM\")";
	mysqli_query($this->link, $query) or die("error" . mysqli_error($this->link)); 
}
}
?>
