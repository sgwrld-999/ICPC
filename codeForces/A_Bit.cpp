#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int x = 0 ;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i][1] == '+')
        {
            x++;
        }
        else
        {
            x--;
        }
    }
    cout << x << endl;
    return 0;
}
