/* func_L01_00436070: MATCH with @ps2as (check.py --as ps2as) at the 34 places in levels 1-36: the plain scalar
   `extern char *D_L01_001D67C8;` becomes Ps2EeAs's lui/lw macro with one register ($a3), as retail. Both other C
   blocks of L01_00435FC8.c (func_L01_00435FC8, func_L01_00435FF0) also MATCH under @ps2as, so the file could simply
   get @ps2as. Not matched because of a false fold: in levels 39-53 the pair is at 0x24DE0/0x24DE4 instead of
   0x24E10/0x24E14 (2 diff there; the catalogue masks the lui/offset constant as an address pair), like
   func_L01_004D2470. With the file's default assembler: 18 diff (7 with an unsized-array alias). */
extern char *D_L01_001D67C8;
typedef struct { s32 a; s32 b; } Pair_00436070;
typedef struct { char pad[0x4E10]; Pair_00436070 pr[3]; } S_00436070;

s32 func_L01_00436070(s32 a, s32 b, u32 i) {
    S_00436070 *s;
    char *p = D_L01_001D67C8;
    if (p != 0 && i < 3) {
        s = (S_00436070 *)(p + 0x20000);
        s->pr[i].a = a;
        s->pr[i].b = b;
        return 1;
    }
    return 0;
}
