#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> custompair;
vector<int> mergeksortedarrays(vector<vector<int>> nums){
	vector<int> sol;
	priority_queue<custompair,vector<custompair>,greater<custompair>> pq;
	for(int i=0;i<nums.size();i++){
		pq.push({nums[i][0],{i,0}});
	}
	while(!pq.empty()){
		custompair temp;
		temp=pq.top();
		pq.pop();
		sol.push_back(temp.first);
		int arr=temp.second.first;
		int col=temp.second.second;
		if(col+1<nums[arr].size()){
			pq.push({nums[arr][col+1],{arr,col+1}});
		}	
	}
	return sol;
}
int main(){
	vector<vector<int>> nums={{2,6,12,15},
							  {1,9,13,15},
							  {20,24,30,32}  
							};
	vector<int> sol;
	sol=mergeksortedarrays(nums);
	for(int i=0;i<sol.size();i++){
		cout<<sol[i]<<" ";
	}					
	return 0;
}
