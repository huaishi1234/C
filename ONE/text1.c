#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct Node 
{
    int data;          // 数据域
    struct Node* next; // 指针域，指向下一个节点
};

// 建立单向链表
struct Node* buildList(int length) {
    struct Node* head = NULL; // 初始化头指针为空
    for (int i = 0; i < length; ++i) {
        int value;
        printf("请输入第%d个元素: ", i + 1);
        scanf("%d", &value); // 输入数据
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // 分配新节点内存
        if (!newNode) {
            printf("内存分配失败\n");
            exit(1); // 内存分配失败时退出程序
        }
        newNode->data = value; // 设置新节点的数据
        newNode->next = head;  // 新节点指向当前头节点
        head = newNode;        // 更新头节点为新节点
    }
    return head; // 返回新的头节点
}

// 输出单链表中的内容
void printList(struct Node* head) {
    struct Node* temp = head; // 创建临时指针遍历链表
    printf("链表内容: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data); // 输出当前节点的数据
        temp = temp->next;            // 移动到下一个节点
    }
    printf("NULL\n"); // 链表结束标志
}

// 计算单链表的长度并输出
int getListLength(struct Node* head) {
    int length = 0;       // 初始化长度计数器
    struct Node* temp = head;
    while (temp != NULL) {
        length++;           // 每经过一个节点增加计数
        temp = temp->next;  // 移动到下一个节点
    }
    printf("链表长度: %d\n", length);
    return length; // 返回链表长度
}

// 删除单链表中的第K个结点，并将剩余结点输出
struct Node* deleteKthNode(struct Node* head, int k) {
    if (head == NULL || k <= 0) {
        printf("无效的操作\n");
        return head; // 如果链表为空或k值无效，直接返回原链表
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    if (k == 1) {
        head = current->next; // 删除第一个节点
        free(current);        // 释放被删除节点的内存
        printf("删除第一个节点后:\n");
        printList(head);
        return head;
    }

    for (int i = 1; current != NULL && i < k; i++) {
        previous = current;   // 记录前驱节点
        current = current->next; // 移动到目标节点
    }

    if (current == NULL) {
        printf("位置超出范围\n");
        return head; // 如果k值超过链表长度，返回原链表
    }

    previous->next = current->next; // 修改前驱节点的指针跳过目标节点
    free(current);                  // 释放被删除节点的内存

    printf("删除第%d个节点后:\n", k);
    printList(head);
    return head;
}

// 将单链表倒排，输出结果
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;     // 初始化前驱节点为空
    struct Node* current = head;  // 当前节点初始化为头节点
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;     // 记录下一个节点
        current->next = prev;     // 当前节点指向前驱节点
        prev = current;           // 更新前驱节点为当前节点
        current = next;           // 移动到下一个节点
    }

    head = prev; // 更新头节点为最后一个处理过的节点（即原链表尾节点）
    printf("倒排后的链表:\n");
    printList(head);
    return head;
}

// 菜单函数，供用户选择操作
void menu() {
    int choice, length, k;
    struct Node* head = NULL;

    do {
        printf("\n请选择操作:\n");
        printf("1. 建立单向链表\n");
        printf("2. 输出单链表内容\n");
        printf("3. 计算单链表长度\n");
        printf("4. 删除单链表中的第K个结点\n");
        printf("5. 倒排单链表\n");
        printf("6. 退出\n");
        printf("输入选项编号: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("请输入链表长度: ");
                scanf("%d", &length);
                head = buildList(length); // 建立链表
                break;
            case 2:
                printList(head); // 输出链表内容
                break;
            case 3:
                getListLength(head); // 获取链表长度
                break;
            case 4:
                printf("请输入要删除的节点位置: ");
                scanf("%d", &k);
                head = deleteKthNode(head, k); // 删除指定位置的节点
                break;
            case 5:
                head = reverseList(head); // 倒排链表
                break;
            case 6:
                printf("退出程序\n");
                break;
            default:
                printf("无效的选择，请重新输入\n");
        }
    } while (choice != 6);

    // 释放链表内存
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp); // 逐个释放节点内存
    }
}

// 主函数
int main() {
    menu(); // 进入菜单循环
    return 0;
}



