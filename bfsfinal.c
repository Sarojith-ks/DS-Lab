#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INITIAL 1
#define WAITING 2
#define VISITED 3

int n; // Number of vertices
int adj[MAX][MAX]; // Adjacency matrix
int state[MAX]; // State of each vertex

int queue[MAX]; // Queue for BFS
int front = -1, rear = -1; // Queue pointers

void create_graph();
void BFS(int v);
void BF_Traversal();
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main() {
    create_graph();
    BF_Traversal();
    return 0;
}

void create_graph() {
    int count, max_edge, origin, destin;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
   
    max_edge = n * (n - 1) / 2; // Maximum number of edges in an undirected graph

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (count = 1; count <= max_edge; count++) {
        printf("Enter edge %d (origin -1 -1 to quit): ", count);
        scanf("%d %d", &origin, &destin);
       
        if (origin == -1 && destin == -1)
            break;

        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid edge!\n");
            count--; // Decrement count to retry this edge
        } else {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1; // Undirected graph
        }
    }
}

void BF_Traversal() {
    int v;
    for (v = 0; v < n; v++) {
        state[v] = INITIAL; // Initialize all states to INITIAL
    }

    printf("Enter start vertex for BFS: ");
    scanf("%d", &v);
   
    BFS(v);
}

void BFS(int v) {
    int i;
   
    printf("BFS traversal: ");
   
    insert_queue(v); // Enqueue the starting vertex
    state[v] = WAITING; // Mark as waiting (in queue)
   
    while (!isEmpty_queue()) {
        v = delete_queue(); // Dequeue
        printf("%d ", v);
        state[v] = VISITED; // Mark as visited
       
        // Visit all adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && state[i] == INITIAL) { // Unvisited adjacent vertex
                insert_queue(i); // Enqueue it
                state[i] = WAITING; // Mark as waiting
            }
        }
    }
    printf("\n");
}

void insert_queue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        exit(1);
    }
    if (front == -1) {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = vertex;
}

int delete_queue() {
    int deleted_item;
   
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        exit(1);
    }
   
    deleted_item = queue[front];
    front = front + 1;
    return deleted_item;
}

int isEmpty_queue() {
    return front == -1 || front > rear;
}

	

