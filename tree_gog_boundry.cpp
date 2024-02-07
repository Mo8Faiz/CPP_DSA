#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};
Node *tree(Node *root){
    int d;
    cin>>d;
    if(d==-1) return NULL;
    root= new Node(d);
    cout<<"LEFT : "<<endl;
    root->left=tree(root->left);
    cout<<"RIGHT : "<<endl;
    root->right=tree(root->right);
    return root;
}
void traverseLEFT(Node* root,vector<int> &ans){
    if((root==NULL) || (root->left==NULL&&root->right==NULL)) return ;
    ans.push_back(root->data);
    if(root->left) traverseLEFT(root->left,ans);
    else traverseLEFT(root->right,ans);
}
void traverseRIGHT(Node*root,vector<int> &ans){
    if((root==NULL)||(root->left==NULL&&root->right==NULL)) return;
    if(root->right) traverseRIGHT(root->right,ans);
    else traverseRIGHT(root->left,ans);
    ans.push_back(root->data);
}
void traverseLEAF(Node* root,vector<int> &ans){
    if(root==NULL) return;
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLEAF(root->left,ans);
    traverseLEAF(root->right,ans);
}
void boundry(Node *root){
    vector<int> ans;
    if(root==NULL) return;
    ans.push_back(root->data);
    traverseLEFT(root->left,ans);
    traverseLEAF(root->left,ans);
    traverseLEAF(root->right,ans);
    traverseRIGHT(root->right,ans);
    for(int x:ans){
        cout<<x<<" ";
    }


}
int main(){
    Node*root=NULL;
    root=tree(root);
    boundry(root);
}
