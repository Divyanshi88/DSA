template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) {
        data = value;
        left = right = nullptr;
    }
};
