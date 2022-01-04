#pragma once
#include<iostream>
#include<string>
#include"Book.h"
#include"Library.h"
#include<fstream>
using namespace std;

Library::Library()			//�����鼮�ļ����û��ļ������ļ�¼�ļ� ����һ��ͼ��� 
{
	this->get_BookNum();	//��ȡ�ļ����鼮��������m_sum; 
	this->get_UserNum();	//��ȡ�ļ�user����������m_user_sum 
	this->get_RecordNum();	//��ȡ�ļ��н��ļ�¼����������m_record_sum 
    ifstream ifs;  
	
	//�鼮���� 
    books=new Book[this->m_sum];
    ifs.open("books.txt",ios::in);
    if(ifs.is_open())		//�ж��ļ��Ƿ���ڻ��
    {
        int i=0;
        string str,temp1,temp2,temp3,temp4;
        int temp5;			//���� 
        int mark=0;
        while(i<this->m_sum)
        {
            ifs>>temp1>>temp2>>temp3>>temp4>>temp5;
            books[i].MakeBook(temp1,temp2,temp3,temp4,temp5);//��ȡ�鼮��Ϣ 
            i++;
        }
    }
    else cout<<"books�ļ�δ�ҵ���"<<endl;
    ifs.close();
    
    //User����
	ifs.open("users.txt",ios::in);
	if(ifs.is_open())
	{
		char ch;
		ifs>>ch; 
		if(ifs.eof())//�ļ���û������ ,�����д���1������Ա�ʻ���10000����ͨ�û� 
		{
			ifs.close();
			m_user_sum=10001;
			users=new User[m_user_sum];
			users[0].MakeUser(123456,123456,1);
			int account=1001;
			for(int i=1;i<m_user_sum;i++)
			{
				users[i].MakeUser(account,123456,2);
				account++; 
			}
			this->SaveUser();//���浽�ļ� 
		}
		else  //�ļ��������� 
		{
			ifs.close();
			this->BuidUser();  //���ô������� 
		} 
	}
	else 
	{
		cout<<"users�ļ�δ�ҵ���"<<endl;
		ifs.close();
	}
	
	//Record��ȡ
	records=new Record[m_record_sum];
    ifs.open("records.txt",ios::in);
    if(ifs.is_open())//�ж��ļ��Ƿ���ڻ��
    {
        int i=0;
        int account;string name;
        while(i<this->m_record_sum)//bugԭ��m_record_sum�ó�m_sum 
        {
            ifs>>account>>name;
            records[i].MakeRecord(account,name);//��ȡrecord��Ϣ 
            i++;
        }
    }
    else cout<<"records�ļ�δ�ҵ���"<<endl;
    ifs.close(); 
}

Library::~Library()//�����������������
{
	if(this->users!=NULL)
	{
		delete[] this->users;
		this->users=NULL;
	}
	if(this->books!=NULL) 
	{
		delete[] this->books;
		books=NULL;
	}
	if(this->records!=NULL)
	{
		delete[] records;
		records=NULL;
	}
} 
void Library::ShowMenue()//�˵�չʾ
{
    cout << "\t\t\t============== ͼ~��~��~��~ϵ~ͳ =============\n";
	cout << "\t\t\t|                1.�û���¼                 ��\n";
	cout << "\t\t\t|                2.����Ա��¼               ��\n";
	cout << "\t\t\t|                3.����                     ��\n";
	cout << "\t\t\t|                0.�˳�                     ��\n";
	cout << "\t\t\t==============================================\n";
	cout << "��ӭʹ��ͼ�����ϵͳ��\n��ѡ���ܣ�\n";
}

void Library::ShowAdministratorMenue()//չʾ����Ա�˵�
{
    cout << "\t\t\t================ ��~��~Ա~��~�� ==============\n";
	cout << "\t\t\t|                1.�޸�����                 ��\n";
	cout << "\t\t\t|                2.����ͼ��                 ��\n";
	cout << "\t\t\t|                3.����û�                 ��\n";
	cout << "\t\t\t|                4.ɾ���û�                 ��\n";
	cout << "\t\t\t|                5.���ͼ��                 ��\n";
	cout << "\t\t\t|                6.ɾ��ͼ��                 ��\n";
	cout << "\t\t\t|                7.�����û�                 ��\n";
	cout << "\t\t\t|                8.�޸�ͼ��                 ��\n";
	cout << "\t\t\t|                0.�˳�                     ��\n";
	cout << "\t\t\t==============================================\n";
	cout << "��ѡ���ܣ�\n";
} 

