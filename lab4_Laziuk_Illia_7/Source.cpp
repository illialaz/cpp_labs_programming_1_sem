//swap matrix blocks clockwise
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void rand_elems(int** A, int p, int max) {//p is size
	srand(time(0));
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			A[i][j] = (rand() % max + 1);
		}
	}
}

//swap blocks of the matrix
void swap(int** A, int** B, int n){//n is size
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			B[i][j] = A[i + n][j];
			B[i][j + n] = A[i][j];
			B[i +n][j + n] = A[i][j + n];
			B[i + n][j] = A[i + n][j + n];
		}
	}
}

void Print(int** A, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << setw(4) << A[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	int n, max_elem;
	cout << "2N * 2N matrix. Enter N" << endl;
	cin >> n;
	cout << "Enter max elem of your matrix" << endl;
	cin >> max_elem;
	int p = 2*n;
	int** arr = new int*[p];
	for (int i = 0; i < p; i++) {
		arr[i] = new int[p];
	}
	int** arr1 = new int* [p];
	for (int i = 0; i < p; i++) {
		arr1[i] = new int[p];
	}
	rand_elems(arr, p, max_elem);
	swap(arr, arr1, n);
	Print(arr, p); //matrix
	cout << endl << endl;
	Print(arr1, p); //new matrix
	
	for (int i = 0; i < p; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	for (int i = 0; i < p; i++) {
		delete[] arr1[i];
	}
	delete[] arr1;
	return 0;
}
