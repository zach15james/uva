#include <bits/stdc++.h>
using namespace std;

int main()
{

  vector<string> results; int N;
  while(scanf("%d", &N) == 1) // read N
  {
    if(N == 0) { break; } // if N == 0, end of input, print saved results
    
    // build ascending stack
    stack<int> start_clone; for(int i = N; i > 0; i--) { start_clone.push(i); }
     
    int f; // explicitly read first value to check it 

    while(scanf("%d", &f) == 1)
    {  // read in first value to check 
      //bool not_done_early = true;
      if(f == 0) break; // end of input for this N, breaks out to scan another N
      
      // init
      stack<int> start = start_clone;
      stack<int> st; 
      bool yes = true;


      // manual first iteration
      while(!start.empty() && start.top() <= f) { st.push(start.top()); start.pop(); }
      //if(st.top() == f) { st.pop(); } else { yes = false; st.pop(); }
      st.pop(); // above check unecessary, as its the first value and works by construction

      // rest of line (N-1) iterations
      for(int i = 0; i < N-1; i++)
      {
        scanf("%d", &f); // read in next value
        while(!start.empty() && start.top() <= f) { st.push(start.top()); start.pop(); }

        if(st.top() == f) { st.pop(); }
        else { yes = false; } // cheap answer, but it works 
      }

      // report result
      if(yes) results.push_back("Yes");
      else results.push_back("No");
    }
    // end of N case
    results.push_back("");
  } 
   
  for(string r : results) printf("%s\n", r.c_str());
  
  return 0;
} 
