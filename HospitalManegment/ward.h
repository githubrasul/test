#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class Ward
{
public:
	string WardId;
	string WardName;
	string TedadOtaq;
	string TedadParastar;
	string BossCode;


public:
	void CreateWard();
	void ListWard();
	void DeleteWard();
	void EditWard();
	void SearchWard();
	void tools(string idx, string namex, string mName, int cont);
};

void Ward::CreateWard()
{
	cout << "*** Shenase Bakhsh : ";
	cin >> WardId;

	string search;
	int offset;
	string line;
	ifstream myfile1;
	myfile1.open("ward.txt");

	if (myfile1.is_open())
	{
		while (!myfile1.eof())
		{
			getline(myfile1, line);
			if ((offset = line.find("Shenase Bakhsh : " + WardId, 0)) != string::npos)
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
		cout << "In Shenase Bakhsh Mojod Mibashad!" << endl;
	}
	else
	{
		ofstream myfile;
		system("CLS");
		cout << "*** Sabt Bakhsh Jadid *** \n" << endl;
		myfile.open("ward.txt", ios::out | ios::app);

		cout << "*** Shenase Bakhsh : ";
		cin >> WardId;
		myfile << "Shenase Bakhsh : " << WardId;
		myfile << "\n";

		//
		cout << "*** Name Bakhsh : ";
		cin >> WardName;
		myfile << "Name Bakhsh : " << WardName;
		myfile << "\n";

		//
		cout << "*** Tedad Otaq Bakhsh : ";
		cin >> TedadOtaq;
		myfile << "Tedad Otaq : " << TedadOtaq;
		myfile << "\n";

		//
		cout << "*** Tedad Parastar Bakhsh : ";
		cin >> TedadParastar;
		myfile << "Tedad Parastar : " << TedadParastar;
		myfile << "\n";

		//
		cout << "*** Code Rais Bakhsh : ";
		cin >> BossCode;
		myfile << "Code Rais Bakhsh : " << BossCode;
		myfile << "\n";


		myfile << "-----------------------------------\n";
		myfile.close();

		cout << "Bakhsh Jadid Ba Moafaghiat Sabt Gardid.\n" << endl;
	}

}

void Ward::ListWard()
{
	fstream file;
	file.open("ward.txt", ios::in);
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

void Ward::DeleteWard()
{
	string line, Code;
	cout << "Kod Bakhsh Ra Vared Konid: ";
	cin >> Code;
	ifstream myfile;
	ofstream temp;
	myfile.open("ward.txt");
	temp.open("temp.txt");

	int skip = 0;

	while (getline(myfile, line))
	{
		if ((line != "Shenase Bakhsh : " + Code) && !(skip > 0))
		{
			temp << line << endl;
		}
		else if ((line == "Shenase Bakhsh : " + Code))
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
	cout << "Bakhsh Ba Kode " << Code << " Ba Moafqiat Hazf Shod." << endl;
	myfile.close();
	temp.close();
	remove("ward.txt");
	rename("temp.txt", "ward.txt");

}
//

void Ward::EditWard()
{

	string line1, line;
	string search, choic;
	int offset;
	int skip = 6;
	//
	ifstream myfile;
	myfile.open("ward.txt");
	//


	cout << "Kod Bakhsh Ra Vared Konid : > ";
	cin >> search;


	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if ((offset = line.find("Shenase Bakhsh : " + search, 0)) != string::npos)
			{
				cout << "Natijeh Jostjo" << "\n" << "Shenase Bakhsh : " << search << endl;
				for (int i = 0; i < skip; i++)
				{
					getline(myfile, line1);
					if ((line1 != "Shenase Bakhsh : " + search)) {
						cout << line1 << endl;
					}
				}
			}
		}
		myfile.close();
	}

	cout << "1) Virayesh Name Bakhsh" << endl;
	cout << "2) Virayesh Tedad Otaq Bakhsh" << endl;
	cout << "3) Virayesh Tedad Parastar Bakhsh" << endl;
	cout << "4) Virayesh kod Rais Bakhsh" << endl;
	cout << "kodam ra mikhahid virayesh konid: ";
	cin >> choic;

	if (choic == "1")
	{
		cout << "Name Bakhsh : ";
		cin >> WardName;
		tools(search, "Name Bakhsh : ", WardName, 0);
	}
	if (choic == "2")
	{
		cout << "Tedad Otaq Bakhsh : ";
		cin >> TedadOtaq;
		tools(search, "Tedad Otaq : ", TedadOtaq, 1);
	}
	if (choic == "3")
	{
		cout << "Tedad Parastar Bakhsh : ";
		cin >> TedadParastar;
		tools(search, "Tedad Parastar : ", TedadParastar, 2);
	}
	if (choic == "4")
	{
		cout << "Kod Rais Bakhsh : ";
		cin >> BossCode;
		tools(search, "Code Rais Bakhsh : ", BossCode, 3);
	}

}

void Ward::tools(string idx, string namex, string mName, int cont)
{
	ofstream outFile("temp.txt");
	ifstream readFile("ward.txt");
	string readout;
	string search;
	int count = 0, start = -1;
	while (getline(readFile, readout))
	{

		if (readout == "Shenase Bakhsh : " + idx)
		{
			outFile << "Shenase Bakhsh : " << idx << endl;
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
	cout << "Bakhsh Ba Moafaghiat Virayesh Gardid.\n" << endl;
	readFile.close();
	outFile.close();
	remove("ward.txt");
	rename("temp.txt", "ward.txt");
}



void Ward::SearchWard()
{
	string search;
	int offset;
	int skip = 5;
	string line;
	string line1;
	ifstream myfile;
	myfile.open("ward.txt");
	cout << "Kod Bakhsh Ra Vared Konid: ";
	cin >> search;

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			if ((offset = line.find("Shenase Bakhsh : " + search, 0)) != string::npos)
			{
				cout << "Natijeh Jostjo" << "\n" << "Shenase Bakhsh : " << search << endl;
				for (int i = 0; i < skip; i++)
				{
					getline(myfile, line1);
					if ((line1 != "Shenase Bakhsh : " + search)) {
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


