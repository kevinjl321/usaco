#include<iostream>
#include<string>
using namespace std;

bool cows_infected[101];
int n, cowx[251], cowy[251];

bool consistent(int p_zero, int k){
    bool infected[101] = {false};
    int num_handshakes[101] = {0};
    infected[p_zero] = true;
    for(int i = 0; i < 251; i++){
        int x = cowx[i];
        int y = cowy[i];
        if(x > 0){
            if (infected[x]){
                num_handshakes[x]++;
            }
            if (infected[y]){
                num_handshakes[y]++;
            } 
            if (num_handshakes[x] <= k && infected[x]){
               infected[y] = true; 
            } 
            if (num_handshakes[y] <= k && infected[y]){
                infected[x] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(infected[i] != cows_infected[i]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int t;
    string s;

    cin >> n >> t >> s;
    for(int i = 1; i <= n; i++){
        cows_infected[i] = s[i - 1] =='1';
    }
    for(int i = 0; i < t; i++){
        int time, x, y;
        cin >> time >> x >> y;
        cowx[time] = x;
        cowy[time] = y;
    }

    bool i_val[101] = {false};
    bool k_val[251] = {false};
    
    for(int i = 1; i <= n; i++){
        for(int K = 0; K < 252; K++){
            if(consistent(i, K)){
                i_val[i] = true;
                k_val[K] = true;
            }
        }
    }

    int min = 251;
    int max = 0;
    int zero = 0;

    for(int i = 0; i < 252; i++){
        if(k_val[i]){
            max = i;
        }
    }
    for(int i = 251; i >= 0; i--){
        if(k_val[i]){
            min = i;
        }
    }
    for(int i = 1; i <= n; i++){
        if(i_val[i]){
            zero++;
        }
    }

    cout << zero << " " << min << " ";
    if(max == 251){
        cout << "Infinity" << endl;
    }
    else{
        cout << max << endl;
    }
    return 0;
}
