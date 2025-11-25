#include <iostream>
#include <vector>
#include <set>

using namespace std;
bool containsDuplicate(vector<int>& nums) {
    set<int> existing;
    for(int i = 0; i < nums.size(); ++i) {
        if(existing.find(nums[i]) == existing.end()) {
            existing.insert(nums[i]);
        } 
        else {
            return true;
        }
    } 
    return false;
}

int main() {

}