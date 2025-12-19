#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <algorithm> // std::find
#include <cmath>


int main()
{
  int C;
  std::cin >> C; std::cin.ignore();
  std::vector<int> results; 

  for(int i = 0; i < C; i++)
  {
    std::string S, T;
    std::getline(std::cin, S); std::getline(std::cin, T);

    int zero = 0, one = 0, question = 0;

    for(int j = 0; j < S.size(); j++) 
    {
      if(S[j] != T[j])
      {
        if(S[j] == '?') { question++; }
        else if(S[j] == '0') { zero++; }
        else { one++; }
      }
    }
    
    //int answer = (std::max(zero, one) - std::min(zero, one)) + std::min(zero,one) + question;
    int answer = (std::count(S.begin(), S.end(), '1') > std::count(T.begin(), T.end(), '1')) ? -1 : std::abs(zero - one) + std::min(zero, one) + question;
    results.push_back(answer); 
  
  }

  for(int c = 0; c < C; c++)
  { std::cout << "Case " << c+1 << ": " << results[c] << "\n"; }

  return 0;
} 
