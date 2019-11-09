#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int max_elem;
    cout << "Enter max number of your array" << endl;
    cin >> max_elem;
    int Mas[10][10];
    srand(time(NULL));
    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Mas[i][j] = rand() % max_elem;
        }
    }
    for(int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << Mas[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl << endl;
    for(int i = 0; i < 10; i++){
        for(int k = 9 - i; k > 0; k--){
            cout << "  ";
        }
        for(int j = 9 - i; j < 10; j++){
            cout << Mas[i][j] << " ";
        }
        cout << endl;
    }
}