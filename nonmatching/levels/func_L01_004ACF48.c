/* func_L01_004ACF48: about 16 rows differ when aligned (66 raw positionally) with the flags `-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division
 * -mno-split-addresses @ps2as` (the file's own line has none of the vu0 flag, N mode and @ps2as: a flag-line change of this one-function file; --all-modes: S 117 diff,
 * N 57, and the 64-bit constant 0x8000000048 needs Ps2EeAs: `ori 0x8000; dsll 24; ori 0x48`). Also needs divs_nops row `func_L01_004ACF48 2` and `.extern` hints (8 bytes
 * for D_L01_001D99A0 and D_L01_001D99D0, the gp-relative bases; D_001D99A4 and D_L01_002EDE40 are lui/addiu). The 0x90-byte record (m[4], c[4], uv[4], four longs) is the
 * particle record of the L05 emitter func_L05_003622D0; the first loop needs its own counter (a shared i goes callee-saved and hoists `addiu $s2,$zero,3`).
 * Left: (1) retail keeps the table address as a temp ($v1 = lui/addiu, $v0 = j * 16 + $v1, `lwc1 $f0,0xC($v0)`) and copies it into e (`move $s5,$v0`) after the load, so col is $s4
 * and e $s5; the draft computes e into $s4 and col into $s5 (a typed D[j].f0C load folds the 0xC into the symbol instead); (2) the temp of `a->hB2 != 0` is $a0 in retail,
 * $v0 here (twice: loop head and the branch-likely slot); (3) `addiu $s3,$gp,-0x2EE0; move $s0,$sp` are two insns later in retail (after the two nops before div.s). */
#include "vu0.h"
typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    struct { f32 x, y; } uv[4];
    long x70, x78, x80, x88;
} S_4ACF48;
__asm__(".extern D_L01_001D99A0, 8");
__asm__(".extern D_L01_001D99C0, 4");
__asm__(".extern D_L01_001D99D0, 8");
extern f32 D_L01_001D99A0[];
extern s32 D_L01_001D99C0;
extern f32 D_L01_001D99D0[];
extern f32 D_001D99A4[];
extern u8 D_L01_002EDE40[];
extern long func_00389598(s32);
extern void func_003C2EC0(void *, s32, void *);
extern s32 func_00382468(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_004ACF48(u8 *a) {
    S_4ACF48 s;
    vu0_v4 mat[4];
    s32 n;
    s32 j;
    s32 i;
    s32 q;
    s32 k;
    u8 *e;
    s32 col;
    f32 t;

    n = D_L01_001D99C0;
    s.x78 = func_00389598(5);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.x70 = 0;
    for (q = 0; q < 4; q++) {
        s.uv[q].x = D_L01_001D99A0[q * 2];
        s.uv[q].y = D_001D99A4[q * 2];
    }
    func_003C2EC0(a, 1, mat);
    for (j = 0; j < n; j++) {
        k = *(u8 *)(a + 0xBC);
        if (*(s16 *)(a + 0xB2) != 0) {
            k += func_00382468();
        }
        e = D_L01_002EDE40 + j * 16;
        col = (k << 24) | 0x2058B0;
        t = (f32)k * (*(f32 *)(e + 0xC) / 40.0f);
        for (i = 0; i < 4; i++) {
            s.c[i] = col;
            func_0038CE20(&s.m[i], D_L01_001D99D0 + i * 4, t);
            vec_add_ba(&s.m[i], &s.m[i], e);
            func_0038D000(&s.m[i], &s.m[i], mat);
            vec_add_ab(&s.m[i], &s.m[i], &mat[3]);
        }
        func_003D2DA0(&s, 0, 0);
    }
}
