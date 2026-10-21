/* US draft of func_003C33C8 (rac3-uya-decomp func_003BDEA8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C33C8 */
typedef struct { u8 pB_[0xB]; u8 bB; u8 pC[0x14]; s32 f20; } T_3BDEA8;
typedef struct { u8 p0[0x24]; T_3BDEA8 *f24; } O_3BDEA8;
extern u8 *D_001DA530;
extern u8 D_002FC1A0[];
extern u8 D_00380120[];
extern u8 D_001D7830[];
extern void func_0038CD28();
void func_003C33C8(void) {
    u32 *pkt;
    u8 *e;
    if (D_001DA530 == D_002FC1A0) return;
    pkt = (u32 *)D_001DA050_003C30C0;
    D_001DA050_003C30C0 = (int)(pkt + 4);
    for (e = D_002FC1A0; e < D_001DA530; e += 8) {
        u32 *a = *(u32 **)e;
        u32 b = *(u32 *)(e + 4);
        O_3BDEA8 *o;
        T_3BDEA8 *t;
        s32 lo, hi, idx;
        s32 base;
        s32 j;
        a[0] = 0x20000000;
        idx = b & 0xF;
        o = (O_3BDEA8 *)(b & ~0xF);
        a[1] = D_001DA050_003C30C0;
        a[3] = 0x11000000;
        t = o->f24;
        hi = t->bB >> 4;
        lo = t->bB & 0xF;
        base = t->f20 - ((lo * hi) << 10) - 0x10;
        for (j = 0; j < hi; j++) {
            s16 h = ((s16 *)base)[j];
            func_0038CD28(D_001DA050_003C30C0, D_00380120, 0x70);
            ((s16 *)D_001DA050_003C30C0)[0x12] = h;
            ((u32 *)D_001DA050_003C30C0)[0x19] = base + (idx << 10) + 0x10 + ((j * lo) << 10);
            D_001DA050_003C30C0 = D_001DA050_003C30C0 + 0x70;
        }
        ((u32 *)D_001DA050_003C30C0)[0] = 0x30000003;
        ((u32 *)D_001DA050_003C30C0)[1] = (u32)D_001D7830;
        ((u32 *)D_001DA050_003C30C0)[2] = 0;
        ((u32 *)D_001DA050_003C30C0)[3] = 0x50000003;
        D_001DA050_003C30C0 = D_001DA050_003C30C0 + 0x10;
        ((u32 *)D_001DA050_003C30C0)[0] = 0x20000000;
        ((u32 *)D_001DA050_003C30C0)[1] = (u32)(a + 4);
        ((u32 *)D_001DA050_003C30C0)[2] = 0;
        ((u32 *)D_001DA050_003C30C0)[3] = 0;
        D_001DA050_003C30C0 = D_001DA050_003C30C0 + 0x10;
    }
    pkt[0] = 0x20000000;
    pkt[1] = D_001DA050_003C30C0;
    pkt[2] = 0;
    pkt[3] = 0;
}
/* localdecomp:end func_003C33C8 */
