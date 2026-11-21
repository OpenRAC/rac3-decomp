#include "common.h"

/* NTSC-U counterpart of func_L03_0039AFF0 (src/levels/shared/L03_0039AFF0.c): 0.012 -> 0.01 */
/* localdecomp:start func_L03_003998F0 */
typedef struct {
    u8 pad0[8];
    f32 x8;
} M_0039AFF0;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x68 - 0x21];
    M_0039AFF0 *x68;
    u8 pad6C[0xF4 - 0x6C];
    f32 xF4;
} O_0039AFF0;

extern void func_L03_00399B48(void *);
extern s32 func_L03_00399B80(void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003BE6A8(f32, f32, f32);

void func_L03_003998F0(O_0039AFF0 *o) {
    M_0039AFF0 *m;

    func_L03_00399B48(o);
    m = o->x68;
    switch (o->b20) {
    case 1:
        m->x8 += 0.00999999978f;
        if (1.0f <= m->x8) {
            func_L01_004A6D70(0, o);
            m->x8 = 1.0f;
            func_L01_00441FB8(o, 2, -1);
        }
        o->xF4 = func_003BE6A8(0.0f, 0.87266463f, m->x8);
        if (func_L03_00399B80(o) == 0) {
            func_L01_004A6D70(0, o);
            func_L01_004A72A8(1, 4, o, 0x1910);
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 2:
        if (func_L03_00399B80(o) == 0) {
            func_L01_004A6D70(0, o);
            func_L01_004A72A8(1, 4, o, 0x1910);
            func_L01_00441FB8(o, 3, -1);
        }
        break;
    case 3:
        m->x8 -= 0.00999999978f;
        if (m->x8 <= 0.0f) {
            func_L01_004A6D70(1, o);
            m->x8 = 0.0f;
            func_L01_00441FB8(o, 4, -1);
        }
        o->xF4 = func_003BE6A8(0.0f, 0.87266463f, m->x8);
        if (func_L03_00399B80(o) != 0) {
            func_L01_004A6D70(1, o);
            func_L01_004A72A8(0, 4, o, 0x1910);
            func_L01_00441FB8(o, 1, -1);
        }
        break;
    case 4:
        if (func_L03_00399B80(o) != 0) {
            func_L01_004A72A8(0, 4, o, 0x1910);
            func_L01_00441FB8(o, 1, -1);
        }
        break;
    case 5:
        m->x8 -= 0.00999999978f;
        if (m->x8 <= 0.0f) {
            m->x8 = 0.0f;
            func_L01_00441FB8(o, 6, -1);
        }
        o->xF4 = func_003BE6A8(0.0f, 0.87266463f, m->x8);
        break;
    case 6:
        break;
    }
}
/* localdecomp:end func_L03_003998F0 */
