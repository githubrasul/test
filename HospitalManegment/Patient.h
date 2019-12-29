#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class Patient
{
public:
	string PatId;
	string FName;
	string LName;
	string CodeMeli;
	string Tellphone;
	string Date;
	string Doctor;
	string BakhshName;

public:
	void CreatePatient();
	void ListPatient();
	void DeletePatient();
	void EditPatient();
	void SearchPatient();
	void tools(string idx, string namex, string mName, int cont);
};

void Patient::CreatePatient()
{
	cout << "*** Shenase Bimar : ";
	cin >> PatId;

	string search;
	int offset;
	string line;
	ifstream myfile1;
	myfile1.open("patient.txt");

	if (myfile1.is_open())
	{
		while (!myfile1.eof())
		{
			getline(myfile1, line);
			if ((offset = line.find("Shenase Bimar : " + PatId, 0)) != string::npos)
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
		cout << "In Shenase Bimar Mojod Mibashad!" << endl;
	}
	else
	{
		ofstream myfile;
		system("CLS");
		cout << "*** Sabt Bimar Jadid *** \n" << endl;
		myfile.open("patient.txt", ios::out | ios::app);

		cout << "*** Shenase Bimar : ";
		cin >> PatId;
		myfile << "Shenase Bimar : " << PatId;
		myfile << "\n";

		//
		cout << "*** Name Bimar : ";
		cin >> FName;
		myfile << "Name Bimar : " << FName;
		myfile << "\n";

		//
		cout << "*** Name Khanvadgi Bimar : ";
		cin >> LName;
		myfile << "Family Bimar : " << LName;
		myfile << "\n";

		//
		cout << "*** Code Meli Bimar : ";
		cin >> CodeMeli;
		myfile << "Code Meli : " << CodeMeli;
		myfile << "\n";

		//
		cout << "*** Tellpone Bimar : ";
		cin >> Tellphone;
		myfile << "Tellpone Bimar : " << Tellphone;
		myfile << "\n";
		//
		cout << "*** Tarikh Paziresh Bimar : ";
		cin >> Date;
		myfile << "Tarikh Paziresh : " << Date;
		myfile << "\n";
		//
		cout << "*** Pezeshk Moalej : ";
		cin >> Doctor;
		myfile << "Doctor : " << Doctor;
		myfile << "\n";

		//
		cout << "*** Name Bakhsh : ";
		cin >> BakhshName;
		myfile << "Bakhsh Name : " << BakhshName;
		myfile << "\n";

		myfile << "-----------------------------------\n";
		myfile.close();

		cout << "Bimar Jadid Ba Moafaghiat Sabt Gardid.\n" << endl;
	}

}

void Patient::ListPatient()
{
	fstream file;
	file.open("patient.txt", ios::in);
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

void Patient::DeletePatient()
{
	string line, Code;
	cout << "Kod Bimar Ra Vared Konid: ";
	cin >> Code;
	ifstream myfile;
	ofstream temp;
	myfile.open("patient.txt");
	temp.open("temp.txt");

	int skip = 0;

	while (getline(myfile, line))
	{
		if ((line != "Shenase Bimar : " + Code) && !(skip > 0))
		{
			temp << line << endl;
		}
		else if ((line == "Shenase Bimar : " + Code))
		{
			if (skip == 0)
			{
				skip = 8;
			}
			else
			{
				--skip;
			}
		}
	}
	cout << "Bimar Ba Kode " << Code << " Ba Moafqiat Hazf Shod." << endl;
	myfile.close();
	temp.close();
	remove("patient.txt");
	rename("temp.txt", "patient.txt");

}
//

void Patient::EditPatient()
{

	string line1, line;
	string search, choic;
	int offset;
	int skip = 7;
	//
	ifstream myfile;
	myfile.open("patient.txt");
	//


	cout << "Kod Bimar Ra Vared Konid : > ";
	cin >> search;


	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if ((offset = line.find("Shenase Bimar : " + search, 0)) != string::npos)
			{
				cout << "Natijeh Jostjo" << "\n" << "Shenase Bimar : " << search << endl;
				for (int i = 0; i < skip; i++)
				{
					getline(myfile, line1);
					if ((line1 != "Shenase Bimar : " + search)) {
						cout << line1 << endl;
					}
				}
			}
		}
		myfile.close();
	}

	cout << "1) Virayesh Name Bimar" << endl;
	cout << "2) Virayesh Family Bimar" << endl;
	cout << "3) Virayesh Kod Meli Bimar" << endl;
	cout << "4) Virayesh Telphone Bimar" << endl;
	cout << "5) Virayesh Tarikh Paziresh Bimar" << endl;
	cout << "6) Virayesh Pezeshk Moalej Bimar" << endl;
	cout << "7) Virayesh Bakhsh Bestari Bimar" << endl;
	cout << "kodam ra mikhahid virayesh konid: ";
	cin >> choic;

	if (choic == "1")
	{
		cout << "Name Bimar : ";
		cin >> FName;
		tools(search, "Name Bimar : ", FName, 0);
	}
	if (choic == "2")
	{
		cout << "Family Bimar : ";
		cin >> LName;
		tools(search, "Family Bimar : ", LName, 1);
	}
	if (choic == "3")
	{
		cout << "Kod Meli Bimar : ";
		cin >> CodeMeli;
		tools(search, "Code Meli : ", CodeMeli, 2);
	}
	if (choic == "4")
	{
		cout << "Tellpone Bimar : ";
		cin >> Tellphone;
		tools(search, "Tellpone Bimar : ", Tellphone, 3);
	}
	if (choic == "5")
	{
		cout << "Tarikh Paziresh Bimar : ";
		cin >> Date;
		tools(search, "Tarikh Paziresh : ", Date, 4);
	}
	if (choic == "6")
	{
		cout << "Pezeshk Moalej Bimar : ";
		cin >> Doctor;
		tools(search, "Doctor : ", Doctor, 5);
	}
	if (choic == "7")
	{
		cout << "Bakhsh Faaliat Bimar : ";
		cin >> BakhshName;
		tools(search, "Bakhsh Name : ", BakhshName, 6);
	}
}

void Patient::tools(string idx, string namex, string mName, int cont)
{
	ofstream outFile("temp.txt");
	ifstream readFile("patient.txt");
	string readout;
	string search;
	int count = 0, start = -1;
	while (getline(readFile, readout))
	{

		if (readout == "Shenase Bimar : " + idx)
		{
			outFile << "Shenase Bimar : " << idx << endl;
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
	cout << "Bimar Ba Moafaghiat Virayesh Gardid.\n" << endl;
	readFile.close();
	outFile.close();
	remove("patient.txt");
	rename("temp.txt", "patient.txt");
}



void Patient::SearchPatient()
{
	string search;
	int offset;
	int skip = 8;
	string line;
	string line1;
	ifstream myfile;
	myfile.open("patient.txt");
	cout << "Kod Bimar Ra Vared Konid: ";
	cin >> search;

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if ((offset = line.find("Shenase Bimar : " + search, 0)) != string::npos)
			{
				cout << "Natijeh Jostjo" << "\n" << "Shenase Bimar : " << search << endl;
				for (int i = 0; i < skip; i++)
				{
					getline(myfile, line1);
					if ((line1 != "Shenase Bimar : " + search)) {
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


