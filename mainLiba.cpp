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
		cout<<"����������ѡ��"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				Libra.CommonUser(); //������ͨ�û����� 
				break;
			case 2:
				Libra.Administrator();  //�������Ա���� 
				break;
			case 3:
				Libra.HelpSystem();   //�������ϵͳ
				break; 
			case 0:
				Libra.ExitSystem();  //�˳�ϵͳ 
				break; 
			default:
				cout<<"��������ȷ�ı�ţ�"<<endl;
				break;
		}
		system("cls");
	}
}
