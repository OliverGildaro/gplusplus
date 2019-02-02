bool test0()
{
      messenger im;
      im.add_user(user { "juan" });
      im.add_user(user { "roberto" });

      string s;
      im.iterate_users([&s](auto& u)
      {
            s += u.get_name();
      });

      return s == "juanroberto" || s == "robertojuan";
}

bool test1()
{
      try
      {
            messenger im;
            im.add_user(user { "juan" });
            im.add_user(user { "roberto" });

            im["roberto"].send_message("juan", "nos vemos a las 5");
      }
      catch (const exception& ex)
      {
            string s = ex.what();
            return s == "User 'roberto' is not logged into the system";
      }

      return false;
}

bool test2()
{
      try
      {
            messenger im;
            im.add_user(user { "juan" });
            im.add_user(user { "roberto" });

            im.login_user("roberto", [](auto&) { });
            im["roberto"].send_message("juan", "nos vemos a las 5");
      }
      catch (const exception& ex)
      {
            string s = ex.what();
            return s == "User 'juan' is not logged into the system";
      }

      return false;
}

bool test3()
{
      try
      {
            messenger im;
            im.add_user(user { "juan" });
            im.add_user(user { "roberto" });

            im.login_user("roberto", [](auto&) { });
            im["maria"].send_message("roberto", "hola");
      }
      catch (const exception& ex)
      {
            string s = ex.what();
            return s == "User 'maria' is not registered into the system";
      }

      return false;
}

bool test4()
{
      try
      {
            messenger im;
            im.add_user(user { "juan" });
            im.add_user(user { "roberto" });

            im.login_user("roberto", [](auto&) { });
            im["roberto"].send_message("maria", "hola");
      }
      catch (const exception& ex)
      {
            string s = ex.what();
            return s == "User 'maria' is not registered into the system";
      }

      return false;
}


bool test5()
{
      messenger im;
      im.add_user(user { "juan" });
      im.add_user(user { "roberto" });

      im.login_user("roberto", [](auto& ) { });
      string s;
      string r;
      im.login_user("juan", [&s, &r](auto& msg)
      {
            s = msg.get_message();
            r = msg.get_sender();
      });
      im["roberto"].send_message("juan", "nos vemos a las 5");

      return s == "nos vemos a las 5" && r == "roberto";
}

bool test6()
{
      string s;
      auto f = [&s](auto& msg)
      {
            s += msg.get_message() + msg.get_sender() + msg.get_receiver();
      };

      messenger im;
      im.add_user(user { "juan" });
      im.add_user(user { "roberto" });
      im.add_user(user_group { "cuates", "juan", "roberto" });

      im.login_user("roberto", f);
      im.login_user("juan", f);

      im["juan"].send_message("cuates", "invito pizza");
      return s == "invito pizzajuancuatesinvito pizzarobertocuates" || s == "invito pizzarobertocuatesinvito pizzajuancuates";
}

bool test7()
{
      try
      {
            messenger im;
            im.add_user(user { "juan" });
            im.add_user(user { "roberto" });

            im.login_user("roberto", [](auto&) { });
            im.login_user("juan", [](auto&) { });
            im.logoff_user("roberto");
            im["roberto"].send_message("juan", "nos vemos a las 5");
      }
      catch (const exception& ex)
      {
            string s = ex.what();
            return s == "User 'roberto' is not logged into the system";
      }

      return false;
}

bool test8()
{
      try
      {
            messenger im;
            im.add_user(user { "juan" });
            im.add_user(user { "roberto" });

            im.login_user("roberto", [](auto&) { });
            im.login_user("juan", [](auto&) { });
            im.logoff_user("juan");
            im["roberto"].send_message("juan", "nos vemos a las 5");
      }
      catch (const exception& ex)
      {
            string s = ex.what();
            return s == "User 'juan' is not logged into the system";
      }

      return false;
}

bool test9()
{
      message_storage ms { messenger { } };

      ms->add_user(user { "juan" });
      ms->add_user(user { "roberto" });

      ms.login_all_users();

      (*ms)["roberto"].send_message("juan", "hola");
      (*ms)["roberto"].send_message("juan", "te cuento que me encontré con jorge");

      (*ms)["juan"].send_message("roberto", "y que te dijo");

      (*ms)["roberto"].send_message("juan", "que vayamos todos la concierto el viernes");

      (*ms)["juan"].send_message("roberto", "genial, vamos, bye");

      string s;
      ms.iterate_messages([&s](auto& msg)
      {
            s += msg.get_sender() + ";" + msg.get_receiver() + ";"  + msg.get_message() + ";";
      });

      return s == "roberto;juan;hola;roberto;juan;te cuento que me encontré con jorge;juan;roberto;y que te dijo;roberto;juan;que vayamos todos la concierto el viernes;juan;roberto;genial, vamos, bye;";
}



int main()
{
      vector<function<bool()>> tests;
      tests.push_back(test0);
      tests.push_back(test1);
      tests.push_back(test2);
      tests.push_back(test3);
      tests.push_back(test4);
      tests.push_back(test5);
      tests.push_back(test6);
      tests.push_back(test7);
      tests.push_back(test8);
      tests.push_back(test9);

      auto accum = 0;
      for (auto& test : tests)
      {
            accum += test();
      }
      cout << "SCORE: " << accum << " / " << tests.size() << "\n";
      return 0;
}