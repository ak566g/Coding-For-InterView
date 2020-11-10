#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


class disjointSet
{
    public:
    class Node
    {
        public:
        int data;
        int rank;
        Node *parent;
    };


    unordered_map<int, Node*> myMap;
    
    void makeSet(int data)
    {
        Node *node = new Node();
        node->data = data;
        node->parent = node;
        node->rank = 0;
        myMap[data] = node;
    }

    int findSet(int data)
    {
        return findSet(myMap[data])->data;
    }

    Node* findSet(Node* node)
    {
        Node *parent = node->parent;
        if(parent == node)
        {
            return parent;
        }
        node->parent = findSet(node->parent);
        return node->parent;
    }

    void Union(int data1, int data2)
    {
        Node *first_node = myMap[data1];
        Node *second_node = myMap[data2];

        Node *parent1 = findSet(first_node);
        Node *parent2 = findSet(second_node);

        //If they are the part of same set do nothing
        if(parent1->data == parent2->data)
        {
            return;
        }

        //else whose rank is higher becomes parent of other
        if(parent1->rank >= parent2->rank)
        {
            if(parent1->rank == parent2->rank)
            {
                parent1->rank += 1;
                parent2->parent = parent1;
            }
            else
            {
                parent1->parent = parent2;
            }
        }
    }
};

int main()
{
    disjointSet *ds = new disjointSet();
    ds->makeSet(1);
    ds->makeSet(2);
    ds->makeSet(3);
    ds->makeSet(4);
    ds->makeSet(5);
    ds->makeSet(6);
    ds->makeSet(7);

    ds->Union(1, 2);
    ds->Union(2, 3);
    ds->Union(4, 5);
    ds->Union(6, 7);
    ds->Union(5, 6);
    ds->Union(3, 7);

    cout << ds->findSet(1) << endl;
    cout << ds->findSet(2) << endl;
    cout << ds->findSet(3) << endl;
    cout << ds->findSet(4) << endl;
    cout << ds->findSet(5) << endl;
    cout << ds->findSet(6) << endl;
    cout << ds->findSet(7) << endl;
}