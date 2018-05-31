//
//  binarySearchTree.h
//  Assignment #12
//
//  Created by Raul Muniz on 4/18/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#ifndef binarySearchTree_h
#define binarySearchTree_h
#include <iostream>
#include<queue>

#include "binarySearchTree.h"
using namespace std;
class binarySearchTree
{
private:
    class node
    {
    public:
        int data;
        node *left;
        node *right;
        
        node(int x)
        {
            data = x;
            left = NULL;
            right = NULL;
        }
    };
    
    node *root;
    
    void recInsert(node * &p, double x)
    {
        if (p == NULL)
        {
            p = new node(x);
        }
        else
        {
            if (x < p->data)
            {
                recInsert(p->left, x);
            }
            else // x >= p->data
            {
                recInsert(p->right, x);
            }
        }
    }
    
    void preOrder(node * p)
    {
        if (p == NULL)
        {
            //nothing!
        }
        else
        {
            cout << p->data << endl;
            preOrder(p->left);
            preOrder(p->right);
        }
    }
    
    void inOrder(node * p)
    {
        if (p == NULL)
        {
            //nothing!
        }
        else
        {
            inOrder(p->left);
            cout << p->data << endl;
            inOrder(p->right);
        }
    }
    
    void postOrder(node * p)
    {
        if (p == NULL)
        {
            //nothing!
        }
        else
        {
            postOrder(p->left);
            postOrder(p->right);
            cout << p->data << endl;
        }
    }
    
    int recNumItems(node * p)
    {
        if (p == NULL)
            return 0;
        else
            return 1 + recNumItems(p->left) + recNumItems(p->right);
    }
    
    int recLeaves(node * p)
    {
        if (p == NULL)
            return 0;
        if (p->left == NULL && p->right == NULL)
        {
            return 1;
        }
        else
        {
            return recLeaves(p->left) + recLeaves(p->right);
        }
    }
    
    int height(node * p) {
        if (p == NULL) {
            return 0;
        }
        else
        {
            int left = height(p->left);
            int right= height(p->right);
            
            if(left > right)
                return left + 1;
            else
                return right + 1;
        }
    }
    
    int fullNodes (node * p)
    {
        if(p==NULL)
        {
            //nothing!
        }
        else if(p->left == NULL && p->right ==NULL)
        {
            return 0;
        }
        else if (p->left != NULL && p->right != NULL)
        {//full node
            return 1 + fullNodes(p->left) + fullNodes(p->right);
        }
        else if (p->left != NULL && p->right == NULL)
        { //go to left
            return fullNodes(p->left);
        }
        else if (p->left == NULL && p->right !=NULL)
        { //go to right
            return fullNodes(p->right);
        }
        return NULL;
    }
    
    int extractMin(node *& p)
    {
        if(p->left == NULL)
        {
            node *temp = p;
            int min = p->data;
            p = p->right;
            delete temp;
            return min;
        }
        else
            return extractMin(p->left);
    }
    
    int extractMax(node *& p)
    {
        if(p->right == NULL)
        {
            node * temp = p;
            int min = p->data;
            p = p->left;
            delete temp;
            return min;
        }
        else
            return extractMax(p->right);
    }
    
    void display(node * p)
    {
        if(p==NULL)
        {
            //Nothing!
        }
        else
        {
            display(p->left);
            cout<<p->data<<endl;
            display(p->right);
        }
    }
    
    void deleteNode(int data)
    {
        node **n = &root;
        while(true){
            if (data ==(*n)->data){
                break;
            }
            else if (data < (*n)->data){
                if ((*n)->left == NULL){
                    throw std::out_of_range ("Unknown object");
                }
                n = &(*n)->left;
            }
            else if (data > (*n)->data){
                if ((*n)->right == NULL){
                    throw std::out_of_range ("Unknown object");
                }
                n = &(*n)->right;
            }
        }
        if ((*n)->right == NULL){
            *n = (*n)->left;
        }
        else {
            node **temp = &(*n)->right;
            node **parent = NULL;
            while((*temp)->left != NULL){
                parent = temp;
                temp = &(*temp)->left;
            }
            
            node *right = (*temp)->right;
            
            (*temp)->left = (*n)->left;
            (*temp)->right = (*n)->right;
            *n = *temp;
            (*parent)->left = right;
        }
    }
    
    void levelDisplay(node *p){
        if (p == NULL)
            return;
        queue<node *> q;
        q.push(p);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
            cout << temp->data << " ";
        }
    }
    
    
    
    
public:
    
    binarySearchTree()
    {
        root = NULL;
    }
    
    void insert(double x)
    {
        recInsert(root, x);
    }
    
    void displayInorder()
    {
        inOrder(root);
    }
    
    void displayPreorder()
    {
        preOrder(root);
    }
    
    void displayPostorder()
    {
        postOrder(root);
    }
    
    int numItems()
    {
        return recNumItems(root);
    }
    
    int numLeaves()
    {
        return recLeaves(root);
    }
    
    int getHeight()
    {
        return height(root);
    }
    
    int fullNodes()
    {
        return fullNodes(root);
    }
    
    int extractMin()
    {
        return extractMin(root);
    }
    
    int extractMax()
    {
        return extractMax(root);
    }
    
    void display()
    {
        display(root);
    }
    
    void remove(int x)
    {
        deleteNode(x);
    }
    
    void levelOrderDisplay()
    {
        levelDisplay(root);
    }
    //part5
    binarySearchTree(double items[], int size);
};


#endif /* binarySearchTree_h */
