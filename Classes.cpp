#include "classes.h"

namespace MyNameSpace
{

	void Patient::SetPeople()
	{
		cout << "<<< ���� ���������� ������������>>>\n\n";
		ChangeCount();
		this->id = Count;
		cout << "������� ��� ��������: ";
		cin >> name;
		this->name = name;
		cout << "������� ������� ��������: ";
		cin >> surname;
		this->surname = surname;
		cout << "������� �������� ��������: ";
		cin >> patronymic;
		this->patronymic = patronymic;
		cout << "������� ��� �������� ��������: ";

		while (!(cin >> year_of_birth) || year_of_birth < 1900 || year_of_birth > 2020)
		{
			MessageBox(NULL, L"������� �������� ��������! ���������� �����!", L"������!", MB_OK);
			cin.clear();
			cin.ignore(32767, '\n');
		}
		this->year_of_birth = year_of_birth;

		cout << "������� ����� ����������: ";
		cin.clear();
		cin.ignore(32767, '\n');
		getline(cin, adress);
		for  (unsigned int i = 0; i < adress.length(); i++)
		{
			if (adress[i] == ' ')
				adress[i] = '`';
		}
		this->adress = adress;
	}

	void Patient::SetUser()
	{
		cout << "<<< ���� ���������� ������������>>>\n\n";
		cout << "������� ����� ������������: (10 ��������)\n";
		cin >> loginU;
		while (loginU.length() < 5)
		{
			MessageBox(NULL, L"����� �� ������������� �����������! ���������� �����!", L"������!", MB_OK);
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������� �����: (10 ��������)\n";
			cin >> loginU;
		}
		for (unsigned int i = 0; i < loginU.length() - 1; i++) {

			loginU[i] = (loginU[i] - (char)'y') % 256;
		}
		this->loginU = loginU;


		cout << "������� ������ ������������: (10 ��������)\n";
		cin >> passwordU;
		while (passwordU.length() < 5)
		{
			MessageBox(NULL, L"������ �� ������������� �����������! ���������� �����!", L"������!", MB_OK);
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������� ������: (10 ��������)\n";
			cin >> passwordU;
		}
		for (unsigned int i = 0; i < passwordU.length() - 1; i++) {

			passwordU[i] = (passwordU[i] - (char)'y') % 256;
		}
		this->passwordU = passwordU;
	};

	void Patient::PrintPeople()
	{
		cout << "|" << setw(5) << this->id << "|" 
			<< setw(20) << this->surname <<  "|" 
			<< setw(20) << this->name <<  "|"
			<< setw(20) << this->patronymic  << "|"
			<< setw(20) << this->year_of_birth  << "|"
			<< setw(40) << this->adress << "|" << endl;
		cout << "�����������������������������������������������������������������������������������������������������������������������������������\n";
	}

	void Patient::ChangeCount()
	{
		Count++;
	}

	void Patient::SetCount(int value)
	{
		Count = value;
	}
	int Patient::Count = 0;

	int Patient::Get_id()
	{
		return this->id;
	}

	void Patient::Set_id(int id)
	{
		this->id = id;
	}

	string Patient::Get_name()
	{
		return this->name;
	}

	void Patient::Set_name(string name)
	{
		this->name = name;
	}

	string Patient::Get_surname()
	{
		return this->surname;
	}

	void Patient::Set_surname(string surname)
	{
		this->surname = surname;
	}

	string Patient::Get_patronymic()
	{
		return this->patronymic;
	}

	void Patient::Set_patronymic(string patronymic)
	{
		this->patronymic = patronymic;
	}

	int Patient::Get_year_of_birth()
	{
		return this->year_of_birth;
	}

	void Patient::Set_year_of_birth(int year_of_birth)
	{
		this->year_of_birth = year_of_birth;
	}

	string Patient::Get_adress()
	{
		return this->adress;
	}

	void Patient::Set_adress(string adress)
	{
		for (unsigned int i = 0; i < adress.length(); i++)
		{
			if (adress[i] == ' ')
				adress[i] = '`';
		}
		this->adress = adress;
	}

	string Patient::Get_loginU()
	{
		return this->loginU;
	}

	string Patient::Get_passwordU()
	{
		return this->passwordU;
	}

