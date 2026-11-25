/* PAL near miss (opus-b43-w20, fourth look after sonnet-b43-w14b, sonnet-b43-w7 and sonnet-b42-w23): 4 raw diffs (check.py) and 2 words
 * outside the longest matching blocks (difflib over check.py's two columns), 854 = 854 words, with the file's flags (-O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2); needs the divs_nops.txt row `func_L01_003B8E60 2 2 2 2 2` (committed).
 * Levers of earlier looks: `n--` last in the do-while body, seven named constants in retail's preheader order, `.extern D_L01_001DE780/788, 4`
 * hints, qzero(w + 0x20), natural V[] store order, block-scoped TI temps for every table copy (sonnet-b43-w14-findings.md).
 * New in b43-w20 (opus-b43-w20-findings.md):
 *  - the three "macro" loads are small-symbol + offset: `D_001D5470_003B8E60[6]` (u8[8], `.extern ..., 16`), `D_L01_001DE780_003B8E60[1]`
 *    (s32[2]) and `D_L01_001DE788_003B8E60[1]` (f32[2]), both with `.extern ..., 16`. gcc keeps a CONST(symbol + offset) address of a small
 *    symbol unsplit (mips_check_split) but gives it length 8 (simple_memory_operand rejects CONST), so reorg never puts it in a delay slot,
 *    and the assembler expands `lbu $v0, sym+6` / `lw $a1, sym+4` / `lwc1 $f13, sym+4` with lui (hint 16): retail's nop slots around
 *    D_001D5476 and the lui/lw pairs before the jal (21 -> 8 aligned).
 *  - the first while loop indexes `fp[i]` instead of walking a pointer p: loop.c makes the pointer a giv whose init `move $s0,$fp` lands in
 *    the loop preheader after the copied exit test, so the bnez delay slot takes `addiu $s4,$zero,1` (cnt = 1) as in retail (8 -> 6).
 *  - the 0x127d copy loop passes `&vp[l]` with `R_3B8E60 *vp = &V[2];` declared INSIDE the loop body: the inner loop.c hoists vp to
 *    its preheader, the giv of the argument gets vp as add_val, its init `s0 = vp` keeps vp as a separate pseudo ($v0):
 *    retail's `addiu $v0,$sp,0x20; move $s0,$v0` and the V[1] reload in $v1 (6 -> 2). vp at the block top is an outer-loop movable
 *    (merged with the spilled &V[2] pseudo: 47 raw); vp just before the loop is folded by combine (no change).
 * Still differs: both w+0x30 copy loops (0x127d, 0x1290) increment the destination giv $s2 before the source giv $s3 (retail $s3
 * first). Sched1/sched2 dumps: both increments are ready in the same cycle with the same priority and class, the tie goes to LUID,
 * and LUID = loop.c creation order = reverse giv discovery order (bl->giv is prepended), so the store's DEST_ADDR giv (found after
 * the load) is created before the load's. Retail needs the destination giv created last. Tried without effect (same 4 raw): struct
 * assignment, `*(u128 *)&V[..]`, row-pointer source, temp T, `V + 3 + l`, in-loop source pointer, while / do-while loop shapes,
 * a separate dst pointer local; worse: user pointer bivs for the source (`s += 16`, 14 raw) or the destination (`l++, dv++`, 16
 * raw), a second index counter (`l++, vi++`, 10 raw). No switch. */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_003B8E60 */
typedef int u128_3B8E60 __attribute__((mode(TI)));
typedef union {
    u128_3B8E60 q;
    f32 f[4];
} R_3B8E60;
extern u8 *D_L01_0021F6C0[];
extern u8 D_001D5470_003B8E60[8];
__asm__(".extern D_001D5470_003B8E60, 16");
__asm__(".extern D_L01_001DE780, 4");
extern s32 D_L01_001DE780;
extern s32 D_L01_001DE780_003B8E60[2];
__asm__(".extern D_L01_001DE780_003B8E60, 16");
__asm__(".extern D_L01_001DE788, 4");
extern f32 D_L01_001DE788;
extern f32 D_L01_001DE788_003B8E60[2];
__asm__(".extern D_L01_001DE788_003B8E60, 16");
extern u128_3B8E60 D_L01_001DE7F0[];
extern u128_3B8E60 D_L01_001DE820[];
extern u128_3B8E60 D_L01_001DE840[];
extern u128_3B8E60 D_L01_001DE860[];
extern u128_3B8E60 D_L01_001DE8A0[];
extern u128_3B8E60 D_L01_001DE8C0[];
extern f32 func_0038CF00(void *, void *);
extern f32 func_00382538(void);
extern f32 func_L01_00443A18(f32, f32);

