#include <vector>
#include <algorithm> 

using namespace std;

// Approach - 1
class Solution {
public:
    int sumEqualsToGoal(vector<int> &nums, int goal){
        if(goal<0) return 0;
        int sum = 0, count = 0;
        int l = 0, r = 0;
        while(r<nums.size()){
            sum += (nums[r] % 2);
            while(sum>goal){
                sum -= (nums[l] % 2);
                l++;
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        for(auto it : nums){
            it = it % 2;
        }
        return sumEqualsToGoal(nums, k) - sumEqualsToGoal(nums, k-1);
    }
};

//Approach - 2
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, odds = 0;
        int l = 0, m = 0, r = 0;
        while(r<nums.size()){
            if(nums[r] % 2 == 1) odds++;

            while(odds > k){
                if(nums[l] % 2 == 1) odds--;
                l++;
                m = l;
            }

            if(odds == k){
                while(nums[m] % 2 != 1){
                    m++;
                }
                res += m - l + 1;
            }
            r++;
        }
        return res;
    }
};