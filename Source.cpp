#include "Matrix.h"

int main(){
	int number_of_rows;
	std::cout << "Enter number of rows:";
	std::cin >> number_of_rows;

	Matrix* A = new Matrix[number_of_rows];

	InputMatrix(A, number_of_rows);

	std::cout << Sum_of_mean_squares(A, Mean_square_column(A, number_of_rows), number_of_rows) << '\n';

	Matrix_merge_sort(A, number_of_rows);

	OutputMatrix(A, number_of_rows);
	
}