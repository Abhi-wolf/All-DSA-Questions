#include <iostream>
#include <unordered_map>
using namespace std;

/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/

class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *prev;

    Node(int k, int v)
    {
        this->key = k;
        this->value = v;
        this->prev = this->next = NULL;
    }
};

class LRUCache
{
    unordered_map<int, Node *> mp;
    int len;
    int cap;
    Node *head;
    Node *tail;

public:
    LRUCache(int capacity)
    {
        this->len = 0;
        this->cap = capacity;
        this->head = NULL;
        this->tail = NULL;
    }

    int get(int key)
    {
        // check if key is present -- if present than move the node to the front of the linked list
        if (mp.find(key) != mp.end())
        {
            Node *t = mp[key];

            if (t != this->head)
            {
                if (t->prev)
                    t->prev->next = t->next;

                if (t->next)
                    t->next->prev = t->prev;

                if (t == this->tail)
                    this->tail = t->prev;

                t->next = this->head;
                t->prev = NULL;
                if (this->head)
                    this->head->prev = t;
                this->head = t;
            }

            return t->value;
        }

        // return -1 if key is not found
        return -1;
    }

    void put(int key, int value)
    {
        // if the key is present then modify the value in the map and move the node to the front
        if (mp.find(key) != mp.end())
        {
            Node *t = mp[key];
            t->value = value;

            // move node to front
            if (t != this->head)
            {
                if (t->prev)
                    t->prev->next = t->next;

                if (t->next)
                    t->next->prev = t->prev;

                if (t == this->tail)
                    this->tail = t->prev;

                t->next = this->head;
                t->prev = NULL;
                if (this->head)
                    this->head->prev = t;
                this->head = t;
            }
        }
        else
        {
            // key not present in the map
            // create a new node
            Node *newnode = new Node(key, value);

            // add this node to the map
            mp[key] = newnode;

            // if there is no node
            if (this->len == 0)
            {
                this->head = this->tail = newnode;
            }
            else
            {
                // add the new node to the head of the linked list
                newnode->next = this->head;
                this->head->prev = newnode;
                this->head = newnode;
            }

            // increase the length
            this->len++;

            // remove the last node if the size is greater than the capacity
            if (this->len > this->cap)
            {
                // remove the key from map
                mp.erase(tail->key);

                Node *todelete = this->tail;
                this->tail = this->tail->prev;
                if (this->tail)
                    this->tail->next = NULL;

                delete todelete;
                this->len--;
            }
        }
    }
};

int main()
{
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << "GET key = 1 -->" << obj->get(1) << endl;
    obj->put(3, 3);
    cout << "GET key = 2 -->" << obj->get(2) << endl;
    obj->put(4, 4);
    cout << "GET key = 1 -->" << obj->get(1) << endl;
    cout << "GET key = 3 -->" << obj->get(3) << endl;
    cout << "GET key = 4 -->" << obj->get(4) << endl;
    return 0;
}