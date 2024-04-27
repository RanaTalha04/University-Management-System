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
		cin >> AName;
		cout << "Enter Age: ";
		cin >> Age;
		cout << "Enter Designation: ";
		cin >> Designation;
		cout << "Enter Department: ";
		cin >> Department;
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
			cin >> name;

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
			cin >> name;
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
			cin >> desig;
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
			cin >> depart;
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
			cin >> name;

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
				cout << "1. Add a new admin to database" << endl;
				cout << "2. Update existing admin" << endl;
				cout << "3. Remove any admin" << endl;
				cout << "4. Show the data of all admins" << endl;
				cout << "5. Main menu" << endl;
				cout << "6. Exit" << endl;

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
						cout << "You want to enter any other data?";
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
				cout << "1. Add a new admin to database" << endl;
				cout << "2. Update existing admin" << endl;
				cout << "3. Remove any admin" << endl;
				cout << "4. Show the data of all admins" << endl;
				cout << "5. Main menu" << endl;
				cout << "5. Exit" << endl;

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
						cout << "You want to enter any other data?";
						cin >> val;
						system("cls");
					} while (val == 'Y' || val == 'y');
					goto ADMIN;
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
		else if (option == 2)
		{

		}
		else if (option == 3)
		{

		}
		else
		{
			exit(0);
		}

		Exit = true;

	}
	return 0;	
}	