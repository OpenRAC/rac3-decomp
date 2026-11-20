/* functional: high. Vector subtractions are retail's VU0 ops (lqc2/vsub.xyz/sqc2 on vf1/vf2) so VU0 state left for the callees is retail's. Signature taken from the matched callers (30 args: 8 ints, 4 floats in f12-f15, 18 stack ints); every store and call read against the PAL asm; byte diff is scheduling/stack only. */
typedef int Q_3303B8 __attribute__((mode(TI)));
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern u8 D_L01_001E2A40[];
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L01_0044C870(void *, s32, void *, void *);
extern s32 func_L01_00459590(f32, void *, s32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_00331230(void *, void *, void *, f32);

u8 *func_L01_003303B8(void *pos, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7,
                      f32 sz, f32 f13, f32 f14, f32 f15,
                      s32 h18, s32 h1C, s32 h1A, s32 h1E, s32 h16, s32 h3C, s32 w64, s32 w38,
                      s32 w40, s32 w44, s32 w48, s32 w4C, s32 w50, s32 w54, s32 w58, s32 w5C,
                      s32 w60, s32 h36) {
    u8 *o;
    u8 *pv;
    u8 *e;
    Q_3303B8 v0 __attribute__((aligned(16)));
    Q_3303B8 v10 __attribute__((aligned(16)));
    Q_3303B8 v20 __attribute__((aligned(16)));
    Q_3303B8 v30 __attribute__((aligned(16)));
    Q_3303B8 v40 __attribute__((aligned(16)));
    f32 d, t;

    o = func_003C24B0(0x13A1, 0x80);
    if (o != 0) {
        o[0x30] = 0xFF;
        *(s16 *)(o + 0x32) = 0xFF;
        o[0x20] = 0;
        pv = *(u8 **)(o + 0x68);
        *(Q_3303B8 *)(o + 0x10) = *(Q_3303B8 *)pos;
        *(f32 *)(o + 0x1C) = 1.0f;
        e = D_L01_001E2A40 + D_001D52F0 * 0x460;
        /* vsub through VU0 as retail: later retail callees (func_0038CF68's qmfc2/qmtc2 through
         * $at, func_0038CE90's full sqc2) carry vf2's w lane into memory, so vf1/vf2 must be left
         * as retail leaves them (vf1 = e - pos with e's w, vf2 = the moby's position). */
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(Q_3303B8 *)&v0) : "m"(*(Q_3303B8 *)e), "m"(*(Q_3303B8 *)(o + 0x10)) : "vf1", "vf2");
        func_0038CF68(&v0, &v0, 1.0f);
        func_003C5180(o + 0x10, &v10, 1);
        *(Q_3303B8 *)(o + 0xC0) = v0;
        func_0038CE90(o + 0xD0, o + 0xC0, &v10);
        func_0038CF68(o + 0xD0, o + 0xD0, 1.0f);
        func_0038CE90(o + 0xE0, o + 0xD0, o + 0xC0);
        *(f32 *)(o + 0xCC) = 0.0f;
        *(f32 *)(o + 0xEC) = 0.0f;
        *(f32 *)(o + 0xDC) = 0.0f;
        *(s32 *)(pv + 0x20) = a2;
        *(s32 *)(pv + 0x24) = a3;
        *(s32 *)(pv + 0x28) = a4;
        *(s32 *)(pv + 0x2C) = a5;
        *(s16 *)(pv + 0x32) = a6;
        *(s16 *)(pv + 0x1C) = h1C;
        *(s16 *)(pv + 0x12) = 0x32;
        *(f32 *)(pv + 0x0) = sz + sz;
        *(f32 *)(pv + 0x4) = sz * 4.0f;
        *(s16 *)(pv + 0x30) = a7;
        *(s16 *)(pv + 0x1A) = h1A;
        *(s16 *)(pv + 0x1E) = h1E;
        *(s16 *)(pv + 0x18) = h18;
        *(s16 *)(pv + 0x16) = h16;
        *(s16 *)(pv + 0x3E) = 7;
        *(s16 *)(pv + 0x3C) = h3C;
        *(s32 *)(pv + 0x40) = w40;
        *(s32 *)(pv + 0x44) = w44;
        *(s32 *)(pv + 0x48) = w48;
        *(s32 *)(pv + 0x4C) = w4C;
        *(s32 *)(pv + 0x50) = w50;
        *(s32 *)(pv + 0x54) = w54;
        *(s32 *)(pv + 0x58) = w58;
        *(s32 *)(pv + 0x5C) = w5C;
        *(f32 *)(pv + 0x6C) = f14;
        *(f32 *)(pv + 0x68) = f15;
        *(f32 *)(pv + 0xC) = sz;
        *(s16 *)(pv + 0x10) = 0x32;
        *(s32 *)(pv + 0x38) = w38;
        *(s32 *)(pv + 0x60) = w60;
        *(s32 *)(pv + 0x64) = w64;
        *(s16 *)(pv + 0x36) = h36;
        v20 = 0;
        if (w38 != 0) {
            func_L01_0044C870(o, w38, o + 0x10, &v20);
        }
        v30 = *(Q_3303B8 *)(o + 0x10);
        ((f32 *)&v30)[3] = sz * 3.0f;
        if (func_L01_00459590(128.0f, &v30, 0) != 1) {
            *(s16 *)(pv + 0x18) = 0;
            *(s16 *)(pv + 0x14) = 0;
        } else {
            *(s16 *)(pv + 0x14) = 8;
            *(f32 *)(pv + 0x8) = 0.125f;
            if (a1 != 0) {
                if (func_L01_0040E548(pos, D_L01_001E2A40 + D_001D52F0 * 0x460) < 2304.0f) {
                    *(s32 *)(D_L01_001E2A40 + 0x28) = 0x21;
                    *(f32 *)(D_L01_001E2A40 + 0x20) = 0.075f;
                    *(s32 *)(D_L01_001E2A40 + 0x2C) = 0;
                }
            }
            if (*(s16 *)(pv + 0x18) != 0) {
                e = D_L01_001E2A40 + D_001D52F0 * 0x460;
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                        : "=m"(*(Q_3303B8 *)&v40) : "m"(*(Q_3303B8 *)(o + 0x10)), "m"(*(Q_3303B8 *)e) : "vf1", "vf2");
                func_0038CF68(&v40, &v40, 1.0f);
                d = func_0038CE68(&v40, D_L01_001E2A40 + 0x380 + D_001D52F0 * 0x460);
                t = 1.5707964f - func_0038D0C8(d);
                *(s16 *)(pv + 0x18) = 0;
                if (t < 0.45378560f) {
                    *(s16 *)(pv + 0x18) = 1;
                }
            }
        }
        func_L01_00331230(o, &v10, &v20, f13);
    }
    return o;
}
