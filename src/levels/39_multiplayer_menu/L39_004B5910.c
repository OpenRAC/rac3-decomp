#include "common.h"

u32 func_L39_004B5910(u32 x) {
    u32 r;
    u32 t;
    do { r = x << 24; } while (0);
    t = x & 0xFF00;
    t <<= 8;
    r |= t;
    t = x >> 8;
    t &= 0xFF00;
    r |= t;
    t = x >> 24;
    r |= t;
    return r;
}

u32 func_L39_004B5938(u32 x) {
    u32 r;
    u32 t;
    do { r = (x << 8) & 0xFF00; } while (0);
    t = x >> 8;
    t &= 0xFF;
    if (x == 0 && (t & 0x100) != 0) {
        return r | t;
    } else {
        return r | t;
    }
}
