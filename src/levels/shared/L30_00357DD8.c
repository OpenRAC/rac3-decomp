#include "common.h"

/* localdecomp:start func_L30_00357DD8 */
typedef struct {
    u8 pad[0x60];
    s32 x60[1];
} S_00357DD8;

extern S_00357DD8 D_00142660;
extern void func_L30_003582E0(void *, s32);

void func_L30_00357DD8(u8 *a0, u8 *a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *q = *(u8 **)(a1 + 0x68);

    if (a0 != 0 && a1 != 0) {
        if (*(s16 *)(a1 + 0xAA) == 0x1B30) {
            ((void (*)(s32, s32))func_L30_003582E0)(0xC6B, 0x55);
            func_L30_00357ED8(a0, a1);
        } else {
            s32 v;
            s32 s;

            ((void (*)(s32, s32))func_L30_003582E0)(0xC6A, 0x54);
            v = *(s32 *)(q + 0x10);
            s = v % 32;
            if (((D_00142660.x60[v >> 5] >> s) ^ 1) & 1) {
                *(s32 *)(p + 0xE4) += 1;
                D_00142660.x60[v >> 5] |= 1 << s;
            }
            func_L01_00456230(a1, 1);
        }
    }
}
/* localdecomp:end func_L30_00357DD8 */

/* localdecomp:start func_L30_00357ED8 */
extern s32 D_001426C0[];
extern void func_L01_00456230(void *, s32);

void func_L30_00357ED8(u8 *a0, u8 *a1) {
    s32 i;
    u8 *o = a1;
    u8 *p = *(u8 **)(a0 + 104);
    s32 *q = *(s32 **)(o + 104);

    if (a0 != 0 && o != 0) {
        i = 0;
        do {
            s32 v = *q + i;
            s32 s = v % 32;
            s32 mask = 1 << s;
            s32 *w = &D_001426C0[v >> 5];
            if (((*w >> s) ^ 1) & 1) {
                *(s32 *)(p + 228) += 1;
                *w |= mask;
            }
            i++;
        } while (i < 10);
        func_L01_00456230(o, 1);
    }
}
/* localdecomp:end func_L30_00357ED8 */

/* localdecomp:start func_L30_00357F90 */
extern s16 *D_L30_0021C420[];
extern u8 *D_L30_001DF71C;
__asm__(".extern D_L30_001DF71C, 16");
extern s32 D_L30_001DF758;
extern s32 func_L30_003580F8(u8 *, u8 *);

void func_L30_00357F90(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s16 *q;

    *(s32 *)(p + 0xE4) = 0;
    *(s32 *)(p + 0xE8) = 0;
    q = D_L30_0021C420[*(s32 *)(p + 0xE0)];
    while ((*(s32 *)(p + 0xE0) & 0xFF) != 0xFF && *(s32 *)(p + 0xE0) <= D_L30_001DF758 && q != 0 &&
           (q[-1] >= 0 || q == D_L30_0021C420[*(s32 *)(p + 0xE0)])) {
        u8 *m = D_L30_001DF71C + (*q & 0x7FFF) * 0x100;

        if (m == 0) {
            return;
        }
        if (*(s16 *)(m + 0xAA) == 0x1B30) {
            **(s32 **)(m + 0x68) = *(s32 *)(p + 0xE8);
            *(s32 *)(p + 0xE8) += 10;
            if (func_L30_003580F8(a0, m)) {
                *(s32 *)(p + 0xE4) += 10;
                func_L01_00456230(m, 1);
            }
        } else {
            *(s32 *)(*(u8 **)(m + 0x68) + 0x10) = *(s32 *)(p + 0xE8);
            *(s32 *)(p + 0xE8) += 1;
            if (func_L30_003580F8(a0, m)) {
                *(s32 *)(p + 0xE4) += 1;
                func_L01_00456230(m, 1);
            }
        }
        q++;
    }
}
/* localdecomp:end func_L30_00357F90 */

/* localdecomp:start func_L30_003580F8 */
/* D_00142660 is declared by the file (S_00357DD8: pad[0x60], s32 x60[]) */

s32 func_L30_003580F8(u8 *a0, u8 *a1) {
    s32 v;
    s32 i;
    s32 s;

    if (a0 == 0 || a1 == 0) {
        return 0;
    }
    if (*(s16 *)(a1 + 0xAA) == 0x1B30) {
        v = **(s32 **)(a1 + 0x68);
        i = v >> 5;
        s = v % 32;
    } else {
        v = *(s32 *)(*(u8 **)(a1 + 0x68) + 0x10);
        i = v >> 5;
        s = v % 32;
    }
    return (D_00142660.x60[i] >> s) & 1;
}
/* localdecomp:end func_L30_003580F8 */

LINKER_REMNANT("asm/levels", func_L30_00358170);

/* localdecomp:start func_L30_00358180 */
#include "vu0.h"

extern void func_L30_00358210(u8 *);
extern void func_L30_004CF4B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L30_00358180(u8 *m, u8 *p, s32 n) {
    vu0_q z;
    u8 *v;

    qzero(&z);
    v = *(u8 **)(m + 0x68);
    if (*(s32 *)(v + 0xD8) > 0) {
        func_L30_00358210(m);
    }
    *(vu0_q *)(v + 0xC0) = p != 0 ? *(vu0_q *)p : z;
    *(s32 *)(v + 0xD8) = *(s32 *)(v + 0xDC) = n;
    func_L30_004CF4B0(0x74, 1);
    func_L01_004450F0(m, 1, -1);
}
/* localdecomp:end func_L30_00358180 */

/* localdecomp:start func_L30_00358210 */
extern void func_L30_004CF4B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L30_00358210(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    *(s32 *)(v + 220) = 0;
    *(s32 *)(v + 216) = 0;
    func_L30_004CF4B0(154, 1);
    func_L01_004450F0(a0, 6, -1);
}
/* localdecomp:end func_L30_00358210 */

/* localdecomp:start func_L30_00358258 */
extern s32 D_L30_001DDAA4;

void func_L30_00358258(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 t = D_L30_001DDAA4;
    s32 cur = *(s32 *)(p + 220);
    f32 fc = cur;
    s32 end = *(s32 *)(p + 216);

    if (cur < t) {
        *(f32 *)(p + 208) = fc / t;
        return;
    }
    if (end - t < cur) {
        *(f32 *)(p + 208) = (f32)(cur - end) / (f32)(-t);
        return;
    }
    *(f32 *)(p + 208) = 1.0f;
}
/* localdecomp:end func_L30_00358258 */

/* localdecomp:start func_L30_003582E0 */
typedef struct {
    u16 x0;
    u8 pad[10];
} S_1A7E18;

extern S_1A7E18 D_001A7E18[];
extern s32 func_L01_0041A5B0(void *, s32);
extern void func_L01_0041BE28(void *, s32);

void func_L30_003582E0(void *a, s32 i) {
    S_1A7E18 *p = &D_001A7E18[i];

    if (p->x0 == 0) {
        if (func_L01_0041A5B0(a, i) == 0) {
            func_L01_0041BE28(a, i);
        }
        if (p->x0 == 0) {
            p->x0 = 1;
        }
    }
}
/* localdecomp:end func_L30_003582E0 */

/* localdecomp:start func_L30_00358360 */
extern u16 D_001426D0[];

u16 func_L30_00358360(void) {
    return D_001426D0[0];
}
/* localdecomp:end func_L30_00358360 */

LINKER_REMNANT("asm/levels", func_L30_00358370);

INCLUDE_ASM("asm/levels", func_L30_00358380);
