#pragma once
#include"Book.h"
#include"User.h"
#include"Record.h"
#include"Help.h"
class Library{
public:
    Library();							//无参构造，从文件中读取books、users、records 
    
    ~Library();							//析构，解决堆区的数组 
	
    Book* books;						//Book数组
    
    //管理员与普通用户统一，以编号区分 
    User* users;						//user指针数组 
    
    Record* records;					//存储借阅记录数据 
    
    Help help;							//Help为成员 
    
    int m_sum;							//书籍总量
    
    int m_user_sum;						//user的总量 
    
    int m_record_sum;					//record的总量 
    
    void get_BookNum();					//获取书籍总量
	
	void get_UserNum();					//从文件总得到User的数量 
	
	void get_RecordNum();				//从文件中得到record的数量 
    
    void ShowMenue();					//主菜单展示
    
    void ShowAdministratorMenue();		//管理员菜单展示
	
	void ShowCommonMenue();				//普通用户菜单展示 
    
    void ExitSystem();					//退出系统 
    
    void SortBookByName(string str);	//按书名查找
    
    void SortBookByIsbn(string str);	//按isbn
    
    void SortBookByCode(string str,int choice);//按分类号 ,choice为分类等级 
    
    void SortBookByAuthor(string str);	//按作者
    
    void SortBook();					//搜索图书总函数，包含上面四种 
	
	void BuidUser();					//从文件中的数据进行创建用户 
	
	void SaveUser();					//修改或增加User后，将数据保存到文件中
	
	void SaveBook();					//修改或增加book后，将数据保存到文件中 
	
	void SaveRecord();					//将record保存到文件中 
	
	void AddBooks();					//增加book
	
	void AddUsers();					//增加user
	
	void DeleteUsers();					//删除user
	
	void DeleteBooks();					//删除book 
	
	void ChangeBookInformation();		//修改图书的信息
	
	bool Login(int account,int password,int code);//判断账号密码输入是否正确
	
	void ChangePassword(int);			//修改密码 
	
	void ResetPassword();				//恢复默认密码 
	
	void LookBorrowBooks(int account);	//查看account借阅的书籍 
	
	void BorrowBooks(int account);		//账户account借阅书籍 
	
	void ReturnBook(int account);		//账户account归还图书 
	 
	void Administrator();				//管理员 
	
	void CommonUser();					//普通用户
	
	void HelpSystem();					//帮助系统 
	

};
