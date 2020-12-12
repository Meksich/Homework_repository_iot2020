#include "Matrix.h"

void InputMatrix(Matrix* A, int number_of_rows) {
	int k = A[0].number_of_columns;
	for (int i = 0; i < number_of_rows; i++) {
		for (int j = 0;j < k; j++)
		{
			std::cout << "enter element on position [" << i << "][" << j << "]: ";
			std::cin >> A[i].array[j];

		}
	}
}



void OutputMatrix(Matrix* A, int number_of_rows) {
	int k = A[0].number_of_columns;

	for (int i = 0; i < number_of_rows; i++) {
		std::cout << "Row ¹ [" << i << "]: ";
		for (int j = 0;j < k; j++)
		{

			std::cout << A[i].array[j] << ' ';
		}
		std::cout << '\n';
	}
}


void Matrix_merge_sort(Matrix* A, int number_of_rows) {
	for (int k = 0; k < number_of_rows; k++) {
		Merge_sort_row(A, 0, A[k].number_of_columns, k);
	}
}



void Merge_sort_row(Matrix* A, int left_side, int right_side, int k) {

	if (right_side == left_side)
		return;
	int mid = (left_side + right_side) / 2;
	Merge_sort_row(A, left_side, mid, k);
	Merge_sort_row(A, mid + 1, right_side, k);

	int i = left_side;
	int j = mid + 1;

	int* t = new int[right_side + 1];

	for (int o = 0; o < right_side - left_side + 1; o++) {
		if ((j > right_side) || ((i < mid + 1) && (A[k].array[i] > A[k].array[j]))) {
			t[o] = A[k].array[i];
			i++;
		}
		else {
			t[o] = A[k].array[j];
			j++;
		}

	}

	for (int o = 0; o < right_side - left_side + 1; o++) {
		A[k].array[left_side + o] = t[o];
	}
	delete[]t;
}

float* Mean_square_column(Matrix* A, int number_of_rows) {
	int k = A[0].number_of_columns;
	float* array_of_mean_squares = new float[number_of_rows];
	for (int i = 0; i < number_of_rows; i++) {
		array_of_mean_squares[i] = 1;
		for (int j = 0; j < k; j++) {
			array_of_mean_squares[i] *= static_cast<float>(A[j].array[i]);
		}
		double o = 1.0 / number_of_rows;
		array_of_mean_squares[i] = static_cast<float>(pow(array_of_mean_squares[i], o));
		std::cout << array_of_mean_squares[i] << ' ';
	}
	std::cout << '\n';
	return array_of_mean_squares;
}

float Sum_of_mean_squares(Matrix* A, float* array_of_mean_squares, int number_of_rows) {
	float sum_columns = 0;
	for (int i = 0; i < number_of_rows; i++) {

		sum_columns += array_of_mean_squares[i];

	}
	delete[]array_of_mean_squares;
	return sum_columns;

}