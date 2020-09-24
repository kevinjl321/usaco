#include<iostream>
#include<map>
#include<string>

using namespace std;

map<string, int> m;

int main(){
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    
    int n;
    cin >> n;
    if (n == 1){
        string x;
        cin >> x;
        cout << x;
        return 0;
    }

    string cowNames[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    for (int i = 0; i < n; i++){
        int y;
        string x;
        cin >> x >> y;
        m[x] += y;
    }

    int lowest = 100000000;
    int secondLowest = 100000000;
    int secondLowestIndex;
    bool tie = false;
    for (int i = 0; i < 7; i++){
        if (lowest >= m[cowNames[i]]){
            lowest = m[cowNames[i]];
        }
    }
    for (int i = 0; i < 7; i++){
        if (secondLowest > m[cowNames[i]] && m[cowNames[i]] != lowest){
            secondLowest = m[cowNames[i]];
            secondLowestIndex = i;
            tie = false;
        }
        else if (secondLowest == m[cowNames[i]]){
            tie = true;
        }
    }
    if (tie){
        cout << "Tie" << endl;
    }
    else{
        cout << cowNames[secondLowestIndex] << endl;
    }
}