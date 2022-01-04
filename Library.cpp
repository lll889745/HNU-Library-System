#pragma once
#include<iostream>
#include<string>
#include"Book.h"
#include"Library.h"
#include<fstream>
using namespace std;

Library::Library()			//根据书籍文件、用户文件、借阅记录文件 生成一个图书馆 
{
	this->get_BookNum();	//获取文件中书籍数量赋给m_sum; 
	this->get_UserNum();	//获取文件user数量赋给了m_user_sum 
	this->get_RecordNum();	//获取文件中借阅记录的数量赋给m_record_sum 
    ifstream ifs;  
	
	//书籍创建 
    books=new Book[this->m_sum];
    ifs.open("books.txt",ios::in);
    if(ifs.is_open())		//判断文件是否存在或打开
    {
        int i=0;
        string str,temp1,temp2,temp3,temp4;
        int temp5;			//数量 
        int mark=0;
        while(i<this->m_sum)
        {
            ifs>>temp1>>temp2>>temp3>>temp4>>temp5;
            books[i].MakeBook(temp1,temp2,temp3,temp4,temp5);//读取书籍信息 
            i++;
        }
    }
    else cout<<"books文件未找到！"<<endl;
    ifs.close();
    
    //User创建
	ifs.open("users.txt",ios::in);
	if(ifs.is_open())
	{
		char ch;
		ifs>>ch; 
		if(ifs.eof())//文件中没有数据 ,则自行创建1个管理员帐户，10000个普通用户 
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
			this->SaveUser();//保存到文件 
		}
		else  //文件中有数据 
		{
			ifs.close();
			this->BuidUser();  //调用创建函数 
		} 
	}
	else 
	{
		cout<<"users文件未找到！"<<endl;
		ifs.close();
	}
	
	//Record读取
	records=new Record[m_record_sum];
    ifs.open("records.txt",ios::in);
    if(ifs.is_open())//判断文件是否存在或打开
    {
        int i=0;
        int account;string name;
        while(i<this->m_record_sum)//bug原因m_record_sum用成m_sum 
        {
            ifs>>account>>name;
            records[i].MakeRecord(account,name);//读取record信息 
            i++;
        }
    }
    else cout<<"records文件未找到！"<<endl;
    ifs.close(); 
}

Library::~Library()//析构，处理堆区数据
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
void Library::ShowMenue()//菜单展示
{
    cout << "\t\t\t============== 图~书~管~理~系~统 =============\n";
	cout << "\t\t\t|                1.用户登录                 ｜\n";
	cout << "\t\t\t|                2.管理员登录               ｜\n";
	cout << "\t\t\t|                3.帮助                     ｜\n";
	cout << "\t\t\t|                0.退出                     ｜\n";
	cout << "\t\t\t==============================================\n";
	cout << "欢迎使用图书管理系统！\n请选择功能：\n";
}

void Library::ShowAdministratorMenue()//展示管理员菜单
{
    cout << "\t\t\t================ 管~理~员~面~板 ==============\n";
	cout << "\t\t\t|                1.修改密码                 ｜\n";
	cout << "\t\t\t|                2.搜索图书                 ｜\n";
	cout << "\t\t\t|                3.添加用户                 ｜\n";
	cout << "\t\t\t|                4.删除用户                 ｜\n";
	cout << "\t\t\t|                5.添加图书                 ｜\n";
	cout << "\t\t\t|                6.删除图书                 ｜\n";
	cout << "\t\t\t|                7.重置用户                 ｜\n";
	cout << "\t\t\t|                8.修改图书                 ｜\n";
	cout << "\t\t\t|                0.退出                     ｜\n";
	cout << "\t\t\t==============================================\n";
	cout << "请选择功能：\n";
} 

void Library::ShowCommonMenue()//展示普通用户的菜单
{
    cout << "\t\t\t================= 用~户~面~板 ================\n";
	cout << "\t\t\t|                1.修改密码                 ｜\n";
	cout << "\t\t\t|                2.搜索图书                 ｜\n";
	cout << "\t\t\t|                3.查看借阅记录             ｜\n";
	cout << "\t\t\t|                4.归还图书                 ｜\n";
	cout << "\t\t\t|                5.借阅图书                 ｜\n";
	cout << "\t\t\t|                0.退出                     ｜\n";
	cout << "\t\t\t==============================================\n";
	cout << "请选择功能：\n";
} 
 
void Library::ExitSystem()//退出系统， 
{
	cout<<"欢迎下次使用！"<<endl;
	system("pause");
	exit(0);
}

