/* Matches PAL (all 432 bytes, with @ps2as -mvu0-use-vf0-vf2 on L01_00310A20.c and no -mno-split-addresses) but not its NTSC-U twin
 * func_L01_00310798: tools/version_map.py reports it nomatch there. The shared C has to match both discs, so the match is held back
 * until a wording does. Found by b9-t5.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_00310A88 */
typedef struct {
    f32 m[16];
    s32 c[4];
    u8 pad50[0x70 - 0x50];
    long q70;
    long q78;
    long q80;
    long q88;
} S_310A88;
typedef struct {
    u8 pad0[0x140];
    f32 v[3];
} G_310A88;
extern G_310A88 D_L01_001E2880;
extern void func_L01_00310998(S_310A88 *);
extern long func_00389598(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(f32 *, f32 *);
extern void func_0038CF68(f32 *, f32 *, f32);
extern void func_0038D328(f32 *, f32 *);
extern void func_003D2DA0(S_310A88 *, f32 *, s32);
void func_L01_00310A88(f32 *pos, s32 a1, s32 a2, s32 a3, s32 a4, f32 f1, f32 f2, f32 f3) {
    S_310A88 s;
    f32 m90[16];
    f32 vD0[4];
    f32 vE0[4];
    s32 color;
    f32 d;
    func_L01_00310998(&s);
    s.q78 = func_00389598(a3);
    color = a1 + (a2 << 24);
    s.q88 = ((long)a4 << 2) | 0x8000000040UL;
    s.q80 = 0xFF9000000260UL;
    s.c[3] = color;
    s.c[2] = color;
    s.c[1] = color;
    s.c[0] = color;
    s.q70 = 0;
    vD0[3] = 0.0f;
    vD0[2] = func_0038D160(D_L01_001E2880.v[0] - pos[0], D_L01_001E2880.v[1] - pos[1]);
    d = func_0038CF38(pos, D_L01_001E2880.v);
    vD0[1] = -func_0038D160(d, D_L01_001E2880.v[2] - pos[2]);
    vD0[0] = f2;
    func_0038D328(m90, vD0);
    vec_sub_ba(vE0, D_L01_001E2880.v, pos);
    func_0038CF68(vE0, vE0, f3);
    m90[12] = pos[0] + vE0[0];
    m90[13] = pos[1] + vE0[1];
    m90[14] = pos[2] + vE0[2];
    m90[15] = 1.0f;
    func_L01_00310A20((f32 *)&s, f1);
    func_003D2DA0(&s, m90, 0);
}
/* localdecomp:end func_L01_00310A88 */
