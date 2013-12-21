#pragma once
class FuzzyTerm
{  
public:

  virtual ~FuzzyTerm(){}

  virtual FuzzyTerm* Clone()const = 0;

  virtual double      GetDOM()const=0;

  virtual void       ClearDOM()=0;

  virtual void       ORwithDOM(double val)=0;

   
};