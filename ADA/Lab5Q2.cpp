#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node( int x){
        data = x;
        next = NULL;
    }
};

