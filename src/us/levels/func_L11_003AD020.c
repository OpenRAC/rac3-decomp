#include "common.h"

/* NTSC-U counterpart of func_L11_003AEDE8 (src/levels/11_obani_moons/L11_003AE1B0.c): 4 -> 5; 0.04 -> 0.0333333 */
#include "vu0.h"
extern u8 D_001A30B0[];
extern void func_0039FB08(s32);
extern void func_003BD360(void *);
extern s32 D_L11_001E1020_003AD020[12] __attribute__((section(".sdata")));
extern void func_L01_0044E010(void *, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L11_003AD8F0(u8 *);

/* localdecomp:start func_L11_003AD020 */
typedef struct {
    vu0_v4 f0;
    s32 f10;
    s32 f14;
    f32 f18;
    s32 f1C;
    u8 pad20[0x2C - 0x20];
    s32 f2C;
    u8 pad30[0x40 - 0x30];
    s32 f40;
    s32 f44;
} V_3AEDE8;
extern s32 D_L11_001E1020_003AD020[12] __attribute__((section(".sdata")));
extern u8 D_001A30B0[];
extern void func_L01_004C4AD8(s32, void *, s32);
extern s32 func_00388398(void *);
extern void func_L01_004C4AB8(s32);
extern void func_0039FB08(s32);
extern void func_003BD360(void *);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L01_0044E010(void *, void *, s32);
extern s32 func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern u8 *func_0037E0B8(s32);
extern s32 func_L03_004307B8(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L11_003AD8F0(u8 *);
extern void func_L11_003ADF58(u8 *);
extern void func_L11_003AE170(u8 *);
extern void func_L11_003AD290(u8 *);
extern void func_L01_00402498(void *, void *);

void func_L11_003AD020(u8 *m)
{
    V_3AEDE8 *v = *(V_3AEDE8 **)(m + 0x68);
    vu0_v4 mtx;
    vu0_v4 dir;
    vu0_v4 a;
    vu0_v4 b;
    s32 idx;
    u8 *e;
    u8 *p;
    f32 s;
    f32 t;

    func_L01_004C4AD8(v->f10, v, 0);
    vec_add_ab(m + 0x10, m + 0x10, v);
    if (func_00388398(&v->f14) != 0) {
        func_L01_004C4AB8(v->f10);
        D_L11_001E1020_003AD020[v->f40] = 0;
        idx = v->f44;
        if (idx != -1) {
            e = D_001A30B0 + (idx << 7);
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_0039FB08(idx);
            }
        }
        v->f44 = -1;
        func_003BD360(m);
        return;
    }
    if (v->f44 == -1) {
        goto spawn;
    }
    e = D_001A30B0 + (v->f44 << 7);
    if (*(u8 **)(e + 0xDC) != m || e[0xD0] == 0) {
spawn:
        v->f44 = func_L01_004A72A8(7, 4, m, 0x1BF6);
    }
    s = 1.0f;
    func_L01_0044E010(m, &mtx, 1);
    func_00388758(&dir, &mtx, v);
    func_00388830(&a, &dir, v->f18);
    vec_add_ba(&a, &a, m + 0x10);
    func_00388830(&b, &dir, -v->f18);
    vec_add_ab(&b, &b, m + 0x10);
    p = func_0037E0B8(*(s32 *)(m + 0xB8));
    if (p != 0) {
        s = (f32)p[0x14];
    }
    func_L03_004307B8(m, &a, &b, 1, 0, 1, 0, s, 0.0f);
    if (v->f1C == 0) {
        v->f2C = 5;
        func_L11_003AD8F0(m);
    }
    func_L11_003ADF58(m);
    func_L01_00402498(func_L11_003AE170, m);
    func_L01_00402498(func_L11_003AD290, m);
    t = v->f18 + 0.0333333351f;
    v->f18 = t;
    if (1.5f < t) {
        v->f18 = 1.5f;
    }
}
/* localdecomp:end func_L11_003AD020 */
