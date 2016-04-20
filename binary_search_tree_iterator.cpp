/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> visitStack;
    bool isMiddle;
    
    bool traverse(TreeNode* root) {
        if (root == NULL) return true;
        
        while (root->left) {
            visitStack.push(root);
            root = root->left;
        }
        visitStack.push(root);
        
        // if root has right, then the node is middle
        if (root->right) {
            return true;
        } else {
            return false;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        isMiddle = traverse(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !visitStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        int res = 0;
        TreeNode* node = visitStack.top();
        res = node->val;
        visitStack.pop();
        if (isMiddle) {
            node = node->right;
            isMiddle = traverse(node);
        } else {
            isMiddle = true;
        }
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
