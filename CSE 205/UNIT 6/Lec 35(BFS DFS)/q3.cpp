#include <iostream>
#include <climits>
using namespace std;
// You are using GCC
class Queue {
private:
    int front, rear, size;
    int capacity;
    int* array;

public:
    Queue(int cap) {
        capacity = cap;
        front = size = 0;
        rear = cap - 1;
        array = new int[cap];
    }

    ~Queue() {
        delete[] array;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(int item) {
        if (isFull()) return;
        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
    }

    int pop() {
        if (isEmpty()) return -1;
        int item = array[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    int frontItem() {
        if (isEmpty()) return -1;
        return array[front];
    }
};

void add_edge(int adj[][100], int src, int dest)
{
    //Type your code  
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

bool BFS(int adj[100][100], int source, int dest, int v, int pred[], int visited[]) {
    
    for (int i = 0; i < v; i++) {
        visited[i] = INT_MAX;
        pred[i] = -1;
    }

    Queue q(v);  
    visited[source] = 0;
    q.push(source);

    while (!q.isEmpty()) {
        int u = q.pop();

        
        for (int i = 0; i < v; i++) {
            if (adj[u][i] == 1 && visited[i] == INT_MAX) {
                visited[i] = visited[u] + 1;
                pred[i] = u;
                q.push(i);

                
                if (i == dest) {
                    return true;
                }
            }
        }
    }

    return false;  
}


void printShortestDistance(int adj[100][100], int source, int dest, int v, int pred[], int dist[]) {
    int path[100]; 
    int path_length = 0;

    int crawl = dest;
    path[path_length++] = crawl;
    while (pred[crawl] != -1) {
        path[path_length++] = pred[crawl];
        crawl = pred[crawl];
    }

    
    cout << "Shortest path length is: " << dist[dest] << endl;

   
    cout << "Path is: ";
    for (int i = path_length - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main()
{
    int v, e;
    cin >> v;

    int adj[100][100] = {0};

    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        add_edge(adj, src, dest);
    }

    int source, dest;
    cin >> source >> dest;

    int pred[v], dist[v];

    if (BFS(adj, source, dest, v, pred, dist))
        printShortestDistance(adj, source, dest, v, pred, dist);
   
    return 0;
}