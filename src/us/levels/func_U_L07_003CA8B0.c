#include "common.h"

/* localdecomp:start func_U_L07_003CA8B0 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CC2B0;

struct Obj_3CCAF0;
extern void func_L07_003CB0D8(struct Obj_3CCAF0 *);
extern void func_L07_003CB450(u8 *);
extern void func_L07_003CB8D0(void *, s32);
extern void func_L07_003CBBF8(void *);
extern void func_L07_003CBC90(void *, f32);
extern void func_L07_003CBDC8(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L07_003CBFE0(void *, s32);
extern void func_L07_003CBF20(void *);
extern void func_L07_003CC268(void *);
extern void func_L07_003CC3A8(void *);
extern void func_L07_003CC3F8(void *);
extern void func_L07_003CC430(void *);
extern void func_L07_003CC528(void *);
extern void func_L07_003CC668(void *);
extern s32 func_L07_003CD230(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004576E8(void *);
extern void func_L01_00458A08(void *, f32);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_00457440(void *, void *);
extern s32 func_L01_0044AF40(void *, f32);
extern f32 func_L01_00436500(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00407180(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_L06_003577D0(void *, void *, void *, void *, s32, s32, f32);
extern s32 func_0038CB00(void *);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern s32 D_L07_001DF41C;
extern s32 D_L07_001DF500;
__asm__(".extern D_L07_001DF41C, 16");
__asm__(".extern D_L07_001DF500, 16");

void func_U_L07_003CA8B0(u8 *obj) {
    V4_003CC2B0 d10;
    V4_003CC2B0 v20;
    u8 *p;
    u8 *t;
    f32 dist, ang;
    s32 base;
    s32 r;

    if (obj[0x20] == 0) func_L07_003CB0D8((struct Obj_3CCAF0 *)obj);
    func_L07_003CB450(obj);
    p = *(u8 **)(obj + 0x68);

    switch (obj[0x20]) {
    case 1:
        if (*(s16 *)(p + 0x144) == 1) func_L01_00441FB8(obj, 5, -1);
        break;
    case 2:
        func_L01_004576E8(obj);
        if (func_L01_00451078(obj, p + 0x70) & 2) {
            if (obj[0x94] >= 6) func_L07_003CB8D0(obj, 6);
            else func_L07_003CB8D0(obj, 5);
        }
        break;
    case 3:
        if (func_L01_00452EC8(obj)) *(s16 *)(p + 0x42E) = *(u16 *)(p + 0x42C);
        if (func_L07_003CD230(obj)) {
            if (func_0038CB00(p + 0x42E)) func_L07_003CB8D0(obj, 4);
        }
        break;
    case 4:
        base = D_L07_001DF41C + (*(s32 *)(p + 0x428) << 8);
        func_L01_00407180(obj, (void *)(base + 0x10), (void *)(base + 0xF0), 0, 2, 3, 0x2D, 0x2D, 0xFF8040, 0x8F1010);
        func_L07_003CB8D0(obj, 5);
        break;
    case 5:
        if (func_L07_003CD230(obj)) {
            if (*(s32 *)(p + 0x40C) != -1) func_L07_003CB8D0(obj, 0x18);
            else func_L07_003CB8D0(obj, 6);
        }
        break;
    case 6:
        if (!func_L07_003CD230(obj)) {
            func_L07_003CB8D0(obj, 5);
            break;
        }
        if (*(s32 *)(p + 0x40C) != -1) {
            func_L07_003CB8D0(obj, 0x18);
            break;
        }
        r = func_L07_003CBFE0(obj, 0);
        if (r != -1) {
            p[0x405] = 1;
            p[0x404] = r;
            p[0x406] = 0;
            func_L07_003CBF20(obj);
        }
        break;
    case 7:
        func_L07_003CBC90(obj, 6.0f);
        break;
    case 8:
        func_L07_003CBC90(obj, 10.0f);
        break;
    case 9:
        func_L07_003CBBF8(obj);
        if (obj[0x60] & 2) func_L07_003CB8D0(obj, 0xA);
        break;
    case 10:
        if (!func_L07_003CD230(obj)) func_L07_003CB8D0(obj, 5);
        else func_L07_003CBC90(obj, -1.0f);
        break;
    case 11:
        if (obj[0x60] & 2) func_L07_003CB8D0(obj, p[0x404] + 0xC);
        break;
    case 12:
        if (p[0x406] == 0) {
            f32 d12 = func_L01_00436500(obj);
            if (d12 >= 14.0f && d12 <= 24.0f) func_L07_003CC430(obj);
        }
        func_L07_003CC268(obj);
        break;
    case 13:
        if (p[0x406] == 0) {
            f32 d13 = func_L01_00436500(obj);
            if (d13 >= 12.0f && d13 <= 20.0f) func_L07_003CC528(obj);
        }
        func_L07_003CC268(obj);
        break;
    case 14:
        if (p[0x406] == 0) {
            f32 d14 = func_L01_00436500(obj);
            if (d14 >= 15.0f && d14 <= 21.0f) func_L07_003CC668(obj);
        }
        func_L07_003CC268(obj);
        break;
    case 15:
        if (p[0x406] == 0) {
            f32 d15 = func_L01_00436500(obj);
            if (d15 >= 22.0f && d15 <= 26.0f) func_L07_003CC668(obj);
        }
        func_L07_003CBDC8(obj, 0xD, 0, 1, func_L01_00436500(obj), 1.5f, 3.5f, 8.0f, 24.0f, 16.0f);
        func_L07_003CC268(obj);
        break;
    case 16:
        p[0x430] = 0;
        func_L07_003CBDC8(obj, 0xD, 0, 1, func_L01_00436500(obj), 1.5f, 3.5f, 8.0f, 24.0f, 16.0f);
        func_L07_003CC268(obj);
        break;
    case 17:
        if (func_L01_0044AF40(obj, 14.0f)) {
            if (obj[0x42] == 0xE) {
                V4_003CC2B0 *pv = &v20;
                V4_003CC2B0 *pd;
                func_003C2F58(obj, 4, pv);
                pd = &d10;
                vec_sub_ab(&d10, p + 0x130, &v20);
                func_0038CF68(pd, pd, 0.4166667f);
                func_L06_003577D0(obj, pd, pv, obj + 0xF0, 1, 0, (f32)p[0x45]);
            }
        }
        func_L07_003CC268(obj);
        break;
    case 18:
        func_L07_003CBDC8(obj, 8, 1, 1, func_L01_00436500(obj), 1.8f, 3.0f, 7.0f, 23.0f, 16.0f);
        func_L07_003CC3A8(obj);
        break;
    case 19:
        func_L07_003CBDC8(obj, 7, 1, -1, func_L01_00436500(obj), 1.8f, 3.0f, 7.0f, 23.0f, 16.0f);
        func_L07_003CC3A8(obj);
        break;
    case 20:
        func_L07_003CBDC8(obj, 9, 0, -1, func_L01_00436500(obj), 1.5f, 3.0f, 8.0f, 24.0f, 16.0f);
        func_L07_003CC3A8(obj);
        break;
    case 21:
    case 22:
    case 23:
        func_L07_003CC3F8(obj);
        break;
    case 24:
        t = (u8 *)(D_L07_001DF500 + (*(s32 *)(p + 0x40C) << 7));
        if (*(s16 *)(p + 0x144) != 1) func_L07_003CB8D0(obj, 5);
        t += 0x30;
        dist = func_0038CF38(obj + 0x10, t);
        if (dist <= 1.0f) {
            ang = func_0038D160(*(f32 *)(p + 0x130) - *(f32 *)(obj + 0x10), *(f32 *)(p + 0x134) - *(f32 *)(obj + 0x14));
            if (func_0038DBA0(*(f32 *)(obj + 0xF8), ang) < 0.43633232f || obj[0x42] == 0xE) {
                if (obj[0x43] != 0xE) func_003C3A10(obj, 0xE, 0, 0xF);
                if (func_L01_0044AF40(obj, 14.0f) && obj[0x42] == 0xE) {
                    V4_003CC2B0 *pv = &v20;
                    V4_003CC2B0 *pd;
                    func_003C2F58(obj, 4, pv);
                    pd = &d10;
                    vec_sub_ab(&d10, p + 0x130, &v20);
                    func_0038CF68(pd, pd, 0.4166667f);
                    func_L06_003577D0(obj, pd, pv, obj + 0xF0, 1, 0, 1.0f);
                }
                if (obj[0x60] & 2) {
                    if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 10);
                }
            } else {
                if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 10);
                {
                    u8 *tgt = *(u8 **)(p + 0x140);
                    ang = func_0038D160(*(f32 *)(tgt + 0x10) - *(f32 *)(obj + 0x10), *(f32 *)(tgt + 0x14) - *(f32 *)(obj + 0x14));
                }
                func_L01_00458A08(obj, ang);
            }
        } else {
            if (obj[0x43] != 3) func_003C3A10(obj, 3, 0, 10);
            func_L01_00457440(obj, t);
        }
        break;
    default:
        break;
    }
}
/* localdecomp:end func_U_L07_003CA8B0 */