void Library::get_BookNum()//获取文件中的书籍数量
{
	m_sum=0;
	ifstream ifs;
	ifs.open("books.txt",ios::in);
	if(!ifs.is_open()) cout<<"文件不存在！"<<endl;
	else
	{
		char ch;ifs>>ch;
		if(ifs.eof()) m_sum=0;    //判断是否是空文件 
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

void Library::get_UserNum()//从 users.txt 中获取user数量
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
		cout<<"users文件不存在！"<<endl;
		ifs.close();
	}
	return ;
} 

void Library::get_RecordNum()//从文件中得到record的数量 
{
	ifstream ifs;
	ifs.open("records.txt",ios::in);
	this->m_record_sum=0;
	if(ifs.is_open())//判断文件是否打开 
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
		cout<<"records文件不存在！"<<endl;
		ifs.close();
	}
	return ;
}

void Library::SortBookByName(string str)//书名查找
{
    for(int i=0;i<m_sum;i++)
    {
        if(books[i].GetName()!=str) continue;
        else
        {
            cout<<books[i].GetAuthor()<<"的"<<books[i].GetName()<<"有"<<books[i].GetBookNum()<<"本剩余。"<<endl;
            return ;
        }
    }
    cout<<"未找到,请检查是否输入正确的书名！"<<endl;
}

void Library::SortBookByIsbn(string str)//按isbn
{
    for(int i=0;i<m_sum;i++)
    {
        if(books[i].GetIsbn()!=str) continue;
        else
        {
            cout<<books[i].GetAuthor()<<"的"<<books[i].GetName()<<"有"<<books[i].GetBookNum()<<"本剩余。"<<endl;
            return ;
        }
    }
    cout<<"未找到,请检查是否输入正确的ISBN！"<<endl;
    return ;
}

//待完善！！！ 
void Library::SortBookByCode(string str)//按分类号,choice为分类等级 
{
	if(str.size()==1) 
    {
    	string str1;
    	for(int i=0;i<this->m_sum;i++)
    	{
    		str1=books[i].GetCode()[0];
    		if(str1==str) cout<<books[i].GetAuthor()<<"的"<<books[i].GetName()<<"有"<<books[i].GetBookNum()<<"本剩余。"<<endl;
		}
	}
	if(str.size()==2)
	{
		char m_str1,m_str2,str1=str[0],str2=str[1];
    	for(int i=0;i<this->m_sum;i++)
    	{
    		m_str1=books[i].GetCode()[0];
    		m_str2=books[i].GetCode()[1];
    		if(m_str1==str1&&m_str2==str2)
    		{
    			cout<<books[i].GetAuthor()<<"的"<<books[i].GetName()<<"有"<<books[i].GetBookNum()<<"本剩余。"<<endl;
			}
		}
	}
	if(str.size()==3)
	{
		char m_str1,m_str2,m_str3,str1=str[0],str2=str[1],str3=str[2];
    	for(int i=0;i<this->m_sum;i++)
    	{
    		m_str1=books[i].GetCode()[0];
    		m_str2=books[i].GetCode()[1];
    		m_str3=books[i].GetCode()[2];
    		if(m_str1==str1&&m_str2==str2&&m_str3==str3)
    		{
    			cout<<books[i].GetAuthor()<<"的"<<books[i].GetName()<<"有"<<books[i].GetBookNum()<<"本剩余。"<<endl;
			}
		}
	}

}

//待完善！！！！！ 
void Library::SortBookByAuthor(string str)    //按照作者查找
{
	for(int i=0;i<m_user_sum;i++)
	{
		if(books[i].GetAuthor()==str)
		{
			cout<<books[i].GetAuthor()<<"的"<<books[i].GetName()<<"有"<<books[i].GetBookNum()<<"本剩余。"<<endl;
			return ;
		}
	}
	cout<<"未找到！"<<endl;
	return;
}

