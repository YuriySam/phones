#Телефоний довілник  (phones)
#Версия: 1
#Дата: 01.05.2022
#Автор: ЮСА

CREATE TABLE ophone (
  id int(10) unsigned NOT NULL auto_increment,
  number varchar(5) NOT NULL DEFAULT '' COMMENT 'Внутрішній номер',
  number1 varchar(13) COMMENT 'Міський номер',
  offid int(10) COMMENT 'Код організації',
  strid int(10) COMMENT 'Код вулиці',
  funid int(10) COMMENT 'Код посади',
  branid int(10) COMMENT 'Код Відділу',
  surname varchar(25) COMMENT 'Призвище',
  name varchar(25) COMMENT 'Імя',
  patronymic varchar(25) COMMENT 'По батькові',
  birthday DATE COMMENT 'Дата народження', 
  house varchar(8) COMMENT 'Номер будинка адреси організації',
  flat smallint(7) unsigned COMMENT 'Номер кабінета організації',
  note varchar(250) COMMENT 'Коментар',
  sortindex int(4) COMMENT 'Порядковий номер для сортування записів',
  userMail varchar(50) COMMENT 'Внутрішня поштова адреса',
  PRIMARY KEY (id),
  INDEX number (number),
  INDEX office (offid)
) COMMENT 'Телефони підприємства';

CREATE TABLE street (
  strid int(10) unsigned NOT NULL auto_increment,
  town_pre varchar(10) COMMENT 'Тип місця',
  town varchar(50) COMMENT 'Назва місця',
  street_pre varchar(20) COMMENT 'Тип вулиць',
  street varchar(50) COMMENT 'Назва вулиць',
  PRIMARY KEY (strid)
) COMMENT 'Перелік вулиць';

CREATE TABLE office (
  offid int(10) unsigned NOT NULL auto_increment,
  office varchar(50) COMMENT 'Назва Підприемства',
  PRIMARY KEY (offid)
) COMMENT 'Перелік Підприемств';

CREATE TABLE branch (
  branid int(10) unsigned NOT NULL auto_increment,
  branch varchar(150) COMMENT 'Назва відділу',
  branindex int(3) COMMENT 'Порядковий номер для сортування записів',
  PRIMARY KEY (branid)
) COMMENT 'Перелік відділів';

CREATE TABLE func (
  funid int(10) unsigned NOT NULL auto_increment,
  func varchar(250) COMMENT 'Назва посади',
  funindex  varchar(4) COMMENT 'Індекс посади для сортування у відділі',
  PRIMARY KEY (funid)
) COMMENT 'Перелік посад';

CREATE TABLE auth (
  authid smallint(5) unsigned NOT NULL auto_increment,
  login varchar(16) binary NOT NULL DEFAULT '',
  pswd varchar(32) binary NOT NULL DEFAULT '',
  logdate datetime NOT NULL DEFAULT '2020-01-01 00:00:00',
  logaddr varchar(20) NOT NULL DEFAULT '',
  PRIMARY KEY (authid)
);

CREATE TABLE message (
  id int(10) unsigned NOT NULL auto_increment,
  message text,
  date datetime,
  host varchar(20),
  PRIMARY KEY (id)
);

CREATE TABLE quote (
  id int(10) unsigned NOT NULL auto_increment,
  quote varchar(255),
  PRIMARY KEY (id)
);
INSERT INTO `office` (`offid`, `office`) VALUES (NULL, 'MyOffice');
INSERT INTO `street` (`strid`, `town_pre`, `town`, `street_pre`, `street`) VALUES (NULL, 'town-pre', 'Town', 'street-pre', 'Street');
INSERT INTO `func` (`funid`, `func`, `funindex`) VALUES (NULL, 'Func', NULL);
INSERT INTO `branch` (`branid`, `branch`, `branindex`) VALUES (NULL, 'Branch', NULL);
INSERT INTO `ophone` (`id`, `number`, `number1`, `offid`, `strid`, `funid`, `branid`, `surname`, `name`, `patronymic`, `birthday`, `house`, `flat`, `note`, `sortindex`, `userMail`) VALUES (NULL, '000', '000-00-00', '1', '1', '1', '1', 'surname', 'name', 'patronymic', '1970-01-01', '1', '1', NULL, NULL, 'info@google.com');

INSERT INTO auth VALUES('1','admin',MD5('admin'),'2004-10-19 00:05:01','127.0.0.1');
