class Hoge
{
public:
    Hoge(int m) : m(m) {}
    void Test0()       { this->m = 0; }
//  void Test1() const { this->m = 1; }
private:
    int m;
};

int main()
{
    Hoge h(-1);
}
