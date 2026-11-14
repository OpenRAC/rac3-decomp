#include "common.h"
#include "vu0.h"


/* localdecomp:start func_L32_003A0BB8 */
extern f32 D_L32_001DE6D4;
extern f32 D_L32_001DE6C8;
void func_L32_003A25B0(void *, f32, f32);
void func_L32_003A2508(void *, s32, f32);
void func_L32_003A14C8(void *, s32);

void func_L32_003A0BB8(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    func_L32_003A25B0(arg0, D_L32_001DE6D4, D_L32_001DE6C8);
    func_L32_003A2508(arg0, 0, 0.0f);
    if (p[0x228] != 0) {
        func_L32_003A14C8(arg0, 1);
    }
}
/* localdecomp:end func_L32_003A0BB8 */

INCLUDE_ASM("asm/levels", func_L32_003A0C18);

INCLUDE_ASM("asm/levels", func_L32_003A0E20);

INCLUDE_ASM("asm/levels", func_L32_003A11C8);

INCLUDE_ASM("asm/levels", func_L32_003A14C8);

/* localdecomp:start func_L32_003A1670 */
void func_L01_004450F0(s32, s32, s32);

void func_L32_003A1670(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    func_L01_004450F0((s32) arg0, arg1, -1);
    if (*(u8 *)((u8 *)arg0 + 0x20) == 3) {
        *(s8 *)(p + 0x229) = 1;
        *(s8 *)(p + 0x228) = 0;
        *(s32 *)(p + 0x21C) = 4;
    }
}
/* localdecomp:end func_L32_003A1670 */

INCLUDE_ASM("asm/levels", func_L32_003A16C8);

INCLUDE_ASM("asm/levels", func_L32_003A1BF0);

/* localdecomp:start func_L32_003A1D30 */
extern s32 func_00382498(s32, s32);

void func_L32_003A1D30(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);
    s32 n;
    s32 i;
    s32 r;

    n = 0;
    for (i = 0; i < 4; i++) {
        s32 *ids = (s32 *)(v + 0x90);
        if (ids[i] != -1) {
            n++;
        }
    }
    if (n >= 2) {
        if (n == 2) {
            for (i = 0; i < 4; i++) {
                s32 *ids = (s32 *)(v + 0x90);
                if (ids[i] != -1 && i != *(s32 *)(v + 0xF0)) {
                    *(s16 *)(v + 0x22A) = i;
                }
            }
            return;
        }
        r = func_00382498(0, n - 3);
        for (i = 0; i < 4; i++) {
            for (i = 0; i < 4; i++) {
                s32 *ids = (s32 *)(v + 0x90);
                if (ids[i] != -1 && i != *(s32 *)(v + 0xF0) && i != *(s16 *)(v + 0x22A)) {
                    if (r == 0) {
                        *(s16 *)(v + 0x22A) = i;
                        return;
                    }
                    r--;
                }
            }
        }
    }
    *(s16 *)(v + 0x22A) = *(s32 *)(v + 0xF0);
}
/* localdecomp:end func_L32_003A1D30 */

INCLUDE_ASM("asm/levels", func_L32_003A1E58);

