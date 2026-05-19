#include "ofstream12.h"


ofstream12::ofstream12(const char* aFileName, size_t aBufferSize)
{
    fBufferSize = aBufferSize;
    fBuffer = new std::byte[fBufferSize];
    reset();

    if (aFileName != nullptr)
    {
        open(aFileName);
    }
}

void ofstream12::reset() {
    fByteIndex = 0;
    fBitIndex = 7;
    // memset(fBuffer, 0, fBufferSize); // wipe entire buffer to 0s
}

void ofstream12::writeBit1() {
    fBuffer[fByteIndex] = std::byte(1 << fBitIndex); //write a 1 
    completeWriteBit();
}

void ofstream12::writeBit0() {
    completeWriteBit();
}

void ofstream12::completeWriteBit()
{
    fBitIndex--;
    if (fBitIndex < 0)
    {
        fByteIndex++;
        fBitIndex = 7;

        //if the buffer itself is still full
        if (fByteIndex == fBufferSize)
        {
            flush();
        }
    }
}

void ofstream12::flush()
{
    size_t lBytes = fBitIndex == 7 ? fByteIndex : fByteIndex + 1;

    fOStream.write(reinterpret_cast<char*>(fBuffer), lBytes);

    reset();
}

void ofstream12::open(const char* aFileName)
{
    fOStream.open(aFileName, std::ios::binary);
}


void ofstream12::close()
{
    fOStream.close();
}

bool ofstream12::good() const
{
    return fOStream.good();
}

bool ofstream12::is_open() const
{
    return fOStream.is_open();
}

ofstream12& ofstream12::operator<<(size_t aValue)
{
    for (int i = 11; i >= 0; i--)
    {
        if (aValue & (1 << i))
            writeBit1();
        else
            writeBit0();
    }

    return *this;
}

ofstream12::~ofstream12()
{
    flush();
    close();
    delete[] fBuffer;
}