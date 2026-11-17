#include "common.h"

/* localdecomp:start func_L39_006A0AC0 */
typedef struct W_006A0AC0 W_006A0AC0;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(W_006A0AC0 *, s32, s32);
    u8 pad20[4];
    void (*f24)(W_006A0AC0 *, void *);
} VT_006A0AC0;
struct W_006A0AC0 {
    u8 pad0[0x60];
    VT_006A0AC0 *vt;
};
typedef struct {
    u8 pad0[4];
    s32 state;
} T_006A0AC0;
typedef struct {
    u8 pad0[0x110];
    W_006A0AC0 *w110;
    W_006A0AC0 *w114;
    u8 pad118[4];
    T_006A0AC0 *t11C;
    u8 pad120[4];
    T_006A0AC0 *t124;
    T_006A0AC0 *t128;
} S_006A0AC0;
extern u8 D_00248568[];
extern void func_L39_0067F100(s32);
extern void func_L39_0068AAB8(S_006A0AC0 *);
extern void func_L39_0068B2F8(S_006A0AC0 *, s32, s32);
void func_L39_006A0AC0(S_006A0AC0 *a0)
{
    func_L39_0067F100(0x2F0000);
    func_L39_0068AAB8(a0);
    a0->w110->vt->f24(a0->w110, D_00248568);
    a0->w110->vt->f1C(a0->w110, 2, 0);
    a0->w114->vt->f24(a0->w114, D_00248568);
    a0->w114->vt->f1C(a0->w114, 2, 0);
    if (a0->t11C->state == 3) func_L39_0068B2F8(a0, 3, 0);
    if (a0->t124->state == 3) func_L39_0068B2F8(a0, 5, 0);
    if (a0->t128->state == 3) func_L39_0068B2F8(a0, 6, 0);
}
/* localdecomp:end func_L39_006A0AC0 */

/* localdecomp:start func_L39_006A0BC8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006A0BC8(void *);

extern void func_L39_0067F168();
void func_L39_006A0BC8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006A0BC8 */
