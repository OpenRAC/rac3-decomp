#include "common.h"

/* NTSC-U counterpart of func_L03_0039C888 (src/levels/03_starship_phoenix/L03_0039C888.c) */
/* localdecomp:start func_L03_0039B188 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_00142CBE[]; __asm__(".extern D_00142CBE, 16");
extern u8 D_001426EB[]; __asm__(".extern D_001426EB, 16");
extern s32 D_001D6694_sda_0039B188; __asm__(".extern D_001D6694_sda_0039B188, 4");
extern f32 D_001DE3C0_sda[2]; __asm__(".extern D_001DE3C0_sda, 8");
extern f32 D_001DE3C8_sda[2]; __asm__(".extern D_001DE3C8_sda, 8");
extern u8 D_001A4C60[];
extern u128_t *D_L03_0021D940_0039B188[]; __asm__(".extern D_L03_0021D940_0039B188, 16");
extern void func_L03_0039B908();
extern void func_003BD360();
extern s32 func_L01_004B6C68();
extern void func_L03_0039BA28();
extern f32 func_00388800();
extern void func_L01_004576E8();
extern s32 func_00388398();
extern s32 func_0037E208();
extern s32 func_0037E1D8();
extern void func_003BE4F0();
extern void func_L01_00441FB8();
extern s32 func_L01_00453210();
extern void func_L01_00455C88();
extern void func_L03_0039BF48();
extern void func_L03_0039BD78();
extern void func_L01_00457440();
extern void func_L03_0039BC20();
extern void func_L03_0039BCB8();
extern f32 func_L01_0040C040();
extern f32 func_L01_00436500();
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_003883C8();
extern s32 func_L01_00452EC8();

typedef struct S_0039C888 S_0039C888;
typedef struct T_0039C888 T_0039C888;
struct T_0039C888 {
    u8 p0[0x120]; u8 x120[0x80]; u8 x1A0[0x174]; s32 x314; u8 p318[4]; s32 x31C; u8 p320[0x10];
    f32 x330; f32 x334; s16 x338; s16 x33A; s16 x33C; s16 x33E; s32 x340;
};
struct S_0039C888 {
    u8 p0[0x10]; u8 x10[8]; f32 x18; u8 p1C[4]; u8 x20; u8 p21[0xF]; u8 x30; u8 x31; u8 p32[2]; u16 x34;
    u8 p36[0xC]; u8 x42; u8 x43; u8 p44[0x1C]; u8 x60; u8 p61[7]; T_0039C888 *x68; u8 p6C[0x8C]; f32 xF8;
};

void func_L03_0039B188(S_0039C888 *a) {
    T_0039C888 *p;
    /* q0-q2 are copies of p that copy propagation removes again. They are kept because they change the size of
       the gcse hash table (253 -> 255 buckets), which orders the pseudos of the PRE copies and so decides
       which of them gets $s3 and which $s4. */
    T_0039C888 *q0;
    T_0039C888 *q1;
    T_0039C888 *q2;
    f32 f;
    int r;
    func_L03_0039B908(a);
    if (D_00142CBE[0] != 0) {
        func_003BD360(a);
        return;
    }
    if (D_001D6694_sda_0039B188 == 2) {
        a->x31 = 0;
        a->x34 |= 1;
        return;
    }
    if (func_L01_004B6C68() == 0) {
        a->x31 = 1;
        a->x34 &= 0xFFFE;
    }
    func_L03_0039BA28(a);
    p = a->x68;
    q0 = p;
    q1 = p;
    q2 = p;
    f = func_00388800(a->x10, D_001A4C60);
    switch (a->x20) {
    case 1:
        func_L01_004576E8(a);
        if (func_00388398(&q0->x340)) {
            q0->x340 = func_0037E208(600, 900);
            if (func_0037E1D8(2)) {
                if (a->x43 != 8) func_003BE4F0(a, 8, 0, 10);
            } else {
                if (a->x43 != 3) func_003BE4F0(a, 3, 0, 10);
            }
            func_L01_00441FB8(a, 4, -1);
        }
        if (f > 10.0f) {
            if (func_L01_00453210(D_001A4C60, q0->x31C) == 0) {
                if (f >= 18.0f) {
                    func_L03_0039BD78(a, q0);
                } else {
                    func_L03_0039BCB8(a, q0);
                }
            }
        }
        break;
    case 4:
    case 5:
        if (a->x60 & 2) {
            func_L03_0039BC20(a, p);
        }
        break;
    case 3:
        func_L01_00455C88(a, q1->x120, 0, 0);
        func_L03_0039BF48(a, q1->x120, q1);
        if (f < 6.0f || func_L01_00453210(D_001A4C60, q1->x31C) != 0) {
            func_L03_0039BC20(a, q1);
        } else if (f > 20.0f) {
            func_L03_0039BD78(a, q1);
        }
        break;
    case 2:
        func_L01_00455C88(a, q2->x120, 0, 0);
        func_L01_00457440(a, q2->x120);
        if (f < 4.0f || func_L01_00453210(D_001A4C60, q2->x31C) != 0) {
            func_L03_0039BC20(a, q2);
        } else if (f < 16.0f) {
            func_L03_0039BCB8(a, q2);
        }
        break;
    case 6: {
        u128_t *tab = D_L03_0021D940_0039B188[q2->x314];
        u128_t v = tab[q2->x338 + 1];
        func_L03_0039BF48(a, &v, q2);
        if (D_001426EB[0] == 0 && func_0037E1D8(0x2D0) == 0) {
            if (func_0037E1D8(2)) {
                if (a->x43 != 3) func_003BE4F0(a, 3, 0, 3);
            } else {
                if (a->x43 != 8) func_003BE4F0(a, 8, 0, 3);
            }
            func_L01_00441FB8(a, 10, -1);
        } else {
            f = func_L01_0040C040(a->x10, (u8 *)tab + ((q2->x338 << 4) + 0x10));
            if (f < 0.0001f) {
                u128_t *t2 = D_L03_0021D940_0039B188[q2->x314];
                u16 s = q2->x338;
                q2->x33E = s;
                q2->x338 = s + (u16)q2->x33A;
                if (q2->x338 >= *(s32 *)t2) {
                    int n = *(u16 *)t2 - 2;
                    q2->x33A = -1;
                    q2->x338 = n;
                }
                if (q2->x338 < 0) {
                    q2->x338 = 1;
                    q2->x33A = 1;
                }
                if (q2->x33E < 2) {
                    if (func_0037E1D8(4) == 0) {
                        q2->x330 = a->x18;
                        q2->x334 = 0;
                        if (a->x43 != 4) func_003BE4F0(a, 4, 0, 3);
                        func_L01_00441FB8(a, 7, -1);
                    }
                }
            }
        }
        break;
    }
    case 7:
        if (a->x42 == 4 && func_L01_00436500(a) > 8.0f) {
            int i = p->x33E;
            p->x334 += (D_001DE3C0_sda[i] - p->x334) * 0.15f;
            a->xF8 = func_00389380(a->xF8, func_003893C8(D_001DE3C8_sda[i], a->xF8) * 0.1f);
            a->x18 = p->x330 + p->x334;
        }
        if (a->x60 & 2) {
            p->x33C = func_0037E208(60, 120);
            if (a->x43 != 5) func_003BE4F0(a, 5, 0, 3);
            func_L01_00441FB8(a, 8, -1);
        }
        break;
    case 8:
        if (func_003883C8(&p->x33C)) {
            if (a->x43 != 6) func_003BE4F0(a, 6, 0, 3);
            func_L01_00441FB8(a, 9, -1);
        }
        break;
    case 9:
        if (a->x42 == 6 && func_L01_00436500(a) > 1.0f) {
            p->x334 = p->x334 * 0.8f;
            a->x18 = p->x330 + p->x334;
        }
        if (a->x60 & 2) {
            if (a->x43 != 1) func_003BE4F0(a, 1, 0, 3);
            func_L01_00441FB8(a, 6, -1);
        }
        break;
    case 10:
    case 11:
        if (a->x60 & 2) {
            if (a->x43 != 1) func_003BE4F0(a, 1, 0, 3);
            func_L01_00441FB8(a, 6, -1);
        }
        break;
    case 12:
        if (func_L01_00452EC8(a)) {
            p->x340 = func_0037E208(0x1C2, 0x384);
        }
        if (func_00388398(&p->x340)) {
            if (a->x43 != 9) func_003BE4F0(a, 9, 0, 15);
            func_L01_00441FB8(a, 13, -1);
        }
        break;
    case 13:
        if (a->x60 & 2) {
            if (a->x43 != 7) func_003BE4F0(a, 7, 0, 15);
            func_L01_00441FB8(a, 12, -1);
        }
        break;
    }
    func_L03_00438870(a, p->x1A0, 2, 4, a->x20 == 1 || a->x20 == 12);
}
/* localdecomp:end func_L03_0039B188 */
