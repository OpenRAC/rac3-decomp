/* NTSC-U draft (2026-11-14, Claude worker): C of func_L03_003998F0, the NTSC-U twin of func_L03_0039AFF0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L03_0039AA48.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L03_0039AFF0 (src/levels/shared/...) */
/* localdecomp:start func_L03_003998F0 */
typedef struct {
    u8 pad0[8];
    f32 x8;
} M_003998F0;

typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x68 - 0x21];
    M_003998F0 *x68;
    u8 pad6C[0xF4 - 0x6C];
    f32 xF4;
} O_003998F0;

extern void func_L03_00399B48(void *);
extern s32 func_L03_00399B80(void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003BE6A8(f32, f32, f32);

void func_L03_003998F0(O_003998F0 *o) {
    M_003998F0 *m;
    f32 t;

    func_L03_00399B48(o);
    m = o->x68;
    switch (o->b20) {
    case 1:
        t = m->x8 + 0.01f;
        m->x8 = t;
        if (1.0f <= t) {
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
        t = m->x8 - 0.01f;
        m->x8 = t;
        if (t <= 0.0f) {
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
        t = m->x8 - 0.01f;
        m->x8 = t;
        if (t <= 0.0f) {
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
