#include <iostream>
using namespace std;
 
int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int N, M;
    int A[151], B[151], G[101];

    cin >> N >> M;
    for (int i = 0; i < M; i++) { 
        cin >> A[i] >> B[i];
        if (A[i] > B[i]) {
            swap (A[i], B[i]);
        } 
    }

    for (int i = 1; i <= N; i++) {
        int g;
        for (g = 1; g <= 4; g++) {
            bool ok = true;
            for (int j = 0; j < M; j++) {
                if (B[j] == i && G[A[j]] == g) {
                    ok = false;
                } 
            }
            if (ok){
                break;
            }
        }
        G[i] = g;
        cout << g;
    }
    
    cout << endl;
    return 0;
}