void func_L01_003B8E60(void *self, s32 idx) {
    s16 *fp;
    u8 *t;
    u8 *m;
    u8 *w;
    u8 *r;
    f32 len;
    f32 inv;
    f32 fn;
    f32 fc;
    f32 d;
    f32 sp1;
    f32 q;
    f32 k55;
    f32 km55;
    f32 km16;
    f32 km015;
    f32 k10;
    f32 k20;
    f32 km50;
    s32 n;
    s32 cnt;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s16 tmp;
    R_3B8E60 V[10];

    fp = D_L01_0021DE20[idx];
    if (fp == 0) {
        return;
    }
    *(u8 *)((u8 *)self + 0x30) = 0xff;
    w = *(u8 **)((u8 *)self + 0x68);
    t = D_L01_0021F6C0[*(s32 *)w];
    len = func_0038CF00(t + 0x10, t + 0x20);
    fn = *(s32 *)t;
    inv = 1.0f / len;
    len = func_0038CF00(t + 0x10, t + *(s32 *)t * 16);
    *(s16 *)(w + 0x80) = len < 5.0f;
    *(f32 *)(w + 0x14) = *(f32 *)(w + 8) * 0.020000001f * inv;
    *(u8 **)(w + 0x70) = t;
    fp = D_L01_0021DE20[idx];
    i = 0;
    cnt = 1;
    while (!(fp[i] & 0x8000)) {
        if (i > 0) {
            j = func_00382468(i);
            tmp = fp[j];
            fp[j] = fp[i];
            fp[i] = tmp;
        }
        i++;
        cnt++;
    }
    d = (f32)*(s32 *)t * 0.400000006f / (f32)cnt;
    sp1 = *(f32 *)(w + 0x14) * 0.25f / d;
    fp = D_L01_0021DE20[idx];
    n = cnt - 1;
    k20 = 2.0f;
    k10 = 1.0f;
    km16 = -1.60000002f;
    km015 = -0.150000006f;
    km50 = -5.0f;
    k55 = 5.5f;
    km55 = -5.5f;
    do {
        m = (u8 *)(D_L01_001E001C + ((*(u16 *)fp & 0x7fff) << 8));
        w = *(u8 **)(m + 0x68);
        if (m != self) {
            *(u16 *)(m + 0x34) |= 2;
        }
        if (*(s16 *)(m + 0xaa) != 0x1d3e && D_001D5470_003B8E60[6] != 0) {
            func_L01_00445F40(m, 0x1d3e);
            *(f32 *)(m + 0x2c) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) * 1.5f;
            func_003C3A10(m, 5, 0, 0);
            func_003C7C38(m);
        }
        *(f32 *)(w + 0x10) = (f32)n / (f32)cnt * fn;
        *(f32 *)(w + 0x8c) = d;
        *(f32 *)(w + 0x94) = sp1 * func_003824E0(0.75f, 1.25f);
        *(f32 *)(w + 0x90) = func_00382538();
        qzero(w + 0x20);
        *(s16 *)(w + 0x82) = 1;
        *(f32 *)(w + 0x28) = *(f32 *)(w + 4) * func_L01_00443A18(0.5f, 1.0f);
        *(s16 *)(w + 0x86) = (func_00382498(D_L01_001DE780, D_L01_001DE780_003B8E60[1]) * 5 + 2) / 6;
        *(f32 *)(w + 0x78) = func_00382538();
        *(f32 *)(w + 0x7c) = func_L01_00443A18(D_L01_001DE788, D_L01_001DE788_003B8E60[1]) * 0.0174532924f * 0.020000001f;
        *(f32 *)(w + 0x88) = *(f32 *)(m + 0x2c) / *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
        *(s32 *)(w + 0x18) = -1;
        *(s32 *)(w + 0x1c) = 0;
        *(s32 *)(w + 0x98) = 0;
        if (*(s16 *)(m + 0xaa) == 0x9b0) {
            V[0].q = 0;
            V[1].q = 0;
            V[2].q = 0;
            V[0].f[1] = 0.75f;
            V[1].f[0] = V[0].f[0] = -2.0999999f;
            V[1].f[1] = -0.75f;
            V[1].f[2] = V[0].f[2] = 0.860000014f;
            V[2].f[0] = -3.0f;
            V[2].f[2] = -0.670000017f;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            func_0038CE20(&V[1], &V[1], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x40) = V[1].q;
            func_0038CE20(&V[2], &V[2], *(f32 *)(w + 0x88));
            {
                u128_3B8E60 T0 = D_L01_001DE7F0[0];
                u128_3B8E60 T1 = D_L01_001DE7F0[1];
                u128_3B8E60 TV = V[2].q;
                u128_3B8E60 T2 = D_L01_001DE7F0[2];
                *(u128_3B8E60 *)(w + 0x50) = TV;
                V[3].q = T0;
                V[4].q = T1;
                V[5].q = T2;
            }
            for (k = 0; k < 3; k++) {
                func_0038CE20(w + 0xb0 + k * 16, &V[3 + k], *(f32 *)(w + 0x88));
            }
        }
        if (*(s16 *)(m + 0xaa) == 0x1c87) {
            V[0].q = 0;
            V[1].q = 0;
            V[0].f[0] = -3.70000005f;
            V[0].f[1] = -1.70000005f;
            V[0].f[2] = 4.0f;
            V[1].f[0] = -3.70000005f;
            V[1].f[1] = 1.70000005f;
            V[1].f[2] = 4.0f;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            func_0038CE20(&V[1], &V[1], *(f32 *)(w + 0x88));
            {
                u128_3B8E60 T0 = D_L01_001DE820[0];
                u128_3B8E60 T1 = D_L01_001DE820[1];
                *(u128_3B8E60 *)(w + 0x40) = V[1].q;
                V[2].q = T0;
                V[3].q = T1;
            }
            for (k = 0; k < 2; k++) {
                func_0038CE20(w + 0xb0 + k * 16, &V[2 + k], *(f32 *)(w + 0x88));
            }
        }
        if (*(s16 *)(m + 0xaa) == 0x1a78) {
            V[0].q = 0;
            V[1].q = 0;
            V[0].f[0] = -3.75f;
            V[0].f[1] = 2.5999999f;
            V[0].f[2] = k20;
            V[0].f[3] = k10;
            V[1].f[0] = -3.75f;
            V[1].f[1] = -2.5999999f;
            V[1].f[2] = k20;
            V[1].f[3] = k10;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            func_0038CE20(&V[1], &V[1], *(f32 *)(w + 0x88));
            {
                u128_3B8E60 T0 = D_L01_001DE840[0];
                u128_3B8E60 T1 = D_L01_001DE840[1];
                *(u128_3B8E60 *)(w + 0x40) = V[1].q;
                V[2].q = T0;
                V[3].q = T1;
            }
            for (k = 0; k < 2; k++) {
                func_0038CE20(w + 0xb0 + k * 16, &V[2 + k], *(f32 *)(w + 0x88));
            }
        }
        if (*(s16 *)(m + 0xaa) == 0x1c46) {
            V[0].q = 0;
            V[0].f[0] = km16;
            V[0].f[2] = km015;
            V[0].f[3] = k10;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            V[1].q = 0;
            V[1].f[0] = km16;
            V[1].f[2] = km015;
            V[1].f[3] = k10;
            func_0038CE20(w + 0xb0, &V[1], *(f32 *)(w + 0x88));
        }
        if (*(s16 *)(m + 0xaa) == 0xb13) {
            V[0].q = 0;
            V[1].q = 0;
            V[0].f[0] = -3.67799997f;
            V[0].f[1] = 0.808000028f;
            V[0].f[2] = 0.100000001f;
            V[0].f[3] = k10;
            V[1].f[0] = -3.67799997f;
            V[1].f[1] = -0.808000028f;
            V[1].f[2] = 0.100000001f;
            V[1].f[3] = k10;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            func_0038CE20(&V[1], &V[1], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x40) = V[1].q;
        }
        if (*(s16 *)(m + 0xaa) == 0x1d94) {
            V[0].q = 0;
            V[1].q = 0;
            V[2].q = 0;
            V[3].q = 0;
            V[0].f[0] = km50;
            V[0].f[1] = k55;
            V[0].f[2] = 4.5f;
            V[0].f[3] = k10;
            V[1].f[0] = km50;
            V[1].f[1] = km55;
            V[1].f[2] = 4.5f;
            V[1].f[3] = k10;
            V[2].f[0] = km50;
            V[2].f[1] = k55;
            V[2].f[2] = k20;
            V[2].f[3] = k10;
            V[3].f[0] = km50;
            V[3].f[1] = km55;
            V[3].f[2] = k20;
            V[3].f[3] = k10;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            func_0038CE20(&V[1], &V[1], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x40) = V[1].q;
            func_0038CE20(&V[2], &V[2], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x50) = V[2].q;
            func_0038CE20(&V[3], &V[3], *(f32 *)(w + 0x88));
            {
                u128_3B8E60 T0 = D_L01_001DE860[0];
                u128_3B8E60 T1 = D_L01_001DE860[1];
                u128_3B8E60 T2 = D_L01_001DE860[2];
                u128_3B8E60 TV = V[3].q;
                u128_3B8E60 T3 = D_L01_001DE860[3];
                *(u128_3B8E60 *)(w + 0x60) = TV;
                V[6].q = T0;
                V[7].q = T1;
                V[8].q = T2;
                V[9].q = T3;
            }
            for (k = 0; k < 4; k++) {
                func_0038CE20(w + 0xb0 + k * 16, &V[6 + k], *(f32 *)(w + 0x88));
            }
        }
        if (*(s16 *)(m + 0xaa) == 0x127d) {
            V[0].q = 0;
            V[1].q = 0;
            V[0].f[0] = -0.165000007f;
            V[0].f[1] = 0.699999988f;
            V[0].f[2] = -0.160999998f;
            V[0].f[3] = k10;
            V[1].f[0] = -0.165000007f;
            V[1].f[1] = -0.699999988f;
            V[1].f[2] = -0.160999998f;
            V[1].f[3] = k10;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            func_0038CE20(&V[1], &V[1], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x40) = V[1].q;
            for (l = 0; l < 2; l++) {
                R_3B8E60 *vp = &V[2];
                V[2 + l].q = *(u128_3B8E60 *)(w + 0x30 + l * 16);
                func_0038CE20(w + 0xb0 + l * 16, &vp[l], *(f32 *)(w + 0x88));
            }
        }
        if (*(s16 *)(m + 0xaa) == 0x1c4d) {
            V[0].q = 0;
            V[1].q = 0;
            V[0].f[0] = -1.89999998f;
            V[0].f[1] = 0.839999974f;
            V[0].f[2] = -0.200000003f;
            V[0].f[3] = k10;
            V[1].f[0] = -1.89999998f;
            V[1].f[1] = -0.839999974f;
            V[1].f[2] = -0.200000003f;
            V[1].f[3] = k10;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            func_0038CE20(&V[1], &V[1], *(f32 *)(w + 0x88));
            {
                u128_3B8E60 T0 = D_L01_001DE8A0[0];
                u128_3B8E60 T1 = D_L01_001DE8A0[1];
                *(u128_3B8E60 *)(w + 0x40) = V[1].q;
                V[2].q = T0;
                V[3].q = T1;
            }
            for (k = 0; k < 2; k++) {
                func_0038CE20(w + 0xb0 + k * 16, &V[2 + k], *(f32 *)(w + 0x88));
            }
        }
        if (*(s16 *)(m + 0xaa) == 0x1290) {
            V[0].q = 0;
            V[1].q = 0;
            V[2].q = 0;
            V[0].f[0] = -0.823000014f;
            V[0].f[1] = 0.698000014f;
            V[0].f[2] = -0.218999997f;
            V[0].f[3] = k10;
            V[1].f[0] = -0.823000014f;
            V[1].f[1] = -0.698000014f;
            V[1].f[2] = -0.218999997f;
            V[1].f[3] = k10;
            V[2].f[0] = -1.37600005f;
            V[2].f[2] = 0.208000004f;
            V[2].f[3] = k10;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            func_0038CE20(&V[1], &V[1], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x40) = V[1].q;
            func_0038CE20(&V[2], &V[2], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x50) = V[2].q;
            for (l = 0; l < 3; l++) {
                V[3 + l].q = *(u128_3B8E60 *)(w + 0x30 + l * 16);
                func_0038CE20(w + 0xb0 + l * 16, &V[3 + l], *(f32 *)(w + 0x88));
            }
        }
        if (*(s16 *)(m + 0xaa) == 0x1340) {
            V[0].q = 0;
            V[1].q = 0;
            V[0].f[0] = -0.215000004f;
            V[0].f[1] = 2.13199997f;
            V[0].f[2] = -0.319000006f;
            V[0].f[3] = k10;
            V[1].f[0] = -0.215000004f;
            V[1].f[1] = -2.13199997f;
            V[1].f[2] = -0.319000006f;
            V[1].f[3] = k10;
            func_0038CE20(&V[0], &V[0], *(f32 *)(w + 0x88));
            *(u128_3B8E60 *)(w + 0x30) = V[0].q;
            func_0038CE20(&V[1], &V[1], *(f32 *)(w + 0x88));
            {
                u128_3B8E60 T0 = D_L01_001DE8C0[0];
                u128_3B8E60 T1 = D_L01_001DE8C0[1];
                *(u128_3B8E60 *)(w + 0x40) = V[1].q;
                V[2].q = T0;
                V[3].q = T1;
            }
            for (k = 0; k < 2; k++) {
                func_0038CE20(w + 0xb0 + k * 16, &V[2 + k], *(f32 *)(w + 0x88));
            }
        }
        *(u8 *)(m + 0x20) = 1;
        if (D_001D545C != 0x10 && D_001D545C != 1 && D_001D545C != 5 && D_001D545C != 0xe) {
            *(s16 *)(m + 0x32) = 0xbe;
        }
        n--;
    } while (*fp++ >= 0);
}
/* localdecomp:end func_L01_003B8E60 */
