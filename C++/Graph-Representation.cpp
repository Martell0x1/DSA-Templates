#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3, M = 2e4 + 4;
int n,m,u,v; pair<int,int> EdgeList[M];
bool AdjMatrix[N][N];
vector<int> AdjList[N]; 
void PrintNieghbours(int u){
    for(int x = 0 ; x < m;x++){ 
        if(EdgeList[x].first == u) cout << EdgeList[x].second;
        else if(EdgeList[x].second == u) cout << EdgeList[x].first; 
        
    } 
    for(int x = 0 ; x < n ; x++){
        if(AdjMatrix[u][x]) cout << x;
    }
    for(int x : AdjList[u]){
        cout << x << " "; 
    } 
    
} 
void AreNeighbours(int u, int v){ 
    /* for(int x = 0 ; x < m ; x++){ 
    if((EdgeList[x].first == u && EdgeList[x].second == v) || (EdgeList[x].first == v && EdgeList[x].second == u)){
        return true; } 
        
    } 
    return false; 
    */ 
    //return AdjMatrix[u][v]; 
    for(int x : AdjList[u]){ 
        if(x == v) return true; 
        
    } 
    return false; 
    
} 
int main(){ 
    cin >>n>>m; 
    for(int x = 0 ; x < m ; x++){ 
        cin >> u >> v; 
        EdgeList[x]={u,v}; 
        AdjMatrix[u][v]=true; // if directed 
        AdjMatrix[v][u]=true; // add this if undirected A
        djList[u].push_back(v); // if directed 
        AdjList[v].push_back(u); //add this if undirected 
        } 
    return 0;
}
