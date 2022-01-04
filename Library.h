#pragma once
#include"Book.h"
#include"User.h"
#include"Record.h"
#include"Help.h"
class Library{
public:
    Library();							//�޲ι��죬���ļ��ж�ȡbooks��users��records 
    
    ~Library();							//������������������� 
	
    Book* books;						//Book����
    
    //����Ա����ͨ�û�ͳһ���Ա������ 
    User* users;						//userָ������ 
    
    Record* records;					//�洢���ļ�¼���� 
    
    Help help;							//HelpΪ��Ա 
    
    int m_sum;							//�鼮����
    
    int m_user_sum;						//user������ 
    
    int m_record_sum;					//record������ 
    
    void get_BookNum();					//��ȡ�鼮����
	
	void get_UserNum();					//���ļ��ܵõ�User������ 
	
	void get_RecordNum();				//���ļ��еõ�record������ 
    
    void ShowMenue();					//���˵�չʾ
    
    void ShowAdministratorMenue();		//����Ա�˵�չʾ
	
	void ShowCommonMenue();				//��ͨ�û��˵�չʾ 
    
    void ExitSystem();					//�˳�ϵͳ 
    
    void SortBookByName(string str);	//����������
    
    void SortBookByIsbn(string str);	//��isbn
    
    void SortBookByCode(string str,int choice);//������� ,choiceΪ����ȼ� 
    
    void SortBookByAuthor(string str);	//������
    
    void SortBook();					//����ͼ���ܺ����������������� 
	
	void BuidUser();					//���ļ��е����ݽ��д����û� 
	
	void SaveUser();					//�޸Ļ�����User�󣬽����ݱ��浽�ļ���
	
	void SaveBook();					//�޸Ļ�����book�󣬽����ݱ��浽�ļ��� 
	
	void SaveRecord();					//��record���浽�ļ��� 
	
	void AddBooks();					//����book
	
	void AddUsers();					//����user
	
	void DeleteUsers();					//ɾ��user
	
	void DeleteBooks();					//ɾ��book 
	
	void ChangeBookInformation();		//�޸�ͼ�����Ϣ
	
	bool Login(int account,int password,int code);//�ж��˺����������Ƿ���ȷ
	
	void ChangePassword(int);			//�޸����� 
	
	void ResetPassword();				//�ָ�Ĭ������ 
	
	void LookBorrowBooks(int account);	//�鿴account���ĵ��鼮 
	
	void BorrowBooks(int account);		//�˻�account�����鼮 
	
	void ReturnBook(int account);		//�˻�account�黹ͼ�� 
	 
	void Administrator();				//����Ա 
	
	void CommonUser();					//��ͨ�û�
	
	void HelpSystem();					//����ϵͳ 
	

};
