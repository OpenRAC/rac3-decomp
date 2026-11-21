/* functional: high. Plain MIPS (flagged handwritten by the splitter, no VU/scratchpad); store order and register use differ from retail, same stores and values. */
extern s32 D_001E0EE4_sda;
extern u8 *D_0023C500[];

void func_L01_004B7FE8(u32 *p, u32 a, u32 b, u32 c) {
    u8 *obj = (u8 *)p;
    u32 base;
    u8 *tbl;
    u32 ent;
    u8 *tab34;
    u32 val;
    u16 *q;
    s32 n;
    u32 dst;
    u32 h14;

    a >>= 2;
    b >>= 2;
    c >>= 2;
    p[0] = (p[0] & ~0x3F) | a;
    p[1] = (p[1] & ~0x3F) | b;
    obj[0x1E] |= 2;
    p[2] = (p[2] & ~0x3F) | c;
    h14 = *(u16 *)(obj + 0x14);
    if (h14 == 0xFFFF) {
        return;
    }
    base = D_001E0EE4_sda + (h14 << 4);
    tbl = D_0023C500[obj[0x1D]];
    val = (a << 2) | (b << 10) | (c << 18) | 0x80000000;
    tab34 = *(u8 **)(tbl + 0x34);
    ent = *(u16 *)(tbl + (obj[0x1F] << 1) + 0x78);
    if (ent == 0) {
        return;
    }
    q = (u16 *)(ent + (u32)tab34);
    n = *q++;
    dst = *q++;
    do {
        dst += base;
        n--;
        *(u32 *)dst = val;
        dst = *q++;
    } while (n > 0);
}
