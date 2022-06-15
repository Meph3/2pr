#ifndef String_hpp
#define String_hpp

#include <iostream>
using namespace std;

class String {
private:
    static int copy_string; //счетчик конструктора копирования класса
protected:
    char* str; //указатель на строку
    int length; //длина строки
public:
    String();//конструктор без параметров
    String(char* p);//конструктор с параметром Си-Строка
    String(char c);//конструктор с параместром Символ
    String(const String& k);//конструктор копирования
    ~String();//деструктор

    String& operator=(const String& k);//перегрузка оператора приравнивания

    friend ostream& operator << (ostream& stream, String& str);//перегрузка оператора вывода

    int Get_length();//функция получения длины
};
class IdentifierString : public String {
private:
    static int copy_is;//счетчик функции копирования класса
public:
    IdentifierString();//конструктор без параметров
    IdentifierString(char* p);//конструктор с параметром Си-Строка
    IdentifierString(const IdentifierString& k);//конструктор копирования
    ~IdentifierString();//деструктор

    friend void operator<(const IdentifierString& left, char symbol);//перегрузка оператора < для нахождения первого вхождения
    IdentifierString& operator=(const IdentifierString& k);//перегрузка оператора =

    friend ostream& operator << (ostream& stream, IdentifierString& str);//перегрузка оператора вывода
};
class DecString : public String {
private:
    static int copy_ds;
public:
    DecString();//конструктор без параметров
    DecString(char* p);//конструктор с параметрами
    DecString(const DecString& k);//конструктор копирования
    ~DecString();//деструктор

    bool form_int();//проверка на возможность представления десятичной строк в формате int

    friend bool operator> (const DecString& left, const DecString& right);//сравнение десятичных строк
    friend void operator- (const DecString& left, const DecString& right);//вычитаение десятичных строк
    DecString& operator= (const DecString& k);//перегрузка оператора =

    friend ostream& operator << (ostream& stream, DecString& str);//перегрузка оператора вывода
};

#endif /* String_hpp */