#pragma once
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
using namespace std;

#include "mysql.h"
#include "id.h"

int pw_conf;

class Manager
{
public:
	int pw_cf();
	int sus_on();
	int sus_off();
	int pw_chman();
};

// 비밀번호 확인
int Manager::pw_cf()
{
	mysql();

	string query_cf;

	query_cf = "SELECT password FROM manager";

	mysql_query(conn, query_cf.c_str());

	res = mysql_store_result(conn);
	row = mysql_fetch_row(res);

	pw_conf = atoi(row[0]);

	return 0;
}

// 계좌 정지
int Manager::sus_on()
{
	cout << "========== ATM MANAGER ==========" << endl << endl;

	// 계좌 입력
	Id acc_man;
	int account_man = acc_man.account();
	cout << endl;

	// 정지된 계좌 조회
	string query_sus;

	query_sus = "SELECT suspension FROM r WHERE account = '";
	query_sus += a;
	query_sus += "'";

	mysql_query(conn, query_sus.c_str());

	res = mysql_store_result(conn);
	row_sus = mysql_fetch_row(res);

	sus = atoi(row_sus[0]);

	if (sus == 0)
	{
		string query_accman;

		query_accman = "UPDATE r SET suspension = 1 WHERE account = '";
		query_accman += a;
		query_accman += "'";

		mysql_query(conn, query_accman.c_str());

		res = mysql_store_result(conn);

		cout << "계좌가 정지되었습니다" << endl << endl;
	}

	else
	{
		cout << "       <정지된 계좌입니다> " << endl << endl;
	}

	cout << "=================================" << endl << endl << endl;
	system("pause");
	system("cls");

	return 0;
}

// 계좌 정지 해제
int Manager::sus_off()
{
	cout << "========== ATM MANAGER ==========" << endl << endl;

	// 계좌 입력
	Id acc_man;
	int account_man = acc_man.account();
	cout << endl;

	// 정지된 계좌 조회
	string query_sus;

	query_sus = "SELECT suspension FROM r WHERE account = '";
	query_sus += a;
	query_sus += "'";

	mysql_query(conn, query_sus.c_str());

	res = mysql_store_result(conn);
	row_sus = mysql_fetch_row(res);

	sus = atoi(row_sus[0]);

	if (sus == 1)
	{
		string query_accman;

		query_accman = "UPDATE r SET suspension = 0 WHERE account = '";
		query_accman += a;
		query_accman += "'";

		mysql_query(conn, query_accman.c_str());

		res = mysql_store_result(conn);

		cout << "정지가 해제되었습니다" << endl << endl;
	}

	else
	{
		cout << "       <정상적인 계좌입니다> " << endl << endl;
	}

	cout << "=================================" << endl << endl << endl;
	system("pause");
	system("cls");

	return 0;
}

// 관리자 비밀번호 변경
int Manager::pw_chman()
{
	string query_pw;
	int ched;

	mysql();

	for (;;)
	{
		cout << "========== ATM MANAGER ==========" << endl << endl;
		cout << "변경하실 비밀번호를 입력하세요" << endl << ">> ";
		cin >> ched;
		cout << endl;

		if (!cin)
		{
			cout << "   <올바른 숫자로 입력하세요>" << endl << endl;
			cout << "=================================" << endl << endl << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("pause");
			system("cls");
		}

		else if (cin)
		{
			query_pw = "UPDATE manager SET password = ";
			query_pw += to_string(ched);
			query_pw += "";

			mysql_query(conn, query_pw.c_str());

			cout << "변경되었습니다" << endl << endl;
			cout << "=================================" << endl << endl << endl;
			system("pause");
			system("cls");

			break;
		}
	}
	return 0;
}
#endif