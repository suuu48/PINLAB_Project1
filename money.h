#pragma once
#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <string>
using namespace std;

#include "mysql.h"
#include "id.h"

int sus_r;
int money_d;
int money_w;
int money_r;
int rcomp;

// ������ ���̺�� ����
int exp()
{
	string query_exp;

	query_exp = "INSERT INTO r_exp (name, bank, account, money) SELECT name, bank, account, money FROM r WHERE account = '";
	query_exp += a;
	query_exp += "'";

	mysql_query(conn, query_exp.c_str());

	res = mysql_store_result(conn);

	return 0;
}

// �۱ݿ� ���̺� ����
int exp2()
{
	string query_exp2;

	query_exp2 = "INSERT INTO r_exp (name, bank, account, money) SELECT name, bank, account, money FROM r WHERE account = '";
	query_exp2 += a_r;
	query_exp2 += "'";

	mysql_query(conn, query_exp2.c_str());

	res = mysql_store_result(conn);

	return 0;
}

class Money
{
public:
	int deposit();
	int withdraw();
	int remit();
	int check();
};
// �Ա�
int Money::deposit()
{
	string query;
	//int money_d;

	for (;;)
	{
		cout << "============== ATM ==============" << endl << endl;

		cout << "�ݾ��� �Է����ּ��� >> ";
		cin >> money_d;
		cout << endl;

		if (!cin)
		{
			cout << "     <���ڷ� �Է����ּ���>" << endl << endl;
			cout << "=================================" << endl << endl << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << endl << endl;
			system("pause");
			system("cls");
		}
		else
			break;
	}

	query = "UPDATE r SET money = money + ";
	query += to_string(money_d);
	query += " WHERE account ='";
	query += a;
	query += "';";

	mysql_query(conn, query.c_str());

	res = mysql_store_result(conn);

	exp();

	cout << money_d << "���� �Ա��մϴ�" << endl << endl;
	cout << "=================================" << endl << endl << endl;
	system("pause");
	system("cls");

	Money ch;
	int check = ch.check();
	
	return 0;
}

// ���
int Money::withdraw()
{
	string query;
	//int money_w;

	for (;;)
	{
		cout << "============== ATM ==============" << endl << endl;
		cout << "�ݾ��� �Է����ּ��� >> ";
		cin >> money_w;
		cout << endl;

		if (!cin)
		{
			cout << "     <���ڷ� �Է����ּ���>" << endl << endl;
			cout << "=================================" << endl << endl << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << endl << endl;
			system("pause");
			system("cls");
		}
		else
			break;
	}

	// �ܾװ� ��ݾ� ��
	string rowm_w(row[3]);

	if (stoi(rowm_w) >= money_w)
	{
		query = "UPDATE r SET money = money - ";
		query += to_string(money_w);
		query += " WHERE account ='";
		query += a;
		query += "'";

		mysql_query(conn, query.c_str());

		res = mysql_store_result(conn);

		exp();

		cout << money_w << "���� ����մϴ�" << endl << endl;
		cout << "=================================" << endl << endl << endl;
		system("pause");
		system("cls");

		Money ch;
		int check = ch.check();
	}

	else
	{
		cout << "       <�ܾ��� �����մϴ�>" << endl << endl;
		cout << "=================================" << endl << endl << endl;
		system("pause");           
		system("cls");
	}
	return 0;
}

