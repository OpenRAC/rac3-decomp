/* exact: byte-identical at level 01 (check.py). Levels 39-53 hold the pair at 0x24DE0/0x24DE4 instead (catalogue false fold), so those need their own copy. */
typedef struct { s32 a; s32 b; } Pair_00436070;
typedef struct { char pad[0x4E10]; Pair_00436070 pr[3]; } S_00436070;

s32 func_L01_00436070(s32 a, s32 b, u32 i) {
    s32 p = D_L01_001D67C8;
    if (p != 0 && i < 3) {
        S_00436070 *s = (S_00436070 *)(p + 0x20000);
        s->pr[i].a = a;
        s->pr[i].b = b;
        return 1;
    }
    return 0;
}
