// http://www.cplusplus.com/doc/tutorial/classes2/

class Example2 {
    int total;
  public:
    Example2 (int initial_value) : total(initial_value) { };
    void accumulate (int x) { total += x; };
};

int main()
{
    Example2 ex (100);   // ok: calls constructor

//  Example2 ex_;        // not valid: no default constructor
    // a.cpp:14:14: error: no matching function for call to 'Example2::Example2()'
}
