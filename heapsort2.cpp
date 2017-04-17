// heapsort2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "heapsort.h"
#include <fstream>
#include <cstdlib>
#include <time.h>  /* clock_t, clock, CLOCKS_PER_SEC */
#include <ctime>
#include <windows.h>
#include <chrono>

using namespace std;

int main()
{
	SetConsoleCP(1251);			// для вывода кирилицы
	SetConsoleOutputCP(1251);	// для вывода кирилицы

	//ifstream fin;
	//ofstream fout;
	//clock_t t, t1, t2, t3, t4, t5, t6, t7, t8;
	bool exit = false;
	char your_answer;
	ifstream fin("data.txt");
	while (!exit)
	{

		cout << "              MENU:" << endl;
		cout << "*******************************" << endl;
		cout << "1. Считать данные с консоли." << endl;
		cout << "2. Считать данные из файла." << endl;
		cout << "3. Вы захотели ввести рандомные числа, за исключением размера массива - его вы введете сами." << endl;
		cout << "4. Завершить программу." << endl;
		cout << "*******************************" << endl;
		cout << "Итак, ваш ответ:" << endl;
		cin >> your_answer;
		cout << "                 " << endl;
		
		switch (your_answer)
		{
		case '1': {

			int n = -1;
			while (n <= 0)
			{
				cout << "Введите размер массива: " << endl;
				cin >> n;
			}
			cout << "Введите элементы массива: " << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}

			auto start_time = chrono::steady_clock::now();

			heap_sort(arr, n);

			auto end_time = chrono::steady_clock::now();

			cout << "Отсортированный массив: " << endl;
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << "  ";
			}
			cout << "\n";

			cout << "Время сортировки: " << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << " микросекунды" << endl;
			cout << "\n\n\n";
			break;
		}
		case '2': {
			int n;

			if (!fin.is_open()) // если файл не открыт
				cout << "Файл не может быть открыт!\n"; // сообщить об этом
			else
			{
				fin >> n;
				cout << "Наш входной массив:  ";
				for (int i = 0; i < n; i++)
				{
					fin >> arr[i];
					cout << arr[i] << "  ";
				}

				cout << endl;

				auto start_time1 = chrono::steady_clock::now();
				heap_sort(arr, n);
				auto end_time1 = chrono::steady_clock::now();

				cout << "Отсортированный массив: " << endl;
				for (int i = 0; i < n; i++)
				{
					cout << arr[i] << "  ";
				}
				cout << "\n";

				cout << "Время сортировки: " << chrono::duration_cast<chrono::microseconds>(end_time1 - start_time1).count() << " микросекунды" << endl;
				cout << "\n\n\n";
				fin.close(); // закрываем файл
			}

			break;
		}
		case '3': {
			int n;
			cout << "Введите размер массива: " << endl;
			cin >> n;
			int random_arr[NMAX + 1];

			cout << "Наш входной рандомный массив: ";
			for (int i = 0; i < n; i++)
			{
				random_arr[i] = rand() % 10000; //запись случайного числа
				cout << random_arr[i] << "  ";
			}
			cout << endl;

			auto start_time2 = chrono::steady_clock::now();

			heap_sort(random_arr, n);

			auto end_time2 = chrono::steady_clock::now();

			cout << "Отсортированный массив: " << endl;
			for (int i = 0; i < n; i++)
			{
				cout << random_arr[i] << "  ";
			}
			cout << "\n";
			cout << "Время сортировки: " << chrono::duration_cast<chrono::microseconds>(end_time2 - start_time2).count() << " микросекунды" << endl;

			cout << "\n\n\n";
			break;
		}
		case '4':

			exit = true;
			break;

		default:
			cout << " Error \n";
			system("cls");
			}
		
	}

	//_getch();
	return 0;
}



