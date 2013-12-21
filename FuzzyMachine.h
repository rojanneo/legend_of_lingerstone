#pragma once
#include "FuzzyVariable.h"
#include "FuzzyOperator.h"
#include "FuzzyRule.h"
#include "FuzzySet.h"
#include "FzSet.h"
class FuzzyMachine
{
private:
	typedef std::vector<FuzzyVariable*> VarMap;
private:
	VarMap m_variables;
	std::vector<FuzzyRule*>   m_rules;
public:
	enum DefuzzifyMethod{max_av, centroid};
	enum {NumSamples = 15};
	FuzzyMachine()
	{
	}

	FuzzyVariable& CreateFLV(std::string name)
	{
		m_variables.push_back(new FuzzyVariable(name));
		return *m_variables[m_variables.size()-1];
	}

	void Fuzzify(std::string nameOfFLV, double value)
	{
		int reqd = -1;
		std::string test;
		for(int count = 0; count<(int)m_variables.size(); count++)
		{
			test = m_variables[count]->GetName();
			
			if(strcmp(test.c_str(), nameOfFLV.c_str()) == 0)
			{
				//std::cout<<test.c_str();
				reqd = count;
			}
		}

		if(reqd!=-1)
		{
			//std::cout<<"TEST: "<<test.c_str()<<std::endl;
			//std::cout<<"Name: "<<nameOfFLV.c_str()<<std::endl;
			//std::cout<<m_variables[reqd]->GetName().c_str();
			m_variables[reqd]->Fuzzify(value);
		}
	}

	double DeFuzzify(const std::string& nameOfFLV, DefuzzifyMethod method)
	{
		int reqd = -1;
		std::string test;
		std::vector<FuzzyRule*>::iterator crule = m_rules.begin();
		for (crule; crule != m_rules.end(); ++crule)
		{
			//(*crule)->SetConfidenceOfConsequentToZero();
		}
		//process the rules
		std::vector<FuzzyRule*>::iterator curRule = m_rules.begin();
		for (curRule; curRule != m_rules.end(); ++curRule)
		{
			(*curRule)->Calculate();
		}

		  //now defuzzify the resultant conclusion using the specified method
		switch (method)
		{
			case centroid:

				
				for(int count = 0; count<(int)m_variables.size(); count++)
				{
					test = m_variables[count]->GetName().c_str();
					if(strcmp(test.c_str(), nameOfFLV.c_str()) == 0)
					{
						reqd = count;
					}
				}

				if(reqd != -1)
				return 10000;
				//return m_variables[reqd]->DeFuzzifyCentroid(NumSamples);

				break;

			case max_av:

				
				reqd = -1;
				for(int count = 0; count<(int)m_variables.size(); count++)
				{
					test = m_variables[count]->GetName().c_str();
					if(strcmp(test.c_str(), nameOfFLV.c_str()) == 0)
					{
						std::cout<<"Test: "<<test.c_str()<<std::endl;
						reqd = count;
					}
				}

				if(reqd != -1)
				return m_variables[reqd]->DeFuzzifyMaxAv();

				break;
		}

		return 0;
	
	}

	void ShowALLDOMS()
	{
		for(int i = 0; i<(int)m_variables.size(); i++)
		{
			//std::cout<<m_variables[i]->GetName().c_str()<<std::endl;
			m_variables[i]->ShowALLDOMS();
			std::cout<<std::endl;
		}
	}

	void AddRule(FuzzyTerm& antecedent, FuzzyTerm& consequence)
	{
		m_rules.push_back(new FuzzyRule(antecedent, consequence));
	}
};