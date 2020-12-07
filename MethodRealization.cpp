#include "Goro.h"

void InputMatrix(Matrix* A, int n) {
	int k = A[0].m;
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < k; j++)
		{
			std::cout << "enter element on position [" << i << "][" << j << "]: ";
			std::cin >> A[i].V[j];

		}
	}
}



void OutputMatrix(Matrix* A, int n) {
	int k = A[0].m;

	for (int i = 0; i < n; i++) {
		std::cout << "Row ¹ [" << i << "]: ";
		for (int j = 0;j < k; j++)
		{

			std::cout << A[i].V[j] << ' ';
		}
		std::cout << '\n';
	}
}


void merge(Matrix* A, int n) {
	for (int k = 0; k < n; k++) {
		merge_sort(A, 0, A[k].m, k);
	}
}



void merge_sort(Matrix* A, int left_side, int right_side, int k) {

	if (right_side == left_side)
		return;
	int mid = (left_side + right_side) / 2;
	merge_sort(A, left_side, mid, k);
	merge_sort(A, mid + 1, right_side, k);

	int i = left_side;
	int j = mid + 1;

	int* t = new int[right_side + 1];

	for (int o = 0; o < right_side - left_side + 1; o++) {
		if ((j > right_side) || ((i < mid + 1) && (A[k].V[i] > A[k].V[j]))) {
			t[o] = A[k].V[i];
			i++;
		}
		else {
			t[o] = A[k].V[j];
			j++;
		}

	}

	for (int o = 0; o < right_side - left_side + 1; o++) {
		A[k].V[left_side + o] = t[o];
	}
	delete[]t;
}

float* f(Matrix* A, int n) {
	int k = A[0].m;
	float* x = new float[n];
	for (int i = 0; i < n; i++) {
		x[i] = 1;
		for (int j = 0; j < k; j++) {
			x[i] *= static_cast<float>(A[j].V[i]);
		}
		double o = 1.0 / n;
		x[i] = static_cast<float>(pow(x[i], o));
		std::cout << x[i] << ' ';
	}
	std::cout << '\n';
	return x;
}

float Func(Matrix* A, float* x, int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {

		sum += x[i];

	}
	delete[]x;
	return sum;

}