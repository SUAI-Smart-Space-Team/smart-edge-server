<?php
	require_once 'db.php';
	if(isset($_GET["temp"])&&isset($_GET["CPU"])&&isset($_GET["memUsed"])&&isset($_GET["memUsed"])&&isset($_GET["devId"])){
		$db = new dbInterface("temp");
		$db->insertIntoTemp($_GET["devId"],$_GET["temp"],$_GET["CPU"],$_GET["memUsed"]);
		//http://localhost/setValue.php?devId=testStand&temp=61348&memUsed=718748&CPU=29
	}
?>
