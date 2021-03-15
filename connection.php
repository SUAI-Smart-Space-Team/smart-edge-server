<?php
ini_set('error_reporting', E_ALL);
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);


$host = 'db:3306'; // адрес сервера 
$database = 'compstore'; // имя базы данных
$user = getenv('MYSQL_USER');; // имя пользователя
$password = getenv('MYSQL_PASSWORD');; // пароль
?>