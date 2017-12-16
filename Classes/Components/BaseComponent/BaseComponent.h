#pragma once
#include <string>
#include "Resources/BaseComponentResources.h";
#include "../../CartesianPlane/CartesianCoordinate/CartesianCoordinate.h"

class BaseComponent
{
	private:
		std::string name;
		int numberOfConnectors;
		CartesianCoordinate coordinates;
	public:
		BaseComponent();
		~BaseComponent();
		int GetNumberOfConnectors();
		void SetNumberOfConnectors(int number);
		std::string GetName();
		void SetName(std::string _name);
		CartesianCoordinate GetCoordinates();
		void SetCoordinates(CartesianCoordinate coords);
		virtual void Draw() = 0;
};

