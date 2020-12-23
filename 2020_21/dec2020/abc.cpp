#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

int num[8];

int main(void){
    for(int i = 0; i < 7; i++){
        cin >> num[i];
    }
    sort(num, num + 7);

    int a = num[0];
    int b = num[1];
    int c = num[6] - (a + b);

    cout << a << " " << b << " " << c << endl;
    return 0;
}