void Library::ShowCommonMenue()//չʾ��ͨ�û��Ĳ˵�
{
    cout << "\t\t\t================= ��~��~��~�� ================\n";
	cout << "\t\t\t|                1.�޸�����                 ��\n";
	cout << "\t\t\t|                2.����ͼ��                 ��\n";
	cout << "\t\t\t|                3.�鿴���ļ�¼             ��\n";
	cout << "\t\t\t|                4.�黹ͼ��                 ��\n";
	cout << "\t\t\t|                5.����ͼ��                 ��\n";
	cout << "\t\t\t|                0.�˳�                     ��\n";
	cout << "\t\t\t==============================================\n";
	cout << "��ѡ���ܣ�\n";
} 
 
void Library::ExitSystem()//�˳�ϵͳ�� 
{
	cout<<"��ӭ�´�ʹ�ã�"<<endl;
	system("pause");
	exit(0);
}

void Library::get_BookNum()//��ȡ�ļ��е��鼮����
{
	m_sum=0;
	ifstream ifs;
	ifs.open("books.txt",ios::in);
	if(!ifs.is_open()) cout<<"�ļ������ڣ�"<<endl;
	else
	{
		char ch;ifs>>ch;
		if(ifs.eof()) m_sum=0;    //�ж��Ƿ��ǿ��ļ� 
		else
		{
			ifs.close();
			ifs.open("books.txt",ios::in);
			string name,isbn,author,code,temp;
			while(ifs>>name&&ifs>>isbn&&ifs>>author&&ifs>>code&&ifs>>temp)
			{
				this->m_sum+=1;
			}
			ifs.close(); 
		}
	} 
} 

void Library::get_UserNum()//�� users.txt �л�ȡuser����
{
	ifstream ifs;
	ifs.open("users.txt",ios::in);
	this->m_user_sum=0;
	if(ifs.is_open())
	{
		char ch;ifs>>ch;
		if(ifs.eof())
		{
			this->m_user_sum=0;
			ifs.close();
		}
		else {
			ifs.close();
			int account,password,code;
			ifs.open("users.txt",ios::in);
			while(ifs>>account&&ifs>>password&&ifs>>code)
			{
				this->m_user_sum+=1;
			}
			ifs.close();
		} 
	}
	else 
	{
		cout<<"users�ļ������ڣ�"<<endl;
		ifs.close();
	}
	return ;
} 

void Library::get_RecordNum()//���ļ��еõ�record������ 
{
	ifstream ifs;
	ifs.open("records.txt",ios::in);
	this->m_record_sum=0;
	if(ifs.is_open())//�ж��ļ��Ƿ�� 
	{
		char ch;ifs>>ch;
		if(ifs.eof())
		{
			this->m_record_sum=0;
			ifs.close();
		}
		else {
			ifs.close();
			int account;string name;
			ifs.open("records.txt",ios::in);
			while(ifs>>account&&ifs>>name)
			{
				this->m_record_sum+=1;
			}
			ifs.close();
		} 
	}
	else 
	{
		cout<<"records�ļ������ڣ�"<<endl;
		ifs.close();
	}
	return ;
}

void Library::SortBookByName(string str)//��������
{
    for(int i=0;i<m_sum;i++)
    {
        if(books[i].GetName()!=str) continue;
        else
        {
            cout<<books[i].GetAuthor()<<"��"<<books[i].GetName()<<"��"<<books[i].GetBookNum()<<"��ʣ�ࡣ"<<endl;
            return ;
        }
    }
    cout<<"δ�ҵ�,�����Ƿ�������ȷ��������"<<endl;
}

