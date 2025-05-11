#include "AnalyzeSoilCommand.h"

namespace Examples
{
	using CommandException = Command::CommandException;
	using Requirement = Drivers::Requirement::Requirement;
	using AnalyzeRequirement = Drivers::Requirement::AnalyzeRequirement;
	using MoveRequirement = Drivers::Requirement::MoveRequirement;
	using SensorRobot = Drivers::Type::SensorRobot;

	AnalyzeSoilCommand::AnalyzeSoilCommand(Map* map, Sector* sector, Coordinate* position)
	{
		this->map = map;
		this->sector = sector;
		this->position = position;
	}

	void AnalyzeSoilCommand::run()
	{
		std::vector<SensorRobot*> robots = this->sector->getSensorRobots();
		for (SensorRobot* robot : robots)
		{
			if (robot->canReach(this->position))
			{
				robot->moveTo(this->position);
				robot->analyzeSoil();
				break;
			}
		}
	}

	std::vector<Requirement*> AnalyzeSoilCommand::getRequirement()
	{
		std::vector<Requirement*> requirements;
		requirements.push_back(new AnalyzeRequirement());
		requirements.push_back(new MoveRequirement());
		return requirements;
	}

	std::wstring AnalyzeSoilCommand::getName()
	{
		return L"analyze_soil_command";
	}
}
