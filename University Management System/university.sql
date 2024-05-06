CREATE DATABASE IF NOT EXISTS UNIVERSITY;
USE University;

CREATE TABLE STUDENT (
	
    RegNo INT NOT NULL,
    SName VARCHAR (25),
    FatherName VARCHAR (25),
    Age INT NOT NULL,
	Department VARCHAR (25),
    Semester INT NOT NULL,
    Section VARCHAR (5),
    Grade VARCHAR (5),
    Course VARCHAR (25),
    CGPA FLOAT,
    PRIMARY KEY (RegNo)
);

CREATE TABLE FACULTY (
	
    ID INT NOT NULL,
    FName VARCHAR (15),
    Age INT NOT NULL,
    Designation VARCHAR (20),
    Department VARCHAR (20),
    Course VARCHAR (20),
    Salary INT NOT NULL,
	PRIMARY KEY (ID)
);

CREATE TABLE ADMINISTRATION (
	
    ID INT NOT NULL,
    AName VARCHAR (15),
    Age INT NOT NULL,
    Designation VARCHAR (20),
    Department VARCHAR (20),
    EmailID VARCHAR (30),
	PRIMARY KEY (ID)
);

CREATE TABLE COURSES (
	
    CourseNo INT NOT NULL,
    Course VARCHAR (25),
    CourseInstr VARCHAR (25),
    Department VARCHAR (25),
    PRIMARY KEY (CourseNo)
);

CREATE VIEW student_view AS
SELECT RegNo,FName,Age,CGPA,Semester
FROM student;

CREATE VIEW faculty_view AS
SELECT ID,FName,Age,Designation
FROM faculty;

SELECT * FROM administration;
SELECT * FROM faculty;
SELECT * FROM student;
SELECT * FROM courses;
