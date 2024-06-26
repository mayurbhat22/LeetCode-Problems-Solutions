class Solution {
public:
    void inOrderTraversal(TreeNode* root, vector<int> &inorder){
        if(!root) return;
        inOrderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        inOrderTraversal(root->right, inorder);
    }

    TreeNode* convertToBalancedBST(vector<int> &inorder, int low, int high){
        if(low>high) return NULL;

        int mid = low + (high - low)/2;
        TreeNode* node = new TreeNode(inorder[mid]);
        node->left = convertToBalancedBST(inorder, low, mid-1);
        node->right = convertToBalancedBST(inorder, mid+1, high);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return NULL;
        vector<int> inorder;
        inOrderTraversal(root, inorder);
        return convertToBalancedBST(inorder, 0, inorder.size()-1);
    }
};