#pragma once
#include<string>

using namespace std;

class User{
	
private:
    int m_account;				//账户
    int m_password;				//密码
    int m_code;					//1为管理员，2为普通用户 
    
public:
    MakeUser(int,int,int);		//给变量赋值 
	
	User(); 
    
    int get_Account();			//获取账户
	
	int get_PassWord();			//获取密码
	
	int get_Code();				//获取识别码 
	
	void Change_Password(int);	//修改密码 
};
