#pragma once
#include<string>
using namespace std;


//�����ļ�¼���ϳ�һ���� 
class Record{
	private:
		int m_account;								//��¼�����˵��û���
		string m_name;								//���ĵ�����
	public:
		Record();
		
		void MakeRecord(int account,string name);	//��������ֵ
		
		int get_Account();							//���ر��� 
		
		string get_Name(); 							//���ر��� 
};
