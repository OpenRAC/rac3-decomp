/* func_L01_0040AAC8 (Claude wave 14 r72, 2026-11-28). First draft kept here. */
/* PAL near miss (wave 14 r72, 2026-11-28): func_L01_0040AAC8 (1156 B, 34 places), a camera-facing 16-vertex
 * ring drawn twice (first draft; fresh entry, written from retail with the functional port's types). 81 diff
 * with the file's line and the divs row `func_L01_0040AAC8 2` (retail has two nops before its one div.s; check
 * with --divs 2). The frame (off/q/r2/view/side/up/pos/roll/rollm at 0x00-0xBF) and the spill slots of tex0,
 * tex1, col and flag at 0xC0-0xCC come out as retail's; the vector library parts are vec_sub_ab/vec_add_ab and
 * qzero. Levers that mattered: the 9080 rows as a 3-float struct, q.y before q.z in loop 1, loop 2's 0.5f as a
 * literal (retail reloads it into $f4, sn takes $f20) with tB loaded first and the [0] store first, the colour
 * pointer for loop 1 (puts 0x80808080 in $s4 hoisted like retail's).
 * Still differs: register choice in loop 1 (i in $s2 vs $s1, the 9080 pointer $s1 vs $s2) and the place of the
 * DFA20 pointer setup (retail before the third func_0038CE20 call); after loop 1 the DFA20 address is shared
 * between the first func_003D3A24 call and loop 2 here ($s1), where retail recomputes it for the call
 * (lui/addiu into $a2) and uses $a1 in loop 2, sharing only the 9140 address ($s0); the last call's address
 * loads come in another order. */
#include "common.h"

/* localdecomp:start func_L01_0040AAC8 */
#include "vu0.h"
typedef struct {
    vu0_v4 off;      /* 0x00 */
    vu0_v4 q;        /* 0x10 */
    vu0_v4 r2;       /* 0x20 */
    vu0_v4 view;     /* 0x30 */
    vu0_v4 side;     /* 0x40 */
    vu0_v4 up;       /* 0x50 */
    vu0_v4 pos;      /* 0x60 */
    vu0_v4 roll;     /* 0x70 */
    vu0_v4 rollm[4]; /* 0x80: func_0038D830 writes a 3-row matrix here */
} Frame_0040AAC8;
extern vu0_v4 D_L01_001E29C0;
typedef struct { f32 x, y, z; } V3_0040AAC8;
extern V3_0040AAC8 D_L01_001E9080[];
extern u32 D_L01_001DFA20[];
extern f32 D_L01_001E9140[];
extern f32 D_L01_002C5200[];
extern f32 D_L01_002C5308[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D750(void *, s32, f32);
extern void func_0038D830(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038C750(void);
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003D3A24(s32, void *, void *, void *, s32);

void func_L01_0040AAC8(vu0_v4 *pos, s32 tex0, s32 tex1, s32 col, s32 flag, f32 sz, f32 div, f32 unused, f32 roll,
                       f32 ang, f32 push) {
    Frame_0040AAC8 f;
    f32 one, half, sn, cs, tA, tB;
    s32 i, j;
    u32 *c;

    one = 1.0f;
    f.pos = *pos;
    vec_sub_ab(&f.view, &D_L01_001E29C0, &f.pos);
    func_0038CF68(&f.view, &f.view, one);
    func_0038CE90(&f.side, &f.view, (u8 *)&D_L01_001E29C0 + 0x40);
    func_0038CF68(&f.side, &f.side, one);
    func_0038CE90(&f.up, &f.side, &f.view);
    if (roll != 0.0f) {
        func_0038D750(&f.roll, 0, roll);
        func_0038D830(&f.roll, &f.rollm[0]);
        func_0038D5F0(&f.view, &f.view, &f.rollm[0]);
    }
    div = one / div;
    func_0038CE20(&f.off, &f.view, push);
    vec_add_ab(&f.pos, &f.pos, &f.off);
    half = 0.5f;
    func_0038CE20(&f.side, &f.side, sz);
    func_0038CE20(&f.up, &f.up, sz);
    qzero(&f.q);
    c = D_L01_001DFA20;
    for (i = 0; i < 16; i++) {
        j = (i * ((((i & 1) << 1) - 1) << 2)) & 0x3C;
        f.q.y = D_L01_002C5308[j];
        f.q.z = D_L01_002C5200[j];
        func_0038D028(&f.r2, &f.q, &f.view);
        D_L01_001E9080[i].x = f.r2.x;
        D_L01_001E9080[i].y = f.r2.y;
        D_L01_001E9080[i].z = f.r2.z;
        *c++ = 0x80808080;
        D_L01_001E9140[i * 2] = f.q.y * half * div + half;
        D_L01_001E9140[i * 2 + 1] = f.q.z * half * div + half;
    }
    func_003A9440(8, 5);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1UL);
    func_0038C750();
    func_003A9440(6, func_00389598(tex0));
    func_003A9440(0x42, 0x800000006AUL);
    func_003D3A24(16, D_L01_001E9080, D_L01_001DFA20, D_L01_001E9140, 1);
    sn = func_0038D098(ang);
    cs = func_0038D0B0(ang);
    for (i = 0; i < 16; i++) {
        j = (i * ((((i & 1) << 1) - 1) << 2)) & 0x3C;
        D_L01_001DFA20[i] = col;
        tB = D_L01_002C5308[j];
        tA = D_L01_002C5200[j];
        f.q.z = tA;
        f.q.y = tB;
        D_L01_001E9140[i * 2] = (tB * sn - tA * cs) * 0.5f * div + 0.5f;
        D_L01_001E9140[i * 2 + 1] = (tA * sn + tB * cs) * 0.5f * div + 0.5f;
    }
    func_003A9440(6, func_00389598(tex1));
    if (flag != 0) {
        func_003A9440(0x42, 0x8000000054UL);
    } else {
        func_003A9440(0x42, 0x8000000058UL);
    }
    func_003D3A24(16, D_L01_001E9080, D_L01_001DFA20, D_L01_001E9140, 1);
    func_003A9440(0x47, 0x5360BUL);
}
/* localdecomp:end func_L01_0040AAC8 */
