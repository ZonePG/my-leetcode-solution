class Node {
public:
  int key, value;
  Node* next;
  Node* prev;
  Node(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}
};

class DoubleList {
public:
  Node* head;
  Node* tail;
  int num_node;

  DoubleList() {
    this->head = new Node(0, 0);
    this->tail = new Node(0, 0);
    this->head->next = tail;
    this->tail->prev = head;
    this->num_node = 0;
  }

  void addFirst(Node* node) {
    Node *headNext = head->next;
    head->next = node;
    headNext->prev = node;
    node->prev = head;
    node->next = headNext;
    num_node++;
  }

  void remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    node = nullptr;
    num_node--;
  }

  int removeLast() {
    Node* last = tail->prev;
    int key = last->key;
    remove(last);
    return key;
  }

  int size() {
    return num_node;
  }
};

class LRUCache {
private:
  unordered_map<int, Node*> map;
  DoubleList cache;
  int capacity;
public:
    LRUCache(int capacity) {
      this->capacity = capacity;
    }
    
    int get(int key) {
      if (!map[key]) {
        return -1;
      }
      int val = map[key]->value;
      put(key, val);
      return val;
    }
    
    void put(int key, int value) {
      Node *node = new Node(key, value);
      if (map[key]) {
        cache.remove(map[key]);
        cache.addFirst(node);
        map[key] = node;
      } else {
        // delete last key
        if (cache.size() == capacity) {
          int key = cache.removeLast();
            map.erase(key);
        }
        cache.addFirst(node);
        map[key] = node;
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
