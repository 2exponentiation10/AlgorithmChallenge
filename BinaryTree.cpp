#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int value);
Node* searchNode(Node* root, int value);
Node* deleteNode(Node* root, int value);
Node* findMin(Node* node);
void inorderTraversal(Node* root);

Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

Node* searchNode(Node* root, int value) {
    if (root == nullptr || root->data == value)
        return root;

    if (value < root->data)
        return searchNode(root->left, value);

    return searchNode(root->right, value);
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* minNode = findMin(root->right);
        root->data = minNode->data;
        root->right = deleteNode(root->right, minNode->data);
    }

    return root;
}

Node* findMin(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}

void preordertraverse(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preordertraverse(root->left);
        preordertraverse(root->right);
    }
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void postordertraverse(Node* root) {
    if (root != nullptr) {
        postordertraverse(root->left);
        postordertraverse(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = nullptr;

    int arr[20];
    int len = 20;

    for (int i = 0; i < len; i++) {
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < len; i++) {
        root = insertNode(root, arr[i]);
    }

    cout << "���� �˻� Ʈ�� (���� ��ȸ): ";
    preordertraverse(root);
    cout << endl;

    cout << "���� �˻� Ʈ�� (���� ��ȸ): ";
    inorderTraversal(root);
    cout << endl;

    cout << "���� �˻� Ʈ�� (���� ��ȸ): ";
    postordertraverse(root);
    cout << endl;
    
    char input[10];
    while (true) {
        cout << "������ �۾��� �Է��Ͻÿ�: ";
        cin >> input;

        if (strcmp(input, "�˻�")==0) {
            int searchValue;
            cout << "ã�� ����� ���� �Է��Ͻÿ�: ";
            cin >> searchValue;
            Node* searchResult = searchNode(root, searchValue);
            if (searchResult != nullptr)
                cout << searchValue << "�� ã�ҽ��ϴ�." << endl;
            else
                cout << searchValue << "�� ã�� ���߽��ϴ�." << endl;
        }


        else if (strcmp(input, "����") == 0) {
            int deleteValue;
            cout << "������ ����� ���� �Է��Ͻÿ�: ";
            cin >> deleteValue;
            root = deleteNode(root, deleteValue);
            cout << "��� ������ �Է��Ͻÿ�: ";
            cin >> input;
            if (strcmp(input, "����") == 0) {
                cout << "���� �˻� Ʈ�� (���� ��ȸ): ";
                preordertraverse(root);
                cout << endl;
            }
            else if (strcmp(input, "����") == 0) {
                cout << "���� �˻� Ʈ�� (���� ��ȸ): ";
                inorderTraversal(root);
                cout << endl;
            }
            else if (strcmp(input, "����") == 0) {
                cout << "���� �˻� Ʈ�� (���� ��ȸ): ";
                postordertraverse(root);
                cout << endl;
            }
            else {
                cout << "�߸��� �Է����� �⺻���� ������ȸ�� ����մϴ�. ";
                inorderTraversal(root);
                cout << endl;
            }

        }

        else if (strcmp(input, "����") == 0) {
            int insertValue;
            cout << "������ ����� ���� �Է��Ͻÿ�: ";
            cin >> insertValue;
            root = insertNode(root, insertValue);

            cout << "��� ������ �Է��Ͻÿ�: ";
            cin >> input;
            if (strcmp(input, "����") == 0) {
                cout << "���� �˻� Ʈ�� (���� ��ȸ): ";
                preordertraverse(root);
                cout << endl;
            }
            else if (strcmp(input, "����") == 0) {
                cout << "���� �˻� Ʈ�� (���� ��ȸ): ";
                inorderTraversal(root);
                cout << endl;
            }
            else if (strcmp(input, "����") == 0) {
                cout << "���� �˻� Ʈ�� (���� ��ȸ): ";
                postordertraverse(root);
                cout << endl;
            }
            else {
                cout << "�߸��� �Է����� �⺻���� ������ȸ�� ����մϴ�. ";
                inorderTraversal(root);
                cout << endl;
            }

        }
        else if (strcmp(input, "����") == 0) {
            break;
        }
        else {
            cout << "�߸����Է��Դϴ�." << endl;
        }

    }
    


    

    return 0;
}