void Library::SortBook()//搜索图书总函数
{
	char choice; 
	while(1)
	{ 
		cout<<"请选择搜索方式："<<endl;
		cout<<"1 按照书名（精确）"<<endl;
		cout<<"2 按照isbn（精确）"<<endl;
		cout<<"3 按照作者（模糊）"<<endl;
		cout<<"4 按照分类号（模糊）"<<endl;
		cout<<"0 退出系统"<<endl;
		cin>>choice;
		switch(choice)
		{
			case '1':								//使用大括号，有同名变量 
			{	
				cout<<"请输入书名："<<endl;
				string str1;cin>>str1;
				this->SortBookByName(str1);
				break;
			} 
			case '2':
			{	cout<<"请输入isbn:"<<endl;
				string str2;cin>>str2;
				this->SortBookByIsbn(str2);
				break;
			} 
			case '3':
			{ 
				cout<<"请输入作者："<<endl; 
				string str3;cin>>str3;
				this->SortBookByAuthor(str3);
				break;
			} 
			case '4':
			{ 
				cout<<"请输入分类号与分类等级：（1为一级，2为二级，3为三级）"<<endl;
				string str4;cin>>str4;
				this->SortBookByCode(str4);
				break;
			} 
			case '0':
			{
				this->ExitSystem();
			}
			default:
				cout<<"请输入正确编号！"<<endl;
				break; 
		}
			system("pause");   //防止清屏太快 
			system("cls") ;
	} 
}

void Library::BuidUser()//从文件中读取user数据
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

void Library::SaveUser()//保存User
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

void Library::SaveBook()//保存book
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

void Library::SaveRecord()//将records保存到文件中
{
	ofstream ofs;ofs.open("records.txt",ios::out);
	for(int i=0;i<this->m_record_sum;i++)
	{
		ofs<<records[i].get_Account()<<" "<<records[i].get_Name()<<endl;	
	}	
}

bool Library::Login(int account,int password,int code)//判断账号密码输入是否正确
{
	if(code==1)
	{
		for(int i=0;i<this->m_user_sum;i++)
		{
			if(users[i].get_Account()==account&&users[i].get_PassWord()==password&&users[i].get_Code()==1)
			{
				cout<<"登入成功！"<<endl;
				system("pause");   //防止清屏太快看不到输出
				return true;
			}
			else continue;
		}
		cout<<"用户名或密码错误，请重新输入！"<<endl;
		system("pause");   //防止清屏太快看不到输出
		return false; 
	}
	else if(code==2)
	{
		for(int i=0;i<this->m_user_sum;i++)
		{
			if(users[i].get_Account()==account&&users[i].get_PassWord()==password&&users[i].get_Code()==2)
			{
				cout<<"用户："<<account<<"登入成功!"<<endl;
				system("pause");//防止清屏太快看不到输出
				return true;
			}
			else continue;
		}
		cout<<"用户名或密码错误，请重新输入！"<<endl;
		system("pause");//防止清屏太快看不到输出
		return false;
	}
	else 
	{
		cout<<"登入失败，用户不存在"<<endl;
		system("pause");//防止清屏太快看不到输出
		return false; 
	}
}

void Library::ChangePassword(int account)//修改密码 
{
	int password1,password2;
	cout<<"请输入新密码："<<endl;cin>>password1;
	cout<<"请确认新密码："<<endl;cin>>password2;
	if(password1==password2)
	{
		for(int i=0;i<this->m_user_sum;i++)
		{
			if(account==users[i].get_Account())
			{
				users[i].Change_Password(password1);
				cout<<"修改成功！"<<endl;
				this->SaveUser();//保存到文件 
				system("pause");//防止清屏太快看不到输出 
				return ;
			}
		}
	}
	else
	{
		cout<<"两次密码不一致！"<<endl; 
		system("pause");//防止清屏太快看不到输出
		return ;
	}
} 

void Library::AddUsers()   //增加用户 
{
	cout<<"请输入您想增加的用户数量：" <<endl;
	int num;cin>>num;
	User *arr=new User[this->m_user_sum+num]; 
	for(int i=0;i<m_user_sum;i++)//将原有数据复制到新数组
	{
		arr[i].MakeUser(users[i].get_Account(),users[i].get_PassWord(),users[i].get_Code());
	}
	for(int j=0;j<num;j++)
	{
		cout<<"请输入第"<<j+1<<"个新增用户的用户名："<<endl;
		int account,mark=0;cin>>account;
		for(int i=0;i<m_user_sum;i++)//判断用户名是否已存在 
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
			cout<<"第"<<j+1<<"用户增加成功！"<<endl;
		}
		else
		{
			cout<<"添加失败！用户名已存在！"<<endl;
		}
	}
	//bug:添加失败会将0,0,0保存到文件； 
	m_user_sum=m_user_sum+num;
	delete[] users;users=NULL;
	users=arr;
	this->SaveUser();//保存数据
	cout<<"数据已更新！"<<endl; 
	system("pause");//防止清屏太快看不到输出
} 


