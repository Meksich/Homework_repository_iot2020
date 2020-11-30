#pragma once
#include <iostream>
#include <string>
#include <cmath>

class Matrix {
private:
	int* V;
	
public:
	int m;

	friend float* f(Matrix* A, int n);
	friend float Func(Matrix *A, float* x, int n);
	friend void InputMatrix(Matrix *A, int n);
	friend void OutputMatrix(Matrix* A, int n);
	friend void merge_sort(Matrix* A, int left_side, int right_side, int k);
	friend void merge(Matrix* A, int n);

	Matrix() {
		this->m = 5;
		V = new int[5];
	}

	Matrix(int m) {
		this->m = m;
		V = new int[m];
	}

	~Matrix(){
		delete[]V;
	}
};


