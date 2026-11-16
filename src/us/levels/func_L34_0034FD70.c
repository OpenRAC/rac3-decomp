#include "common.h"

/* NTSC-U counterpart of func_L34_00350A90 (src/levels/34_vidcomic_3/L34_00350A90.c) */
/* localdecomp:start func_L34_0034FD70 */
typedef struct { s32 a; s32 b; } E_00350A90;
typedef struct { E_00350A90 e[14]; s32 f70; s32 t74; s32 c78; s32 i7C; f32 f80; s32 m84; } V_00350A90;
extern u8 D_001A4BE0[];
extern void func_L34_00350060(u8 *);
extern f32 func_00388800(void *, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_00388398(void *);
extern s32 func_L34_00350880(s32, s32);

void func_L34_0034FD70(u8 *o) {
    V_00350A90 *v = *(V_00350A90 **)(o + 0x68);
    f32 d;
    s32 in;
    u8 *r;
    s32 t;
    u8 *h;

    func_L34_00350060(o);
    d = func_00388800(o + 0x10, D_001A4BE0 + 0x80);
    h = D_001A4BE0;
    in = 0;
    if (*(f32 *)(h + 0x88) > 83.0f && *(f32 *)(h + 0x88) < 100.0f &&
        *(f32 *)(h + 0x80) > 108.0f && *(f32 *)(h + 0x80) < 120.0f) {
        in = 1;
    }
    switch (o[0x20]) {
    case 0:
        func_L01_00441FB8(o, 1, -1);
        break;
    case 1:
        if (in) {
            break;
        }
        func_0039FE80(0, 0, o);
        v->c78 = v->e[0].a;
        if (o[0x43] != 1) {
            func_003BE4F0(o, 1, 0, 7);
        }
        func_L01_00441FB8(o, 2, -1);
        break;
    case 2:
        if (func_00388398(&v->t74)) {
            r = (u8 *)func_L34_00350880((s32)o, 0);
            if (r != 0) {
                r = *(u8 **)(r + 0x68);
                *(f32 *)(r + 0xC) = v->f80;
                if (v->m84 != 0) {
                    *(s32 *)r = v->m84;
                }
            }
            t = v->c78 - 1;
            v->c78 = t;
            if (t < 0) {
                v->c78 = 0;
            }
            v->t74 = 0xF;
        }
        if (v->c78 == 0) {
            v->t74 = v->e[v->i7C].b;
            v->i7C += 1;
            if (v->e[v->i7C].a == 0) {
                v->i7C = 0;
            }
            v->c78 = v->e[v->i7C].a;
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 3:
        if (in) {
            func_L01_00441FB8(o, 1, -1);
        }
        if (*(u16 *)(o + 0x96) >= 0x1F && o[0x43] != 0) {
            func_0039FE80(1, 0, o);
            if (o[0x43] != 0) {
                func_003BE4F0(o, 0, 0, 7);
            }
        }
        if (func_00388398(&v->t74) && d > 5.0f) {
            func_0039FE80(0, 0, o);
            if (o[0x43] != 1) {
                func_003BE4F0(o, 1, 0, 7);
            }
            func_L01_00441FB8(o, 2, -1);
        }
        break;
    }
}
/* localdecomp:end func_L34_0034FD70 */
