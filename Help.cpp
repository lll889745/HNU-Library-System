#pragma once
#include"Help.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void Help::HelpMenu()
{
    cout << "\t\t\t================= 帮~助~系~统 ================\n";
	cout << "\t\t\t|                1.忘记密码                 ｜\n";
	cout << "\t\t\t|                2.密码输错次数太多         ｜\n";
	cout << "\t\t\t|                3.报告未知问题             ｜\n";
	cout << "\t\t\t|                0.退出系统                 ｜\n";
	cout << "\t\t\t==============================================\n";
	cout << "使用中遇到问题？请选择你的问题：";
}

void Help::ForgetProblem()
{
    cout << "请联系管理员重置！" << endl;
    system("pause");
    return ;
}

void Help::MuchProblem()
{
    cout << "请联系管理员！"<< endl;
    system("pause");
    return ;
}

void Help::ReportProblem()
{
    string problem, communicate;
    ofstream outfile("Bugs.txt", ios::out|ios::app);
    cout << "请输入您发现的问题："<< endl;
    cin >> problem;
    outfile << "问题：" << problem << endl;
    cout << endl << "请输入您的联系方式："<< endl;
    cin >> communicate;
    outfile << "联系方式：" << communicate << endl;
    outfile << "============================"<<endl;
    outfile.close();
    cout << "我们已经收到您的建议，谢谢！"<< endl;
    system("pause");
    return ;
}


