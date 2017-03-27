class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> seq;
        inOrder(root, seq);
        vector<int> sumSeq = sum(seq);
        dfs(root, seq, sumSeq);
        return root;
    }

private:
    void inOrder(TreeNode* root, vector<int> &orderedSeq) {
        if (root) {
            inOrder(root->left, orderedSeq);
            orderedSeq.push_back(root->val);
            inOrder(root->right, orderedSeq);
        }
    }

    // Return the right-most index
    int binarySearchRightmost(int target, vector<int> &orderedSeq) {
        int size = orderedSeq.size();
        int left = 0, right = size - 1;
        int idx = -1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (target < orderedSeq[middle]) {
                right = middle - 1;
            } else if (target > orderedSeq[middle]) {
                left = middle + 1;
            } else {
                idx = middle;
                break;
            }
        }
        // Reach the right-most position.
        for (; idx < size && orderedSeq[idx] == target; ++target) ;
        return idx;
    }

    vector<int> sum(vector<int> &orderedSeq) {
        vector<int> ret(orderedSeq);
        for (int i = ret.size() - 2; i >= 0; --i) {
            ret[i] += ret[i + 1];
        }
        return ret;
    }

    void dfs(TreeNode* root, vector<int> &seq, vector<int> &sumSeq) {
        if (root) {
            int idx = binarySearchRightmost(root->val, seq);
            if (idx < sumSeq.size()) {
                root->val = sumSeq[idx];
            }

            dfs(root->left, seq, sumSeq);
            dfs(root->right, seq, sumSeq);
        }
    }
};
