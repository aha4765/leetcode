http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=206262&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3090%5D%5Bvalue%5D%3D2%26searchoption%5B3090%5D%5Btype%5D%3Dradio%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311

1. Convert a given Binary Tree to Doubly Linked List
//in order
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* convert(TreeNode* root) {
  TreeNode *head, *tail;
  helper(root, head, tail);
  return head;
}

int helper(TreeNode* root, TreeNode* &head, TreeNode* &tail) {
  if (root == nullptr) {
    head = nullptr;
    tail = nullptr;
    return 0;
  }
  TreeNode* lhead, *ltail, *rhead, *rtail;
  helper(root->left, lhead, ltail);
  helper(root->right, rhead, rtail);
  if (ltail != nullptr) {
    ltail->right = root;
    root->left = ltail;
    head = lhead;
  }
  else {
    head = root;
  }
  
  if (rhead != nullptr) {
    root->right = rhead;
    rhead->left = root;
    tail = rtail;
  }
  else {
    tail = root;
  }
  return 0;
}

Time complexity O(N)
