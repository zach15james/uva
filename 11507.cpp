#include <bits/stdc++.h>


using namespace std;


int main()
{
  int L;  // starting pointeed in +x direction
  
  // starting point: (0,0,0) w/ free extreme (L-1,0,0)
  // ending pt: (1,0,0)
  vector<pair<char,char>> results;

  while(scanf("%d", &L) == 1 && L != 0)
  {
    int x = 1, y = 0, z = 0;

    for(int l = 0; l < L-1; l++)
    {
      char command[4]; scanf("%s", command);
      
      if(strcmp(command, "No") == 0) continue;
      int old_x = x, old_y = y, old_z = z;

      if(strcmp(command, "+y") == 0)
      { x = -old_y; y = old_x; }
      else if(strcmp(command, "-y") == 0)
      { x = old_y; y = -old_x; } 
      else if(strcmp(command, "+z") == 0)
      { x = -old_z; z = old_x; }
      else if(strcmp(command, "-z") == 0)
      { x = old_z; z = -old_x; }
    }

    // final coordinate calculation
    string rs;
    if(x==1) rs = "+x";
    else if(x == -1) rs = "-x";
    else if(y == 1)  rs = "+y";
    else if(y == -1) rs = "-y";
    else if(z == 1)  rs = "+z";
    else if(z == -1) rs = "-z";
    else if(x == -1) { rs = -x; }

    results.push_back({rs[0], rs[1]});

  }
  
  for(auto result : results) { printf("%c%c\n", result.first, result.second); }
  return 0;
} 
