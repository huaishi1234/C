#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct Node 
{
    int data;
    struct Node* next;
};

// 建立单向链表
struct Node* buildList(int length) {
    struct Node* head = NULL;
    for (int i = 0; i < length; ++i) {
        int value;
        printf("请输入第%d个元素: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (!newNode) {
            printf("内存分配失败\n");
            exit(1);
        }
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// 输出单链表中的内容
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("链表内容: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 计算单链表的长度并输出
int getListLength(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    printf("链表长度: %d\n", length);
    return length;
}

// 删除单链表中的第K个结点，并将剩余结点输出
struct Node* deleteKthNode(struct Node* head, int k) {
    if (head == NULL || k <= 0) {
        printf("无效的操作\n");
        return head;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    if (k == 1) {
        head = current->next;
        free(current);
        printf("删除第一个节点后:\n");
        printList(head);
        return head;
    }

    for (int i = 1; current != NULL && i < k; i++) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("位置超出范围\n");
        return head;
    }

    previous->next = current->next;
    free(current);

    printf("删除第%d个节点后:\n", k);
    printList(head);
    return head;
}

// 将单链表倒排，输出结果
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
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
                head = buildList(length);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                getListLength(head);
                break;
            case 4:
                printf("请输入要删除的节点位置: ");
                scanf("%d", &k);
                head = deleteKthNode(head, k);
                break;
            case 5:
                head = reverseList(head);
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
        free(temp);
    }
}

// 主函数
int main() {
    menu();
    return 0;
}



