#pragma once
#include"Record.h"
#include<string>

using namespace std;

int Record::get_Account()
{
	return m_account;
}

string Record::get_Name()
{
	return m_name;
}

Record::Record()
{
	
}

void Record::MakeRecord(int account,string name)
{
	m_account=account,m_name=name;
}

 
