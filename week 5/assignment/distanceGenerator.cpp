#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

struct coordinate{
	int x,y;
};

void distance(coordinate a,coordinate b){
	cout<<fixed<<setprecision(10)<<sqrt(pow((b.x-a.x),2)+pow((b.y-a.y),2))<<endl;
}

main(){
	vector<coordinate> v;
	int n;
	cin>>n;
	coordinate a;
	for(int i=0;i<n;i++){
		cin>>a.x>>a.y;
		v.push_back(a);
	}
	
	
	for(int i=0;i<n;i++){
		cout<<"i:"<<i<<endl;
		for(int j=0;j<n;j++){
			cout<<"\tj:"<<j;
			cout<<"\td:";	
			distance(v[i],v[j]);
		}
	}
	
	return 0;
}
