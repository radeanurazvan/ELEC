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
	BaseComponent* component = nullptr;
	auto componentCoordinates = new CartesianCoordinate(details.Position.x, details.Position.y);
	if(details.Type == BatteryResources::Name)
	{
		component =  new Battery();
	}
	if (details.Type == CondenserResources::Name)
	{
		component =  new Condenser();
	}
	if (details.Type == DiodeResources::Name)
	{
		component = new Diode();
	}
	if (details.Type == NodeResources::Name)
	{
		component = new Node();
	}
	if (details.Type == NpnTransistorResources::Name)
	{
		component = new NpnTransistor();
	}
	if (details.Type == OperationalAmplifierResources::Name)
	{
		component = new OperationalAmplifier();
	}
	if (details.Type == PnpTransistorResources::Name)
	{
		component = new PnpTransistor();
	}
	if (details.Type == ResistorResources::Name)
	{
		component = new Resistor();
	}
	if (details.Type == ServoMotorResources::Name)
	{
		component = new ServoMotor();
	}
	if (details.Type == NandGateResources::Name)
	{
		component = new NandGate();
	}
	if (details.Type == ZennerDiodeResources::Name)
	{
		component = new ZennerDiode();
	}
	component->SetCoordinates(*componentCoordinates);
	return component;
}
