#include <iostream>
#include<string>
#include"User.h"
#include"Book.h"
#include"Record.h"
#include"Library.h"
using namespace std;

int main()
{
	Library Libra; 
	int choice;
	while(1)
	{
		Libra.ShowMenue();
		cout<<"请输入您的选择："<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				Libra.CommonUser(); //进入普通用户界面 
				break;
			case 2:
				Libra.Administrator();  //进入管理员界面 
				break;
			case 3:
				Libra.HelpSystem();   //进入帮助系统
				break; 
			case 0:
				Libra.ExitSystem();  //退出系统 
				break; 
			default:
				cout<<"请输入正确的编号："<<endl;
				break;
		}
		system("cls");
	}
}
