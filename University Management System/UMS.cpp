//Libraries for database and C++
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <sstream>
#include <fstream>
#include "mysql_connection.h"
#include "mysql_driver.h"
#include "mysql_error.h"
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


using namespace std;

// Defining the database login data globally
const char* host= "tcp://localhost:3306/university";
const char* username = "root";
const char* password = "ranamuhammadtalhashahid";

// Making a student class

class student
{
private:

	int RegNo, Age, Semester;
	string Department, SName, FatherName,Section,Grade,Courses,Instructor;
	float CGPA;

public:
		
	student()
	{
		RegNo = 0;
		Age = 0;
		Semester = 0;
		Department = ""; 
		SName = "";
		FatherName = ""; 
		Section = ""; 
		Grade = "";
		Courses = "";
		Instructor = "";
		CGPA = 0.0;
	}

	//Setters Function

	void SetRegno(int reg)
	{
		RegNo = reg;
	}
	void Setage(int age)
	{
		Age = age;
	}
	void Setsem(int sem)
	{
		Semester = sem;
	}
	void Setdept(string dept)
	{
		Department = dept;
	}
	void Setname(string name)
	{
		SName = name;
	}
	void SetFname(string fname)
	{
		FatherName = fname;

	}
	void Setsec(string sec)
	{
		Section = sec;
	}
	void Setgrade(string grade)
	{
		Grade = grade;
	}
	void Setcourse(string courses)
	{
		Courses = courses;
	}
	void Setinstr(string Instr)
	{
		Instructor = Instr;
	}
	void Setcgpa(float cgpa)
	{
		CGPA = cgpa;
	}

	// Getters Function

	int getRegno(int reg)
	{
		return reg;
	}
	int getage(int age)
	{
		return age;
	}
	string getsem(string sem)
	{
		return  sem;
	}
	string getdept(string dept)
	{
		return  dept;
	}
	string getname(string Sname)
	{
		return Sname;
	}
	string getFname(string fname)
	{
		return fname;

	}
	string getsec(string sec)
	{
		return sec;
	}
	string getgrade(string grade)
	{
		return grade;
	}
	string getcourse(string course)
	{
		return course;
	}
	string getInstr(string instr)
	{
		return instr;

	}
	float getcgpa(float cgpa)
	{
		return cgpa;
	}
	
};

// Making a faculty class
class faculty
{
private:

	int ID, Age, Salary;
	string Department, FName, Designation, Courses;
	
public:

	faculty()
	{
		ID = 0;
		Age = 0;
		Salary = 0;
		Department = "";
		FName = "";
		Designation = "";
		Courses = "";
	}

	//Setters Function

	void SetRegno(int id)
	{
		ID = id;
	}
	void Setage(int age)
	{
		Age = age;
	}
	void Setsem(int salary)
	{
		Salary = salary;
	}
	void Setdept(string dept)
	{
		Department = dept;
	}
	void Setname(string name)
	{
		FName = name;
	}
	void SetFname(string desig)
	{
		Designation = desig;

	}
	void Setcourse(string courses)
	{
		Courses = courses;
	}
	
	// Getters Function

	int getid(int id)
	{
		return id;
	}
	int getage(int age)
	{
		return age;
	}
	string getsal(string sal)
	{
		return  sal;
	}
	string getdept(string dept)
	{
		return  dept;
	}
	string getname(string fname)
	{
		return fname;
	}
	string getdesig(string desig)
	{
		return desig;

	}
	string getcourse(string course)
	{
		return course;
	}
};

// Making a courses class
class courses 
{
private:

	int CourseNo;
	string Course, CourseInst,Department;

public:

	courses ()
	{
		CourseNo = 0;
		Course = "";
		CourseInst = "";
		Department = "";
	}

	//Setters Function

	void Setcourseno(int id)
	{
		CourseNo = id;
	}
	void Setcourse(string name)
	{
		Course = name;
	}
	void SetcourseInst(string courseinst)
	{
		CourseInst = courseinst;
	}
	void Setdept(string dept)
	{
		Department = dept;
	}

	// Getters Function

	int getcourseno(int id)
	{
		return id;
	}
	string getname(string cname)
	{
		return cname;
	}
	string getcourseinst(string courseinst)
	{
		return courseinst;
	}
	string getdept(string dept)
	{
		return  dept;
	}
};

//Making an administration class
class administration 
{
private:

	int ID, Age;
	string AName,Designation,Department,EmailID;

public:

	// Default Constructor
	administration()
	{
		ID = 0;
		Age = 0;
		AName = "";
		Designation = "";
		Department = "";
		EmailID = "";
	}

	//Setters Function
	void Setid(int id)
	{
		ID = id;
	}
	void Setage(int age)
	{
		Age = age;
	}
	void Setname(string name)
	{
		AName = name;
	}
	void SetDesig(string desig)
	{
		Designation = desig;
	
	}
	void Setdept(string dept)
	{
		Department = dept;
	}
	void Setmailid(string mailid)
	{
		EmailID = mailid;
	}

	// Getters Function
	int getid(int id)
	{
		return id;
	}

	int getage(int age)
	{
		return age;
	}
	string getname(string name)
	{
		return name;
	}
	string getDesig(string desig)
	{
		return desig;

	}
	string getdept(string dept)
	{
		return  dept;
	}
	string getmailid(string mailid)
	{
		return mailid;
	}

	// Registration Function
	void Registration() {
		string R_username, R_password;

		cout << endl;
		cout << "Enter username: ";
		cin >> R_username;

		cout << "Enter password: ";
		cin >> R_password;

		fstream file("Credential.txt", ios::app);
		if (!file.is_open()) {
			cout << "Error: Unable to open file for writing.\n";
		}

		file << R_username << " " << R_password << endl;
		file.close();

		cout << "Registration successful!\n";

	}

