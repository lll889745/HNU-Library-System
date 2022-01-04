#pragma once
#include<string>
using namespace std;
class Book{
private:
    string m_name;			//书名
    string m_author;		//作者
    string m_isbn;			//isbn
    string m_code;			//图书分类号
    int m_booknum;			//书籍数量 
public:
    Book(string,string,string,string);
    
    Book();
    
    void MakeBook(string,string,string,string,int);		//对书名，作者等赋值
    
    string GetName();
    
    string GetIsbn();
    
    string GetAuthor();
    
    string GetCode();
    
    int GetBookNum();
    
};
