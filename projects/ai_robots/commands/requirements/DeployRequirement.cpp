#include "DeployRequirement.h"
#include "MoveRequirement.h"
#include "AttachRequirement.h"

namespace Drivers { namespace Requirement
{
	DeployRequirement::DeployRequirement()
	{
		this->optional = false;
	}

	void DeployRequirement::makeOptional()
	{
		this->optional = true;
	}

	std::wstring DeployRequirement::getName()
	{
		return L"Deploy_Requirement";
	}

	bool DeployRequirement::isMeet()
	{
		// Placeholder for checking if robot has deploy capabilities
		return false;
	}

	bool DeployRequirement::isOptional()
	{
		return this->optional;
	}

	std::vector<Requirement*> DeployRequirement::depends()
	{
		std::vector<Requirement*> depends;
		depends.push_back(new MoveRequirement());
		depends.push_back(new AttachRequirement());
		return depends;
	}
} }
