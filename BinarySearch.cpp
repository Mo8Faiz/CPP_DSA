#include<bits/stdc++.h>
using namespace std;
bool binser(vector<int> v,int n,int key){ //BOOL type function to return answer in TRUE/FALSE form
    int s=0;// Starting Pointer
    int e=n-1;//Ending Pointer
    while(s<=e){//Condition 
        int mid=s+(e-s)/2;//Mid pointer Points towards the middle element of the vector
        if(v[mid]==key) return true; //The funtion will return 1 if it found the element
        else if(v[mid]>key) e=mid-1;
        else s=mid+1;
    }
    return false; //The funtion will return 0 is it cannot find the element
}
int main(){
    //Driver Code
    vector<int> v={1,3,5,7,9,10,13,17,23};
    int n=v.size();
    int key;
    cout<<"Enter elemnt to be found : "<<endl;
    cin>>key;
    cout<<binser(v,n,key);//Function Call
}