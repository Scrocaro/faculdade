#pragma once

#include "Calc.h"

class MeuCPU: public CPU
{
  	public:
		MeuCPU(Display *display)
		{
			this->display = display;
			this->operandoUm = 0;
			this->operandoDois = 0;
			this->flagOperandoUm = 0;
			this->flagOperandoDois = 0;
			this->operacao = VAZIO;
		}

		Display* getDisplay()
		{
			return this->display;
		}
		
		void setDisplay(Display* display)
		{
			this->display = display;
		}
		
		int getOperando()
		{
			if(this->operacao == VAZIO)	return this->operandoUm;
			else return this->operandoDois;
		}
		
		char getOperacao()
		{
			return this->operacao;
		}
		
		void setOperando(int operando)
		{
			if(this->operacao == VAZIO)	
			{
				this->operandoUm = operando;
				this->flagOperandoUm = 1;
			}
			else 
			{
				this->operandoDois = operando;
				this->flagOperandoDois = 1;
			}
			this->display->setAtual(operando);
		}
		
		void setOperacao(Operacao operacao)
		{
			this->operacao = operacao;
		}

		void limparCPU()
		{
			this->operandoUm = ZERO;
			this->operandoDois = ZERO;
			this->operacao = VAZIO;
			this->flagOperandoUm  = ZERO;
			this->flagOperandoDois = ZERO;
		}

		void realizaOperacao()
		{
			if(this->operandoUm != 0 && this->operacao != VAZIO)
			{
				switch (this->operacao)
				{
					case ADICAO:
						operandoUm = operandoUm + operandoDois;
						display->setAtual(operandoUm);
						break;
					
					case SUBTRACAO:
						operandoUm = operandoUm - operandoDois;
						display->setAtual(operandoUm);
						break;	
					
					case DIVISAO:
						operandoUm = operandoUm / operandoDois;
						display->setAtual(operandoUm);
						break;
						
					case MULTIPLICACAO:
						operandoUm = operandoUm * operandoDois;
						display->setAtual(operandoUm);
						break;
						
					default:
						throw "erro!\n";
				}
			}
			else if(this->flagOperandoUm == ZERO && this->flagOperandoDois != ZERO)
			{
				operandoUm = operandoDois;
				display->setAtual(operandoUm);
			}
			
			this->flagOperandoUm = ZERO;
			this->flagOperandoDois = ZERO;
			this->operandoDois = ZERO;
		}
};