DROP DATABASE IF EXISTS jspdb;

CREATE DATABASE jspdb;

USE jspdb;

 CREATE TABLE  members (
   id   VARCHAR(20),
   passwd   VARCHAR(20),
   email   VARCHAR(50)
); 

INSERT INTO members  VALUES ('hs1', '1234', 'hs@hansung.ac.kr');
INSERT INTO members  VALUES ('hansung', '2568', 'hansung@hansung.ac.kr');
INSERT INTO members  VALUES ('sihns', '5678', 'sihns@hansung.ac.kr');
INSERT INTO members  VALUES ('hong', '7890', 'hong@hansung.ac.kr');
INSERT INTO members  VALUES ('kim', '1590', 'kim@hansung.ac.kr');


