#include <iostream>
#include <cstring>
using namespace std;

class texto
{
private:
      size_t len;
      size_t len_abc;
      char* tok;

public:
      texto(const char* txt)
      { 
            tokenizer(txt);
      }
      ~texto() { }

      bool is_letter(char letter)
      {
            const char* abcd = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            len_abc = strlen(abcd);
            
            for(size_t i = 0; i < len_abc; i++)
            {
                  if(letter == abcd[i])
                        return true;
            }
            return false;
      }

      void tokenizer(const char* txt)
      {
            len = strlen(txt);
            size_t pos_init;
            size_t count_letter = 0;
            for(size_t i = 0; i < len; i++)
            {
                  if(is_letter(txt[i]) == true)
                  {
                        pos_init = i;
                        do{
                              count_letter++;

                        }while(is_letter(txt[++i]));

                        tok = new char[count_letter+1];

                        for(size_t i = 0; i < count_letter; i++)
                        {
                              tok[i] = txt[pos_init++];
                        }
                        tok[count_letter] = 0;                       
                        cout << tok << "\n";
                  }
                  count_letter = 0;
            }
      }
};

int main()
{
      texto t{"My name's oliver, i live in the house of my mom. I have two brothers and one syster... i use to study c++ and i like to make songs, for example: cantame and delirio."};
      // texto t2{"my name..s oliver"};
}