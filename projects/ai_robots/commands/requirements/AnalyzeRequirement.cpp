
namespace Drivers { namespace Requirement
{
	AnalyzeRequirement::AnalyzeRequirement()
	{
		this->optional = false;
	}

	void AnalyzeRequirement::makeOptional()
	{
		this->optional = true;
	}

	std::wstring AnalyzeRequirement::getName()
	{
		return L"Analyze_Requirement";
	}

	bool AnalyzeRequirement::isMeet()
	{
		// You would check if a robot has an active analysis sensor
		return false;
	}

	bool AnalyzeRequirement::isOptional()
	{
		return this->optional;
	}

	std::vector<Requirement*> AnalyzeRequirement::depends()
	{
		std::vector<Requirement*> depends;
		depends.push_back(new MapRequirement());
		return depends;
	}
} }
