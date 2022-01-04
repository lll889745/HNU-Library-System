#include<iostream>
#include<string>
#include"User.h"
#include"Library.h"
#pragma once
using namespace std;

User::MakeUser(int account,int password,int code)//对成员变量赋值 
{
    m_account=account;
    m_password=password;
    m_code=code;
}

User::User() //无参构造 
{
	
}

int User::get_Account()//获取账户
{
	return this->m_account;
}

int User::get_PassWord()//获取密码
{
	return this->m_password;
}	
int User::get_Code()//获取识别码 
{
	return this->m_code;
}

void User::Change_Password(int p)//改密码 
{
	this->m_password=p;
} 

