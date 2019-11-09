#include <iostream>
#include <ctime>
using namespace std;

void arr_fil(int mas[15]){
    int n, c = 0;
    for(int i = 1; i < 6; i++){
        cin >> n;
        mas[c] = n/100000;
        c++;
        mas[c] = (n%10000)/1000;
        c++;
        mas[c] = (n%100)/10;
        c++;
    }
}

int del_2(int mas[15]){
    int c = 0;
    for(int i = 0; i < 15 - c; i++){
        if((mas[i]%2) == 0){
            for(int j = 0; j< 15 - i; j++){
                mas[i + j] = mas[i + j +1];
            }
            mas[14 - c] = 0;
            c ++;
            i --;
        }
    }
    return c;
}

int main() {
    int mas[15] = {0};
    cout << "Enter 5 6-digit numbers" << endl;
    arr_fil(mas);
    int num_of_del = (15 - del_2(mas));
    for(int i = 0; i < 15; i++){
        if(mas[i] == 0){
            break;
        }
        cout << mas[i];
    }
    int N;
    cout << endl << "Enter N (size of matrix N*N)" << endl;
    cin >> N;
    int** matrix;
    matrix = new int* [N];
    for(int i = 0; i < N; i++){
        matrix[i] = new int [N];
    }
    int n = num_of_del;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matrix[i][j] = mas[((num_of_del)%n)];
            num_of_del++;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j - N; j++){
            cout << matrix[i][j];
        }
        cout << endl;
    }
    return 0;
}
