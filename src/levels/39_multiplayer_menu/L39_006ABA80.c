#include "common.h"

/* localdecomp:start func_L39_006ABA80 */
extern void func_0011D534(void *, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005170B8(s32, s32);

typedef struct V_006ABA80 V_006ABA80;
typedef struct O_006ABA80 {
    u8 pad[0x60];
    V_006ABA80 *vt;
} O_006ABA80;
struct V_006ABA80 {
    u8 pad[0x58];
    s32 (*f58)(O_006ABA80 *, f32 *);
};

typedef struct P_006ABA80 {
    u8 pad0[0x114];
    O_006ABA80 *obj;
    u8 pad118[0x1B0];
    u8 buf[0xC8];
    s32 idx;
    u8 pad394[4];
    s32 timer;
    u8 pad39C[0x10];
    s32 text;
} P_006ABA80;

void func_L39_006ABA80(P_006ABA80 *p) {
    f32 r[4];
    f32 x;
    f32 y;
    s32 color;

    if (p->idx < 199 && p->text >= 0) {
        color = 0x8066CCFF;
        if (p->timer % 37 >= 18) {
            color = 0x66CCFF;
        }
        func_0011D534(r, 0, 16);
        if (p->obj->vt->f58(p->obj, r)) {
            x = r[2] + 0.01f;
            y = (r[1] + r[3]) * 0.5f;
            if (p->idx > 0 && p->buf[p->idx - 1] == ' ') {
                x += 0.02f;
            }
        } else {
            x = 0.2f;
            y = 0.555f;
        }
        func_L01_00516470(p->text, x, y);
        func_L01_00517538(p->text, 0.005f, 0.034f);
        func_L01_005170B8(p->text, color);
    }
}
/* localdecomp:end func_L39_006ABA80 */
