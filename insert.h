#pragma once
#ifndef INSERT_H
#define INSERT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "mysql.h"

class Insert
{
public:
	int insert();
};


// 계좌 생성
int Insert::insert()
{
	mysql();

	string name_new; // 새로운 이름
	string b_new; // 은행 유무 비교
	string bank_new; // 은행 선택
	int pw_new = 0; // 비밀번호 생성
	int account_new = 0;
	string query_new;
	string query_cmf;
	
	system("cls");
	cout << "============== ATM ==============" << endl << endl;
	cout << "이름 >> ";

	string remainder;
	getline(cin, remainder);

	getline(cin, name_new);
	cout << endl;

	// 은행 선택
	for (;;)
	{
		cout << "(1. 국민 2. 농협 3. 신한 4. 카카오 5. 우리)" << endl;
		cout << "은행 >> ";
		cin >> b_new;
		cout << endl;
		if (b_new == "1")
		{
			bank_new = "kookmin"; break;
		}

		else if (b_new == "2")
		{
			bank_new = "nunghyup"; break;
		}

		else if (b_new == "3")
		{
			bank_new = "sinhan"; break;
		}

		else if (b_new == "4")
		{
			bank_new = "kakao"; break;
		}

		else if (b_new == "5")
		{
			bank_new = "woori"; break;
		}

		else
			cout << "   <올바른 숫자로 입력하세요> " << endl << endl;
	}

	// 비밀번호 생성
	for (;;)
	{
		cout << "비밀번호를 입력해주세요 >> ";
		cin >> pw_new;
		cout << endl;

		if (!cin)
		{
			cout << "     <숫자로 입력해주세요>" << endl << endl;
			cout << "=================================" << endl << endl << endl;
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << endl << endl;
		}
		else
			break;
	}

	// 계좌 생성 
	srand((unsigned)time(NULL));
	account_new = rand() % 99999999 + 10000000;

	// 계좌 저장
	query_new = "INSERT INTO r (name, bank, account, pw, money, suspension) VALUES ('";
	query_new += name_new;
	query_new += "','";
	query_new += bank_new;
	query_new += "','";
	query_new += to_string(account_new);
	query_new += "','";
	query_new += to_string(pw_new);
	query_new += "',";
	query_new += "'0','0')";

	mysql_query(conn, query_new.c_str());

	res = mysql_store_result(conn);

	system("pause");
	system("cls");

	cout << "============== ATM ==============" << endl << endl;

	string query;

	query = "SELECT name, bank, account, money FROM r WHERE account='";
	query += to_string(account_new);
	query += "'";

	mysql_query(conn, query.c_str());

	res = mysql_store_result(conn);
	row = mysql_fetch_row(res);

	cout << "이름 : " << row[0] << endl;
	cout << "은행 : " << row[1] << endl;
	cout << "계좌번호 : " << row[2] << endl;
	cout << "현재 잔액 : " << row[3] << endl << endl;
	cout << "=================================" << endl << endl << endl;
	system("pause");
	system("cls");

	return 0;
}
#endif