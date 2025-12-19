#include <bits/stdc++.h>
using namespace std;

int main()
{
  //printf("start\n");
  // TC must be within budget, same hotel, 
  int N, B, H, W; // N: participans, B: budget, H: hotels, W: weeks 
  
  vector<int> cost;
  int t = 0; // test case # 
  while(scanf("%d %d %d %d", &N, &B, &H, &W) == 4) // read 4 values? 
  { 
    vector<int> test_case_costs;

    for(int h = 0; h < H; h++)
    {
      int p; scanf("%d", &p); //a[h][0] = p;
      
      for(int w = 0; w < W; w++)
      {
        int beds; scanf("%d", &beds);
        if(N <= beds && (N * p <= B) )
        { test_case_costs.push_back(N * p); }
      }   
    }
    
    auto min_it = min_element(test_case_costs.begin(), test_case_costs.end());

    if(min_it == test_case_costs.end())
    {
      // no valid one there
      cost.push_back(-1);
    } else { cost.push_back(*min_it); }
    t++;
  }

  for(int c : cost)
  {
    if(c == -1) printf("stay home\n");
    else printf("%d\n", c); // note: min_element returns an iterator
  }

  return 0;
}

