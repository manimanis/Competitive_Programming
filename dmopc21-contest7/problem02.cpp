#include <bits/stdc++.h>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode(int val, ListNode* next=nullptr, ListNode* prev=nullptr): val(val), next(next), prev(prev) {}
};

class LinkedList {
    ListNode *_head;
    ListNode *_tail;
public:
    LinkedList(): _head(nullptr), _tail(nullptr) {}
    void appendNode(int val) {
        ListNode *node = new ListNode(val);
        if (_head == nullptr) {
            _head = node;
            _tail = node;
        }
        _tail->next = node;
        node->prev = _tail;
        _tail = node;
    }
    
    ListNode* find(int val) {
        return find(_head, val);
    }

    ListNode* find(ListNode* start, int val) {
        ListNode* p = start;
        while (p != nullptr) {
            if (p->val == val) {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }

    void move(int l, int r, int k) {
        ListNode* pl = find(l);
        ListNode* pr = find(pl, r);
        if (k == 0) {
            if (pl->prev != nullptr) {
                pl->prev->next = pr->next;           
            }
            if (pr->next != nullptr) {
                pr->next->prev = pl->prev;
            } else {
                _tail = pl->prev;
            }
            _head->prev = pr;
            pr->next = _head;
            _head = pl;
        } else {
            ListNode* pk = find(k);
            pl->prev->next = pr->next;
            if (pr->next != nullptr) 
                pr->next->prev = pl->prev;
            else
                _tail = pl->prev;
            pr->next = pk->next;
            pk->next->prev = pr;
            pk->next = pl;
            pl->prev = pk;
        }
    }

    void print() {
        ListNode* p = _head;
        while (p != nullptr) {
            if (p != _head) cout << " ";
            cout << p->val;
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    int n, q, l, r, k;
    cin >> n >> q;
    LinkedList scarf;
    for (int i = 1; i <=n; i++) {
        scarf.appendNode(i);
    }
    for (int i = 0; i < q; i++) {
        cin >> l >> r >> k;
        scarf.move(l, r, k);
    }
    scarf.print();
}