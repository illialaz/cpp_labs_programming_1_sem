//The program calculates the number of positive elements and rewrites the elements of 
//the array in the new array so that negative elements immideately go and then the rest
#include <iostream>
using namespace std;

//scans your array and then prints number of positive elements
int num_of_positive(int* A, int size) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		cout << "Enter the " << i + 1 << " element of array" << endl;
		cin >> A[i];
		if (A[i] >= 0) {
			num++;
		}
	}
	return num;
}

//Prints your array
void Print(int *A,int size) {
	for (int i = 0; i < size; i++) {
		cout << A[i] << ' ';
	}
	cout << endl;
}

//Combines all functions
void Print_negative_then_positive(int* A, int* B, int size) {
	cout << "Number of positive elements in this array is: " << num_of_positive(A, size) << endl;
	int start = 0;
	int finish = size - 1;
	for (int i = 0; i < size; i++) {
		if (A[i] < 0) {
			B[start] = A[i];
			start++;
		}
		else {
			B[finish] = A[i];
			finish--;
		}
	}
	Print(A, size);
	Print(B, size);
}

int main(){
	int n;
	cout << "Enter size of your array" << endl;
	cin >> n;
	int* p;
	int* q;
	p = new int[n];
	q = new int[n];
	Print_negative_then_positive(p, q, n);
	return 0;
}