	void Patient::TransformationAdress()
	{
		for (unsigned int i = 0; i < this->adress.length(); i++)
		{
			if (this->adress[i] == '`')
				this->adress[i] = ' ';
		}
	}
	void Patient::TransformationAdressPrime()
	{
		for (unsigned int i = 0; i < this->adress.length(); i++)
		{
			if (this->adress[i] == ' ')
				this->adress[i] = '`';
		}
	}

	void Patient::WriteFile(string path)
	{
		fstream fs;
		fs.open(path, fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Error!" << endl;
		}
		else
		{
			for (unsigned int i = 0; i < this->adress.length(); i++)
			{
				if (this->adress[i] == ' ')
					this->adress[i] = '`';
			}
			fs << *this;
		}
		fs.close();
	}

	void Administrator::SetUser()
	{
		cout << "<<< ���� ���������� ������������>>>\n\n";
		cout << "������� ��� ��������������: ";
		cin >> nameA;
		this->nameA = nameA;
		cout << "������� �����: (10 ��������)\n";
		cin >> loginA;
		while (loginA.length() < 10)
		{
			MessageBox(NULL, L"����� �� ������������� �����������! ���������� �����!", L"������!", MB_OK);
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������� �����: (10 ��������)\n";
			cin >> loginA;
		}
		for (unsigned int i = 0; i < loginA.length() - 1; i++) {

			loginA[i] = (loginA[i] - (char)'y') % 256;
		}
		this->loginA = loginA;


		cout << "������� ������: (10 ��������)\n";
		cin >> passwordA;
		while (passwordA.length() < 10)
		{
			MessageBox(NULL, L"������ �� ������������� �����������! ���������� �����!", L"������!", MB_OK);
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "������� ������: (10 ��������)\n";
			cin >> passwordA;
		}
		for (unsigned int i = 0; i < passwordA.length() - 1; i++) {

			passwordA[i] = (passwordA[i] - (char)'y') % 256;
		}
		this->passwordA = passwordA;
	}

	void Administrator::WriteFile(string path)
	{
		fstream fs;
		fs.open(path, fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Error!" << endl;
		}
		else
		{
			fs << *this;
		}
		fs.close();
	}

	void Administrator::ReadFile(string path, Administrator &ad, deque<Administrator> &dq_ad)
	{
		fstream fs;

		fs.open(path, fstream::in | fstream::out | ios::app);

		if (!fs.is_open())
		{
			cout << "Error!" << endl;
		}
		else if (fs.peek() == EOF)
			cout << "-" << endl;
		else
		{
			while (!fs.eof())
			{
				fs >> ad;
				dq_ad.push_back(ad);
			}
		}
		fs.close();
	}

	void Administrator::PrintPeople()
	{
		cout << this->nameA << endl;
	}

	string Administrator::Get_nameA()
	{
		return this->nameA;
	}

	void Doctor::SetCnt(int value)
	{
		cnt = value;
	}
	void Doctor::ChangeCnt()
	{
		cnt++;
	}

	int Doctor::cnt = 0;

	void Doctor::SetUser()
	{
		cout << "<<< ���� ���������� �����>>>\n\n";
		ChangeCnt();
		this->id = cnt;
		cout << "������� ��� �����: ";
		cin >> name;
		this->name = name;
		cout << "������� ������� �����: ";
		cin >> surname;
		this->surname = surname;
		cout << "������� �������� �����: ";
		cin >> patronymic;
		this->patronymic = patronymic;
		cout << "������� ������������� �����: ";
		cin >> specialization;
		this->specialization = specialization;
	}

	void Doctor::WriteFile(string path)
	{
		fstream fs;
		fs.open(path, fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Error!" << endl;
		}
		else
		{
			fs << *this;
		}
		fs.close();
	}

	int Doctor::Get_ID()
	{
		return this->id;
	}

	void Doctor::PrintPeople()
	{
		cout << this->id << " " << this->surname << " " << this->name << " " << this->patronymic << endl;
	}

	string Doctor::Get_name()
	{
		return this->name;
	}

	string Doctor::Get_surname()
	{
		return this->surname;
	}

	string Doctor::Get_patronymic()
	{
		return this->patronymic;
	}

	string Doctor::Get_specialization()
	{
		return this->specialization;
	}

