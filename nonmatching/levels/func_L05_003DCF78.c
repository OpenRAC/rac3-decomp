/* NTSC-U draft (2026-11-14, Claude worker): C of func_L05_003DAAE8, the NTSC-U twin of func_L05_003DCF78, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (PAL line has neither)" (src/levels/shared/L05_003DCBF0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L05_003DAAE8 */
typedef int u128_t_3DAAE8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DAAE8;
__asm__(".extern D_001DF21C_sda, 4");
extern f32 D_001DF21C_sda;
__asm__(".extern D_001DF218_sda, 4");
extern f32 D_001DF218_sda;
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L05_003DAAE8(u8 *m) {
    s32 *v;
    V4_3DAAE8 b;
    V4_3DAAE8 q;
    V4_3DAAE8 c;
    V4_3DAAE8 w;
    f32 s;
    s32 i;
    s32 r;

    s = *(f32 *)(m + 0x2C) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
    v = *(s32 **)(m + 0x68);
    *(u128_t_3DAAE8 *)&q = 0;
    q.z = D_001DF21C_sda;
    b = q;
    func_003886E8(&b, &b, s);
    for (i = 0; i < 2; i++) {
        func_003886E8(&c, m + 0xC0, func_0037E250(-D_001DF218_sda, D_001DF218_sda) * s);
        vec_add_ab(&q, &c, &b);
        func_003886E8(&c, m + 0xD0, func_0037E250(-0.6f, 0.6f) * s);
        vec_add_ab(&q, &c, &q);
        *(u128_t_3DAAE8 *)&w = 0;
        w.x = func_0037E250(-1.0f, 1.0f);
        w.y = func_0037E250(-1.0f, 1.0f);
        w.z = func_0037E250(-2.0f, 0.0f);
        c = w;
        func_003886E8(&w, m + 0xE0, -1.0f);
        vec_add_ab(&c, &w, &c);
        func_00388830(&c, &c, func_0037E250(1.5f, 3.0f) * 0.016666668f);
        r = func_0037E208(3, 6);
        func_L02_003E0520(m, &q, 0.0f, &c, r, (i & 1) ? 3 : 0, 0.033333335f, s, 15.0f, 1.0f, 0);
    }
    v[1]--;
    *v = func_0037E208(0x5A, 0xB4);
}
/* localdecomp:end func_L05_003DAAE8 */
