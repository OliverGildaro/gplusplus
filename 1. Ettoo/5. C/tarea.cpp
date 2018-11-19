//tarea


struct StringBuilder
{
      /* data */
};

void init(SB* sb);
void add(SB* sb, const char*);
void add(SB* sb, int n);
void add_line(SB* sb, const char*);//a;adir un enter al final
size_t get_length(const SB* sb);
const char* get_string(const SB* sb);
void release(SB* sb);

//char aux[20];
//itoa(458, aux, "la base"10) transforma int a char

int main()
{

}