	template<class T>
	T Date<T>::Get_month()
	{
		return this->month;
	}

	template<class T>
	void Date<T>::Set_month(T month)
	{
		this->month = month;
	}

	template<class T>
	T Date<T>::Get_day()
	{
		return this->day;
	}

	template<class T>
	void Date<T>::Set_day(T day)
	{
		this->day = day;
	}

	template<class T>
	string Date<T>::Get_time()
	{
		return this->time;
	}

	template<class T>
	void Date<T>::Set_time(string time)
	{
		this->time = time;
	}

	template<class T>
	void Date<T>::SetDate()
	{
		SYSTEMTIME st;
		GetSystemTime(&st);
		int flag = 0;
		cout << "������������������������������������������������" << endl;
		for (unsigned int i = 0; i < 14;)
		{
			if (i == 7)
			{
				cout << endl;
				cout << "������������������������������������������������" << endl;
			}
			if (st.wMonth == 4 || st.wMonth == 6 || st.wMonth == 9 || st.wMonth == 11)
				cout << "|" << setw(2) << (st.wDay + i) % 30 + 1 << "." << setw(2) << st.wMonth << "|";
			else if (st.wMonth == 2)
				cout << "|" << setw(2) << (st.wDay + i) % 28 + 1 << "." << setw(2) << st.wMonth << "|";
			else
				cout << "|" << setw(2) << (st.wDay + i) % 31 + 1 << "." << setw(2) << st.wMonth << "|";
			i++;
			if ((((st.wDay + i > 30) && (st.wMonth == 4 || st.wMonth == 6 || st.wMonth == 9 || st.wMonth == 11)) ||
				((st.wDay + i > 31) && (st.wMonth == 1 || st.wMonth == 3 || st.wMonth == 5 || st.wMonth == 7 || st.wMonth == 10 || st.wMonth == 12 || st.wMonth == 8)) ||
				((st.wDay + i > 28) && (st.wMonth == 2))) && flag == 0)
			{
				st.wMonth += 1;
				flag = 1;
			}
		}
		cout << endl << "������������������������������������������������" << endl;


		int vis;
		cout << "\t������� ���� ������: " << endl;

		if (st.wYear % 4 == 0)
		{
			if (st.wYear % 100 == 0)
			{
				if (st.wYear % 400 == 0)
				{
					vis = 1;

				}
			}
			else
			{
				vis = 1;
			}
		}
		else
		{
			vis = 0;
		}

		cout << "������� �����: " << endl;
		while (!(cin >> month) || (month > 12 || month < 1)) {
			MessageBox(NULL, L"������� �������� ��������! ���������� �����!", L"������!", MB_OK);
			cin.clear();
			cin.ignore(32767, '\n');
		}
		this->month = month;

		cout << "������� ����: " << endl;
		switch (this->month) {

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: {

			while (!(cin >> day) || (day > 31 || day < 1)) {
				MessageBox(NULL, L"������� �������� ��������! ���������� �����!", L"������!", MB_OK);
				cin.clear();
				cin.ignore(32767, '\n');
			}
			break;
		}
		case 2: {

			if (vis == 1)
			{
				while (!(cin >> day) || (day > 29 || day < 1)) {
					MessageBox(NULL, L"������� �������� ��������! ���������� �����!", L"������!", MB_OK);
					cin.clear();
					cin.ignore(32767, '\n');
				}
			}
			else
			{
				while (!(cin >> day) || (day > 28 || day < 1)) {
					MessageBox(NULL, L"������� �������� ��������! ���������� �����!", L"������!", MB_OK);
					cin.clear();
					cin.ignore(32767, '\n');
				}
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			while (!(cin >> day) || (day > 30 || day < 1)) {
				MessageBox(NULL, L"������� �������� ��������! ���������� �����!", L"������!", MB_OK);
				cin.clear();
				cin.ignore(32767, '\n');
			}
			break;
		}
		}
		this->day = day;

		int var;
		vector<string> tm = {"9:00", "9:30", "10:00", "10:30", "11:00", "11:30", "12:30", "13:00", "13:30", "14:00", "14:30", "15:00"};
		for (unsigned int i = 0, ch = 1; i < tm.size(); i++)
		{
			cout << ch << " - " << tm[i] << endl;
			ch++;
		}
		cout << "�������� ����� ������: ";
		while (!(cin >> var) || (var > 12 || var < 1)) {
			MessageBox(NULL, L"������� �������� ��������! ���������� �����!", L"������!", MB_OK);
			cin.clear();
			cin.ignore(32767, '\n');
		}
		this->time = tm[var - 1];
	};

	void Ticket::SetTicket()
	{	
		int choice_of_specialty, specialist;
		vector<Doctor> doct;
		Doctor DCT;

		fstream fs;
		fs.open("doc.txt", fstream::in | fstream::out | ios::app);

		if (!fs.is_open())
		{
			cout << "Error!" << endl;
		}
		else if (fs.peek() == EOF)
		{
			Doctor::SetCnt(0);
		}
		else
		{
			while (!fs.eof())
			{
				fs >> DCT;
				doct.push_back(DCT);
				Doctor::SetCnt(DCT.Get_ID());
			}
		}
		fs.close();

		vector<string> amount_spec = {"��������",
				"������",
				"�����������",
				"������",
				"������-���������",
				"���� ����� ��������(�������� ����)",
				"�����������������", "����������-��������", "����������-������", "��������" };

		while(true) 
		{
			cout << "1.��������\n"
				"2.������\n"
				"3.�����������\n"
				"4.������\n"
				"5.������-���������\n"
				"6.���� ����� ��������(�������� ����)\n"
				"7.�����������������\n"
				"8.����������-��������\n"
				"9.����������-������\n"
				"10.��������" << endl;
			cout << "������� ������������� �����: ";
			check(choice_of_specialty);
			if (choice_of_specialty > 10 || choice_of_specialty < 1)
				Warning();
			else
				break;
		}
		system("cls");

		while (true)
		{
			cout << "�� ������ ������� ����������� �����������?" << endl;
			cout << "1 - �� | 2 - ���" << endl;
			int choice;
			check(choice);
			if (choice == 1)
			{
				cout << "�������� ����������� �����������: " << endl;
				for (unsigned int i = 0; i < doct.size(); i++)
				{
					if (amount_spec[choice_of_specialty - 1] == doct.at(i).Get_specialization())
						doct.at(i).PrintPeople();
				}
				cout << "������� Id ���������� �����������";
				check(specialist);
				if (specialist < 1)
				{
					Warning(); continue;
				}
				else
				{
					for (unsigned int i = 0; i < doct.size(); i++)
					{
						if (specialist == doct.at(i).Get_ID())
						{
							this->spec = doct.at(i).Get_specialization();
							this->doctor = doct.at(i).Get_surname() + doct.at(i).Get_name() + doct.at(i).Get_patronymic();
						}
					}
					break;
				}
			}
			/*else if (choice == 2)
			{
				this->doctor = doct[];
				break;
			}*/
			else
				Warning();
		}
		system("cls");

		this->cabinet = rand()%1000 + 101;
		this->date.SetDate();
		system("cls");
		cout << "��� �����: \n\n";
		this->PrintTicket();
	}

	int Ticket::Get_cabinet()
	{
		return this->cabinet;
	}

	void Ticket::Set_cabinet(int cabinet)
	{
		this->cabinet = cabinet;
	}

	string Ticket::Get_doctor()
	{
		return this->doctor;
	}

	string Ticket::Get_spec()
	{
		return this->spec;
	}

	void Ticket::WriteFile(string path)
	{
		fstream fs;
		fs.open(path, fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Error!" << endl;
		}
		else
		{
			for (unsigned int i = 0; i < this->doctor.length(); i++)
			{
				if (this->doctor[i] == ' ')
					this->doctor[i] = '`';
			}
			fs << *this;
		}

		fs.close();
	}

	void Ticket::Change_str()
	{
		for (unsigned int i = 0; i < this->doctor.length(); i++)
		{
			if (this->doctor[i] == '`')
				this->doctor[i] = ' ';
		}
	}

	void Ticket::PrintTicket()
	{
		cout << "\n���� - " << this->Get_spec() << " - "
			<< this->Get_doctor() << "; ������� - "
			<< this->Get_cabinet() << "; ���� - "
			<< this->date.Get_day() << "."
			<< this->date.Get_month() << "; ����� - |"
			<< this->date.Get_time() << "|;" << endl;
	}

	void Medical_card::SetCard()
	{
		this->patient.SetUser();
		system("cls");
		this->patient.SetPeople();
	}

	void Medical_card::PrintCard()
	{
		this->patient.PrintPeople();
	}

	void Medical_card::PrintCard(int condition)
	{
		if (condition == 0)
		{
			cout << "������������������������������������������������������������������������������������������������������������������������������������\n";
			cout << "| id  |      �������       |         ���        |      ��������      |    ��� ��������    |                  �����                 |\n";
			cout << "������������������������������������������������������������������������������������������������������������������������������������\n";
		}
		this->patient.PrintPeople();
	};

	void Medical_card::WriteFile(string path)
	{
		fstream fs;
		fs.open(path, fstream::in | fstream::out | fstream::app);

		if (!fs.is_open())
		{
			cout << "Error!" << endl;
		}
		else
		{
			this->patient.TransformationAdressPrime();
			fs << *this;
		}

		fs.close();
	}

	void Medical_card::Change()
	{
		this->patient.TransformationAdress();
	}

	Patient Medical_card::Get_patient()
	{
		return this->patient;
	}

	ostream& operator<<(ostream& os, Medical_card& point)
	{
		os << "\n" << point.patient.Get_id() << " "
			<< point.patient.Get_name() << " "
			<< point.patient.Get_surname() << " "
			<< point.patient.Get_patronymic() << " "
			<< point.patient.Get_year_of_birth() << " "
			<< point.patient.Get_adress();
		return os;
	}
	istream& operator>>(istream& is, Medical_card& point)
	{
		int a, b;
		string A, B, C, D;
		is >> a;
		point.patient.Set_id(a);
		is >> A;
		point.patient.Set_name(A);
		is >> B;
		point.patient.Set_surname(B);
		is >> C;
		point.patient.Set_patronymic(C);
		is >> b;
		point.patient.Set_year_of_birth(b);
		is >> D;
		point.patient.Set_adress(D);
		return is;
	}

	ostream & operator<<(ostream& os, const Doctor& point)
	{
		os << "\n" << point.id << " " << point.surname << " " << point.name << " " << point.patronymic << " " << point.specialization;
		return os;
	}
	istream & operator>>(istream& is, Doctor& point)
	{
		is >> point.id;
		is >> point.surname;
		is >> point.name;
		is >> point.patronymic;
		is >> point.specialization;
		return is;
	}

	ostream& operator<<(ostream& os, const Administrator& point)
	{
		os << "\n" << point.nameA << " " << point.loginA << " " << point.passwordA;
		return os;
	}
	istream& operator>>(istream& is, Administrator& point)
	{
		is >> point.nameA;
		is >> point.loginA;
		is >> point.passwordA;
		return is;
	}

	ostream& operator<<(ostream& os, const Patient& point)
	{
		os << "\n" << point.loginU << " " << point.passwordU;
		return os;
	}
	istream& operator>>(istream& is, Patient& point)
	{
		is >> point.loginU;
		is >> point.passwordU;
		return is;
	}

	ostream& operator<<(ostream& os, Ticket& point)
	{
		os << "\n" << point.spec << " "
			<< point.doctor << " "
			<< point.cabinet << " "
			<< point.date.Get_month() << " "
			<< point.date.Get_day() << " "
			<< point.date.Get_time();
		return os;
	}
	istream& operator>>(istream& is, Ticket& point)
	{
		string c;
		int A, B;
		is >> point.spec;
		is >> point.doctor;
		is >> point.cabinet;
		is >> A;
		point.date.Set_month(A);
		is >> B;
		point.date.Set_day(B);
		is >> c;
		point.date.Set_time(c);
		return is;
	}

	void menu_pol()
	{
		cout << "�������� ��������\n";
		cout << "1 - ������������������\n";
		cout << "2 - ��������������\n";
		cout << "0 - ��������� � ���������� ����\n";
	}

	void menu_del() {
		cout << "<<< ���� ��������>>>\n\n";
		printf("1. ������� �� ���������\n"
			"2. ������� ���\n"
			"0. ������");
		printf("��� ����� ~>\n");
	}

	void menu_rec()
	{

		cout << "�������� ��������\n";
		cout << "1 - �������� ����������� ���� �������������\n";
		cout << "2 - ���������� ������ ������������\n";
		cout << "3 - ����� ������������ �� ��������� ���������\n";
		cout << "4 - �������� ������������\n";
		cout << "5 - ��������� ���������� �������������\n";
		cout << "6 - ���������� ������� ������� ����������� � ���������� �������\n";
		cout << "7 - ���������� ������������� �� ���� ��������\n";
		cout << "8 - �������������� ������� ������ �����������\n\n";
		cout << "9 - ���������� ����������������\n";
		cout << "10 - ������ �� ������� ������\n";
		cout << "0 - ��������� � ���������� ����\n";

	}

	void Warning()
	{
		MessageBox(NULL, L"������� ������������ ��������! ���������� �����!", L"������!", MB_OK);
		cin.clear();
		cin.ignore(32767, '\n');
	}

	void begin()
	{
		printf("<<<<< ��� ������������ ��������� CLIENTS ! >>>>>\n\n");
		printf("\t�������� ��������\n\n");
		printf("1 - ���� � �������� ��������������\n");
		printf("2 - ���� � �������� ������������\n");
		printf("0 - �����\n");
	}

	void filter(deque<Medical_card> p) {
		system("cls");

		int A, B, flag = 0;
		printf("<<< ���������� �� ���� �������� ��������� >>>\n");
		printf("������� �������� �� ������ ���� ������ ���������\n");
		check(A);
		printf("������� �������� �� ������ ���� ������ ���������\n");
		check(B);
		for (int i = 0; i != p.size(); i++)
		{
			if (p.at(i).patient.Get_year_of_birth() >= A && p.at(i).patient.Get_year_of_birth() <= B) {
				p.at(i).PrintCard();
				flag = 1;
			}
		}
		if (flag == 0)
			cout << "��� �������� � ����� ����� ��������!" << endl;
	}

	void edit(deque<Medical_card> &p, int var)
	{
		int variable, flag = 0;
		string find_parameter;
		int int_find_parameter, select_id, have_ticket = 0;
		Ticket tick;

		if (var == 0)
		{
			for (int i = 0; i != p.size(); i++)
			{
				p.at(i).PrintCard(i);
			}
			cout << "������� id ������, ������� ������ �������������: " << endl;
			check(select_id);
		}
		else 
		{
			select_id = var;
		}
		system("cls");

		for (int i = 0; i != p.size(); i++)
		{
			if (p.at(i).patient.Get_id() == select_id)
			{
				fstream ful, fl;
				string ph = p.at(i).Get_patient().Get_surname() + "_" + p.at(i).Get_patient().Get_name();
				ful.open(ph + "\\info.txt", fstream::in | fstream::out | fstream::app);

				if (!ful.is_open())
				{
					cout << "Error!" << endl;
				}
				else
				{
					ful >> p.at(i).patient;
					for (unsigned int j = 0; j < p.at(i).patient.Get_loginU().length() - 1; j++) {

						p.at(i).patient.Get_loginU()[j] = (p.at(i).patient.Get_loginU()[j] + (char)'y') % 256;
					}
					for (unsigned int j = 0; j < p.at(i).patient.Get_passwordU().length() - 1; j++) {

						p.at(i).patient.Get_passwordU()[j] = (p.at(i).patient.Get_passwordU()[j] + (char)'y') % 256;
					}
				}
				ful.close();

				fl.open(ph + "\\tickets.txt", fstream::in | fstream::out | fstream::app);
				if (!fl.is_open())
				{
					have_ticket = -1;
				}
				else
				{
					fl >> tick;
				}
				fl.close();

				destruction(p, i);
				flag = 1;
				cout << "����� �������� �� ������ ���������������: \n";
				cout << "1.�������\n";
				cout << "2.���\n";
				cout << "3.��������\n";
				cout << "4.��� ��������\n";
				cout << "5.�����\n";
				cout << "��� ����� ~> ";
				check(variable);

				switch (variable)
				{
				case 1:
				{
					cout << "������� �������: ";
					cin >> find_parameter;
					p.at(i).patient.Set_surname(find_parameter);
					break;
				}
				case 2:
				{
					cout << "������� ���: ";
					cin >> find_parameter;
					p.at(i).patient.Set_name(find_parameter);
					break;
				}
				case 3:
				{
					cout << "������� ��������: ";
					cin >> find_parameter;
					p.at(i).patient.Set_patronymic(find_parameter);
					break;
				}
				case 4:
				{
					cout << "������� ��� ��������: ";
					cin >> int_find_parameter;
					p.at(i).patient.Set_year_of_birth(int_find_parameter);
					break;
				}
				case 5:
				{
					cout << "������� ������: ";
					cin >> find_parameter;
					p.at(i).patient.Set_adress(find_parameter);
					break;
				}
				default:
				{
					Warning();
					break;
				}
				}

				string name = p.at(i).Get_patient().Get_surname() + "_" + p.at(i).Get_patient().Get_name();
				const char *cname = name.c_str();
				if (_mkdir(cname) == -1)
				{
					cout << "������ ������������ ��� ����������!" << endl;
					break;
				};
				p.at(i).PrintCard();
				p.at(i).patient.WriteFile(name + "\\info.txt");
				p.at(i).WriteFile(name + "\\param.txt");
				if(have_ticket != -1)
					tick.WriteFile(name + "\\tickets.txt");
			}
		}
		
		cout << "�������������� ���������!" << endl;
		if(flag == 0)
			cout << "������� � ������ ���������� �� ����������!" << endl;
		else
		{
			remove("path.txt");
			for (unsigned int j = 0; j < p.size(); j++)
			{
				p.at(j).WriteFile("path.txt");
			}
		}
	}

	void destruction(deque<Medical_card> &p, int i)
	{
		string name = p.at(i).Get_patient().Get_surname() + "_" + p.at(i).Get_patient().Get_name();
		const char *cname = name.c_str();
		string nameI = p.at(i).Get_patient().Get_surname() + "_" + p.at(i).Get_patient().Get_name() + "\\info.txt";
		const char *cnameI = nameI.c_str();
		string nameP = p.at(i).Get_patient().Get_surname() + "_" + p.at(i).Get_patient().Get_name() + "\\param.txt";
		const char *cnameP = nameP.c_str();
		string nameT = p.at(i).Get_patient().Get_surname() + "_" + p.at(i).Get_patient().Get_name() + "\\tickets.txt";
		const char *cnameT = nameT.c_str();
		remove(cnameI); remove(cnameP); remove(cnameT);
		_rmdir(cname);
	}

	void sort(deque<Medical_card> &p)
	{
		for (unsigned int i = 0; i < p.size(); i++) 
		{
			for (unsigned int j = i + 1; j < p.size(); j++)
			{
				if (p.at(i).patient.Get_patronymic() > p.at(j).patient.Get_patronymic()) {
					Patient tmp = p.at(i).patient;
					p.at(i).patient = p.at(j).patient;
					p.at(j).patient = tmp;
				}
				if (p.at(i).patient.Get_name() > p.at(j).patient.Get_name()) {
					Patient tmp = p.at(i).patient;
					p.at(i).patient = p.at(j).patient;
					p.at(j).patient = tmp;
				}
				if (p.at(i).patient.Get_surname() > p.at(j).patient.Get_surname()) {
					Patient tmp = p.at(i).patient;
					p.at(i).patient = p.at(j).patient;
					p.at(j).patient = tmp;
				}
			}
		}
	}

	int menu_admin(deque<Administrator> p) {

		system("cls");
		cout << "<<< ���� >>>\n\n";

		string path = "adm.txt";
		fstream ful;
		ful.open(path, fstream::in | fstream::out | fstream::app);
		string pas, log, name;
		char a[3];

		Administrator A;

		if (!ful.is_open())
		{
			cout << "Error!" << endl;
		}
		else
		{
			while (!ful.eof())
			{
				ful >> A;
				for (unsigned int i = 0; i < A.loginA.length() - 1; i++) {

					A.loginA[i] = (A.loginA[i] + (char)'y') % 256;
				}
				for (unsigned int i = 0; i < A.passwordA.length() - 1; i++) {

					A.passwordA[i] = (A.passwordA[i] + (char)'y') % 256;
				}
				p.push_back(A);
			}
		}
		ful.close();

		cout << "������� ��� ��������������:\n";
		cin >> name;

		int i = 0;
		while (name != p.at(i).nameA) {
			i++;
			if (i == p.size())
			{
				a[2] = MessageBox(NULL, L"�������������� �� ����������!", L"������!", MB_RETRYCANCEL);
				if (a[2] == IDRETRY) {
					i = 0;
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "������� ��� ��������������:\n";
					cin >> name;
				}
				else
					return 0;
			}
		}

		cout << "������� �����\n";
		cin >> log;

		while (log != p.at(i).loginA)
		{
			a[0] = MessageBox(NULL, L"�������� �����! ���������� �����!", L"������!", MB_RETRYCANCEL);
			if (a[0] == IDRETRY) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������� �����\n";
				cin >> log;
			}
			else
				return 0;
		}

		cout << "������� ������\n";
		cin >> pas;

		while (pas != p.at(i).passwordA)
		{
			a[1] = MessageBox(NULL, L"�������� ������! ���������� �����!", L"������!", MB_RETRYCANCEL);
			if (a[1] == IDRETRY) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������� ������\n";
				cin >> pas;
			}
			else
				return 0;
		}
		return 1;
	}

	void Search(deque<Medical_card> p)
	{
		int variable, flag = 0;
		string find_parameter;
		cout << "�� ������ ��������� �� ������ ����������� �����: \n";
		cout << "1.�������\n";
		cout << "2.���\n";
		cout << "3.��������\n";
		cout << "��� ����� ~> ";
		check(variable);
		system("cls");

		switch (variable)
		{
		case 1:
		{
			cout << "������� �������: ";
			cin >> find_parameter;
			for (int i = 0; i != p.size(); i++)
			{
				if (p.at(i).Get_patient().Get_surname() == find_parameter)
				{
					p.at(i).PrintCard();
					flag = 1;
				}
			}
			break;
		}
		case 2:
		{
			cout << "������� ���: ";
			cin >> find_parameter;
			for (int i = 0; i != p.size(); i++)
			{
				if (p.at(i).Get_patient().Get_name() == find_parameter)
				{
					p.at(i).PrintCard();
					flag = 1;
				}
			}
			break;
		}
		case 3:
		{
			cout << "������� ��������: ";
			cin >> find_parameter;
			for (int i = 0; i != p.size(); i++)
			{
				if (p.at(i).Get_patient().Get_patronymic() == find_parameter)
				{
					p.at(i).PrintCard();
					flag = 1;
				}
			}
			break;
		}
		default:
		{
			Warning();
			break;
		}
		}
		if (flag == 0)
			cout << "������� � ������ ���������� �� ����������!" << endl;
	}

	int User_Info(Patient A, string path) {

		system("cls");
		cout << "<<< ���� >>>\n\n";

		fstream ful;
		ful.open(path, fstream::in | fstream::out | fstream::app);
		string pas, log, name;
		char a[3];

		if (!ful.is_open())
		{
			cout << "Error!" << endl;
		}
		else
		{
			ful >> A;
			for (unsigned int i = 0; i < A.loginU.length() - 1; i++) {

				A.loginU[i] = (A.loginU[i] + (char)'y') % 256;
			}
			for (unsigned int i = 0; i < A.passwordU.length() - 1; i++) {

				A.passwordU[i] = (A.passwordU[i] + (char)'y') % 256;
			}
		}
		ful.close();

		cout << "������� �����\n";
		cin >> log;

		while (log != A.loginU)
		{
			a[0] = MessageBox(NULL, L"�������� �����! ���������� �����!", L"������!", MB_RETRYCANCEL);
			if (a[0] == IDRETRY) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������� �����\n";
				cin >> log;
			}
			else
				return 0;
		}


		cout << "������� ������\n";
		cin >> pas;

		while (pas != A.passwordU)
		{
			a[1] = MessageBox(NULL, L"�������� ������! ���������� �����!", L"������!", MB_RETRYCANCEL);
			if (a[1] == IDRETRY) {
				cin.clear();
				cin.ignore(32767, '\n');
				cout << "������� ������\n";
				cin >> pas;
			}
			else
				return 0;
		}
		return 1;
	}
}