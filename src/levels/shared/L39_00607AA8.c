#include "common.h"

/* localdecomp:start func_L39_00607AA8 */
typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } G_00607AA8;
typedef struct { u8 p0[8]; s32 f8; } P_00607AA8;
extern G_00607AA8 *D_L39_00241164;
__asm__(".extern D_L39_00241164, 16");
/* counter written by the handwritten interrupt handler func_L39_00608DB0 */
extern volatile s32 D_L39_0024CC24;
__asm__(".extern D_L39_0024CC24, 16");
extern s32 D_L39_0024CC0C;
__asm__(".extern D_L39_0024CC0C, 16");
extern void *D_L39_0024CC10;
__asm__(".extern D_L39_0024CC10, 16");
extern s32 D_L39_00240468_sda;
extern void *D_L39_0024CC10_sda;
extern s32 D_L39_0024CBE0_sda;
extern void func_L39_005C42A0(void);
extern void func_L39_00608180(void *);
extern void func_L39_0060A670(s32);
extern s32 func_L39_00609378(char *, s32 *);
extern s32 func_L39_00609490(s32 *, s32, s32);
extern void func_L39_006093A8(char *, s32);
extern void func_L39_00607DD8(void);
extern s32 func_L39_006093E8(char *, s32 *);
extern s32 func_001470F0(s32, s32, s32, char *, s32);
extern void func_L39_00609428(char *, s32);
extern void func_L39_00608098(void);
extern s32 func_L39_0060ACB8(s32);
extern s32 func_L39_00607DF8(void);
extern void func_L39_00608FE0(s32);
extern s32 func_L39_0060A680(s32);
extern s32 func_L39_0060A700(s32);
extern s32 func_L39_0060A7D0(s32);
extern void func_L39_00609030(void);
extern void func_L39_00608220(void *);

s32 func_L39_00607AA8(s32 a0, char *a1, s32 *a2) {
    s32 o0;
    s32 o1;
    s32 ret;
    P_00607AA8 *p;
    s32 done = 0;
    s32 armed = 0;
    s32 started = 0;
    s32 left;
    s32 left2;
    s32 avail;
    s32 n;
    s32 k;

    ret = 0;
    p = (P_00607AA8 *)(a1 + 0x50000);
    left = *a2;
    left2 = left;
    D_L39_0024CC24 = 0;
    while (left >= 5 && func_L39_0060A680(a0) != 3) {
        s32 hit = 0;
        func_L39_005C42A0();
        if (D_L39_00241164->f1A0 == 0 && done != 0 && started != 0) {
            armed = 1;
        }
        if (armed && !(D_L39_00240468_sda & 0x80)) {
            s32 t = D_L39_00240468_sda & ~0xC0;
            if (t != 2) {
                if (t == 0 && D_L39_00241164->f1A0 != 0 && D_L39_00241164->f1A4 == 0) {
                    hit = 1;
                } else if (D_L39_00241164->f1A4 & 0x800) {
                    hit = 1;
                }
            }
        }
        if (!done && D_L39_0024CC24 >= 10) {
            func_L39_00608180(D_L39_0024CC10_sda);
            done = 1;
        }
        if (hit && !ret) {
            ret = 1;
            func_L39_0060A670(D_L39_0024CC0C);
        }
        if (!done && D_L39_0024CC24 >= 10) {
            func_L39_00608180(D_L39_0024CC10);
            done = 1;
        }
        avail = func_L39_00609378(a1, &o0);
        if (left2 > 0 && avail > 0xFFFF) {
            k = func_L39_00609490(a2, o0, 0x10000);
            left2 -= k;
            func_L39_006093A8(a1, k);
        }
        func_L39_00607DD8();
        if (!done && D_L39_0024CC24 >= 10) {
            func_L39_00608180(D_L39_0024CC10);
            done = 1;
        }
        n = func_L39_006093E8(a1, &o1);
        if (n > 0) {
            k = func_001470F0(a0, o1, n, a1, p->f8);
            left -= k;
            func_L39_00609428(a1, k);
        }
        func_L39_00608098();
        if (!done && D_L39_0024CC24 >= 10) {
            func_L39_00608180(D_L39_0024CC10_sda);
            done = 1;
        }
        if (!started && func_L39_0060ACB8(D_L39_0024CBE0_sda) && func_L39_00607DF8()) {
            func_L39_00608FE0(1);
            started = 1;
        }
    }
    while (!func_L39_0060A700(a0)) {
        func_L39_00608098();
        func_L39_00607DD8();
    }
    while (!func_L39_0060A7D0(a0) && func_L39_0060A680(a0) != 3) {
        func_L39_00608098();
        func_L39_00607DD8();
    }
    func_L39_00609030();
    func_L39_00608220(D_L39_0024CC10_sda);
    return ret;
}
/* localdecomp:end func_L39_00607AA8 */

/* localdecomp:start func_L39_00607DD8 */
void func_00126110(s32);

void func_L39_00607DD8(void) {
    func_00126110(1);
}
/* localdecomp:end func_L39_00607DD8 */
