/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        vector<TreeNode*> nodeVector;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            TreeNode* node = new TreeNode(nums[i]);
            
            while (nodeVector.empty() == false && nodeVector.back()->val < nums[i])
            {
                node->left = nodeVector.back();
                nodeVector.pop_back();
            }
            
            if (nodeVector.empty() == false)
            {
                nodeVector.back()->right = node;
            }
            
            nodeVector.push_back(node);
        }
        return nodeVector.front();
    }
};