#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    bool minDays(vector<int> &bloomDay, int m, int k, int day){
        int bouque = 0;
        int flowers = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                flowers++;
                if(flowers == k) {
                    bouque++;
                    flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }
        if(bouque >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // if(m * k > bloomDay.size()) return -1;
        int minVal = 0;
        int maxVal = 0;
        for(auto it : bloomDay){
            minVal = min(minVal, it);
            maxVal = max(maxVal, it);
        }
        int low = minVal;
        int high = maxVal;
        int ans = -1;
        while(low<=high){
            int mid  = low + (high - low) / 2;
            if(minDays(bloomDay, m, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};