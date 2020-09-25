#include<iostream>
using namespace std;

int k, n;
int datas[10][20];

bool better(int a, int b, int session)
{
  int apos, bpos;
  for (int i = 0; i < n; i++) {
    if (datas[session][i] == a) apos = i;
    if (datas[session][i] == b) bpos = i;
  }
  return apos < bpos;
}
 
int Nbetter(int a, int b)
{
  int total = 0;
  for (int session=0; session< k; session++)
    if (better(a,b,session)) total++;
  return total;
}

int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    cin >> k >> n;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin >> datas[i][j];
        }
    }

    int answer = 0;
    for (int a=1; a<=n; a++)
        for (int b=1; b<=n; b++)
            if (Nbetter(a,b) == k) 
                answer++;
    
    cout << answer << endl;
}