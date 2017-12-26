#include "CircuitReader.h"
#include "../JsonHelper/JsonHelper.cpp"
#include "../FileHelper/FileHelper.h"

JsonObjects::CircuitDetails CircuitReader::ReadFromJSON(char* jsonFile)
{
	std::string jsonCircuit = FileHelper::GetFileContent(jsonFile);
	auto circuitDetails = JsonHelper::Parse<JsonObjects::CircuitDetails>(jsonCircuit);
	return circuitDetails;
}
