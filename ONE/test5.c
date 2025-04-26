#include <stdio.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 快速排序函数（包含分区逻辑）
void quickSort(int arr[], int low, int high, int* swapCount) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        // 分区过程
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
                (*swapCount)++;
            }
        }
        swap(&arr[i + 1], &arr[high]);
        (*swapCount)++;
        int pi = i + 1;

        // 递归地对左右子数组进行快速排序
        quickSort(arr, low, pi - 1, swapCount);
        quickSort(arr, pi + 1, high, swapCount);
    }
}

// 冒泡排序函数
void bubbleSort(int arr[], int n, int* swapCount, int* passCount) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        (*passCount)++;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                (*swapCount)++;
            }
        }
    }
}

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// 二分查找函数
int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // 关键字未找到
}

// 显示菜单并获取用户选择
int menu() {
    int choice;
    printf("\n请选择操作：\n");
    printf("1. 二分查找\n");
    printf("2. 快速排序\n");
    printf("3. 冒泡排序\n");
    printf("4. 退出\n");
    printf("请输入您的选择: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    int n;

    // 输入数组中的元素数量
    printf("请输入数组中的元素数量: ");
    scanf("%d", &n);

    int arr[n];

    // 输入数组中的元素
    printf("请输入数组中的元素:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        // 从菜单中获取用户选择
        choice = menu();

        switch (choice) {
            case 1:
                int key;
                // 输入要查找的元素
                printf("请输入要查找的元素: ");
                scanf("%d", &key);
                // 首先使用快速排序对数组进行排序
                int swapCountQuick = 0;
                quickSort(arr, 0, n - 1, &swapCountQuick);
                printf("快速排序后的数组: \n");
                printArray(arr, n);
                int result = binarySearch(arr, n, key);
                if (result != -1)
                    printf("元素在索引 %d 处找到\n", result);
                else
                    printf("元素未在数组中找到\n");
                break;

            case 2:
                swapCountQuick = 0;
                quickSort(arr, 0, n - 1, &swapCountQuick);
                printf("快速排序后的数组: \n");
                printArray(arr, n);
                printf("总交换次数: %d\n", swapCountQuick);
                break;

            case 3:
                int swapCountBubble = 0;
                int passCountBubble = 0;
                bubbleSort(arr, n, &swapCountBubble, &passCountBubble);
                printf("冒泡排序后的数组: \n");
                printArray(arr, n);
                printf("总趟数: %d\n", passCountBubble);
                printf("总交换次数: %d\n", swapCountBubble);
                break;

            case 4:
                printf("正在退出...\n");
                break;

            default:
                printf("无效的选择！请重新输入。\n");
        }
    } while (choice != 4);

    return 0;
}




