#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// 定义邻接链表节点结构
struct G {
    int data;
    struct G* next;
};

// 添加边到邻接链表
void addEdge(struct G* adj[], int src, int dest) {
    // 创建从src到dest的边
    struct G* newNode = (struct G*)malloc(sizeof(struct G));
    if (!newNode) {
        fprintf(stderr, "内存分配失败\n");
        exit(1);
    }
    newNode->data = dest;
    newNode->next = adj[src];
    adj[src] = newNode;

    // 如果是无向图，添加从dest到src的边
    newNode = (struct G*)malloc(sizeof(struct G));
    if (!newNode) {
        fprintf(stderr, "内存分配失败\n");
        exit(1);
    }
    newNode->data = src;
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

// 深度优先搜索（DFS）
void DFS(struct G* A[], int n, int V) {
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    printf("顶点是 : %d\n", V);
    visited[V] = 1;
    stack[++top] = V;

    while (top != -1) {
        int current = stack[top--];
        struct G* p = A[current];

        while (p != NULL) {
            if (!visited[p->data]) {
                printf("顶点是 : %d\n", p->data);
                visited[p->data] = 1;
                stack[++top] = p->data;
            }
            p = p->next;
        }
    }
}

// 广度优先搜索（BFS）
void BFS(struct G* A[], int n, int V) {
    int visited[MAX] = {0}, CQ[MAX];
    printf("顶点是 : %d\n", V);
    visited[V] = 1;      // 访问起始点
    int front = 0;
    int rear = 0;
    CQ[rear++] = V; // 入队列

    while (front != rear) {       // 队不空
        int current = CQ[front++];
        struct G* p = A[current];     // 找其第一邻接点
        while (p != NULL) {
            if (visited[p->data] == 0) {  // 未访问过
                printf("顶点是 : %d\n", p->data);
                visited[p->data] = 1;
                CQ[rear++] = p->data;
            }
            p = p->next;  // 下一邻接点
        }
    }
}

// 显示菜单并处理用户选择
void menu(struct G* adj[], int n, int start_vertex) {
    int choice;
    do {
        printf("\n图的遍历菜单:\n");
        printf("1. 深度优先遍历 (DFS)\n");
        printf("2. 广度优先遍历 (BFS)\n");
        printf("3. 退出\n");
        printf("请输入您的选择: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("从顶点 %d 开始的深度优先遍历:\n", start_vertex);
                DFS(adj, n, start_vertex);
                break;
            case 2:
                printf("从顶点 %d 开始的广度优先遍历:\n", start_vertex);
                BFS(adj, n, start_vertex);
                break;
            case 3:
                printf("正在退出...\n");
                break;
            default:
                printf("无效的选择。请重新输入。\n");
        }
    } while (choice != 3);
}

int main() {
    int n, e, start_vertex;

    printf("请输入图的顶点数量: ");
    scanf("%d", &n);

    // 初始化邻接链表
    struct G* adj[n];
    for (int i = 0; i < n; ++i)
        adj[i] = NULL;

    printf("请输入图的边数量: ");
    scanf("%d", &e);

    printf("请输入每条边的两个顶点 (格式: src dest):\n");
    for (int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(adj, src, dest);
    }

    printf("请输入起始顶点: ");
    scanf("%d", &start_vertex);

    if (start_vertex >= 0 && start_vertex < n) {
        menu(adj, n, start_vertex);
    } else {
        printf("无效的起始顶点。\n");
    }

    return 0;
}



