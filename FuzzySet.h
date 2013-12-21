#pragma once
#include <iostream>
class FuzzySet
{
private:
	double m_DOM;
	double m_representativeValue;
	std::string m_name;
public:

	FuzzySet(std::string name, double repVal):m_name(name), m_DOM(0.0), m_representativeValue(repVal)
	{
	}

	virtual double CalculateDOM(double value) = 0;

	double GetRepresentativeValue()
	{
		return m_representativeValue;
	}

	void ClearDOM()
	{
		m_DOM = 0.0;
	}

	void SetDOM(double value)
	{
		m_DOM = value;
	}

	double GetDOM()
	{
		return m_DOM;
	}

	bool IsEqual(double x, double y)
	{
		if (fabs(x-y) < 1E-12)
		{
			return true;
		}

		return false;
	}

	std::string GetName()
	{
		return m_name;
	}

	void ORwithDOM(double val){if (val > m_DOM) m_DOM = val;}

	~FuzzySet(void)
	{
	}
};

