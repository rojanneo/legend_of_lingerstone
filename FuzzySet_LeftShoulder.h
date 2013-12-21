#pragma once
#include "fuzzyset.h"
class FuzzySet_LeftShoulder :
	public FuzzySet
{
private:
	double m_peakPoint;
	double m_leftOffset;
	double m_rightOffset;
public:

	FuzzySet_LeftShoulder(std::string name, double peak, double left, double right):FuzzySet(name, ((peak - left) + peak)/2),
		m_peakPoint(peak), m_rightOffset(right), m_leftOffset(left)
	{
	}

	double CalculateDOM(double value)
	{
		if((IsEqual(m_rightOffset, 0.0) && IsEqual(m_peakPoint, value))||IsEqual(m_leftOffset, 0.0) && IsEqual(m_peakPoint , value))
		{
			return 1.0;
		}

		if((value >= m_peakPoint) && (value < (m_peakPoint + m_rightOffset)))
		{
			double grad = 1.0/-m_rightOffset;
			return grad * ( value - m_peakPoint) + 1.0;
		}
		else if(value < m_peakPoint && value >= (m_peakPoint - m_leftOffset))
		{
			return 1.0;
		}
		else
		{
			return 0.0;
		}
	}

	~FuzzySet_LeftShoulder(void)
	{
	}
};

