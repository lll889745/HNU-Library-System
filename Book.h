#pragma once
#include<string>
using namespace std;
class Book{
private:
    string m_name;			//����
    string m_author;		//����
    string m_isbn;			//isbn
    string m_code;			//ͼ������
    int m_booknum;			//�鼮���� 
public:
    Book(string,string,string,string);
    
    Book();
    
    void MakeBook(string,string,string,string,int);		//�����������ߵȸ�ֵ
    
    string GetName();
    
    string GetIsbn();
    
    string GetAuthor();
    
    string GetCode();
    
    int GetBookNum();
    
};
