#include <vector>
#include <algorithm> 

using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left = 0, right = 0;
        int sum = 0;
        int windowSum = 0;
        int maxSum = 0;
        while(right<customers.size()){
            if(grumpy[right] == 1) windowSum += customers[right];
            else sum += customers[right];

            if((right-left+1) < minutes) right++;
            else if(right-left+1==minutes){
                maxSum = max(maxSum, windowSum);
                if(grumpy[left] == 1) windowSum -= customers[left];
                left++;
                right++;
            }
        }
        return sum + maxSum;
    }
};