#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void nextGreater(vector<int>&nums){
    stack<int>st;
   
 for(int i = 0;i<nums.size() ;i++){
    while(!st.empty() && nums[st.top()]<nums[i]){
        int kids = st.top();
        nums[kids] = nums[i];
        st.pop();
    }
    st.push(i);
 }
while(!st.empty()){
    nums[st.top()]=-1;
    st.pop();
}
 
}
int main(){
    vector<int> nums = {4,3,2,7,4,5};
    nextGreater(nums);
    for(auto it:nums) cout<<it<<" ";
}