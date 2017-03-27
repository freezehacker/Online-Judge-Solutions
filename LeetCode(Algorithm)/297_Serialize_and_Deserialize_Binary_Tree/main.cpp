class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Special case.
        if (!root) {
            return "[]";
        }

        // BFS
        vector<string> tmpResult;
        queue<TreeNode*> nodes;
        nodes.push( root );
        while ( !nodes.empty() ) {
            TreeNode* node = nodes.front();
            nodes.pop();

            if (node == NULL) {
                tmpResult.push_back( "null" );
                continue;
            }
            tmpResult.push_back( std::to_string( node->val ) );
            nodes.push( node->left );
            nodes.push( node->right );
        }

        // Remove the 'null's at the end.
        while ( tmpResult.at( tmpResult.size() - 1 ) == "null" ) {
            tmpResult.pop_back();
        }

        // Translate into string type.
        string result;
        result += "[";
        for (int i = 0, size = tmpResult.size(); i < size; ++i) {
            if (i != 0) {
                result += ",";
            }
            result += tmpResult.at( i );
        }
        result += "]";
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Special case.
        if (data == "[]") {
            return NULL;
        }

        vector<string> strings = split( data.substr( 1, data.size() - 1 ), ',' );
        int k = 0;

        // Create the root.
        TreeNode* root = new TreeNode( atoi( strings[k++].c_str() ) );
        queue<TreeNode*> nodes;
        nodes.push( root );

        // BFS
        while ( !nodes.empty() ) {
            TreeNode* node = nodes.front();
            nodes.pop();

            if ( k < strings.size() ) {
                if ( strings[k] != "null" ) {
                    node->left = new TreeNode( atoi( strings[k].c_str() ) );
                    nodes.push( node->left );
                }
                k++;
            }

            if ( k < strings.size() ) {
                if ( strings[k] != "null" ) {
                    node->right = new TreeNode( atoi( strings[k].c_str() ) );
                    nodes.push( node->right );
                }
                k++;
            }
        }

        // Return the root.
        return root;
    }

    vector<string> split(string s, char delim) {
        vector<string> ret;
        string curString;
        for (int i = 0, size = s.size(); i < size; ++i) {
            if ( s[i] != delim ) {
                curString.push_back( s[i] );
            } else {
                ret.push_back( curString );
                curString = "";
            }
        }
        ret.push_back( curString );
        return ret;
    }
};