//闪退 
void Library::DeleteUsers()//删除user
{
	cout<<"请输入想要删除的用户数量："<<endl;
	int num;cin>>num;
	User *arr1=new User[m_user_sum-num];
	int *arr2=new int[num];
	for(int i=0;i<num;i++)
	{
		cout<<"请输入第"<<i+1<<"个想删除的用户名："<<endl;
		cin>>arr2[i];
	}
	int mark=0;
	for(int i=0;i<m_user_sum;i++)
	{
		int flag=0;
		for(int j=0;j<num;j++)//j误写成i 
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
	//users的释放 
	m_user_sum-=num;
	delete[] users;
	users=arr1;
	this->SaveUser();
	cout<<"数据已更新！"<<endl;
	system("pause");//防止清屏太快看不到输出
}


//已解决bug，内存溢出，m_sum误写成m_user_sum 
void Library::AddBooks()//增加图书
{ 
	int num;
    cout<< "您要添加几本书？"<< endl;
    cin >> num;
    Book *arr=new Book[m_sum+num]; 
	for(int i=0;i<m_sum;i++)//将原有数据复制到新数组
	{
		arr[i].MakeBook(books[i].GetName(),books[i].GetIsbn(),books[i].GetAuthor(),books[i].GetCode(),books[i].GetBookNum());
	}
    for(int j=0;j<num;j++)//添加 
	{
		cout<<"请输入第"<<j+1<<"个新增书籍的名字、isbn、作者、分类号、数量："<<endl;
		string name,isbn,author,code;int n;
		cin>>name>>isbn>>author>>code>>n;
		arr[m_sum+j].MakeBook(name,isbn,author,code,n);  //!!!程序崩溃愿因，此处m_sum写成了m_user_sum 
		cout<<"第"<<j+1<<"书籍添加成功！"<<endl;
	}
    m_sum=m_sum+num;
    delete[] books;
    books=arr;
    this->SaveBook();
    cout<<"数据已更新！"<<endl;
	system("pause");   //防止清屏太快看不到输出	
} 


//!!!闪退 bug!!!
void Library::DeleteBooks()//删除图书
{
	cout<<"请输入您想要删除的图书名："<<endl;
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
		cout<<"书籍未找到！请确保输入正确！"<<endl;
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
	//books空间释放 
	m_sum-=1;
	books=arr;
	this->SaveBook();
	cout<<"删除成功！数据已更新！"<<endl;
	system("pause");	 
} 
 
void Library::ChangeBookInformation()//修改图书信息
{
	cout<<"请输入您想要修改的原图书名："<<endl;
	string name1;cin>>name1;
	for(int i=0;i<m_sum;i++)
	{
		if(books[i].GetName()==name1)
		{
			cout<<"请输入重新修改的书名，isbn,作者，分类号，数量："<<endl;
			string name2,isbn,author,code;int n;
			cin>>name2>>isbn>>author>>code>>n;
			books[i].MakeBook(name2,isbn,author,code,n);
			this->SaveBook(); 
			cout<<"修改成功！数据已更新！"<<endl;
			system("pause");
			return ;
		}
	}
	
	cout<<"书籍未找到！请确保输入正确！"<<endl;
	system("pause");
	return ; 
} 

void Library::ResetPassword()//恢复默认密码
{
	cout<<"请输入您想恢复默认密码的用户名："<<endl;	
	int account;cin>>account;
	for(int i=0;i<m_user_sum;i++)
	{
		if(users[i].get_Account()==account)
		{
			users[i].MakeUser(account,123456,2);
			this->SaveUser();
			cout<<"更改完毕！数据已更新！"<<endl;
			system("pause");
			return ;
		}
	}
	//执行到这里，说明没有找到改用户 
	cout<<"未找到该用户！"<<endl;
	system("pause");
	return ;
}

void Library::LookBorrowBooks(int account)//查看account借阅的书籍 
{
	int mark=0;
	cout<<"您现在借有图书："<<endl;
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
		cout<<"无！"<<endl;
	}
	system("pause");
	return ;
} 

