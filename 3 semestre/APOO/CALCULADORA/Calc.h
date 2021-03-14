#pragma once

#include <iostream>
using namespace std;

enum Digito {ZERO , UM , DOIS , TRES , QUATRO, CINCO, SEIS , SETE , OITO, NOVE};
enum Operacao {ADICAO = '+', SUBTRACAO = '-', DIVISAO = '/', MULTIPLICACAO = '*', VAZIO = ' '};

class Display
{
    public:
        virtual void setAtual(int operando) = 0;
        virtual int getAtual() = 0;
        virtual void mostrarResultado() = 0;
        virtual void limparDisplay() = 0;
};

class CPU
{
    protected:
		Display* display;
		int operandoUm;
		int operandoDois;
		int flagOperandoUm;
		int flagOperandoDois;
		char operacao;
    public:
        virtual void setDisplay(Display* display) = 0;
        virtual Display* getDisplay() = 0;
        virtual int getOperando() = 0;
        virtual char getOperacao() = 0;
        virtual void setOperando(int operando) = 0;
        virtual void setOperacao(Operacao operacao) = 0;
        virtual void limparCPU() = 0;
        virtual void realizaOperacao() = 0;
};

class TecladoNumerico
{
    public:
        virtual void pressionarZero() = 0;
        virtual void pressionarUm() = 0;
        virtual void pressionarDois() = 0;
        virtual void pressionarTres() = 0;
        virtual void pressionarQuatro() = 0;
        virtual void pressionarCinco() = 0;
        virtual void pressionarSeis() = 0;
        virtual void pressionarSete() = 0;
        virtual void pressionarOito() = 0;
        virtual void pressionarNove() = 0;
};

class TecladoDeOperacoes
{
    public:
        virtual void pressionarSoma() = 0;
        virtual void pressionarSubtracao() = 0;
        virtual void pressionarMultiplicacao() = 0;
        virtual void pressionarDivisao() = 0;
        virtual void pressionarIgual() = 0;
        virtual void pressionarCE() = 0;
};

class Calculadora
{
    protected:
        CPU *cpu;
        Display *display;
        TecladoNumerico *tecladoNumerico;
        TecladoDeOperacoes *tecladoDeOperacoes;
};