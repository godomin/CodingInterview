#include <iostream>
using namespace std;
bool adj[100][100];
bool visited[100];
int num;
void DFS(int node) {
    cout << "visite " << node << endl;
    visited[node] = true;
    for(int i=0;i<num;i++) {
        if(adj[node][i] && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int node) {
    int queue[200];
    int front = 0;
    int rear = 0;
    queue[rear++] = node;
    while(front != rear) {
        visited[node] = true;
        for(int i=0;i<num;i++) {
            if(adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                rear = rear % 200;
            }
        }
        node = queue[front++];
    }
}

int main() {
    int a, b;
    
    /*num = 4;
    adj[0][1] = true;
    adj[1][2] = true;
    adj[2][0] = true;
    adj[3][2] = true;*/
    
    cout << "number of node: ";
    cin >> num;
    for(int i=0;i<num;i++) {
        cout << "node -> node: ";
        cin >> a >> b;
        adj[a][b] = true;
    }
    
    cout << "start node, end node: ";
    cin >> a >> b;
    
    BFS(3);
    if(visited[0]) {
        cout << "route exist" << endl;
    } else {
        cout << "route does not exist" << endl;
    }
}
