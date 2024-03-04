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
    int data;
    cin>>data;
    if(data==-1) return NULL;
    root= new Node(data);
    cout<<"left : "<<endl;
    root->left=tree(root->left);
    cout<<"right : "<<endl;
    root->right=tree(root->right);
    return root;
}
void inorder(Node *root,vector<int> &ans){
    stack<Node *> s;
    Node *temp=root;
   // vector<int> ans;
    while(true){
        if(temp!=NULL){
            s.push(temp);
            temp=temp->left;
        }
        else{
            if(s.empty()) break;
            temp=s.top();
            s.pop();
            ans.push_back(temp->data);
            temp=temp->right;
        }

    }
    // for(auto x : ans){
    //     cout<<x<<" ";
    // }
}
void preorder(Node *root,vector<int> &ans){
    stack<Node *> s;
    s.push(root);
    while(!s.empty()){
        root=s.top();
        s.pop();
        if(root->right) s.push(root->right);
        ans.push_back(root->data);
        if(root->left) s.push(root->left);
    }
}
void postorder(Node *root,vector<int> &ans){
    stack<Node*> s1,s2;
    Node *temp=root;
    s1.push(temp);
    while(!s1.empty()){
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left) s1.push(temp->left);
        if(temp->right) s1.push(temp->right);
    }
    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
    }

}


int main(){
    vector<int> ans0;
    vector<int> ans1;
    vector<int> ans2;
    Node * root= NULL;
    root= tree(root);
    inorder(root,ans0);
    for(auto x : ans0){
        cout<<x<<" ";
    }
    cout<<endl;
    preorder(root,ans1);
    for(auto x : ans1){
        cout<<x<<" ";
    }
    cout<<endl;
    postorder(root,ans2);
    for(auto x : ans2){
        cout<<x<<" ";
    }
}