#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int max_elem;
    cout << "Enter max number of your array" << endl;
    cin >> max_elem;
    int Mas[10][10];
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<10; j++){
            Mas[i][j] = rand() % max_elem;
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j<10; j++){
            cout << Mas[i][j] << ' ';
        }
        cout << endl;
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i + j == 9 || i == j){
                cout << Mas[i][j] << ' ';
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}
