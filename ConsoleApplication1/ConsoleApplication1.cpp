// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <set>
#include <map>
#include <random>
#include <iterator> 
#include <algorithm>

#define N 100

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(1, N);
uniform_real_distribution<> distR(1, N);

void CreateSet(set<int> *_set, int size)
{
	int a;

	for (int i = 0; i < size; i++)
	{
		 a = dist(gen);
		_set->insert(a);
	}
};


void CreateMap(map<int, double> *_map, int size)
{
	int a;
	double b;

	for (int i = 0; i < size; i++)
	{
		a = dist(gen);
		b = distR(gen);
		_map->insert(pair<int, double>(b, a));
	}
};

void IncreaseByFirst(set<int> *_set)
{
	set<int>::iterator iter = _set->begin();
	set<int> set;
	int first_element = *iter;
	set.insert(*iter);
	iter++;
	for (int i = 1; i < _set->size(); i++, iter++)
	{
		set.insert(*iter + first_element);
	}
	_set->clear();
	_set->swap(set);
}

void ReplaceByFirst(map<int, double> *_map)
{
	map<int, double>::iterator iter = _map->begin();
	map<int, double>::iterator iter2 = _map->begin();
	int small = iter->first;
	int big = iter->first;
	int average;
	int count = 0;
	for (int i = 1; i <= _map->size(); i++, iter++)
	{
		if (small > iter->first)
		{
			small = iter->first;
		}
		if (small > iter->second)
		{
			small = iter->second;
		}
		if (big < iter->first)
		{
			big = iter->first;
		}
		if (big < iter->second)
		{
			big = iter->second;
		}
	}

	cout << "Наименьшее число и наибольшее: " << small << " : " << big << endl;
	average = (small + big) / 2;
	cout << "Среднее арифметическое: " << average << endl;
	for (int i = 1; i <= _map->size(); i++, iter2++)
	{
		if (average < iter2->first)
		{
			count++;
		}
		if (average < iter2->second)
		{
			count++;
		}
	}
	cout << "Количество чисел, которые больше среднего арифметического:" << count << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ostream_iterator<int> ositer(cout, ", ");

	set<int> dSet;
	map <int, double> strMap;

	CreateSet(&dSet, 10);

	set<int>::iterator iter = dSet.begin();


	copy(dSet.begin(), dSet.end(), ositer);

	cout << endl << "Введите значение удаляемого элемента: ";
	int num;
	cin >> num;
	if (dSet.find(num) != dSet.end())
	{
		dSet.erase(num);
	}
	else
		cout << endl << "Элемент отсутствует." << endl;
	copy(dSet.begin(), dSet.end(), ositer);
	iter = dSet.begin();
	cout << endl << "Введите номер удаляемого элемента: ";
	cin >> num;
	if (dSet.size() + 1 > num)
	{
		for (int i = 0; i < num - 1; i++)
			iter++;
		num = *iter;
		dSet.erase(num);
		copy(dSet.begin(), dSet.end(), ositer);
	}
	else cout << "Номер выходит за границы.";

	IncreaseByFirst(&dSet);
	cout << endl << "Увеличено на значение первого элемента." << endl;
	copy(dSet.begin(), dSet.end(), ositer);
	cout << endl << endl;

	CreateMap(&strMap, 10);
	map <int, double> ::iterator it = strMap.begin();
	for (int i = 0; it != strMap.end(); it++, i++)
		cout << it->first << " : " << it->second << endl;

	ReplaceByFirst(&strMap);

}

