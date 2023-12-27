#include <iostream>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};


int maxPathSum(TreeNode* root) {
   
    if (root == nullptr) {
        return 0;
    }

    int leftSum = maxPathSum(root->left);
    int rightSum = maxPathSum(root->right);

    int currentSum = max(root->val, max(leftSum, rightSum) + root->val);

    
    int maxSum = max(currentSum, leftSum + rightSum + root->val);

    return maxSum;
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

  
    int maxSum = maxPathSum(root);

   
    cout << "Max = " << maxSum << endl;

    return 0;
}
