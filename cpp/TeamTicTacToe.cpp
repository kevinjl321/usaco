#include <iostream>
using namespace std;
 
char B[3][3];
 
int cow_wins(char ch){
  if (B[0][0] == ch && B[1][1] == ch && B[2][2] == ch) return 1;
  if (B[0][2] == ch && B[1][1] == ch && B[2][0] == ch) return 1;

  for (int i=0; i<3; i++){
    if (B[0][i] == ch && B[1][i] == ch && B[2][i] == ch) return 1;
    if (B[i][0] == ch && B[i][1] == ch && B[i][2] == ch) return 1;
  }
  return 0; 
}
 
bool check3(char ch1, char ch2, char a, char b, char c) {
    if (a != ch1 && a != ch2) return false;
    if (b != ch1 && b != ch2) return false;
    if (c != ch1 && c != ch2) return false; 
    if (a != ch1 && b != ch1 && c != ch1) return false;
    if (a != ch2 && b != ch2 && c != ch2) return false;
    return true;
}
 
int team_wins(char ch1, char ch2){
    if (check3(ch1, ch2, B[0][0], B[1][1], B[2][2])) return 1;
    if (check3(ch1, ch2, B[0][2], B[1][1], B[2][0])) return 1;

    for (int i=0; i<3; i++) {
        if (check3(ch1, ch2, B[0][i], B[1][i], B[2][i])) return 1;
        if (check3(ch1, ch2, B[i][0], B[i][1], B[i][2])) return 1;
    }
    return 0; 
}
 
int main(void)
{
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
  
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
        cin >> B[i][j];
    
    int answer1 = 0, answer2 = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++) 
        answer1 += cow_wins(ch);
    for (char ch1 = 'A'; ch1 <= 'Z'; ch1++) 
        for (char ch2 = ch1+1; ch2 <= 'Z'; ch2++) 
        answer2 += team_wins(ch1, ch2);
    
    cout << answer1 << endl << answer2 << endl;
    return 0;
}