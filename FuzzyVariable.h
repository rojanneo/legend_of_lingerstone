#pragma once
#include <iostream>
#include <vector>
#include "FuzzySet.h"
#include "FuzzyMachine.h"
#include "FzSet.h"
#include "FuzzySet_LeftShoulder.h"
#include "FuzzySet_RightShoulder.h"
#include "FuzzySet_Triangle.h"
class FuzzyVariable
{
private:
	typedef std::vector<FuzzySet*>MemberSets;
private:
	std::string m_name;
	double m_minRange;
	double m_maxRange;
	MemberSets m_memberSets;
	friend class FuzzyMachine;
public:
	FuzzyVariable(std::string name):m_minRange(0.0), m_maxRange(0.0)
	{
		m_name = name;
	}

	~FuzzyVariable(void)
	{}

	void AdjustRangeToFit(double minBound, double maxBound)
	{
		if (minBound < m_minRange) m_minRange = minBound;
		if (maxBound > m_maxRange) m_maxRange = maxBound;
	}

	FzSet AddLeftShoulderSet(std::string name, double min, double peak, double max)
	{	
		FuzzySet *l = new FuzzySet_LeftShoulder(name, peak, peak - min, max - peak);
		m_memberSets.push_back(l);

		AdjustRangeToFit(min, max);
		FzSet f(l);
		return f;
	}


	FzSet FuzzyVariable::AddRightShoulderSet(std::string name, double minBound, double peak, double maxBound)
	{
		FuzzySet *l = new FuzzySet_RightShoulder(name, peak, peak - minBound, maxBound - peak);
		m_memberSets.push_back(l);
		AdjustRangeToFit(minBound, maxBound);
		FzSet f(l);
		return f;
	}


	FzSet FuzzyVariable::AddTriangularSet(std::string name, double minBound, double peak, double maxBound)
	{
		FuzzySet *l = new FuzzySet_Triangle(name, peak, peak-minBound, maxBound-peak);
		m_memberSets.push_back(l);
		AdjustRangeToFit(minBound, maxBound);

		FzSet f(l);
		return f;
	}

	std::string GetName()
	{
		return m_name;
	}

	void Fuzzify(double value)
	{
		double dummy = -1;
		if(value > m_maxRange && value < m_minRange)
		{
			std::cout<<"OUT OF RANGE";
		}
		else
		{
			for(int i = 0; i<(int)m_memberSets.size(); i++)
			{
				dummy = m_memberSets[i]->CalculateDOM(value);
				m_memberSets[i]->SetDOM(dummy);
			}
		}
	}

	double DeFuzzifyMaxAv()const
	{
		double bottom = 0.0;
		double top    = 0.0;

		for(int i = 0; i<(int)m_memberSets.size(); i++)
		{
			bottom += m_memberSets[i]->GetDOM();
//			bottom += curSet->second->GetDOM();
			std::cout<<m_memberSets[i]->GetDOM()<<std::endl;
			top += m_memberSets[i]->GetRepresentativeValue() * m_memberSets[i]->GetDOM();
		}

		  //make sure bottom is not equal to zero
		if (bottom == 0) return 0.0;
		//std::cout<<"Top: "<<top<<std::endl;
		//std::cout<<"Bottom: "<<bottom<<std::endl;
		return top / bottom;   
	}




	void ShowALLDOMS()
	{
		std::cout<<"NAME\t\t"<<"DOM"<<std::endl;
		for(int i = 0; i<(int)m_memberSets.size(); i++)
		{
			std::cout<<m_memberSets[i]->GetName().c_str()<<"\t";
			std::cout<<" "<<m_memberSets[i]->GetDOM();
			std::cout<<std::endl;
		}
	}
};

