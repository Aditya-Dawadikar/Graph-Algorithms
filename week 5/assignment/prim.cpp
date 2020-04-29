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
    float * distance;
public:
    vector<vertex> v;
    void create(int);
    void prim();
    float dist(vertex,vertex);
    bool alldone();
    void showDistance();
    void showVisited();
};

void Graph::create(int n){
    V=n;
    visited=new bool[V];
    distance=new float[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
        distance[i]=INT_MAX;
    }
}

void Graph::showDistance(){
    cout<<"minimum distance of each vertex\n";
    for(int i=0;i<V;i++){
        cout<<i<<": "<<distance[i]<<endl;
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

float Graph::dist(vertex u,vertex v){
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
    int src=0;
    visited[0]=true;
    distance[0]=0;
    
    float min=0;
    
    queue<int>q;
    q.push(src);
    
    while(!q.empty()){
        int u;
        u=q.front();
        q.pop();
        visited[u]=true;
        min+=distance[u];
        
        for(int i=1;i<V;i++){
            if(visited[i]==false && u!=i && dist(v[u],v[i])<distance[i]){
                distance[i]=dist(v[u],v[i]);
            }
        }
        float m=distance[0];
        for(int i=0;i<V;i++){
            if(distance[i]<m && visited[i]==false){
                m=distance[i];
                u=i;  
            }
        }
        q.push(u);
        visited[u]=true;
        cout<<"current src:"<<u<<endl;
        showDistance();
        showVisited();
    }
    
    cout<<min;
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
        //vert.x=vert.x-1;
        //vert.y=vert.y-1;
        g.v.push_back(vert);
    }
    g.prim();
    return 0;
}


