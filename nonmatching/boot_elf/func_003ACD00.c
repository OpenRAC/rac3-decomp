/* Near miss of func_003ACD00 with its file's own flags: tools/check.py reports 74 diff
   (the version it replaces: 76).
   What differs: Only the four float literals differ: retail builds 0.5675f (0x3F1147AE),
   0.005f (0x3BA3D70A), 0.85f (0x3F59999A) and 0.03f (0x3CF5C28F) inline (`lui $at,hi` / `ori
   $at,$at,lo` / `mtc1 $at,$fN`), while ee-gcc 2.95.3 with this file's flags (-mvu0-use-vf0-vf2
   -O2 -G8 -fopt-stack -mno-check-zero-division) puts them in the .lit4 pool and loads them
   with `lwc1 $fN,off($gp)`; the 8 extra words also shift the three branch targets (`b`,
   `beqz`, `bnez`). Everything else now matches, including the PAL constant change (v +/- 9
   instead of 8, so `addiu $s1,$s1,9` / `addiu $s1,$s1,-9`).
*/

/* Candidate for func_003ACD00 (PAL retail). Based on the US draft
   (rac3-uya-decomp func_003ACB60), with the PAL constants (9 instead of 8). */


/* localdecomp:start func_003ACD00 */
extern void func_003AB810(void *, f32);
s32 func_003ACD00(void *arg0) {
    O_A73A0 *o = arg0;
    s32 cnt = o->f198;
    s32 v = o->p8[3];
    u8 *p;
    u8 *q;
    s32 hi;
    s32 m;
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
        { s32 *r = (s32 *)func_003AB270(p); *r = (*r & 0xFFFFFF) | hi; }
        { s32 *r = (s32 *)func_003AB270(q); *r = (*r & 0xFFFFFF) | hi; }
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
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003AB810(q, k + 0.005f); }
            f = D_001D8434_003ACD00;
            if (zero < f) {
                func_003AB810(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003AB810(p, g * 0.85f + 0.03f);
            f = D_001D8438_003ACD00;
            if (zero <= f) {
                func_003AB810(p, f);
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
            { f32 k; f32 t = ((f32)x - 40.0f) / 202.0f; k = 0.5675f; k *= t; func_003AB810(q, k + 0.005f); }
            f = D_001D8434_003ACD00;
            if (zero < f) {
                func_003AB810(q, f);
            }
            g = ((f32)o->f18C - k14) / 152.0f;
            func_003AB810(p, g * 0.85f + 0.03f);
            f = D_001D8438_003ACD00;
            if (zero <= f) {
                func_003AB810(p, f);
            }
            o->f1B0 = g * 306.0f + k23;
            break;
        }
        case 2:
            break;
        }
    }
}
/* localdecomp:end func_003ACD00 */
