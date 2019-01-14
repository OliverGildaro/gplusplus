// Implement a f_stack<T> (LIFO) class.

// Implement a RPN evaluator class. (1 2 +) will push 1 and 2 in a stack, and the operator + will remove  them and push into them the result of adding them up. It will support the 4 basic operations.

// You can use everything seen at class, but no other stuff.

// Not compiling code will render your exam useless.

// Having memory leaks will subtract 10 points to your last score.

// Do not use inheritance, polymorphism or any virtual thing.

#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <cstring>

using namespace std;


class f_exception : public exception
{
private:
    size_t len;
    char* m_except;
public:
    f_exception(const char* p_except)
    :len{strlen(p_except)}, m_except{new char[len+1]} 
    {
        memcpy(m_except, p_except, len+1);
    }
    ~f_exception() { }

    const char* what() const noexcept override
    {
        return m_except;
    }
};

template<typename T>
class Node
{
private:
    T value;
public:
    Node<T>* previous;
public:
    Node(const T& value)
    :value{value} 
    { 
        previous = nullptr;
    }

    T get_value()
    {
        return value;
    }
};

template<typename T>
class linked_list
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t count;
public:
    linked_list()
    :first{nullptr}, last{nullptr}, count{0} { }

    void push(Node<T>* node)
    {
        if(first == nullptr)
        {
            first = last = node;
        }
        else
        {
            node->previous = last;
            last = node;
        }
        count++;
    }

    size_t get_size() const
    {
        return count;
    }

    T pop()
    {
        Node<T>* aux;
        if(last != nullptr)
        {
            T aux_value = last->get_value();
            aux = last;
            last = last->previous;
            count--;
            delete aux;
            return aux_value;
        }
        else
        {
            throw f_exception{"Attempt to pop value from empty stack"};
        }
    }

    template <typename PROC>
    void iterate(PROC p)
    {
        Node<T>* aux = last;
        for(size_t i = 0; i < count; i++)
        {
            T value = aux->get_value();
            p(value);
            aux = aux->previous;
        }
    }
    
};


template<typename T>
class f_stack
{
private:
    T value;
    linked_list<T> list;
public:
    f_stack() { }

    bool is_empty()
    {
        if(list.get_size() == 0)
        {
            return true;
        }
        return false;
    }

    void push(const T& value)
    {
        Node<T>* node = new Node<T>{value};
        list.push(node);
    }

    T pop()
    {
        return list.pop();
    }

    template <typename PROC>
    void iterate(PROC p)
    {
        list.iterate(p);
    }
};

bool test0()

{

    f_stack<int> st;

    auto r1 = st.is_empty();

    st.push(10);

    auto r2 = st.is_empty();

    return r1 && !r2;

}



bool test1()

{

    f_stack<int> st;

    st.push(50);

    st.push(40);

    st.push(25);



    return st.pop() == 25 && st.pop() == 40; }



bool test2()

{

    f_stack<string> s;

    s.push("easy");

    s.push("was");

    s.push("exam");

    s.push("second");



    auto s4 = s.pop();

    auto s3 = s.pop();

    auto s2 = s.pop();

    auto s1 = s.pop();

    return s4 == "second" && s3 == "exam" && s2 == "was" && s1 == "easy" && s.is_empty(); }



bool test3()

{

    f_stack<string> sd;

    sd.push("devices");

    sd.push("own");

    sd.push("my");

    sd.push("to");

    sd.push("left");



    string accum;

    sd.iterate([&accum](auto& x)

    {
        accum += x + " ";
    });


    string accum2;

    sd.iterate([&accum2](auto& x)

    {

        accum2 += x + " ";

    });


    return accum == accum2 && accum == "left to my own devices "; }



bool test4()

{

    try

    {

        f_stack<string> x;

        x.push("hello");

        x.push("world");



        x.pop();

        x.pop();

        x.pop();



        return false;

    }

    catch (const std::exception& ex)
    {
        return "Attempt to pop value from empty stack"s == ex.what();
    }

}

template <typename PROC>
void split_string(char a, const string& str, PROC p)
{
    size_t len = str.length();
    char* st = new char[len+1];
    memcpy(st, str.data(), len+1);

    char *pChar = &a;

    char* token = strtok(st, pChar);

    while(token)
    {
        string s{token};
        p(s);
        token = strtok(nullptr, pChar);
    }
}

class evaluator
{
private:
public:
    evaluator()
    { 
    }
    ~evaluator() { }

    double evaluate(const string& str)
    {
        f_stack<int> fc = f_stack<int>{};
        split_string(' ', str, [fc](auto& charAst){
            if(charAst == "+")
            {
                // cout << "es suma\n";
            }
            else if(charAst == "-")
            {
                // cout << "es resta\n";

            }
            else if(charAst == "*")
            {
                // cout << "es mul\n";

            }
            else
            {
                fc.push(charAst);
            }
        });
    }
};


bool test5()

{

    string result;

    split_string(' ', "abc def ghi jkl", [&result](auto& s)

    {

        result += s + "; ";

    });



    return result == "abc; def; ghi; jkl; "; }




bool test6()

{

    evaluator m;

    return m.evaluate("10 30 +") == 40;

}



bool test7()

{

    evaluator x;

    return x.evaluate("10 20 50 + *") == 700; }



bool test8()

{

    try

    {

        evaluator x;

        x.evaluate("10 20 + +");

        return false;

    }

    catch (const exception& x)

    {

        return "Operand not found"s == x.what();

    }

}



// bool test9()

// {

//     evaluator x;

//     x.add_operator("min", [](auto& x, auto& y)

//     {

//         return x < y ? x : y;

//     });



//     return x.evaluate("5 3 * 10 20 - min") == 15; }

using test = bool(*)();

auto main() -> int

{

    test tests[] = { test0,

                     test1,

                     test2,

                     test3,

                     test4,

                     test5,

                     test6,

                     test7,

                     test8,

                    //  test9

    };



    size_t score = 0;

    for (auto& t : tests)

    {

        score += t() * 10;

    }



    cout << "Score: " << score << " / 100\n";

    getchar();

    return 0;

}