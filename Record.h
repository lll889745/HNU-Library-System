#pragma once
#include<string>
using namespace std;


//将借阅记录集合成一个类 
class Record{
	private:
		int m_account;								//记录借阅人的用户名
		string m_name;								//借阅的书名
	public:
		Record();
		
		void MakeRecord(int account,string name);	//给变量赋值
		
		int get_Account();							//返回变量 
		
		string get_Name(); 							//返回变量 
};
