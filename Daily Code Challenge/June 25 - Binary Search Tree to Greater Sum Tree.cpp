#include <vector>
#include <algorithm> 
#include <queue>

using namespace std;

class Solution {
public:
    void bstToGst(TreeNode* root, int &maxValue){
        if(!root) return;

        bstToGst(root->right, maxValue);
        maxValue = root->val += maxValue;
        bstToGst(root->left, maxValue);

    }

    TreeNode* bstToGst(TreeNode* root) {
        int maxValue = 0;
        bstToGst(root, maxValue);
        return root;
    }
};