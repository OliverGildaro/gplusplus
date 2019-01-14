#include <iostream>

using namespace std;



class Image
{
private:
    string name;
public:
    Image(const string& name)
    :name{name} { }
    ~Image() { }

    string get_name() const
    {
        return name;
    }
};


template<typename T>
class default_comparator
{
private:
public:
    bool is_less(T* a, T* b)
    {
        return a->get_name() < b->get_name();
    }
};

template<typename T>
class Node
{
private:
    T* img;
public:
    Node<T>* left;
    Node<T>* right;
public:
    Node(Image* img)
    :img{img} 
    { 
        left = nullptr;
        right = nullptr;
    }
    ~Node() { }

    T* get_imagePtr()
    {
        return img;
    }
};

template<typename T, typename LESS = default_comparator<T>>
class Tree
{
private:
    Node<T>* root;
    LESS c;
private:
    void add(Node<T>*& node, T* img)
    {
        if(node == nullptr)
        {
            node = new Node<T>{img};
            return;
        }
        bool less = c.is_less(node->get_imagePtr(), img);
        if(less)
        {
            add(node->left, img);
        }
        else
        {
            add(node->right, img);
        }
    }
public:
    Tree()
    :root{nullptr} { }

    void add(T* img)
    {
        add(root, img);
    }
};


int main()
{
    Tree<Image> t1;

    t1.add(new Image{"img1"});
    t1.add(new Image{"img2"});
}