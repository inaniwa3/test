// https://ja.wikipedia.org/wiki/RAII
// Resource Acquisition Is Initialization 資源獲得時初期化

#include <cstddef>

// RAII を実現する配列ラッパークラス。
template<typename T> class ArrayWrapper {
    size_t m_count;
    T* m_data;
public:
    ArrayWrapper() : m_count(), m_data() {}
    explicit ArrayWrapper(size_t count) : m_count(count), m_data(new T[count]()) {}
    ~ArrayWrapper() { delete[] m_data; }
    size_t count() const { return m_count; }
    T* data() { return m_data; }
    const T* data() const { return m_data; }
    T& operator[](size_t index) { return m_data[index]; }
    const T& operator[](size_t index) const { return m_data[index]; }
    // コピーは禁止とする。所有権の移動もサポートしない。
private:
    ArrayWrapper(const ArrayWrapper&);
    ArrayWrapper& operator=(const ArrayWrapper&);
};

void function1B(size_t count) {
    ArrayWrapper<double> array1(count);
    ArrayWrapper<double> array2(count);

    // 動的に確保した配列をここで作業領域として使用する。
    for (size_t i = 0; i < count; ++i) {
        array1[i] = i * 0.1;
        array2[i] = i * 0.1;
    }
    // ...

} // RAII 変数 array1, array2 の属するブロックを抜ける。
  // このとき array2, array1 の各デストラクタが順に呼ばれ、
  // それぞれが内部で管理する配列メモリ領域は自動的に破棄される。

int main()
{
    function1B(16);
    return 0;
}
