#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003619F0);

/* localdecomp:start func_L05_00362148 */
#include "vu0.h"
__asm__(".extern D_L05_001DD9C0, 4");
__asm__(".extern D_L05_001DD9D4, 4");
typedef struct { u8 pad[0x32]; s16 f32; } M_362148;
extern f32 D_L05_001DD9C0;
extern f32 D_L05_001DD9D4;
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);

u8 *func_L05_00362148(u8 *a0, vu0_v4 *a1, vu0_v4 *a2, s32 a3, s32 t0, u8 t1, f32 f) {
    u8 *m;
    u8 *s;
    vu0_v4 tmp;
    m = func_003C24B0(0x169C, 0x80);
    if (m != 0) {
        s = *(u8 **)(m + 0x68);
        m[0x30] = 0xFF;
        m[0x20] = 0;
        ((M_362148 *)m)->f32 = 0xFF;
        m[0x31] = 1;
        *(s32 *)(s + 4) = a3;
        *(s32 *)(s + 0) = (s32)a0;
        *(vu0_q *)(m + 0x10) = *(vu0_q *)a1;
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)(a0 + 0xF0);
        *(f32 *)(m + 0x2C) = D_L05_001DD9C0;
        *(f32 *)(s + 0xC) = 1.0f / (f32)t0;
        *(s32 *)(s + 0x54) = t1;
        *(f32 *)(s + 0x58) = f;
        *(s16 *)(s + 8) = t0;
        *(s32 *)(s + 0x50) = 0;
        *(vu0_q *)(s + 0x20) = *(vu0_q *)a1;
        *(vu0_q *)(s + 0x10) = *(vu0_q *)a2;
        vec_sub_ba(&tmp, s + 0x10, s + 0x20);
        tmp.z = 0;
        func_0038CE20(&tmp, &tmp, D_L05_001DD9D4);
        vec_add_ba(s + 0x40, s + 0x20, &tmp);
        func_0038CF68(&tmp, &tmp, -1.0f);
        tmp.z = *(f32 *)(s + 0x18) - *(f32 *)(s + 0x28);
        vec_add_ab(s + 0x30, s + 0x10, &tmp);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L05_00362148 */

INCLUDE_ASM("asm/levels", func_L05_003622D0);

INCLUDE_ASM("asm/levels", func_L05_003624B0);

/* localdecomp:start func_L05_003627A0 */
extern void func_L01_004450F0(s32, s32, s32);
extern u8 *D_L05_001DFB9C;
extern u8 *D_001DFB9C_sda;
__asm__(".extern D_L05_001DFB9C, 16");
__asm__(".extern D_001DFB9C_sda, 4");

void func_L05_003627A0(void *arg0) {
    u8 *p;
    s32 a;

    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        p = *(u8 **)((u8 *)arg0 + 0x68);
        a = *(s32 *)p;
        *(s32 *)(p + 0x8) = 0;
        *(s32 *)(p + 0xC) = 0;
        if (a != -1) {
            *(u8 **)(p + 0x8) = D_L05_001DFB9C + (a << 8);
        }
        a = *(s32 *)(p + 0x4);
        if (a != -1) {
            *(u8 **)(p + 0xC) = D_001DFB9C_sda + (a << 8);
        }
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L05_003627A0 */

/* localdecomp:start func_L05_00362810 */
typedef struct P_362810 {
    f32 f0;
    s32 w4;
    f32 f8;
    s32 wC;
} P_362810;

typedef struct S_362810 {
    char pad0[0x18];
    f32 f18;
    char pad1[0x20 - 0x1C];
    u8 b20;
    char pad2[0x68 - 0x21];
    P_362810 *p68;
} S_362810;

struct S_362968;
void func_L05_00362968(struct S_362968 *a0);
s32 func_003A52A0(void *, s32, void *);
void func_003A4F28(s32);
void func_003C41A0(f32 *, void *, f32, f32, f32, f32);

extern u8 D_001A30B0[];
__asm__(".extern D_001A30B0, 16");
extern f32 D_001DDA38_sda;
extern f32 D_001DDA3C_sda;
__asm__(".extern D_001DDA38_sda, 4");
__asm__(".extern D_001DDA3C_sda, 4");

void func_L05_00362810(S_362810 *a0) {
    P_362810 *p;
    u8 *e;
    s32 w;
    s32 k;
    f32 t;
    f32 u;

    func_L05_00362968(a0);
    p = a0->p68;
    k = a0->b20;
    if (k != 2) {
        if (k < 3) {
            if (k == 1) {
                func_L01_004450F0((s32) a0, 2, -1);
            }
        }
    } else {
        if (a0->f18 < p->f0) {
            if (p->wC == -1) {
                p->wC = func_003A52A0(0, 4, a0);
            } else {
                e = D_001A30B0 + (p->wC << 7);
                if (*(void **) (e + 0xDC) != a0 || e[0xD0] == 0) {
                    p->wC = func_003A52A0(0, 4, a0);
                }
            }
            t = D_001DDA38_sda * 1.44f;
            u = D_001DDA3C_sda * 1.2f;
            func_003C41A0(&a0->f18, &p->w4, p->f0, t, t, u);
        } else {
            w = p->wC;
            if (w != -1) {
                e = D_001A30B0 + (w << 7);
                if (*(void **) (e + 0xDC) == a0 && e[0xD0] != 0) {
                    func_003A4F28(w);
                }
            }
            p->wC = -1;
            func_L01_004450F0((s32) a0, 3, -1);
        }
    }
}
/* localdecomp:end func_L05_00362810 */

/* localdecomp:start func_L05_00362968 */
typedef struct P_362968 {
    f32 f0;
    s32 w4;
    f32 f8;
    s32 wC;
} P_362968;

typedef struct S_362968 {
    char pad0[0x18];
    f32 f18;
    char pad1[0x20 - 0x1C];
    u8 b20;
    char pad2[0x68 - 0x21];
    P_362968 *p68;
} S_362968;

s32 func_L01_004450F0_00362968(void *, s32, s32);

void func_L05_00362968(S_362968 *a0) {
    P_362968 *p;
    f32 t;
    f32 g;

    p = a0->p68;
    if (a0->b20 == 0) {
        g = p->f8;
        p->wC = -1;
        t = a0->f18 + g;
        p->w4 = 0;
        p->f0 = t;
        func_L01_004450F0_00362968(a0, 1, -1);
    }
}
/* localdecomp:end func_L05_00362968 */
