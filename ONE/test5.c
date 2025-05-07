#include <stdio.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 快速排序函数
void quickSort(int arr[], int low, int high, int* swapCount) {
    if (low < high) {  
        int pivot = arr[high];// 选择最后一个元素作为标准
        int i = (low - 1); // 较小元素的索引

        
        for (int j = low; j <= high - 1; j++) {// 遍历数组并将小于基准的元素移到左边
            if (arr[j] < pivot) {
                i++; // 增加较小元素的索引
                swap(&arr[i], &arr[j]); // 交换当前元素与较小元素
                (*swapCount)++;
            }
        }
        swap(&arr[i + 1], &arr[high]); // 将基准放到正确的位置
        (*swapCount)++;
        int pi = i + 1;

        quickSort(arr, low, pi - 1, swapCount);// 递归地对左右子数组进行快速排序
        quickSort(arr, pi + 1, high, swapCount);
    }
}

// 冒泡排序函数
void bubbleSort(int arr[], int n, int* swapCount, int* passCount) {
    int i, j;
    for (i = 0; i < n-1; i++) { // 控制次数
        (*passCount)++;
        for (j = 0; j < n-i-1; j++) { // 每趟比较相邻元素
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]); // 如果顺序不对则交换
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
        int mid = left + (right - left) / 2; // 计算中间位置

        if (arr[mid] == key)
            return mid; // 如果找到返回索引

        if (arr[mid] < key)
            left = mid + 1; // 在右半部分继续查找
        else
            right = mid - 1; // 在左半部分继续查找
    }

    return -1; // 未找到返回
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
    int arr[n];
    // 输入数组中的元素数量
    printf("请输入数组中的元素数量: ");
    scanf("%d", &n);

    // 输入数组中的元素
    printf("请输入数组中的元素:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        choice = menu();// 从菜单中获取用户选择
        switch (choice) {
            case 1:
                int key;
                int swapCountQuick = 0;
                int result = 0;
                // 输入要查找的元素
                printf("请输入要查找的元素: ");
                scanf("%d", &key);
                // 首先使用快速排序对数组进行排序
                quickSort(arr, 0, n - 1, &swapCountQuick);
                printf("快速排序后的数组: \n");
                printArray(arr, n);
                result = binarySearch(arr, n, key);
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



