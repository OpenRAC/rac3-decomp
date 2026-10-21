/* US draft of func_003BC7C0 (rac3-uya-decomp func_003BC6E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BC7C0 */
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x90]; s32 tbl[1]; } B_3B6F28;
extern B_3B6F28 *D_00227598_003BC7C0[];
typedef struct { s32 a[1]; } A_3B6F28;
extern s32 D_001DA218_003BC7C0[2];
extern s32 D_001DA240_003BC7C0[2];
extern s32 D_001DA1F0_003BC7C0[2];
typedef struct { u8 pad[0xA4]; u32 fA4; } S_1A30B0_3B6F28;
extern S_1A30B0_3B6F28 D_001A30B0;
extern void func_003BBB80();
extern void func_11F0A0();
extern void func_13BED0();
void func_003BC7C0(s32 n, s32 *list) {
    s32 local[12];
    B_3B6F28 *base;
    u8 *e;
    s32 i;
    s32 *pa, *pb;
    s32 *idx;
    s32 *lp;
    s32 m;
    m = -1;
    base = D_00227598_003BC7C0[0];
    e = (u8 *)base + base->f8;
    idx = D_001DA218_003BC7C0;
    pb = D_001DA240_003BC7C0;
    pa = idx;
    for (i = 9; i >= 0; i--) {
        *pa++ = m;
        *pb++ = m;
    }
    if (list == 0) {
        for (i = 0; i < n; i++) local[i] = i;
        list = local;
    }
    D_001A30B0.fA4 = 0xFFFFFFFFU;
    if (n > 0) {
        u8 *e18 = e + 0x18;
        A_3B6F28 *t = (A_3B6F28 *)base->tbl;
        s32 c = 0xC000;
        lp = list;
        i = n;
        do {
            u8 *q = e18 + t->a[*lp++];
            *(s32 *)(q + 0x2C) = c;
            *(s32 *)(q + 0x28) = c;
        } while (--i);
    }
    func_11F0A0(0);
    for (i = 0; i < n; i++) {
        s32 k = list[i];
        idx[k] = i;
        func_003BBB80(e + base->tbl[k], &D_001DA1F0_003BC7C0[i]);
    }
    func_13BED0();
}
/* localdecomp:end func_003BC7C0 */
