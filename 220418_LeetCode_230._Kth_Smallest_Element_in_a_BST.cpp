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
#include <vector>
#include <algorithm>

class Solution {
public:
	vector<int> v;
	int kthSmallest(TreeNode* root, int k) {
		recur(root);
		sort(v.begin(), v.end());
		return v[k - 1];
	}

	void recur(TreeNode* r) {
		v.push_back(r->val);
		if (r->left) recur(r->left);
		if (r->right) recur(r->right);
	}

};