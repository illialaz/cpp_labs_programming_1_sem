#include <iostream>
#include <ctime>
#define SIZE 20
using namespace std;


int max(int arr[]) {
    int max1 = arr[0], max2 = 1, max3 = 1;
    for(int i = 1; i <= SIZE; i ++){
        if(arr[i] > max1){
            max2 = max1;
            max1 = arr[i];
            continue;
        }
        if(arr[i] > max2){
            max3 = max2;
            max2 = arr[i];
            continue;
        }
        if(arr[i] > max3){
            max3 = arr[i];
            continue;
        }
    }
    return max1 * max2 * max3;
}


int main() {
    int max_elem;
    int arr[SIZE];
    cout << "Enter MAX element of sequence" << endl;
    cin >> max_elem;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % (max_elem);
    }
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << endl;
    }
    cout << max(arr) << endl;
}

