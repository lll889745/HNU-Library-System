#include<iostream>
#include<string>
#include"User.h"
#include"Library.h"
#pragma once
using namespace std;

User::MakeUser(int account,int password,int code)//�Գ�Ա������ֵ 
{
    m_account=account;
    m_password=password;
    m_code=code;
}

User::User() //�޲ι��� 
{
	
}

int User::get_Account()//��ȡ�˻�
{
	return this->m_account;
}

int User::get_PassWord()//��ȡ����
{
	return this->m_password;
}	
int User::get_Code()//��ȡʶ���� 
{
	return this->m_code;
}

void User::Change_Password(int p)//������ 
{
	this->m_password=p;
} 

