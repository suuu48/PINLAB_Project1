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

// ���� �Է�
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

// ��й�ȣ �Է� -> ��й�ȣ Ȯ�� (3�� �ȿ� ������ Ȯ��â / 3�� Ʋ���� ���� ����)
int Id::password() 
{
	string pw;
	string pw_cmp;
	string query;

	pw_cmp = row[0];

	for (int i = 0; i < 3; i++) 
	{
		cout << "��й�ȣ�� �Է����ּ��� >> ";
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
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ� " << endl << 2 - i << "�� �� ���°� �����˴ϴ�" << endl;
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
			cout << "���°� �����Ǿ����ϴ�" << endl << endl;
		}
	}
	return 0;
}

// Ȯ��â
int Id::check()
{
	string query;

	query = "SELECT name, bank, account, money FROM r WHERE account='";
	query += a;
	query += "'";

	mysql_query(conn, query.c_str());

	res = mysql_store_result(conn);
	row = mysql_fetch_row(res);

	cout << "�̸� : " << row[0] << endl;
	cout << "���� : " << row[1] << endl;
	cout << "���¹�ȣ : " << row[2] << endl << endl;

	return 0;
}
#endif