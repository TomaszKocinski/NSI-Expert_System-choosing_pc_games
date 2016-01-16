#pragma once
#include "CPU.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
double CPU::Family(set<string>& set_to_choose)
{
	string str;
	set<string>::iterator ite;
	do {
		cout << "Wybierz rodzinê twojego procesora (przepisz jej nazwe)" << endl;
		for (set <string>::iterator ite = set_to_choose.begin(); ite != set_to_choose.end(); ite++) {
			cout << *ite << " ";
		}
		cout << endl;
		getline(cin, str);
	} while ((ite = set_to_choose.find(str)) == set_to_choose.end());
	system("ClS");
	family = str;
	if (producent == "AMD") {
		return Year(Year_AMD);
	}
	if (producent == "Intel") {
		return Year(Year_Intel);
	}
}

double CPU::Year(set<string>& set_to_choose)
{
	string str;
	set<string>::iterator ite;
	do {
		cout << "Wybierz rok wydania twojego procesora (przepisz jej nazwe)" << endl;
		for (set <string>::iterator ite = set_to_choose.begin(); ite != set_to_choose.end(); ite++) {
			cout << *ite << " ";
		}
		cout << endl;
		getline(cin, str);
	} while ((ite = set_to_choose.find(str)) == set_to_choose.end());
	system("ClS");
	family = *ite;
	return Freq();
	
}

double CPU::Freq()
{
	string str;
	double dtemp;
	do {
		cout << "Podaj czestopliwosc taktowania twojego procesora w Ghz" << endl;
		getline(cin, str);
		istringstream iss(str);
		iss >> str;
		if (!iss) continue;
		std::string::const_iterator ite = str.begin();
		while (ite != str.end() && (isdigit(*ite) || *ite == '.')) {
			++ite;
		}
		if (ite != str.end()) {
			dtemp = 0;
			continue;
		}
		dtemp = stod(str);
	} while (dtemp<1 || dtemp>4);
	system("ClS");
	//family = *ite;
	if (producent == "AMD") {
		return Freq();
	}
	if (producent == "Intel") {
		return Freq();
	}
}

CPU::CPU()
{
	ifstream file("CPUamd.txt");
	if (!file) {
		throw exception();
	}
	string temp;
	while (getline(file, temp))
		Family_name_AMD.insert(temp);
	file.close();
	file.open("CPUintel.txt");
	if (!file) {
		throw exception();
	}
	while (getline(file, temp))
		Family_name_Intel.insert(temp);
	file.close();
	file.open("CPUintelYear.txt");
	if (!file) {
		throw exception();
	}
	while (getline(file, temp))
		Year_Intel.insert(temp);
	file.close();
	file.open("CPUamdYear.txt");
	if (!file) {
		throw exception();
	}
	while (getline(file, temp))
		Year_AMD.insert(temp);
	file.close();
}

CPU::~CPU()
{
}

double CPU::getCPUscore()
{
	string temp;
	double choice = 0;

	do {
		cout << "Jakiej marki posiadasz procesor? AMD(1), Intel(2)" << endl;
		getline(cin, temp);
		if (temp.size() != 1) continue;
		if (temp[0] == '1') choice = 1;
		else if (temp[0] == '2') choice = 2;
	} while (choice != 1 && choice != 2);
	system("ClS");

	if (choice == 1) {
		producent = "AMD";
		return Family(Family_name_AMD);
	}
	if (choice == 2) {
		producent = "Intel";
		return Family(Family_name_Intel);
	}
}
