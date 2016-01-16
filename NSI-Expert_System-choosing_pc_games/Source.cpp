#pragma once
#include "GPU.h"
#include "CPU.h"
int main(void) {
	GPU GraphicCard;
	CPU CentralProcessingUnit;
	GraphicCard.getGPUscore();
	CentralProcessingUnit.getCPUscore();
	return 0;
}