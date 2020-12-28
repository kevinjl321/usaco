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
    setIO("breedflip");

    int n;
	cin >> n;

	string a;
	cin >> a;
	string b;
	cin >> b;

	int ans = 0;
	bool valid = false;
	for(int i = 0; i < n; i++){
		if(a[i] != b[i]){
			if(!valid){
				valid = true;
				ans++;
			}
		}
		else{
			valid = false;
		}
	}

	cout << ans << endl;
    return 0;
}