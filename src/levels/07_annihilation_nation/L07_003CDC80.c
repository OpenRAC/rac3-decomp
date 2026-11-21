#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

/* declared by functions of L07_003CC2B0.c, which this file was cut from */
void func_L07_003CD2E8(void *, s32);
extern void func_L07_003CD2E8(void *, s32);
extern void func_L07_003CD2E8(void *, int);

/* localdecomp:start func_L07_003CDC80 */
extern f32 func_0038D160(f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_L07_003CD2E8(void *, s32);
extern void func_L07_003CD938(void *);
extern s32 func_L07_003CD9F8(void *, s32);
extern void func_L07_003CE940(void *);
extern s32 func_L07_003CDB30(void *);

void func_L07_003CDC80(u8 *a0) {
    u8 *q = a0 + 0xF8;
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 ang;
    f32 t;
    s32 r;

    ang = func_0038D160(*(f32 *)(p + 0x130) - *(f32 *)(a0 + 0x10),
                        *(f32 *)(p + 0x134) - *(f32 *)(a0 + 0x14));
    func_L01_00448890(q, p + 0x204, 0, ang,
                      *(f32 *)(p + 0x164), *(f32 *)(p + 0x168),
                      *(f32 *)(p + 0x16C));
    if (a0[0x60] & 2) {
        p[0x407] = 0;
        if (a0[0x20] == 0x10) {
            func_L07_003CD938(a0);
            return;
        }
        r = -1;
        p[0x405] = p[0x405] + 1;
        if (p[0x406] == 0) {
            t = func_003824E0(0.0f, 1.0f);
            if (t < 0.7f) {
                r = func_L07_003CD9F8(a0, 1);
            }
        }
        if (r == -1) {
            func_L07_003CE940(a0);
            if (func_L07_003CDB30(a0) == 0) {
                func_L07_003CD2E8(a0, 6);
            }
        } else {
            p[0x404] = r;
            func_L07_003CD2E8(a0, r + 0xC);
        }
    }
}
/* localdecomp:end func_L07_003CDC80 */
