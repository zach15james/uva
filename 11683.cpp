#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
int main()
{
  int A, C; // A: height, C: length
  vector<int> times;

  while(scanf("%d %d", &A, &C) == 2 && A != 0)
  {
    //printf("case #%d:\n", times.size());
    // read in values 
    int c_i; int t = 0;
    vector<int> arr; 
    for(int c = 0; c < C; c++)
    { scanf("%d", &c_i); /*printf("pushing back: %d\n", c_i);*/ arr.push_back(c_i); }
 
    // iterate through until finished
    for(int r = 0; r < A; r++)
    { 
      bool current_line = false;
 
      for(int c = 0; c < C; c++)
      {
        if(arr[c] <= r && !current_line)
        { t++; current_line = true; /*printf("t iterated to: %d at (r: %d, c: %d)\n", t, r, c);*/ }
        else if(arr[c] > r) { current_line = false; } // reset condition
      }
    }
    //printf("value of t: %d\n", t);
    times.push_back(t); 
  }

  for(int time : times) printf("%d\n", time);
  return 0;
}
