#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmaller(vector<int>&nums){
    stack<int>st;
    vector<int>ans(nums.size(),0);
    st.push(-1);
    for(int i = nums.size()-1;i>=0;i--){
        while(st.top()>=nums[i]){
          st.pop();
            
        }
        ans[i] = st.top();
        st.push(nums[i]);   
    }
    return ans;
}

int main(){
    vector<int> nums = {8,4,6,2,3};
    vector<int> ans = nextSmaller(nums);
    for(auto it:ans) cout<<it<<" ";
}