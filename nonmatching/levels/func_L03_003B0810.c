/* Wave 13 (r24, 2026-11-28) replaces the earlier draft of this function (Regional matching study (2026-11-24)). */
/* func_L03_003B0810 near (wave 13 r24): 80 differences under the file's line (the draft: 123). Changed
 * against the draft: (1) the sel[2] bounds load hi before A in both arms (retail's lw $s1/$s0 order);
 * (2) the switch selector is (i & 1) ? s->f12C : s->f128 (retail's beql with the f128 load in its delay
 * slot); (3) the shared return 0 sits in if (sel[3] == -1) { fail: return 0; } before the switch loop, as
 * retail places it; (4) the mask loop bound is a local k = hi - lo, which frees $a2 for &tmp (no extra
 * move before the call, so the switch loop needs no alignment nop). Still differs: the lo/hi block after
 * sel[0] (retail computes h*8 in $v1 and copies it to $s4: indexing D_L03_001DE8A0/8A4/900/904 by [h][0]
 * instead of the o offset reproduces that gcse copy but schedules the lui before the sll, 84); the sel[2]
 * arms schedule the lui before the sll (retail's sll fills the beqz delay slot); sel[2] lands in $t1, k in
 * $t0 and the tmp giv in $a1 (retail $a1, $a1, $t1); the mask-block bound addresses swap $a0/$a1. */
#include "common.h"

/* localdecomp:start func_L03_003B0810 */
typedef struct { char pad0[0x128]; int f128; int f12C; char pad130[0x190-0x130]; int f190[4]; int a1A0[1]; char p1A4[0x1E0-0x1A4]; int a1E0[1]; char p1E4[0x220-0x1E4]; int a220[1]; char p224[0x2A0-0x224]; int a2A0[1]; char p2A4[0x310-0x2A4]; int a310[1]; char p314[0x360-0x314]; int a360[1]; } S_003B0810;
typedef struct { char pad0[0x68]; S_003B0810 *p; } A_003B0810;
typedef struct { int a; int b; } P_003B0810;
extern s32 D_001DE858_sda;
__asm__(".extern D_001DE858_sda, 4");
extern s32 D_001DE830_sda[1];
__asm__(".extern D_001DE830_sda, 4");
extern s32 D_001DE840_sda[1];
__asm__(".extern D_001DE840_sda, 4");
extern u32 D_L03_001E1D90;
extern s32 D_L03_002BE328[][6];
extern s32 D_L03_002BA568[][6];
extern s32 D_L03_002BA4F0[][5];
extern s32 D_L03_002A2430[][30];
extern s32 D_L03_001DE860[][2];
extern s32 D_L03_001DE864[][2];
extern s32 D_L03_001DE890[][2];
extern s32 D_L03_001DE894[][2];
extern s32 D_L03_001DE8A0[][2];
extern s32 D_L03_001DE8A4[][2];
extern s32 D_L03_001DE8D0[][2];
extern s32 D_L03_001DE8D4[][2];
extern s32 D_L03_001DE900[][2];
extern s32 D_L03_001DE904[][2];
extern f32 func_003824E0(f32, f32);
extern s32 func_L03_003B0670();
extern s32 func_L03_003B06F0();

