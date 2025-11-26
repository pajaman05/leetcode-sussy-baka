#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> goal;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        goal[target - nums[i]] = i;
    }        
    for (int i = 0; i < n; i++) {
        if(goal.find(nums[i]) != goal.end() && goal[nums[i]] != i) {
            cout<<"nums[i] = "<<goal[nums[i]]<<" i = "<<i<<endl;
            if(goal[nums[i]] < i) return {goal[nums[i]], i};
            else return {i, goal[nums[i]]};
        }
    }
    return {0, 0};
}

int main (){
    vector<int> numsTest = {0, 4 , 3, 0};
    int targetTest = 0;
    vector<int> result = twoSum(numsTest, targetTest);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}