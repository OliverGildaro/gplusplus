
#include <iostream>
//implement red black tree

using namespace std;

template <typename T>

struct default_less
{
      bool is_less(const T& a, const T& b) const
      {
            return a < b;
      }
};

template <typename T, typename LESS=default_less<T>>//le pasamos una politica que implemente un algoritmo de comparacion
class Tree
{
private:
      struct Node
      {
            T elem;
            Node* left;
            Node* right;
      };
      Node* root;
      LESS c;

public:
      Tree()
      :root{nullptr} { }
      ~Tree() 
      { 
            release(root);
      }

      void add(const T& n)
      {
            add(root, n);
      }

      void print() const
      {
            print(root);
      }

      void release(Node* node)
      {
            if(node == nullptr) return;
            release(node->left);
            release(node->right);
            delete node;
      }

      const T& operator[](const T& e)
      {
            return find(root, e);
      }

private:
      void add(Node*& node, const T& n)//(&)ahora root y node son el mismo puntero
      {
            if(node == nullptr)
            {
                  node = new Node{n, nullptr, nullptr};
                  return;
            }

            bool less = c.is_less(n, node->elem);
            if(less)
                  add(node->left, n);
            else
                  add(node->right, n);
      }
      void print(Node* node) const
      {
            if(node==nullptr)
                  return;
            print(node->left);
            cout << node->elem << "\n";
            print(node->right);
      }

      const T& find(Node* node, const T& e) const
      {
            if(node == nullptr)
                  throw "not found";
            
            bool less = c.is_less(e, node->elem);
            if(less)
                  return find(node->left, e);
            if(c.is_less(node->elem, e))
                  return find(node->right, e);
            
            return node->elem;
      }
};

int main()
{
      Tree<int> p;
      p.add(14);
      p.add(55);
      p.add(23);
      p.add(65);
      p.add(2);

      Tree<string> s;
      s.add("hello");
      s.add("world");
      s.add("today");
      s.add("is");
      s.add("friday");

      p.print();
      s.print();

      auto& ss = s["gatuso"];
      cout << "ELEMENT: " << ss << "\n";
}