	// Login Function
	void Login() {
		string username, password;
		string stored_username, stored_password;
		bool found = false;

		cout << endl;
		cout << "Enter username: ";
		cin >> username;

		cout << "Enter password: ";
		cin >> password;

		fstream file("Credential.txt");
		if (!file.is_open()) {
			cerr << "Error: Unable to open file for reading.\n";

		}

		while (file >> stored_username >> stored_password) {
			if (username == stored_username && password == stored_password) {
				cout << "Logged In Successfully!\n";
				found = true;
				file.close();
			}
		}
		if (!found)
		{
			cout << "Invalid username or password!\n";
			Login();
		}

		file.close();
	}

	// Inserting data into database
	void insertIntoDatabase()
	{
		sql::Connection* conn;
		sql::Driver* driver;

		driver = get_driver_instance();
		conn = driver->connect(host, username, password);
		Sleep(3000);
		system("cls");

		cout << "Enter ID: ";
		cin >> ID;
		cout << "Enter Admin Name: ";
		cin.ignore(); // Ignore any previous newline character from the input buffer
		getline(cin, AName);
		cout << "Enter Age: ";
		cin >> Age;
		cout << "Enter Designation: ";
		getline(cin, Designation);
		cout << "Enter Department: ";
		cin >> Department;
		getline(cin, Department);
		cout << "Enter Email ID: ";
		cin >> EmailID;
		
		sql::PreparedStatement* stmt = conn->prepareStatement("INSERT INTO administration (ID,AName,Age, Designation, Department, EmailID) VALUES (?, ?, ?, ?, ?, ?)");
		stmt->setInt(1, ID);
		stmt->setString(2, AName);
		stmt->setInt(3 , Age);
		stmt->setString(4, Designation);
		stmt->setString(5, Department);
		stmt->setString(6, EmailID);
		stmt->execute();
	
		cout << endl;
		cout << "Record inserted Successfully" << endl;
		cout << endl;
	}
	
	// Updating data from database
	void updateIntoDatabase()
	{
		sql::Connection* conn;
		sql::Driver* driver;

		driver = get_driver_instance();
		conn = driver->connect(host, username, password);
		Sleep(3000);
		system("cls");

		int option;
		cout << "1. ID" << endl;
		cout << "2. Age" << endl;
		cout << "3. Name" << endl;
		cout << "4. Designation" << endl;
		cout << "5. Department" << endl;
		cout << "6. Email ID" << endl;

		cout << "Enter what you want to update:";
		cin >> option;

		if (option == 1)
		{
			int id;
			string name;

			cout << "Enter new ID: ";
			cin >> id;
			cout << "Enter Name you want to change the id of: ";
			getline(cin, name);
			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE administration SET ID = ? Where AName = ?");
			stmt->setInt(1, id);
			stmt->setString(2, name);
			stmt->execute();

			cout << endl;
			cout << "Record Updated Successfully" << endl;
			cout << endl;
			
		}
		
		else if (option == 2)
		{
			int id;
			int age;

			cout << "Enter new Age: ";
			cin >> age;
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE administration SET Age = ? Where ID = ?");
			stmt->setInt(1, age);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 3)
		{
			int id;
			string name;

			cout << "Enter new Name: ";
			getline(cin, name);
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE administration SET AName = ? Where ID = ?");
			stmt->setString(1, name);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 4)
		{
			int id;
			string desig;

			cout << "Enter new Designation: ";
			getline(cin, desig);
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE administration SET Designation = ? Where ID = ?");
			stmt->setString(1, desig);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 5)
		{
			int id;
			string depart;

			cout << "Enter new Department: ";
			getline(cin, depart);
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE administration SET Department = ? Where ID = ?");
			stmt->setString(1, depart);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 6)
		{
			int id;
			string emailid;

			cout << "Enter new Email Id: ";
			cin >> emailid;
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE administration SET EmailID = ? Where ID = ?");
			stmt->setString(1, emailid);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}
			
		else
		{
			cout << "Error: unable to process" << endl;
		}

	}

	// Removing data from database
	void removefromDatabase()
	{
		sql::Connection* conn;
		sql::Driver* driver;

		driver = get_driver_instance();
		conn = driver->connect(host, username, password);
		sql::PreparedStatement*stmt = conn->prepareStatement("SELECT * FROM administration");
		sql::ResultSet* res = stmt->executeQuery();
		cout << "Displaying data from database:" << endl;
		if (res) {
			while (res->next()) {
				cout << "ID: " << res->getInt("ID") << endl;
				cout << "Name: " << res->getString("AName") << endl;
				cout << "Age: " << res->getInt("Age") << endl;
				cout << "Designation: " << res->getString("Designation") << endl;
				cout << "Department: " << res->getString("Department") << endl;
				cout << "Email ID: " << res->getString("EmailID") << endl;
				cout << endl;
			}
		}
		else {
			cout << "No data found in the database." << endl;
		}
		cout << "Records displayed successfully!" << endl;
		cout << endl;
		cout << "Enter ID and Name of admin you want to remove from database:" << endl;

			int id;
			string name;

			cout << "Enter ID: ";
			cin >> id;
			cout << "Enter the name of admin: ";
			getline(cin, name);

			stmt=conn->prepareStatement("DELETE FROM administration  Where ID = ? AND AName = ?");
			stmt->setInt(1, id);
			stmt->setString(2, name);
			stmt->execute();

			cout << endl;
			cout << "Record Removed Successfully" << endl;
			cout << endl;
		delete res;
	}

