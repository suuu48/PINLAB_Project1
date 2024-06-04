#pragma once
#ifndef ID_H
#define ID_H

#include <iostream>
#include <string>
using namespace std;

#include "mysql.h"

int sus;

class Id 
{
public:
	int account();
	int password();
	int check();
};

// 계좌 입력
int Id::account() 
{
	mysql();
	exist();

	string query;

	query = "SELECT pw FROM r WHERE account = '";
	query += a;
	query += "'";

	mysql_query(conn, query.c_str());

	res = mysql_store_result(conn);
	row = mysql_fetch_row(res);

	return 0;
}

// 비밀번호 입력 -> 비밀번호 확인 (3번 안에 맞으면 확인창 / 3번 틀리면 계좌 정지)
int Id::password() 
{
	string pw;
	string pw_cmp;
	string query;

	pw_cmp = row[0];

	for (int i = 0; i < 3; i++) 
	{
		cout << "비밀번호를 입력해주세요 >> ";
		cin >> pw;
		cout << endl;

		if (pw == pw_cmp) 
		{
			Id ch;
			int check = ch.check();
			break;
		}

		else if (i < 2) 
		{
			cout << "비밀번호가 일치하지 않습니다 " << endl << 2 - i << "번 후 계좌가 정지됩니다" << endl;
		}

		else 
		{
			query = "UPDATE r SET suspension = 1 WHERE account='";
			query += a;
			query += "'";

			mysql_query(conn, query.c_str());

			string query_sus;

			query_sus = "SELECT suspension FROM r WHERE account = '";
			query_sus += a;
			query_sus += "'";

			mysql_query(conn, query_sus.c_str());
	
			res = mysql_store_result(conn);
			row_sus = mysql_fetch_row(res);

			sus = atoi(row_sus[0]);
			cout << "계좌가 정지되었습니다" << endl << endl;
		}
	}
	return 0;
}

// 확인창
int Id::check()
{
	string query;

	query = "SELECT name, bank, account, money FROM r WHERE account='";
	query += a;
	query += "'";

	mysql_query(conn, query.c_str());

	res = mysql_store_result(conn);
	row = mysql_fetch_row(res);

	cout << "이름 : " << row[0] << endl;
	cout << "은행 : " << row[1] << endl;
	cout << "계좌번호 : " << row[2] << endl << endl;

	return 0;
}
#endif