/* functional: high. Decoded line by line from PAL asm (COP1 words 0x46000184/46010044/46000004 are sqrt.s, written with sqrt_asm as the file's headers do); 176 diffs are register allocation and scheduling only. Cfg offsets: 08 wavelength base, 0C amplitude scale, 10/14 hi/lo, 18 base angle, 1C step, 20 blend. */
typedef struct Wave_0030FC68 {
    f32 amp;
    f32 f04;
    f32 f08;
    f32 phase;
    f32 dirx;
    f32 diry;
    f32 f18;
} Wave_0030FC68;

typedef struct Cfg_0030FC68 {
    u8 pad00[8];
    f32 f08;
    f32 f0C;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
} Cfg_0030FC68;

extern Wave_0030FC68 D_L02_0026EB80[];
extern s32 D_001DC570_sda[];
__asm__(".extern D_001DC570_sda, 4");
extern f32 D_L02_001E00BC;
extern f32 D_L02_001E00D8;
extern f32 D_L02_001E00DC;
extern f32 func_L02_0030FB58(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L02_0030FC68(Cfg_0030FC68 *s) {
    s32 i;
    f32 lo, hi, mid, g, t, sn, cs, sx, sy, sum;
    f32 twopi;
    Wave_0030FC68 *w;

    sx = 0.0f;
    sy = 0.0f;
    sum = 0.0f;
    hi = s->f10;
    lo = s->f14;
    mid = sqrt_asm(hi * lo);
    for (i = 0; i < 8; i++) {
        w = &D_L02_0026EB80[i];
        w->f04 = (s->f18 + s->f1C * 45.0f * ((f32)D_001DC570_sda[i] - 3.5f)) * 0.017453292f;
        if (i < 4) {
            g = lo + (mid - lo) * s->f20 * (f32)i * 0.29166666f;
        } else {
            g = hi + (mid - hi) * s->f20 * (f32)(7 - i) * 0.29166666f;
        }
        w->f08 = g;
        w->phase = (f32)i * 0.7853982f;
        w->amp = w->f08 * s->f0C;
    }
    twopi = 6.2831855f;
    D_L02_001E00BC = (s->f08 * twopi * s->f08 + s->f08 * twopi * s->f08) / (lo + D_L02_0026EB80[3].f08);
    for (i = 0; i < 8; i++) {
        w = &D_L02_0026EB80[i];
        t = func_L02_0030FB58(w->f04);
        g = w->f08;
        sn = func_0038D098(t);
        cs = func_0038D0B0(t);
        sn = sn * twopi / g;
        cs = cs * twopi / g;
        w->dirx = sn;
        w->diry = cs;
        w->f18 = -sqrt_asm(D_L02_001E00BC * twopi / g);
        if (sn >= 0.0f) {
            sx += w->amp * sn;
        } else {
            sx -= w->amp * sn;
        }
        if (cs >= 0.0f) {
            sy += w->amp * cs;
        } else {
            sy -= w->amp * cs;
        }
        sum += w->amp;
    }
    D_L02_001E00DC = sum;
    D_L02_001E00D8 = sqrt_asm(sx * sx + sy * sy);
}
