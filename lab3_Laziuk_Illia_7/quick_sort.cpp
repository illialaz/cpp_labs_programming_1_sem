#include <iostream>
#include <ctime>
#define SIZE 1000
using namespace std;



void quickSort(int arr[], int left, int right) {
    int a = left, b = right;
    int tmp;
    int c = arr[(left + right) / 2];
    while (a <= b) {
        while (arr[a] < c) {
            a++;
        }
        while (arr[b] > c) {
            b--;
        }
        if (a <= b) {
            tmp = arr[a];
            arr[a] = arr[b];
            arr[b] = tmp;
            a++;
            b--;
        }
    }
    if (left < b)
        quickSort(arr, left, b);
    if (a < right)
        quickSort(arr, a, right);
}



int search (int sequence[],int start, int finish,int center, int number) {
    if ((finish - start) < 2) {
        return 0;
    }
    if (sequence[start] == number) {
        return start + 1;
    }
    if (sequence[finish] == number) {
        return finish + 1;
    }
    if (sequence[center] == number) {
        return center + 1;
    }
    if (sequence[center] < number) {
        return search(sequence, center, finish, (center + finish) / 2, number);
    }
    if (sequence[center] > number) {
        return search(sequence, start, center, (start + center) / 2, number);
    }
    return 0;
}



int main() {
    int number;
    int max_elem;
    int total = 0;

    cout << "Enter MAX element of sequence" << endl;
    cout << "MAX element should be > " << SIZE << endl;
    cin >> max_elem;
    cout << "Enter a number to choose if it is the element of sequence" << endl;
    cout << "Number should be < " << max_elem << endl;
    cin >> number;

    int sequence[SIZE];
    int start = 0, finish = SIZE - 1, center = (SIZE - 1) / 2;

    if(max_elem < SIZE){
        cout << "Incorrect data. Try again" << endl;
    }

    srand(time(NULL));
    for (int i = 0; i < SIZE - 1; i++) {
        sequence[i] = rand() % (max_elem - 1) + 1;
    }

    quickSort(sequence, 0, SIZE - 1);

    for (int i = 0; i < SIZE - 1; i++) {
        cout << sequence[i] << endl;
    }

    total = search(sequence, start, finish, center, number);

    if(total == 0){
        cout << "The number isn't in the sequence" <<endl;
    } else {
        cout << "The number of this numeric in the sequence is " << total << endl;
    }
    return 0;
}
