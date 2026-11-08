/* near miss (level 3, Starship Phoenix): 10 differences, only reachable with @ps2as (L03_003A20E0.c has none; 131 diff with the default assembler): retail has i in $s5 and a in $s6, the C the other way round, rippling through the lw/lq operands and the bgez, and orders addiu $t3,1 and mov.s $f14,$f21 the other way; do-while, a local copy of a, declaring i first and a per-iteration pointer tried */
#include "common.h"

/* localdecomp:start func_L03_003A2790 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A2790;
typedef struct { u8 pad[0x68]; f32 *p68; } S_003A2790;
typedef struct { u8 pad[0xE0]; V4_003A2790 v; } A_003A2790;
typedef struct { u8 pad0[0x25C0]; void *q; } H_003A2790;
typedef struct { u8 pad[0xD4]; u8 *p; } G_003A2790;
extern H_003A2790 D_001A4BE0_003A2790;
extern G_003A2790 D_L03_0021F298_003A2790;
extern u8 D_L03_002A1420_003A2790[];
__asm__(".extern D_001A4BE0_003A2790, 16");
__asm__(".extern D_L03_0021F298_003A2790, 16");
__asm__(".extern D_L03_002A1420_003A2790, 16");
void func_L02_003BAFA0(f32, void *, void *, void *, s32);
void func_0038CF68(V4_003A2790 *, V4_003A2790 *, f32);
f32 func_L01_00443A18(f32, f32);
f32 func_003824E0(f32, f32);
s32 func_00382498(s32, s32);
u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L03_003A2790(A_003A2790 *a, s32 *b) {
    char buf[0x10];
    V4_003A2790 vec;
    f32 *p = *(f32 **)((u8 *)a + 0x68);
    s32 i;
    for (i = 23; i >= 0; i--) {
        s32 h;
        f32 f;
        u8 *r;
        func_L02_003BAFA0(0.0f, D_001A4BE0_003A2790.q, D_L03_002A1420_003A2790, buf, 0);
        vec = a->v;
        func_0038CF68(&vec, &vec, p[4] * 0.040000003f);
        h = (s32)func_L01_00443A18(2.0f, 5.0f);
        f = func_003824E0(0.05f, 0.1f);
        func_L01_004713C8(buf, &vec, (s32)((f32)((func_00382498(20, 25) * 5 + 2) / 6) * p[4]), b[0], h, 0x7F, 0x7F, 1, f * 210000.0f, 2100.0f, -0.0012f);
        h = -(h * 2);
        r = func_L01_004713C8(buf, &vec, (s32)((f32)((func_00382498(20, 25) * 5 + 2) / 6) * p[4]), b[1], h, 0x30, 0x30, 0, (f *= 4.0f) * 210000.0f, 4200.0f, -0.0012f);
        if (r) r[2] = *D_L03_0021F298_003A2790.p;
    }
    p[4] = p[4] + 0.035000004f;
    if (p[4] > 1.0f) p[4] = 1.0f;
}
/* localdecomp:end func_L03_003A2790 */
