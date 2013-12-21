#pragma once
#include <vector>
#include "FuzzyTerm.h"
class FuzzyAND:public FuzzyTerm
{
private:
	std::vector<FuzzyTerm*>m_terms;
	FuzzyAND& operator = (const FuzzyAND&);
public:
	~FuzzyAND()
	{
		std::vector<FuzzyTerm*>::iterator curTerm;
		for (curTerm = m_terms.begin(); curTerm != m_terms.end(); ++curTerm)
		{
			delete *curTerm;
		}
		}

	FuzzyAND(const FuzzyAND& fa)
	{
		std::vector<FuzzyTerm*>::const_iterator curTerm;
		for (curTerm = fa.m_terms.begin(); curTerm != fa.m_terms.end(); ++curTerm)
		{
			m_terms.push_back((*curTerm)->Clone());
		}
	}


	FuzzyAND(FuzzyTerm& op1, FuzzyTerm& op2)
	{
		m_terms.push_back(op1.Clone());
		m_terms.push_back(op2.Clone());
	}
	FuzzyAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
	{
		m_terms.push_back(op1.Clone());
		m_terms.push_back(op2.Clone());
		m_terms.push_back(op3.Clone());
	}
	FuzzyAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
	{
		m_terms.push_back(op1.Clone());
		m_terms.push_back(op2.Clone());
		m_terms.push_back(op3.Clone());
		m_terms.push_back(op4.Clone());
	}

	//virtual ctor
	FuzzyTerm* Clone()const{return new FuzzyAND(*this);}
  
	double FuzzyAND::GetDOM()const
	{
		double smallest = std::numeric_limits<double>::max();

		std::vector<FuzzyTerm*>::const_iterator curTerm;
		for (curTerm = m_terms.begin(); curTerm != m_terms.end(); ++curTerm)
		{
			if ((*curTerm)->GetDOM() < smallest)
			{
			  smallest = (*curTerm)->GetDOM();
			}
		}

		return smallest;
}


//------------------------- ORwithDOM -----------------------------------------
void FuzzyAND::ORwithDOM(double val)
{
  std::vector<FuzzyTerm*>::iterator curTerm;
  for (curTerm = m_terms.begin(); curTerm != m_terms.end(); ++curTerm)
  {
    (*curTerm)->ORwithDOM(val);
  }
}

//---------------------------- ClearDOM ---------------------------------------
void FuzzyAND::ClearDOM()
{
  std::vector<FuzzyTerm*>::iterator curTerm;
  for (curTerm = m_terms.begin(); curTerm != m_terms.end(); ++curTerm)
  {
    (*curTerm)->ClearDOM();
  }
}
};