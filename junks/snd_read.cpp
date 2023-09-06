#include <iostream>
#include <string>
#include <inttypes.h>
#include <sndfile.hh>

#define BUF_SIZE    1024

int main(void)
{
    const char *fp_name = "untitled.wav";
    SndfileHandle fp(fp_name, SFM_READ);
    static int16_t buffer[BUF_SIZE];

    fp.read(buffer, BUF_SIZE);

    return 0;
}