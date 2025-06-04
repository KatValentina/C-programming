#include <iostream>
#include <vector>
#include"Header.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    PNode head = NULL; // Указатель на корень дерева в первом задании
    PNode Head = NULL;//Указатель на корень для второго дерева
    UNode UHead = NULL, Tail = NULL;//указатели на двухсвязный список
    int c;//выбор для заполнения списка
    cout << "Программа работает только с целыми неотрицательными числами" << endl;
    cout << "1 - с клавиатуры, 2 - рандомно, 3 - из файла" << endl << "Выберите способ заполнения двухсвязного списка: ";
    cin >> c;

    switch (c) {
    case 1:
        Board(UHead,Tail);
        break;
    case 2:
        Rand(UHead, Tail);
        break;
    case 3:
        File(UHead, Tail);
        break;
    default:
        cout << "Нет такого способа заполнения";
        return 1;
    }
    PrintSpisok(UHead, Tail);
    mergeSort(UHead);
    cout << "\nИзменённый список " << endl;
    PrintSpisok(UHead, Tail);
    cout << "Дерево: " << endl;
    AddToTree(head, UHead);
    string rpref = "";
    string cpref = "";
    string lpref = "";
    Print(head, rpref, cpref, lpref);

    int ch; // переменная под выбор
    cout << "\n1 - с клавиатуры, 2 - рандомно, 3 - из файла" << endl << "Выберите способ заполнения дерева: ";
    cin >> ch;

    switch (ch) {
    case 1:
        Keyboard(Head);
        break;
    case 2:
        Random(Head);
        break;
    case 3:
        ToFile(Head);
        break;
    default:
        cout << "Нет такого способа заполнения";
        return 1;
    }

    if (head == NULL) {
        cout << "\nДерево пустое!";
        return 1;
    }
    else {
        cout << "\nПолучившееся дерево:" << endl;
        string rpref = "";
        string cpref = "";
        string lpref = "";
        Print(Head, rpref, cpref, lpref);
        cout << "Вывод дерева в порядке (Корень-Право-Лево): ";
        vector<int> res = inOrder(Head);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        };
        return 0;
    }
}

