#include <bits/stdc++.h>
using namespace std;

int L[100005], R[100005];

int main()
{
  // optimizations
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  
  // real code:
  vector<string> output_results;
  int S, B;
  
  while(cin >> S >> B && (S != 0 || B != 0))
  {
    
    for(int i = 1; i <= S; i++) { L[i] = i - 1; R[i] = i + 1; }
    L[1] = 0; R[S] = 0;

    int l,r = 0;
    for(int i = 0; i < B; i++) //iterate throug the loss reports
    { 
      stringstream ss;

      cin >> l >> r;

      if(L[l] != 0) { R[L[l]] = R[r]; }
      if(R[r] != 0) { L[R[r]] = L[l]; }

      int new_left = L[l];
      int new_right = R[r];
      
      if(new_left == 0) {ss << "*"; } else { ss << new_left; }
      ss << " "; // keep that separating space
      if(new_right == 0) {ss << "*"; } else { ss << new_right; }
          
      output_results.push_back(ss.str());
    }
    output_results.push_back("-"); // asterisk after each case
  }

  for(const string& s : output_results) { cout << s << "\n"; }

  return 0;
}
