/* functional: high. Compiles with the file flags; diff is stack layout and scheduling only; all control flow, constants and call args traced by hand against the asm. */
/* localdecomp:start func_L01_00349C58 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_00349C58;
extern u8 D_L01_001D66B0[];
void func_L01_00349C58(u8 *m) {
    extern void func_L01_004CAB30(void *, void *);
    extern void func_L01_0034C378(u8 *);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_0038CB00(void *);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(void *);
    extern void func_L01_00404AD8(void *, void *);
    extern s32 func_L01_0034ACD8(void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_004CABD8(void *, void *, void *);
    extern void *func_L01_00470668(void *, void *, s32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);
    extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
    extern s32 func_00382468(s32);
    u8 *v = *(u8 **)(m + 0x68);
    Vec_00349C58 q10, q20, q30, q40, q50, q60;
    s32 state, n, i;
    f32 t, d, lim, nf, f;

    func_L01_004CAB30(m + 0x10, m + 0x10);
    func_L01_0034C378(v);
    *(f32 *)(v + 0x00) = func_0038DAB8(*(f32 *)(v + 0x00), 0.05235987901687622f);
    *(f32 *)(v + 0x04) = func_0038DAB8(*(f32 *)(v + 0x04), 0.003490658476948738f);
    *(f32 *)(v + 0x08) = func_0038DAB8(*(f32 *)(v + 0x08), 0.004363323096185923f);
    *(f32 *)(v + 0x0C) = func_0038DAB8(*(f32 *)(v + 0x0C), -0.004363323096185923f);
    *(f32 *)(v + 0x10) = func_0038DAB8(*(f32 *)(v + 0x10), 0.006981316953897476f);
    *(f32 *)(v + 0x14) = func_0038DAB8(*(f32 *)(v + 0x14), -0.006981316953897476f);
    func_0038CB00(v + 0x1E);
    func_0038CB00(v + 0x34);
    func_0038CAD0(v + 0x40);
    if (func_0038CB00(v + 0x1C) != 0) {
        if (*(s16 *)(v + 0x1E) == 0) {
            if (*(s32 *)(v + 0x4C) == 0) func_003C2880(m);
            return;
        }
    }
    state = *(s32 *)(v + 0x50);
    if (state < 4) func_L01_00404AD8((void *)func_L01_0034ACD8, m);

    if (*(s16 *)(v + 0x1E) >= 0x2D) {
        state = *(s32 *)(v + 0x50);
        if (state == 3) n = 5;
        else if (state < 4) { if (state == 2) n = 10; else n = 20; }
        else if (state == 4) n = 2;
        else n = 20;
        do {
            n--;
            f = func_003824E0(16.0f, 32.0f);
            func_0038CE20(&q10, m + 0xC0, f * 0.020000001415610313f);
            t = func_L01_00443A18(0.2617993950843811f, 1.3962633609771729f);
            d = func_L01_00443A18(0.2617993950843811f, 1.3962633609771729f);
            func_003C4840(&q30, m + 0xD0, t);
            func_0038D850(&q20, &q10, &q30);
            func_003C4840(&q30, m + 0xC0, d);
            func_0038D850(&q20, &q20, &q30);
            i = (func_00382498(0x14, 0x28) * 5 + 2) / 6;
            func_L01_004CABD8(&q20, &q20, m + 0x10);
            func_L01_00470668(m + 0x10, &q20, i, 0.005840000230818987f);
        } while (n != 0);
        state = *(s32 *)(v + 0x50);
    } else {
        state = *(s32 *)(v + 0x50);
    }

    if (state < 3 && (u16)(*(u16 *)(v + 0x1E) - 11) < 0x16) {
        f32 a, b, c;
        f32 zero = 0.0f;
        f32 quarter = 0.25f, half = 0.5f;
        a = func_003824E0(-0.9599310755729675f, -1.3962633609771729f);
        b = func_00382538();
        c = func_003824E0(zero, half);
        func_00382760(&q10, c * 0.020000001415610313f, b, a);
        f = func_003824E0(quarter, 0.75f) * 210000.0f;
        func_0038CE20(&q20, m + 0xC0, -0.44999998807907104f);
        {
            Vec_00349C58 s = *(Vec_00349C58 *)(m + 0x10);
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(q20) : "m"(s), "m"(q20) : "vf1", "vf2");
        }
        q30.v[0] = q20.v[0] + func_L01_00443A18(zero, quarter);
        q30.v[1] = q20.v[1] + func_L01_00443A18(zero, quarter);
        q30.v[2] = q20.v[2] + func_L01_00443A18(zero, quarter);
        func_L01_004CABD8(&q10, &q10, &q30);
        func_L01_004708C8(&q30, &q10, 0x4F93E5FF, 0x102434EE, f, half, func_00382498(0x19, 0x25), 1, -1, -1, 0);
    }

    t = (f32)*(s16 *)(v + 0x1E);
    lim = (t * *(f32 *)(v + 0x24) * -3.0f + 4.0f) * 1.5f;
    d = *(f32 *)(m + 0x18) - *(f32 *)(v + 0x18);
    if (0.0f < d && d < lim && *(s16 *)(v + 0x1E) >= 0x16) {
        f32 one = 1.0f;
        f32 k;
        d = d / lim;
        *(s128 *)&q10 = 0;
        q10.v[2] = one;
        q10.v[3] = one;
        k = d * -0.6499999761581421f;
        n = (s32)((one - d) * 30.0f);
        k = k + 0.75f;
        if (!(0 < n)) n = 1;
        func_0038CE90(&q20, &q10, m + 0xC0);
        nf = (f32)n;
        func_0038CF68(&q20, &q20, lim * k);
        *(Vec_00349C58 *)&q30 = *(Vec_00349C58 *)(m + 0x10);
        q30.v[2] = *(f32 *)(v + 0x18) + 0.25f;
        {
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(q40) : "m"(q30), "m"(q20) : "vf1", "vf2");
            __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                    : "=m"(q50) : "m"(q30), "m"(q20) : "vf1", "vf2");
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(q60) : "m"(q50), "m"(q40) : "vf1", "vf2");
        }
        func_0038CE20(&q60, &q60, one / nf);
        state = *(s32 *)(v + 0x50);
        if (state == 3) n = (s32)(nf * 0.30000001192092896f);
        else if (state < 4) { if (state == 2) n = (s32)(nf * 0.6000000238418579f); }
        else if (state == 4) n = (s32)(nf * 0.10000000149011612f);
        if (n > 0) {
            i = n;
            do {
                s32 r = func_00382468(0x10);
                s32 neg = func_00382468(2);
                u8 *o;
                if (neg != 0) r = -r;
                f = func_003824E0(0.20000000298023224f, 1.5f);
                o = func_L01_004669B0(&q40, 0.30000001192092896f, 1.0f, 0.8999999761581421f, f * 210000.0f, r, D_L01_001D66B0, 0x7F204080, 1);
                __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                        : "=m"(q40) : "m"(q40), "m"(q60) : "vf1", "vf2");
                if (o != 0) {
                    s32 rr = func_00382498(8, 0x19);
                    o[9] = 0x44;
                    *(s16 *)(o + 0xA) = (rr * 5 + 2) / 6;
                    *(s32 *)(o + 0x24) = 2;
                    o[0x2A] = func_00382498(0x50, 0x7F);
                    o[0x2B] = o[0xA];
                }
            } while (--i != 0);
        }
    }
}
/* localdecomp:end func_L01_00349C58 */
