#include<bits/stdc++.h>
using namespace std;
bool Search(vector<int> v,int key,int s,int e){
    if(s>e) return 0;
    int mid=s+(e-s)/2;
    if(v[mid]==key) return 1;
    if(v[mid]>key) return Search(v,key,s,mid-1);
    else return Search(v,key,mid+1,e);
}
int main(){
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    int s=0;
    int e=v.size()-1;
    int key;
    cout<<"Enter element to be found : "<<endl;
    cin>>key;
    cout<<Search(v,key,s,e);
}