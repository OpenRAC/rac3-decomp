/* functional: high. 16-bit byte swap of the low half of x (DNAS library helper); 3 diff, scheduling only. */
u32 func_L39_004B5938(u32 x) {
    u32 r;
    u32 t;
    do { r = x << 8; } while (0);
    r &= 0xFF00;
    t = x >> 8;
    t &= 0xFF;
    r |= t;
    return r;
}
