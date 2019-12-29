#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "hospital.h"
#include "ward.h"
#include "employee.h"
#include "Patient.h"
#include "account.h"


using namespace std;

void MainMenu();

#pragma region Hospital

class menusHospital
{
public:

	void Add_Hospital();
	void Del_Hospital();
	void Rpt_Hospital();
	void Search_Hospital();
	void Edit_Hospital();

	void menu1()
	{
		int choice = 0;
		cout << "                               *** Modiriat Bimarstan *** \n" << endl;

		cout << "Yeki Az Gozineh hay Zir Ra Entekhab konid - \n" << endl;
		cout << "[1] Afzodan Bimarstan -" << endl;
		cout << "[2] Hazf Bimarstan -" << endl;
		cout << "[3] Virayesh Bimarstan -" << endl;
		cout << "[4] Jostjo Bimarstan -" << endl;
		cout << "[5] List Bimarstan -" << endl;
		cout << "[0] Menu Asli - \n" << endl;
		cout << "Entekhab Shoma :- ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			system("CLS");
			Add_Hospital();
			break;
		}
		case 2: {
			system("CLS");
			Del_Hospital();
			break;
		}
		case 3: {
			system("CLS");
			Edit_Hospital();
			break;
		}
		case 4: {
			system("CLS");
			Search_Hospital();
			break;
		}
		case 5: {
			system("CLS");
			Rpt_Hospital();
			break;
		}
		case 0: {
			system("CLS");
			MainMenu();
			break;
		}
		default:
			cout << "Gozeneh Entekhabi Eshtebast" << endl;
			break;
		}
	}
};
//
void menusHospital::Add_Hospital()
{
	char con;
	Hospital b;
	b.CreateHos();
	cout << "Aya Mikhahid Bimarstan jadid Ezafe Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Add_Hospital();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu1();
	}
}
//
void menusHospital::Del_Hospital()
{
	char con;
	Hospital b;
	b.DeleteHos();
	cout << "Aya Mikhahid Bimarstan digari hazf Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Del_Hospital();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu1();
	}
}
//
void menusHospital::Rpt_Hospital()
{
	char con;
	Hospital b;
	b.ListHos();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu1();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusHospital::Search_Hospital()
{
	char con;
	Hospital b;
	b.SearchHos();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu1();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusHospital::Edit_Hospital()
{
	char con;
	Hospital b;
	b.EditHos();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu1();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}


#pragma endregion

#pragma region Ward

class menusWard
{
public:

	void Add_Ward();
	void Del_Ward();
	void Rpt_Ward();
	void Search_Ward();
	void Edit_Ward();

	void menu2()
	{
		int choice = 0;
		cout << "                               *** Modiriat Bakhsh *** \n" << endl;

		cout << "Yeki Az Gozineh hay Zir Ra Entekhab konid - \n" << endl;
		cout << "[1] Afzodan Bakhsh -" << endl;
		cout << "[2] Hazf Bakhsh -" << endl;
		cout << "[3] Virayesh Bakhsh -" << endl;
		cout << "[4] Jostjo Bakhsh -" << endl;
		cout << "[5] List Bakhsh -" << endl;
		cout << "[0] Menu Asli - \n" << endl;
		cout << "Entekhab Shoma :- ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			system("CLS");
			Add_Ward();
			break;
		}
		case 2: {
			system("CLS");
			Del_Ward();
			break;
		}
		case 3: {
			system("CLS");
			Edit_Ward();
			break;
		}
		case 4: {
			system("CLS");
			Search_Ward();
			break;
		}
		case 5: {
			system("CLS");
			Rpt_Ward();
			break;
		}
		case 0: {
			system("CLS");
			MainMenu();
			break;
		}
		default:
			cout << "Gozeneh Entekhabi Eshtebast" << endl;
			break;
		}
	}
};
//
void menusWard::Add_Ward()
{
	char con;
	Ward b;
	b.CreateWard();
	cout << "Aya Mikhahid Bakhsh jadid Ezafe Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Add_Ward();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu2();
	}
}
//
void menusWard::Del_Ward()
{
	char con;
	Ward b;
	b.DeleteWard();
	cout << "Aya Mikhahid Bakhsh digari hazf Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Del_Ward();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu2();
	}
}
//
void menusWard::Rpt_Ward()
{
	char con;
	Ward b;
	b.ListWard();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu2();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusWard::Search_Ward()
{
	char con;
	Ward b;
	b.SearchWard();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu2();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusWard::Edit_Ward()
{
	char con;
	Ward b;
	b.EditWard();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu2();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}


#pragma endregion

#pragma region Employee

class menusEmp
{
public:

	void Add_Emp();
	void Del_Emp();
	void Rpt_Emp();
	void Search_Emp();
	void Edit_Emp();

	void menu3()
	{
		int choice = 0;
		cout << "                               *** Modiriat Karmandan *** \n" << endl;

		cout << "Yeki Az Gozineh hay Zir Ra Entekhab konid - \n" << endl;
		cout << "[1] Afzodan Karmand -" << endl;
		cout << "[2] Hazf Karmand -" << endl;
		cout << "[3] Virayesh Karmand -" << endl;
		cout << "[4] Jostjo Karmand -" << endl;
		cout << "[5] List Karmand -" << endl;
		cout << "[0] Menu Asli - \n" << endl;
		cout << "Entekhab Shoma :- ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			system("CLS");
			Add_Emp();
			break;
		}
		case 2: {
			system("CLS");
			Del_Emp();
			break;
		}
		case 3: {
			system("CLS");
			Edit_Emp();
			break;
		}
		case 4: {
			system("CLS");
			Search_Emp();
			break;
		}
		case 5: {
			system("CLS");
			Rpt_Emp();
			break;
		}
		case 0: {
			system("CLS");
			MainMenu();
			break;
		}
		default:
			cout << "Gozeneh Entekhabi Eshtebast" << endl;
			break;
		}
	}
};
//
void menusEmp::Add_Emp()
{
	char con;
	Employee b;
	b.CreateEmp();
	cout << "Aya Mikhahid Karmand jadid Ezafe Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Add_Emp();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu3();
	}
}
//
void menusEmp::Del_Emp()
{
	char con;
	Employee b;
	b.DeleteEmp();
	cout << "Aya Mikhahid Karmand digari hazf Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Del_Emp();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu3();
	}
}
//
void menusEmp::Rpt_Emp()
{
	char con;
	Employee b;
	b.ListEmp();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu3();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusEmp::Search_Emp()
{
	char con;
	Employee b;
	b.SearchEmp();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu3();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusEmp::Edit_Emp()
{
	char con;
	Employee b;
	b.EditEmp();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu3();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}


#pragma endregion

#pragma region Patient

class menusPat
{
public:

	void Add_Pat();
	void Del_Pat();
	void Rpt_Pat();
	void Search_Pat();
	void Edit_Pat();

	void menu4()
	{
		int choice = 0;
		cout << "                               *** Modiriat Bimaran *** \n" << endl;

		cout << "Yeki Az Gozineh hay Zir Ra Entekhab konid - \n" << endl;
		cout << "[1] Afzodan Bimar -" << endl;
		cout << "[2] Hazf Bimar -" << endl;
		cout << "[3] Virayesh Bimar -" << endl;
		cout << "[4] Jostjo Bimar -" << endl;
		cout << "[5] List Bimar -" << endl;
		cout << "[0] Menu Asli - \n" << endl;
		cout << "Entekhab Shoma :- ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			system("CLS");
			Add_Pat();
			break;
		}
		case 2: {
			system("CLS");
			Del_Pat();
			break;
		}
		case 3: {
			system("CLS");
			Edit_Pat();
			break;
		}
		case 4: {
			system("CLS");
			Search_Pat();
			break;
		}
		case 5: {
			system("CLS");
			Rpt_Pat();
			break;
		}
		case 0: {
			system("CLS");
			MainMenu();
			break;
		}
		default:
			cout << "Gozeneh Entekhabi Eshtebast" << endl;
			break;
		}
	}
};
//
void menusPat::Add_Pat()
{
	char con;
	Patient b;
	b.CreatePatient();
	cout << "Aya Mikhahid Bimar jadid Ezafe Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Add_Pat();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu4();
	}
}
//
void menusPat::Del_Pat()
{
	char con;
	Patient b;
	b.DeletePatient();
	cout << "Aya Mikhahid Bimar digari hazf Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Del_Pat();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu4();
	}
}
//
void menusPat::Rpt_Pat()
{
	char con;
	Patient b;
	b.ListPatient();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu4();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusPat::Search_Pat()
{
	char con;
	Patient b;
	b.SearchPatient();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu4();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusPat::Edit_Pat()
{
	char con;
	Patient b;
	b.EditPatient();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu4();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}


#pragma endregion

#pragma region Accounting

class menusAccount
{
public:

	void Add_Account();
	void Del_Account();
	void Rpt_Account();
	void Search_Account();
	void Edit_Account();

	void menu5()
	{
		int choice = 0;
		cout << "                               *** Tasvieh Hesab Bimaran *** \n" << endl;

		cout << "Yeki Az Gozineh hay Zir Ra Entekhab konid - \n" << endl;
		cout << "[1] Afzodan Tasvieh Hesab -" << endl;
		cout << "[2] Hazf Tasvieh Hesab -" << endl;
		cout << "[3] Virayesh Tasvieh Hesab -" << endl;
		cout << "[4] Jostjo Tasvieh Hesab -" << endl;
		cout << "[5] List Tasvieh Hesab -" << endl;
		cout << "[0] Menu Asli - \n" << endl;
		cout << "Entekhab Shoma :- ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			system("CLS");
			Add_Account();
			break;
		}
		case 2: {
			system("CLS");
			Del_Account();
			break;
		}
		case 3: {
			system("CLS");
			Edit_Account();
			break;
		}
		case 4: {
			system("CLS");
			Search_Account();
			break;
		}
		case 5: {
			system("CLS");
			Rpt_Account();
			break;
		}
		case 0: {
			system("CLS");
			MainMenu();
			break;
		}
		default:
			cout << "Gozeneh Entekhabi Eshtebast" << endl;
			break;
		}
	}
};
//
void menusAccount::Add_Account()
{
	char con;
	Accounting b;
	b.CreateAccounting();
	cout << "Aya Mikhahid Tasvieh jadid Ezafe Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Add_Account();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu5();
	}
}
//
void menusAccount::Del_Account()
{
	char con;
	Accounting b;
	b.DeleteAccounting();
	cout << "Aya Mikhahid Tasvieh digari hazf Konid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		Del_Account();
	}
	else if (con == 'n')
	{
		system("CLS");
		menu5();
	}
}
//
void menusAccount::Rpt_Account()
{
	char con;
	Accounting b;
	b.ListAccounting();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu5();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusAccount::Search_Account()
{
	char con;
	Accounting b;
	b.SearchAccounting();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu5();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}
//
void menusAccount::Edit_Account()
{
	char con;
	Accounting b;
	b.EditAccounting();
	cout << "Aya Mikhahid Be Menu Ghabl Bargardid? (y/n)";
	cin >> con;
	if (con == 'y')
	{
		system("CLS");
		menu5();
	}
	else if (con == 'n')
	{
		system("CLS");
		MainMenu();
	}
}


#pragma endregion
//============================================================


void MainMenu()
{
	int c;

	cout << "                               *** System Modiriat Bimarstan *** \n" << endl;
	cout << "Yeki Az Gozineh hay Zir Ra Entekhab konid - \n" << endl;
	cout << "[1] Modiriat Bimarstan -" << endl;
	cout << "[2] Modiriat Bakhsh -" << endl;
	cout << "[3] Modiriat Karmandan -" << endl;
	cout << "[4] Modiriat Bimar -" << endl;
	cout << "[5] Hesabdari -" << endl;
	cout << "[0] Khoroj - \n" << endl;
	cout << "Entekhab Shoma :- ";
	cin >> c;
	switch (c)
	{
	case 1:
		system("CLS");
		menusHospital m;
		m.menu1();
		break;

	case 2:
		system("CLS");
		menusWard w;
		w.menu2();
		break;

	case 3:
		system("CLS");
		menusEmp e;
		e.menu3();
		break;

	case 4:
		system("CLS");
		menusPat p;
		p.menu4();
		break;

	case 5:
		system("CLS");
		menusAccount a;
		a.menu5();
		break;

	case 0:
		exit(0);
		break;

	default:
		cout << "Gozeneh Entekhabi Eshtebast" << endl;
		break;
	}
}


int main()
{
	MainMenu();
	_getch();
	return 0;
}


