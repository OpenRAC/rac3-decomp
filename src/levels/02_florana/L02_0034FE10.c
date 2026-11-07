#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_0034FE10);

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

INCLUDE_ASM("asm/levels", func_L02_003514D0);