	// Displaying data from database
	void displayfromDatabase()
	{
		try {
			sql::Connection* conn;
			sql::Driver* driver;
			driver = get_driver_instance();
			conn = driver->connect(host, username, password);
			if (!conn) {
				cout << "Connection to the database failed." << endl;
				return;
			}
			Sleep(3000);
			cout << "Displaying data from database:" << endl;
			sql::PreparedStatement* stmt = conn->prepareStatement("SELECT * FROM administration");
			sql::ResultSet* res = stmt->executeQuery();
			if (res) {
				while (res->next()) {
					cout << "ID: " << res->getInt("ID") << endl;
					cout << "Name: " << res->getString("AName") << endl;
					cout << "Age: " << res->getInt("Age") << endl;
					cout << "Designation: " << res->getString("Designation") << endl;
					cout << "Department: " << res->getString("Department") << endl;
					cout << "Email ID: " << res->getString("EmailID") << endl;
					cout << endl;
				}
			}
			else {
				cout << "No data found in the database." << endl;
			}
			delete res;
			delete stmt;
			delete conn;
			cout << "Records displayed successfully!" << endl;
		}
		catch (sql::SQLException& e) {
			cout << "SQL Exception: " << e.what() << endl;
		}
		catch (std::runtime_error& e) {
			cout << "Runtime Error: " << e.what() << endl;
		}

	}

