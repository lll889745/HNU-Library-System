#pragma once
#include"Help.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void Help::HelpMenu()
{
    cout << "\t\t\t================= ��~��~ϵ~ͳ ================\n";
	cout << "\t\t\t|                1.��������                 ��\n";
	cout << "\t\t\t|                2.����������̫��         ��\n";
	cout << "\t\t\t|                3.����δ֪����             ��\n";
	cout << "\t\t\t|                0.�˳�ϵͳ                 ��\n";
	cout << "\t\t\t==============================================\n";
	cout << "ʹ�����������⣿��ѡ��������⣺";
}

void Help::ForgetProblem()
{
    cout << "����ϵ����Ա���ã�" << endl;
    system("pause");
    return ;
}

void Help::MuchProblem()
{
    cout << "����ϵ����Ա��"<< endl;
    system("pause");
    return ;
}

void Help::ReportProblem()
{
    string problem, communicate;
    ofstream outfile("Bugs.txt", ios::out|ios::app);
    cout << "�����������ֵ����⣺"<< endl;
    cin >> problem;
    outfile << "���⣺" << problem << endl;
    cout << endl << "������������ϵ��ʽ��"<< endl;
    cin >> communicate;
    outfile << "��ϵ��ʽ��" << communicate << endl;
    outfile << "============================"<<endl;
    outfile.close();
    cout << "�����Ѿ��յ����Ľ��飬лл��"<< endl;
    system("pause");
    return ;
}


