#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        int sum = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int diff = sum - k;
            if(hashMap.find(diff) != hashMap.end()){
                res += hashMap[diff];
            }
            hashMap[sum]++;
        }
        return res;
    }
};