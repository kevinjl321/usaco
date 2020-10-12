#include<iostream>
#include<algorithm>
using namespace std;

int n;
int apples[20];

int main(){
    cin >> n;
    long long sum = 0;

    for(int i = 0; i < n; i++){
        cin >> apples[i];
        sum += apples[i];
    }   

    long long ans = 0;
    for(int i = 0; i < 1 << n; i++){
        long long c_sum = 0;
        for(int j = 0; j < n; j++){
            if(i >> j & 1){
                c_sum += apples[j];
            }
        }
        if(c_sum <= sum / 2){
            ans = max(ans, c_sum);
        }
    }

    cout << sum - (2 * ans) << endl;
    return 0;
}