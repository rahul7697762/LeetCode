class Solution {
    public:
        TreeNode* findMin(TreeNode* root) {
            while (root->left != nullptr) {
                root = root->left;
            }
            return root;
        }
    
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == nullptr) {
                return nullptr;
            }
    
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } else if (key > root->val) {
                root->right = deleteNode(root->right, key);
            } else {
                // Found the node to delete
                if (root->left == nullptr) {
                    TreeNode* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    TreeNode* temp = root->left;
                    delete root;
                    return temp;
                } else {
                    // Node with two children: Get the inorder successor
                    TreeNode* suces = findMin(root->right);
                    root->val = suces->val;
                    root->right = deleteNode(root->right, suces->val);
                }
            }
    
            return root;
        }
    };
    