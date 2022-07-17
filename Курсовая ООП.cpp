#include <iostream>
#include <string>
#include <time.h>
#include <deque>
#include <Windows.h>
#include <direct.h>
#include "classes.h"
using namespace std;
using namespace MyNameSpace;

int main()
{
	setlocale(LC_ALL, "rus");
	system("color F0");
	system("mode con cols=140 lines=30");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	srand((unsigned int)time(NULL));

	int menu1, adm, x = 0;
	double sta = clock();
	int *ptr = new int;    //Использование динамической памяти

	Medical_card MDC;
	Administrator admin;
	deque<Medical_card> Registration;
	deque<Administrator> Adm;
	deque<Ticket> time_check;
	Ticket TC;
	TC.ReadFile("tkt.txt", TC, time_check);

	string path = "path.txt";
	fstream fs;

	fs.open(path, fstream::in | fstream::out | ios::app);

	if (!fs.is_open())
	{
		cout << "Error!" << endl;
	}
	else if (fs.peek() == EOF)
		Patient::SetCount(0);
	else
	{
		while (!fs.eof())
		{
			fs >> MDC;
			MDC.Change();
			Registration.push_back(MDC);
			Patient::SetCount(MDC.Get_patient().Get_id());
		}
	}
	fs.close();

	while (x == 0)
	{
		begin();
		cout << "Ваш выбор ~> ";
		check(menu1);

		switch (menu1)
		{
		case 1:
		{
			if (menu_admin(Adm) == 0) {
				break;
			}
			system("cls");
			int y = 0;
			while (y == 0)
			{
				cout << "<<< Меню администраторa >>>\n\n";
				menu_rec();
				cout << "Ваш выбор ~> ";
				check(adm);
				system("cls");

				if (Registration.empty()) {
					cout << "Список пуст!\n";
					system("pause");
					system("cls");
					continue;
				}
				switch (adm) {
				case 1:
				{
					for (int i = 0; i != Registration.size(); i++)
					{
						Registration.at(i).PrintCard(i);
					}
					break;
				}
				case 2:
				{
					MDC.SetCard();
					string name = MDC.Get_patient().Get_surname() + "_" + MDC.Get_patient().Get_name();
					const char *cname = name.c_str();
					if (_mkdir(cname) == -1)
					{
						cout << "Данный пользователь уже существует!" << endl;
						break;
					};
					MDC.WriteFile("path.txt");
					MDC.Get_patient().WriteFile(name + "\\info.txt");
					MDC.WriteFile(name + "\\param.txt");
					MDC.Change();
					Registration.push_back(MDC);
					cout << "\nПользователь успешно зарегистрирован" << endl;
					break;
				}
				case 3:
				{
					Search(Registration);
					break;
				}
				case 4:
				{
					int ch;
					for (unsigned int i = 0; i != Registration.size(); i++)
					{
						Registration.at(i).PrintCard(i);
					}
					menu_del();
					cout << "Ваш выбор ~> ";
					cin >> ch;
					switch (ch) {
					case 1:
					{
						deque<Medical_card>::iterator itr = Registration.begin();
						cout << "Введите id пользователя, которого вы хотите удалить ~> ";
						int ID, flg = 0;;
						check(ID);
						for (unsigned int i = 0; i < Registration.size(); i++)
						{
							if (Registration.at(i).Get_patient().Get_id() == ID)
							{
								destruction(Registration, i);
								advance(itr, i);
								Registration.erase(itr);
								flg = 1;
							}
						}
						if (flg == 0)
							cout << "Записей с id данным не существует!" << endl;
						else
						{
							remove("path.txt");
							for (unsigned int j = 0; j < Registration.size(); j++)
							{
								Registration.at(j).Get_patient().Set_adress(Registration.at(j).Get_patient().Get_adress());
								Registration.at(j).WriteFile("path.txt");
							}
							cout << "Пользователь успешно удален" << endl;
						}
						break;
						}
					case 2:
					{
						int answer = MessageBox(NULL, L"Вы действительно хотите удалить все записи?", L"ПРЕДУПРЕЖДЕНИЕ!", MB_YESNO);
						if (answer == IDNO) {
							cin.clear();
							cin.ignore(32767, '\n');
							break;
						}
						else
						{
							Registration.clear();
							fs.open("path.txt", fstream::out | ios::trunc);
							fs.close();
						}
						break;
					}
					default:
						Warning();
						break;
					}
				}
				case 5:
					cout << "Количество элементов = " << Registration.size() << endl;
					break;
				case 6:
					sort(Registration);
					break;
				case 7:
				filter(Registration);
					break;
				case 8:
					edit(Registration, 0);
					break;
				case 9:
				{
					admin.ReadFile("adm.txt", admin, Adm);
					cout << "<<<Меню управления администраторами>>>" << endl << endl;
					cout << "1.Добавить нового администратора" << endl;
					cout << "2.Удалить существующего администратора" << endl;
					cout << "0.Выйти в предыдущее меню" << endl;
					int ch;
					cout << "Ваш выбор ~> ";
					check(ch);
					switch (ch) {
					case 1:
					{
						admin.SetUser();
						admin.WriteFile("adm.txt");
						Adm.push_back(admin);
						cout << "Администратор успешно добавлен" << endl;
						break;
					}
					case 2:
					{
						cout << "<<<Меню удаления администратора>>>" << endl;
						for (unsigned int i = 0; i != Adm.size(); i++)
						{
							Adm.at(i).PrintPeople();
						}
						cout <<"Введите имя администратора, которого хотите удалить" << endl;
						string adm_name; 
						int flag = 0;
						cout << "Ваш выбор ~> ";
						cin >> adm_name;
						for (unsigned int i = 0; i < Adm.size(); i++)
						{
							if (Adm.at(i).Get_nameA() == adm_name)
							{
								deque<Administrator>::iterator itr = Adm.begin();
								advance(itr, i);
								Adm.erase(itr);
								flag = 1;
							}
						}
						if (flag == 0)
						{
							cout << "Не существует администраторов с данным именем!" << endl;
						}
						else
						{
							remove("adm.txt");
							for (unsigned int j = 0; j < Adm.size(); j++)
							{
								Adm.at(j).WriteFile("adm.txt");
							}
							cout << "Администратор успешно удален" << endl;
						}
						break;
					}
					case 0: break;
					default:
						Warning();
						break;
					}
					break;
				}
				case 10:
				{
					vector<Doctor> octo;
					Doctor dct;
					fstream fs;
					fs.open("doc.txt", fstream::in | fstream::out | ios::app);

					if (!fs.is_open())
					{
						cout << "Error!" << endl;
					}
					else if (fs.peek() == EOF)
						Doctor::SetCnt(0);
					else
					{
						while (!fs.eof())
						{
							fs >> dct;
							octo.push_back(dct);
							Doctor::SetCnt(dct.Get_ID());
						}
					}
					fs.close();

					cout << "<<<Меню работы с записями врачей>>>" << endl << endl;
					cout << "1.Добавить нового врача" << endl;
					cout << "2.Удалить существующего врача" << endl;
					cout << "3.Просмотреть список врачей" << endl;
					int ch;
					cout << "Ваш выбор ~> ";
					check(ch);
					switch (ch) {
					case 1:
					{
						dct.SetPeople();
						dct.WriteFile("doc.txt");
						octo.push_back(dct);
						cout << "Врач успешно добавлен" << endl;
						break;
					}
					case 2:
					{
						cout << "<<<Меню удаления врача>>>" << endl;
						for (unsigned int i = 0; i != octo.size(); i++)
						{
							octo.at(i).PrintPeople();
						}
						cout << "Введите id врача, которого хотите удалить" << endl;
						int octo_id;
						int flag = 0;
						cout << "Ваш выбор ~> ";
						check(octo_id);
						vector<Doctor>::iterator itr = octo.begin();
						for (unsigned int i = 0; i < octo.size(); i++)
						{
							if (octo.at(i).Get_ID() == octo_id)
							{
								advance(itr, i);
								octo.erase(itr);
								flag = 1;
							}
						}
						if (flag == 0)
						{
							cout << "Данного врача не существует!" << endl;
						}
						else
						{
							remove("doc.txt");
							for (unsigned int j = 0; j < octo.size(); j++)
							{
								octo.at(j).WriteFile("doc.txt");
							}
							cout << "Врач успешно удален" << endl;
						}
						break;
					}
					case 3:
					{
						for (unsigned int i = 0; i != octo.size(); i++)
						{
							octo.at(i).PrintPeople();
						}
					}
					case 0: break;
					default:
						Warning();
						break;
					}
					break;
				}
				case 11:
				{
					for (int i = 0; i != time_check.size(); i++)
					{
						time_check.at(i).PrintTicket();
					}
					break;
				}
				case 0:y = 1; break;
				default:
				{
					Warning();
					break;
				}
				}
				system("pause");
				system("cls");

			}
			break;
		}
		case 2:
		{
			system("cls");
			int y = 0;
			while (y == 0)
			{
				cout << "<<< Меню пользователя >>>\n\n";
				menu_pol();

				cout << "Ваш выбор ~> ";
				cin >> adm;

				switch (adm)
				{
				case 1:
				{
					system("cls");
					MDC.SetCard();
					string name = MDC.Get_patient().Get_surname() + "_" + MDC.Get_patient().Get_name();
					const char *cname = name.c_str();
					if (_mkdir(cname) == -1)
					{
						cout << "Данный пользователь уже существует!" << endl;
						break;
					};
					MDC.WriteFile("path.txt");
					MDC.Get_patient().WriteFile(name + "\\info.txt");
					MDC.WriteFile(name+ "\\param.txt");
					MDC.Change();
					Registration.push_back(MDC);
					break;
				}
				case 2:
				{
					system("cls");
					Medical_card medical;
					Patient inf;
					string Surname, Name;
					cout << "Введите Имя" << endl;
					cout << "Ваш выбор ~> ";
					cin >> Name;
					cout << "Введите Фамилию" << endl;
					cout << "Ваш выбор ~> ";
					cin >> Surname;
					string name = Surname + "_" + Name;
					const char *cname = name.c_str();
					if (_mkdir(cname) == -1)
					{
						fstream fs;
						fs.open(name + "\\info.txt", fstream::in | fstream::out | fstream::app);

						if (!fs.is_open())
						{
							cout << "Error!" << endl;
						}
						else
						{
							fs >> inf;
							if (User_Info(inf, name + "\\info.txt") == 0) {
								break;
							}
						}
						fs.close();
						system("cls");
					
						fstream fl;
						fl.open(name + "\\param.txt", fstream::in | fstream::out | fstream::app);

						if (!fl.is_open())
						{
							cout << "Error!" << endl;
						}
						else
						{
							fl >> medical;
							medical.Change();
							medical.PrintCard();
						}
						fl.close();

						int io = 0;
						Ticket ticket;
						while (io == 0)
						{
							system("cls");
							cout << "Добро пожаловать в аккаунт!" << endl << endl;
							cout << "1.Заказать талон\n";
							cout << "2.Просмотреть свои талоны\n";
							cout << "3.Редактирование данных\n";
							cout << "0.Выход из аккаунта\n";
							cout << "Выберите операцию ~> ";
							int swh;
							check(swh);
							system("cls");

							switch (swh)
							{
							case 1:
							{
								ticket.SetTicket();
								ticket.WriteFile(name + "\\tickets.txt");
								ticket.WriteFile("tkt.txt");
								break;
							}
							case 2:
							{

								fstream fs;

								fs.open(name + "\\tickets.txt", fstream::in | fstream::out | ios::app);

								if (!fs.is_open())
								{
									cout << "Error!" << endl;
								}
								else if (fs.peek() == EOF)
									cout << "У вас нет талонов!" << endl;
								else
								{
									while (!fs.eof())
									{
										fs >> ticket;
										ticket.Change_str();
										ticket.PrintTicket();
									}
								}
								fs.close();
								break;
							}
							case 3:
							{
								edit(Registration, medical.Get_patient().Get_id());
								break;
							}
							case 0: io = 1; break;
							default:
								Warning();
								break;
							}
							system("pause");
						}
					}
					else
					{
						cout << "Пользователя не существует!" << endl;
						_rmdir(cname);
					}
					break;
				}
				case 0: y = 1; break;
				default:
				{
					Warning();
					break;
				}
				}
				system("cls");
			}
			break;
		}

		case 0:
		{
			system("cls");
			cout << "\nПрограмма завершена\n";
			printf("\nВремя работы программы - %.2lf мин.\n", ((clock() - sta) / CLOCKS_PER_SEC) / 60);
			exit(0);
		}
		default:
		{
			Warning();
			break;
		}
		}
		system("cls");
	}
	delete[] ptr;
}