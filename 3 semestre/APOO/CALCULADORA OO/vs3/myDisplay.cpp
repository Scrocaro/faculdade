#pragma once

#include <iostream>
#include "calculator.h"

class MyDisplay: public Display
{
	public:
		void addDigit(Digit number) 
		{	
			std::cout << number;
		}

		//void addDecimalSeparator(){}

		//void setSignal(Signal signal){}

		void clear() 
		{
			std::cout << "\n";
		}
};