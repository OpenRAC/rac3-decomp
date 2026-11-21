/* func_L02_0030FC68 (732 bytes, 22 places, shared file L02_0030FA80.c, twin `asm`): 19 diff with the file's flags (@ps2as, -mvu0-use-vf0-vf2) and the
   divs_nops row `func_L02_0030FC68 2 0 2 2 2 2 2` (not committed; add it with the matched C: the three sqrt.s and the four div.s).
   A fan of eight shots (a trajectory table of 28-byte entries at D_L02_0026EB80): loop 1 fills each entry from the object's angle/speed/scale floats
   (sqrt_asm of the product f10 * f14, the 45 / 3.5 / 0.2917 / pi/4 constants), loop 2 asks func_L02_0030FB58 / func_0038D098 / func_0038D0B0 for the
   wrapped angle and its sine and cosine and sums the weighted components (and a negated sqrt of D_L02_001E00BC * 2pi / entry speed).
   Everything but register numbers is retail's. What differs (all register choices, one extra `mov.s`):
   (1) the zero held for the three accumulators: retail loads it into sw ($f28) and copies it into sb ($f25) then sa ($f24); gcc loads it into sa ($f24) and
   copies it into sw and sb; (2) the end: retail has sa*sa in $f0 and sb*sb in $f1 (add.s $f0,$f0,$f1, sqrt.s $f0,$f0, the store in the jr slot and the
   result already in $f0); gcc has them the other way round, so the sum lands in $f1 and a `mov.s $f0,$f1` follows.
   What paid: reading the table through `D_L02_0026EB80[i].fXX` in both loops (a pointer `e = &D[i]` made one giv where retail has two: 40 -> 26 aligned);
   no variable for 2pi (the literal everywhere: 26 -> 16); the stores of the entry in the order f00 then f0C (16 -> 8).
   Tried without effect (all 8 or worse): the three accumulators' declaration order (all 6) with 4 initialisation forms, chains and copies, sw initialised at
   its declaration, the final expression as sb*sb + sa*sa / temporaries / a result local / a reload, a greedy climb over the declaration order of all locals,
   a separate counter for loop 2, a pointer loop. The allocation order from -dl (sa 13 refs, sb 11, sw 6) already equals retail's; only the zero holder differs. */
/* localdecomp:start func_L02_0030FC68 */
typedef struct { f32 f00, f04, f08, f0C, f10, f14, f18; } Ent_0030FC68;
typedef struct {
    u8 pad0[8];
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
} P_0030FC68;

extern Ent_0030FC68 D_L02_0026EB80[8];
extern s32 D_L02_001DC570[2];
__asm__(".extern D_L02_001DC570, 8");
extern f32 D_L02_001E00BC;
__asm__(".extern D_L02_001E00BC, 16");
extern f32 D_L02_001E00D8;
__asm__(".extern D_L02_001E00D8, 16");
extern f32 D_L02_001E00DC;
__asm__(".extern D_L02_001E00DC, 16");
extern f32 func_L02_0030FB58(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

f32 func_L02_0030FC68(P_0030FC68 *p) {
    s32 i;
    s32 j;
    f32 f5 = p->f10;
    f32 f4 = p->f14;
    f32 sa;
    f32 sb;
    f32 sw = 0.0f;
    f32 r;
    f32 a;
    f32 w;
    f32 ang;
    f32 sn;
    f32 cs;
    f32 q;
    f32 vx;
    f32 vy;

    sa = sw;
    sb = sw;
    r = sqrt_asm(f5 * f4);
    for (i = 0; i < 8; i++) {
        D_L02_0026EB80[i].f04 = (p->f18 + p->f1C * 45.0f * ((f32)D_L02_001DC570[i] - 3.5f)) * 0.0174532924f;
        if (i < 4) {
            D_L02_0026EB80[i].f08 = f4 + (r - f4) * p->f20 * (f32)i * 0.291666657f;
        } else {
            D_L02_0026EB80[i].f08 = f5 + (r - f5) * p->f20 * (f32)(7 - i) * 0.291666657f;
        }
        D_L02_0026EB80[i].f00 = D_L02_0026EB80[i].f08 * p->f0C;
        D_L02_0026EB80[i].f0C = (f32)i * 0.785398185f;
    }
    D_L02_001E00BC = p->f08 * 6.28318548f * p->f08 * 2.0f / (f4 + D_L02_0026EB80[3].f08);
    for (j = 0; j < 8; j++) {
        w = D_L02_0026EB80[j].f08;
        a = D_L02_0026EB80[j].f00;
        ang = func_L02_0030FB58(D_L02_0026EB80[j].f04);
        sn = func_0038D098(ang);
        cs = func_0038D0B0(ang);
        vx = sn * 6.28318548f / w;
        vy = cs * 6.28318548f / w;
        q = D_L02_001E00BC * 6.28318548f / w;
        D_L02_0026EB80[j].f10 = vx;
        D_L02_0026EB80[j].f14 = vy;
        D_L02_0026EB80[j].f18 = -sqrt_asm(q);
        if (0.0f <= vx) {
            sa += a * vx;
        } else {
            sa -= a * vx;
        }
        if (0.0f <= vy) {
            sb += a * vy;
        } else {
            sb -= a * vy;
        }
        sw += a;
    }
    D_L02_001E00DC = sw;
    return D_L02_001E00D8 = sqrt_asm(sa * sa + sb * sb);
}
/* localdecomp:end func_L02_0030FC68 */
