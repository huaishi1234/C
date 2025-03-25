#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构体
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 动态交互建立二叉树
struct TreeNode* insertNode() {
    int value;
    printf("请输入节点值 (输入-1结束): ");
    scanf("%d", &value);

    if (value == -1) {
        return NULL;
    }

    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!newNode) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    printf("请输入 %d 的左子节点:\n", value);
    newNode->left = insertNode();
    printf("请输入 %d 的右子节点:\n", value);
    newNode->right = insertNode();

    return newNode;
}

// 先序遍历 (DLR)
void preOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// 中序遍历 (LDR)
void inOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

// 后序遍历 (LRD)
void postOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

// 计算二叉树中的结点个数
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// 计算二叉树的深度
int calculateDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = calculateDepth(root->left);
    int rightDepth = calculateDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 释放二叉树内存
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// 菜单函数，供用户选择操作
void menu() {
    struct TreeNode* root = NULL;
    int choice;

    do {
        printf("\n请选择操作:\n");
        printf("1. 建立二叉树\n");
        printf("2. 先序遍历 (DLR)\n");
        printf("3. 中序遍历 (LDR)\n");
        printf("4. 后序遍历 (LRD)\n");
        printf("5. 计算二叉树中的结点个数\n");
        printf("6. 计算二叉树的深度\n");
        printf("7. 退出\n");
        printf("输入选项编号: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("开始建立二叉树:\n");
                root = insertNode();
                break;
            case 2:
                printf("先序遍历结果: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("中序遍历结果: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("后序遍历结果: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("二叉树中的结点个数: %d\n", countNodes(root));
                break;
            case 6:
                printf("二叉树的深度: %d\n", calculateDepth(root));
                break;
            case 7:
                printf("退出程序\n");
                break;
            default:
                printf("无效的选择，请重新输入\n");
        }
    } while (choice != 7);

    // 释放二叉树内存
    freeTree(root);
}

// 主函数
int main() {
    menu();
    return 0;
}



