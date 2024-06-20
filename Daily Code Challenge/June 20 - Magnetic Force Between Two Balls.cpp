#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int possibleMaxDistance(vector<int>& position, int m, int distance){
        int count = 1;
        int prevPosition = position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i]-prevPosition >= distance){
                count++;
                prevPosition = position[i];
            }
        }
        if(count >= m) return true;
        else return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int ans = 0;
        int low = 0;
        int high = position[n-1];
        while(low<=high){
            int mid = low + (high - low) / 2;
            if(possibleMaxDistance(position, m, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};