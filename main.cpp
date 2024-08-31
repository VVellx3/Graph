#include <iostream>
#include <map>

struct Node {
  int value;
  Node* next = nullptr;

  Node(int val) : value(val) {}
};

struct Graph {
  std::map<Node*, Node*> nodes;

  void push(Node* val) {
    nodes[val] = val;
  }

  void connect(Node* val1, Node* val2) {
    nodes[val1]->next = val2;
  }

  Node* operator[](Node* val) {
    return nodes[val];
  }
};

int main() {
  Graph gr;

  Node* node1 = new Node(1);
  Node* node2 = new Node(2);
  Node* node3 = new Node(3);

  gr.push(node1);
  gr.push(node2);
  gr.push(node3);

  gr[node1]->value; // output: 1
  gr[node2]->value; // output: 2
  gr[node3]->value; // output: 3
  
  gr.connect(node1, node3);
  gr.connect(node2, node1);
  gr.connect(node3, node2);
  
  gr[node1]->next->value; //output: 3
  gr[node1]->next->next->next->value; //output: 1
  
  gr.connect(node3, node1); // not error, just update
  gr[node3]->next->value; // output: 1

  delete node1;
  delete node2;
  delete node3;

  return 0;
}