void Library::SortBookByIsbn(string str)//��isbn
{
    for(int i=0;i<m_sum;i++)
    {
        if(books[i].GetIsbn()!=str) continue;
        else
        {
            cout<<books[i].GetAuthor()<<"��"<<books[i].GetName()<<"��"<<books[i].GetBookNum()<<"��ʣ�ࡣ"<<endl;
            return ;
        }
    }
    cout<<"δ�ҵ�,�����Ƿ�������ȷ��ISBN��"<<endl;
    return ;
}

//�����ƣ����� 
void Library::SortBookByCode(string str,int choice)//�������,choiceΪ����ȼ� 
{
	if(choice==1) 
    {
    	string str1;
    	for(int i=0;i<this->m_sum;i++)
    	{
    		str1=books[i].GetCode()[0];
    		if(str1==str) cout<<books[i].GetAuthor()<<"��"<<books[i].GetName()<<"��"<<books[i].GetBookNum()<<"��ʣ�ࡣ"<<endl;
		}
	}
	if(choice==2)
	{
		char m_str1,m_str2,str1=str[0],str2=str[1];
    	for(int i=0;i<this->m_sum;i++)
    	{
    		m_str1=books[i].GetCode()[0];
    		m_str2=books[i].GetCode()[1];
    		if(m_str1==str1&&m_str2==str2)
    		{
    			cout<<books[i].GetAuthor()<<"��"<<books[i].GetName()<<"��"<<books[i].GetBookNum()<<"��ʣ�ࡣ"<<endl;
			}
		}
	}
	if(choice==3)
	{
		char m_str1,m_str2,m_str3,str1=str[0],str2=str[1],str3=str[2];
    	for(int i=0;i<this->m_sum;i++)
    	{
    		m_str1=books[i].GetCode()[0];
    		m_str2=books[i].GetCode()[1];
    		m_str3=books[i].GetCode()[2];
    		if(m_str1==str1&&m_str2==str2&&m_str3==str3)
    		{
    			cout<<books[i].GetAuthor()<<"��"<<books[i].GetName()<<"��"<<books[i].GetBookNum()<<"��ʣ�ࡣ"<<endl;
			}
		}
	}

}

//�����ƣ��������� 
void Library::SortBookByAuthor(string str)    //�������߲���
{
	for(int i=0;i<m_user_sum;i++)
	{
		if(books[i].GetAuthor()==str)
		{
			cout<<books[i].GetAuthor()<<"��"<<books[i].GetName()<<"��"<<books[i].GetBookNum()<<"��ʣ�ࡣ"<<endl;
			return ;
		}
	}
	cout<<"δ�ҵ���"<<endl;
	return;
}

void Library::SortBook()//����ͼ���ܺ���
{
	char choice; 
	while(1)
	{ 
		cout<<"��ѡ��������ʽ��"<<endl;
		cout<<"1 ������������ȷ��"<<endl;
		cout<<"2 ����isbn����ȷ��"<<endl;
		cout<<"3 �������ߣ�ģ����"<<endl;
		cout<<"4 ���շ���ţ�ģ����"<<endl;
		cout<<"0 �˳�ϵͳ"<<endl;
		cin>>choice;
		switch(choice)
		{
			case '1':								//ʹ�ô����ţ���ͬ������ 
			{	
				cout<<"������������"<<endl;
				string str1;cin>>str1;
				this->SortBookByName(str1);
				break;
			} 
			case '2':
			{	cout<<"������isbn:"<<endl;
				string str2;cin>>str2;
				this->SortBookByIsbn(str2);
				break;
			} 
			case '3':
			{ 
				cout<<"���������ߣ�"<<endl; 
				string str3;cin>>str3;
				this->SortBookByAuthor(str3);
				break;
			} 
			case '4':
			{ 
				cout<<"���������������ȼ�����1Ϊһ����2Ϊ������3Ϊ������"<<endl;
				string str4;int temp;cin>>str4>>temp;
				this->SortBookByCode(str4,temp);
				break;
			} 
			case '0':
			{
				this->ExitSystem();
			}
			default:
				cout<<"��������ȷ��ţ�"<<endl;
				break; 
		}
			system("pause");   //��ֹ����̫�� 
			system("cls") ;
	} 
}

