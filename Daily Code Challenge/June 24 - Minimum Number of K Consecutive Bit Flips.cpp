#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        deque<int> q;
        int res = 0;
        for(int i=0; i<nums.size(); i++){
            if(!q.empty() && i > q.front() + k - 1){
                q.pop_front();
            }

            if( (nums[i] + q.size()) % 2 == 0){
                if(i+k > nums.size()){
                    return -1;
                }
                res++;
                q.push_back(i);
            }
        }
        return res;
    }
};