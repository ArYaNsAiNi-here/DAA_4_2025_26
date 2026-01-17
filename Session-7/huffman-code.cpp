#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int freq;
    Node *left, *right;
    
    Node(int f) {
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

class Solution {
public:
    void preorder(Node* root, string s, vector<string>& ans) {
        if (!root) return;
        
        if (!root->left && !root->right) {
            ans.push_back(s);
            return;
        }
        
        preorder(root->left, s + "0", ans);
        preorder(root->right, s + "1", ans);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        
        for (int i = 0; i < N; i++) {
            pq.push(new Node(f[i]));
        }
        
        while (pq.size() > 1) {
            Node* left = pq.top();
            pq.pop();
            
            Node* right = pq.top();
            pq.pop();
            
            Node* parent = new Node(left->freq + right->freq);
            parent->left = left;
            parent->right = right;
            
            pq.push(parent);
        }
        
        Node* root = pq.top();
        vector<string> ans;
        preorder(root, "", ans);
        
        return ans;
    }
};