#include <iostream>
using namespace std;

int N, x[100], passto[100]; 

int target(int i) {
    int left_nbr = -1, left_dist = 1000;
    int right_nbr = -1, right_dist = 1000;
                                                                                                
    for (int j = 0; j < N; j++){
        if (x[j] < x[i] && x[i] - x[j] < left_dist){ 
            left_nbr = j; 
            left_dist = x[i] - x[j];
        }
    }
    for (int j = 0; j < N; j++){
        if (x[j] > x[i] && x[j] - x[i] < right_dist){ 
            right_nbr = j; 
            right_dist = x[j] - x[i]; 
        }
    }

    if (left_dist <= right_dist){
        return left_nbr;
    }
    return right_nbr;
}

int main(void){
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> x[i];
    }

    for (int i = 0; i < N; i++){
        passto[target(i)]++;
    } 

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (passto[i] == 0){
            ans++;
        }                                                          
        if (i < target(i) && target(target(i)) ==i && passto[i]==1 && passto[target(i)]==1){
            ans++;
        }                                                                               
    }

    cout << ans << endl;
    return 0;
}