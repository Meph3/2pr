#include <stdio.h>
#include <iostream>
#include <cstring>
#include "Strings.hpp"
#define _CRT_SECURE_NO_WARNINGS
int main() {
    int count = 0, menu1, menu2, menu3, i = 0, ele;
    char* p = new char[1000];
    bool canWork = false;
    String** strings;
    do {
        system("clear");
        cout << "1.Инициализация" << endl;
        cout << "2.Тестирование" << endl;
        cout << "3.Выход" << endl;
        cin >> menu1;
        switch (menu1) {
        case 1:
            do {
                system("clear");
                cout << "1.Число элементов" << endl;
                cout << "2.Начальное значение" << endl;
                cout << "3.Выход" << endl;
                cin >> menu2;
                switch (menu2) {
                case 1:
                    system("clear");
                    cout << "Введите кол-во элементов: ";
                    cin >> count;
                    strings = new String * [count];
                    canWork = true;
                    break;
                case 2:
                    if (canWork) {
                        system("clear");
                        do {
                            cout << "Выберите тип элемента " << i + 1 << endl;
                            cout << "1.Строка" << endl;
                            cout << "2.Строка-Идентификатор" << endl;
                            cout << "3.Десятичная Строк" << endl;
                            cin >> menu3;
                            switch (menu3) {
                            case 1:
                                String * str1;
                                cout << "Введите строку: ";
                                cin >> p;
                                str1 = new String(p);
                                strings[i] = str1;
                                break;
                            case 2:
                                IdentifierString * str2;
                                cout << "Введите строку: ";
                                cin >> p;
                                str2 = new IdentifierString(p);
                                strings[i] = str2;
                                break;
                            case 3:
                                DecString * str3;
                                cout << "Введите строку: ";
                                cin >> p;
                                str3 = new DecString(p);
                                strings[i] = str3;
                                break;
                            default:
                                break;
                            }
                            i++;
                        } while (i != count);
                    }
                    else {
                        cout << "Сначала введите кол-во элементов" << endl;
                        //getchar();
                        return 0;
                    }
                    break;
                case 3:
                    break;
                default:
                    break;
                }
            } while (menu2 != 3);
            break;
        case 2:
            if (canWork) {
                if (i == count) {
                    system("clear");
                    do {
                        cout << "1.Строка" << endl;
                        cout << "2.Строка-Идентификатор" << endl;
                        cout << "3.Десятичная строка" << endl;
                        cout << "4.Выход" << endl;
                        cin >> menu2;
                        switch (menu2) {
                        case 1:
                            do {
                                cout << "1.Получить длину Строки" << endl;
                                cout << "2.Вывести Строку" << endl;
                                cout << "3.Выход" << endl;
                                cin >> menu3;
                                switch (menu3) {
                                case 1:
                                    cout << "Введите номер элемента: ";
                                    cin >> ele;
                                    cout << "Длина строки номер " << ele << " : " << strings[ele - 1]->Get_length() << endl;
                                    //getchar();
                                    return 0;
                                    break;
                                case 2:
                                    cout << "Введите номер элемента: ";
                                    cin >> ele;
                                    cout << *strings[ele - 1];
                                    //getchar();
                                    return 0;
                                    break;
                                case 3:
                                    break;
                                default:
                                    break;
                                }
                            } while (menu3 != 3);
                            break;
                        case 2:
                            do {
                                cout << "1.Найти позицию первого вхождения символа" << endl;
                                cout << "2.Вывести Строку-Идентификатор" << endl;
                                cout << "3.Выход" << endl;
                                cin >> menu3;
                                switch (menu3) {
                                case 1:
                                    cout << "Введите номер элемента: ";
                                    cin >> ele;
                                    char p;
                                    cout << "Введите символ: ";
                                    cin >> p;
                                    *static_cast<IdentifierString*>(strings[ele - 1]) < p;
                                    //getchar();
                                    return 0;
                                    break;
                                case 2:
                                    cout << "Введите номер элемента: ";
                                    cin >> ele;
                                    cout << *static_cast<IdentifierString*>(strings[ele - 1]);
                                    //getchar();
                                    return 0;
                                    break;
                                case 3:
                                    break;
                                default:
                                    break;
                                }
                            } while (menu3 != 3);
                            break;
                        case 3:
                            do {
                                cout << "1.Определить можно ли предстваить Десятичную строку в формате int" << endl;
                                cout << "2.Сравнить 2 Десятичные строки" << endl;
                                cout << "3.Вычесть из одной Десятичной строки другую" << endl;
                                cout << "4.Вывести Десятичную строку" << endl;
                                cout << "5.Выход" << endl;
                                cin >> menu3;
                                switch (menu3) {
                                case 1:
                                    cout << "Введите номер строки: ";
                                    cin >> ele;
                                    if (static_cast<DecString*>(strings[ele - 1])->form_int()) {
                                        cout << "Можно представить в формате int" << endl;
                                    }
                                    else {
                                        cout << "Нельзя представить в формате int" << endl;
                                    }
                                    //getchar();
                                    return 0;
                                    break;
                                case 2:
                                    int ele2;
                                    cout << "Введите номер первой строки: ";
                                    cin >> ele;
                                    cout << "Введите номер второй строки: ";
                                    cin >> ele2;
                                    if (*static_cast<DecString*>(strings[ele - 1]) > *static_cast<DecString*>(strings[ele2 - 1])) {
                                        cout << "Первое число больше второго" << endl;
                                    }
                                    else {
                                        cout << "Второе число больше первого или числа равны" << endl;
                                    }
                                    //getchar();
                                    return 0;
                                    break;
                                case 3:
                                    int ele3;
                                    cout << "Введите номер первой строки: ";
                                    cin >> ele;
                                    cout << "Введите номер второй строки: ";
                                    cin >> ele3;
                                    *static_cast<DecString*>(strings[ele - 1]) - *static_cast<DecString*>(strings[ele3 - 1]);
                                    break;
                                case 4:
                                    cout << "Введите номер строки: ";
                                    cin >> ele;
                                    cout << *static_cast<DecString*>(strings[ele - 1]);
                                    break;
                                case 5:
                                    break;
                                default:
                                    break;
                                }
                            } while (menu3 != 5);
                            break;
                        case 4:
                            break;
                        default:
                            break;
                        }
                    } while (menu2 != 4);
                }
                else {
                    cout << "Сначала введите начальные значения" << endl;
                    //getchar();
                    return 0;
                }
            }
            else {
                cout << "Сначала введите кол-во элементов" << endl;;
                //getchar();
                return 0;
            }
            break;
        case 3:
            break;
        default:
            break;
        }
    } while (menu1 != 3);
    return 0;
}