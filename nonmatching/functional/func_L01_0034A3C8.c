/* functional: high. 543-word diff but equal instruction multiset except o+0x20 pointer addressing; every loop, count table and constant traced by hand. */
/* localdecomp:start func_L01_0034A3C8 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_0034A3C8;
extern u8 D_L01_001D66B0[];
extern u8 D_L01_001E2A40[];
extern u8 D_L01_00221098[];
extern u8 D_001A4EC0[];
void func_L01_0034A3C8(u8 *m, f32 *unused, s32 kind) {
    extern s32 func_L01_00459590(void *, s32, f32);
    extern f32 func_0038CF00(void *, void *);
    extern void func_L01_0034C300(u8 *, f32);
    extern void func_L01_0044AF78(void *, void *, void *, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    Vec_0034A3C8 q20, q30, q40, q50, q60, q70;
    f32 heading, f, g, a, big, t;
    s32 n, i, r, sign, life;
    u8 *o;

    *(Vec_0034A3C8 *)&q20 = *(Vec_0034A3C8 *)(m + 0x10);
    q20.v[3] = 2.0f;
    if (func_L01_00459590(&q20, 0, 48.0f) == 1) {
        func_L01_0034C300(*(u8 **)(m + 0x68), func_0038CF00(m + 0x10, D_L01_001E2A40));
        *(s32 *)(D_L01_001E2A40 + 0x28) = 0x21;
        *(f32 *)(D_L01_001E2A40 + 0x20) = 0.10000000149011612f;
        *(s32 *)(D_L01_001E2A40 + 0x2C) = 0;
    }
    func_L01_0044AF78(m, D_L01_001D66B0, m + 0x10, 0, 0, 0, 0.0f, 0.0f, 0.0f, 0.0f,
                      -1, 0, 0, -1, 0, 0x1010001, 9.0f, 0.0f, 20.0f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(q30) : "m"(*(Vec_0034A3C8 *)D_L01_001E2A40), "m"(*(Vec_0034A3C8 *)(m + 0x10)) : "vf1", "vf2");
    func_0038CF68(&q30, &q30, 0.5f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(q40) : "m"(*(Vec_0034A3C8 *)(m + 0x10)), "m"(q30) : "vf1", "vf2");
    *(Vec_0034A3C8 *)(m + 0x10) = q40;
    heading = func_0038D160(*(f32 *)D_L01_001E2A40 - *(f32 *)(m + 0x10),
                            *(f32 *)(D_L01_001E2A40 + 4) - *(f32 *)(m + 0x14));

    if (kind == 3) n = 5;
    else if (kind < 4) { if (kind == 2) n = 10; else n = 20; }
    else if (kind == 4) n = 1;
    else n = 20;
    sign = 1;
    if (n != 0) {
        i = n;
        do {
            sign = -sign;
            q50.v[0] = q40.v[0] + func_L01_00443A18(0.0f, 1.0f);
            q50.v[1] = q40.v[1] + func_L01_00443A18(0.0f, 1.0f);
            q50.v[2] = q40.v[2] + func_L01_00443A18(0.0f, 1.0f);
            f = func_003824E0(0.020000001415610313f, 0.04000000283122063f);
            a = func_L01_00443A18(0.0f, 1.3962633609771729f);
            g = func_0038DAB8(heading, func_L01_00443A18(0.0f, 1.5707963705062866f));
            func_00382760(&q60, f, g, a);
            o = func_L01_004669B0(&q50, 0.0f, 1.0f, 1.0099999904632568f, 315000.0f, sign, &q60, 0x7F60A0FF, 1);
            if (o != 0) {
                r = func_00382498(0x28, 0x46);
                o[9] = 0x44;
                *(s16 *)(o + 0xA) = (r * 5 + 2) / 6;
                *(s32 *)(o + 0x24) = 3;
                r = func_00382498(1, 0xA);
                o[0x2A] = 0x40;
                *(f32 *)(o + 0x3C) = (f32)((r * 5 + 2) / 6);
                o[0x2B] = o[0xA];
            }
        } while (--i != 0);
    }

    if (kind == 3) n = 8;
    else if (kind < 4) { if (kind == 2) n = 16; else n = 32; }
    else if (kind == 4) n = 2;
    else n = 32;
    if (n != 0) {
        i = n;
        do {
            s32 r1, r2, life2;
            r1 = (s32)func_L01_00443A18(2.0f, 5.0f);
            r2 = func_00382498(0x32, 0x50);
            q50.v[0] = q40.v[0] + func_L01_00443A18(0.0f, 0.10000000149011612f);
            q50.v[1] = q40.v[1] + func_L01_00443A18(0.0f, 0.10000000149011612f);
            q50.v[2] = q40.v[2] + func_L01_00443A18(0.0f, 0.10000000149011612f);
            f = func_003824E0(0.3499999940395355f, 0.75f);
            big = f * 210000.0f;
            t = func_003824E0(4.0f, 8.0f) * 0.020000001415610313f;
            a = func_L01_00443A18(0.0f, 1.3962633609771729f);
            g = func_0038DAB8(heading, a);
            q60.v[0] = func_0038D098(g) * t;
            q60.v[1] = func_0038D0B0(g) * t;
            q60.v[2] = 0.0f;
            q60.v[2] = func_003824E0(0.0f, 12.0f) * 0.020000001415610313f;
            life2 = (r2 * 5 + 2) / 6;
            func_L01_0046FB40(&q50, &q60, life2, 0x7F7F7F, r1, 0x7F, 0x7F, big, 2100.0f, 0.005840000230818987f, 1);
            q70.v[0] = q50.v[0] + func_L01_00443A18(0.0f, 0.009999999776482582f);
            q70.v[1] = q50.v[1] + func_L01_00443A18(0.0f, 0.009999999776482582f);
            q70.v[2] = q50.v[2] + func_L01_00443A18(0.0f, 0.009999999776482582f);
            func_L01_0046FB40(&q70, &q60, life2, 0x7F7F7F, -r1, 0x7F, 0x7F, big, 2100.0f, 0.005840000230818987f, 1);
            r1 = r1 << 1;
            f = f * 6.0f;
            o = func_L01_0046FB40(&q50, &q60, life2, 0x202080, -r1, 0x30, 0x30, f * 210000.0f, 4200.0f, 0.005840000230818987f, 1);
            if (o != 0) o[2] = **(u8 **)(D_L01_00221098 + 0xD4);
        } while (--i != 0);
    }

    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(q50) : "m"(q40), "m"(*(Vec_0034A3C8 *)D_L01_001E2A40) : "vf1", "vf2");
    func_0038CF68(&q50, &q50, 1.0f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(q40) : "m"(q40), "m"(q50) : "vf1", "vf2");

    if (kind == 3) n = 5;
    else if (kind < 4) { if (kind == 2) n = 10; else n = 20; }
    else if (kind == 4) n = 1;
    else n = 20;
    if (n != 0) {
        i = n;
        do {
            s32 lifeC;
            f = func_003824E0(0.20000000298023224f, 3.0f);
            func_0038CE20(&q60, D_001A4EC0, -(f * 0.020000001415610313f));
            lifeC = (func_00382498(0x5A, 0xB4) * 5 + 2) / 6;
            r = (s32)func_L01_00443A18(1.0f, 2.0f);
            big = func_003824E0(0.5f, 1.5f) * 210000.0f;
            q70.v[0] = q40.v[0] + func_L01_00443A18(0.0f, 0.75f);
            q70.v[1] = q40.v[1] + func_L01_00443A18(0.0f, 0.75f);
            q70.v[2] = q40.v[2] + func_L01_00443A18(0.0f, 0.75f);
            o = func_L01_004669B0(&q70, 0.0f, 1.0f, 1.0099999904632568f, big, r, &q60, 0x7F202020, 1);
            if (o != 0) {
                *(s16 *)(o + 0xA) = lifeC;
                o[3] = 0x44;
                o[9] = 0x44;
                r = func_00382498(7, 0xF);
                *(s32 *)(o + 0x24) = 3;
                o[0x2A] = 0x7F;
                *(f32 *)(o + 0x3C) = (f32)((r * 5 + 2) / 6);
                o[0x2B] = o[0xA];
            }
        } while (--i != 0);
    }
}
/* localdecomp:end func_L01_0034A3C8 */
