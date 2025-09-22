#include <bits/stdc++.h>
using namespace std;


int main()
{

    //freopen("input.txt", "r", stdin);   // read from input.txt

    // fast io 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line; // holds line 
    vector<string> lines;
    while(getline(cin, line))
    {
        lines.push_back(line);
    }

    for(string l : lines)
    {
        cout << l << "\n";
    }

    return 0;

}