/* near miss (level 5, Daxx): 2 differences: needs the divs_nops row "func_L05_003DC5B8 2"; func_L01_00451FE0 declared with the parameter order other files already use fixes the first call; left: in the second call retail stores the stack argument 0x608020 (sw $a0,0x40($sp)) before lui $v0,0x100, ours the reverse (a scheduler tie; 512 prototype orders of func_L01_003303B8 and about 20 wordings tried) */
#include "common.h"

/* localdecomp:start func_L05_003DC5B8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_3DC5B8;

typedef struct {
    char pad0[0x24];
    float f24;
} P_3DC5B8;

typedef struct {
    char pad0[0x10];
    V4_3DC5B8 f10;
    u8 f20;
    char pad1[3];
    P_3DC5B8 *f24;
    char pad2[4];
    float f2C;
    char pad3[0x96 - 0x30];
    u16 f96;
} S_3DC5B8;

extern u8 D_L05_001D66B0[8];
__asm__(".extern D_L05_001D66B0, 16");
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_L05_003DC520(void *, s32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L05_003DC5B8(S_3DC5B8 *p, s32 a, s32 b, f32 c) {
    V4_3DC5B8 tmp;
    f32 d;

    func_003A52A0(0, 0, p);
    func_L01_00451FE0(p, a, D_L05_001D66B0, 4.0f, 6.0f, 7.0f, 9.0f, 255, -1.0f, -1.0f, 180, 0, 0, 35, 1.0f, 1.0f, 0, 3);
    if (b != 0) {
        func_L05_003DC520(p, b);
    }
    d = p->f2C / p->f24->f24;
    tmp = p->f10;
    tmp.z = tmp.z + d * 7.5f;
    func_L01_003303B8(&tmp, 1, 0xF, 0, 0, 2, 5, 2, d * 4.0f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 1, 0, 0x1000000, 0, 0x608020, 0x808020, 0x204080, 0x203080, 0, 0, 0x80408020, 0x28001080, 0x808020, 0);
    func_L01_00451E78(p, 1, 0.0f);
}
/* localdecomp:end func_L05_003DC5B8 */
