// Get from discussion

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
public:
    BSTIterator(TreeNode *root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (st.empty()) {
            return false;
        }
        else {
            return true;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp = st.top();
        int res = temp->val;
        st.pop();
        temp = temp->right;
        while (temp != nullptr) {
            st.push(temp);
            temp = temp->left;
        }
        return res;
    }
    
private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