	// Inserting student data into database
	void insertstudentintodatabase()
	{
		try {
			sql::Connection* conn;
			sql::Driver* driver;

			driver = get_driver_instance();
			conn = driver->connect(host, username, password);
			if (!conn) {
				cout << "Connection to the database failed." << endl;
				return;
			}
			Sleep(3000);
			system("cls");

			cout << "Enter Registration Number: ";
			int RegNo;
			cin >> RegNo;

			cout << "Enter Student Name: ";
			string name;
			cin.ignore(); // Ignore any previous newline character from the input buffer
			getline(cin, name);

			cout << "Enter Father Name: ";
			string fname;
			getline(cin, fname);

			cout << "Enter Age: ";
			int age;
			cin >> age;

			cout << "Enter Department: ";
			string department;
			getline(cin, department);

			cout << "Enter Semester: ";
			int Sem;
			cin >> Sem;

			cout << "Enter Section: ";
			string Sec;
			getline(cin, Sec);

			cout << "Enter Grade: ";
			string grade;
			getline(cin, grade);

			cout << "Enter Course Name: ";
			string course;
			getline(cin, course);

			cout << "Enter CGPA: ";
			float cgpa;
			cin >> cgpa;

			sql::PreparedStatement* stmt = conn->prepareStatement("INSERT INTO student (RegNo, SName, FatherName,Age, Department,Semester,Section,Grade,Course,CGPA) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
			stmt->setInt(1, RegNo);
			stmt->setString(2, name);
			stmt->setString(3, fname);
			stmt->setInt(4, age);
			stmt->setString(5, department);
			stmt->setInt(6, Sem);
			stmt->setString(7, Sec);
			stmt->setString(8, grade);
			stmt->setString(9, course);
			stmt->setDouble(10, cgpa);
			stmt->execute();

			cout << "Student data inserted successfully!" << endl;

			delete stmt;
			delete conn;
		}
		catch (sql::SQLException& e) {
			cout << "SQL Exception: " << e.what() << endl;
		}
		catch (std::runtime_error& e) {
			cout << "Runtime Error: " << e.what() << endl;
		}

	}

	// Updating student data from database
	void updatedtudentIntoDatabase()
	{
		sql::Connection* conn;
		sql::Driver* driver;

		driver = get_driver_instance();
		conn = driver->connect(host, username, password);
		Sleep(3000);
		system("cls");

		int option;
		cout << "1. RegNo" << endl;
		cout << "2. SName" << endl;
		cout << "3. Father Name" << endl;
		cout << "4. Age" << endl;
		cout << "5. Department" << endl;
		cout << "6. Semester" << endl;
		cout << "7. Section" << endl;
		cout << "8. Grade" << endl;
		cout << "9. Course" << endl;
		cout << "10. CGPA" << endl;

		cout << "Enter what you want to update:";
		cin >> option;

		if (option == 1)
		{
			int id;
			string name;

			cout << "Enter new RegNo: ";
			cin >> id;
			cout << "Enter Name you want to change the id of: ";
			getline(cin, name);

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET RegNo = ? Where SName = ?");
			stmt->setInt(1, id);
			stmt->setString(2, name);
			stmt->execute();

			cout << endl;
			cout << "Record Updated Successfully" << endl;
			cout << endl;

		}
		else if (option == 2)
		{
			int id;
			string name;

			cout << "Enter new Name: ";
			cin >> name;
			cout << "Enter RegNo of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET SName = ? Where RegNo = ?");
			stmt->setString(1, name);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}
		else if (option == 3)
		{
			int id;
			string name;

			cout << "Enter Father Name: ";
			getline(cin, name);
			cout << "Enter RegNo of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET FatherName = ? Where RegNo = ?");
			stmt->setString(1, name);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}
		else if (option == 4)
		{
			int id;
			int age;

			cout << "Enter new Age: ";
			cin >> age;
			cout << "Enter RegNo of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET Age = ? Where RegNo = ?");
			stmt->setInt(1, age);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}
		else if (option == 5)
		{
			int id;
			string depart;

			cout << "Enter new Department: ";
			getline(cin, depart);
			cout << "Enter RegNo of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET Department = ? Where RegNo = ?");
			stmt->setString(1, depart);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}
		else if (option == 6)
		{
			int id;
			int sem;

			cout << "Enter new Semester: ";
			cin>> sem;
			cout << "Enter RegNo of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET Semester = ? Where RegNo = ?");
			stmt->setInt(1, sem);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}
		else if (option == 7)
		{
			int id;
			string section;

			cout << "Enter new Section: ";
			cin >> section;
			cout << "Enter RegNo of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET section = ? Where RegNo = ?");
			stmt->setString(1, section);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}
		else if (option == 8)
		{
			int id;
			string grade;

			cout << "Enter new Grade: ";
			cin >> grade;
			cout << "Enter RegNo of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET Grade = ? Where RegNo = ?");
			stmt->setString(1, grade);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}
		else if (option == 9)
		{
			int id;
			string course;

			cout << "Enter new Course Name: ";
			cin >> course;
			cout << "Enter RegNo of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET Course Name = ? Where RegNo = ?");
			stmt->setString(1, course);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
			}
		else if (option == 10)
		{
			int id;
			float cgpa;

			cout << "Enter new CGPA: ";
			cin >> cgpa;
			cout << "Enter RegNo of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE student SET CGPA = ? Where RegNo = ?");
			stmt->setDouble(1, cgpa);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
			}
		else
		{
			cout << "Error: unable to process" << endl;
		}

	}

	// Removing student data from database
	void removestudentfromDatabase()
	{
		sql::Connection* conn;
		sql::Driver* driver;
		driver = get_driver_instance();
		conn = driver->connect(host, username, password);
		if (!conn) {
			cout << "Connection to the database failed." << endl;
			return;
		}
		Sleep(3000);
		cout << "Displaying data from database:" << endl;
		sql::PreparedStatement* stmt = conn->prepareStatement("SELECT * FROM administration");
		sql::ResultSet* res = stmt->executeQuery();
		if (res) {
			while (res->next()) {
				cout << "Reg NO: " << res->getInt("RegNo") << endl;
				cout << "Name: " << res->getString("SName") << endl;
				cout << "Father Name: " << res->getString("FatherName") << endl;
				cout << "Age: " << res->getInt("Age") << endl;
				cout << "Department: " << res->getString("Department") << endl;
				cout << "Semester: " << res->getInt("Semester") << endl;
				cout << "Section: " << res->getString("Section") << endl;
				cout << "Grade: " << res->getString("Grade") << endl;
				cout << "Course: " << res->getString("Course") << endl;
				cout << "CGPA: " << res->getString("CGPA") << endl;
				cout << endl;
			}
		}
		else {
			cout << "No data found in the database." << endl;
		}
		cout << "Records displayed successfully!" << endl;
		cout << endl;
		cout << "Enter ID and Name of admin you want to remove from database:" << endl;

		int id;
		string name;

		cout << "Enter ID: ";
		cin >> id;
		cout << "Enter the name of admin: ";
		getline(cin, name);

		stmt = conn->prepareStatement("DELETE FROM administration  Where RegNo = ? AND SName = ?");
		stmt->setInt(1, id);
		stmt->setString(2, name);
		stmt->execute();

		cout << endl;
		cout << "Record Removed Successfully" << endl;
		cout << endl;
		delete res;
	}

	// Displaying student data from database
	void displaystudentfromDatabase()
	{
		try {
			sql::Connection* conn;
			sql::Driver* driver;
			driver = get_driver_instance();
			conn = driver->connect(host, username, password);
			if (!conn) {
				cout << "Connection to the database failed." << endl;
				return;
			}
			Sleep(3000);
			cout << "Displaying data from database:" << endl;
			sql::PreparedStatement* stmt = conn->prepareStatement("SELECT * FROM administration");
			sql::ResultSet* res = stmt->executeQuery();
			if (res) {
				while (res->next()) {
					cout << "Reg NO: " << res->getInt("RegNo") << endl;
					cout << "Name: " << res->getString("SName") << endl;
					cout << "Father Name: " << res->getString("FatherName") << endl;
					cout << "Age: " << res->getInt("Age") << endl;
					cout << "Department: " << res->getString("Department") << endl;
					cout << "Semester: " << res->getInt("Semester") << endl;
					cout << "Section: " << res->getString("Section") << endl;
					cout << "Grade: " << res->getString("Grade") << endl;
					cout << "Course: " << res->getString("Course") << endl;
					cout << "CGPA: " << res->getString("CGPA") << endl;
					cout << endl;
				}
			}
			else {
				cout << "No data found in the database." << endl;
			}
			delete res;
			delete stmt;
			delete conn;
			cout << "Records displayed successfully!" << endl;
		}
		catch (sql::SQLException& e) {
			cout << "SQL Exception: " << e.what() << endl;
		}
		catch (std::runtime_error& e) {
			cout << "Runtime Error: " << e.what() << endl;
		}

	}

	// Inserting faculty data into database
	void insertfacultyintodatabase()
	{
		try {
			sql::Connection* conn;
			sql::Driver* driver;

			driver = get_driver_instance();
			conn = driver->connect(host, username, password);
			if (!conn) {
				cout << "Connection to the database failed." << endl;
				return;
			}
			Sleep(3000);
			system("cls");

			cout << "Enter ID Number: ";
			int id;
			cin >> id;

			cout << "Enter Name: ";
			string name;
			cin.ignore(); // Ignore any previous newline character from the input buffer
			getline(cin, name);

			cout << "Enter Age: ";
			int age;
			cin >> age;

			cout << "Enter Designation: ";
			string desig;
			getline(cin, desig);

			cout << "Enter Department: ";
			string department;
			getline(cin, department);

			cout << "Enter Course: ";
			string course;
			getline(cin, course);

			cout << "Enter Salary: ";
			string salary;
			getline(cin, salary);

			sql::PreparedStatement* stmt = conn->prepareStatement("INSERT INTO faculty (ID, FName,Age, Designation,Department,Course,Salary) VALUES (?, ?, ?, ?, ?, ?, ?)");
			stmt->setInt(1, id);
			stmt->setString(2, name);
			stmt->setInt(3, age);
			stmt->setString(4, desig);
			stmt->setString(5, department);
			stmt->setString(6, course);
			stmt->setString(7, salary);
			stmt->execute();

			cout << "Faculty data inserted successfully!" << endl;

			delete stmt;
			delete conn;
		}
		catch (sql::SQLException& e) {
			cout << "SQL Exception: " << e.what() << endl;
		}
		catch (std::runtime_error& e) {
			cout << "Runtime Error: " << e.what() << endl;
		}
	}

	// Updating faculty data from database
	void updatefacultyIntoDatabase()
	{
		sql::Connection* conn;
		sql::Driver* driver;

		driver = get_driver_instance();
		conn = driver->connect(host, username, password);
		Sleep(3000);
		system("cls");

		int option;
		cout << "1. ID" << endl;
		cout << "2. Name" << endl;
		cout << "3. Age" << endl;
		cout << "4. Designation" << endl;
		cout << "5. Department" << endl;
		cout << "6. Course" << endl;
		cout << "7. Salary" << endl;

		cout << "Enter what you want to update:";
		cin >> option;

		if (option == 1)
		{
			int id;
			string name;

			cout << "Enter new ID: ";
			cin >> id;
			cout << "Enter Name you want to change the id of: ";
			getline(cin, name);
			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE faculty SET ID = ? Where FName = ?");
			stmt->setInt(1, id);
			stmt->setString(2, name);
			stmt->execute();

			cout << endl;
			cout << "Record Updated Successfully" << endl;
			cout << endl;

		}

		else if (option == 2)
		{
			int id;
			int age;

			cout << "Enter new Age: ";
			cin >> age;
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE faculty SET Age = ? Where ID = ?");
			stmt->setInt(1, age);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 3)
		{
			int id;
			string name;

			cout << "Enter new Name: ";
			getline(cin, name);
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE faculty SET FName = ? Where ID = ?");
			stmt->setString(1, name);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 4)
		{
			int id;
			string desig;

			cout << "Enter new Designation: ";
			getline(cin, desig);
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE faculty SET Designation = ? Where ID = ?");
			stmt->setString(1, desig);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 5)
		{
			int id;
			string depart;

			cout << "Enter new Department: ";
			getline(cin, depart);
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE faculty SET Department = ? Where ID = ?");
			stmt->setString(1, depart);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 6)
		{
			int id;
			string course;

			cout << "Enter new Course: ";
			cin >> course;
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE faculty SET Course = ? Where ID = ?");
			stmt->setString(1, course);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}
		
		else if (option == 7)
		{
			int id;
			int salary;

			cout << "Enter new Salary: ";
			cin >> salary;
			cout << "Enter id of the person you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE faculty SET Salary = ? Where ID = ?");
			stmt->setInt(1, salary);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else
		{
			cout << "Error: unable to process" << endl;
		}

	}

	// Removing faculty data from database
	void removefacultyfromDatabase()
	{
		sql::Connection* conn;
		sql::Driver* driver;
		driver = get_driver_instance();
		conn = driver->connect(host, username, password);
		if (!conn) {
			cout << "Connection to the database failed." << endl;
			return;
		}
		Sleep(3000);
		cout << "Displaying data from database:" << endl;
		sql::PreparedStatement* stmt = conn->prepareStatement("SELECT * FROM faculty");
		sql::ResultSet* res = stmt->executeQuery();
		if (res) {
			while (res->next()) {
				cout << "ID: " << res->getInt("ID") << endl;
				cout << "Faculty Name: " << res->getString("FName") << endl;
				cout << "Age: " << res->getInt("Age") << endl;
				cout << "Designation: " << res->getString("Designation") << endl;
				cout << "Department: " << res->getString("Department") << endl;
				cout << "Course Name: " << res->getString("Course") << endl;
				cout << "Salary: " << res->getInt("Salary") << endl;
				cout << endl;
			}
		}
		else {
			cout << "No data found in the database." << endl;
		}
		cout << "Records displayed successfully!" << endl;
		cout << endl;
		cout << "Enter ID and Name of admin you want to remove from database:" << endl;

		int id;
		string name;

		cout << "Enter ID: ";
		cin >> id;
		cout << "Enter the name of admin: ";
		getline(cin, name);

		stmt = conn->prepareStatement("DELETE FROM faculty  Where ID = ? AND FName = ?");
		stmt->setInt(1, id);
		stmt->setString(2, name);
		stmt->execute();

		cout << endl;
		cout << "Record Removed Successfully" << endl;
		cout << endl;
		delete res;
	}

	// Displaying faculty data from database
	void displayfacultyfromDatabase()
	{
		try {
			sql::Connection* conn;
			sql::Driver* driver;
			driver = get_driver_instance();
			conn = driver->connect(host, username, password);
			if (!conn) {
				cout << "Connection to the database failed." << endl;
				return;
			}
			Sleep(3000);
			cout << "Displaying data from database:" << endl;
			sql::PreparedStatement* stmt = conn->prepareStatement("SELECT * FROM faculty");
			sql::ResultSet* res = stmt->executeQuery();
			if (res) {
				while (res->next()) {
					cout << "ID: " << res->getInt("ID") << endl;
					cout << "Faculty Name: " << res->getString("FName") << endl;
					cout << "Age: " << res->getInt("Age") << endl;
					cout << "Designation: " << res->getString("Designation") << endl;
					cout << "Department: " << res->getString("Department") << endl;
					cout << "Course Name: " << res->getString("Course") << endl;
					cout << "Salary: " << res->getInt("Salary") << endl;
					cout << endl;
				}
			}
			else {
				cout << "No data found in the database." << endl;
			}
			delete res;
			delete stmt;
			delete conn;
			cout << "Records displayed successfully!" << endl;
		}
		catch (sql::SQLException& e) {
			cout << "SQL Exception: " << e.what() << endl;
		}
		catch (std::runtime_error& e) {
			cout << "Runtime Error: " << e.what() << endl;
		}

	}

	// Inserting course data into database
	void insertcourseIntoDatabase()
	{
		try {
			sql::Connection* conn;
			sql::Driver* driver;

			driver = get_driver_instance();
			conn = driver->connect(host, username, password);
			if (!conn) {
				cout << "Connection to the database failed." << endl;
				return;
			}
			Sleep(3000);
			system("cls");

			cout << "Enter Course Number: ";
			int courseNo;
			cin >> courseNo;

			cout << "Enter Course Name: ";
			string courseName;
			cin.ignore(); // Ignore any previous newline character from the input buffer
			getline(cin, courseName);

			cout << "Enter Course Instructor: ";
			string courseInstructor;
			getline(cin, courseInstructor);

			cout << "Enter Department: ";
			string department;
			getline(cin, department);

			sql::PreparedStatement* stmt = conn->prepareStatement("INSERT INTO courses (CourseNo, Course, CourseInstr, Department) VALUES (?, ?, ?, ?)");
			stmt->setInt(1, courseNo);
			stmt->setString(2, courseName);
			stmt->setString(3, courseInstructor);
			stmt->setString(4, department);
			stmt->execute();

			cout << "Course inserted successfully!" << endl;

			delete stmt;
			delete conn;
		}
		catch (sql::SQLException& e) {
			cout << "SQL Exception: " << e.what() << endl;
		}
		catch (std::runtime_error& e) {
			cout << "Runtime Error: " << e.what() << endl;
		}
	}

	// Updating course data from database
	void updatecourseIntoDatabase()
	{
		sql::Connection* conn;
		sql::Driver* driver;

		driver = get_driver_instance();
		conn = driver->connect(host, username, password);
		Sleep(3000);
		system("cls");

		int option;
		cout << "1. Course No" << endl;
		cout << "2. Coures Name" << endl;
		cout << "3. Course Instructor" << endl;
		cout << "4. Department" << endl;

		cout << "Enter what you want to update:";
		cin >> option;

		if (option == 1)
		{
			int id;
			string name;

			cout << "Enter new Coures No: ";
			cin >> id;
			cout << "Enter Coures name you want to change the course number of: ";
			getline(cin, name);
			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE Courses SET CouresNo = ? Where Course = ?");
			stmt->setInt(1, id);
			stmt->setString(2, name);
			stmt->execute();

			cout << endl;
			cout << "Record Updated Successfully" << endl;
			cout << endl;

		}

		else if (option == 2)
		{
			int id;
			string name;

			cout << "Enter new Course Name: ";
			cin >> name;
			cout << "Enter course no you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE courses SET Course = ? Where CourseNo = ?");
			stmt->setString(1, name);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 3)
		{
			int id;
			string name;

			cout << "Enter new Course instructor name: ";
			getline(cin, name);
			cout << "Enter course no you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE courses SET CourseInstr = ? Where CourseNo = ?");
			stmt->setString(1, name);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else if (option == 4)
		{
			int id;
			string depart;

			cout << "Enter new Department: ";
			getline(cin, depart);
			cout << "Enter Course No you want to change the data of: ";
			cin >> id;

			sql::PreparedStatement* stmt = conn->prepareStatement("UPDATE courses SET Department = ? Where CourseNo = ?");
			stmt->setString(1, depart);
			stmt->setInt(2, id);
			stmt->execute();

			cout << "Record Updated Successfully" << endl;
		}

		else
		{
			cout << "Error: unable to process" << endl;
		}

	}

	// Removing course data from database
	void removecoursefromDatabase()
	{
			sql::Connection* conn;
			sql::Driver* driver;
			driver = get_driver_instance();
			conn = driver->connect(host, username, password);
			if (!conn) {
				cout << "Connection to the database failed." << endl;
				return;
			}
			Sleep(3000);
			cout << "Displaying data from database:" << endl;
			sql::PreparedStatement* stmt = conn->prepareStatement("SELECT * FROM Courses");
			sql::ResultSet* res = stmt->executeQuery();
			if (res) {
				while (res->next()) {
					cout << "Course No: " << res->getInt("CourseNo") << endl;
					cout << "Course Name: " << res->getString("Course") << endl;
					cout << "Course Instructor: " << res->getInt("CourseInstr") << endl;
					cout << "Department: " << res->getString("Department") << endl;
					cout << endl;
				}
			}
			else {
				cout << "No data found in the database." << endl;
			}
			delete res;
			delete stmt;
			delete conn;
			cout << "Records displayed successfully!" << endl;

		cout << "Enter Course No and Name of course you want to remove from database:" << endl;

		int id;
		string name;

		cout << "Enter Course No: ";
		cin >> id;
		cout << "Enter the Course name: ";
		getline(cin, name);

		stmt = conn->prepareStatement("DELETE FROM courses  Where CourseNo = ? AND Course = ?");
		stmt->setInt(1, id);
		stmt->setString(2, name);
		stmt->execute();

		cout << endl;
		cout << "Record Removed Successfully" << endl;
		cout << endl;
		delete res;
	}

	// Displaying course data from database
	void displaycoursefromDatabase()
	{
		try {
			sql::Connection* conn;
			sql::Driver* driver;
			driver = get_driver_instance();
			conn = driver->connect(host, username, password);
			if (!conn) {
				cout << "Connection to the database failed." << endl;
				return;
			}
			Sleep(3000);
			cout << "Displaying data from database:" << endl;
			sql::PreparedStatement* stmt = conn->prepareStatement("SELECT * FROM Courses");
			sql::ResultSet* res = stmt->executeQuery();
			if (res) {
				while (res->next()) {
					cout << "Course No: " << res->getInt("CourseNo") << endl;
					cout << "Course Name: " << res->getString("Course") << endl;
					cout << "Course Instructor: " << res->getInt("CourseInstr") << endl;
					cout << "Department: " << res->getString("Department") << endl;
					cout << endl;
				}
			}
			else {
				cout << "No data found in the database." << endl;
			}
			delete res;
			delete stmt;
			delete conn;
			cout << "Records displayed successfully!" << endl;
		}
		catch (sql::SQLException& e) {
			cout << "SQL Exception: " << e.what() << endl;
		}
		catch (std::runtime_error& e) {
			cout << "Runtime Error: " << e.what() << endl;
		}

	}

};