s32 func_L03_003B0810(A_003B0810 *a) {
    S_003B0810 *s = a->p;
    s32 v, i, n, g, h, k, t;
    s32 buf[6];
    s32 sel[4];
    s32 tmp[12];
    s32 *row;
    s32 mask, lo, hi, A, o;
    s32 fp = 0;

    {
        s32 enabled = D_001DE858_sda;
        s32 pair = enabled & 2;
        v = (enabled & 1) + (pair > 0);
    }
    if (v == 1 && func_003824E0(0.0f, 1.0f) < 0.3f || v == 2 && func_003824E0(0.0f, 1.0f) < 0.6f) {
        if (v == 2) {
            g = D_L03_001E1D90 == 0;
        } else {
            g = 0 < (D_001DE858_sda & 2);
        }
        D_L03_001E1D90 = g;
        fp = 1;
    } else {
        n = 0;
        for (i = 0; i < 6; i++) {
            if ((D_001DE858_sda >> i) & 1) {
                buf[n++] = i;
            }
        }
        k = func_003824E0(0.0f, 1.0f) < 0.35f;
        g = func_L03_003B0670(D_001DE830_sda, 4, buf, n, k);
        if (g == 4) {
            if (func_003824E0(0.0f, 1.0f) < 0.35f) {
                g = func_L03_003B0670(D_001DE830_sda, 4, buf, n, 0);
            }
        }
    }
    s->f128 = g;
    n = 0;
    for (i = 0; i < 6; i++) {
        if (D_L03_002BE328[g][i] >= 0 && ((D_001DE858_sda >> i) & 1)) {
            if (i >= 2 || func_003824E0(0.0f, 1.0f) < 0.7f) {
                buf[n++] = i;
            }
        }
    }
    k = func_003824E0(0.0f, 1.0f) < 0.6f;
    h = func_L03_003B0670(D_001DE840_sda, 6, buf, n, k);
    if (h == -1) return 0;
    s->f12C = h;
    if (fp) {
        sel[0] = func_L03_003B06F0(D_L03_002A2430[g], 30, D_L03_002BE328[g][h], D_L03_002BE328[g + 6][h], 0);
    } else {
        sel[0] = D_L03_002BE328[g][h];
    }
    if (sel[0] == -1) goto fail;
    lo = D_L03_001DE860[h][0];
    o = h * 8;
    hi = D_L03_001DE864[h][0];
    t = 0;
    if (h != 5 && func_003824E0(0.0f, 1.0f) < 0.25f) t = 1;
    sel[1] = func_L03_003B06F0(D_L03_002A2430[h], 30, lo, hi, t);
    if (sel[1] == -1) goto fail;
    if (fp) {
        hi = D_L03_001DE894[g][0];
        A = D_L03_001DE890[g][0];
    } else {
        hi = D_L03_001DE8D4[g][0];
        A = D_L03_001DE8D0[g][0];
    }
    sel[2] = func_L03_003B06F0(D_L03_002A2430[g], 30, A, hi, 0);
    if (sel[2] == -1) goto fail;
    if (fp) {
        sel[3] = func_L03_003B06F0(D_L03_002A2430[h], 30, *(s32 *)((char *)D_L03_001DE8A0 + o), *(s32 *)((char *)D_L03_001DE8A4 + o), 0);
    } else {
        mask = D_L03_002BA568[g][sel[2] - A];
        lo = *(s32 *)((char *)D_L03_001DE900 + o);
        hi = *(s32 *)((char *)D_L03_001DE904 + o);
        n = 0;
        k = hi - lo;
        for (i = 0; i <= k; i++) {
            if (D_L03_002BA4F0[h][i] & mask) {
                tmp[n++] = lo + i;
            }
        }
        sel[3] = func_L03_003B0670(D_L03_002A2430[h], 30, tmp, n, 0);
    }
    if (sel[3] == -1) {
    fail:
        return 0;
    }
    for (i = 0; i < 4; i++) {
        switch ((i & 1) ? s->f12C : s->f128) {
        case 0: s->f190[i] = s->a220[sel[i]]; break;
        case 1: s->f190[i] = s->a2A0[sel[i]]; break;
        case 2: s->f190[i] = s->a1A0[sel[i]]; break;
        case 3: s->f190[i] = s->a310[sel[i]]; break;
        case 4: s->f190[i] = s->a1E0[sel[i]]; break;
        case 5: s->f190[i] = s->a360[sel[i]]; break;
        }
    }
    return 1;
}
/* localdecomp:end func_L03_003B0810 */
