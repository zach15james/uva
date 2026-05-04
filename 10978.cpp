#include <bits/stdc++.h>
using namespace std;

//typedef enum {H, D, C, S} Suit;

int main()
{
  int N; scanf("%d\n", &N);
  vector<char[3]> cards(N); 

  for(int i = 0; i < N; i++)
  {
    char value, suit; char eat_word[7]; // may have to change if value ~ eat_word are !unique
    scanf("%c%c %s\n", &value, &suit, &eat_word);
    int moves = eat_word.length();
    int M = moves;
    while(moves>0) // check if off-by-one later
    {
      char c = cards[M-moves][0];
      if((c >= '1' && c <= '9') || c == 'A' || c == 'J' || c == 'Q' || c == 'K'))
      {
        // already filled spot :(

      }
      else
      {
        moves--;
      }
    }
    
    //printf("val: %c, suit: %c, eat: %s\n", value, suit, eat_word);
  }

  scanf("%d", &N); // eat the 0 
  
  return 0;
}
