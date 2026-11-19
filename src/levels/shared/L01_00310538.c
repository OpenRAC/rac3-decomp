#include "common.h"

/* localdecomp:start func_L01_00310538 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { s32 v[2]; } Pair8;
extern void func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_0013D3E0(void);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00472238(void *, void *, s32, s32, f32);
extern s32 func_L01_00472560(void *, void *, s32, f32, s32);
extern Pair8 D_L01_001DC698[];

void func_L01_00310538(u8 *m, s32 unused, void *pos, void *dir) {
    u8 *vars = *(u8 **)(m + 0x68);
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    Pair8 tbl;
    vu0_v4 v4;
    s32 i;
    f32 f;

    func_003A52A0(0, 0, m);
    func_0038CF68(&v0, dir, 2.0f);
    vec_add_ab(&v0, &v0, pos);
    func_0038CE90(&v3, pos, &v0);
    func_0038CF68(&v1, dir, 0.15f);
    vec_add_ba(&v1, pos, &v1);
    func_0038CF68(&v3, &v3, 1.0f);
    func_0038CE20(&v2, dir, 0.0009765625f);
    func_0038CF68(&v2, &v2, 1.0f);
    tbl = D_L01_001DC698[0];
    f = func_00382538();
    for (i = 23; i >= 0; i--) {
        func_0038D890(&v4, &v3, dir, f);
        func_L01_00472238(&v1, &v4, tbl.v[func_0013D3E0() % 2], 17, 0.050000004f);
        f = func_0038DAB8(f, 0.27318197f);
    }
    for (i = 0; i < 24; i++) {
        f32 t = (f32)i / 23.0f * 1.5f;
        func_L01_00472560(pos, &v2, tbl.v[func_0013D3E0() % 2], t, func_00382498(25, 42));
    }
    *(u128_t *)vars = *(u128_t *)&v2;
}
/* localdecomp:end func_L01_00310538 */
