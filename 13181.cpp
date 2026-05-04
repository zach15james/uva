#include <bits/stdc++.h>
using namespace std;
#define FK 500000

int main()
{
  vector<int> results;

  char line[FK+2];
  while(fgets(line, sizeof(line), stdin))
  {
    bool x_virginity = true; int virgin_max = 0;
    line[strcspn(line, "\n")] = '\0';
    int ct = 0, max_ct = 0;
    for(int i = 0; i < strlen(line); i++)
    {
      if(line[i] == '.') { ct++; if(ct > max_ct) { max_ct = ct; } }
      else if(line[i] == 'X')
      {
        if(x_virginity) { virgin_max = ct; x_virginity = false; }
        if(ct > max_ct) { max_ct = ct; }
        ct = 0; // reset w/ X 
      }
      else { printf("[ERR] Neither a . or a X was taken in!\n"); }
    }
    
    // testing to see if it can even get the max ct right...
    /*
    if(ct > max_ct) { max_ct = ct; } // recording missing not ending in x case  
    if(max_ct <= virgin_max) { max_ct = virgin_max; max_ct++; }
    if(max_ct % 2 == 0)
    {
      max_ct /= 2; max_ct--;
      //results.push_back(max_ct);
    }
    else { max_ct--; max_ct /= 2; }
    */

    results.push_back(max_ct); 
  }

  for(int r : results) { printf("%d\n", r); }

  return 0; 
}
