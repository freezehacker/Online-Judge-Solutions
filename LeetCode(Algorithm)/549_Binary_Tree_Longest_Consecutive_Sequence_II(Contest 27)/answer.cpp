#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
    TreeNode* treeNode;
    int inc;
    int dec;

    Node(TreeNode *treeNode = NULL, int inc = 1, int dec = 1)
     : treeNode(treeNode), inc(inc), dec(dec) {}
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        answer = 0; // root == NULL
        postTraverse( root );
        return answer;
    }

    Node* postTraverse(TreeNode *root) {
        if ( root ) {
            Node* leftNode = postTraverse( root->left );
            Node* rightNode = postTraverse( root->right );


            Node* thisNode = new Node( root );
            int thisVal = root->val;

            if ( left ) {
                int leftVal = root->left->val;
                if ( leftVal - thisVal == -1 ) {    // increase by 1
                    thisNode->inc = max( thisNode->inc, leftNode->inc + 1 );
                } else if ( leftVal - thisVal == 1 ) {  // decrease by 1
                    thisNode->dec = max( thisNode->dec, leftNode->dec + 1 );
                }
            }

            if ( right ) {
                int rightVal = root->right->val;
                if ( rightVal - thisVal == 1 ) {    // decrease
                    thisNode->dec = max( thisNode->dec, rightNode->dec + 1 );
                } else if ( rightVal - thisVal == -1 ) {    // increase
                    thisNode->inc = max( thisNode->inc, rightNode->inc + 1 );
                }
            }

            answer = max( answer, thisNode->inc + thisNode->dec - 1 );  // Update the answer.
        }
    }

private:
    int answer;
};


int main() {
    return 0;
}