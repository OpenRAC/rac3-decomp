/* US draft of func_003A6C90 (rac3-uya-decomp func_003A6B18, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: unmapped symbols: func_003A4548 func_003A7DB0 func_003A82F8 func_003E5950. */


/* localdecomp:start func_003A6C90 */
/* VU0 j-form: each VU0 instruction is a separate non-volatile __asm__
   using the "j" (VU0 register) constraint, which needs -mvu0-use-vf0-vf2 (on every line of
   tools/text_parts.txt). With -mvu0-use-vf0-vf31 loop.c hoists and strength-reduces differently
   (234 diffs). Uses one plain-C volatile read of D.f34. See Matching-Patterns,
   "VU0 j-form". */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A1438;
typedef struct {
    u8 pad[0x10]; V4_3A1438 f10; u8 pad20[0x40 - 0x20]; u8 f40; u8 f41; u8 pad42[2]; f32 f44;
    u8 pad48[0x61 - 0x48]; u8 f61; u8 pad62; u8 f63; u8 pad64[4]; u8 *f68; u8 pad6C[0xAA - 0x6C]; s16 fAA;
} O_3A1438;
typedef struct { u8 pad[0x20]; u8 f20; u8 pad21[0x34 - 0x21]; u16 f34; u8 pad36[0xAA - 0x36]; s16 fAA; u8 padAC[0x100 - 0xAC]; } E_3A1438;
typedef struct {
    u8 pad[0x34]; s32 f34; s32 f38; s32 f3C; s16 f40; u8 pad42[2]; s16 f44; u8 pad46[2]; s16 f48;
    u8 pad4A[0x60 - 0x4A]; s8 f60; u8 pad61[0x1A0 - 0x61]; O_3A1438 *f1A0[1];
} S_225780_3A1438;
typedef struct { u8 pad[0x1A0]; unsigned long f1A0; } Pad_3A1438;
typedef struct { u8 pad[0x25C0]; O_3A1438 *f25C0; } S_1A4BE0_3A1438;
extern S_225780_3A1438 D_00225700_003A6C90;
extern S_1A4BE0_3A1438 D_001A4BE0_003A6C90;
extern f32 D_001D9BD0_003A6C90;
extern s32 D_001D5B90_003A6C90;
extern Pad_3A1438 *D_001D52FC_003A6C90;
extern s32 D_00142690_003A6C90[];
extern s32 D_001D4D40_003A6C90;
extern s32 D_001D545C_003A6C90;
extern s32 D_00143950_003A6C90[];
extern s16 D_001CCFD4_003A6C90[];
extern O_3A1438 *D_001DA008;
extern s32 D_001D4B60_003A6C90;
extern E_3A1438 *D_001DA49C_003A6C90;
extern E_3A1438 *D_001DA4A4_003A6C90;
extern void func_003E58D8(void);
extern void func_003A82F8(void);
extern s32 func_003A1B98(void);
extern s32 func_003E5950(void);
extern void func_003C2D68_003A6C90(O_3A1438 *);
extern void func_0038D200_003A6C90(void *, void *, f32);
extern void func_003A5CC0(O_3A1438 *, s32);
extern void func_003A7DB0();
extern void func_0038A2F8_003A6C90(void (*)(), O_3A1438 *);
extern void func_003C7FF0_003A6C90(O_3A1438 *);
extern void func_00381C78(O_3A1438 *, s32);
extern void func_00381BA0(O_3A1438 *);
extern s32 func_00381BC0_003A6C90(void);
extern void func_003D0ED8(void);
extern void func_003A70C8(void);
extern s32 func_003A6C08(s32);
extern s32 func_003A2B50(s32);
extern void func_003E5970(void);
s32 func_003A6C90(void) {
    s32 r;
    s32 over;
    f32 f;
    if (D_00225700_003A6C90.f60 != 0) return 0;
    if (!(D_00225700_003A6C90.f34 + 1 < D_00225700_003A6C90.f40)) {
        D_001D5B90_003A6C90 = 0;
        D_00225700_003A6C90.f60 = 1;
        return 0;
    }
    func_003E58D8();
    func_003A82F8();
    f = D_001D9BD0_003A6C90 - 0.34f;
    D_00225700_003A6C90.f38++;
    D_00225700_003A6C90.f34++;
    D_001D9BD0_003A6C90 = f;
    if (f < 0.0f) D_001D9BD0_003A6C90 = 0.0f;
    if (!(*(volatile s32 *)&D_00225700_003A6C90.f34 < D_00225700_003A6C90.f48)) func_003A1B98();
    r = 0;
    over = !(D_00225700_003A6C90.f34 < D_00225700_003A6C90.f40);
    if (D_00225700_003A6C90.f34 >= 0x12 && D_001D9BD0_003A6C90 == 0.0f) {
        if (((D_00142690_003A6C90[0] & 0xFFFF0000) != 0 || D_001D4D40_003A6C90 != 0 || D_001D545C_003A6C90 <= 0)
            && (((s32 *)D_001D52FC_003A6C90)[0x1A4 / 4] & 0x800)) {
            r = 1;
        } else {
            r = 1;
            if ((D_001D52FC_003A6C90->f1A0 & 0x8000000000FUL) ^ 0x8000000000FUL) r = 0;
        }
    }
    if (r != 0 || over) {
        D_00225700_003A6C90.f60 = 1;
        D_001D5B90_003A6C90 = 0;
    } else {
        s32 i;
        s32 v;
        s32 lim = D_00143950_003A6C90[0] ? 0x50 : 0x60;
        if (D_00225700_003A6C90.f38 >= lim) {
            D_00225700_003A6C90.f3C++;
            if (D_001CCFD4_003A6C90[0] != 0) func_003A2B50(1);
            func_003A70C8();
            func_003A6C08(D_00225700_003A6C90.f3C + 1);
        }
        v = func_003E5950();
        for (i = 0; i < D_00225700_003A6C90.f44; i++) {
            O_3A1438 *o = D_00225700_003A6C90.f1A0[i];
            s32 h = D_00225700_003A6C90.f38 >> 1;
            u8 *p;
            V4_3A1438 a, b;
            o->f41 = h + 1;
            o->f40 = h;
            func_003C2D68_003A6C90(o);
            o->f44 = (f32)(D_00225700_003A6C90.f38 & 1) * 0.5f;
            if (v != 0 && (D_00225700_003A6C90.f38 & 1)) o->f44 = 1.0f;
            p = o->f68;
            func_0038D200_003A6C90(&a, p + o->f40 * 16, 1.0f - o->f44);
            func_0038D200_003A6C90(&b, p + o->f41 * 16, o->f44);
            {
                u128_t x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(o->f10) : "j"(x));
            }
            {
                s32 aa = o->fAA;
                if (aa == 0xD54) {
                    o->f63 = 8;
                    func_003A5CC0(o, 0);
                    if (D_001DA008 == 0 || D_001DA008->fAA == aa) func_0038A2F8_003A6C90(func_003A7DB0, o);
                }
            }
            o->f61 = 0xFF;
            func_003C7FF0_003A6C90(o);
            if (o->fAA == 0) {
                D_001A4BE0_003A6C90.f25C0 = o;
                func_00381C78(o, 1);
            }
            if (o->fAA == 10) func_00381BA0(o);
        }
        if (D_001D4B60_003A6C90 == 4 || func_00381BC0_003A6C90() > 0) {
            E_3A1438 *e;
            for (e = D_001DA49C_003A6C90; e < D_001DA4A4_003A6C90; e++) {
                if (e->f20 < 0xFE && e->fAA == 0x50A) e->f34 |= 1;
            }
        }
    }
    func_003A4548();
    func_003D0ED8();
    func_003E5970();
    return r;
}
/* localdecomp:end func_003A6C90 */
