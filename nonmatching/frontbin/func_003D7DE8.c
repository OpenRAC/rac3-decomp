/* US draft of func_003D7DE8 (rac3-uya-decomp func_003D2878, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003D7DE8 */
__asm__(".extern D_001D936C, 1");
__asm__(".extern D_001D9350, 4");
__asm__(".extern D_001D9354, 4");
__asm__(".extern D_001D9358, 4");
__asm__(".extern D_001D935C, 4");
extern s32 D_001D0A50[];
extern s32 D_001D5600, D_001D5604, D_001D5608_003D7DE8, D_001D5610_003D7DE8, D_001D5614_003D7DE8, D_001D561C_003D7DE8, D_001D5620, D_001D55F0;
extern u8 D_001D936C;
extern s32 D_001D9350, D_001D9354, D_001D9358, D_001D935C;
extern void func_003D6A40(long **, s32, s32, s32, s32, s32);
extern void func_003D72B0(u8 **, s32, s32, s32, s32, s32, s32);
extern void func_003D6EE8(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003D7850(s32, s32, s32);
extern void func_003D7878(s32, s32, s32);
extern void func_003D78A0(s32, s32, s32);
extern void func_003D78E0(long **, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_003D7DE8(void) {
    long *d = (long *)D_001D0A50;
    long *p;
    s32 lw, lh, v;
    d[0] = 0x5000000000000001UL;
    d[1] = 0xEEEEEEEEEEEEEEEEUL;
    d[2] = 0;
    d[3] = 0x3F;
    d[4] = 0xA0000000A0UL;
    d[5] = 0x19;
    d[6] = 0x100000000UL;
    d[7] = 0x4F;
    d[8] = 0x60;
    d[9] = 0x15;
    d[10] = 5;
    d[11] = 9;
    d[12] = 0x3000000000000001UL;
    d[13] = 0xEEEEEEEEEEEEEEEEUL;
    d[14] = (D_001D5614_003D7DE8 >> 13) | 0x40000;
    d[15] = 0x4D;
    d[16] = 0xFF000000FF0000UL;
    d[17] = 0x41;
    d[18] = 0x3040C;
    d[19] = 0x48;
    d[20] = 0x2400000000000001UL;
    d[21] = 1;
    d[22] = 0;
    d[23] = 0x306;
    p = d + 24;
    func_003D6A40(&p, 0xA0, 0xA0, 0x10A0, 0x10A0, 0);
    *p++ = 0x5000000000000001UL;
    *p++ = 0xEEEEEEEEEEEEEEEEUL;
    v = D_001D5600;
    if (v & (v - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lw = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lw = 0x1E - t; }
    }
    v = D_001D5604;
    if (v & (v - 1)) {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lh = 0x1F - t; }
    } else {
        { s32 t; __asm__("plzcw %0, %1" : "=r"(t) : "r"(v));
        lh = 0x1E - t; }
    }
    *p++ = ((long)D_001D5610_003D7DE8 >> 8) | (((long)D_001D5600 >> 6) << 14) | ((long)lw << 26) | ((long)lh << 30) | 0x400000000UL;
    *p++ = 7;
    *p++ = (D_001D5614_003D7DE8 >> 13) | 0x40000;
    *p++ = 0x4D;
    *p++ = 0xFF000000FF0000UL;
    *p++ = 0x41;
    *p++ = 0x3040D;
    *p++ = 0x48;
    *p++ = 0x8000000088UL;
    *p++ = 0x43;
    *p++ = 0x2400000000000001UL;
    *p++ = 1;
    *p++ = D_001D9350 | ((long)D_001D9354 << 8) | ((long)D_001D9358 << 16) | ((long)D_001D935C << 24);
    *p++ = 0x316;
    func_003D6AE0(&p, 0x98, 0x98, 0, 0, 0x1098, 0x1098, D_001D5600 << 4, D_001D5604 << 4);
    *p++ = 0x1000000000008001UL;
    *p++ = 0xEEEEEEEEEEEEEEEEUL;
    *p++ = 0;
    *p++ = 0x3F;
    *p++ = 0x1000000000000001UL;
    *p++ = 0xEEEEEEEEEEEEEEEEUL;
    *p++ = 0x30802;
    *p++ = 0x48;
    if (D_001D936C == 1) {
        func_003D7850((s32)&p, D_001D5614_003D7DE8, D_001D5620);
        func_003D7850((s32)&p, D_001D5614_003D7DE8, D_001D5620);
    }
    func_003D72B0((u8 **)&p, D_001D5614_003D7DE8, 0x100, 0x100, D_001D5620, 0x80, 0x80);
    func_003D7878((s32)&p, D_001D5620, D_001D561C_003D7DE8);
    if (D_001D936C == 1) {
        func_003D7878((s32)&p, D_001D5620, D_001D561C_003D7DE8);
    }
    func_003D72B0((u8 **)&p, D_001D561C_003D7DE8, 0x80, 0x80, D_001D5620, 0x40, 0x40);
    func_003D78A0((s32)&p, D_001D5620, D_001D561C_003D7DE8);
    func_003D78A0((s32)&p, D_001D5620, D_001D561C_003D7DE8);
    func_003D78A0((s32)&p, D_001D5620, D_001D561C_003D7DE8);
    func_003D6EE8(&p, D_001D561C_003D7DE8, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0, 0, 0);
    func_003D6EE8(&p, D_001D5608_003D7DE8, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0, 0, 0);
    func_003D78E0(&p, D_001D5620, 0x40, 0x40, 1, 6, 6, D_001D561C_003D7DE8, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0,
                  0x400, 0x400, 0x10, 0, 0x410, 0x400, 0, 0x10, 0x400, 0x410, 0x10, 0x10, 0x410, 0x410);
    func_003D78E0(&p, D_001D561C_003D7DE8, 0x40, 0x40, 1, 6, 6, D_001D5608_003D7DE8, 0x40, 0x40, 1, 0xA0, 0xA0, 0x4A0, 0x4A0, 0, 0,
                  0x400, 0x400, 0x10, 0, 0x410, 0x400, 0, 0x10, 0x400, 0x410, 0x10, 0x10, 0x410, 0x410);
    D_001D55F0 = (u8 *)p - (u8 *)d;
}
/* localdecomp:end func_003D7DE8 */
