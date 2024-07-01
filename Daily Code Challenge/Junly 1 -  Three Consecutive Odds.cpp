#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<=n-3; i++){
            if(arr[i] & 1){
                if(arr[i+1] & 1){
                    if(arr[i+2] & 1){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};