void Library::BuidUser()//���ļ��ж�ȡuser����
{
	this->users=new User[m_user_sum]; 
	ifstream ifs;
	ifs.open("users.txt",ios::in);
	int account,password,code,i=0;
	while(i<m_user_sum)
	{
		ifs>>account>>password>>code;
		users[i].MakeUser(account,password,code);
		i++;
	}
	ifs.close();
} 

void Library::SaveUser()//����User
{
	ofstream ofs;ofs.open("users.txt",ios::out);
	for(int i=0;i<this->m_user_sum;i++)
	{
		ofs<<users[i].get_Account()<<" "
		   <<users[i].get_PassWord()<<" "
		   <<users[i].get_Code()<<endl;
	}
	ofs.close();
} 

void Library::SaveBook()//����book
{
	ofstream ofs;ofs.open("books.txt",ios::out);
	for(int i=0;i<this->m_sum;i++)
	{
		ofs<<books[i].GetName()<<" "
		   <<books[i].GetIsbn()<<" "
		   <<books[i].GetAuthor()<<" "
		   <<books[i].GetCode()<<" "
		   <<books[i].GetBookNum()<<endl;
	}
	ofs.close();
} 

void Library::SaveRecord()//��records���浽�ļ���
{
	ofstream ofs;ofs.open("records.txt",ios::out);
	for(int i=0;i<this->m_record_sum;i++)
	{
		ofs<<records[i].get_Account()<<" "<<records[i].get_Name()<<endl;	
	}	
}

bool Library::Login(int account,int password,int code)//�ж��˺����������Ƿ���ȷ
{
	if(code==1)
	{
		for(int i=0;i<this->m_user_sum;i++)
		{
			if(users[i].get_Account()==account&&users[i].get_PassWord()==password&&users[i].get_Code()==1)
			{
				cout<<"����ɹ���"<<endl;
				system("pause");   //��ֹ����̫�쿴�������
				return true;
			}
			else continue;
		}
		cout<<"�û���������������������룡"<<endl;
		system("pause");   //��ֹ����̫�쿴�������
		return false; 
	}
	else if(code==2)
	{
		for(int i=0;i<this->m_user_sum;i++)
		{
			if(users[i].get_Account()==account&&users[i].get_PassWord()==password&&users[i].get_Code()==2)
			{
				cout<<"�û���"<<account<<"����ɹ�!"<<endl;
				system("pause");//��ֹ����̫�쿴�������
				return true;
			}
			else continue;
		}
		cout<<"�û���������������������룡"<<endl;
		system("pause");//��ֹ����̫�쿴�������
		return false;
	}
	else 
	{
		cout<<"����ʧ�ܣ��û�������"<<endl;
		system("pause");//��ֹ����̫�쿴�������
		return false; 
	}
}

void Library::ChangePassword(int account)//�޸����� 
{
	int password1,password2;
	cout<<"�����������룺"<<endl;cin>>password1;
	cout<<"��ȷ�������룺"<<endl;cin>>password2;
	if(password1==password2)
	{
		for(int i=0;i<this->m_user_sum;i++)
		{
			if(account==users[i].get_Account())
			{
				users[i].Change_Password(password1);
				cout<<"�޸ĳɹ���"<<endl;
				this->SaveUser();//���浽�ļ� 
				system("pause");//��ֹ����̫�쿴������� 
				return ;
			}
		}
	}
	else
	{
		cout<<"�������벻һ�£�"<<endl; 
		system("pause");//��ֹ����̫�쿴�������
		return ;
	}
} 

