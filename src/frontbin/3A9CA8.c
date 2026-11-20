#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A9CA8 */
extern u8 D_001D8064;
void func_003A9CA8(u8 a) { D_001D8064 = a; }
/* localdecomp:end func_003A9CA8 */

/* localdecomp:start func_003A9CB0 */
extern u8 D_001D8064;
u8 func_003A9CB0(void) {
    return D_001D8064;
}
/* localdecomp:end func_003A9CB0 */

/* localdecomp:start func_003A9CB8 */
#include "vu0.h"

typedef struct {
    unsigned long x0;
    s16 x8;
    s16 xA;
    s16 xC;
    s16 xE;
} R_003A9CB8;

typedef struct {
    s32 w[4];
} W_003A9CB8;

typedef struct {
    u8 p0[6];
    s16 n;
    u8 p8[4];
    f32 fC;
    u32 x10;
    u32 x14;
    u32 x18;
    u32 x1C;
    u32 x20;
} H_003A9CB8;

/* from rac2-decomp's func_00300618 */
H_003A9CB8 *func_003A9CB8(H_003A9CB8 *h) {
    u32 base = (u32)h;
    W_003A9CB8 *src;
    s32 i;
    h->x10 += base;
    h->x14 += base;
    h->x18 += base;
    h->x1C += base;
    if (h->x20 != 0) h->x20 += base;
    i = 0;
    src = (W_003A9CB8 *)h->x18;
    h->fC *= 0.0032116016f;
    if (h->n > 0) {
        do {
            s32 a = src->w[0];
            s32 b = src->w[1];
            s32 c = src->w[2];
            s32 d = src->w[3];
            ((R_003A9CB8 *)h->x18)[i].xA = a >> 4;
            src++;
            ((R_003A9CB8 *)h->x18)[i].x8 = b >> 4;
            ((R_003A9CB8 *)h->x18)[i].xC = 30 - plzcw_asm(c);
            ((R_003A9CB8 *)h->x18)[i].xE = 30 - plzcw_asm(d);
            ((R_003A9CB8 *)h->x18)[i].x0 = 0;
            i++;
        } while (i < h->n);
    }
    return h;
}
/* localdecomp:end func_003A9CB8 */
