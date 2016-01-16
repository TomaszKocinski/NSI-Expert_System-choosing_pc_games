#pragma once
#include "GPU.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
GPU::GPU()
{
	ifstream file("GPUnvidia.txt");
	if (!file) {
		throw exception();
	}
	pair<string, double> temp_pair;
	while (file >> temp_pair.first >> temp_pair.second)
		GPUnvidia.insert(temp_pair);
	file.close();
	file.open("GPUamd.txt");
	if (!file) {
		throw exception();
	}
	while (file >> temp_pair.first >> temp_pair.second)
		GPUamd.insert(temp_pair);
	file.close();
}
GPU::~GPU()
{
}

double GPU::getGPUscore()
{
	string temp;
	double choice = 0;

	do {
		cout << "Czy posiadasz karte graficzna (nie zintegrowana)? Wpisz 1 gdy tak, 2 gdy nie" << endl;
		getline(cin, temp);
		if (temp.size() != 1) continue;
		if (temp[0] == '1') choice = 1;
		if (temp[0] == '2') choice = 2;
	} while (choice != 1 && choice != 2);
	system("ClS");
	if (choice == 2) return 0;

	do {
		cout << "Wybierz swoja karte graficzna, czy posiadasz karte AMD(1) czy NVIDIA(2)" << endl;
		getline(cin, temp);
		if (temp.size() != 1) continue;
		if (temp[0] == '1') choice = 1;
		if (temp[0] == '2') choice = 2;
	} while (choice != 1 && choice != 2);
	system("ClS");
	if (choice == 1) {
		cout << "Wybrales AMD" << endl;
		choice = getGPU(GPUamd);
	}
	else if (choice == 2) {
		cout << "Wybrales Nvidie" << endl;
		choice = getGPU(GPUnvidia);
	}
	else throw exception();
	return choice;
}

double GPU::getGPU(map<string, double>& GPU)
{
	string str;
	map<string, double>::iterator ite;
	do {
		cout << "Wybierz swoja karte graficzna (przepisz jej nazwe)" << endl;
		for (map<string, double>::iterator ite = GPU.begin(); ite != GPU.end(); ite++) {
			cout << ite->first << " ";
		}
		cout << endl;
		getline(cin, str);
	} while ((ite = GPU.find(str)) == GPU.end());

	if (ite->first.size() == 4) GPU_of_user = "AMD HD" + ite->first;
	if (ite->first[0] == '2' || ite->first[0] == '3') {
		if (ite->first[1] == '6')
		{
			GPU_of_user = "AMD r7 " + ite->first;
		}
		else GPU_of_user = "AMD r9 " + ite->first;
	}
	else GPU_of_user = "Nvidia GTX " + ite->first;
	Speed_of_current_GPU = ite->second;
	system("ClS");
	return ite->second;
}
