#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
    public:
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            vector<vector<int>> adj(n);
            for(auto edge : edges){
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);            
            }
            vector<bool> visited(n,false);
            stack<int> vecle;
            vecle.push(source);
            visited[source]=true;
            while(!vecle.empty()){
                int current=vecle.top();
                vecle.pop();
                if(current==destination) return true;
                for(int neighbor : adj[current]){
                    if(!visited[neighbor]){
                        visited[neighbor]=true;
                        vecle.push(neighbor);
                    }
                }
            }
            return false;
        }
    };