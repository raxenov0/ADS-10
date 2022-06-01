// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#endif  // INCLUDE_TREE_H_
#include <vector>
#include <iostream>
#include <string>

template<typename T>
class Tree {
private:
  struct Node {
        std::vector<Node*> points;
        T value;
    };
    Node* root;
    Node* current;
    std::vector <T> elements;
    std::string element;
    std::vector<T> perest;
    std::vector<std::vector<T>> result;
    
public:
    Tree(std::vector <T> in) {
        elements = in;
        element.resize(in.size());
        perest.resize(in.size());
        Node* root = new Node;
        root->value = '*';
        transition(in, -1, 0, root);
    }
    Node* createNode(T value) {
        Node* temp = new Node;
        temp->value = value;
        return temp;
    }
    void transition(std::vector<char> in, int k,int number, Node* root) {
        if (in.size() == 1) {
            result.push_back(perest);
            return;
        }
        auto iter = in.cbegin();
        if (k >= 0) {
            number++;
            in.erase(iter + k);
        }
        for (int i = 0; i < in.size(); i++) {
            root->points.push_back(createNode(in[i]));
            perest[number] = in[i];
            transition(in, i,number,root->points[i]);
        }
    }
    std::vector<T> getPerm(int number) {
        if (number > result.size()) throw("Error!");
        return result[number-1];
    }
};
