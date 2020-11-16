#include <iostream>
using namespace std;
 
int N, a, b;
int d[100000];
 
int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

	cin >> N;
	for(int i = 1;i < N;i++) {
		cin >> a >> b;
		d[a - 1]++, d[b - 1]++;
	}

	int D = 0;
	for(int i = 0;i < N; i++) {
		if(d[i] > D) {
			D = d[i];
        }
    }
	cout << D + 1 << endl;
}