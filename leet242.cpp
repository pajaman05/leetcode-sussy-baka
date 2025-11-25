#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
bool isAnagram(string s, string t) {
    if(t.length() != s.length()) return false;
    map<char, int> letters; 
    for (int i = 0; i < s.length(); i++) {
        ++letters[s[i]];
    }
    for (int i = 0; i < t.length(); i++) {
        if(letters.find(t[i]) != letters.end()) {
            --letters[t[i]];
        }
        else return false;
    }
    for (auto &p : letters) {
        if(p.second != 0) return false;
    }
    return true;
}

int main() {

}