#include <assert.h>

#include "mugi.h"

int main(int argc, char *argv[]) {
    MUGI_State_t state;
    uint64_t out;

    const unsigned char key[16] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
    };
    const unsigned char iv[16] = {
        0xf0, 0xe0, 0xd0, 0xc0, 0xb0, 0xa0, 0x90, 0x80,
        0x70, 0x60, 0x50, 0x40, 0x30, 0x20, 0x10, 0x00
    };

    MUGI_Init(&state, key, iv);

    MUGI_Stream_Unit(&state, &out);
    assert(out == 0xbc62430614b79b71ULL);

    MUGI_Stream_Unit(&state, &out);
    assert(out == 0x71a66681c35542deULL);

    MUGI_Stream_Unit(&state, &out);
    assert(out == 0x7aba5b4fb80e82d7ULL);

    MUGI_Stream_Unit(&state, &out);
    assert(out == 0x0b96982890b6e143ULL);

    return 0;
}
