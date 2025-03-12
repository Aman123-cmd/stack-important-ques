#include<iostream>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

vector<int> nextSmaller(vector<int> &nums){
    stack<int> st;
    vector<int>ans(nums.size(),0);
st.push(-1);
for(int i = nums.size()-1;i>=0;i--){
    while(st.top()!=-1 && nums[st.top()]>=nums[i]){
        st.pop();
    }
    ans[i] = st.top();
    st.push(i);
}
return ans;
}
vector<int> prevSmaller(vector<int> &nums){
    stack<int> st;
    vector<int>ans(nums.size(),0);
st.push(-1);
for(int i =0;i<nums.size();i++){
    while(st.top()!=-1 && nums[st.top()]>=nums[i]){
        st.pop();
    }
    ans[i] = st.top();
    st.push(i);
}
return ans;
}
int largestArea(vector<int>&nums){
    vector<int>prev = prevSmaller(nums);
    vector<int>next = nextSmaller(nums);
    for(int i = 0;i<next.size();i++){
        if(next[i]==-1){
            next[i] = next.size();
        }
    }
int maxArea = INT_MIN;
    for(int i = 0;i<nums.size();i++){
        int width = next[i]-prev[i]-1;
        int length = nums[i];
        int area = length*width;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int main(){
    vector<int>nums = { 2,1,5,6,2,3};
    int ans = largestArea(nums);
    cout<<"ans->"<<ans;
}