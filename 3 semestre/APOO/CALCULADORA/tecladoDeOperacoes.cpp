#pragma once

#include "Calc.h"

class MeuTecladoDeOperacoes: public TecladoDeOperacoes
{
  	private:
		CPU* cpu;

  	public:
		MeuTecladoDeOperacoes(CPU* cpu)
		{
			this->cpu = cpu;
		};

		void pressionarSoma()
		{
			cpu->setOperacao(ADICAO);
		}
		
		void pressionarSubtracao()
		{
			cpu->setOperacao(SUBTRACAO);
		}
		
		void pressionarMultiplicacao()
		{
			cpu->setOperacao(MULTIPLICACAO);
		}
		
		void pressionarDivisao()
		{
			cpu->setOperacao(DIVISAO);
		}

		void pressionarIgual()
		{
			cpu->realizaOperacao();
			cpu->setOperacao(VAZIO);
			Display* d = cpu->getDisplay();
			d->mostrarResultado();
		}

		void pressionarCE()
		{
			cpu->limparCPU();
			Display* display = cpu->getDisplay();
			display->limparDisplay();

		}
};