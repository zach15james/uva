#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n; scanf("%d", &n);

  //int load[n];
  vector<long long> load(n);
  long long total = 0; 


  for(int i = 0; i < n; i++)
  { 
    scanf("%lld", &load[i]);
    total += load[i]; 
  }

  //int *res;
  vector<ing> res;
  
  for(int i = 0; i < n; i++)
  {
    if(load[i] * 2 > 2LL * total) res.push_back(i);
  }

  // output code here
  for(size_t i = 0; i < res.size(); i++)
  { printf("%d\n", res[i]); }

  return 0;
}