void Library::BorrowBooks(int account)//账户account借阅书籍 
{
	cout<<"请输入您要借的书籍数量："<<endl;
	int num;cin>>num;
	Record* arr=new Record[m_record_sum+num];
	for(int i=0;i<m_record_sum;i++)
	{
		arr[i].MakeRecord(records[i].get_Account(),records[i].get_Name());
	}
	for(int i=1;i<=num;i++)
	{
		cout<<"请输入第"<<i<<"本要借的书籍名字"<<endl;
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
			cout<<"所借书籍不存在！"<<endl;
			system("pause");
		}
		else
		{
			if(books[mark].GetBookNum()<=0)
			{
				cout<<"书籍已借完！"<<endl;
				system("pause");
			}
			else
			{
				//更新所借书数量 
				books[mark].MakeBook(books[mark].GetName(),books[mark].GetIsbn(),books[mark].GetAuthor(),books[mark].GetCode(),books[i].GetBookNum()-1);
				//将借阅数据保存
				arr[m_record_sum+i-1].MakeRecord(account,tempname);
				cout<<"借阅成功！"<<endl;
				system("pause");
			}
		}
	}
	m_record_sum+=num;
	delete[] records;
	records=arr;
	this->SaveBook();
	this->SaveRecord();
	cout<<"数据已更新！"<<endl;
	system("pause");
	return ;
}

void Library::ReturnBook(int account)//账户account归还图书
{
	this->LookBorrowBooks(account);//展示已借图书 
	cout<<"请输入您想归还的书籍数量："<<endl;
	int num;cin>>num;
	string name;
	for(int i=0;i<num;i++)
	{
		cout<<"请输入第"<<i+1<<"本要归还的图书全称："<<endl;
		cin>>name;
		for(int j=0;j<m_record_sum;j++)
		{
			if(records[j].get_Name()==name)
			{
				records[j].MakeRecord(0,"temp");
				cout<<"归还成功！"<<endl;
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
	cout<<"数据已更新!"<<endl;
	system("pause");
	return ;	
}

void Library::HelpSystem()//帮助系统 
{
	int choice;
	while(1)
	{
		this->help.HelpMenu();
		cin>>choice;
		switch(choice)
		{
			case 1:    //忘记密码 
				this->help.ForgetProblem();
				break;
			case 2:   //密码输错次数太多 
				this->help.MuchProblem();
				break;
			case 3:   //报告未知问题
				this->help.ReportProblem();
				break;
			case 0:   //退出系统 
				this->ExitSystem(); 
				break;
			default:
				cout<<"请输入正确编号："<<endl;
				break;
		} 
		system("cls");
	}
}

void Library::Administrator()//管理员函数
{
	//登入管理员
	cout<<"请输入您的用户名与密码："<<endl;
	int account,password;
	cin>>account>>password;
	if(this->Login(account,password,1))  //判断是否正确 
	{
		int choice;
		while(1)
		{
			this->ShowAdministratorMenue();
			cout<<"请输入您的选择："<<endl; 
			cin>>choice;
			switch(choice)
			{
				case 1:   //修改管理员密码 
					this->ChangePassword(account); 
					break;
				case 2:   //搜索图书 
					this->SortBook();
					break;
				case 3:   //添加用户 
					this->AddUsers();
					break;
				case 4:	  //删除用户 
					this->DeleteUsers();
					break;
				case 5:   //添加图书 
					this->AddBooks();
					break;
				case 6:   //删除图书 
					this->DeleteBooks();
					break;
				case 7:   //恢复复用户默认密码 
					this->ResetPassword();
					break;
				case 8:	  //修改图书信息 
					this->ChangeBookInformation();
					break; 
				case 0:   //退出系统 
					this->ExitSystem(); 
					break;
				default:
					cout<<"请输入正确的编号！"<<endl;
					break;
			}
			system("cls");
		} 
	}
	else ;	
}

void Library::CommonUser()//普通用户函数 
{
	//登入普通用户
	cout<<"请输入您的用户名与密码："<<endl;
	int account,password;
	cin>>account>>password;
	if(this->Login(account,password,2))  //判断是否正确 
	{
		int choice;
		while(1)
		{
			this->ShowCommonMenue();  //展示普通用户菜单 
			cout<<"请输入您的选择："<<endl; 
			cin>>choice;
			switch(choice)
			{
				case 1:   //修改用户密码
					this->ChangePassword(account) ;
					break;
				case 2:   //搜索图书 
					this->SortBook(); 
					break;
				case 3:   //查看借阅图书 
					this->LookBorrowBooks(account);
					break;
				case 4:   //归还图书 
					this->ReturnBook(account); 
					break;
				case 5:   //借阅图书 
					this->BorrowBooks(account);
					break;
				case 0:   //退出系统 
					this->ExitSystem(); 
					break;
				default:
					cout<<"请输入正确的编号！"<<endl;
					break;
			}
			system("cls");
		} 
	}
	else ;
} 
