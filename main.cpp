#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "mysql.h"
#include "id.h"
#include "money.h"
#include "insert.h"
#include "manager.h"

// 계좌 입력 -> 비밀번호 입력 -> 이름, 계좌 확인창
int id() 
{
	system("cls");
	cout << "============== ATM ==============" << endl << endl;

	// 계좌 입력
	Id acc;
	int id = acc.account();

	// 정지된 계좌 조회
	string query_sus;
	
	query_sus = "SELECT suspension FROM r WHERE account = '";
	query_sus += a;
	query_sus += "'";

	mysql_query(conn, query_sus.c_str());

	res = mysql_store_result(conn);
	row_sus = mysql_fetch_row(res);

	sus = atoi(row_sus[0]);
	
	// 정지 여부에 따라 비밀번호 입력
	if (sus == 0) 
	{
		Id ps;
		int p = ps.password();
	}
	else
		cout << endl << "       <정지된 계좌입니다> " << endl << endl;

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
		cout << "============== ATM ==============" << endl << endl << "1. 예금입금 \t 6. 계좌생성" << endl;
		cout << "2. 예금출금 \t 7. 비밀번호 변경" << endl << "3. 계좌이체 \t ================" << endl;
		cout << "4. 잔액조회 \t ================" << endl << "5. 통장정리 \t 0. 관리자" << endl << endl;
		cout << "=================================" << endl << endl << endl;
		cout << "메뉴를 선택해주세요 >> ";
		cin >> menu;
		cout << endl;

		if (!cin)
		{
			cout << "   <올바른 숫자로 입력하세요>" << endl << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("pause");
			system("cls");
		}


		else
		{
			switch (menu)
			{
			case 1: // 예금입금
			{
				id();

				if (sus == 0)
				{
					Money d;
					int deposit = d.deposit();

					for (;;)
					{
						cout << "명세표를 출력하시겠습니까? \n" << "1. 예 \n2. 아니요 \n\n" << "입력 >> ";
						cin >> txt;
						cout << "\n\n";

						if (!cin)
						{
							cout << "   <올바른 숫자로 입력하세요>" << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							system("pause");
							system("cls");
						}

						else if (txt == 1)
						{
							fstream fout("C:\\temp\\test\\test.txt");

							fout << "거래명세표 \n" << "[ 입금 ] \n\n";
							fout << "=========================" << endl << endl;
							fout << "요청 금액 : \t" << money_d << endl;
							fout << "거래 후 잔액 : \t" << row[3] << endl << endl;
							fout << "=========================" << endl << endl;
							fout << "이름 : \t\t" << row[0] << endl;
							fout << "계좌 번호 : \t" << row[2] << endl;
	
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
							cout << "   < 올바른 숫자로 입력하세요 >" << endl << endl;
							system("pause");
							system("cls");
						}
					}

					break;
				}
				else
					break;


			}

			case 2: // 예금출금
			{
				id();

				if (sus == 0)
				{
					Money w;
					int withdraw = w.withdraw();
					
					for (;;)
					{
						cout << "명세표를 출력하시겠습니까? \n" << "1. 예 \n2. 아니요 \n\n" << "입력 >> ";
						cin >> txt;
						cout << "\n\n";

						if (!cin)
						{
							cout << "   <올바른 숫자로 입력하세요>" << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							system("pause");
							system("cls");
						}

						else if (txt == 1)
						{
							fstream fout("C:\\temp\\test\\test.txt");

							fout << "거래명세표 \n" << "[ 출금 ] \n\n";
							fout << "=========================" << endl << endl;
							fout << "요청 금액 : \t" << money_w << endl;
							fout << "거래 후 잔액 : \t" << row[3] << endl << endl;
							fout << "=========================" << endl << endl;
							fout << "이름 : \t\t" << row[0] << endl;
							fout << "계좌 번호 : \t" << row[2] << endl;

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
							cout << "   < 올바른 숫자로 입력하세요 >" << endl << endl;
							system("pause");
							system("cls");
						}
					}

					break;
				}
				else
					break;
			}

			case 3: // 계좌이체
			{
				id();

				if (sus == 0)
				{
					Money r;
					int remit = r.remit();

					for (;;)
					{
						cout << "명세표를 출력하시겠습니까? \n" << "1. 예 \n2. 아니요 \n\n" << "입력 >> ";
						cin >> txt;
						cout << "\n\n";

						if (!cin)
						{
							cout << "   <올바른 숫자로 입력하세요>" << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							system("pause");
							system("cls");
						}

						else if (txt == 1)
						{
							fstream fout("C:\\temp\\test\\test.txt");

							fout << "거래명세표 \n" << "[ 송금 ] \n\n";
							fout << "=========================" << endl << endl;
							fout << "요청 금액 : \t" << money_r << endl;
							fout << "거래 후 잔액 : \t" << row[3] << endl << endl;
							fout << "=========================" << endl << endl;
							fout << "이름 : \t\t" << row[0] << endl;
							fout << "계좌 번호 : \t" << row[2] << endl << endl;
							fout << "받는 계좌 : \t" << a_r << endl;
							
							if (rcomp == 0)
							{
								fout << "수수료 : \t\t" << "0";
							}
							else
							{
								fout << "수수료 : \t\t" << "500";
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
							cout << "   < 올바른 숫자로 입력하세요 >" << endl << endl;
							system("pause");
							system("cls");
						}
					}

					break;
				}
				else
					break;
			}

			case 4: // 계좌조회
			{
				id();

				if (sus == 0)
				{
					cout << "============== ATM ==============" << endl << endl;
					cout << "잔액은 " << row[3] << "원 입니다" << endl << endl;
					cout << "=================================" << endl << endl << endl;
					system("pause");
					system("cls");

					break;
				}
				else
					break;
			}

			case 5: // 통장정리
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

			case 6: // 계좌 생성
			{
				Insert id_new;
				int insert = id_new.insert();

				break;
			}

			case 7: // 비밀번호 변경
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
						cout << "변경하실 비밀번호를 입력하세요" << endl << "4자리 >> ";
						cin >> pw_ch;
						cout << endl;


						if (!cin)
						{
							cout << "   <올바른 숫자로 입력하세요>" << endl << endl;
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

							cout << "변경되었습니다" << endl << endl;
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

			case 0: // 관리자
			{
				int menu_man;
				int pw_man;

				system("cls");
				cout << "========== ATM MANAGER ==========" << endl << endl;
				cout << "관리자 비밀번호 : ";
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
						cout << "1. 계좌 정지" << endl;
						cout << "2. 계좌 정지 해제" << endl;
						cout << "3. 관리자 비밀번호 변경" << endl;
						cout << "4. ATM 메뉴로" << endl;
						cout << "5. ATM 종료" << endl << endl;
						cout << "=================================" << endl << endl << endl;
						cout << "메뉴를 선택해주세요 >> ";
						cin >> menu_man;
						cout << endl;

						if (!cin)
						{
							cout << "   < 올바른 숫자로 입력하세요 >" << endl << endl;
							cin.clear();
							cin.ignore(INT_MAX, '\n');
							system("pause");
							system("cls");
						}

						else
						{
							switch (menu_man)
							{
							case 1: // 계좌 정지
							{
								system("cls");

								Manager sus;
								int sus_on = sus.sus_on();

								break;
							}

							case 2: // 계좌 정지 해제
							{
								system("cls");

								Manager sus;
								int sus_off = sus.sus_off();

								break;
							}

							case 3: // 관리자 비밀번호 변경
							{
								system("cls");

								Manager pwch;
								int man_ch = pwch.pw_chman();

								break;
							}

							case 4: // ATM 메뉴로
							{
								cout << "     <ATM 메뉴로 돌아갑니다>" << endl << endl << endl;

								system("pause");
								system("cls");
								break;
							}

							case 5: // ATM 종료
							{
								cout << "   <ATM 프로그램을 종료합니다>" << endl << endl;
								exit(1);
							}

							default:
							{
								cout << "   < 올바른 숫자로 입력하세요 >" << endl << endl;
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
					cout << "비밀번호가 일치하지 않습니다 " << endl << endl << endl;
					system("pause");
					system("cls");

					break;
				}
			}

			default:
			{
				cout << "   < 올바른 숫자로 입력하세요 >" << endl << endl;
				system("pause");
				system("cls");
			}
			}
		}
	}
}