#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_003A6C90 (src/boot_elf/text/3A6C90.c): the minimum count 15 -> 18 (60 Hz) */
/* localdecomp:start func_U_003A6B18 */
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
extern S_225780_3A1438 D_U_00225780;
extern S_1A4BE0_3A1438 D_001A4BE0;
extern f32 D_U_001D9C50[1];
extern s32 D_U_001D5B90;
extern Pad_3A1438 *D_001D52FC;
extern s32 D_00142690[];
extern s32 D_001D4D40;
extern s32 D_001D545C;
extern s32 D_00143950[];
extern s16 D_001CCFD4[];
extern O_3A1438 *D_U_001DA088;
extern s32 D_001D4B60;
extern E_3A1438 *D_U_001DA51C;
extern E_3A1438 *D_U_001DA524;
extern void func_U_003A82F8(void);
extern s32 func_U_003E5950(void);
extern void func_U_003A7DB0();
extern s32 func_U_003A4548(void);
extern void func_U_003E5790(void);
extern s32 func_U_003A1A58(void);
extern void func_U_003C2C50(O_3A1438 *);
extern void func_U_0038D148(void *, void *, f32);
extern void func_U_003A5B80(O_3A1438 *, s32);
extern void func_U_0038A2A0(void (*)(), O_3A1438 *);
extern void func_U_003C7E88(O_3A1438 *);
extern void func_U_00381CA0(O_3A1438 *, s32);
extern void func_U_00381BC8(O_3A1438 *);
extern s32 func_U_00381BE8(void);
extern void func_U_003D0D70(void);
extern void func_U_003A6F50(void);
extern s32 func_U_003A6A90(s32);
extern s32 func_U_003A2A10(s32);
extern void func_U_003E5828(void);
s32 func_U_003A6B18(void) {
    s32 r;
    s32 over;
    f32 f;
    if (D_U_00225780.f60 != 0) return 0;
    if (!(D_U_00225780.f34 + 1 < D_U_00225780.f40)) {
        D_U_001D5B90 = 0;
        D_U_00225780.f60 = 1;
        return 0;
    }
    func_U_003E5790();
    func_U_003A82F8();
    f = D_U_001D9C50[0] - 0.34f;
    D_U_00225780.f38++;
    D_U_00225780.f34++;
    D_U_001D9C50[0] = f;
    if (f < 0.0f) D_U_001D9C50[0] = 0.0f;
    if (!(D_U_00225780.f34 < D_U_00225780.f48)) func_U_003A1A58();
    r = 0;
    over = !(D_U_00225780.f34 < D_U_00225780.f40);
    if (D_U_00225780.f34 >= 18 && D_U_001D9C50[0] == 0.0f) {
        if (((D_00142690[0] & 0xFFFF0000) != 0 || D_001D4D40 != 0 || D_001D545C <= 0)
            && (((long)D_001D52FC->f1A0 >> 32) & 0x800)) {
            r = 1;
        } else if ((D_001D52FC->f1A0 & 0x8000000000FUL) == 0x8000000000FUL) {
            r = 1;
        }
    }
    if (r != 0 || over) {
        D_U_00225780.f60 = 1;
        D_U_001D5B90 = 0;
    } else {
        s32 i;
        s32 v;
        s32 lim = D_00143950[0] ? 0x50 : 0x60;
        if (D_U_00225780.f38 >= lim) {
            D_U_00225780.f3C++;
            if (D_001CCFD4[0] != 0) func_U_003A2A10(1);
            func_U_003A6F50();
            func_U_003A6A90(D_U_00225780.f3C + 1);
        }
        v = func_U_003E5950();
        for (i = 0; i < D_U_00225780.f44; i++) {
            O_3A1438 *o = D_U_00225780.f1A0[i];
            s32 h = D_U_00225780.f38 >> 1;
            u8 *p;
            V4_3A1438 a, b;
            o->f41 = h + 1;
            o->f40 = h;
            func_U_003C2C50(o);
            o->f44 = (f32)(D_U_00225780.f38 & 1) * 0.5f;
            if (v != 0 && (D_U_00225780.f38 & 1)) o->f44 = 1.0f;
            p = o->f68;
            func_U_0038D148(&a, p + o->f40 * 16, 1.0f - o->f44);
            func_U_0038D148(&b, p + o->f41 * 16, o->f44);
            {
                vu0_q x, y;
                __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
                __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b));
                __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
                __asm__("sqc2 %1, %0" : "=m"(o->f10) : "j"(x));
            }
            {
                s32 aa = o->fAA;
                if (aa == 0xD54) {
                    o->f63 = 8;
                    func_U_003A5B80(o, 0);
                    if (D_U_001DA088 == 0 || D_U_001DA088->fAA == aa) func_U_0038A2A0(func_U_003A7DB0, o);
                }
            }
            o->f61 = 0xFF;
            func_U_003C7E88(o);
            if (o->fAA == 0) {
                D_001A4BE0.f25C0 = o;
                func_U_00381CA0(o, 1);
            }
            if (o->fAA == 10) func_U_00381BC8(o);
        }
        if (D_001D4B60 == 4 || func_U_00381BE8() > 0) {
            E_3A1438 *e;
            for (e = D_U_001DA51C; e < D_U_001DA524; e++) {
                if (e->f20 < 0xFE && e->fAA == 0x50A) e->f34 |= 1;
            }
        }
    }
    func_U_003A4548();
    func_U_003D0D70();
    func_U_003E5828();
    return r;
}
/* localdecomp:end func_U_003A6B18 */
