#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class Employee
{
public:
	string EmpId;
	string FName;
	string LName;
	string CodeMeli;
	string Tellphone;
	string Roal;
	string BakhshName;

public:
	void CreateEmp();
	void ListEmp();
	void DeleteEmp();
	void EditEmp();
	void SearchEmp();
	void tools(string idx, string namex, string mName, int cont);
};

void Employee::CreateEmp()
{
	cout << "*** Shenase Karmand : ";
	cin >> EmpId;

	string search;
	int offset;
	string line;
	ifstream myfile1;
	myfile1.open("employee.txt");

	if (myfile1.is_open())
	{
		while (!myfile1.eof())
		{
			getline(myfile1, line);
			if ((offset = line.find("Shenase Karmand : " + EmpId, 0)) != string::npos)
			{
				search = "OK";
			}
		}
		myfile1.close();
	}
	else
	{
		cout << "Yaft Nashod!";
	}

	if (search == "OK")
	{
		cout << "In Shenase Karmand Mojod Mibashad!" << endl;
	}
	else
	{
		ofstream myfile;
		system("CLS");
		cout << "*** Sabt Karmand Jadid *** \n" << endl;
		myfile.open("employee.txt", ios::out | ios::app);

		cout << "*** Shenase Karmand : ";
		cin >> EmpId;
		myfile << "Shenase Karmand : " << EmpId;
		myfile << "\n";

		//
		cout << "*** Name Karmand : ";
		cin >> FName;
		myfile << "Name Karmand : " << FName;
		myfile << "\n";

		//
		cout << "*** Name Khanvadgi Karmand : ";
		cin >> LName;
		myfile << "Family Karmand : " << LName;
		myfile << "\n";

		//
		cout << "*** Code Meli Karmand : ";
		cin >> CodeMeli;
		myfile << "Code Meli : " << CodeMeli;
		myfile << "\n";

		//
		cout << "*** Tellpone Karmand : ";
		cin >> Tellphone;
		myfile << "Tellpone Karmand : " << Tellphone;
		myfile << "\n";
		//
		cout << "*** Semat Karmand : ";
		cin >> Roal;
		myfile << "Semat Karmand : " << Roal;
		myfile << "\n";

		//
		cout << "*** Name Bakhsh : ";
		cin >> BakhshName;
		myfile << "Bakhsh Name : " << BakhshName;
		myfile << "\n";

		myfile << "-----------------------------------\n";
		myfile.close();

		cout << "Karmand Jadid Ba Moafaghiat Sabt Gardid.\n" << endl;
	}

}

void Employee::ListEmp()
{
	fstream file;
	file.open("employee.txt", ios::in);
	string wholeFile;

	if (file.is_open())
	{
		stringstream buffer;
		buffer << file.rdbuf();
		wholeFile = buffer.str();
	}
	else
	{
		cout << "Khata Dar Baz Kardan File!";
	}
	cout << wholeFile;

}

void Employee::DeleteEmp()
{
	string line, Code;
	cout << "Kod Karmand Ra Vared Konid: ";
	cin >> Code;
	ifstream myfile;
	ofstream temp;
	myfile.open("employee.txt");
	temp.open("temp.txt");

	int skip = 0;

	while (getline(myfile, line))
	{
		if ((line != "Shenase Karmand : " + Code) && !(skip > 0))
		{
			temp << line << endl;
		}
		else if ((line == "Shenase Karmand : " + Code))
		{
			if (skip == 0)
			{
				skip = 7;
			}
			else
			{
				--skip;
			}
		}
	}
	cout << "Karmand Ba Kode " << Code << " Ba Moafqiat Hazf Shod." << endl;
	myfile.close();
	temp.close();
	remove("employee.txt");
	rename("temp.txt", "employee.txt");

}
//

void Employee::EditEmp()
{

	string line1, line;
	string search, choic;
	int offset;
	int skip = 6;
	//
	ifstream myfile;
	myfile.open("employee.txt");
	//


	cout << "Kod Karmand Ra Vared Konid : > ";
	cin >> search;


	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if ((offset = line.find("Shenase Karmand : " + search, 0)) != string::npos)
			{
				cout << "Natijeh Jostjo" << "\n" << "Shenase Karmand : " << search << endl;
				for (int i = 0; i < skip; i++)
				{
					getline(myfile, line1);
					if ((line1 != "Shenase Karmand : " + search)) {
						cout << line1 << endl;
					}
				}
			}
		}
		myfile.close();
	}

	cout << "1) Virayesh Name Karmand" << endl;
	cout << "2) Virayesh Family Karmand" << endl;
	cout << "3) Virayesh Kod Meli Karmand" << endl;
	cout << "4) Virayesh Telphone Karmand" << endl;
	cout << "5) Virayesh Semat Karmand" << endl;
	cout << "6) Virayesh Bakhsh Faaliat Karmand" << endl;
	cout << "kodam ra mikhahid virayesh konid: ";
	cin >> choic;

	if (choic == "1")
	{
		cout << "Name Karmand : ";
		cin >> FName;
		tools(search, "Name Karmand : ", FName, 0);
	}
	if (choic == "2")
	{
		cout << "Family Karmand : ";
		cin >> LName;
		tools(search, "Family Karmand : ", LName, 1);
	}
	if (choic == "3")
	{
		cout << "Kod Meli Karmand : ";
		cin >> CodeMeli;
		tools(search, "Code Meli : ", CodeMeli, 2);
	}
	if (choic == "4")
	{
		cout << "Tellpone Karmand : ";
		cin >> Tellphone;
		tools(search, "Tellpone Karmand : ", Tellphone, 3);
	}
	if (choic == "5")
	{
		cout << "Semat Karmand : ";
		cin >>Roal;
		tools(search, "Semat Karmand : ", Roal, 4);
	}
	if (choic == "6")
	{
		cout << "Bakhsh Faaliat Karmand : ";
		cin >> BakhshName;
		tools(search, "Bakhsh Name : ", BakhshName, 5);
	}
}

void Employee::tools(string idx, string namex, string mName, int cont)
{
	ofstream outFile("temp.txt");
	ifstream readFile("employee.txt");
	string readout;
	string search;
	int count = 0, start = -1;
	while (getline(readFile, readout))
	{

		if (readout == "Shenase Karmand : " + idx)
		{
			outFile << "Shenase Karmand : " << idx << endl;
			start = cont;
			count = 0;
		}
		else if (count == start)
		{
			outFile << namex << mName << endl;
			count++;
		}
		else
		{
			outFile << readout << endl;
			count++;
		}
	}
	cout << "Karmand Ba Moafaghiat Virayesh Gardid.\n" << endl;
	readFile.close();
	outFile.close();
	remove("employee.txt");
	rename("temp.txt", "employee.txt");
}



void Employee::SearchEmp()
{
	string search;
	int offset;
	int skip = 7;
	string line;
	string line1;
	ifstream myfile;
	myfile.open("employee.txt");
	cout << "Kod Karmand Ra Vared Konid: ";
	cin >> search;

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if ((offset = line.find("Shenase Karmand : " + search, 0)) != string::npos)
			{
				cout << "Natijeh Jostjo" << "\n" << "Shenase Karmand : " << search << endl;
				for (int i = 0; i < skip; i++)
				{
					getline(myfile, line1);
					if ((line1 != "Shenase Karmand : " + search)) {
						cout << line1 << endl;
					}
				}
			}
		}
		myfile.close();
	}
	else
	{
		cout << "Yaft Nashod!";
	}
}


