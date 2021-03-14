#pragma once

#include "Calc.h"

class MeuDisplay: public Display
{
	int  atual;
	public:
		MeuDisplay()
		{
			this->atual = 0;
		}

		void setAtual(int operando)
		{
			this->atual = operando;
		}

		int getAtual()
		{
			return this->atual;
		}

		void mostrarResultado()
		{
			cout << "Resultado: " << this->atual << "\n";
		}    
		void limparDisplay()
		{
			setAtual(0);
		}
};