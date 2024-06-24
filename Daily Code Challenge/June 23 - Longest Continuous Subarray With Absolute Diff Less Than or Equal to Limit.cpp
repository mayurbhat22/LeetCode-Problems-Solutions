#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, right = 0;
        priority_queue<pair<int, int>> maxHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        int maxLength = 0;
        while(right<nums.size()){
            maxHeap.push({nums[right], right});
            minHeap.push({nums[right], right});

            if(abs(maxHeap.top().first-minHeap.top().first) <= limit) {
                right++;
                maxLength = max(maxLength, right-left);
            }
            else{
                while(minHeap.size() && maxHeap.size() && abs(maxHeap.top().first-minHeap.top().first) > limit){
                    while(left >= maxHeap.top().second)
                        maxHeap.pop();
                    while(left >= minHeap.top().second)
                        minHeap.pop();
                    left++;
                }
                right++;
            }
        }
        return maxLength;
    }
};