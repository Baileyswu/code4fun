/* 
能找到 LCA 分为两种情况。
1. 左子树里有 p 或 q，右子树里有 p 或 q，则当前的根节点就是 LCA。
2. 子树里有 p 或 q，当前根节点是 p 或 q，则当前的根节点就是 LCA。
这样打印一下会发现，较深的那一方是不满足 1 或 2 的，但也需要标记出来：
   子树里没有 p 或 q，当前根节点是 p 或 q，也返回这个节点。
*/

#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        TreeNode* ls = lowestCommonAncestor(root->left, p, q);
        TreeNode* rs = lowestCommonAncestor(root->right, p, q);
        // if(root) printf("rt = %d ", root->val);
        // if(ls) printf("ls = %d ", ls->val);
        // if(rs) printf("rp = %d ", rs->val);
        // printf("\n");
        if(ls&&rs || (root==p||root==q)&&((ls||rs) || (!ls&&!rs))) return root;
        return ls ? ls : rs;
    }
};