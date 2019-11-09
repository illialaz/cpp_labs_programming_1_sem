#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int min_elem;
    int min_column;
    int max_elem = 0; //max elem should be = min
    int max_column;
    cout << "Enter max number of your array" << endl;
    cin >> min_elem; //min elem should = max
    int Mas[5][10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            Mas[i][j] = rand() % min_elem; //elements in array will be < max
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++) {
            if(Mas[i][j] > max_elem) {
                max_elem = Mas[i][j];
                max_column = j;
            }
            if(Mas[i][j] < min_elem) {
                min_elem = Mas[i][j];
                min_column = j;
            }
        }
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 5; j++) {
            cout << Mas[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl << endl << endl << endl;
    // Change columns with max and min element
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 5; j++) {
            if(j == max_column){
                cout << Mas[i][min_column] << "   ";
                continue;
            }
            if(j == min_column){
                cout << Mas[i][max_column] << "   ";
                continue;
            }
            cout << Mas[i][j] << "   ";
        }
        cout << endl;
    }
}

