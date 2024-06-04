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


// ���� ����
int Insert::insert()
{
	mysql();

	string name_new; // ���ο� �̸�
	string b_new; // ���� ���� ��
	string bank_new; // ���� ����
	int pw_new = 0; // ��й�ȣ ����
	int account_new = 0;
	string query_new;
	string query_cmf;
	
	system("cls");
	cout << "============== ATM ==============" << endl << endl;
	cout << "�̸� >> ";

	string remainder;
	getline(cin, remainder);

	getline(cin, name_new);
	cout << endl;

	// ���� ����
	for (;;)
	{
		cout << "(1. ���� 2. ���� 3. ���� 4. īī�� 5. �츮)" << endl;
		cout << "���� >> ";
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
			cout << "   <�ùٸ� ���ڷ� �Է��ϼ���> " << endl << endl;
	}

	// ��й�ȣ ����
	for (;;)
	{
		cout << "��й�ȣ�� �Է����ּ��� >> ";
		cin >> pw_new;
		cout << endl;

		if (!cin)
		{
			cout << "     <���ڷ� �Է����ּ���>" << endl << endl;
			cout << "=================================" << endl << endl << endl;
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << endl << endl;
		}
		else
			break;
	}

	// ���� ���� 
	srand((unsigned)time(NULL));
	account_new = rand() % 99999999 + 10000000;

	// ���� ����
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

	cout << "�̸� : " << row[0] << endl;
	cout << "���� : " << row[1] << endl;
	cout << "���¹�ȣ : " << row[2] << endl;
	cout << "���� �ܾ� : " << row[3] << endl << endl;
	cout << "=================================" << endl << endl << endl;
	system("pause");
	system("cls");

	return 0;
}
#endif