void Library::AddUsers()   //�����û� 
{
	cout<<"�������������ӵ��û�������" <<endl;
	int num;cin>>num;
	User *arr=new User[this->m_user_sum+num]; 
	for(int i=0;i<m_user_sum;i++)//��ԭ�����ݸ��Ƶ�������
	{
		arr[i].MakeUser(users[i].get_Account(),users[i].get_PassWord(),users[i].get_Code());
	}
	for(int j=0;j<num;j++)
	{
		cout<<"�������"<<j+1<<"�������û����û�����"<<endl;
		int account,mark=0;cin>>account;
		for(int i=0;i<m_user_sum;i++)//�ж��û����Ƿ��Ѵ��� 
		{
			if(account==users[i].get_Account())
			{
				mark=1;
				break;
			} 
		}
		if(mark==0)
		{
			arr[m_user_sum+j].MakeUser(account,123456,2);
			cout<<"��"<<j+1<<"�û����ӳɹ���"<<endl;
		}
		else
		{
			cout<<"���ʧ�ܣ��û����Ѵ��ڣ�"<<endl;
		}
	}
	//bug:���ʧ�ܻὫ0,0,0���浽�ļ��� 
	m_user_sum=m_user_sum+num;
	delete[] users;users=NULL;
	users=arr;
	this->SaveUser();//��������
	cout<<"�����Ѹ��£�"<<endl; 
	system("pause");//��ֹ����̫�쿴�������
} 


