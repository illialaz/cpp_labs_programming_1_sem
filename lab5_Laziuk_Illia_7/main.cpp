#include <iostream>
using namespace std;

int main() {
    int* A, n;
    cin >> n;
    int* C;
    int* B;
    A = new int[n];
    C = A;
    for(int i = 0;  i < n; i++){
        cin >> *(A + i);
    }
    for(B = A+1; B < A + n; B++){
        int tmp = 0;
        while((C - tmp) >= A && (*(C - tmp) > *(B - tmp))){
            int tmp1 = *(C - tmp);
            *(C - tmp) = *(B - tmp);
            *(B - tmp) = tmp1;
            tmp++;
        }
        C++;
    }
    for(int i = 0; i < n; i++){
        cout << *(A+i) << '\t';
    }
    return 0;
}
