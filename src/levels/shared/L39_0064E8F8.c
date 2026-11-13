#include "common.h"

/* localdecomp:start func_L39_0064E8F8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x10];
    u128_t q10;
    u8 p20[3];
    u8 b23;
    u8 p24[0xC];
    u8 b30;
    u8 b31;
    u16 h32;
    u16 h34;
    u8 p36[0xBA];
    u128_t qF0;
} O_0064E8F8;
typedef struct {
    u8 p0[0xA0];
    u128_t qA0;
    u128_t qB0;
    u8 pC0[0x60];
    u8 b120[8];
    s32 w128;
    u8 p12C[0x12C8];
    O_0064E8F8 *obj;
    u8 p13F8[0x112C];
    O_0064E8F8 *src;
} S_0064E8F8;

extern O_0064E8F8 *func_003C24B0(s32, s32);
extern void func_003C7C38(O_0064E8F8 *);
extern s32 func_L39_005F33E0(s32, s32, u8 *);
extern f32 func_0038CED8(void *);
extern s32 func_L01_0040E728(void *, void *, f32);
extern void func_L39_006378B0(S_0064E8F8 *);

void func_L39_0064E8F8(S_0064E8F8 *p)
{
    u8 *s;

    if (p->obj == 0) {
        p->obj = func_003C24B0(0x52A, 0x80);
        if (p->obj != 0) {
            p->obj->q10 = p->qA0;
            p->obj->qF0 = p->qB0;
            p->obj->h32 = 0x40;
            p->obj->b31 = 1;
            p->obj->b30 = 0;
            p->obj->b23 = 0;
            p->obj->h34 |= 0x800;
            func_003C7C38(p->obj);
            func_L39_005F33E0(0, 0, (u8 *)p->obj);
        }
    }
    if (p->obj != 0) {
        p->obj->b23 += 6;
        if (p->obj->b23 > 0x80) {
            p->obj->b23 = 0x80;
        }
        p->obj->q10 = p->src->q10;
        p->obj->qF0 = p->src->qF0;
        func_003C7C38(p->obj);
    }
    s = p->b120;
    p->w128 = 0;
    func_L01_0040E728(s, s, func_0038CED8(s) * 0.90400004f);
    func_L39_006378B0(p);
}
/* localdecomp:end func_L39_0064E8F8 */
