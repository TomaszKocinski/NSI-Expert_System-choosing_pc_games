#pragma once
#include <map>
#include <string>
using namespace std;
class GPU
{
	map<string, double> GPUnvidia;
	map<string, double> GPUamd;
	std::string GPU_of_user;
	double getGPU(map<string, double>&);
	
public:
	double Speed_of_current_GPU;
	GPU();
	~GPU();
	double getGPUscore();
	
};



