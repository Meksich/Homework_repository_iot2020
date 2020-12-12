#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Matrix {
private:
	int* array;
	
public:
	int number_of_columns;

	friend float* Mean_square_column(Matrix* A, int number_of_rows);
	friend float Sum_of_mean_squares(Matrix *A, float* x, int number_of_rows);
	friend void InputMatrix(Matrix *A, int number_of_rows);
	friend void OutputMatrix(Matrix* A, int number_of_rows);
	friend void Merge_sort_row(Matrix* A, int left_side, int right_side, int k);
	friend void Matrix_merge_sort(Matrix* A, int number_of_rows);

	Matrix() {
		this->number_of_columns = 5;
		array = new int[5];
	}

	Matrix(int number_of_columns) {
		this->number_of_columns = number_of_columns;
		array = new int[number_of_columns];
	}

	~Matrix(){
		delete[]array;
	}
};


