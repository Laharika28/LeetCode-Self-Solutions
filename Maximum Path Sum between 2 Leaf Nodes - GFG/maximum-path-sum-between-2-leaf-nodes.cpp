// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

int solve(Node* root,int& res){
    if(root==NULL){
        return 0;
    }
    
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    
    int temp;
    if(root->left!=NULL && root->right!=NULL){
        temp= max(l,r) + root->data;
    }else{
        if(root->left != NULL){
            temp=l+root->data;
        }else if(root->right != NULL){
            temp=r+root->data;
        }else{
            temp=root->data;
        }
    }
    int ans;
    if(root->left == NULL || root->right == NULL){
        ans=INT_MIN;
    }else{
     ans = l+r+root->data;   
    }
    res = max(res,ans);
    return temp;
}

class Solution {
public:
    int maxPathSum(Node* root)
    {
        // code here
        if(root==NULL){
            return 0;
        }
        
        int res=INT_MIN;
        int t=solve(root,res);
        if(root->left==NULL || root->right==NULL){
            res=max(res,t);
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        cout << ob.maxPathSum(root) << "\n";
    }
    return 0;
}  // } Driver Code Ends