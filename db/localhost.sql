-- phpMyAdmin SQL Dump
-- version 4.0.6deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jan 20, 2014 at 05:33 PM
-- Server version: 5.5.34-0ubuntu0.13.10.1
-- PHP Version: 5.5.3-1ubuntu2.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `T1B1`
--
CREATE DATABASE IF NOT EXISTS `T1B1` DEFAULT CHARACTER SET utf8 COLLATE utf8_bin;
USE `T1B1`;

-- --------------------------------------------------------

--
-- Table structure for table `activeevent`
--

CREATE TABLE IF NOT EXISTS `activeevent` (
  `eventId` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `activeevent`
--

INSERT INTO `activeevent` (`eventId`) VALUES
(7);

-- --------------------------------------------------------

--
-- Table structure for table `activephase`
--

CREATE TABLE IF NOT EXISTS `activephase` (
  `phaseId` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `activephase`
--

INSERT INTO `activephase` (`phaseId`) VALUES
(2);

-- --------------------------------------------------------

--
-- Table structure for table `activeround`
--

CREATE TABLE IF NOT EXISTS `activeround` (
  `roundId` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `activeround`
--

INSERT INTO `activeround` (`roundId`) VALUES
(4);

-- --------------------------------------------------------

--
-- Table structure for table `boardmode`
--

CREATE TABLE IF NOT EXISTS `boardmode` (
  `boardMode` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `boardmode`
--

INSERT INTO `boardmode` (`boardMode`) VALUES
(3);

-- --------------------------------------------------------

--
-- Table structure for table `climbereventroundenrollment`
--

CREATE TABLE IF NOT EXISTS `climbereventroundenrollment` (
  `roundId` int(11) NOT NULL,
  `eventId` int(11) NOT NULL,
  `phaseId` int(11) NOT NULL,
  `startNumber` int(11) NOT NULL,
  `polePosition` int(11) NOT NULL,
  PRIMARY KEY (`eventId`,`roundId`,`phaseId`,`startNumber`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

-- --------------------------------------------------------

--
-- Table structure for table `climbers`
--

CREATE TABLE IF NOT EXISTS `climbers` (
  `climberId` int(11) NOT NULL AUTO_INCREMENT,
  `firstname` varchar(20) COLLATE utf8_bin NOT NULL,
  `lastname` varchar(20) COLLATE utf8_bin NOT NULL,
  `nationality` varchar(3) COLLATE utf8_bin NOT NULL,
  `sex` char(1) COLLATE utf8_bin NOT NULL DEFAULT '0',
  PRIMARY KEY (`climberId`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=320 ;

--
-- Dumping data for table `climbers`
--

INSERT INTO `climbers` (`climberId`, `firstname`, `lastname`, `nationality`, `sex`) VALUES
(208, 'Annie', 'Stoor', 'AUT', 'F'),
(209, 'Kathy', 'Wine', 'AUT', 'F'),
(210, 'Barbara', 'Bacher', 'AUT', 'F'),
(211, 'Katharina', 'Posch', 'AUT', 'F'),
(212, 'Magali', 'Hayen', 'BEL', 'F'),
(213, 'Petra', 'R&#367;ži&#269;ková', 'CZE', 'F'),
(214, 'Silvie', 'Rajfová', 'CZE', 'F'),
(215, 'Karolina', 'Nevelikova', 'CZE', 'F'),
(216, 'Katrine', 'Vandet Salling', 'DEN', 'F'),
(217, 'Anna', 'Laitinen', 'FIN', 'F'),
(218, 'Mélanie', 'Sandoz', 'FRA', 'F'),
(219, 'Cécile', 'Avezou', 'FRA', 'F'),
(220, 'Anne-Laure', 'Chevrier', 'FRA', 'F'),
(221, 'Mellie', 'Nevel', 'FRA', 'F'),
(222, 'Margaux', 'Pucheux', 'FRA', 'F'),
(223, 'Gill', 'Peet', 'GBR', 'F'),
(224, 'Sandra', 'Cocos', 'GBR', 'F'),
(225, 'Diane', 'Merrick', 'GBR', 'F'),
(226, 'Helen', 'Haldenby', 'GBR', 'F'),
(227, 'Michaela', 'Tracy', 'GBR', 'F'),
(228, 'Monika', 'Retschy', 'GER', 'F'),
(229, 'Juli', 'Warm', 'GER', 'F'),
(230, 'Friederike', 'Petri', 'GER', 'F'),
(231, 'Valeri', 'Kremer', 'ISR', 'F'),
(232, 'Annalisa', 'De Marco', 'ITA', 'F'),
(233, 'Alexandra', 'Ladurner', 'ITA', 'F'),
(234, 'Jenny', 'Lavarda', 'ITA', 'F'),
(235, 'Andrea', 'Ebner', 'ITA', 'F'),
(236, 'Vera', 'Zijlstra', 'NED', 'F'),
(237, 'Nikki', 'van Bergen', 'NED', 'F'),
(238, 'Rianne', 'van den Berg', 'NED', 'F'),
(239, 'Therese', 'Johansen', 'NOR', 'F'),
(240, 'Hannah', 'Midtbø', 'NOR', 'F'),
(241, 'Ekaterina', 'Andreeva', 'RUS', 'F'),
(242, 'Olga', 'Bibik', 'RUS', 'F'),
(243, 'Olga', 'Iakovleva', 'RUS', 'F'),
(244, 'Tatiana', 'Shemulinkina', 'RUS', 'F'),
(245, 'Anna', 'Gallyamova', 'RUS', 'F'),
(246, 'Yana', 'Chereshneva', 'RUS', 'F'),
(247, 'Dinara', 'Fakhritdinova', 'RUS', 'F'),
(248, 'Mindy', 'Mint', 'SLO', 'F'),
(249, 'Petra', 'Klingler', 'SUI', 'F'),
(250, 'Rebekka', 'Stotz', 'SUI', 'F'),
(251, 'Anouk', 'Piola', 'SUI', 'F'),
(252, 'Natalie', 'Bärtschi', 'SUI', 'F'),
(253, 'Olga', 'Kulish', 'UKR', 'F'),
(254, 'Levgeniia', 'Kazbekova', 'UKR', 'F'),
(255, 'Olga', 'Shalagina', 'UKR', 'F'),
(256, 'Kilian', 'Fischhuber', 'AUT', 'M'),
(257, 'Jakob', 'Schubert', 'AUT', 'M'),
(258, 'Lukas', 'Ennemoser', 'AUT', 'M'),
(259, 'Jan', 'De Smit', 'BEL', 'M'),
(260, 'Nicolas', 'Farcy', 'BEL', 'M'),
(261, 'Emiliyan', 'Kolevski', 'BUL', 'M'),
(262, 'Stefan', 'Avramov', 'BUL', 'M'),
(263, 'Bozhidar', 'Lyubenov', 'BUL', 'M'),
(265, 'Martin', 'Stránik', 'CZE', 'M'),
(266, 'Jan', 'Chvála', 'CZE', 'M'),
(267, 'Robin', 'Vickery', 'DEN', 'M'),
(268, 'Bjørn', 'Arnel Iisager', 'DEN', 'M'),
(269, 'Marco Antonio', 'Jubes Angarita', 'ESP', 'M'),
(270, 'Ignacio', 'Sánchez González', 'ESP', 'M'),
(271, 'Anthony', 'Gullsten', 'FIN', 'M'),
(272, 'Yohann', 'Dechamps', 'FRA', 'M'),
(273, 'Guillaume', 'Glairon Mondet', 'FRA', 'M'),
(274, 'Jonathan', 'Partridge', 'GBR', 'M'),
(275, 'James', 'Garden', 'GBR', 'M'),
(276, 'David', 'Barrans', 'GBR', 'M'),
(277, 'Ben', 'West', 'GBR', 'M'),
(278, 'Nathan', 'Phillips', 'GBR', 'M'),
(279, 'Thomas', 'Tauporn', 'GER', 'M'),
(280, 'Jan', 'Hojer', 'GER', 'M'),
(281, 'Jonas', 'Baumann', 'GER', 'M'),
(282, 'Mathias', 'Conrad', 'GER', 'M'),
(283, 'Stefan', 'Danker', 'GER', 'M'),
(284, 'Dominic', 'Burns', 'IRL', 'M'),
(285, 'Stefano', 'Ghisolfi', 'ITA', 'M'),
(286, 'Michael', 'Piccolruaz', 'ITA', 'M'),
(287, 'Stefan', 'Scarperi', 'ITA', 'M'),
(288, 'Rolands', 'Rugens', 'LAT', 'M'),
(289, 'Jurijs', 'Krasanovs', 'LAT', 'M'),
(290, 'Dmitrijus', 'Monastyreckis', 'LTU', 'M'),
(291, 'Arturas', 'Volkovas', 'LTU', 'M'),
(292, 'Freek', 'Pannekoek', 'NED', 'M'),
(293, 'Ben', 'Buskruit', 'NED', 'M'),
(294, 'Jorg', 'Verhoeven', 'NED', 'M'),
(295, 'Nicky', 'de Leeuw', 'NED', 'M'),
(296, 'John', 'Topper', 'NOR', 'M'),
(297, 'Ken', 'Kan', 'NOR', 'M'),
(298, 'Jakub', 'Glowka', 'POL', 'M'),
(299, 'Aleks', 'de Grote', 'POL', 'M'),
(300, 'Andrzej', 'Mecherzynski-Wiktor', 'POL', 'M'),
(301, 'Jacco', 'Haring', 'POL', 'M'),
(302, 'Mircea', 'Struteanu', 'ROU', 'M'),
(303, 'Dmitrii', 'Sharafutdinov', 'RUS', 'M'),
(304, 'Rustam', 'Gelmanov', 'RUS', 'M'),
(305, 'Yury', 'Novitskiy', 'RUS', 'M'),
(306, 'Arman', 'Ter-Minasyan', 'RUS', 'M'),
(307, 'Aleksei', 'Shchervianin', 'RUS', 'M'),
(308, 'Klemen', 'Be&#269;an', 'SLO', 'M'),
(309, 'Jernej', 'Kruder', 'SLO', 'M'),
(310, 'Benjamin', 'Blaser', 'SUI', 'M'),
(311, 'Remo', 'Sommer', 'SUI', 'M'),
(312, 'Kevin', 'Heiniger', 'SUI', 'M'),
(313, 'Kevin', 'Hemund', 'SUI', 'M'),
(314, 'Viliam', 'Fer&#269;ák', 'SVK', 'M'),
(315, 'Marián', 'Šeliga', 'SVK', 'M'),
(316, 'Sergii', 'Topishko', 'UKR', 'M'),
(317, 'Mykhaylo', 'Shalagin', 'UKR', 'M'),
(318, 'Sergii', 'Karpin', 'UKR', 'M'),
(319, 'Andrew', 'Zhigarev', 'UKR', 'M');

-- --------------------------------------------------------

--
-- Table structure for table `eventenrollment`
--

CREATE TABLE IF NOT EXISTS `eventenrollment` (
  `eventId` int(11) NOT NULL,
  `climberId` int(11) NOT NULL,
  `startNumber` int(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`climberId`,`eventId`),
  UNIQUE KEY `startNumber` (`startNumber`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=106 ;

--
-- Dumping data for table `eventenrollment`
--

INSERT INTO `eventenrollment` (`eventId`, `climberId`, `startNumber`) VALUES
(7, 208, 1),
(7, 224, 2),
(7, 229, 3),
(7, 209, 4),
(7, 221, 5),
(7, 248, 6),
(7, 292, 100),
(7, 293, 101),
(7, 296, 102),
(7, 297, 103),
(7, 299, 104),
(7, 301, 105);

-- --------------------------------------------------------

--
-- Table structure for table `eventphaseenrollment`
--

CREATE TABLE IF NOT EXISTS `eventphaseenrollment` (
  `eventId` int(11) NOT NULL,
  `phaseId` int(11) NOT NULL,
  `sequence` int(11) NOT NULL,
  PRIMARY KEY (`eventId`,`phaseId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `eventphaseenrollment`
--

INSERT INTO `eventphaseenrollment` (`eventId`, `phaseId`, `sequence`) VALUES
(7, 0, 3),
(7, 1, 2),
(7, 2, 1);

-- --------------------------------------------------------

--
-- Table structure for table `events`
--

CREATE TABLE IF NOT EXISTS `events` (
  `eventId` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) COLLATE utf8_bin NOT NULL,
  `date` varchar(20) COLLATE utf8_bin NOT NULL,
  `place` varchar(20) COLLATE utf8_bin NOT NULL,
  `location` varchar(20) COLLATE utf8_bin NOT NULL,
  `international` char(1) COLLATE utf8_bin NOT NULL DEFAULT 'N',
  PRIMARY KEY (`eventId`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=8 ;

--
-- Dumping data for table `events`
--

INSERT INTO `events` (`eventId`, `name`, `date`, `place`, `location`, `international`) VALUES
(7, 'EK', '2013', 'Eindhoven', 'Strijp S', '1');

-- --------------------------------------------------------

--
-- Table structure for table `globals`
--

CREATE TABLE IF NOT EXISTS `globals` (
  `name` varchar(25) COLLATE utf8_bin NOT NULL,
  `value` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `globals`
--

INSERT INTO `globals` (`name`, `value`) VALUES
('activeevent', 5),
('activeround', 4);

-- --------------------------------------------------------

--
-- Table structure for table `phases`
--

CREATE TABLE IF NOT EXISTS `phases` (
  `phaseId` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`phaseId`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_bin AUTO_INCREMENT=3 ;

--
-- Dumping data for table `phases`
--

INSERT INTO `phases` (`phaseId`, `name`) VALUES
(0, 'Finals'),
(1, 'Semi finals'),
(2, 'Qualifications');

-- --------------------------------------------------------

--
-- Table structure for table `roundenrollment`
--

CREATE TABLE IF NOT EXISTS `roundenrollment` (
  `eventId` int(11) NOT NULL,
  `roundId` int(11) NOT NULL,
  `phaseId` int(11) NOT NULL,
  `startNumber` int(11) NOT NULL,
  `polePosition` int(11) NOT NULL,
  PRIMARY KEY (`roundId`,`phaseId`,`eventId`,`startNumber`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `roundenrollment`
--

INSERT INTO `roundenrollment` (`eventId`, `roundId`, `phaseId`, `startNumber`, `polePosition`) VALUES
(7, 3, 2, 1, 1),
(7, 3, 2, 2, 2),
(7, 3, 2, 3, 3),
(7, 3, 2, 4, 4),
(7, 3, 2, 5, 5),
(7, 3, 2, 6, 6),
(7, 4, 2, 100, 50),
(7, 4, 2, 101, 51),
(7, 4, 2, 102, 52),
(7, 4, 2, 103, 53),
(7, 4, 2, 104, 54),
(7, 4, 2, 105, 55);

-- --------------------------------------------------------

--
-- Table structure for table `roundphaseenrollment`
--

CREATE TABLE IF NOT EXISTS `roundphaseenrollment` (
  `eventId` int(11) NOT NULL,
  `phaseId` int(11) NOT NULL,
  `roundId` int(11) NOT NULL,
  `sequence` int(2) NOT NULL,
  `nrofboulders` int(2) NOT NULL,
  PRIMARY KEY (`eventId`,`roundId`,`phaseId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `roundphaseenrollment`
--

INSERT INTO `roundphaseenrollment` (`eventId`, `phaseId`, `roundId`, `sequence`, `nrofboulders`) VALUES
(7, 0, 3, 3, 1),
(7, 1, 3, 2, 4),
(7, 2, 3, 1, 3),
(7, 0, 4, 3, 1),
(7, 1, 4, 2, 2),
(7, 2, 4, 1, 3);

-- --------------------------------------------------------

--
-- Table structure for table `rounds`
--

CREATE TABLE IF NOT EXISTS `rounds` (
  `roundId` int(11) NOT NULL DEFAULT '0',
  `name` varchar(20) COLLATE utf8_bin NOT NULL,
  `boulderprefix` varchar(3) COLLATE utf8_bin NOT NULL,
  PRIMARY KEY (`roundId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `rounds`
--

INSERT INTO `rounds` (`roundId`, `name`, `boulderprefix`) VALUES
(3, 'Women', 'W'),
(4, 'Men', 'M');

-- --------------------------------------------------------

--
-- Table structure for table `scores`
--

CREATE TABLE IF NOT EXISTS `scores` (
  `eventId` int(11) NOT NULL DEFAULT '0',
  `roundId` int(11) NOT NULL DEFAULT '0',
  `phaseId` int(11) NOT NULL,
  `boulderNumber` int(11) NOT NULL DEFAULT '0',
  `startNumber` int(11) NOT NULL DEFAULT '0',
  `finished` int(11) NOT NULL DEFAULT '1',
  `started` int(11) NOT NULL,
  `topped` int(11) DEFAULT NULL,
  `topAttempts` int(11) DEFAULT NULL,
  `bonussed` int(11) DEFAULT NULL,
  `bonusAttempts` int(11) DEFAULT NULL,
  `attempts` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`eventId`,`phaseId`,`roundId`,`boulderNumber`,`startNumber`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

--
-- Dumping data for table `scores`
--

INSERT INTO `scores` (`eventId`, `roundId`, `phaseId`, `boulderNumber`, `startNumber`, `finished`, `started`, `topped`, `topAttempts`, `bonussed`, `bonusAttempts`, `attempts`) VALUES
(7, 3, 2, 1, 1, 1, 0, 0, 0, 1, 1, 1),
(7, 3, 2, 1, 2, 1, 0, 1, 1, 1, 1, 1),
(7, 3, 2, 1, 3, 0, 0, 0, 0, 0, 0, 0),
(7, 3, 2, 1, 4, 0, 0, 0, 0, 0, 0, 0),
(7, 3, 2, 1, 5, 1, 0, 1, 1, 1, 1, 1);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
