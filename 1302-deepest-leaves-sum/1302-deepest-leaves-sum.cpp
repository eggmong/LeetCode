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
class Solution {
public:
    int deepestLeavesSum(TreeNode* root)
    {
    // 가장 깊은 레벨의, 같은 레벨 노드끼리의 합 구하기

    int answer = 0;
    int currentLevel = 0;

    queue<TreeNode*> queue;
    queue.push(root);

    while (queue.empty() == false)
    {
        currentLevel = queue.size();
        answer = 0;

        for (int i = 0; i < currentLevel; i++)
        {
            TreeNode* current = queue.front();
            queue.pop();

            answer += current->val;

            if (current->left != nullptr)
            {
                queue.push(current->left);
            }

            if (current->right != nullptr)
            {
                queue.push(current->right);
            }
        }
    }

    return answer;
    }
};