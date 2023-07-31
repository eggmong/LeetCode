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
    void merge(TreeNode* root1, TreeNode* root2, TreeNode* &mergedTree)
    {
        if(root1 == nullptr && root2 == nullptr)
        {
            return;
        }
        else if(root1 == nullptr && root2)
        {
            mergedTree = new TreeNode(root2->val);
            
            merge(root1, root2->left, mergedTree->left);
            merge(root1, root2->right, mergedTree->right);
        }
        else if(root1 && root2 == nullptr)
        {
            mergedTree = new TreeNode(root1->val);
            
            merge(root1->left, root2, mergedTree->left);
            merge(root1->right, root2, mergedTree->right);
        }
        else
        {
            mergedTree = new TreeNode(root1->val + root2->val);
            
            merge(root1->left, root2->left, mergedTree->left);
            merge(root1->right, root2->right, mergedTree->right);
        }        
    }
    
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        TreeNode* mergedTree(nullptr);
        merge(root1, root2, mergedTree);
        
        return mergedTree;
    }
};