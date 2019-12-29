#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class Hospital
{
public:
	string HosId;
	string HosName;
	string Address;
	string BossId;
	string BossName;


public:
	void CreateHos();
	void ListHos();
	void DeleteHos();
	void EditHos();
	void SearchHos();
	void tools(string idx, string namex, string mName, int cont);
};

void Hospital::CreateHos()
{
	cout << "*** Shenase Bimarstan : ";
	cin >> HosId;

	string search;
	int offset;
	string line;
	ifstream myfile1;
	myfile1.open("hospital.txt");

	if (myfile1.is_open())
	{
		while (!myfile1.eof())
		{
			getline(myfile1, line);
			if ((offset = line.find("Shenase Bimarstan : " + HosId, 0)) != string::npos)
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
		cout << "In Shenase Bimarstan Mojod Mibashad!" << endl;
	}
	else
	{
		ofstream myfile;
		system("CLS");
		cout << "*** Sabt Bimarstan Jadid *** \n" << endl;
		myfile.open("hospital.txt", ios::out | ios::app);

		cout << "*** Shenase Bimarstan : ";
		cin >> HosId;
		myfile << "Shenase Bimarstan : " << HosId;
		myfile << "\n";

		//
		cout << "*** Name Bimarstan : ";
		cin >> HosName;
		myfile << "Name Bimarstan : " << HosName;
		myfile << "\n";

		//
		cout << "*** Address Bimarstan : ";
		cin >> Address;
		myfile << "Address Bimarstan : " << Address;
		myfile << "\n";

		//
		cout << "*** Kod Rais Bimarstan : ";
		cin >> BossId;
		myfile << "Kod Rais Bimarstan : " << BossId;
		myfile << "\n";

		//
		cout << "*** Name Rais Bimarstan : ";
		cin >> BossName;
		myfile << "Name Rais Bimarstan : " << BossName;
		myfile << "\n";


		myfile << "-----------------------------------\n";
		myfile.close();

		cout << "Bimarstan Jadid Ba Moafaghiat Sabt Gardid.\n" << endl;
	}

}

void Hospital::ListHos()
{
	fstream file;
	file.open("hospital.txt", ios::in);
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

void Hospital::DeleteHos()
{
	string line, Code;
	cout << "Kod Bimarstan Ra Vared Konid: ";
	cin >> Code;
	ifstream myfile;
	ofstream temp;
	myfile.open("hospital.txt");
	temp.open("temp.txt");

	int skip = 0;

	while (getline(myfile, line))
	{
		if ((line != "Shenase Bimarstan : " + Code) && !(skip > 0))
		{
			temp << line << endl;
		}
		else if ((line == "Shenase Bimarstan : " + Code))
		{
			if (skip == 0)
			{
				skip = 6;
			}
			else
			{
				--skip;
			}
		}
	}
	cout << "Bimarstan Ba Kode " << Code << " Ba Moafqiat Hazf Shod." << endl;
	myfile.close();
	temp.close();
	remove("hospital.txt");
	rename("temp.txt", "hospital.txt");

}
//

void Hospital::EditHos()
{

	string line1, line;
	string search, choic;
	int offset;
	int skip = 6;
	//
	ifstream myfile;
	myfile.open("hospital.txt");
	//


	cout << "Kod Bimarstan Ra Vared Konid : > ";
	cin >> search;


	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if ((offset = line.find("Shenase Bimarstan : " + search, 0)) != string::npos)
			{
				cout << "Natijeh Jostjo" << "\n" << "Shenase Bimarstan : " << search << endl;
				for (int i = 0; i < skip; i++)
				{
					getline(myfile, line1);
					if ((line1 != "Shenase Bimarstan : " + search)) {
						cout << line1 << endl;
					}
				}
			}
		}
		myfile.close();
	}

	cout << "1) Virayesh Name Bimarstan" << endl;
	cout << "2) Virayesh Adres Bimarstan" << endl;
	cout << "3) Virayesh Kod Rais Bimarstan" << endl;
	cout << "4) Virayesh Name Rais Bimarstan" << endl;
	cout << "kodam ra mikhahid virayesh konid: ";
	cin >> choic;

	if (choic == "1")
	{
		cout << "Name Bimarstan : ";
		cin >> HosName;
		tools(search, "Name Bimarstan : ", HosName, 0);
	}
	if (choic == "2")
	{
		cout << "Address Bimarstan : ";
		cin >> Address;
		tools(search, "Address Bimarstan : ", Address, 1);
	}
	if (choic == "3")
	{
		cout << "Kod Rais Bimarstan : ";
		cin >> BossId;
		tools(search, "Kod Rais Bimarstan : ", BossId, 2);
	}
	if (choic == "4")
	{
		cout << "Name Rais Bimarstan : ";
		cin >> BossName;
		tools(search, "Name Rais Bimarstan : ", BossName, 3);
	}

}

void Hospital::tools(string idx, string namex, string mName, int cont)
{
	ofstream outFile("temp.txt");
	ifstream readFile("hospital.txt");
	string readout;
	string search;
	int count = 0, start = -1;
	while (getline(readFile, readout))
	{

		if (readout == "Shenase Bimarstan : " + idx)
		{
			outFile << "Shenase Bimarstan : " << idx << endl;
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
	cout << "Bimarstan Ba Moafaghiat Virayesh Gardid.\n" << endl;
	readFile.close();
	outFile.close();
	remove("hospital.txt");
	rename("temp.txt", "hospital.txt");
}



void Hospital::SearchHos()
{
	string search;
	int offset;
	int skip = 5;
	string line;
	string line1;
	ifstream myfile;
	myfile.open("hospital.txt");
	cout << "Kod Bimarstan Ra Vared Konid: ";
	cin >> search;

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if ((offset = line.find("Shenase Bimarstan : " + search, 0)) != string::npos)
			{
				cout << "Natijeh Jostjo" << "\n" << "Shenase Bimarstan : " << search << endl;
				for (int i = 0; i < skip; i++)
				{
					getline(myfile, line1);
					if ((line1 != "Shenase Bimarstan : " + search)) {
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


