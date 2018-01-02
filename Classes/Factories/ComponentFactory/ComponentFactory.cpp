#include "ComponentFactory.h"
#include "../../Components/Battery/Resources/BatteryResources.h"
#include "../../Components/Battery/Battery.h"
#include "../../Components/Condenser/Resources/CondenserResources.h"
#include "../../Components/Condenser/Condenser.h"
#include "../../Components/Diode/Resources/DiodeResources.h"
#include "../../Components/Diode/Diode.h"
#include "../../Components/Node/Resources/NodeResources.h"
#include "../../Components/Node/Node.h"
#include "../../Components/NpnTransistor/Resources/NpnTransistorResources.h"
#include "../../Components/NpnTransistor/NpnTransistor.h"
#include "../../Components/OperationalAmplifier/Resources/OprerationalAmplifierResources.h"
#include "../../Components/OperationalAmplifier/OperationalAmplifier.h"
#include "../../Components/PnpTransistor/Resources/PnpTransistorResources.h"
#include "../../Components/PnpTransistor/PnpTransistor.h"
#include "../../Components/Resistor/Resources/ResistorResources.h"
#include "../../Components/Resistor/Resistor.h"
#include "../../Components/ServoMotor/Resources/ServoMotorResources.h"
#include "../../Components/ServoMotor/ServoMotor.h"
#include "../../Components/NandGate/Resources/NandGateResources.h"
#include "../../Components/NandGate/NandGate.h"
#include "../../Components/ZennerDiode/Resources/ZennerDiodeResources.h"
#include "../../Components/ZennerDiode/ZennerDiode.h"


BaseComponent* ComponentFactory::GetComponentByDetails(const JsonObjects::ComponentDetails details)
{
	BaseComponent* component = GetComponentByName(details.Type);
	auto componentCoordinates = new CartesianCoordinate(details.Position.x, details.Position.y);
	component->SetCoordinates(*componentCoordinates);
	component->SetOrientation(details.orientation);
	return component;
}

BaseComponent* ComponentFactory::GetComponentByName(const std::string name)
{
	BaseComponent* component = nullptr;
	if (name == BatteryResources::Name)
	{
		component = new Battery();
	}
	if (name == CondenserResources::Name)
	{
		component = new Condenser();
	}
	if (name == DiodeResources::Name)
	{
		component = new Diode();
	}
	if (name == NodeResources::Name)
	{
		component = new Node();
	}
	if (name == NpnTransistorResources::Name)
	{
		component = new NpnTransistor();
	}
	if (name == OperationalAmplifierResources::Name)
	{
		component = new OperationalAmplifier();
	}
	if (name == PnpTransistorResources::Name)
	{
		component = new PnpTransistor();
	}
	if (name == ResistorResources::Name)
	{
		component = new Resistor();
	}
	if (name == ServoMotorResources::Name)
	{
		component = new ServoMotor();
	}
	if (name == NandGateResources::Name)
	{
		component = new NandGate();
	}
	if (name == ZennerDiodeResources::Name)
	{
		component = new ZennerDiode();
	}
	return component;
}

std::vector<BaseComponent*> ComponentFactory::GetListOfComponents()
{
	std::vector<BaseComponent*> components;
	components.push_back(new Battery());
	components.push_back(new Condenser());
	components.push_back(new Diode());
	components.push_back(new NandGate());
	components.push_back(new Node());
	components.push_back(new NpnTransistor());
	components.push_back(new OperationalAmplifier());
	components.push_back(new PnpTransistor());
	components.push_back(new Resistor());
	components.push_back(new ServoMotor());
	components.push_back(new ZennerDiode());

	return components;
}
