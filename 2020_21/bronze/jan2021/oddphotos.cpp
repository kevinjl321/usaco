#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

int n, cows[1001];
int alt_1, alt_2, groups = 0;

int main(void){
    cin >> n;

    for(int i = 0; i < n; i++){cin >> cows[i];}
    for(int i = 0; i < n; i++){alt_1 += cows[i] % 2;}
    alt_2 = abs(alt_1 - n);

    if(alt_1 > alt_2){
        alt_1 = abs(alt_1 - alt_2);

        if(alt_1%3==0){groups=((alt_1*2)/3);}
        else if(alt_1%3==1){ groups=((alt_1*2-5)/3);}
        else if(alt_1%3==2){groups=((alt_1*2-1)/3);}

        cout << ((alt_2*2)+groups) << endl;
    }
    else{
        cout << ((alt_1*2)+1) << endl;
    }

    return 0;
}