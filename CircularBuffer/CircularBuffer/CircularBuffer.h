#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <vector>
using namespace std;

void TestBuffer();

class CircularBuffer
{

    public:
        CircularBuffer(int length);
        virtual ~CircularBuffer();
        void write(int v);
        int read();

    protected:
    private:
        int _ridx;
        int _widx;
        vector<int> _buffer;
};

#endif // CIRCULARBUFFER_H