//���� 
void Library::DeleteUsers()//ɾ��user
{
	cout<<"��������Ҫɾ�����û�������"<<endl;
	int num;cin>>num;
	User *arr1=new User[m_user_sum-num];
	int *arr2=new int[num];
	for(int i=0;i<num;i++)
	{
		cout<<"�������"<<i+1<<"����ɾ�����û�����"<<endl;
		cin>>arr2[i];
	}
	int mark=0;
	for(int i=0;i<m_user_sum;i++)
	{
		int flag=0;
		for(int j=0;j<num;j++)//j��д��i 
		{
			if(users[i].get_Account()==arr2[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0) 
		{
			arr1[mark]=users[i] ;
			mark+=1;
		}
		else continue;
	}
	//users���ͷ� 
	m_user_sum-=num;
	delete[] users;
	users=arr1;
	this->SaveUser();
	cout<<"�����Ѹ��£�"<<endl;
	system("pause");//��ֹ����̫�쿴�������
}


//�ѽ��bug���ڴ������m_sum��д��m_user_sum 
void Library::AddBooks()//����ͼ��
{ 
	int num;
    cout<< "��Ҫ��Ӽ����飿"<< endl;
    cin >> num;
    Book *arr=new Book[m_sum+num]; 
	for(int i=0;i<m_sum;i++)//��ԭ�����ݸ��Ƶ�������
	{
		arr[i].MakeBook(books[i].GetName(),books[i].GetIsbn(),books[i].GetAuthor(),books[i].GetCode(),books[i].GetBookNum());
	}
    for(int j=0;j<num;j++)//��� 
	{
		cout<<"�������"<<j+1<<"�������鼮�����֡�isbn�����ߡ�����š�������"<<endl;
		string name,isbn,author,code;int n;
		cin>>name>>isbn>>author>>code>>n;
		arr[m_sum+j].MakeBook(name,isbn,author,code,n);  //!!!�������Ը�򣬴˴�m_sumд����m_user_sum 
		cout<<"��"<<j+1<<"�鼮��ӳɹ���"<<endl;
	}
    m_sum=m_sum+num;
    delete[] books;
    books=arr;
    this->SaveBook();
    cout<<"�����Ѹ��£�"<<endl;
	system("pause");   //��ֹ����̫�쿴�������	
} 


//!!!���� bug!!!
void Library::DeleteBooks()//ɾ��ͼ��
{
	cout<<"����������Ҫɾ����ͼ������"<<endl;
	string name;cin>>name;
	Book* arr=new Book[m_sum-1];
	int mark=-1;
	for(int i=0;i<m_sum;i++)
	{
		if(name==books[i].GetName())
		{
			mark=i;
			break;
		}
	}
	if(mark==-1)
	{
		cout<<"�鼮δ�ҵ�����ȷ��������ȷ��"<<endl;
		system("pause");
		return ;
	}
	else
	{
		int j=0;
		for(int i=0;i<m_sum;i++)
		{
			if(i==mark) continue;
			else
			{
				arr[j]=books[i];
				
				j+=1; 
			}
		}
	}
	//books�ռ��ͷ� 
	m_sum-=1;
	books=arr;
	this->SaveBook();
	cout<<"ɾ���ɹ��������Ѹ��£�"<<endl;
	system("pause");	 
} 
 
void Library::ChangeBookInformation()//�޸�ͼ����Ϣ
{
	cout<<"����������Ҫ�޸ĵ�ԭͼ������"<<endl;
	string name1;cin>>name1;
	for(int i=0;i<m_sum;i++)
	{
		if(books[i].GetName()==name1)
		{
			cout<<"�����������޸ĵ�������isbn,���ߣ�����ţ�������"<<endl;
			string name2,isbn,author,code;int n;
			cin>>name2>>isbn>>author>>code>>n;
			books[i].MakeBook(name2,isbn,author,code,n);
			this->SaveBook(); 
			cout<<"�޸ĳɹ��������Ѹ��£�"<<endl;
			system("pause");
			return ;
		}
	}
	
	cout<<"�鼮δ�ҵ�����ȷ��������ȷ��"<<endl;
	system("pause");
	return ; 
} 

void Library::ResetPassword()//�ָ�Ĭ������
{
	cout<<"����������ָ�Ĭ��������û�����"<<endl;	
	int account;cin>>account;
	for(int i=0;i<m_user_sum;i++)
	{
		if(users[i].get_Account()==account)
		{
			users[i].MakeUser(account,123456,2);
			this->SaveUser();
			cout<<"������ϣ������Ѹ��£�"<<endl;
			system("pause");
			return ;
		}
	}
	//ִ�е����˵��û���ҵ����û� 
	cout<<"δ�ҵ����û���"<<endl;
	system("pause");
	return ;
}

void Library::LookBorrowBooks(int account)//�鿴account���ĵ��鼮 
{
	int mark=0;
	cout<<"�����ڽ���ͼ�飺"<<endl;
	for(int i=0;i<m_record_sum;i++)
	{
		if(records[i].get_Account()==account)
		{
			mark+=1;
			cout<<records[i].get_Name()<<endl;
		}
	} 
	if(mark==0)
	{
		cout<<"�ޣ�"<<endl;
	}
	system("pause");
	return ;
} 

void Library::BorrowBooks(int account)//�˻�account�����鼮 
{
	cout<<"��������Ҫ����鼮������"<<endl;
	int num;cin>>num;
	Record* arr=new Record[m_record_sum+num];
	for(int i=0;i<m_record_sum;i++)
	{
		arr[i].MakeRecord(records[i].get_Account(),records[i].get_Name());
	}
	for(int i=1;i<=num;i++)
	{
		cout<<"�������"<<i<<"��Ҫ����鼮����"<<endl;
		string tempname;cin>>tempname;
		int mark=-1;
		for(int j=0;j<m_sum;j++)
		{
			if(tempname!=books[j].GetName())
			{
				continue;
			}
			else
			{
				mark=j;
				break;
			}
		}
		if(mark==-1)
		{
			cout<<"�����鼮�����ڣ�"<<endl;
			system("pause");
		}
		else
		{
			if(books[mark].GetBookNum()<=0)
			{
				cout<<"�鼮�ѽ��꣡"<<endl;
				system("pause");
			}
			else
			{
				//�������������� 
				books[mark].MakeBook(books[mark].GetName(),books[mark].GetIsbn(),books[mark].GetAuthor(),books[mark].GetCode(),books[i].GetBookNum()-1);
				//���������ݱ���
				arr[m_record_sum+i-1].MakeRecord(account,tempname);
				cout<<"���ĳɹ���"<<endl;
				system("pause");
			}
		}
	}
	m_record_sum+=num;
	delete[] records;
	records=arr;
	this->SaveBook();
	this->SaveRecord();
	cout<<"�����Ѹ��£�"<<endl;
	system("pause");
	return ;
}

void Library::ReturnBook(int account)//�˻�account�黹ͼ��
{
	this->LookBorrowBooks(account);//չʾ�ѽ�ͼ�� 
	cout<<"����������黹���鼮������"<<endl;
	int num;cin>>num;
	string name;
	for(int i=0;i<num;i++)
	{
		cout<<"�������"<<i+1<<"��Ҫ�黹��ͼ��ȫ�ƣ�"<<endl;
		cin>>name;
		for(int j=0;j<m_record_sum;j++)
		{
			if(records[j].get_Name()==name)
			{
				records[j].MakeRecord(0,"temp");
				cout<<"�黹�ɹ���"<<endl;
				system("pause");
				break;	
			}	
		} 
	}
	Record* arr=new Record[m_record_sum-num];
	int mark=0;
	for(int i=0;i<m_record_sum;i++)
	{
		if(records[i].get_Account()!=0)
		{
			arr[mark].MakeRecord(records[i].get_Account(),records[i].get_Name());
			mark+=1;
		}
		else continue;
	}
	m_record_sum-=num;
	delete[] records;
	records=arr;
	cout<<"�����Ѹ���!"<<endl;
	system("pause");
	return ;	
}

void Library::HelpSystem()//����ϵͳ 
{
	int choice;
	while(1)
	{
		this->help.HelpMenu();
		cin>>choice;
		switch(choice)
		{
			case 1:    //�������� 
				this->help.ForgetProblem();
				break;
			case 2:   //����������̫�� 
				this->help.MuchProblem();
				break;
			case 3:   //����δ֪����
				this->help.ReportProblem();
				break;
			case 0:   //�˳�ϵͳ 
				this->ExitSystem(); 
				break;
			default:
				cout<<"��������ȷ��ţ�"<<endl;
				break;
		} 
		system("cls");
	}
}

void Library::Administrator()//����Ա����
{
	//�������Ա
	cout<<"�����������û��������룺"<<endl;
	int account,password;
	cin>>account>>password;
	if(this->Login(account,password,1))  //�ж��Ƿ���ȷ 
	{
		int choice;
		while(1)
		{
			this->ShowAdministratorMenue();
			cout<<"����������ѡ��"<<endl; 
			cin>>choice;
			switch(choice)
			{
				case 1:   //�޸Ĺ���Ա���� 
					this->ChangePassword(account); 
					break;
				case 2:   //����ͼ�� 
					this->SortBook();
					break;
				case 3:   //����û� 
					this->AddUsers();
					break;
				case 4:	  //ɾ���û� 
					this->DeleteUsers();
					break;
				case 5:   //���ͼ�� 
					this->AddBooks();
					break;
				case 6:   //ɾ��ͼ�� 
					this->DeleteBooks();
					break;
				case 7:   //�ָ����û�Ĭ������ 
					this->ResetPassword();
					break;
				case 8:	  //�޸�ͼ����Ϣ 
					this->ChangeBookInformation();
					break; 
				case 0:   //�˳�ϵͳ 
					this->ExitSystem(); 
					break;
				default:
					cout<<"��������ȷ�ı�ţ�"<<endl;
					break;
			}
			system("cls");
		} 
	}
	else ;	
}

void Library::CommonUser()//��ͨ�û����� 
{
	//������ͨ�û�
	cout<<"�����������û��������룺"<<endl;
	int account,password;
	cin>>account>>password;
	if(this->Login(account,password,2))  //�ж��Ƿ���ȷ 
	{
		int choice;
		while(1)
		{
			this->ShowCommonMenue();  //չʾ��ͨ�û��˵� 
			cout<<"����������ѡ��"<<endl; 
			cin>>choice;
			switch(choice)
			{
				case 1:   //�޸��û�����
					this->ChangePassword(account) ;
					break;
				case 2:   //����ͼ�� 
					this->SortBook(); 
					break;
				case 3:   //�鿴����ͼ�� 
					this->LookBorrowBooks(account);
					break;
				case 4:   //�黹ͼ�� 
					this->ReturnBook(account); 
					break;
				case 5:   //����ͼ�� 
					this->BorrowBooks(account);
					break;
				case 0:   //�˳�ϵͳ 
					this->ExitSystem(); 
					break;
				default:
					cout<<"��������ȷ�ı�ţ�"<<endl;
					break;
			}
			system("cls");
		} 
	}
	else ;
} 
