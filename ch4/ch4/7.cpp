#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< vector<int> > graph;
queue<int> answer;
vector<int> answer2;
int degree[100] = {0};
bool visited[100];
void bfs() {
    queue<int> q;
    for(int i=0;i<graph.size();i++) {
        if(degree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int start = q.front();
        q.pop();
        for(int i=0;i<graph[start].size();i++) {
            int end = graph[start][i];
            degree[end]--;
            if(degree[end] == 0) {
                q.push(end);
            }
        }
        answer.push(start);
    }
}

void dfs(int vertex) {
    if(visited[vertex])
        return;
    visited[vertex] = true;
    for(int i=0;i<graph[vertex].size(); i++) {
        dfs(graph[vertex][i]);
    }
    answer2.push_back(vertex);
}
int main() {
    int v,e;
    cout << "number of vertex and edge: ";
    cin >> v >> e;
    graph.resize(v);
    for(int i=0;i<e;i++) {
        char a, b;
        cout << "x -> y: ";
        cin >> a >> b;
        graph[a-'a'].push_back(b-'a');
        degree[b-'a']++;
    }
    
    bfs();
    int n = (int)answer.size();
    for(int i=0;i<n;i++) {
        cout << (char)(answer.front() + 'a') << " ";
        answer.pop();
    }
    
    cout << endl;
    
    for(int i=0;i<graph.size();i++) {
        dfs(i);
    }
    reverse(answer2.begin(), answer2.end());
    for(int i=0;i<answer2.size();i++) {
        cout << (char)(answer2[i] + 'a') << " ";
    }
    
    
    
}
