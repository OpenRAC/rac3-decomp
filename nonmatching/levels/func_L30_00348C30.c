/* NTSC-U draft (2026-11-14, Claude worker): C of func_L30_00347EC0, the NTSC-U twin of func_L30_00348C30, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 1 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L30_00347EC0 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_00347EC0 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00347EC0;

typedef struct C_00347EC0 {
    u8 pad00[0x1A];
    u16 h1A;
    u8 pad1C[0x14];
} C_00347EC0;

typedef struct M_00347EC0 {
    V_00347EC0 r[4];
} M_00347EC0;

extern u128_t D_L30_001E9020;
extern f32 D_L30_001DD348;
__asm__(".extern D_L30_001DD348, 4");
extern f32 D_001A4C64[];
extern void func_003BD9A0(void *, s32, void *);
extern void func_L30_00348780(void *, void *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004084B0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);

void func_L30_00347EC0(u8 *o) {
    V_00347EC0 a;
    V_00347EC0 b;
    C_00347EC0 c;
    M_00347EC0 m;
    V_00347EC0 d;
    V_00347EC0 e;
    s32 i;

    func_003BD9A0(o, 4, &m);
    b = m.r[3];
    func_L30_00348780(o, &a);
    func_L01_00443628(&c, o, 1, &a, 1.0f);
    c.h1A = *(u16 *)(o + 0xAA);
    func_00388830(&a, &a, D_L30_001DD348);
    vec_add_ab(&a, &a, &b);
    a.y = D_001A4C64[0];
    b.y = D_001A4C64[0];
    if (func_003CE740(&b, &a, 0, o, &c) != 0) {
        for (i = 0; i < 2; i++) {
            f32 f;
            *(u128_t *)&d = D_L30_001E9020;
            func_003BF6A8(&d, 0.3f);
            e.x = func_0037E250(0.0f, 0.016666668f);
            e.y = func_0037E250(0.0f, 0.016666668f);
            e.z = func_0037E250(0.033333335f, 0.116666675f);
            f = func_0037E250(0.25f, 1.25f);
            func_L01_0046C468(&d, &e, 0x2D, 0x808080, func_0037E208(0, 2) - 1, 0x60, 0, 0, f * 210000.0f, f * 210000.0f * 0.1f, 0.002f);
        }
    }
    func_L01_004084B0(&b, &d, 0x15, 1, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0.3f, 1.0f, 0.0f);
    func_L01_004084B0(&b, &d, 0x15, 1, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0x3F2020FF, 0.1f, 1.0f, 0.0f);
}
/* localdecomp:end func_L30_00347EC0 */
