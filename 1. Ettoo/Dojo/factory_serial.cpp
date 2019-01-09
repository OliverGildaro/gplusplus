
Ernesto Bascon Pantoja<Ernesto.Bascon@jalasoft.com>
vie 7/12, 10:56 DEVINT27; Roland Miranda Aviles (roland.miranda@icloud.com); Pablo Azero; Romulo Rojas

Implement everything needed to run this code properly:

 

int main()

{

      auto p = SerializerFactory::get_serializer(SerializerType::Xml);

      auto q = SerializerFactory::get_serializer(SerializerType::Json);

     

      auto car = new Car("123ABC", "Volkswagen", "Beetle", 1970);

      auto person = new Person("Juan", "Perez", Date { 10, 2, 1976 });

     

      auto cp = car->serialize(p);

      auto cq = car->serialize(q);

     

      auto pp = person->serialize(p);

      auto pq = person->serialize(q);

     

     

      cout << cp.to_str() << "\n";

      cout << cq.to_str() << "\n\n";

     

      cout << pp.to_str() << "\n";

      cout << pq.to_str() << "\n";

     

      delete car;

      delete person;

     

}

 

//Notice I am not explicitly invoking delete for the serializers, think on how to make their destructors to be invoked anyway.

 

//Should print:

//<car><id>123ABC</id><brand>Volkswagen</brand><model>Beetle</model><year>1970</year></car>

//{ "id": "1234ABC", "brand": "Volkswagen", "model": "Beetle", "year": 1970 }

//

//<person><firstname>Juan</firstname><lastname>Perez</lastname><date><day>10</day><month>2</month><year>1976</year></date></person>

//{ "firstname" : "Juan", "lastname", "Perez", "date" : { "day": 10, "month": 2, "year" : 1976 } }

 

 

 

//ENJOY!!!
