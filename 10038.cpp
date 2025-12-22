#include <cstdio>
#include <vector>
#include <string>
#include <bitset> 
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
  int n;
  vector<string> results;
  while(scanf("%d", &n) != EOF)
  {
    bitset<3005> hit; // max
    int a,b; scanf("%d", &a);
    for(int i = 1; i < n; i++)
    {
      scanf("%d", &b);
      int diff = abs(b - a);
      if(diff > 0 && diff < n) { hit[diff] = 1; } //update if in valid range 
      a = b;
    }

    if(hit.count() == (n > 0 ? n-1 : 0)) { results.push_back("Jolly"); }
    else { results.push_back("Not jolly"); }
  }

  for(string s : results) { printf("%s\n", s.c_str()); }

  return 0;
}