// �۱� -> �ٸ� ������ ��� ������ 500�� �ΰ�
int Money::remit()
{
	string query_re;
	string query_re2;
	//int money_r;

	for (;;)
	{
		cout << "============== ATM ==============" << endl << endl;
		cout << "�ݾ��� �Է����ּ��� >> ";
		cin >> money_r;
		cout << endl;

		if (!cin)
		{
			cout << "     <���ڷ� �Է����ּ���>" << endl << endl;
			cout << "=================================" << endl << endl << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << endl << endl;
			system("pause");
			system("cls");
		}
		else
			break;
	}

	exist_r();

	// ������ ���� ��ȸ
	string query_sus_r;

	query_sus_r = "SELECT suspension FROM r WHERE account = '";
	query_sus_r += a_r;
	query_sus_r += "'";

	mysql_query(conn, query_sus_r.c_str());
	
	res = mysql_store_result(conn);
	row_sus_r = mysql_fetch_row(res);

	sus_r = stoi(row_sus_r[0]);

	if (sus_r == 0)
	{	
		query_re = "SELECT bank FROM r WHERE account = '";
		query_re += a_r;
		query_re += "'";

		mysql_query(conn, query_re.c_str());

		res = mysql_store_result(conn);
		row_r = mysql_fetch_row(res);


		query_re2 = "SELECT * FROM r WHERE account = '";
		query_re2 += a;
		query_re2 += "'";

		mysql_query(conn, query_re2.c_str());

		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		
		// �� ������ ���� ��
		int b_cmp = strcmp(row[2], row_r[0]);

		// ���� ��ġ
		if(b_cmp == 0)
		{
			rcomp = 0;

			// �ܾװ� ��ݾ� ��
			string query_r_e;

			if (stoi(row[5]) >= money_r)
			{
				// �޴� ���¿� �Ա�
				query_r_e = "UPDATE r SET money = money + ";
				query_r_e += to_string(money_r);
				query_r_e += " WHERE account ='";
				query_r_e += a_r;
				query_r_e += "';";

				mysql_query(conn, query_r_e.c_str());

				res = mysql_store_result(conn);

				exp2();

				// ������ ���¿��� ���
				string query_r_e2;
				query_r_e2 = "UPDATE r SET money = money - ";
				query_r_e2 += to_string(money_r);
				query_r_e2 += " WHERE account ='";
				query_r_e2 += a;
				query_r_e2 += "';";

				mysql_query(conn, query_r_e2.c_str());

				res = mysql_store_result(conn);

				exp();

				cout << "=================================" << endl << endl << endl;
				system("pause");
				system("cls");

				Money ch;
				int check = ch.check();
			}
			else
			{
				cout << "       <�ܾ��� �����մϴ�>" << endl << endl;
				cout << "=================================" << endl << endl << endl;
				system("pause");
				system("cls");
			}
		}

		// ���� ����ġ
		else
		{
			rcomp = 1;

			cout << endl << "   <������ 500���� �ΰ��˴ϴ�>" << endl << endl;

			// �ܾװ� ��ݾ� ��
			string query_r_n;

			if ((stoi(row[5])- 500) >= money_r) //if ((stoi(rowm) - 500) >= money_r)
			{
				// �޴� ���¿� �Ա�
				query_r_n = "UPDATE r SET money = money + ";
				query_r_n += to_string(money_r);
				query_r_n += " WHERE account ='";
				query_r_n += a_r;
				query_r_n += "';";

				mysql_query(conn, query_r_n.c_str());

				res = mysql_store_result(conn);

				exp2();

				// ������ ���¿��� ���
				string query_r_n2;
				query_r_n2 = "UPDATE r SET money = money - (";
				query_r_n2 += to_string(money_r);
				query_r_n2 += " + 500) WHERE account ='";
				query_r_n2 += a;
				query_r_n2 += "';";

				mysql_query(conn, query_r_n2.c_str());

				res = mysql_store_result(conn);

				exp();

				cout << "=================================" << endl << endl << endl;
				system("pause");
				system("cls");

				Money ch;
				int check = ch.check();
			}
			else
			{
				cout << "       <�ܾ��� �����մϴ�>" << endl << endl;
				cout << "=================================" << endl << endl << endl;
				system("pause");
				system("cls");
			}
		}
	}

	else 
	{
		cout << endl << "       <������ �����Դϴ�> " << endl << endl;
		cout << "=================================" << endl << endl << endl;
		system("pause");
		system("cls");
	}
	return 0;
}

// Ȯ��â
int Money::check()
{
	cout << "============== ATM ==============" << endl << endl;

	string query;

	query = "SELECT name, bank, account, money FROM r WHERE account='";
	query += a;
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