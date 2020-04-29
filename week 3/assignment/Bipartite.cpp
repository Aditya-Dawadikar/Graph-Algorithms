#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std; 
  
// function to store the connected nodes 
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 
  
// function to check whether a graph is bipartite or not 
bool isBipartite(vector<int> adj[], int v, 
                 vector<bool>& visited, vector<int>& color) 
{ 
  
  	vector<int>::iterator u;
    for (u=adj[v].begin(); u!=adj[v].end();u++) { 
  
        // if vertex u is not explored before 
        if (visited[*u] == false) { 
  
            // mark present vertic as visited 
            visited[*u] = true; 
  
            // mark its color opposite to its parent 
            color[*u] = !color[v]; 
  
            // if the subtree rooted at vertex v is not bipartite 
            if (!isBipartite(adj, *u, visited, color)) 
                return false; 
        } 
  
        // if two adjacent are colored with same color then 
        // the graph is not bipartite 
        else if (color[*u] == color[v]) 
            return false; 
    } 
    return true; 
} 
  
// Driver Code 
int main() 
{ 
    // no of nodes 
    int n,m;
    cin>>n>>m;
    
    int N=n;
  
    // to maintain the adjacency list of graph 
    vector<int> adj[N+1]; 
  
    // to keep a check on whether 
    // a node is discovered or not 
    vector<bool> visited(N+1); 
  
    // to color the vertices 
    // of graph with 2 color 
    vector<int> color(N+1); 
  
    // adding edges to the graph 
    int u,v;
	for(int i=0;i<m;i++){
    	cin>>u>>v;
    	addEdge(adj,u,v);
	}
    
    // marking the source node as visited 
    visited[1] = true; 
  
    // marking the source node with a color 
    color[1] = 0; 
  
    // Function to check if the graph 
    // is Bipartite or not 
    if (isBipartite(adj, 1, visited, color)) { 
        cout << "1"; 
    } 
    else { 
        cout << "0"; 
    } 
  
    return 0; 
} 
