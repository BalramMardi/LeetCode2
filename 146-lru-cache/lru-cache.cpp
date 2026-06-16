class LRUCache {
    struct Node{
        int key, val;
        Node* prev, *next;
        Node(int key, int val):key(key),val(val),prev(nullptr),next(nullptr){}
    };

    int capacity;
    Node* head,*tail;
    unordered_map<int,Node*> mp;
    void remove(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void insertFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }


public:
    LRUCache(int capacity):capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }
        Node* k = mp[key];
        remove(k);
        insertFront(k);
        return k->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insertFront(node);
            return;
        }

        if((int)mp.size() == capacity){
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
        
        Node* node = new Node(key,value);
        insertFront(node);
        mp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */