#include<iostream>
using namespace std;

int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n;
    int m;
    cin >> n >> m;
    
   int speedLimits[100] = {0};
   int current = 0;
   for(int i = 0; i < n; i++){
       int s;
       cin >> s;
       int k;
       cin >> k;
       for(int j = 0; j < s; j++){
           speedLimits[current] = k;
           current++;
       }
   }

   int travelSpeed[100] = {0};
   current = 0;
   for(int i = 0; i < m; i++){
       int s;
       cin >> s;
       int k;
       cin >> k;
       for(int j = 0; j < s; j++){
           travelSpeed[current] = k;
           current++;
       }
    }

    int max = 0;
    for(int i = 0; i < 100; i++){
       if(travelSpeed[i] - speedLimits[i] > max){
           max = travelSpeed[i] - speedLimits[i];
        }
    }

    cout << max << endl;
}