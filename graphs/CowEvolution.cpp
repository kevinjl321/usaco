#include <iostream>
#include <vector>
#include<string>
using namespace std;
 
int N;
vector<string> characteristics[25];
vector<string> all_characteristics;

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(), "r", stdin);
	freopen((s+".out").c_str(), "w", stdout);
}
 
bool crossing(int a, int b) {
    int A = 0, B = 0, AB = 0;
    for (int i = 0; i < N; i++) {
        vector<string> &v = characteristics[i];
        bool has_a = false, has_b = false;
        for (int j = 0; j < v.size(); j++) {
            if (v[j]==all_characteristics[a]) {
                has_a = true;
            } 
            if (v[j]==all_characteristics[b]) {
                has_b = true;
            } 
        }

        if (has_a && has_b) {
            AB++;
        } 
        else if (has_a) {
            A++;
        } 
        else if (has_b) {
            B++;
        }
    }
    return AB > 0 && A > 0 && B > 0;
}
 
int main() {
    setIO("evolution");

    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            cin >> s;
            characteristics[i].push_back(s);
            bool found = false;
            for (int k = 0; k < all_characteristics.size(); k++) {
                if (all_characteristics[k] == s) {
                    found = true;
                } 
            }
            if(!found) {
                all_characteristics.push_back(s);
            } 
        }
    }
        
    int M = all_characteristics.size();
    bool ok = true;
    for (int a = 0; a < M; a++) {
        for (int b = a + 1; b < M; b++) {
            if (crossing(a, b)) {
                ok = false;
            }
        }
    } 
    
    if (ok) {
        cout << "yes" << endl;
    } 
    else {
        cout << "no" << endl;
    }

    return 0;
}