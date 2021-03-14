#pragma once

#include "Calc.h"

class MeuTecladoNumerico: public TecladoNumerico
{
  	private:
  		CPU *cpu;

  	public:
		MeuTecladoNumerico(CPU* cpu)
		{
			this->cpu = cpu;	
		};

		void setCPU(CPU* cpu)
		{
			this->cpu = cpu;
		}
		
		void pressionarZero()
		{
			int operando = this->cpu->getOperando();
			operando *=  10;
			cpu->setOperando(operando);
		}
		
		void pressionarUm()
		{
			int operando = this->cpu->getOperando();
			if(operando != 0) operando *= 10;
			operando += UM;
			cpu->setOperando(operando);
		}

		void pressionarDois()
		{
			int operando = this->cpu->getOperando();
			if(operando != 0) operando *= 10;
			operando += DOIS;
			cpu->setOperando(operando);
		}

		void pressionarTres()
		{
			int operando = this->cpu->getOperando();
			if(operando != 0) operando *= 10;
			operando += TRES;
			cpu->setOperando(operando);
		}

		void pressionarQuatro()
		{
			int operando = this->cpu->getOperando();
			if(operando != 0) operando *= 10;
			operando += QUATRO;
			cpu->setOperando(operando);
		}

		void pressionarCinco()
		{
			int operando = this->cpu->getOperando();
			if(operando != 0) operando *= 10;
			operando += CINCO;
			cpu->setOperando(operando);
		}

		void pressionarSeis()
		{
			int operando = this->cpu->getOperando();
			if(operando != 0) operando *= 10;
			operando += SEIS;
			cpu->setOperando(operando);
		}

		void pressionarSete()
		{
			int operando = this->cpu->getOperando();
			if(operando != 0) operando *= 10;
			operando += SETE;
			cpu->setOperando(operando);
		}

		void pressionarOito()
		{
			int operando = this->cpu->getOperando();
			if(operando != 0) operando *= 10;
			operando += OITO;
			cpu->setOperando(operando);
		}
		
		void pressionarNove()
		{
			int operando = this->cpu->getOperando();
			if(operando != 0) operando *= 10;
			operando += NOVE;
			cpu->setOperando(operando);
		}
};