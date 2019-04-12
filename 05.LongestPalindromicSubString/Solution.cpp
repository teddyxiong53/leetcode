#include <vector>
#include <iostream>
#include <string>

using namespace std;

string manacher(string s) {
    string t = "$#";
    for(int i=0; i<s.size(); i++) {
        t += s[i];
        t += "#";
    }
    vector<int> p(t.size(), 0);
    int mx = 0;
    int id = 0;
    int resLen = 0;
    int resCenter = 0;
    for(int i=1; i<t.size(); i++) {
        if(mx > i) {
            p[i] = min(p[2*id - i], mx- i);
        } else {
            p[i] = 1;
        }
        while(t[i+p[i]] == t[i-p[i]]) {
            p[i]++;
        }
        if(mx < 1+p[i]) {
            mx = i+p[i];
            id = i;
        }
        if(resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter-resLen)/2, resLen-1);
}

int main()
{
    string s1 = "122122";
    cout << manacher(s1) << endl;
}


