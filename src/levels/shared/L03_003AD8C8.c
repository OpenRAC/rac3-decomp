#include "common.h"

typedef struct { u8 p0[0x34]; u16 h34; } M_3ABF90;
typedef struct { u8 p0[0x2C]; s32 w2C; u8 p30[0x20]; s32 w50; s32 w54; } S_3AC2C8;
typedef struct { u8 p0[0x68]; S_3AC2C8 *w68; } M_3AC2C8;

/* localdecomp:start func_L03_003AD8C8 */
extern void func_003C6F90(M_3ABF90 *, s32, s32, s32, s32);
__asm__(".extern D_L03_001DE720, 8");
extern s32 D_L03_001DE720[2];

void func_L03_003AD8C8(M_3ABF90 *m, s32 i) {
    m->h34 &= ~0x80;
    func_003C6F90(m, D_L03_001DE720[i], 14, 14, 14);
}
/* localdecomp:end func_L03_003AD8C8 */

INCLUDE_ASM("asm/levels", func_L03_003AD910);

/* localdecomp:start func_L03_003ADA98 */
extern void func_L01_00456230(void *, s32);
extern void func_L03_004330B8(s32, s32);
extern u8 *D_L03_001DF99C;

void func_L03_003ADA98(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    s32 *p;
    s32 i;
    s32 t;
    func_L01_00456230(a0, 1);
    p = (s32 *)(pv + 8);
    for (i = 0; i < 2; i++) {
        t = p[i];
        if (t != -1) {
            func_L01_00456230(D_L03_001DF99C + (t << 8), 1);
        }
        if (a0[0x21] != 0xFF) {
            func_L03_004330B8(a0[0x21], 1);
        }
    }
}
/* localdecomp:end func_L03_003ADA98 */

/* localdecomp:start func_L03_003ADB38 */
extern void func_L03_003AE810(u8 *);
void func_L03_003ADB38(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    s32 n = *(s32 *)(p + 80) + 1;
    s32 m;
    *(s32 *)(p + 80) = n;
    m = p[*(s32 *)(p + 44) * 32 + 522];
    if (m < n) {
        *(s32 *)(p + 80) = m;
    }
    func_L03_003AE810(a0);
}
/* localdecomp:end func_L03_003ADB38 */

/* localdecomp:start func_L03_003ADB80 */
void func_L03_003ADB80(unsigned char *object) {
    int *state = *(int **)(object + 0x68);
    unsigned char *t = (unsigned char *)state[0];
    if (t != 0) {
        if (*(short *)(t + 0xAA) == 0x1C01) {
            if (t[0x20] != 0xFE) {
                if (t[0x20] != 0xFD) {
                    int *w = *(int **)(t + 0x68);
                    state[1] = 0x20;
                    *w = 0;
                }
            }
        }
    }
}
/* localdecomp:end func_L03_003ADB80 */

/* localdecomp:start func_L03_003ADBC8 */
extern void func_L03_003AE810(u8 *);
extern void func_L03_003ADB80(u8 *);
void func_L03_003ADBC8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    *(s32 *)(p + 84) = 0;
    *(s32 *)(p + 80) = 0;
    ((void (*)(void))func_L03_003AE810)();
    func_L03_003ADB80(a0);
}
/* localdecomp:end func_L03_003ADBC8 */

/* localdecomp:start func_L03_003ADC00 */
extern void func_L03_003ADB80(u8 *);
extern void func_L03_003AE810(u8 *);
extern void func_L03_003AE880(M_3AC2C8 *);

void func_L03_003ADC00(M_3AC2C8 *m) {
    S_3AC2C8 *s = m->w68;
    s->w54 = 0;
    s->w50 = 0;
    s->w2C = 0;
    func_L03_003AE880(m);
    ((void (*)(M_3AC2C8 *))func_L03_003AE810)(m);
    ((void (*)(M_3AC2C8 *))func_L03_003ADB80)(m);
}
/* localdecomp:end func_L03_003ADC00 */

/* localdecomp:start func_L03_003ADC48 */
extern u8 *D_L03_001DF9A0;
extern u8 *D_L03_001DF9A4;

void func_L03_003ADC48(void) {
    u8 *p;
    for (p = D_L03_001DF9A0; p <= D_L03_001DF9A4; p += 0x100) {
        if (p != 0 && p[0x20] != 0xFE && p[0x20] != 0xFF) {
            s32 h = *(s16 *)(p + 0xAA);
            if (h == 0x1C04 || h == 0x1C06) {
                p[0x20] = 1;
                if (h == 0x1C04) {
                    *(s32 *)(*(u8 **)(p + 0x68) + 0x24) += 3;
                }
            }
        }
    }
}
/* localdecomp:end func_L03_003ADC48 */

