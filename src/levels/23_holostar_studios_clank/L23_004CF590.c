#include "common.h"

typedef struct {
    u8 p0[0x34];
    u16 h34;
    u8 p36[0x66];
    s32 w9C;
} M_004CF590;
typedef struct {
    u8 p0[0x1A0];
    s32 w1A0;
} P_004CF590;
typedef struct {
    u8 p0[0xBF4];
    M_004CF590 *wBF4;
    M_004CF590 *wBF8;
    u8 pBFC[4];
    f32 fC00;
    f32 fC04;
    u8 pC08[0xAC4];
    f32 f16CC;
    u8 p16D0[0x380];
    s32 w1A50;
    u8 p1A54[4];
    s32 w1A58;
    u8 p1A5C[0x28];
    s32 w1A84;
    u8 p1A88[0x108];
    u8 a1B90[0x150];
    u8 a1CE0[0x8E0];
    M_004CF590 *w25C0;
    u8 p25C4[0x20];
    u8 b25E4;
    u8 p25E5;
    u8 b25E6;
    u8 p25E7[0x269];
    s32 w2850;
    s32 w2854;
    u16 h2858;
} G_004CF590;

/* localdecomp:start func_L23_004CF590 */
/* Ps2EeAs only uses $gp for this if it knows the size before the use. */
__asm__(".extern D_001DBD18, 4");
extern G_004CF590 D_001A4BE0;
extern P_004CF590 *D_001D52FC;
extern s32 D_001D545C;
extern s32 D_001D4BA0;
extern f32 D_001DBD18;
extern void func_00394F48();
extern void func_00394F90();
extern void func_00395478();
extern void func_00393348(s32, s32, void *, void *, void *, s32, s32);
extern void func_L01_0041C828(s32);
extern void func_L01_00425FE0(s32);
extern void func_L01_0044E740(void *);
extern void func_L01_004436F4(void *);
extern void func_L01_004E04E8(void);
extern void func_L01_004E1560(void);
extern void func_L01_004E2ED0(void);
extern void func_L01_004EAA80(void);
extern void func_L01_004ED188(void);
extern void func_L01_0050FDD8(s32, s32);
extern void func_L01_0050FED0(void);
extern void func_L01_005108C0(s32);
extern void func_L23_004CF810(s32);
extern void func_L23_004D0308(s32);
extern void func_L23_004E3428(s32, s32);

void func_L23_004CF590(s32 a0, s32 a1, M_004CF590 *a2) {
    G_004CF590 *s0 = &D_001A4BE0;

    if (s0->b25E4 != a0) {
        if (s0->b25E4 != 0) {
            func_L23_004CF810(0);
        }
        a2->h34 &= 0xFFBE;
        func_L01_004EAA80();
        s0->b25E6 = 1;
        func_L01_004ED188();
        s0->w25C0 = s0->wBF8;
        func_L01_0044E740(s0->a1B90);
        func_L01_0044E740(s0->a1CE0);
        s0->w25C0->w9C = -1;
        func_L01_005108C0(1);
        func_L01_004E1560();
        func_L01_004E04E8();
        s0->b25E4 = a0;
        s0->wBF4 = a2;
        s0->w25C0 = a2;
        if (s0->b25E4 == 2) {
            s0->f16CC = D_001DBD18;
        }
        if (s0->b25E4 == 1) {
            s0->f16CC = 1.1f;
            if (D_001D52FC->w1A0 & 0x10) {
                func_00393348(0x23, 0, func_00394F48, func_00394F90, func_00395478, 0, 0);
                func_L01_0041C828(3);
            }
        }
        func_L23_004D0308(1);
        {
            G_004CF590 *s1 = &D_001A4BE0;

            s1->w25C0->h34 |= 6;
            s1->fC00 = 1.0f;
            s1->fC04 = 1.0f;
            func_L01_0050FED0();
            func_L01_004436F4(s1->w25C0);
            func_L01_004E2ED0();
            switch (a0) {
            case 1:
                s1->h2858 = *(u16 *)&s1->w2850;
                s1->w2850 = s1->w2854;
                if (s1->w2854 >= 5) {
                    s1->w2850 = 4;
                }
                s1->w1A50 = 0;
                s1->w1A58 = 0;
                if (D_001D545C == 0x17 && D_001D4BA0 != a0) {
                    func_L01_00425FE0(1);
                }
                func_L01_0050FDD8(0x14, 0);
                break;
            case 2:
                s1->w1A84 = 0x5DC;
                break;
            case 3:
                break;
            }
            func_L23_004E3428(a1, 2);
        }
    }
}
/* localdecomp:end func_L23_004CF590 */
