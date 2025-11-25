#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int DoOpp(string opp, int a, int b) {
    cout<<"doing opp"<<endl;
    if(opp == "+"){
        return a + b;    
    }
    else if(opp == "-"){
        return a - b;    
    }
    else if(opp == "*"){
        return a * b;    
    }
    else if(opp == "/"){
        return a / b;    
    }
    return 0;
}
int evalRPN(vector<string>& tokens) {
    //cout<<"tryin'"<<endl;
    stack<string> opp;
    stack<int> nums;
    int res = 0;
    bool prevNum = false;
    while(!tokens.empty()) {
        if(tokens.back() == "+") {
            opp.push("+");
            tokens.pop_back();
            prevNum = false;
            cout<<"got plus"<<endl;
        }
        else if(tokens.back() == "-") {
            opp.push("-");
            tokens.pop_back();
            prevNum = false;
        }
        else if(tokens.back() == "*") {
            opp.push("*");
            tokens.pop_back();
            prevNum = false;
            cout<<"got a mult"<<endl;
        }
        else if(tokens.back() == "/") {
            opp.push("/");
            tokens.pop_back();
            prevNum = false;
        }
        else if(prevNum == true) {
            res = DoOpp(opp.top(), stoi(tokens.back()), nums.top());
            tokens.pop_back();
            nums.pop();
            opp.pop();
            cout<<"did the opp and pop current res = " << res<<endl;
            while(!opp.empty())
            {
                res = DoOpp(opp.top(), res, nums.top());
                cout<<"did the opp and pop current res = " << res<<endl;
                opp.pop();
                nums.pop();
                cout<<"poppin'"<<endl;
            }
            prevNum = false;
        }
        else {
            cout<<"got a num"<<endl;
            nums.push(stoi(tokens.back()));
            tokens.pop_back();
            prevNum = true;
        }
    }
    return res;
}

int main() {
    vector<string> s = {"4","13","5","/","+"};
    cout<<evalRPN(s)<<endl;
}