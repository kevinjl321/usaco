#include <iostream>
using namespace std;

int main()
{
  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);
  
  int b_init, b_fin, s_init, s_fin, g_init, g_fin, p_init, p_fin;
  cin >> b_init >> b_fin >> s_init >> s_fin >> g_init >> g_fin >> p_init >> p_fin;
  
  int s_promote = (p_fin + g_fin + s_fin) - (p_init + s_init + g_init);
  int g_promote = (p_fin + g_fin)- (p_init + g_init);
  int p_promote = (p_fin - p_init);
  
  cout << s_promote << endl;
  cout << g_promote << endl;
  cout << p_promote << endl;
  
  return 0;
  
}
