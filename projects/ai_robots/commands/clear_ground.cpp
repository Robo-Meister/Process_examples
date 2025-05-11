#include "ClearGroundCommand.h"

namespace Examples
{
	using CommandException = Command::CommandException;
	using CommandInterface = Command::CommandInterface;
	using Object = Factory::Object;
	using Requirement = Drivers::Requirement::Requirement;
	using ClearRequirement = Drivers::Requirement::ClearRequirement;
	using MoveRequirement = Drivers::Requirement::MoveRequirement;
	using MapRequirement = Drivers::Requirement::MapRequirement;
	using ClearRobot = Drivers::Type::ClearRobot;

	ClearGroundCommand::ClearGroundCommand(Map* map, Sector* sector, Area* targetArea)
	{
		this->map = map;
		this->sector = sector;
		this->targetArea = targetArea;
	}

	void ClearGroundCommand::run()
	{
		std::vector<Workspace*> workspaces = this->sector->getWorkspaces();
		for (Workspace* workspace : workspaces)
		{
			ClearRobot* robot = dynamic_cast<ClearRobot*>(workspace->getRobot());
			if (robot && robot->canClear(this->targetArea))
			{
				workspace->assignTask(this);
				break;
			}
		}
	}

	std::vector<Requirement*> ClearGroundCommand::getRequirement()
	{
		std::vector<Requirement*> requirements;
		requirements.push_back(new ClearRequirement());
		requirements.push_back(new MoveRequirement());
		requirements.push_back(new MapRequirement());
		return requirements;
	}

	std::wstring ClearGroundCommand::getName()
	{
		return L"clear_ground_command";
	}
}
