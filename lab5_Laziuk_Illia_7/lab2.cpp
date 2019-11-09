#include <iostream>
#include <ctime>
using namespace std;

int main(){
    int n, m, tmp;
    cin >> n >> m;
    int ** matrix;
    matrix = new int* [m];
    for(int i = 0; i < m; i++){
        *(matrix + i) = new int[n];
    }
    srand(time(0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            *(*(matrix + i) + j) = rand()%10;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << *(*(matrix + i) + j);
        }
        cout << endl;
    }
    cout << "\n\n\n";
    int string1, string2;
    cin >> string1 >> string2;
    swap(*(matrix + string1 - 1),*(matrix + string2 - 1));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << *(*(matrix + i) + j);
        }
        cout << endl;
    }
    return 0;
}
