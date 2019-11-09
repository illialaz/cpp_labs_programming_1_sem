#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int hp = 100;
    int n = 0;
    float b = 0;
    double s = 0;
    srand(time(0));
    while(1){
        for(int i = 0; i < 40; i++){
            hp -= (rand()%5 + 2);
            hp += 2;
        }
        if(hp <= 0){
            b++;
        }
        n++;
        s = b/n * 100;
        if(n%400000 == 0){
            cout << s << '%' <<'\n';
        }
        hp = 100;
    }
    return 0;
}