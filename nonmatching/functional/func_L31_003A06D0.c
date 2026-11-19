/* functional: high. Checked with --flags '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division' --mode S; instruction stream equal after masking regs/addressing. */
#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad00[0x10];
    f32 vx;
    f32 vy;
    f32 vz;
    s32 w1C;
    f32 f20;
    f32 f24;
    s32 w28;
    f32 f2C;
    s32 w30;
    s32 w34;
    f32 f38;
    s32 w3C;
    s32 w40;
    s32 w44;
    s32 w48;
    s32 w4C;
    s32 w50;
    u8 pad54[0xC];
    f32 f60;
} Priv_003A06D0;

typedef struct {
    u8 pad00[0x18];
    u8 *p18;
    u8 pad1C[4];
    vu0_v4 v20;
} Glob_003A06D0;

typedef struct {
    u8 pad00[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    u8 *ownerDC;
} Slot_003A06D0;

/* localdecomp:start func_L31_003A06D0 */
extern f32 D_L31_001DE740;
extern f32 D_L31_001DE744;
extern f32 D_L31_001DE74C;
extern f32 D_L31_001DE754;
extern f32 D_L31_001DE758;
extern s32 D_L31_001DE6E0;
extern s32 D_L31_001DE6E4;
extern Glob_003A06D0 D_L31_001E9180;
extern u8 D_001A30B0[];
extern void func_L31_003A11E0(void *);
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L31_003A0D30(void *);
extern f32 func_0038DB48(f32);
extern s32 func_L01_004561B8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_003FB640(void *, f32, s32, void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L31_003A12B0(s32, void *, void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00456230(void *, s32);
extern void func_L31_003A1270(void *);
extern void func_L31_003A0C88(void *);

void func_L31_003A06D0(u8 *obj) {
    Priv_003A06D0 *p;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    u8 *carrier;
    u8 *slot;
    vu0_v4 *pv40;
    u8 *tgt;
    f32 a;
    f32 b;
    f32 t;
    f32 k;
    f32 q;
    s32 i;
    s32 h;

    p = *(Priv_003A06D0 **)(obj + 0x68);
    a = D_L31_001DE740;
    if (p->w3C == 0) {
        a = a * p->f60;
    }
    b = D_L31_001DE744;
    if (p->w3C == 0) {
        b = b * p->f60;
    }
    switch (obj[0x20]) {
    case 0:
        func_L31_003A11E0(obj);
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (func_L01_00456250(obj) != 0) {
            func_L01_004450F0(obj, 2, -1);
        }
        func_L31_003A0D30(obj);
        *(f32 *)(obj + 0xF0) = func_0038DB48(0.0f);
        *(f32 *)(obj + 0xF8) = -1.5707964f;
        func_L01_0043B9E8(obj, 0xFF, 0xFF, 0xFF);
        h = p->w34;
        if (h == -1 || *(u8 **)((slot = D_001A30B0 + h * 128) + 0xDC) != obj || slot[0xD0] == 0) {
            p->w34 = func_003A52A0(1, 4, obj);
        }
        break;
    case 2:
        if (func_L01_004561B8(obj) != 0 && obj[0x43] != 1) {
            func_003C3A10(obj, 1, 0, 4);
        }
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
        p->vx = p->vx + p->f20;
        p->vz = p->vz + p->f24;
        vec_add_ba(&v10, obj + 0x10, &p->vx);
        if (func_L01_003FB640(&v10, a, 0x12, obj) != 0 || func_0038CAD0(&p->w28) != 0) {
            if (D_L31_001E9180.p18 != 0) {
                p->w40 = (s32)D_L31_001E9180.p18;
            }
            *(vu0_q *)(obj + 0x10) = *(vu0_q *)&D_L31_001E9180.v20;
            func_L01_004450F0(obj, 3, -1);
        } else {
            *(vu0_q *)(obj + 0x10) = *(vu0_q *)&v10;
        }
        if (p->w3C != 0) {
            func_L01_00446780(obj, obj + 0x10, 1, 0, 1, 0, a, p->f2C, 1.0f);
        }
        func_L31_003A0D30(obj);
        if (p->vz != 0.0f) {
            if (p->vx == 0.0f) {
                *(f32 *)(obj + 0xF0) = 0.0f;
            } else {
                *(f32 *)(obj + 0xF0) = func_0038D160(p->vx, p->vz);
                *(f32 *)(obj + 0xF0) = func_0038DAB8(*(f32 *)(obj + 0xF0), (p->vx < 0.0f) ? D_L31_001DE754 : D_L31_001DE758);
            }
            *(f32 *)(obj + 0xF8) = -1.5707964f;
            func_L01_0043B9E8(obj, 0xFF, 0xFF, 0xFF);
            h = p->w34;
            if (h == -1 || *(u8 **)((slot = D_001A30B0 + h * 128) + 0xDC) != obj || slot[0xD0] == 0) {
                p->w34 = func_003A52A0(1, 4, obj);
            }
        }
        break;
    case 3:
        carrier = 0;
        tgt = (u8 *)p->w40;
        if (tgt != 0 && (*(u16 *)(tgt + 0x34) & 0x20) != 0) {
            carrier = *(u8 **)(*(u8 **)(tgt + 0x68) + 8);
        }
        if (func_L01_004561B8(obj) != 0) {
            if (p->w3C != 0) {
                func_003A52A0(0, 0, obj);
            }
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(obj, 1);
            p->w28 = D_L31_001DE6E4;
            if (p->w3C != 0) {
                pv40 = &v40;
                for (i = 0; i < D_L31_001DE6E0; i++) {
                    *(vu0_q *)&v40 = 0;
                    v40.y = 1.0f;
                    v40.w = 1.0f;
                    func_0038CF68(&v20, &p->vx, p->f38);
                    t = func_003C4088(2.042035f, 4.2411504f, (f32)i / (f32)D_L31_001DE6E0);
                    func_0038D890(&v20, &v20, pv40, t);
                    if (carrier != 0) {
                        vec_add_ab(&v20, &v20, carrier + 0x10);
                    }
                    func_0038CE20(&v10, &v20, D_L31_001DE74C);
                    vec_add_ba(&v10, obj + 0x10, &v10);
                    qzero(&v30);
                    v30.x = p->f20;
                    v30.z = p->f24;
                    func_L01_00456230(func_L31_003A12B0(p->w30, &v20, &v10, &v30, p->w44, p->w48, p->w4C, p->w50, 1.0f, p->f38, p->f60, 0), 1);
                }
            }
        }
        if (carrier != 0) {
            vec_add_ab(obj + 0x10, obj + 0x10, carrier + 0x10);
            q = *(f32 *)(carrier + 0x18);
            if (q < 0.0f) {
                *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) - q;
            }
        }
        k = (f32)(D_L31_001DE6E4 - p->w28) / (f32)D_L31_001DE6E4;
        func_L31_003A0D30(obj);
        if (p->w3C != 0) {
            func_L01_00446780(obj, obj + 0x10, 1, 0, 1, 0, func_003C4088(a, b, 1.0f - k), 20.0f, 1.0f);
        }
        if (func_0038CAD0(&p->w28) != 0) {
            func_L01_004450F0(obj, 4, -1);
        }
        break;
    case 4:
        func_L31_003A1270(obj);
        return;
    }
    if (p->w3C > 0) {
        func_L31_003A0C88(obj);
    }
}
/* localdecomp:end func_L31_003A06D0 */
