#pragma once

#include "Calc.h"

class MinhaCalculadora: public Calculadora
{
  	public:
		MinhaCalculadora(Display* display, CPU* cpu, TecladoNumerico* tn, TecladoDeOperacoes* to)
		{
			this->display = display;
			this->cpu = cpu;
			this->tecladoNumerico = tn;
			this->tecladoDeOperacoes = to;
			
			this->cpu->setDisplay(display);
		}
};