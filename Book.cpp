#pragma once
#include<iostream>
#include<string>
#include"Book.h"
using namespace std;


Book::Book(string name,string isbn,string author,string code) //�вι��� 
{
    m_name=name;
    m_isbn=isbn;
    m_author=author;
    m_code=code;
}

Book::Book()  //�޲� 
{

}

void Book::MakeBook(string name,string isbn,string author,string code,int num) //���鼮������ֵ �������� 
{
    m_name=name,m_isbn=isbn,m_author=author,m_code=code,m_booknum=num;
}

string Book::GetName()//�������� 
{
    return m_name;
}

string Book::GetIsbn()//����isbn 
{
    return m_isbn;
}

string Book::GetAuthor()//�������� 
{
    return m_author;
}

string Book::GetCode()//���ط���� 
{
    return m_code;
}

int Book::GetBookNum()//�����鼮���� 
{
	return m_booknum;
} 
