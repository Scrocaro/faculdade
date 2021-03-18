#include "calculator.h"
#include "calculatorTest.cpp"
#include "myOperationKeyBoard.cpp"
#include "myNumericKeyBoard.cpp"
#include "myCalculator.cpp"
#include "myDisplay.cpp"
#include "myCPU.cpp"

int main(int argc, char* argv[])
{
	Display* d = new MyDisplay();
	Cpu* cpu = new MyCPU();
	NumericKeyBoard* nk = new MyNumericKeyBoard();
	OperationKeyBoard* opk = new MyOperationKeyBoard();

	Calculator* calculator = new MyCalculator(d, cpu, nk, opk);

	CalculatorTest::run(calculator);
	
/*
	nk->pressOne();
	nk->pressZero();

	opk->pressAddition();

	nk->pressOne();
	nk->pressOne();

	opk->pressEquals();
	cpu->reset();

	nk->pressSeven();
	nk->pressOne();

	opk->pressSubtraction();

	nk->pressOne();
	nk->pressOne();

	opk->pressEquals();	
	cpu->reset();
*/

	delete d;
	delete cpu;
	delete nk;
	delete opk;
	delete calculator;

	return 0;

}
