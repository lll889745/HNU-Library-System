#pragma once
#include<string>

using namespace std;

class User{
	
private:
    int m_account;				//�˻�
    int m_password;				//����
    int m_code;					//1Ϊ����Ա��2Ϊ��ͨ�û� 
    
public:
    MakeUser(int,int,int);		//��������ֵ 
	
	User(); 
    
    int get_Account();			//��ȡ�˻�
	
	int get_PassWord();			//��ȡ����
	
	int get_Code();				//��ȡʶ���� 
	
	void Change_Password(int);	//�޸����� 
};
