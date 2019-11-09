#include <iostream>
#include <ctime>
#include <cmath>
#define SIZE 10
using namespace std;

int main(){
    int number, max_elem, total = 0, total_num = -1;
    cout << "Enter your number" << endl;
    cin >> number;
    cout << "Enter MAX element of your sequence" << endl;
    cin >> max_elem;

    int sequence[SIZE];
    srand(time(NULL));
    for (int i = 0; i <= SIZE - 1; i++) {
        sequence[i] = rand() % (max_elem - 1) + 1;
    }

    for (int i = 0; i <= SIZE - 1; i++) {
        if (abs(sequence[i] -  number) > total_num) {
            total_num = sequence[i];
            total = i;
        }
    }

    for (int i = 0; i <= SIZE - 1; i++) {
        cout << sequence[i] << endl;
    }

    cout << "The element most distant from the given is " << total_num << endl;
    cout << "It's number in the sequence is " << total + 1 << endl;
    return 0;
}
