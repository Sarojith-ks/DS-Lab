#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

// Vertex count
int vertex_count = 0;

// Vertex definition
struct vertex {
    char data;
    bool visited;
};

// Array of vertices
struct vertex *graph[MAX];

// Adjacency matrix
int adj_matrix[MAX][MAX];

// Queue
int queue[MAX];
int rear = -1;
int front = 0;
int queue_count = 0;

// Queue operations
void enqueue(int data) {
    queue[++rear] = data;
    queue_count++;
}

int dequeue() {
    queue_count--;
    return queue[front++];
}

bool is_queue_empty() {
    return queue_count == 0;
}

// Add vertex to the vertex list
void add_vertex(char data) {
    if (vertex_count >= MAX) {
        printf("Maximum vertex limit reached!\n");
        return;
    }
    struct vertex *new = (struct vertex *)malloc(sizeof(struct vertex));
    new->data = data;
    new->visited = false;
    graph[vertex_count] = new;
    vertex_count++;
}

// Add edge to the adjacency matrix
void add_edge(int start, int end) {
    if (start >= vertex_count || end >= vertex_count || start < 0 || end < 0) {
        printf("Invalid vertex indices!\n");
        return;
    }
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;  // Since it's an undirected graph
}

// Return an adjacent unvisited vertex
int adj_vertex(int vertex_get) {
    for (int i = 0; i < vertex_count; i++) {
        if (adj_matrix[vertex_get][i] == 1 && graph[i]->visited == false) {
            return i;
        }
    }
    return -1;
}

// Display vertex value
void display_vertex(int pos) {
    printf("%c ", graph[pos]->data);
}

// BFS traversal function
void bfs(struct vertex *new, int start) {
    if (!new) {
        printf("\nNothing to display\n");
        return;
    }

    new->visited = true;
    display_vertex(start);
    enqueue(start);

    while (!is_queue_empty()) {
        int pop_vertex = dequeue();
        // Explore adjacent vertices
        int unvisited;
        while ((unvisited = adj_vertex(pop_vertex)) != -1) {
            graph[unvisited]->visited = true;
            display_vertex(unvisited);
            enqueue(unvisited);
        }
    }

    // Reset visited for all vertices after BFS
    for (int i = 0; i < vertex_count; i++) {
        graph[i]->visited = false;
    }
    printf("\n");
}

// Display vertex positions
void show() {
    printf("\n.................................\n");
    for (int i = 0; i < vertex_count; i++) {
        printf("Vertex '%c' is at position %d\n", graph[i]->data, i);
    }
    printf(".................................\n");
}

int main() {
    int opt;
    char data;
    int edge_1, edge_2;
    int start;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    do {
        printf("\n1) Add vertex\n2) Create edge\n3) BFS Traversal\n0) Exit\nChoose option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("\nEnter data to be added to vertex: ");
                scanf(" %c", &data);  // Space before %c to skip any newline characters
                add_vertex(data);
                break;

            case 2:
                show();
                printf("\nEnter starting vertex position: ");
                scanf("%d", &edge_1);
                printf("Enter ending vertex position: ");
                scanf("%d", &edge_2);
                add_edge(edge_1, edge_2);
                break;

            case 3:
                printf("\nEnter starting vertex position for BFS: ");
                scanf("%d", &start);
                bfs(graph[start], start);
                break;

            default:
                printf("\nInvalid option! Try again.\n");
        }
    } while (opt != 0);

    return 0;
}

