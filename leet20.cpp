#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
    int n = s.length();
    stack<char> checking;
    for(int i = 0; i < n; i++)
    {
        char toCheck = s[i];
        if(!checking.empty() &&
        ((checking.top() == '(' && s[i] == ')') ||
        (checking.top() == '[' && s[i] == ']') ||
        (checking.top() == '{' && s[i] == '}'))) {
            checking.pop();
        }
        else checking.push(s[i]);
    }
    if(checking.empty()) return true;
    return false;      
}

int main() {
    string a;
    cin>>a;
    if(isValid(a)) cout<<"valid"<<endl;
    else cout<<"not valid"<<endl;
    return 0;    
}