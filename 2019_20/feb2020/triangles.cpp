#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    if((name).size()){
        freopen((name+".in").c_str(), "r", stdin); 
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(void){
    setIO("triangles");

    int x[101];
    int y[101];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    }

	int ans = 0;
    for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(y[i] == y[j] && x[i] == x[k]){
					int area = abs((x[j] - x[i])*(y[k] - y[i]));
					if(area > ans){
						ans = area;
					}
				}
			}
		}
    }

	cout << ans << endl;
    return 0;
}