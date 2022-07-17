#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>
#include <deque>
#include <vector>
#include <direct.h>
using namespace std;

namespace MyNameSpace  //Использование пространства имен
{
	template<class T>   //Шаблонный класс
	class Date
	{
	public:
		Date()
		{
			SYSTEMTIME st;
			GetSystemTime(&st);
			this->day = st.wDay;
			this->month = st.wMonth;
		};

		Date(T day, T month)
		{
			this->day = day;
			this->month = month;
		};

		~Date() {};

		void SetDate();
		T Get_month();  //Шаблонный метод
		void Set_month(T);
		T Get_day();
		void Set_day(T);
		string Get_time();
		void Set_time(string);

	private:
		T day, month;
		string time;
	};

	class Men   //Абстрактный класс
	{
	public:
		Men() {};
		virtual ~Men() {};

		virtual void SetPeople() = 0;      //Чисто виртуальные методы
		virtual void PrintPeople() = 0;
		virtual void WriteFile(string) = 0;

	};

	class Patient : public virtual Men
	{
	public:
		Patient() 
		{ 
			this->id = 0;
		};
		~Patient() {};

		void SetPeople() override;
		void SetUser();
		void PrintPeople() override;
		void WriteFile(string) override;
		void TransformationAdress();
		void TransformationAdressPrime();
		static void ChangeCount();
		static void SetCount(int);
		int Get_id();
		void Set_id(int);
		string Get_name();
		void Set_name(string);
		string Get_surname();
		void Set_surname(string);
		string Get_patronymic();
		void Set_patronymic(string);
		int Get_year_of_birth();
		void Set_year_of_birth(int);
		string Get_adress();
		void Set_adress(string);
		string Get_loginU();
		string Get_passwordU();

	private:
		int id;
		string name;
		string surname;
		string patronymic;
		string adress;
		int year_of_birth;
		string loginU;
		string passwordU;
		static int Count;

		friend ostream& operator<<(ostream& os, const Patient& point);
		friend istream& operator>>(istream& is, Patient& point);
		friend int User_Info(Patient A, string path);
	};

	class Doctor : public virtual Men
	{
	public:
		void SetPeople() override ;
		void WriteFile(string) override;
		int Get_ID();
		void PrintPeople() override;
		string Get_name();
		void Set_name(string);
		string Get_surname();
		void Set_surname(string);
		string Get_patronymic();
		void Set_patronymic(string);
		string Get_specialization();
		void Set_specialization(string);
		static void SetCnt(int);  //статические методы
		static void ChangeCnt();
	private:						//Сокрытие данных
		string name;
		string surname;
		string patronymic;
		string specialization;
		int id;
		static int cnt;   //статическое поле

		friend ostream& operator<<(ostream& os, const Doctor& point);   //Дружественные функции
		friend istream& operator>>(istream& is, Doctor& point);
	};

	class Administrator : public virtual Men
	{
	public:
		Administrator() {};
		~Administrator() {};

		void SetUser();
		void SetPeople() override;   
		void WriteFile(string) override;
		void ReadFile(string, Administrator&, deque<Administrator>&);
		void PrintPeople() override;
		string Get_nameA();

	private:
		string nameA;
		string loginA;
		string passwordA;
		friend ostream& operator<<(ostream& os, const Administrator& point);
		friend istream& operator>>(istream& is, Administrator& point);
		friend int menu_admin(deque<Administrator> p);
	};

	class Ticket
	{
	public:
		Ticket() {};
		~Ticket() {};
	
		void SetTicket();
		void PrintTicket();
		int Get_cabinet();
		void Set_cabinet(int);
		string Get_doctor();
		string Get_spec();
		void WriteFile(string);
		void Change_str();
		void ReadFile(string path, Ticket &ti, deque<Ticket> &dq_ti);

		Date<int> date;
	private:
		string doctor;
		string spec;
		int cabinet;
		friend ostream& operator<<(ostream& os, Ticket& point);
		friend istream& operator>>(istream& is, Ticket& point);
	};

	class Medical_card
	{
	public:
		Medical_card() {};
		~Medical_card() {};

		void SetCard();
		void PrintCard();				//
		void PrintCard(int condition);  //Переопределение методов
		void WriteFile(string path);
		void Change();
		Patient Get_patient();

	private:
		Patient patient;
		friend ostream& operator<<(ostream& os, Medical_card& point);  // Перегрузука операторов
		friend istream& operator>>(istream& is, Medical_card& point);
		friend void filter(deque<Medical_card> p);
		friend void edit(deque<Medical_card> &p, int var);
		friend void sort(deque<Medical_card> &p);
	};

	void menu_pol();
	void menu_del();
	void menu_rec();
	void Warning();
	void begin();
	void filter(deque<Medical_card>);
	int menu_admin(deque<Administrator>);
	void Search(deque<Medical_card>);
	void edit(deque<Medical_card> &p, int var);
	void sort(deque<Medical_card> &p);
	int User_Info(Patient, string);
	void destruction(deque<Medical_card> &p, int i);

	template<class T>    //Шаблонная пользовательская функция
	void check(T &a)     //Передача параметра по ссылке
	{
		while (!(cin >> a)) {
			MessageBox(NULL, L"Введено некорректное значение! Попробуйте снова!", L"ОШИБКА!", MB_OK);
			cin.clear();
			cin.ignore(32767, '\n');
		}
	}
}