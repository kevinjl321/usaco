#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int c[3];
    int m[3];

    for(int i = 0; i < 3; i++){
        cin >> c[i] >> m[i];
    }

    int i = 0;
    while(i < 100) {
        int milk = min(c[(i+1) % 3] - m[(i+1) % 3], m[i % 3]);
        m[(i+1) % 3] += milk;
        m[i % 3] -= milk;
        i++;
    }

    for(int i = 0; i < 3; i++){
        cout << m[i] << endl;
    }

    return 0;
}