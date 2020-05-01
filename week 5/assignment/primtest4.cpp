#include <iostream>
#include <queue> 
#include <vector>
#include <bits/stdc++.h>
#include <cmath>


using namespace std;

struct vertex{
    int x,y;
};

class Graph{
    int V;
    bool * visited;
    double * distance;
    typedef pair<double,int> element;
    vector<vertex> parent;
public:
    vector<vertex> v;
    void create(int);
    void prim();
    double dist(vertex,vertex);
    bool alldone();
    void showDistance();
    void showVisited();
};

void Graph::create(int n){
    V=n;
    visited=new bool[V];
    distance=new double[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
}

void Graph::showDistance(){
    cout<<"minimum distance of each vertex\n";
    for(int i=0;i<V ;i++){
        cout<<fixed<<setprecision(10)<<i<<": "<<distance[i]<<endl;
    }
    cout<<endl;
}

void Graph::showVisited(){
    cout<<"visited array\n";
    for(int i=0;i<V;i++){
        cout<<i<<": "<<visited[i]<<endl;
    }
    cout<<endl;
}

double Graph::dist(vertex u,vertex v){
    return (sqrt(pow((v.x-u.x),2)+pow((v.y-u.y),2)));
}

bool Graph::alldone(){
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            return false;
        }
    }
    return true;
}

void Graph::prim(){
	float d;
	distance[0]=0;
	visited[0]=true;
	priority_queue< element, vector <element> , greater<element> > pq,parent;
	pq.push(make_pair(0,0));
	int u;
	double di;
		while(!pq.empty() && !alldone()){
			u=pq.top().second;
			di=pq.top().first;
			//cout<<"current vertex:"<<u<<endl;
			//cout<<"current min:"<<di<<endl;
			pq.pop();
					
			for(int j=0;j<V;j++){
				if(!visited[j] && u!=j){
					d=dist(v[u],v[j]);
					if(distance[j]>=d){
						distance[j]=d;
					}	
					parent.push(make_pair(d,j));
				}
			}
			
			int verid=parent.top().second;
			double verdis=parent.top().first;
			visited[verid]=true;
			
			//cout<<"current parent top min id:"<<verid<<endl;
			//cout<<"current parent top min distance:"<<verdis<<endl;
			
			pq.push(make_pair(verdis,verid));
			
			while(!parent.empty()){
				parent.pop();
			}	
			//showDistance();
			//showVisited();
		}
		double min=0;
		for(int i=0;i<V;i++){
			min+=distance[i];
		}
		//cout<<fixed<<min<<endl;
		//cout.setf( ios_base::fixed, ios_base::floatfield );
    	//cout.precision( 20 );
    	//cout<<setprecision(6)<<min<< endl;
		cout<<fixed<<setprecision(8) <<min<< endl;
}

int main()
{
    int n;
    vertex vert;
    cin>>n;
    Graph g;
    g.create(n);
    for(int i=0;i<n;i++){
        cin>>vert.x>>vert.y;
        g.v.push_back(vert);
    }
    g.prim();

    return 0;
}













