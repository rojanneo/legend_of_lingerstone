#pragma once
#include "fuzzyset.h"
class FuzzySet_RightShoulder :
	public FuzzySet
{
private:
	double m_peakPoint;
	double m_rightOffset;
	double m_leftOffset;
public:

	FuzzySet_RightShoulder(std::string name, double peak, double left, double right):FuzzySet(name, ((peak + right) + peak)/2),
		m_peakPoint(peak), m_rightOffset(right), m_leftOffset(left)
	{
	}

	double CalculateDOM(double value)
	{
		if(IsEqual(m_leftOffset, 0.0) && IsEqual(m_peakPoint, value))
		{
			return 1.0;
		}

		if((value <= m_peakPoint) && (value > (m_peakPoint - m_leftOffset)))
		{
			double grad = 1.0/m_leftOffset;
			return grad * ( value - (m_peakPoint - m_leftOffset));
		}
		else if(value > m_peakPoint)
		{
			return 1.0;
		}
		else
		{
			return 0.0;
		}
	}

	~FuzzySet_RightShoulder(void)
	{
	}
};

