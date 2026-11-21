#include "common.h"

/* localdecomp:start func_L07_003DC598 */
extern void func_0038CC88(void *, void *, s32);
extern f32 func_003C4088(f32, f32, f32);
extern int func_L01_00448070(int, int, f32);

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
    u8 pad[8];
} S_3DC598;

void func_L07_003DC598(S_3DC598 *dst, S_3DC598 *a, S_3DC598 *b, f32 t) {
    if (a == b || t <= 0.0f) {
        func_0038CC88(dst, a, 0x20);
    } else if (t >= 1.0f) {
        func_0038CC88(dst, b, 0x20);
    } else {
        dst->f0 = func_003C4088(a->f0, b->f0, t);
        dst->f4 = func_003C4088(a->f4, b->f4, t);
        dst->f8 = func_003C4088(a->f8, b->f8, t);
        dst->fC = func_003C4088(a->fC, b->fC, t);
        dst->f10 = func_003C4088(a->f10, b->f10, t);
        dst->b14 = func_L01_00448070(a->b14, b->b14, t);
        dst->b15 = func_L01_00448070(a->b15, b->b15, t);
        dst->b16 = func_L01_00448070(a->b16, b->b16, t);
        dst->b17 = func_L01_00448070(a->b17, b->b17, t);
    }
}
/* localdecomp:end func_L07_003DC598 */

/* localdecomp:start func_L07_003DC6E8 */
typedef int Q_003DC6E8 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0xE0];
    Q_003DC6E8 position;
    u8 padF0[0x25C0 - 0xF0];
    void *moby;
} Hero_003DC6E8;
typedef struct { u8 pad0[0x68]; u8 *vars; u8 pad6C[0xB8 - 0x6C]; u8 *owner; } Moby_003DC6E8;
extern u8 *D_L07_0021C460[];
extern Hero_003DC6E8 D_001A4BE0;
void func_L07_003DC6E8(Moby_003DC6E8 *moby)
{
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L07_003DC790(Moby_003DC6E8 *, void *, Q_003DC6E8 *, f32);
    u8 *vars = moby->vars;
    f32 radius = func_L01_0040E548(vars, vars + 0x70);
    s32 index;
    u8 *other;
    Q_003DC6E8 position;
    for (index = 0; (other = D_L07_0021C460[index]) != 0; index++) {
        if (other != moby->owner) {
            position = *(Q_003DC6E8 *)(other + 0x10);
            func_L07_003DC790(moby, other, &position, radius);
        }
    }
    position = D_001A4BE0.position;
    func_L07_003DC790(moby, D_001A4BE0.moby, &position, radius);
}
/* localdecomp:end func_L07_003DC6E8 */

INCLUDE_ASM("asm/levels", func_L07_003DC790);

INCLUDE_ASM("asm/levels", func_L07_003DC940);
