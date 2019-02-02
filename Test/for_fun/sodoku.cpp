Implement this sudoku solver:

int main()
{
        sudoku_solver<3> ss {
          "  8" "5  " "  7"
          " 6 " "4  " "   "
          "   " "2 9" "8 4"

          " 72" " 3 " " 4 "
          "5  " "   " " 8 "
          " 8 " "67 " "   "

          "6 3" "72 " "  8"
          "257" " 4 " " 6 "
          "   " "   " " 73" };

        auto  r = ss.solve();
        cout << r << "\n";
        return 0;
}


You can try to use backtrack algorithm in order to find the actual values.

You could also use a stack of possible states.