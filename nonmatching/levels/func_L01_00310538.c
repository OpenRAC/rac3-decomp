/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00310248, the NTSC-U twin of func_L01_00310538, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_0030E630.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_00310538 (src/levels/shared/L01_0030E630.c).
 * Byte-exact only with -mvu0-use-vf0-vf2 + @ps2as and split addresses (no -mno-split-addresses); needs divs row 'func_L01_00310248 2'. */
/* localdecomp:start func_L01_00310248 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 v[2]; } Pair8;
extern void func_0039FE80(s32, s32, void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E2A8(void);
extern void func_00389158(void *, void *, void *, f32);
extern s32 func_0013D3E0(void);
extern f32 func_00389380(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_0046EAE8(void *, void *, s32, s32, f32);
extern s32 func_L01_0046EE10(void *, void *, s32, f32, s32);
extern Pair8 D_L01_001DC6D8[];

void func_L01_00310248(u8 *m, s32 unused, void *pos, void *dir) {
    u8 *vars = *(u8 **)(m + 0x68);
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    Pair8 tbl;
    vu0_v4 v4;
    s32 i;
    f32 f;

    func_0039FE80(0, 0, m);
    func_00388830(&v0, dir, 2.0f);
    vec_add_ab(&v0, &v0, pos);
    func_00388758(&v3, pos, &v0);
    func_00388830(&v1, dir, 0.15f);
    vec_add_ba(&v1, pos, &v1);
    func_00388830(&v3, &v3, 1.0f);
    func_003886E8(&v2, dir, 0.0009765625f);
    func_00388830(&v2, &v2, 1.0f);
    tbl = D_L01_001DC6D8[0];
    f = func_0037E2A8();
    for (i = 23; i >= 0; i--) {
        func_00389158(&v4, &v3, dir, f);
        func_L01_0046EAE8(&v1, &v4, tbl.v[func_0013D3E0() % 2], 20, 0.041666668f);
        f = func_00389380(f, 0.27318197f);
    }
    for (i = 0; i < 24; i++) {
        f32 t = (f32)i / 23.0f * 1.5f;
        func_L01_0046EE10(pos, &v2, tbl.v[func_0013D3E0() % 2], t, func_0037E208(30, 50));
    }
    *(u128_t *)vars = *(u128_t *)&v2;
}
/* localdecomp:end func_L01_00310248 */
