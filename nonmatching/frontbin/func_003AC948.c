/* Near miss of func_003AC948 with its file's own flags: tools/check.py reports 58 diff
   (the version it replaces: 60).
   What differs: With PAL's step constant 9 (instead of the US 8) the C now compiles to
   retail's bytes everywhere except retail's own padding in front of its two `div.s`: retail
   has 2 `nop`s before `div.s $f0,$f0,$f3` and 1 `nop` before `div.s $f20,$f0,$f2`, which our
   build does not emit (12 bytes short), and the three branch offsets that the padding shifts
   (b 0x1b8 vs 0x1c4, beqz 0x128 vs 0x134, bnez 0x124 vs 0x130). Every other instruction is
   byte-identical (55 diff rows in the checker = 6 differing words). gcc 2.95.3 and Ps2EeAs do
   not reproduce that `div.s` padding from plain C: per this project's own...
*/

/* US draft of func_003AC948 (rac3-uya-decomp func_003A73A0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL.

   PAL changes: the animation step is 9, not 8 (addiu $s1,$s1,9 / addiu $s1,$s1,-9).
   What is left is retail's padding in front of the two div.s (2 nops before the first,
   1 before the second), which the project's own build restores from
   config/frontbin/divs_nops.txt (that table still carries the US name func_003A73A0 2 1). */


/* localdecomp:start func_003AC948 */
typedef struct { s32 *p0; s32 *p4; u8 *p8; s32 *pC; u8 sub10[0x178]; s32 f188, f18C, f190; u8 p194[4]; s32 f198, f19C, f1A0, f1A4; f32 f1A8; u8 p1AC[4]; f32 f1B0; s32 f1B4; } O_A73A0;
extern f32 D_001D8434_003AC948;
extern f32 D_001D8438_003AC948;
__asm__(".extern D_001D8434_003AC948, 4");
__asm__(".extern D_001D8438_003AC948, 4");
extern void func_003AB458(void *, f32);
s32 func_003AC948(void *arg0) {
    O_A73A0 *o = arg0;
    s32 cnt = o->f198;
    s32 v = o->p8[3];
    u8 *p;
    u8 *q;
    s32 hi;
    s32 *t;
    s32 m;
    s32 x;
    f32 f;
    if (cnt > 0) {
        v = v + 9;
        v = (v >= 0x81) ? 0x80 : v;
        o->f198 = cnt - 1;
    } else {
        v = v - 9;
        v = (v <= -1) ? 0 : v;
    }
    if (v == 0) {
        *o->p4 = 0;
    } else {
        f32 k14 = 14.0f;
        f32 k23 = 23.5f;
        f32 g = 0.0f;
        f32 zero;
        hi = v << 24;
        p = (u8 *)o + 0x10;
        q = (u8 *)o + 0x4C;
        { s32 *r = (s32 *)o->p8; *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = o->pC; *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_003AAEB8(p); *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_003AAEB8(q); *r = (*r & 0xFFFFFF) | hi; }
        m = o->f1A4;
        switch (m) {
        case 0: {
            s32 x;
            f32 f;
            zero = g;
            x = (o->f1B4 >> 1) + 8;
            o->f19C = 8;
            o->f1A0 = 6;
            o->f18C = ((o->f190 * 0x10) >> 1) + 6;
            o->f188 = x;
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003AB458(q, k + 0.005f); }
            f = D_001D8434_003AC948;
            if (zero < f) {
                func_003AB458(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003AB458(p, g * 0.85f + 0.03f);
            f = D_001D8438_003AC948;
            if (zero <= f) {
                func_003AB458(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 1: {
            s32 x;
            f32 f;
            zero = g;
            x = (o->f1B4 >> 1) + 8;
            o->f19C = 8;
            o->f1A0 = 6;
            o->f18C = ((o->f190 * 0x10) >> 1) + 6;
            o->f188 = x;
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003AB458(q, k + 0.005f); }
            f = D_001D8434_003AC948;
            if (zero < f) {
                func_003AB458(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003AB458(p, g * 0.85f + 0.03f);
            f = D_001D8438_003AC948;
            if (zero <= f) {
                func_003AB458(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 2:
            break;
        }
    }
}
/* localdecomp:end func_003AC948 */
