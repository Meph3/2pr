#include "Strings.hpp"
#include <iostream>
#include <string>
#include "string.h"
using namespace std;

//MARK: Описание методов класса String
int String::copy_string = 0;
String::String() {
    cout << "Конструктор без параметров класса Строка" << endl;
    this->str = 0;
    this->length = 0;
}
String::String(char* p) {
    cout << "Конструктор класса Строка, принимающий в качестве параметра СИ-Строку" << endl;
    int n = strlen(p); //получение длины строки
    this->str = new char[n + 1]; //выделение динамически памяти
    this->length = n;
    strcpy_s(this->str, p);
    
}
String::String(char c) {
    cout << "Конструктор класса Строка, принимающий в качестве параметра Символ" << endl;
    this->str = new char[2];
    this->str[0] = c;
    this->str[1] = '\0';
    this->length = 1;
}
String::String(const String& k) {
    String::copy_string++;
    cout << "Конструктор копирования класса Строка. Количество вызовов = " << String::copy_string << endl;
    this->str = new char[k.length + 1];
    this->length = k.length;
    strcpy(this->str, k.str);
}
String::~String() {
    cout << "Деструктор класса Строка" << endl;
    delete[] str;
}
String& String::operator=(const String& k) {
    cout << "Перегрузка оператора = в классе Строка" << endl;
    this->str = new char[k.length + 1];
    this->length = k.length;
    strcpy(this->str, k.str);
    return *this;
}
int String::Get_length() {
    cout << "Получение длины строки класса Строка" << endl;
    return this->length;
}
ostream& operator <<(ostream& stream, String& str) {
    int i;
    for (i = 0; i < str.length; i++) {
        stream << str.str[i];
    }
    stream << endl;
    return stream;
}

//MARK: Описание методов класса IdentifierString
int IdentifierString::copy_is = 0;
IdentifierString::IdentifierString() : String() {
    cout << "Конструктор без параметров класса Строка-Идентификатор" << endl;
    this->str = 0;
    this->length = 0;
}
IdentifierString::IdentifierString(char* p) : String(p) {
    cout << "Конструктор класса Строка-Идентификатор, принимающий в качестве параметра Си-Строку" << endl;
    bool canCopy = true;
    int i;
    char arr[51][10] = { "bool","case","catch","char","char8_t","char16_t","char32_t",
        "class","const","continue","default","delete","do","double","else",
        "enum","extern","false","float","for","friend","if","inline","int","long",
        "namespace","new","nullptr","operator","protected","public","private","return",
        "short","signed","sizeof","static","struct","switch","template","this","throw",
        "true","try","typedef","union","unsigned","using","virtual","void","while" };
    for (i = 0; i < 51; i++) { //сравнение со всеми ключевыми словами
        if (!strcmp(p, arr[i])) {
            cout << "Неверный идентификатор" << endl;
            canCopy = false;
            break;
        }
    }
    if ((p[0] >= 65 && p[0] <= 90) || (p[0] >= 97 && p[0] <= 122)) { //проверка условий для идентификатора
        for (i = 1; i < strlen(p); i++) {
            if (p[i] < 48 || (p[i] > 57 && p[i] < 65) || (p[i] > 90 && p[i] < 97 && p[i] != 95) || p[i]>122) {
                cout << "Неверный идентификатор" << endl;
                canCopy = false;
                break;
            }
        }
    }
    else {
        canCopy = false;
    }
    int n = strlen(p);
    this->str = new char[n + 1];
    this->length = n;
    cin >> 
    if (canCopy) {
        strcpy(this->str, p);
    }
    else {
        for (i = 0; i < n + 1; i++) {
            str[i] = '\0';
        }
    }
}
IdentifierString::IdentifierString(const IdentifierString& k) : String(k) {
    IdentifierString::copy_is++;
    cout << "Конструктор копирования класса Строка-Идентификатор. Количество вызовов = " << IdentifierString::copy_is << endl;
    int n = strlen(k.str);
    this->str = new char[n + 1];
    this->length = n;
    strcpy(this->str, k.str);
}
IdentifierString::~IdentifierString() {
    cout << "Деструктор класса Строка-Идентификатор" << endl;
}
void operator<(const IdentifierString& left, char symbol) {
    cout << "Перегрузка оператора < в классе Строка-Идентификатор(нахождение первого вхождения)" << endl;
    char* pos = nullptr;
    int i;
    for (i = 0; i < strlen(left.str); i++) { //поиск первого вхождения
        if (left.str[i] == symbol) { //если находят нужный символ в строке, тогда передается его адрес и останавливается цикл
            pos = &left.str[i];
            break;
        }
    }
    if (pos == nullptr) { //проверка найден ли символ или нет
        cout << "Символ в строке не найден" << endl;
    }
    else {
        cout << "Первое вхождение искомого символа в строке на позиции #" << pos - left.str + 1 << endl;
    }
}
IdentifierString& IdentifierString::operator=(const IdentifierString& k) {
    cout << "Перегрузка оператора = в классе Строка-Идентификатор" << endl;
    int i;
    this->str = new char[k.length + 1];
    this->length = k.length;
    strcpy(this->str, k.str);
    return *this;
}
ostream& operator <<(ostream& stream, IdentifierString& str) {
    int i;
    for (i = 0; i < str.length; i++) {
        stream << str.str[i];
    }
    stream << endl;
    return stream;
}

