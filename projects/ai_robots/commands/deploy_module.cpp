#include "DeployModuleCommand.h"

namespace Examples
{
	using Requirement = Drivers::Requirement::Requirement;
	using MoveRequirement = Drivers::Requirement::MoveRequirement;
	using AttachRequirement = Drivers::Requirement::AttachRequirement;
	using DeployRequirement = Drivers::Requirement::DeployRequirement;
	using BuilderRobot = Drivers::Type::BuilderRobot;

	DeployModuleCommand::DeployModuleCommand(Map* map, Sector* sector, Module* module)
	{
		this->map = map;
		this->sector = sector;
		this->module = module;
	}

	void DeployModuleCommand::run()
	{
		for (Workspace* workspace : this->sector->getWorkspaces())
		{
			BuilderRobot* robot = dynamic_cast<BuilderRobot*>(workspace->getRobot());
			if (robot && robot->canDeploy(this->module))
			{
				workspace->assignTask(this);
				break;
			}
		}
	}

	std::vector<Requirement*> DeployModuleCommand::getRequirement()
	{
		std::vector<Requirement*> requirements;
		requirements.push_back(new MoveRequirement());
		requirements.push_back(new AttachRequirement());
		requirements.push_back(new DeployRequirement());
		return requirements;
	}

	std::wstring DeployModuleCommand::getName()
	{
		return L"deploy_module_command";
	}
}
