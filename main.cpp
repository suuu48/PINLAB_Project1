#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "mysql.h"
#include "id.h"
#include "money.h"
#include "insert.h"
#include "manager.h"

// ���� �Է� -> ��й�ȣ �Է� -> �̸�, ���� Ȯ��â
int id() 
{
	system("cls");
	cout << "============== ATM ==============" << endl << endl;

	// ���� �Է�
	Id acc;
	int id = acc.account();

	// ������ ���� ��ȸ
	string query_sus;
	
	query_sus = "SELECT suspension FROM r WHERE account = '";
	query_sus += a;
	query_sus += "'";

	mysql_query(conn, query_sus.c_str());

	res = mysql_store_result(conn);
	row_sus = mysql_fetch_row(res);

	sus = atoi(row_sus[0]);
	
	// ���� ���ο� ���� ��й�ȣ �Է�
	if (sus == 0) 
	{
		Id ps;
		int p = ps.password();
	}
	else
		cout << endl << "       <������ �����Դϴ�> " << endl << endl;

	cout << "=================================" << endl << endl << endl;
	system("pause");
	system("cls");

	return 0;
}

int main()
{
	system("color f0");
	int menu;
	int txt;

	for (;;)
	{
		cout << "============== ATM ==============" << endl << endl << "1. �����Ա� \t 6. ���»���" << endl;
		cout << "2. ������� \t 7. ��й�ȣ ����" << endl << "3. ������ü \t ================" << endl;
		cout << "4. �ܾ���ȸ \t ================" << endl << "5. �������� \t 0. ������" << endl << endl;
		cout << "=================================" << endl << endl << endl;
		cout << "�޴��� �������ּ��� >> ";
		cin >> menu;
		cout << endl;

		if (!cin)
		{
			cout << "   <�ùٸ� ���ڷ� �Է��ϼ���>" << endl << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("pause");
			system("cls");
		}


		else
		{
			switch (menu)
			{
			case 1: // �����Ա�
			{
				id();

				if (sus == 0)
				{
					Money d;
					int deposit = d.deposit();

					for (;;)
					{
						cout << "��ǥ�� ����Ͻðڽ��ϱ�? \n" << "1. �� \n2. �ƴϿ� \n\n" << "�Է� >> ";
						cin >> txt;
						cout << "\n\n";

						if (!cin)
						{
							cout << "   <�ùٸ� ���ڷ� �Է��ϼ���>" << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							system("pause");
							system("cls");
						}

						else if (txt == 1)
						{
							fstream fout("C:\\temp\\test\\test.txt");

							fout << "�ŷ���ǥ \n" << "[ �Ա� ] \n\n";
							fout << "=========================" << endl << endl;
							fout << "��û �ݾ� : \t" << money_d << endl;
							fout << "�ŷ� �� �ܾ� : \t" << row[3] << endl << endl;
							fout << "=========================" << endl << endl;
							fout << "�̸� : \t\t" << row[0] << endl;
							fout << "���� ��ȣ : \t" << row[2] << endl;
	
							fout.close();
							
							system("pause");
							system("cls");

							break;
						}
						else if (txt == 2)
						{
							system("pause");
							system("cls");
							break;						
						}
						else 
						{
							cout << "   < �ùٸ� ���ڷ� �Է��ϼ��� >" << endl << endl;
							system("pause");
							system("cls");
						}
					}

					break;
				}
				else
					break;


			}

			case 2: // �������
			{
				id();

				if (sus == 0)
				{
					Money w;
					int withdraw = w.withdraw();
					
					for (;;)
					{
						cout << "��ǥ�� ����Ͻðڽ��ϱ�? \n" << "1. �� \n2. �ƴϿ� \n\n" << "�Է� >> ";
						cin >> txt;
						cout << "\n\n";

						if (!cin)
						{
							cout << "   <�ùٸ� ���ڷ� �Է��ϼ���>" << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							system("pause");
							system("cls");
						}

						else if (txt == 1)
						{
							fstream fout("C:\\temp\\test\\test.txt");

							fout << "�ŷ���ǥ \n" << "[ ��� ] \n\n";
							fout << "=========================" << endl << endl;
							fout << "��û �ݾ� : \t" << money_w << endl;
							fout << "�ŷ� �� �ܾ� : \t" << row[3] << endl << endl;
							fout << "=========================" << endl << endl;
							fout << "�̸� : \t\t" << row[0] << endl;
							fout << "���� ��ȣ : \t" << row[2] << endl;

							fout.close();

							system("pause");
							system("cls");

							break;
						}
						else if (txt == 2)
						{
							system("pause");
							system("cls");
							break;
						}
						else
						{
							cout << "   < �ùٸ� ���ڷ� �Է��ϼ��� >" << endl << endl;
							system("pause");
							system("cls");
						}
					}

					break;
				}
				else
					break;
			}

			case 3: // ������ü
			{
				id();

				if (sus == 0)
				{
					Money r;
					int remit = r.remit();

					for (;;)
					{
						cout << "��ǥ�� ����Ͻðڽ��ϱ�? \n" << "1. �� \n2. �ƴϿ� \n\n" << "�Է� >> ";
						cin >> txt;
						cout << "\n\n";

						if (!cin)
						{
							cout << "   <�ùٸ� ���ڷ� �Է��ϼ���>" << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							system("pause");
							system("cls");
						}

						else if (txt == 1)
						{
							fstream fout("C:\\temp\\test\\test.txt");

							fout << "�ŷ���ǥ \n" << "[ �۱� ] \n\n";
							fout << "=========================" << endl << endl;
							fout << "��û �ݾ� : \t" << money_r << endl;
							fout << "�ŷ� �� �ܾ� : \t" << row[3] << endl << endl;
							fout << "=========================" << endl << endl;
							fout << "�̸� : \t\t" << row[0] << endl;
							fout << "���� ��ȣ : \t" << row[2] << endl << endl;
							fout << "�޴� ���� : \t" << a_r << endl;
							
							if (rcomp == 0)
							{
								fout << "������ : \t\t" << "0";
							}
							else
							{
								fout << "������ : \t\t" << "500";
							}

							fout.close();

							system("pause");
							system("cls");

							break;
						}
						else if (txt == 2)
						{
							system("pause");
							system("cls");
							break;
						}
						else
						{
							cout << "   < �ùٸ� ���ڷ� �Է��ϼ��� >" << endl << endl;
							system("pause");
							system("cls");
						}
					}

					break;
				}
				else
					break;
			}

			case 4: // ������ȸ
			{
				id();

				if (sus == 0)
				{
					cout << "============== ATM ==============" << endl << endl;
					cout << "�ܾ��� " << row[3] << "�� �Դϴ�" << endl << endl;
					cout << "=================================" << endl << endl << endl;
					system("pause");
					system("cls");

					break;
				}
				else
					break;
			}

			case 5: // ��������
			{
				id();

				if (sus == 0)
				{
					cout << "============== ATM ==============" << endl << endl;

					string query_arr;
					int num_fields = mysql_num_fields(res);

					query_arr = "SELECT * FROM r_exp WHERE account = '";
					query_arr += a;
					query_arr += "'";

					mysql_query(conn, query_arr.c_str());

					res = mysql_store_result(conn);
					row = mysql_fetch_row(res);

					while (row = mysql_fetch_row(res))
					{
						for (int i = 0; i < num_fields; i++)
						{
							cout << row[i];
							cout << " | ";
						}
						cout << endl;
					}
					cout << endl;
					cout << "=================================" << endl << endl << endl;
					system("pause");
					system("cls");

					break;
				}
				else
					break;
			}

			case 6: // ���� ����
			{
				Insert id_new;
				int insert = id_new.insert();

				break;
			}

			case 7: // ��й�ȣ ����
			{
				int pw_ch;
				string query_pw;

				id();

				if (sus == 0)
				{
					for (;;)
					{
						system("cls");
						cout << "============== ATM ==============" << endl << endl;
						cout << "�����Ͻ� ��й�ȣ�� �Է��ϼ���" << endl << "4�ڸ� >> ";
						cin >> pw_ch;
						cout << endl;


						if (!cin)
						{
							cout << "   <�ùٸ� ���ڷ� �Է��ϼ���>" << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							system("pause");
							system("cls");
						}
						else if (cin)
						{
							query_pw = "UPDATE r SET pw = ";
							query_pw += to_string(pw_ch);
							query_pw += " WHERE account = '";
							query_pw += a;
							query_pw += "'";

							mysql_query(conn, query_pw.c_str());

							cout << "����Ǿ����ϴ�" << endl << endl;
							cout << "=================================" << endl << endl << endl;
							system("pause");
							system("cls");

							break;
						}
					}
					break;
				}
				else
					break;
			}

			case 0: // ������
			{
				int menu_man;
				int pw_man;

				system("cls");
				cout << "========== ATM MANAGER ==========" << endl << endl;
				cout << "������ ��й�ȣ : ";
				cin >> pw_man;
				cout << endl;

				Manager pw;
				int pw_confirm = pw.pw_cf();

				if (pw_conf == pw_man)
				{
					system("cls");

					for (;;)
					{
						cout << "========== ATM MANAGER ==========" << endl << endl;
						cout << "1. ���� ����" << endl;
						cout << "2. ���� ���� ����" << endl;
						cout << "3. ������ ��й�ȣ ����" << endl;
						cout << "4. ATM �޴���" << endl;
						cout << "5. ATM ����" << endl << endl;
						cout << "=================================" << endl << endl << endl;
						cout << "�޴��� �������ּ��� >> ";
						cin >> menu_man;
						cout << endl;

						if (!cin)
						{
							cout << "   < �ùٸ� ���ڷ� �Է��ϼ��� >" << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							system("pause");
							system("cls");
						}

						else
						{
							switch (menu_man)
							{
							case 1: // ���� ����
							{
								system("cls");

								Manager sus;
								int sus_on = sus.sus_on();

								break;
							}

							case 2: // ���� ���� ����
							{
								system("cls");

								Manager sus;
								int sus_off = sus.sus_off();

								break;
							}

							case 3: // ������ ��й�ȣ ����
							{
								system("cls");

								Manager pwch;
								int man_ch = pwch.pw_chman();

								break;
							}

							case 4: // ATM �޴���
							{
								cout << "     <ATM �޴��� ���ư��ϴ�>" << endl << endl << endl;

								system("pause");
								system("cls");
								break;
							}

							case 5: // ATM ����
							{
								cout << "   <ATM ���α׷��� �����մϴ�>" << endl << endl;
								exit(1);
							}

							default:
							{
								cout << "   < �ùٸ� ���ڷ� �Է��ϼ��� >" << endl << endl;
								system("pause");
								system("cls");
							}
							}
							break;
						}
					}
					break;
				}
				else
				{
					cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ� " << endl << endl << endl;
					system("pause");
					system("cls");

					break;
				}
			}

			default:
			{
				cout << "   < �ùٸ� ���ڷ� �Է��ϼ��� >" << endl << endl;
				system("pause");
				system("cls");
			}
			}
		}
	}
}