//MARK: Описание методов класса DecString
int DecString::copy_ds = 0;
DecString::DecString() : String() {
    cout << "Конструктор без параметров класса Десятичная строка" << endl;
    this->str = 0;
    this->length = 0;
}
DecString::DecString(char* p) : String(p) {
    cout << "Конструктор класса Десятичная строка, принимающая в качестве параметра Си-Строку" << endl;
    bool canCopy = false;
    int i, n = strlen(p);
    if (p[0] == 43 || p[0] == 45) { //проверка условий ввода десятичной строки
        canCopy = true;
        if (p[1] != 48) {
            for (i = 2; i < n; i++) {
                if (p[i] < 48 || p[i]>57) {
                    canCopy = false;
                    break;
                }
            }
        }
        else {
            canCopy = false;
        }
    }
    else if (p[0] >= 49 && p[0] <= 57) {
        canCopy = true;
        for (i = 1; i < n; i++) {
            if (p[i] < 48 || p[i]>57) {
                canCopy = false;
                break;
            }
        }
    }
    else {
        canCopy = false;
    }
    this->str = new char[n + 1];
    this->length = n;
    if (canCopy) { //обнуление если условия ввода не выполнены
        strcpy(this->str, p);
    }
    else {
        for (i = 0; i < n + 1; i++) {
            str[i] = '\0';
        }
    }
}
DecString::DecString(const DecString& k) : String(k) {
    DecString::copy_ds++;
    cout << "Конструктор копирования класса Десятичная строка. Количество вызовов = " << DecString::copy_ds << endl;
    int n = strlen(k.str);
    this->str = new char[n + 1];
    this->length = n;
    strcpy(this->str, k.str);
}
DecString::~DecString() {
    cout << "Деструктор класса Десятичная строка" << endl;
}
bool DecString::form_int() {
    long int number;
    number = atol(this->str);
    if (number > INT_MAX || number < INT_MIN) {
        return false;
    }
    else {
        return true;
    }
}
bool operator>(const DecString& left, const DecString& right) {
    long int first, second;
    first = atol(left.str); //перевод строк в числа
    second = atol(right.str);
    if (first > second) { //сравнение чисел
        return true;
    }
    else if (second > first) {
        return false;
    }
    else {
        cout << "Числа равны" << endl;
        return false;
    }
}
void operator-(const DecString& left, const DecString& right) {
    long int first, second;
    first = atol(left.str);//перевод строк в числа
    second = atol(right.str);
    first -= second; //вычитание из 1 строки 2
    DecString* b = new DecString();
    if (left.length >= right.length) { //проверка на длину строк, для выделения памяти под результирующую строку
        b->length = left.length;
        b->str = new char[left.length + 1];
    }
    else {
        b->length = right.length;
        b->str = new char[right.length + 1];
    }
    printf(b->str, "%ld", first);//перевод числа в строку
    //b->str = to_string(first).c_str();
    cout << "Результат: " << *b; //вывод результата
}
DecString& DecString::operator=(const DecString& k) {
    cout << "Перегрузка оператора = в классе Десятичная строка" << endl;
    int i;
    this->str = new char[k.length + 1];
    for (i = 0; i < strlen(k.str); i++) {
        this->str[i] = k.str[i];
    }
    this->length = k.length;
    return *this;
}
ostream& operator <<(ostream& stream, DecString& str) {
    int i;
    for (i = 0; i < str.length; i++) {
        stream << str.str[i];
    }
    stream << endl;
    return stream;
}