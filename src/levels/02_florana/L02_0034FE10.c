#include "common.h"

/* localdecomp:start func_L02_0034FE10 */
typedef struct { u8 p0[0x34]; u16 h34; u8 p36[0x62]; s32 f98; u8 p9C[0xE]; s16 hAA; } R_34FE10;
typedef struct { u8 p0[0x92C]; s32 f92C; s32 f930; } P_34FE10;
typedef struct { u8 p0[0x68]; P_34FE10 *f68; } A_34FE10;
extern s16 *D_0021B460[];
extern u8 *D_001DE99C;
__asm__(".extern D_001DE99C, 16");
extern s32 D_001DE9D8_sda;
__asm__(".extern D_001DE9D8_sda, 4");
extern s32 D_001DE9D8;
__asm__(".extern D_001DE9D8, 16");
void func_L01_004AA7E8(void *, s32);

void func_L02_0034FE10(A_34FE10 *a0) {
    P_34FE10 *p = a0->f68;
    s16 *q;
    if (p->f92C == 0xFF) return;
    {
        q = D_0021B460[p->f92C];
        while ((p->f92C & 0xFF) != 0xFF && p->f92C <= D_001DE9D8_sda && q != 0 && (q[-1] >= 0 || q == D_0021B460[p->f92C])) {
            R_34FE10 *r = (R_34FE10 *)(D_001DE99C + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) break;
            if (r->hAA == 0x16AD || r->hAA == 0x19DB) {
                r->f98 = 0;
                r->h34 = (r->h34 | 0x41) & 0xEFFF;
                func_L01_004AA7E8(r, 1);
                r->h34 |= 2;
            }
            q++;
        }
    }
    if (p->f930 != 0xFF) {
        q = D_0021B460[p->f930];
        while ((p->f930 & 0xFF) != 0xFF && p->f930 <= D_001DE9D8 && q != 0 && (q[-1] >= 0 || q == D_0021B460[p->f930])) {
            R_34FE10 *r = (R_34FE10 *)(D_001DE99C + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) return;
            if (r->hAA == 0x16AD || r->hAA == 0x19DB) {
                r->f98 = 0;
                r->h34 = (r->h34 | 0x41) & 0xEFFF;
                func_L01_004AA7E8(r, 1);
                r->h34 |= 2;
            }
            q++;
        }
    }
}
/* localdecomp:end func_L02_0034FE10 */

/* localdecomp:start func_L02_00350030 */
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0x30]; u16 h44; } O_350030;
typedef struct { u8 p0[0x24]; O_350030 *f24; u8 p28[0xC]; u16 h34; u8 p36[0x62]; s32 f98; u8 p9C[0xE]; s16 hAA; } R_350030;
typedef struct { u8 p0[0x92C]; s32 f92C; s32 f930; } P_350030;
typedef struct { u8 p0[0x68]; P_350030 *f68; } A_350030;
extern s16 *D_0021B460[];
extern u8 *D_001DE99C;
__asm__(".extern D_001DE99C, 16");
extern s32 D_001DE9D8_sda;
__asm__(".extern D_001DE9D8_sda, 4");

void func_L02_00350030(A_350030 *a0, s32 a1) {
    P_350030 *p = a0->f68;
    s16 *q;
    if (a1 == 1) {
        if (p->f92C == 0xFF) return;
        q = D_0021B460[p->f92C];
        while ((p->f92C & 0xFF) != 0xFF && p->f92C <= D_001DE9D8_sda && q != 0 && (q[-1] >= 0 || q == D_0021B460[p->f92C])) {
            R_350030 *r = (R_350030 *)(D_001DE99C + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) return;
            if (r->hAA == 0x16AD || r->hAA == 0x19DB) {
                O_350030 *o = r->f24;
                r->h34 &= 0xFFBE;
                r->h34 |= o->h44 & 0x1000;
                r->f98 = o->f10;
                r->h34 &= 0xFFFD;
            }
            q++;
        }
    } else {
        if (p->f930 == 0xFF) return;
        q = D_0021B460[p->f930];
        while ((p->f930 & 0xFF) != 0xFF && p->f930 <= D_001DE9D8_sda && q != 0 && (q[-1] >= 0 || q == D_0021B460[p->f930])) {
            R_350030 *r = (R_350030 *)(D_001DE99C + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) return;
            if (r->hAA == 0x16AD || r->hAA == 0x19DB) {
                O_350030 *o = r->f24;
                r->h34 &= 0xFFBE;
                r->h34 |= o->h44 & 0x1000;
                r->f98 = o->f10;
                r->h34 &= 0xFFFD;
            }
            q++;
        }
    }
}
/* localdecomp:end func_L02_00350030 */

INCLUDE_ASM("asm/levels", func_L02_00350200);

/* localdecomp:start func_L02_00350398 */
s32 func_00382468(s32);
void func_003C3A10(void *, s32, s32, s32);

void func_L02_00350398(void *arg0) {
    s32 temp_s0_2;
    s32 temp_s1;
    u8 temp_s0;
    u8 temp_s0_3;

    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        temp_s0 = *(u8 *)((u8 *)arg0 + 0x43);
        if (temp_s0 != func_00382468(4)) {
            temp_s1 = func_00382468(4);
            temp_s0_2 = func_00382468(2);
            func_003C3A10(arg0, temp_s1, temp_s0_2, func_00382468(0xA));
        }
        *(u8 *)((u8 *)arg0 + 0x20) = 1U;
    }
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 1) {
        if ((*(u8 *)((u8 *)arg0 + 0x60)) & 2) {
            temp_s0_3 = *(u8 *)((u8 *)arg0 + 0x43);
            if (temp_s0_3 != func_00382468(4)) {
                func_003C3A10(arg0, func_00382468(4), 0, 0x11);
            }
        }
    }
}
/* localdecomp:end func_L02_00350398 */

INCLUDE_ASM("asm/levels", func_L02_00350478);

INCLUDE_ASM("asm/levels", func_L02_00351208);

/* localdecomp:start func_L02_003514D0 */
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L02_003514D0(u8 *a0)
{
    u8 *p;
    f32 zero = 0.0f;

    *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) - zero;
    *(u32 *)(a0 + 0x98) = 0;
    *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
    p = *(u8 **)(a0 + 0x68);
    func_L01_004AA7E8(a0, 1);
    *(f32 *)(p + 0x190) = 0.5f;
    p[0x1A8] = 3;
    p[0x170] = 0xB;
    *(f32 *)(p + 0x194) = 0.5f;
    p[0x1D8] = 1;
    p[0x1D9] = 1;
    p[0x171] = 3;
    *(f32 *)(p + 0x19C) = 0.15f;
    p[0x1DB] = 0x1C;
    p[0x1DA] = 0;
    p[0x176] = 0x10;
    *(f32 *)(p + 0x70) = 0.7f;
    *(f32 *)(p + 0x74) = 3.0f;
    *(f32 *)(p + 0x9C) = zero;
    *(f32 *)(p + 0x78) = 1.0f;
    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x80) = 1.5707964f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    p[0x172] = 3;
    func_L01_0045BD78(a0, 0.0024f, 0.040000003f, 0.0025132743f, 0.041887905f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 5;
        *(f32 *)(p + 0x30) = 5.0f;
    }
    p[0x39] = 1;
    *(f32 *)(p + 0x40) = 2.0f;
    p[0x3F] = 0;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 1.5f;
    p[0x3E] = 1;
    func_L01_004450F0(a0, 1, 0);
    if (a0[0x43] != 0xE) {
        func_003C3A10(a0, 0xE, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L02_003514D0 */
