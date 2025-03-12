#include<iostream>
#include<stack>
#include<vector>
using namespace std;

    class Car{
        public:
        int pos,speed;
        Car(int p,int s):pos(p),speed(s){};
    };
    static bool myComp(Car&a,Car&b){
        return a.pos<b.pos;
    }

    int carFleet(int target,vector<int>&position,vector<int>&speed){
      vector<Car>cars;
    
      for(int i = 0;i<position.size();i++){
        Car car(position[i],speed[i]);
        cars.push_back(car);

      }
stack<float> st;
for(auto car:cars){
    int time = (target-car.pos)/(float(car.speed));
    while(!st.empty() && time>=st.top()){
        st.pop();
    }
    st.push(time);
}
return st.size();
    }
   

 int main(){
    vector<int>position = {0,2,4};
    vector<int>speed  = {4,2,1};
    int ans = carFleet(100,position,speed);
    cout<<"total no of car fleet->"<<ans<<endl;
}