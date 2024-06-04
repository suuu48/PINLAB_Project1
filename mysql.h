#pragma once
#ifndef MYSQL_H
#define MYSQL_H

#include <iostream>
#include <string>
#include <mysql.h>

// const char* host = "104.198.15.202";
// const char* user = "root";
// const char* pw = "0620";
// const char* db = "atm";

const char* host = "localhost";
const char* user = "root";
const char* pw = "0620";
const char* db = "test";

int port = 3306;

MYSQL* conn;
MYSQL_RES* res;
MYSQL_RES* res_r2;
MYSQL_ROW row;
MYSQL_ROW row_sus;
MYSQL_ROW row_sus_r;
MYSQL_ROW row_mon;
MYSQL_ROW row_r;
MYSQL_ROW row_cmf;
MYSQL_ROW row_count;

//MYSQL_RES* res_r;
//MYSQL_RES* res_count;
//MYSQL_RES* res_count_r;

string a;
string a_r;
int b_r;

// mysql 연결
int mysql()
{
	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, host, user, pw, db, port, NULL, 0))
	{
		fprintf(stderr, "%s ", mysql_error(conn));
		exit(1);
	}
	return 0;
}

// 데이터 in DB 확인
int exist()
{
	string query_all;
	int b;

	int checking = 0;

	for (;;)
	{
		query_all = "SELECT account FROM r";

		mysql_query(conn, query_all.c_str());

		res = mysql_store_result(conn);
		int	fields_all = mysql_num_fields(res);

		for (;;)
		{
			cout << "계좌번호를 입력해주세요 >> ";
			cin >> b;
			cout << endl;

			if (!cin)
			{
				cout << "     <숫자로 입력해주세요>" << endl << endl;
				cout << "=================================" << endl << endl << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << endl << endl;
				system("pause");
				system("cls");
				cout << "============== ATM ==============" << endl << endl;
			}
			else
				break;
		}

		while (row = mysql_fetch_row(res))
		{
			if (stoi(row[0]) == b)
			{
				checking++;
			}
		}

		mysql_free_result(res);

		if (checking == 1) 
		{
			break;
		}
		else 
		{
			cout << " < 올바른 계좌를 입력해주세요 >" << endl << endl;
			cout << "=================================" << endl << endl << endl;
			system("pause");
			system("cls");
			cout << "============== ATM ==============" << endl << endl;
		}
	}
	a = to_string(b);
	return 0;
}

int exist_r()
{
	string query_all_r;
	
	int checking_r = 0;

	for (;;)
	{
		query_all_r = "SELECT account FROM r";

		mysql_query(conn, query_all_r.c_str());

		res_r2 = mysql_store_result(conn);
		int	fields_all_r = mysql_num_fields(res_r2);

		for (;;)
		{
			cout << "받으실 계좌번호를 입력해주세요 >> ";
			cin >> b_r;
			cout << endl;

			if (!cin)
			{
				cout << "     <숫자로 입력해주세요>" << endl << endl;
				cout << "=================================" << endl << endl << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << endl << endl;
				system("pause");
				system("cls");
				cout << "============== ATM ==============" << endl << endl;
			}
			else
				break;
		}

		while (row = mysql_fetch_row(res_r2))
		{
			if (stoi(row[0]) == b_r)
			{
				checking_r++;
			}
		}

		mysql_free_result(res_r2);

		if (checking_r == 1)
		{
			break;
		}
		else
		{
			cout << " < 올바른 계좌를 입력해주세요 >" << endl << endl;
			cout << "=================================" << endl << endl << endl;
			system("pause");
			system("cls");
			cout << "============== ATM ==============" << endl << endl;
		}
	}
	a_r = to_string(b_r);

	return 0;
}
#endif