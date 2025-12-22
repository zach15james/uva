#include <bits/stdc++.h>
#include <list>
using namespace std;


int main()
{
  int n;
  vector<vector<int>> results;
  while(scanf("%d", &n) == 1 && n != 0)
  {
    vector<tuple<int,int,int>> arr; // { given: car_number(C), end_idx(P), ?: start_idx =: n) }
    vector<int> result(n, 0);

    //list<int> start; 
    int C,P;
    for(int i = 0; i < n; i++)
    { scanf("%d %d", &C,&P); arr.push_back({C,P, i}); }
    
    // sorted in descending abs value order (of greatest to least permutation change)  
    sort(arr.begin(), arr.end(), [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) 
        { return abs(get<1>(a)) > abs(get<1>(b)); });
    
    bool possible = true;
    // follow instructions to get to start array (list here)
    for(int i = 0; i < n; i++)
    {

      int start_position = get<2>(arr[i]) + get<1>(arr[i]); // start positionition - change
      
      if(start_position >= n || start_position < 0 || result[start_position] != 0)
      { possible = false; break; } 
      else {result[start_position] = get<0>(arr[i]); }

    }    

    if(!possible || find(result.begin(), result.end(), 0) != result.end())
    { // 0 value IS found ie final start vector incomplete
      results.push_back({-1});
    }
    else { results.push_back(result); }
    
  }

  for(auto& r : results)
  {
    if(r[0] == -1) { printf("-1\n"); continue;  }
    else
    { for(int i = 0; i < r.size(); i++) { printf("%d%c", r[i], (i == r.size() - 1? '\n' : ' ')); }
    }
  }

  return 0;
}
