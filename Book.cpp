#pragma once
#include<iostream>
#include<string>
#include"Book.h"
using namespace std;


Book::Book(string name,string isbn,string author,string code) //有参构造 
{
    m_name=name;
    m_isbn=isbn;
    m_author=author;
    m_code=code;
}

Book::Book()  //无参 
{

}

void Book::MakeBook(string name,string isbn,string author,string code,int num) //对书籍变量赋值 ，更常用 
{
    m_name=name,m_isbn=isbn,m_author=author,m_code=code,m_booknum=num;
}

string Book::GetName()//返回书名 
{
    return m_name;
}

string Book::GetIsbn()//返回isbn 
{
    return m_isbn;
}

string Book::GetAuthor()//返回作者 
{
    return m_author;
}

string Book::GetCode()//返回分类号 
{
    return m_code;
}

int Book::GetBookNum()//返回书籍数量 
{
	return m_booknum;
} 
