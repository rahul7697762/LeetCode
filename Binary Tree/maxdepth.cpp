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
        int maxDepth(TreeNode* root) {
    
             if (!root) return 0;
             int depth = 0;
    
            queue<TreeNode*> q;
            q.push(root);
    
            while (!q.empty()) {
                int currentLevel = q.size();
                vector<int> res;
    
                for (int i = 0; i < currentLevel; ++i) {
                    TreeNode* front = q.front();
                    q.pop();
                    
    
                    if (front->left) q.push(front->left);
                    if (front->right) q.push(front->right);
                }
    
                depth++;
            }
    
            return depth;
    
            
        }
    };