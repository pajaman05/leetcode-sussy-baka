#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> brojac;
    int n = nums.size();
    set<int> documented;
    vector<int> topK;
    for(int i = 0; i < n; ++i) {
        ++brojac[nums[i]];
    }
    for (int i = 0; i < k; i++)
    {    
        int currMax = -1;
        for(auto &p : brojac) {
            bool isDocumented = documented.find(p.first) == documented.end();
            cout<<"p.first: "<<p.first<<" p.second: "<<p.second<<" Is documented: "<<isDocumented<<endl;
            if(p.second > brojac[currMax] && isDocumented)
            {
                currMax = p.first;
            }
        }
        cout<<"currMax: "<<currMax<<" brojac[currMax]: "<<brojac[currMax]<<endl;
        documented.insert(currMax);
        topK.push_back(currMax);
    }
    return topK;
}

int main() {

}