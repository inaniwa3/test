// https://cybozu.atlassian.net/wiki/spaces/pubjp/pages/8159240

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>

class file {
public:
    file(const std::string& filename):
        m_fd(open(filename.c_str(), O_RDONLY)) {
        std::cout << "m_fd: " << m_fd << std::endl;
        if( m_fd == -1 )
            throw std::runtime_error("failed to open" + filename);
    }
    virtual ~file() {
        std::cout << "destructor" << std::endl;
        if( m_fd != -1 ) close(m_fd);
    }
    int fileno() const {
        return m_fd;
    }
    int read_fuga(char* in, std::size_t len) {
        std::size_t n_read = 0;
        while( n_read != len ) {
            int t = read(m_fd, in, len - n_read);
            if( t == 0 )
                throw std::runtime_error("unexpected end of file");
            if( t == -1 )
                throw std::runtime_error("failed to read");
            n_read += t;
        }
        return n_read;
    }
private:
    const int m_fd;
};
 
void read_hoge(const std::string& filename) {
    file f(filename);
    std::vector<char> v(8);
    f.read_fuga(&(v[0]), 8);  // ファイルが 8 バイト未満なら例外が飛ぶが、f は close される
    // 正常なときも f は close される
    std::cout << "read" << std::endl;
}

int main()
{
    try {
        read_hoge("size00.txt");
    } catch (...) {
        std::cout << "catch" << std::endl;
    }
    // m_fd: 3
    // destructor
    // catch

    try {
        read_hoge("size10.txt");
    } catch (...) {
        std::cout << "catch" << std::endl;
    }
    // m_fd: 3
    // read
    // destructor

    return 0;
}