// Main Menu
int main()
{
	try {
		
		sql::Driver* driver;
		sql::Connection* conn;

	driver = get_driver_instance();
	conn = driver->connect(host, username,password);

	if (!conn)
	{
		cout << "Connection failed\n";
	}
	else 
	{
		cout << "\t\nConnection Secured.\n";
	}
	Sleep(3000);
	}
	catch (sql::SQLException& e) {
		cout << "SQL Exception: " << e.what() << endl;
	}
	catch (std::runtime_error& e) {
		cout << "Runtime Error: " << e.what() << endl;
	}
		
	administration admin;
	bool Exit = false;
	int option;

	while (!Exit)
	{
		// Main menu
	MainMenu:
		system("cls");
		cout << "\n\t\t WELCOME TO UNIVERSITY MANAGEMENT SYSTEM\n";
		cout << "\t\t -----------------------------------------\n";

		cout << "1. Administrator" << endl;
		cout << "2. Faculty" << endl;
		cout << "3. Student" << endl;
		cout << "4. Exit" << endl;

		cout << "\nEnter your choice: ";
		cin >> option;

		cout << endl;
		cout << "Wait, while we are processing......";
		Sleep(3000);

		// For admin

		if (option == 1)
		{	
			int val;
			
			system("cls");
				
			cout << endl;
			cout << "1. Register" << endl;
			cout << "2. Login" << endl;
			cout << "3. Main Menu" << endl;
			cout << "4. Exit" << endl;

			cout << "\nEnter your choice: ";
			cin >> val;

			cout << endl;
			cout << "Wait, while we are processing......";
			Sleep(3000);
			system("cls");

			if (val == 1)
			{
				cout << endl;
				cout << "To Register enter your username and password" << endl;

				admin.Registration();

				cout << endl;
				cout << "Wait, while we are processing......";
				Sleep(3000);
				system("cls");
				
				int opt;
			ADMIN:

				cout << endl;
				cout << "1.  Add a new Admin" << endl;
				cout << "2.  Update existing Admins" << endl;
				cout << "3.  Remove any Admin" << endl;
				cout << "4.  Display Admins" << endl;
				cout << "5.  Add a new Student" << endl;
				cout << "6.  Update existing Student" << endl;
				cout << "7.  Remove any Student" << endl;
				cout << "8.  Display Students" << endl;
				cout << "9.  Add a new Faculty member" << endl;
				cout << "10. Update existing Faculty" << endl;
				cout << "11. Remove any Faculty" << endl;
				cout << "12. Display Faculty" << endl;
				cout << "13. Add a new Course " << endl;
				cout << "14. Update existing Courses" << endl;
				cout << "15. Remove any Courses" << endl;
				cout << "16. Display Courses" << endl;
				cout << "17. Main menu" << endl;
				cout << " Exit" << endl;

				cout << "\nEnter your choice: ";
				cin >> opt;

				cout << endl;
				cout << "Wait, while we are processing......";
				Sleep(3000);
				system("cls");

				if (opt == 1)
				{
					char val;
					do
					{
						cout <<endl;
						admin.insertIntoDatabase();
						cout << "You want to enter any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMIN;
				}

				else if (opt == 2)
				{
					char val;
					do
					{
						cout <<endl;
						admin.updateIntoDatabase();
						cout << "You want to update any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMIN;
				}

				else if (opt == 3)
				{
					char val;
					do
					{
						cout << endl;

						admin.removefromDatabase();
						cout << "You want to remove any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMIN;
				}

				else if (opt == 4)
				{
					cout << endl;
					admin.displayfromDatabase();
					Sleep(3000);
					system("cls");
					goto ADMIN;
			
				}
				
				else if (opt == 5)
				{
					char val;
					do
					{
						cout << endl;
						admin.insertstudentintodatabase();
						cout << "You want to enter any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');

					goto ADMIN;
				}

				else if (opt == 6)
				{
					goto MainMenu;
				}

				else if (opt == 7)
				{
					char val;
					do
					{
						cout << endl;

						admin.removestudentfromDatabase();
						cout << "You want to remove any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMIN;
				}

				else if (opt == 8)
				{
					cout << endl;
					admin.displaystudentfromDatabase();
					Sleep(3000);
					system("cls");
					goto ADMIN;
				}

				else if (opt == 9)
				{
					char val;
					do
					{
						cout << endl;
						admin.insertfacultyintodatabase();
						cout << "You want to enter any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');

					goto ADMIN;
				}

				else if (opt == 10)
				{
					goto MainMenu;
				}

				else if (opt == 11)
				{
					char val;
					do
					{
						cout << endl;

						admin.removefacultyfromDatabase();
						cout << "You want to remove any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMIN;
				}

				else if (opt == 12)
				{
					cout << endl;
					admin.displayfacultyfromDatabase();
					Sleep(3000);
					system("cls");
					goto ADMIN;
				}
				 
				else if (opt == 13)
				{
					char val;
					do
					{
						cout << endl;
						admin.insertcourseIntoDatabase();
						cout << "You want to enter any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');

					goto ADMINL;
				}

				else if (opt == 14)
				{
					goto MainMenu;
				}

				else if (opt == 15)
				{
					char val;
					do
					{
						cout << endl;

						admin.removecoursefromDatabase();
						cout << "You want to remove any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMIN;
				}

				else if (opt == 16)
				{
					cout << endl;
					admin.displaycoursefromDatabase();
					Sleep(3000);
					system("cls");
					goto ADMIN;
				}

				else if (opt == 17)
				{
					goto MainMenu;
				}

				else
				{
					exit(0);
				}
			}
			else if (val == 2)
			{
				cout << endl;
				cout << "To Login enter your username and password" << endl;

				admin.Login();

				cout << endl;
				cout << "Wait, while we are processing......";
				Sleep(3000);
				system("cls");
	
			ADMINL:

				int opt;
				cout << endl;
				cout << "1.  Add a new Admin" << endl;
				cout << "2.  Update existing Admins" << endl;
				cout << "3.  Remove any Admin" << endl;
				cout << "4.  Display Admins" << endl;
				cout << "5.  Add a new Student" << endl;
				cout << "6.  Update existing Student" << endl;
				cout << "7.  Remove any Student" << endl;
				cout << "8.  Display Students" << endl;
				cout << "9.  Add a new Faculty member" << endl;
				cout << "10. Update existing Faculty" << endl;
				cout << "11. Remove any Faculty" << endl;
				cout << "12. Display Faculty" << endl;
				cout << "13. Add a new Course " << endl;
				cout << "14. Update existing Courses" << endl;
				cout << "15. Remove any Courses" << endl;
				cout << "16. Display Courses" << endl;
				cout << "17. Main menu" << endl;
				cout << " Exit" << endl;

				cout << "\nEnter your choice: ";
				cin >> opt;

				cout << endl;
				cout << "Wait, while we are processing......";
				Sleep(3000);
				system("cls");

				if (opt == 1)
				{
					char val;
					do
					{
						cout <<endl;
						admin.insertIntoDatabase();
						cout << "You want to enter any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMINL;
				}

				else if (opt == 2)
				{
					char val;
					do
					{
						cout <<endl;
						admin.updateIntoDatabase();
						cout << "You want to update any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMINL;
				}

				else if (opt == 3)
				{
					char val;
					do
					{
						cout <<endl;
						admin.removefromDatabase();
						cout << "You want to remove any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMINL;
				}

				else if (opt == 4)
				{
					cout <<endl;
					admin.displayfromDatabase();
					Sleep(3000);
					system("cls");
					goto ADMINL;
				}

				else if (opt == 5)
				{
					char val;
					do
					{
						cout << endl;
						admin.insertstudentintodatabase();
						cout << "You want to enter any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');

					goto ADMINL;
				}

				else if (opt == 6)
				{
					goto MainMenu;
				}

				else if (opt == 7)
				{

					char val;
					do
					{
						cout << endl;
						admin.removestudentfromDatabase();
						cout << "You want to remove any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMINL;
				}

				else if (opt == 8)
				{
					cout << endl;
					admin.displayfromDatabase();
					Sleep(3000);
					system("cls");
					goto ADMINL;
				}

				else if (opt == 9)
				{
					char val;
					do
					{
						cout << endl;
						admin.insertfacultyintodatabase();
						cout << "You want to enter any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');

					goto ADMINL;
				}

				else if (opt == 10)
				{
					goto MainMenu;
				}

				else if (opt == 11)
				{
					char val;
					do
					{
						cout << endl;
						admin.removefromDatabase();
						cout << "You want to remove any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMINL;
				}

				else if (opt == 12)
				{
					cout << endl;
					admin.displayfacultyfromDatabase();
					Sleep(3000);
					system("cls");
					goto ADMINL;
				}

				else if (opt == 13)
				{
					char val;
					do
					{
						cout << endl;
						admin.insertcourseIntoDatabase();
						cout << "You want to enter any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');

					goto ADMINL;
				}

				else if (opt == 14)
				{
					goto MainMenu;
				}

				else if (opt == 15)
				{
					char val;
					do
					{
						cout << endl;

						admin.removecoursefromDatabase();
						cout << "You want to remove any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMINL;
				}

				else if (opt == 16)
				{
					cout << endl;
					admin.displaycoursefromDatabase();
					Sleep(3000);
					system("cls");
					goto ADMINL;
				}

				else if (opt == 17)
				{
					goto MainMenu;
				}

				else 
				{
					exit(0);
				}
				
			}
			else if (val == 3)
			{
				goto MainMenu;
			}

			else
			{
				exit(0);
			}
		}

		// For faculty

		else if (option == 2)
		{

		}

		// For student

		else if (option == 3)
		{

		}

		// To exit

		else
		{
			exit(0);
		}

		Exit = true;

	}
	  return 0;	
}	