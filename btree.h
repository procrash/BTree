#pragma once
#include <stdint.h>
#include <algorithm>
#include <iostream>

template <typename T>
class BTree {

    enum class NodeType{Root, Left, Right};

    BTree<T>* parent{nullptr};
    BTree<T>* left{nullptr};
    BTree<T>* right{nullptr};
    int64_t balance{0};

    NodeType type;
    T data;

    bool isEmpty;

public:
    int dummy;
    BTree();

    BTree(T data);

    int64_t insert(T data);

    BTree* findNode(T data) {
        BTree* result = nullptr;
        if (this->data==data) {
            return this;
        }
        else {
            if (this->data>data) {
                return left->find(data);
            } else {
                return right->find(data);
            }
        }
    }

    void remove(T data) {
        BTree* result = find(data);

        // We don't have hanging something under our node
        if (result->left==nullptr && result->right==nullptr) {
            switch (type) {
                    case NodeType::Left  : parent->left = nullptr; break;
                    case NodeType::Right : parent->right = nullptr; break;
                    case NodeType::Root  : break;
            };
            delete result;
        } // A node hangs on the left side nothing on it's right side,
          // hang it in to the parent node
          else if (result->left != nullptr && result->right==nullptr){
            switch (type) {
                    case NodeType::Left  : parent->left = left; break;
                    case NodeType::Right : parent->right = nullptr; break;
                    case NodeType::Root  : break;
            };
            delete result;
        } // A node hangs on the right side nothing on the left side
          // hang it in on the right side of the parent
        else if (result->left == nullptr && result->right!=nullptr){
            switch (type) {
                    case NodeType::Left  : parent->left = nullptr; break;
                    case NodeType::Right : parent->right = right; break;
                    case NodeType::Root  : break;
            };
            delete result;
        } else {
            if (result->left!=nullptr && result->right!=nullptr) {
            switch (type) {
                    case NodeType::Left  : parent->left = nullptr; break;
                    case NodeType::Right : parent->right = nullptr; break;
                    case NodeType::Root  : break;
            };
                if (parent != nullptr) {
                        parent->insert(result->left);
                        parent->insert(result->right);
                            delete result;
                } else {
                    // One of the leafs will become the next root node

                }
            }
        }


    }

    void print() {
        BTree *rootNode = this;
        // while (!rootNode->parent==nullptr) rootNode = rootNode->parent;

        if (parent==nullptr) {
            std::cout << "RootNode " << this->data << std::endl;
        }
        else if (parent->left == this) {
                std::cout << "Left:" << this->data << std::endl;
        } else if (parent->right == this) {
                std::cout << "Right:" << this->data << std::endl;
        }

        if (left!=nullptr) left->print();
        if (right!=nullptr) right->print();


    }

    void rotateCounterClockwise() {
        if (parent==nullptr) return;
        T parentData = parent->data;
        parent->data = this->data;
        parent->right = nullptr;
        parent->insert(parentData);
    }
    void rotateClockwise() {
        if (parent==nullptr) return;
        T parentData = parent->data;
        parent->data = this->data;
        parent->left = nullptr;
        parent->insert(parentData);
    }

    int getBalance() {
        if (left!=nullptr && right!=nullptr) {
                return left->determineBalance()-right->determineBalance();
        }
        if (left!=nullptr && right==nullptr) {
            return -1-left->determineBalance();
        }
        if (right!=nullptr && left==nullptr) {
            return +1+right->determineBalance();
        }


    }

    int determineBalance() {
        int result = 0;

        if (this->left == nullptr && this->right == nullptr) return 0;
        if (this->left !=nullptr && this->right == nullptr) return 1+left->determineBalance();
        if (this->right !=nullptr && this->left == nullptr) return 1+right->determineBalance();
        if (this->left!=nullptr && this->right!=nullptr) return std::max(1+left->determineBalance(), 1+right->determineBalance());
    }

};


template<typename T>
BTree<T>::BTree() : isEmpty(true){

}


template<typename  T>
BTree<T>::BTree(T data) : isEmpty(false){
    this->data = data;
}



template<typename T>
int64_t BTree<T>::insert(T data) {
    if (this->isEmpty) {
        this->data = data;
        this->isEmpty = false;
    }
    else
    if (data < this->data) {
        if (left==nullptr) {
            left = new BTree(data);
            left->parent = this;
            left->type = NodeType::Left;
            balance--;
        } else {
                balance -= std::abs(left->insert(data));
        }
    } else if (data>this->data) {
        if (right==nullptr) {
                right = new BTree(data);
                right->parent = this;
                right->type = NodeType::Right;
                balance++;

        } else {
                balance += std::abs(right->insert(data));
        }
    } else {
        // Replace
        return 0;
    }

    return balance;
}

