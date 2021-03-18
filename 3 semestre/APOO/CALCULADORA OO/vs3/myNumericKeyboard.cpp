#pragma once

#include "calculator.h"

class MyNumericKeyBoard: public NumericKeyBoard
{
	private:
		Cpu* cpu;

	public:
		void setCpu(Cpu *cpu)
		{
			this->cpu = cpu;
		}

		void pressZero(){	cpu->receiveDigit(ZERO);	}

		void pressOne(){	cpu->receiveDigit(ONE);		}

		void pressTwo(){	cpu->receiveDigit(TWO);		}

		void pressThree(){	cpu->receiveDigit(THREE);	}

		void pressFour(){	cpu->receiveDigit(FOUR);	}

		void pressFive(){	cpu->receiveDigit(FIVE);	}

		void pressSix(){	cpu->receiveDigit(SIX);		}

		void pressSeven(){	cpu->receiveDigit(SEVEN);	}

		void pressEight(){	cpu->receiveDigit(EIGHT);	}

		void pressNine(){	cpu->receiveDigit(NINE);	}
};

