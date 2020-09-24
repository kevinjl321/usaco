#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int findCowByName(vector<string> names, string s){
    for(int i = 0; i < names.size(); i++){
        if(names[i] == s){
            return i;
        }
    }
    return -1;
}

int main(){
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    
    int N;
    cin >> N;

    vector<string> names = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    int amount[7];

    for(int i = 0; i < N; i++){
        string s;
        int n;
        cin >> s >> n;
        amount[findCowByName(names, s)] += n;
    }

    int minimumAmount = 1000000;
		for(int i = 0; i < 7; i++) {
			if(amount[i] < minimumAmount) {
				minimumAmount = amount[i];
			}
		}
		
	int secondSmallestAmount = 1000000;
	for(int i = 0; i < 7; i++) {
		if(amount[i] > minimumAmount && amount[i] < secondSmallestAmount) {
			secondSmallestAmount = amount[i];
		}
	}

    const int NOT_FOUND = -1;
    const int MORE_THAN_ONE = -2;
	int indexOfSecondSmallest = NOT_FOUND;
    for(int i = 0; i < 7; i++){
        if(amount[i] == secondSmallestAmount) {
			if(indexOfSecondSmallest == NOT_FOUND) {
			    indexOfSecondSmallest = i;
			}
			else {
				indexOfSecondSmallest = MORE_THAN_ONE;
			}
		}
    }

    if(indexOfSecondSmallest >= 0) {
		cout << names[indexOfSecondSmallest] << endl;
	}
	else {
		cout << "Tie" << endl;
	}
    return 0;
}