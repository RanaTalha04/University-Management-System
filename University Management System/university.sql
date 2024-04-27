CREATE DATABASE IF NOT EXISTS UNIVERSITY;
USE University;

CREATE TABLE STUDENT (
	
    RegNo INT NOT NULL,
    SName VARCHAR (15),
    FatherName VARCHAR (15),
    Age INT NOT NULL,
	Department VARCHAR (10),
    Semester INT NOT NULL,
    Section VARCHAR (2),
    Grade VARCHAR (2),
    Courses VARCHAR (10),
    CGPA FLOAT,
    PRIMARY KEY (RegNo)
);

CREATE TABLE FACULTY (
	
    ID INT NOT NULL,
    FName VARCHAR (15),
    Age INT NOT NULL,
    Designation VARCHAR (10),
    Department VARCHAR (10),
    Course VARCHAR (10),
    Salary INT NOT NULL,
	PRIMARY KEY (ID)
);

CREATE TABLE ADMINISTRATION (
	
    ID INT NOT NULL,
    AName VARCHAR (15),
    Age INT NOT NULL,
    Designation VARCHAR (10),
    Department VARCHAR (10),
    EmailID VARCHAR (30),
	PRIMARY KEY (ID)
);

CREATE TABLE COURSES (
	
    CourseNo INT NOT NULL,
    CourseName VARCHAR (20),
    CourseInstr VARCHAR (10),
    Department VARCHAR (10),
    PRIMARY KEY (CourseNo)
);

SELECT * FROM administration;