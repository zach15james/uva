#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 2k lines of inputs (terminated by single line w/ #)
    // each line, string S: w/ max length 14
    vector<string> lines;
    string line;
    while(getline(cin, line) && line != "#")
    {
        lines.push_back(line); // add it to vector array
    }

    for(int i = 0; i < (int)lines.size(); i++)
    {
        line = lines.at(i);
        //cout << line;

        if(line == "HELLO") { cout << "Case " << i+1 << ": ENGLISH\n"; }
        else if(line == "HOLA") { cout << "Case " << i+1 << ": SPANISH\n"; }
        else if(line == "HALLO") { cout << "Case " << i+1 << ": GERMAN\n"; }
        else if(line == "BONJOUR") { cout << "Case " << i+1 << ": FRENCH\n"; }
        else if(line == "CIAO") { cout << "Case " << i+1 << ": ITALIAN\n"; }
        else if(line == "ZDRAVSTVUJTE") { cout << "Case " << i+1 << ": RUSSIAN\n"; }
        else { cout << "Case " << i+1 << ": UNKNOWN\n"; }
    }

    return 0;
}