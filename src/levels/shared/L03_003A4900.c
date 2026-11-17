#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L03_003A4900);

INCLUDE_ASM("asm/levels", func_L03_003A4FC8);

/* localdecomp:start func_L03_003A51E0 */
extern s32 func_00382498(s32, s32);
extern void func_0038D570(void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern vu0_v4 D_L03_002BA370[][4];
extern u8 *D_L03_001DFA80;

void func_L03_003A51E0(vu0_v4 *out, s32 idx) {
    vu0_v4 s[2];
    vu0_v4 m[4];
    vu0_v4 e;
    vu0_v4 r;
    vu0_v4 t;
    s32 n;
    s32 k;

    n = func_00382498(0, 5);
    k = func_00382498(0, 3);
    switch (k) {
    case 0:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][0];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][1];
        break;
    case 1:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][0];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][2];
        break;
    case 2:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][2];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][3];
        break;
    case 3:
        *(vu0_q *)&s[0] = *(vu0_q *)&D_L03_002BA370[n][1];
        *(vu0_q *)&s[1] = *(vu0_q *)&D_L03_002BA370[n][3];
        break;
    }
    func_0038D570(m, D_L03_001DFA80 + idx * 0x80);
    *(vu0_q *)&m[3] = *(vu0_q *)(D_L03_001DFA80 + idx * 0x80 + 0x30);
    m[3].w = 1.0f;
    vec_sub_ba(&r, &s[1], &s[0]);
    e = r;
    func_0038CE20(&e, &e, func_003824E0(0.0f, 1.0f));
    vec_add_ab(&t, &s[0], &e);
    r = t;
    *out = r;
    func_0038D028(out, out, m);
}
/* localdecomp:end func_L03_003A51E0 */

INCLUDE_ASM("asm/levels", func_L03_003A5388);
