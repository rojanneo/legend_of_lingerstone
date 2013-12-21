#pragma once
#include "fuzzyset.h"
class FuzzySet_Triangle :
	public FuzzySet
{
private:
	double m_peakPoint;
	double m_leftOffset;
	double m_rightOffset;
public:
	FuzzySet_Triangle(std::string name, double mid, double left, double right):FuzzySet(name, mid),m_peakPoint(mid), m_leftOffset(left), m_rightOffset(right)
	{
	
	}

	double CalculateDOM(double value)
	{
		if((IsEqual(m_rightOffset, 0.0) && IsEqual(m_peakPoint, value))||(IsEqual(m_leftOffset, 0.0) && IsEqual(m_peakPoint, value)))
		{
			return 1.0;
		}

		if((value <= m_peakPoint) && (value >= m_peakPoint - m_leftOffset))
		{
			double grad = 1.0/m_leftOffset;
			return grad * (value - (m_peakPoint - m_leftOffset));
		}
		else if((value > m_peakPoint) && (value < (m_peakPoint + m_rightOffset)))
		{
			double grad = 1.0/-m_rightOffset;
			return grad * (value - m_peakPoint) + 1.0;
		}
		else
		{
			return 0.0;
		}
	}


	~FuzzySet_Triangle(void);
};

