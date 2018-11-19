//enums ...... valores discretos manejados por el compilador

//existen dos tipos de enums

//c enum
enum severity
{
      HIGH,
      LOW
};

//scoped enum c++11
enum class severityPLus// reutiliza la palabra class
{
      HIGH = 10,
      LOW,//este sera 11
      //se puede poner valores arbitrarios
      MID = 45
};

int main()
{
      severity s = HIGH;
      severityPLus s2 = severityPLus::HIGH;// vive dentro del scope.... :: scope operator
}