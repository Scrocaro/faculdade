#include "Calc.h"
#include "tecladoDeOperacoes.cpp"
#include "tecladoNumerico.cpp"
#include "calculadora.cpp"
#include "display.cpp"
#include "cpu.cpp"

int main(int argc, char* argv[])
{
	Display* d = new MeuDisplay();
	CPU* cpu = new MeuCPU(d);
	TecladoNumerico* tn = new MeuTecladoNumerico(cpu);
	TecladoDeOperacoes* to = new MeuTecladoDeOperacoes(cpu);

	Calculadora* calculadora = new MinhaCalculadora(d, cpu, tn, to);

	tn->pressionarUm();
	tn->pressionarZero();

	to->pressionarSoma();

	tn->pressionarUm();
	tn->pressionarUm();

	to->pressionarIgual();
	to->pressionarCE();

	tn->pressionarSete();
	tn->pressionarUm();

	to->pressionarSubtracao();

	tn->pressionarUm();
	tn->pressionarUm();

	to->pressionarIgual();	
	to->pressionarCE();

	delete d;
	delete cpu;
	delete tn;
	delete to;
	delete calculadora;

	return 0;
}
