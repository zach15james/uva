#include <bits/stdc++.h>
using namespace std;

// note: cabin baggage limits: 
// max length: 56cm, width: 45cm, depth: 25cm
// max sum of all sides (length+width+depth) <= 125cm
// weight <= 7kg
//
// input: 4 values, positive numbers, with 2 decimal points

int main()
{
  double length, width, depth, weight;
  int t; // number of test cases (ie. number of bags)
 
  scanf("%d", &t);
  vector<int> results; 
  //results.reserve(t+1);
  results.reserve(t);

  while(t--)
  {  
    scanf("%lf %lf %lf %lf", &length, &width, &depth, &weight);
    // max length, width, dept
    if((length > 56.00 || width > 45.00 || depth > 25.00) && (length+width+depth > 125.00) || weight > 7.00)
    { results.push_back(0); }
    else
    {
      // success! 
      results.push_back(1);

    }
  }
  
  // should iterate through results then the sum at the end
  for(int r : results)
  {
    printf("%d\n", r);
  }
  int sum_total = accumulate(results.begin(), results.end(), 0);

  printf("%d\n", sum_total);


 return 0;
}
