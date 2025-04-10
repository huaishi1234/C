#include <stdio.h>
#include <limits.h>

#define MAX 10000 // 设置一个较大的值表示无穷大
#define V 9     // 图中的顶点数量

// Dijkstra算法实现
void dijkstra(int A[][V], int Dist[], int Path[], int n, int V0) {
    for (int i = 0; i < n; i++) {
        Dist[i] = (A[V0][i] == 0 && i != V0) ? MAX : A[V0][i];
        if (Dist[i] < MAX && i != V0) {
            Path[i] = V0;
        } else {
            Path[i] = -1; // 表示不可达
        }
    }

    int visited[V];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    Dist[V0] = 0;
    Path[V0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int min_dist = MAX;

        // 找到当前未访问节点中距离最小的节点
        for (int v = 0; v < n; v++) {
            if (!visited[v] && Dist[v] <= min_dist) {
                min_dist = Dist[v];
                u = v;
            }
        }

        if (u == -1) break; // 如果找不到新的最小距离顶点，退出循环

        visited[u] = 1;

        // 更新相邻节点的距离
        for (int v = 0; v < n; v++) {
            if (!visited[v] && A[u][v] && Dist[u] != MAX && Dist[u] + A[u][v] < Dist[v]) {
                Dist[v] = Dist[u] + A[u][v];
                Path[v] = u;
            }
        }
    }

    // 打印结果
    printf("从顶点 %d 到其他顶点的最短路径:\n", V0);
    for (int i = 0; i < n; i++) {
        if (Dist[i] != MAX) {
            int k = i;
            while (k != V0) {
                printf("%d <- ", k);
                k = Path[k];
            }
            printf("%d", V0);
            printf(" = %d\n", Dist[i]);
        } else {
            printf("No Path to vertex: %d\n", i);
        }
    }
}

int main() {
    int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
                        {4, 0, 8, 0, 0, 0, 0, 11, 0},
                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 1, 6},
                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
                        {0, 0, 2, 0, 0, 0, 6, 7, 0} };

    int Dist[V];
    int Path[V];
    int source_vertex;

    printf("请输入源点 (0-%d): ", V-1);
    scanf("%d", &source_vertex);

    if (source_vertex >= 0 && source_vertex < V) {
        dijkstra(graph, Dist, Path, V, source_vertex);
    } else {
        printf("无效的源点。\n");
    }

    return 0;
}



