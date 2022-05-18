// LAB-10.1.cpp
// Сушинський Ігор
// Лабораторія №10.1
// Пошук символів у текстовому файлі.
// Варіант 18

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

void CreateTXT(char* fname) // створення файлу з введених рядків
{
	ofstream fout(fname); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок
	do
	{
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // «кінець рядка», який залишився після вводу числа
		cout << "Ввести рядок: "; getline(cin, s); // ввели рядок
		fout << s << endl; // записали його у файл
		cout << "Продовжити? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname) // виведення файлу на екран
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl; // виводимо його на екран
	}
	cout << endl;
}

int ProcessTXT(char* fname) // обчислення загальної кількості символів + - =
{
	ifstream fin(fname); // відкрили файл для зчитування
	string s; // прочитаний рядок
	size_t i = 0;
	size_t j = 0;
	while (getline(fin, s))
	{
		i++;
		if (s.find(s) != string::npos)
			cout << "Номер рядка у файлі: " << i << endl;
		if (s.rfind(s, 3) == '.')
			cout << "Номер позиції у рядку: " << j << endl;
	}
	return 0;
}

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

	// текстові файли
	char fname[100]; // ім'я першого файлу
	cout << "Ввести ім'я файлу: "; cin >> fname;

	CreateTXT(fname); // ввели рядки файлу з клавіатури
	PrintTXT(fname); // вивели вміст першого файлу на екран

	cout << "Пошук номеру рядка у файлі та номеру позиції у рядку" << endl;
	ProcessTXT(fname);

	return 0;
}