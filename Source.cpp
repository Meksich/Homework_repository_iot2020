#include "Goro.h"

int main(){
	int n;
	std::cout << "Enter number of rows:";
	std::cin >> n;

	Matrix* A = new Matrix[n];

	InputMatrix(A, n);

	std::cout << Func(A, f(A, n), n) << '\n';

	merge(A, n);

	OutputMatrix(A, n);
	
}