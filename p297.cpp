class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encode = "{";
        if(root)
            encode += to_string(root->val) + serialize(root->left) + serialize(root->right);
        encode += "}";

        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() <=2){
            return nullptr;
        }
        else{
            int first_start = 1, second_start = 1;
            while(data[first_start] != '{') ++first_start;
            TreeNode* root = new TreeNode(stoi(data.substr(1, first_start-1)));
            
            int open = 1, i = first_start + 1;
            while(open != 0){
                if(data[i] == '{') open++;
                else if(data[i] == '}') open--;
                ++i;
            }
            second_start = i;
            
            root -> left = deserialize(data.substr(first_start, i-first_start));
            root -> right = deserialize(data.substr(second_start, data.length()-second_start-1));
            
            return root;
            
        }
    }
};