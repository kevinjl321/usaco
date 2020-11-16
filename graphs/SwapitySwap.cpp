#include<iostream>
using namespace std;
 
void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}
 
int N, K, A1, A2, B1, B2, res[101];
 
int nex(int x) {
	if (A1 <= x && x <= A2) {
        x = A1 + A2 - x;
    }
	if (B1 <= x && x <= B2) {
        x = B1 + B2 - x;
    } 
	return x;
}
 
int main() {
	setIO("swap");
    
	cin >> N >> K >> A1 >> A2 >> B1 >> B2;
	for (int i = 1; i <= N; ++i) {
		int p = 1, cur = nex(i);
		while (cur != i) {
			p++;
			cur = nex(cur);
		}
		int k = K % p;
		for (int j = 0; j < k; ++j) {
            cur = nex(cur);
        } 
		res[cur] = i;
	}
	for (int i = 1; i <= N; ++i) {
        cout << res[i] << endl;
    } 
}