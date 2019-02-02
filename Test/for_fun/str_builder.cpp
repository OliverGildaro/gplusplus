

Create a StringBuilder to work in a method like this:

 

int main()

{

      StringBuilder sb;

      sb.append("(");

      for (int i = 0; i < 1000; i++)

      {

            for (int j = 0; j < 1000; j++)

            {

                  sb.append(i);

                  sb.append(", ");

                  sb.append(j);

                  sb.append("); ");

            }

           

            sb.appendLine("");

      }

     

      cout << sb.getChars() << "\n";

}

 

// It should show something like:

/*

(0, 0); (0, 1); (0, 2); ............. (0, 999);

(1, 0); (1, 1); (1, 2); ............. (1, 999);

...

...

(999, 0); (999, 1); (999, 2); ........... (999, 999);

*/

 

Do not use std::string, just only char*.

Test for memory leaks, they should be.. ZERO.

Try to be as performant as possible.

 
