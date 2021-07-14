-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Хост: localhost:3306
-- Время создания: Фев 21 2021 г., 10:00
-- Версия сервера: 8.0.23
-- Версия PHP: 8.0.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `compstore`
--
CREATE DATABASE IF NOT EXISTS `compstore` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin;
USE `compstore`;

-- --------------------------------------------------------

--
-- Структура таблицы `frontdata`
--

CREATE TABLE `frontdata` (
  `nameVarible` text COLLATE utf8_bin,
  `value` text COLLATE utf8_bin
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Дамп данных таблицы `frontdata`
--

INSERT INTO `frontdata` (`nameVarible`, `value`) VALUES
('pumpColor', '255, 128, 0'),
('pumpColor', '255, 128, 0'),
('coolerSpeed', '98'),
('coolerSpeed', '98'),
('coolerColor', '64, 0, 128'),
('coolerColor', '64, 0, 128'),
('pumpSpeed', '49'),
('pumpSpeed', '49');

-- --------------------------------------------------------

--
-- Структура таблицы `temp`
--

CREATE TABLE `temp` (
  `ID` int NOT NULL,
  `idDevice` text COLLATE utf8_bin,
  `date` text COLLATE utf8_bin,
  `temp` text COLLATE utf8_bin,
  `RAM` text COLLATE utf8_bin,
  `CPU` text COLLATE utf8_bin
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Дамп данных таблицы `temp`
--

INSERT INTO `temp` (`ID`, `idDevice`, `date`, `temp`, `RAM`, `CPU`) VALUES
(1, '21:29 20.02.2021', '1234', '12', '1900', '1'),
(2, '21:29 20.02.2021', '1234', '12', '1900', '1'),
(3, 'testStand', '21:29 20.02.2021', '61348', '718748', '29'),
(4, 'testStand', '21:29 20.02.2021', '61348', '718748', '29'),
(5, 'testStand', '21:29 20.02.2021', '61348', '718748', '29'),
(6, 'testStand', '21:29 20.02.2021', '61348', '718748', '29'),
(7, 'testStand', '21:29 20.02.2021', '61348', '718748', '29');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `temp`
--
ALTER TABLE `temp`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `temp`
--
ALTER TABLE `temp`
  MODIFY `ID` int NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
