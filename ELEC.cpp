#include "stdafx.h"
#include "Classes/Helpers/FileHelper/FileHelper.h"
#include "Classes/Wrappers/CircuitDetails/CircuitDetails.h";

using std::cout;
int main()
{
	std::string jsonCircuit =  FileHelper::GetFileContent("circuit.json");
	////auto circuitDetails = JsonHelper::Parse<CircuitDetails>(jsonCircuit);
	return 0;
}

