#include "common.h"

/* localdecomp:start func_L03_0039AFF0 */
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

extern void func_L03_0039B248(void *);
extern s32 func_L03_0039B280(void *);
extern void func_L01_004AA760(s32, void *);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C3BE8(f32, f32, f32);

void func_L03_0039AFF0(O_0039AFF0 *o) {
    M_0039AFF0 *m;

    func_L03_0039B248(o);
    m = o->x68;
    switch (o->b20) {
    case 1:
        m->x8 += 0.012f;
        if (1.0f <= m->x8) {
            func_L01_004AA760(0, o);
            m->x8 = 1.0f;
            func_L01_004450F0(o, 2, -1);
        }
        o->xF4 = func_003C3BE8(0.0f, 0.87266463f, m->x8);
        if (func_L03_0039B280(o) == 0) {
            func_L01_004AA760(0, o);
            func_L01_004AAC98(1, 4, o, 0x1910);
            func_L01_004450F0(o, 3, -1);
        }
        break;
    case 2:
        if (func_L03_0039B280(o) == 0) {
            func_L01_004AA760(0, o);
            func_L01_004AAC98(1, 4, o, 0x1910);
            func_L01_004450F0(o, 3, -1);
        }
        break;
    case 3:
        m->x8 -= 0.012f;
        if (m->x8 <= 0.0f) {
            func_L01_004AA760(1, o);
            m->x8 = 0.0f;
            func_L01_004450F0(o, 4, -1);
        }
        o->xF4 = func_003C3BE8(0.0f, 0.87266463f, m->x8);
        if (func_L03_0039B280(o) != 0) {
            func_L01_004AA760(1, o);
            func_L01_004AAC98(0, 4, o, 0x1910);
            func_L01_004450F0(o, 1, -1);
        }
        break;
    case 4:
        if (func_L03_0039B280(o) != 0) {
            func_L01_004AAC98(0, 4, o, 0x1910);
            func_L01_004450F0(o, 1, -1);
        }
        break;
    case 5:
        m->x8 -= 0.012f;
        if (m->x8 <= 0.0f) {
            m->x8 = 0.0f;
            func_L01_004450F0(o, 6, -1);
        }
        o->xF4 = func_003C3BE8(0.0f, 0.87266463f, m->x8);
        break;
    case 6:
        break;
    }
}
/* localdecomp:end func_L03_0039AFF0 */
