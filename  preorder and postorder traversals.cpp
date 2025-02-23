class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            unordered_map<int, int> postIndex;
            for (int i = 0; i < postorder.size(); ++i) {
                postIndex[postorder[i]] = i;  // Store postorder indices for quick lookup
            }
            int preIndex = 0;
            return buildTree(preorder, postorder, postIndex, preIndex, 0, postorder.size() - 1);
        }
    
    private:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& postIndex, 
                            int& preIndex, int left, int right) {
            if (preIndex >= preorder.size() || left > right) return nullptr;
            
            TreeNode* root = new TreeNode(preorder[preIndex++]);
            if (left == right) return root;  // Leaf node case
            
            int leftChildIndex = postIndex[preorder[preIndex]];  // Find left child in postorder
            
            root->left = buildTree(preorder, postorder, postIndex, preIndex, left, leftChildIndex);
            root->right = buildTree(preorder, postorder, postIndex, preIndex, leftChildIndex + 1, right - 1);
            
            return root;
        }
    };
    