#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

class Accounting
{
public:
	string PatId;
	string FName;
	string LName;
	string CodeMeli;
	string Tellphone;
	string Date;
	string BakhshName;
	string TedadRozBestari;
	string MablaghKol;
	string Bimeh;
	string darsadBimeh;
	string UltPricePay;

public:
	void CreateAccounting();
	void ListAccounting();
	void DeleteAccounting();
	void EditAccounting();
	void SearchAccounting();
	void tools(string idx, string namex, string mName, int cont);
};

void Accounting::CreateAccounting()
{
	cout << "*** Shenase Bimar : ";
	cin >> PatId;

	string search;
	int offset;
	string line;
	ifstream myfile1;
	myfile1.open("accounting.txt");

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
		cout << "*** Sabt Tasvieh Hesab Jadid *** \n" << endl;
		myfile.open("accounting.txt", ios::out | ios::app);

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
		cout << "*** Tarikh Tarkhis Bimar : ";
		cin >> Date;
		myfile << "Tarikh Tarkhis : " << Date;
		myfile << "\n";

		//
		cout << "*** Name Bakhsh : ";
		cin >> BakhshName;
		myfile << "Bakhsh Name : " << BakhshName;
		myfile << "\n";
		//
		cout << "*** Tedad Rooz Bestari : ";
		cin >> TedadRozBestari;
		myfile << "Tedad Rooz Bestari : " << TedadRozBestari;
		myfile << "\n";
		//
		cout << "*** Mablagh kol : ";
		cin >> MablaghKol;
		myfile << "Mablagh kol : " << MablaghKol;
		myfile << "\n";
		//
		cout << "*** Name Bimeh Darmani : ";
		cin >> Bimeh;
		myfile << "Name Bimeh : " << Bimeh;
		myfile << "\n";
		//
		cout << "*** Darsad Bimeh : ";
		cin >> darsadBimeh;
		myfile << "Darsad Bimeh : " << darsadBimeh;
		myfile << "\n";
		//
		cout << "*** Mablagh Kol Pardakhti : ";
		cin >> UltPricePay;
		myfile << "Mablagh Kol Pardakhti : " << UltPricePay;
		myfile << "\n";

		myfile << "-----------------------------------\n";
		myfile.close();

		cout << "Tasvieh Hesab Jadid Ba Moafaghiat Sabt Gardid.\n" << endl;
	}

}

void Accounting::ListAccounting()
{
	fstream file;
	file.open("accounting.txt", ios::in);
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

void Accounting::DeleteAccounting()
{
	string line, Code;
	cout << "Kod Bimar Ra Vared Konid: ";
	cin >> Code;
	ifstream myfile;
	ofstream temp;
	myfile.open("accounting.txt");
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
				skip = 12;
			}
			else
			{
				--skip;
			}
		}
	}
	cout << "Tasvieh Hesab Ba Kode " << Code << " Ba Moafqiat Hazf Shod." << endl;
	myfile.close();
	temp.close();
	remove("accounting.txt");
	rename("temp.txt", "accounting.txt");

}
//

void Accounting::EditAccounting()
{

	string line1, line;
	string search, choic;
	int offset;
	int skip = 12;
	//
	ifstream myfile;
	myfile.open("accounting.txt");
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
	cout << "5) Virayesh Tarikh Tarkhis Bimar" << endl;
	cout << "6) Virayesh Bakhsh Bestari Bimar" << endl;
	cout << "7) Virayesh Tedad Roz Bestari Bimar" << endl;
	cout << "8) Virayesh Mablagh Kol" << endl;
	cout << "9) Virayesh Bimeh" << endl;
	cout << "10) Virayesh darsad Bimeh" << endl;
	cout << "11) Virayesh Mablagh Kol Pardakhti" << endl;
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
		cout << "Tarikh tarkhis Bimar : ";
		cin >> Date;
		tools(search, "Tarikh Tarkhis : ", Date, 4);
	}
	if (choic == "6")
	{
		cout << "Bakhsh Bestari Bimar : ";
		cin >> BakhshName;
		tools(search, "Bakhsh Name : ", BakhshName, 5);
	}
	if (choic == "7")
	{
		cout << "Tedad Roz Bestari : ";
		cin >> TedadRozBestari;
		tools(search, "Tedad Roz Bestari : ", TedadRozBestari, 6);
	}
	if (choic == "8")
	{
		cout << "Mablagh Kol : ";
		cin >> MablaghKol;
		tools(search, "Mablagh Kol : ", MablaghKol, 7);
	}
	if (choic == "9")
	{
		cout << "Bimeh : ";
		cin >> Bimeh;
		tools(search, "Name Bimeh : ", Bimeh, 8);
	}
	if (choic == "10")
	{
		cout << "darsad Bimeh : ";
		cin >> darsadBimeh;
		tools(search, "Darsad Bimeh : ", darsadBimeh, 9);
	}
	if (choic == "11")
	{
		cout << "Mablagh Kol Pardakhti : ";
		cin >> UltPricePay;
		tools(search, "Mablagh Kol Pardakhti : ", UltPricePay, 10);
	}
}

void Accounting::tools(string idx, string namex, string mName, int cont)
{
	ofstream outFile("temp.txt");
	ifstream readFile("accounting.txt");
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
	cout << "Tasvieh Hesab Ba Moafaghiat Virayesh Gardid.\n" << endl;
	readFile.close();
	outFile.close();
	remove("accounting.txt");
	rename("temp.txt", "accounting.txt");
}

void Accounting::SearchAccounting()
{
	string search;
	int offset;
	int skip = 12;
	string line;
	string line1;
	ifstream myfile;
	myfile.open("accounting.txt");
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


