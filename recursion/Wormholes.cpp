#include <iostream>
using namespace std;

int N, X[13], Y[13];
int partner[13];
int next_on_right[13];

bool cycle_exists(void) {
    for (int start = 1; start <= N; start++) {
        int pos = start;
        for (int count = 0; count < N; count++) {
            pos = next_on_right[partner[pos]];
        }
        if (pos != 0){
            return true;
        }
    }
    return false;
}

int solve(void) {
    int i, total = 0;
    for (i = 1; i <= N; i++) {
        if (partner[i] == 0) break;
    }

    if (i > N) {
        if (cycle_exists()){
            return 1;
        }
        else{
            return 0;
        }
    }

    for (int j = i + 1; j <= N; j++) {
        if (partner[j] == 0) {
            partner[i] = j;
            partner[j] = i;
            total += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return total;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (X[j] > X[i] && Y[i] == Y[j]) {
                if (next_on_right[i] == 0 || X[j] - X[i] < X[next_on_right[i]] - X[i]) {
                    next_on_right[i] = j;
                }
            }
        }
    }

    cout << solve() << endl;
    return 0;
}