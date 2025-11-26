#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> outAnagrams;
    vector<map<char, int>> charPool;
    bool first = true;
    int n = strs.size();
    int emptyIndex = -1;
    for (int i = 0; i < n; ++i) {
        if(first) {
            map<char, int> tempMap;
            for(int j = 0; j < strs[i].length(); ++j) {
                ++tempMap[strs[i][j]];
            }
            charPool.push_back(tempMap);
            outAnagrams.push_back({strs[i]});
            first = false;
            if(strs[i] == "") emptyIndex = 0;
        }
        else if(strs[i] == "" && emptyIndex == -1) {
            emptyIndex = charPool.size();
            outAnagrams.push_back({""});
            cout<<"First empty string with index "<<emptyIndex<<endl;
        }
        else if(strs[i] == "") {
            outAnagrams[emptyIndex].push_back("");
            cout<<"Empty string No. "<<outAnagrams[emptyIndex].size()<<endl;
        }
        else {
            for(int j = 0; j < charPool.size(); ++j) {
                map<char, int> tempMap = charPool[j];
                bool makeNew = false;
                bool addToExisting = true;
                for(int k = 0; k < strs[i].length(); ++k) {
                    cout<<"Current count of "<<strs[i][k]<<" is "<<tempMap[strs[i][k]]<< " in pool number "<<j<<endl; 
                    if(tempMap[strs[i][k]] > 0) {
                        --tempMap[strs[i][k]];
                    }
                    else if(j + 1 >= charPool.size()) {
                        makeNew = true;
                        cout<<"Making new... - Current pool size: "<<charPool.size()<<" | Trigger word: "<<strs[i]<<endl;
                        break;
                    } 
                    else {
                        addToExisting = false;
                        break;
                    }
                }
                
                if(!makeNew && j + 1 >= charPool.size()) {      
                    for(auto &p : tempMap) {
                        if(p.second != 0) {
                            cout<<"Making new... - Current pool size: "<<charPool.size()<<" | Trigger word: "<<strs[i]<<endl;
                            makeNew = true;
                            break;
                        }
                    }
                }
                
                if(makeNew){    
                    map<char, int> tempMap2;
                    for(int k = 0; k < strs[i].length(); ++k) {
                        ++tempMap2[strs[i][k]];
                    }
                    charPool.push_back(tempMap2);
                    outAnagrams.push_back({strs[i]});
                    break;
                }
                else if(addToExisting){
                    cout<<"Adding to existing pool..."<<endl;
                    outAnagrams[j].push_back(strs[i]);
                    break;
                }
            }
        }
    }
    return outAnagrams;
}

int main() {
    vector<string> testStrs = {"stop","pots","reed","","tops","deer","opts",""};
    vector<vector<string>> result = groupAnagrams(testStrs);
    int i = 1;
    for(auto &a : result) { 
        for(auto &b : a) {
            cout<<b<<" "<<i<<endl;
        }
        ++i;
    }
    
    return 0;
}