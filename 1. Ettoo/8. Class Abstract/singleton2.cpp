//otra manera de instanciar un singleton

#include <iostream>

using namespace std;


struct singleton2
{
    private:
        singleton2()
        {
            cout << "hola amigos\n";
        }
    public:
        void hi() const
        {
            cout << "hoy es jueves\n";
        }

        static singleton2& instance()
        {
            static singleton2 s;
            return s;
        }
};


int main()
{
    singleton2::instance().hi();
    singleton2::instance().hi();
}