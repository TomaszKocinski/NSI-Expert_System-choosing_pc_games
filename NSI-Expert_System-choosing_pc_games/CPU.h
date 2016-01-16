#pragma once
#include <vector>
#include <set>
using namespace std;
class CPU
{
	set<string> Family_name_AMD;
	set<string> Family_name_Intel;
	set<string> Year_AMD;
	set<string> Year_Intel;
	double Family(set<string>&);
	double Year(set<string>&);
	double Freq();
	std::string producent;
	std::string family;
	int year;
	//double Intel();
public:
	CPU();
	~CPU();
	double getCPUscore();
	
	


};