/* localdecomp:start func_L32_003A20C8 */
s32 func_L01_004561B8(void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L01_00456230(void *, s32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L32_003A2468(void *, s32);
extern u8 *D_L32_001DFE1C;

void func_L32_003A20C8(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);
    s32 i;
    s32 *p;
    u8 **q;

    if (func_L01_004561B8(arg0) != 0) {
        for (i = 0; i < 6; i++) {
            q = &((u8 **)(v + 0x200))[i];
            if (*q != 0 && func_L30_0034D8D8(*q + 0x10, 1.5f) != 0) {
                func_L01_00456230(*q, 1);
                func_L01_0043B9E8(*q, v[0x44], v[0x45], v[0x46]);
                (*q)[0xA8] = 0xFF;
            } else {
                func_003C2880(*q);
            }
            *q = 0;
        }
        func_L32_003A2468(arg0, 0);
        p = (s32 *)(v + 0xE0);
        for (i = 0; i < 2; i++) {
            if (*p != -1) {
                func_L01_00456230(D_L32_001DFE1C + (*p << 8), 0);
            }
            p++;
        }
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L32_003A20C8 */

/* localdecomp:start func_L32_003A21E0 */
extern s32 D_L32_001DE6F8;
extern f32 D_L32_001DE614;
extern u8 *D_L32_001DFF00;
__asm__(".extern D_L32_001DE6F8, 4");
__asm__(".extern D_L32_001DE614, 4");
__asm__(".extern D_L32_001DFF00, 16");
s32 func_L01_004561B8(void *);
f32 func_003C4088(f32, f32, f32);
void func_L32_003A1BF0(void *, void *, f32, f32);
void func_L32_003A1670(void *, s32);

void func_L32_003A21E0(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 f20;
    f32 r;
    s32 v;
    u8 b;

    if (func_L01_004561B8(arg0) != 0) {
        *(s32 *)(p + 0x78) = 0;
    }
    v = *(s32 *)(p + 0x78);
    f20 = (f32) (v + 1) / (f32) D_L32_001DE6F8;
    *(s32 *)(p + 0x78) = v + 1;
    if (f20 > 1.0f) {
        f20 = 1.0f;
    }
    r = func_003C4088(D_L32_001DE614, 0.0f, f20);
    if (*(s16 *)(p + 0x22A) != -1) {
        func_L32_003A1BF0(arg0, D_L32_001DFF00 + ((*(s32 *)(p + (*(s16 *)(p + 0x22A) << 2) + 0x90)) << 7) + 0x30, r, 1.0f - f20);
    } else {
        func_L32_003A1BF0(arg0, (u8 *)arg0 + 0x10, r, 1.0f);
    }
    b = *(u8 *)(p + 0x229);
    if (b != 0) {
        func_L32_003A1670(arg0, 2);
    }
}
/* localdecomp:end func_L32_003A21E0 */

/* localdecomp:start func_L32_003A22E0 */
extern f32 D_L32_001DE6A4;
__asm__(".extern D_L32_001DFF00, 16");
f32 func_0038CF00(void *, void *);
void func_L32_003A1D30(void *);

static __inline__ u8 *target_pos_003A22E0(u8 *p) {
    u8 *tbl = p + 0x90;

    return D_L32_001DFF00 + (*(s32 *)(tbl + (*(s16 *)(p + 0x22A) << 2)) << 7) + 0x30;
}

void func_L32_003A22E0(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    if (*(s16 *)(p + 0x22A) == -1 ||
        func_0038CF00((u8 *)arg0 + 0x10, target_pos_003A22E0(p)) < D_L32_001DE6A4) {
        func_L32_003A1D30(arg0);
        *(u8 *)(p + 0x228) = 1;
    }
    func_L32_003A1BF0(arg0, target_pos_003A22E0(p), D_L32_001DE614, 1.0f);
    if (*(u8 *)(p + 0x229) == 0) {
        func_L32_003A1670(arg0, 1);
    }
}
/* localdecomp:end func_L32_003A22E0 */

/* localdecomp:start func_L32_003A23C8 */
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L32_003A1670(void *, s32);
extern void func_L32_003A2468(void *, s32);
extern u8 D_1A4C60[];
extern u8 *D_L32_001DFE1C;

void func_L32_003A23C8(void *arg0) {
    u8 *v = *(u8 **)((u8 *)arg0 + 0x68);
    s32 i;
    s32 none;
    s32 *p;
    u8 *base;

    if (func_00382380(D_1A4C60, *(s32 *)(v + 0xEC), 0)) {
        func_L32_003A2468(arg0, 1);
        p = (s32 *)(v + 0xE0);
        none = -1;
        for (i = 1; i >= 0; i--) {
            base = D_L32_001DFE1C;
            if (*p != none) {
                func_L01_00456230(base + (*p << 8), 1);
            }
            p++;
        }
        func_L32_003A1670(arg0, 2);
    }
}
/* localdecomp:end func_L32_003A23C8 */

/* localdecomp:start func_L32_003A2468 */
extern s32 D_L32_001DEC54;
__asm__(".extern D_L32_001DEC54, 16");

static __inline__ f32 *elem_003A2468(u8 **list, s32 n) {
    return (f32 *)(*list + (n << 5));
}

void func_L32_003A2468(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *q;
    u8 *r;
    u8 *base;
    s32 i;
    f32 *x;

    if (p == 0) {
        return;
    }
    q = *(u8 **)(p + 0x218);
    if (q == 0) {
        return;
    }
    r = *(u8 **)(q + 0x68);
    if (r == 0) {
        return;
    }
    base = r + 0x4C;
    for (i = 0; i < 4; i++) {
        if (((s32 *)(p + 0x80))[i] != -1) {
            x = elem_003A2468(&base, ((s32 *)(p + 0x80))[i]);
            if (arg1 != 0) {
                *x = 0.0f;
            } else {
                *x = 1.0f;
            }
        }
    }
    x = elem_003A2468(&base, *(s32 *)(p + 0xE8));
    if (arg1 != 0) {
        *x = 1.0f;
    } else {
        *x = 0.0f;
    }
    D_L32_001DEC54 = arg1 ^ 1;
}
/* localdecomp:end func_L32_003A2468 */
