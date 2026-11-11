#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 x0;
    u8 x1;
    u8 x2;
    u8 x3;
    u32 color;
    u8 x8;
    u8 x9;
    u8 padA[2];
    f32 xC;
    u128_t pos;
    s32 count;
    f32 step;
} Fx_4450E0;

/* localdecomp:start func_L23_004450E0 */
extern Fx_4450E0 *func_L01_004618E0(s32);
extern u8 *D_L23_0021ED6C[];

void func_L23_004450E0(u128_t *pos, u8 r, u8 g, u8 b, s32 count, f32 total, f32 size) {
    Fx_4450E0 *o;

    if (count == 0) {
        return;
    }
    o = func_L01_004618E0(5);
    if (o == 0) {
        return;
    }
    o->pos = *pos;
    o->color = 0x7F000000 | (b << 16) | (g << 8) | r;
    o->x9 = 0xA4;
    o->x3 = 0x48;
    o->xC = size;
    o->x1 = 0;
    o->x8 = 0;
    o->x2 = *D_L23_0021ED6C[0];
    o->count = count;
    o->step = total / (f32)count;
}
/* localdecomp:end func_L23_004450E0 */
