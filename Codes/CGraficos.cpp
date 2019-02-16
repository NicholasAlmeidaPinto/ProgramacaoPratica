/*#include "CGraficos.h"

void CGrafico::PlotarCartesiano(std::vector<double> X, std::vector<double> Y){
	CGnuplot grafico;
	grafico.PlotVector
}

void CGrafico::PlotarLog(std::vector<double> X, std::vector<double> Y){

}

void CGrafico::PlotarLog_Log(std::vector<double> X, std::vector<double> Y){

}

void CGraficos::PlotarCartesiano(std::vector<double> X, std::vector<double> Y)
{
}*/
#include <vector>
#include <iostream>
#include "CGnuplot.h"

int main() {
	std::vector<int> X(1, 2, 3, 4, 5);
	std::vector<int> Y(1, 3, 2, 4, 5);
	CGnuplot grafico;
	grafico.PlotVector(X, Y);
	std::cin.get();
	return 0;
}