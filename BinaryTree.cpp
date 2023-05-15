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

    cout << "이진 검색 트리 (전위 순회): ";
    preordertraverse(root);
    cout << endl;

    cout << "이진 검색 트리 (중위 순회): ";
    inorderTraversal(root);
    cout << endl;

    cout << "이진 검색 트리 (후위 순회): ";
    postordertraverse(root);
    cout << endl;
    
    char input[10];
    while (true) {
        cout << "수행할 작업을 입력하시오: ";
        cin >> input;

        if (strcmp(input, "검색")==0) {
            int searchValue;
            cout << "찾을 노드의 값을 입력하시오: ";
            cin >> searchValue;
            Node* searchResult = searchNode(root, searchValue);
            if (searchResult != nullptr)
                cout << searchValue << "를 찾았습니다." << endl;
            else
                cout << searchValue << "를 찾지 못했습니다." << endl;
        }


        else if (strcmp(input, "삭제") == 0) {
            int deleteValue;
            cout << "삭제할 노드의 값을 입력하시오: ";
            cin >> deleteValue;
            root = deleteNode(root, deleteValue);
            cout << "출력 형식을 입력하시오: ";
            cin >> input;
            if (strcmp(input, "전위") == 0) {
                cout << "이진 검색 트리 (전위 순회): ";
                preordertraverse(root);
                cout << endl;
            }
            else if (strcmp(input, "중위") == 0) {
                cout << "이진 검색 트리 (중위 순회): ";
                inorderTraversal(root);
                cout << endl;
            }
            else if (strcmp(input, "후위") == 0) {
                cout << "이진 검색 트리 (후위 순회): ";
                postordertraverse(root);
                cout << endl;
            }
            else {
                cout << "잘못된 입력으로 기본값인 중위순회로 출력합니다. ";
                inorderTraversal(root);
                cout << endl;
            }

        }

        else if (strcmp(input, "삽입") == 0) {
            int insertValue;
            cout << "삽입할 노드의 값을 입력하시오: ";
            cin >> insertValue;
            root = insertNode(root, insertValue);

            cout << "출력 형식을 입력하시오: ";
            cin >> input;
            if (strcmp(input, "전위") == 0) {
                cout << "이진 검색 트리 (전위 순회): ";
                preordertraverse(root);
                cout << endl;
            }
            else if (strcmp(input, "중위") == 0) {
                cout << "이진 검색 트리 (중위 순회): ";
                inorderTraversal(root);
                cout << endl;
            }
            else if (strcmp(input, "후위") == 0) {
                cout << "이진 검색 트리 (후위 순회): ";
                postordertraverse(root);
                cout << endl;
            }
            else {
                cout << "잘못된 입력으로 기본값인 중위순회로 출력합니다. ";
                inorderTraversal(root);
                cout << endl;
            }

        }
        else if (strcmp(input, "종료") == 0) {
            break;
        }
        else {
            cout << "잘못된입력입니다." << endl;
        }

    }
    


    

    return 0;
}