#include <iostream>
using namespace std;

class Display
{
  private:
	int atual;

  public:
    Display()
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

class CPU
{
  private:
	Display* display;
  	int operandoUm;
  	int operandoDois;
	int flagOperandoUm;
	int flagOperandoDois;
  	char operacao;

  public:
  	CPU(Display *display)
  	{
		this->display = display;
  		this->operandoUm = 0;
  		this->operandoDois = 0;
		this->flagOperandoUm = 0;
		this->flagOperandoDois = 0;
  		this->operacao = ' ';
	}
	
	int getOperando()
	{
		if(this->operacao == ' ')	return this->operandoUm;
		else return this->operandoDois;
	}
	
	char getOperacao()
	{
		return this->operacao;
	}
	
	void setOperando(int operando)
	{
		if(this->operacao == ' ')	
		{
			this->operandoUm = operando;
			this->flagOperandoUm = 1;
		}
		else 
		{
			this->operandoDois = operando;
			this->flagOperandoDois = 1;
		}
	}
	
	void setOperacao(char operacao)
	{
		this->operacao = operacao;
	}

	void realizaOperacao()
  	{
  		if(this->operandoUm != 0 && this->operacao != ' ')
		{
	  		switch (this->operacao)
	  		{
	  			case '+':
	  				operandoUm = operandoUm + operandoDois;
					display->setAtual(operandoUm);
	  				break;
	  			
				case '-':
	  				operandoUm = operandoUm - operandoDois;
					display->setAtual(operandoUm);
	  				break;	
				
				case '/':
	  				operandoUm = operandoUm / operandoDois;
					display->setAtual(operandoUm);
	  				break;
	  				
	  			case '*':
	  				operandoUm = operandoUm * operandoDois;
					display->setAtual(operandoUm);
	  				break;
	  				
	  			default:
	  				throw "erro!\n";
			}
		}
		else if(this->flagOperandoUm == 0 && this->flagOperandoDois != 0)
		{
			operandoUm = operandoDois;
			display->setAtual(operandoUm);
		}
		
		this->flagOperandoUm = 0;
		this->flagOperandoDois = 0;
		this->operandoDois = 0;
	}
};

class TecladoDeOperacoes
{
  private:
	CPU* cpu;

  public:
  	TecladoDeOperacoes(CPU *cpu)
  	{
		  this->cpu = cpu;
	}

    void pressionarSoma()
    {
    	cpu->setOperacao('+');
	}
	
	void pressionarSubtracao()
    {
    	cpu->setOperacao('-');
	}
	
	void pressionarMultiplicacao()
    {
    	cpu->setOperacao('*');
	}
	
    void pressionarDivisao()
    {
    	cpu->setOperacao('/');
	}

	void pressionarIgual()
	{
		cpu->realizaOperacao();
	}
};

class TecladoNumerico
{
  private:
  	CPU *cpu;

  public:
  	TecladoNumerico(CPU* cpu)
  	{
  		this->cpu = cpu;	
	}
	
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
		operando += 1;
		cpu->setOperando(operando);
	}

	void pressionarDois()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += 2;
		cpu->setOperando(operando);
	}

	void pressionarTres()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += 3;
		cpu->setOperando(operando);
	}

	void pressionarQuatro()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += 4;
		cpu->setOperando(operando);
	}

	void pressionarCinco()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += 5;
		cpu->setOperando(operando);
	}

	void pressionarSeis()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += 6;
		cpu->setOperando(operando);
	}

	void pressionarSete()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += 7;
		cpu->setOperando(operando);
	}

	void pressionarOito()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += 8;
		cpu->setOperando(operando);
	}
    
	void pressionarNove()
	{
		int operando = this->cpu->getOperando();
		if(operando != 0) operando *= 10;
		operando += 9;
		cpu->setOperando(operando);
	}
};

class Calculadora
{
  private:
    CPU *cpu;
    Display *display;
    TecladoNumerico *tecladoNumerico;
    TecladoDeOperacoes *tecladoDeOperacoes;

  public:
    Calculadora()
	{
      this->display = new Display();
      this->cpu = new CPU(this->display);
      this->tecladoNumerico = new TecladoNumerico(this->cpu);
      this->tecladoDeOperacoes = new TecladoDeOperacoes(this->cpu);
    }
    
    CPU* getCPU()
    {
    	return this->cpu;
	}
    
    TecladoNumerico* getTN()
    {
    	return this->tecladoNumerico;
	}
	
	TecladoDeOperacoes* getTO()
    {
    	return this->tecladoDeOperacoes;
	}
	
	Display* getDisplay()
    {
    	return this->display;
	}
};

int main(int argc, char* argv[])
{
	Calculadora *calculadora = new Calculadora();
	Display* d = calculadora->getDisplay();
	TecladoNumerico* tn = calculadora->getTN();
	TecladoDeOperacoes* to = calculadora->getTO();
	CPU* cpu = calculadora->getCPU();

	tn->pressionarUm();
	tn->pressionarZero();
	int ou = cpu->getOperando();

	to->pressionarSoma();

	tn->pressionarUm();
	tn->pressionarUm();
	int od = cpu->getOperando();

	to->pressionarIgual();

	d->mostrarResultado();

	tn->pressionarSete();
	tn->pressionarUm();
	od = cpu->getOperando();

	to->pressionarIgual();

	d->mostrarResultado();

	return 0;
}