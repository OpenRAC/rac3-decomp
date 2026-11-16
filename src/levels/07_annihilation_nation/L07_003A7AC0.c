#include "common.h"

/* localdecomp:start func_L07_003A7AC0 */
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    u8 b14;
    u8 b15;
    u8 b16;
    u8 b17;
} S_003A7AC0;

extern void func_0038CC88(void *, void *, s32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_00448070(s32, s32, f32);

void func_L07_003A7AC0(S_003A7AC0 *dst, S_003A7AC0 *p, S_003A7AC0 *q, f32 t)
{
    if (p == q || t <= 0.0f) {
        func_0038CC88(dst, p, 0x20);
    } else if (t >= 1.0f) {
        func_0038CC88(dst, q, 0x20);
    } else {
        dst->f0 = func_003C4088(p->f0, q->f0, t);
        dst->f4 = func_003C4088(p->f4, q->f4, t);
        dst->f8 = func_003C4088(p->f8, q->f8, t);
        dst->fC = func_003C4088(p->fC, q->fC, t);
        dst->f10 = func_003C4088(p->f10, q->f10, t);
        dst->b14 = func_L01_00448070(p->b14, q->b14, t);
        dst->b15 = func_L01_00448070(p->b15, q->b15, t);
        dst->b16 = func_L01_00448070(p->b16, q->b16, t);
        dst->b17 = func_L01_00448070(p->b17, q->b17, t);
    }
}
/* localdecomp:end func_L07_003A7AC0 */

/* localdecomp:start func_L07_003A7C10 */
typedef int Q_003A7C10 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0xE0];
    Q_003A7C10 position;
    u8 padF0[0x25C0 - 0xF0];
    void *moby;
} Hero_003A7C10;
typedef struct { u8 pad0[0x68]; u8 *vars; u8 pad6C[0xB8 - 0x6C]; u8 *owner; } Moby_003A7C10;
extern u8 *D_L07_0021C460[];
extern Hero_003A7C10 D_001A4BE0;
void func_L07_003A7C10(Moby_003A7C10 *moby)
{
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L07_003A7CB8(Moby_003A7C10 *, void *, Q_003A7C10 *, f32);
    u8 *vars = moby->vars;
    f32 radius = func_L01_0040E548(vars, vars + 0x130);
    s32 index;
    u8 *other;
    Q_003A7C10 position;
    for (index = 0; (other = D_L07_0021C460[index]) != 0; index++) {
        if (other != moby->owner) {
            position = *(Q_003A7C10 *)(other + 0x10);
            func_L07_003A7CB8(moby, other, &position, radius);
        }
    }
    position = D_001A4BE0.position;
    func_L07_003A7CB8(moby, D_001A4BE0.moby, &position, radius);
}
/* localdecomp:end func_L07_003A7C10 */

INCLUDE_ASM("asm/levels", func_L07_003A7CB8);

INCLUDE_ASM("asm/levels", func_L07_003A7E88);
