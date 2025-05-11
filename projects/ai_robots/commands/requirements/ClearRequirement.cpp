#include "ClearRequirement.h"

namespace Drivers { namespace Requirement
{
	ClearRequirement::ClearRequirement()
	{
		this->optional = false;
	}

	void ClearRequirement::makeOptional()
	{
		this->optional = true;
	}

	std::wstring ClearRequirement::getName()
	{
		return L"Clear_Requirement";
	}

	bool ClearRequirement::isMeet()
	{
		// Placeholder: logic to check robot's cleaning capability
		return false;
	}

	bool ClearRequirement::isOptional()
	{
		return this->optional;
	}

	std::vector<Requirement*> ClearRequirement::depends()
	{
		std::vector<Requirement*> depends;
		// Example: requires movement capability
		// depends.push_back(new MoveRequirement());
		return depends;
	}
} }