/* localdecomp:start func_L03_003ADCD8 */
extern u8 *D_L03_001DF9A0;
extern u8 *D_L03_001DF9A4;
extern f32 D_L03_001DF2D0;
extern void func_L03_003AE558(s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_003ADCD8(u8 *a0) {
    u8 *p;
    for (p = D_L03_001DF9A0; p <= D_L03_001DF9A4; p += 0x100) {
        if (p != 0 && p[0x20] != 0xFE && p[0x20] != 0xFF) {
            s32 h = *(s16 *)(p + 0xAA);
            if (h == 0x1C04 || h == 0x1C06) {
                p[0x31] = 0;
                *(u16 *)(p + 0x34) |= 1;
            }
        }
    }
    D_L03_001DF2D0 = 0.5f;
    func_L03_003AE558(1);
    func_L01_004450F0(a0, 0x12, -1);
}
/* localdecomp:end func_L03_003ADCD8 */

/* localdecomp:start func_L03_003ADDA0 */
extern u8 *D_L03_001DF9A0;
extern u8 *D_L03_001DF9A4;
extern f32 D_L03_001DF2D0;
extern void func_L03_003AE558(s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L03_003ADDA0(u8 *a0) {
    u8 *p;
    s32 t;
    for (p = D_L03_001DF9A0; p <= D_L03_001DF9A4; p += 0x100) {
        if (p != 0 && p[0x20] != 0xFE && p[0x20] != 0xFF) {
            s32 h = *(s16 *)(p + 0xAA);
            if (h == 0x1C04 || h == 0x1C06) {
                if (h == 0x1C06) {
                    p[0x31] = 1;
                    *(u16 *)(p + 0x34) &= ~1;
                } else if (h == 0x1C04) {
                    t = *(s32 *)(*(u8 **)(p + 0x68) + 0x24);
                    if (t != 0 && t != 3 && t != 6) {
                        p[0x31] = 1;
                        *(u16 *)(p + 0x34) &= ~1;
                    }
                }
            }
        }
    }
    D_L03_001DF2D0 = 0.0f;
    func_L03_003AE558(0);
    func_L01_004450F0(a0, 4, -1);
}
/* localdecomp:end func_L03_003ADDA0 */

/* localdecomp:start func_L03_003ADE98 */
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L03_0043F5D0(s32, s32, f32);

void func_L03_003ADE98(u8 *a0, s32 a1, s32 a2) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 x = func_0038DAB8(*(f32 *)(pv + 0x10), 0.12566371f);
    *(f32 *)(pv + 0x10) = x;
    func_003C6F90(*(M_3ABF90 **)pv, func_L03_0043F5D0(a1, a2, x), 14, 14, 14);
    func_003C6F90(*(M_3ABF90 **)(pv + 0x30), func_L03_0043F5D0(a1, a2, *(f32 *)(pv + 0x10)), 14, 14, 14);
}
/* localdecomp:end func_L03_003ADE98 */

/* localdecomp:start func_L03_003ADF38 */
__asm__(".extern D_L03_001DE5C0, 4");
extern s32 D_L03_001DE5C0;

void func_L03_003ADF38(void) {
    D_L03_001DE5C0++;
}
/* localdecomp:end func_L03_003ADF38 */

/* localdecomp:start func_L03_003ADF48 */
__asm__(".extern D_L03_001DE5C4, 4");
extern s32 D_L03_001DE5C4;

void func_L03_003ADF48(void) {
    D_L03_001DE5C4++;
}
/* localdecomp:end func_L03_003ADF48 */

INCLUDE_ASM("asm/levels", func_L03_003ADF58);

/* localdecomp:start func_L03_003AE480 */
extern void func_L01_00516AA0(s32, s32, s32);

void func_L03_003AE480(s32 on) {
    if (on) {
        func_L01_00516AA0(0x4A0000, 1, 1);
    } else {
        func_L01_00516AA0(0x4A0000, 1, 0);
    }
}
/* localdecomp:end func_L03_003AE480 */

/* localdecomp:start func_L03_003AE4C0 */
extern void func_L01_00516AA0(s32, s32, s32);

void func_L03_003AE4C0(s32 arg0) {
    if (arg0) {
        func_L01_00516AA0(0x4A000A, 1, 1);
        func_L01_00516AA0(0x4A000B, 1, 1);
        func_L01_00516AA0(0x4A000C, 1, 1);
    } else {
        func_L01_00516AA0(0x4A000A, 1, 0);
        func_L01_00516AA0(0x4A000B, 1, 0);
        func_L01_00516AA0(0x4A000C, 1, 0);
    }
}
/* localdecomp:end func_L03_003AE4C0 */

/* localdecomp:start func_L03_003AE558 */
extern void func_L01_00516AA0(s32, s32, s32);

void func_L03_003AE558(s32 arg0) {
    if (arg0) {
        func_L01_00516AA0(0x4A000F, 1, 1);
        func_L01_00516AA0(0x4A0010, 1, 1);
        func_L01_00516AA0(0x4A000E, 1, 1);
    } else {
        func_L01_00516AA0(0x4A000F, 1, 0);
        func_L01_00516AA0(0x4A0010, 1, 0);
        func_L01_00516AA0(0x4A000E, 1, 0);
    }
}
/* localdecomp:end func_L03_003AE558 */

INCLUDE_ASM("asm/levels", func_L03_003AE5F0);
