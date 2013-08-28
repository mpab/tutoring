#include "stdafx.h"
#include "CircularBuffer.h"
#include <iostream>

using namespace std;

CircularBuffer::CircularBuffer(int length)
{
    _ridx = -1;
    _widx = 0;
    _buffer.resize(length);
}

CircularBuffer::~CircularBuffer()
{
}

void FillBuffer(CircularBuffer &cb)
{
	cout << "filling buffer" << endl;
    for (int i = 0; i != 100; ++i)
    {
        cb.write(i);
    }
}

void DumpBuffer(CircularBuffer &cb)
{
	cout << "reading from buffer" << endl;
	for (int i = 0; i != 100; ++i)
    {
        cout << cb.read() << endl;
    }
}

void TestBuffer()
{
	try 
	{
		CircularBuffer cb(10);
		DumpBuffer(cb);
	}
	catch (exception e)
	{
		cout << "caught exception " << e.what() << endl;
	}
}



void CircularBuffer::write(int a)
{
	_widx = (_widx + 1) % _buffer.size();
	_buffer[_widx] = a;

}

int CircularBuffer::read()
{
	if(_ridx == -1) 
		throw new exception("no data in buffer");
		//return -9999999;

	_ridx = (_ridx + 1) % _buffer.size();
    return _buffer[_ridx];

}
