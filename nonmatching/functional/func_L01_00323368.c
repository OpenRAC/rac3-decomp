/* functional: medium. Written from the asm (no draft); compiles under file flags, not byte-exact (423 words differ, same frame size 0xA0). Blocks read one by one incl. branch-likely delay slots; floats from raw hex. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00323368;
extern u8 D_001A4BE0[];
extern s32 D_001D6694;
extern s32 D_L01_001E1830;
extern s32 D_L01_001E1834;
extern s32 D_L01_001E1850;
extern s32 D_L01_001DCA00;
extern V_00323368 D_L01_001DC9A0;
extern V_00323368 D_L01_001DC9B0;
extern V_00323368 D_001E29C0;
extern V_00323368 D_001E29E0;
extern u8 D_L01_002AE990[];
extern s32 D_001D52FC;
#define D000_00323368 ((void (*)(void *, void *, void *))func_0038D000)
#define CF68_00323368 ((void (*)(void *, void *, f32))func_0038CF68)
#define CAD0_00323368 ((s32 (*)(void *))func_0038CAD0)
#define G_00323368(off, T) (*(T *)(D_001A4BE0 + (off)))
void func_L01_00323368(u8 *m) {
    extern void func_00323F38();
    extern u8 *func_L01_004572B0(u8 *, s32, s32 *);
    extern u8 *func_L01_00457410(u8 *);
    extern void func_L01_00444F38(u8 *, s32, s32, s32, s32);
    extern void func_L01_0040E050(void *);
    extern u8 *func_L01_00450BB0(void *, void *, s32, f32, f32, f32, f32, f32);
    extern void func_L01_004CB128(void *, u8 *, s32);
    extern f32 func_0038CF00(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_L01_004CB1F0(f32, f32);
    extern s32 func_L01_005118D0(s32, s32);
    extern void func_L01_004EA7D8(s32, u8 *);
    extern void func_003C3A10(u8 *, s32, s32, s32);
    extern s32 func_L01_003F2058(void *, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_003A52A0(s32, s32, u8 *);
    extern void func_L01_00385228(void *, u8 *, u8 *);
    extern void func_L01_00404A10(void *, u8 *);
    extern void func_L01_00323A18(u8 *);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32, s32);
    extern s32 func_L01_003F1FC0(s32, s32);
    extern void func_L01_003F6F20(s32, u8 *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    V_00323368 sp0, sp10, sp20;
    u8 *vars = *(u8 **)(m + 0x68);
    u8 *obj;
    u8 *P;
    u8 *hero;
    s16 idx;
    s32 found, i;
    f32 f20;
    if (m[0x20] == 0) {
        m[0x30] = 0xFF;
        D_L01_001E1834 = 0;
        *(s16 *)(vars + 0x58) = -1;
        m[0x20] = 1;
        idx = (s16)(s32)func_L01_004572B0(m, 0, &found);
        *(s16 *)(vars + 0x5A) = idx;
        if (found == 0) {
            u8 *p = (u8 *)func_L01_00457480(*(s16 *)(m + 0xAA), idx);
            s32 v = (s32)func_L01_00457410(p + 0x40);
            for (i = 0; i < 16; i++) {
                *(s32 *)(p + i * 4) = v;
                v += 0x280;
            }
        }
    }
    if (G_00323368(0x25C4, s32) == 1) func_L01_005003D0(0x1D, 1);
    if (m[0x42] == m[0x43]) {
        if (m[0x60] & 2) func_L01_00444F38(m, 1, 0, 2, 0);
    }
    func_L01_0040E050(vars + 0x50);
    func_0038D000(&sp0, &D_L01_001DC9A0, m + 0xC0);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(sp0) : "m"(sp0), "m"(*(V_00323368 *)(m + 0x10)) : "vf1", "vf2");
    *(V_00323368 *)(vars + 0x10) = sp0;
    func_0038D000(&sp10, &D_L01_001DC9B0, m + 0xC0);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(sp10) : "m"(sp10), "m"(*(V_00323368 *)(m + 0x10)) : "vf1", "vf2");
    *(V_00323368 *)(vars + 0x20) = sp10;
    func_0038CF68(vars + 0x40, m + 0xD0, -20.0f);
    func_0038CF68(vars + 0x30, G_00323368(0x25C0, u8 *) + 0xC0, 1.0f);
    obj = func_L01_00450BB0(vars + 0x10, vars + 0x30, 0, 0.0523f, 0.0523f, 35.0f, 0.7853982f, 0.6109f);
    if (obj) {
        func_L01_004CB128(&sp20, obj, 0);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(V_00323368 *)(vars + 0x30)) : "m"(sp20), "m"(*(V_00323368 *)(vars + 0x10)) : "vf1", "vf2");
        func_0038CF68(vars + 0x30, vars + 0x30, 20.0f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(V_00323368 *)vars) : "m"(*(V_00323368 *)(vars + 0x30)), "m"(sp0) : "vf1", "vf2");
        if (G_00323368(0x25C4, s32) != 0x1D && G_00323368(0x16B0, s32) == 0) {
            f20 = func_0038CF00(&D_001E29C0, &sp20) / 150.0f;
            *(f32 *)(vars + 0x5C) = func_0038DAB8(*(f32 *)(vars + 0x5C), 0.0345f);
            f20 = f20 * 0.65f;
            func_L01_003F6F20(0, m, 0xFF0FFF0F, &sp20, 0x26, -1, 4,
                              __builtin_fabsf(0.9f - f20), -*(f32 *)(vars + 0x5C), 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
            G_00323368(0xBD8, u8 *) = obj;
        }
    }
    if (G_00323368(0x25C4, s32) == 0x1D || G_00323368(0x16B0, s32) != 0) {
        func_0038CF68(vars + 0x30, &D_001E29E0, 20.0f);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(V_00323368 *)vars) : "m"(*(V_00323368 *)(vars + 0x30)), "m"(sp0) : "vf1", "vf2");
        func_L01_003F6F20(0, m, func_L01_004CB1F0(0.99f, 150.0f), 0, 0x56, -1, 4,
                          0.75f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        G_00323368(0xBD8, u8 *) = obj;
    } else {
        if (!obj) {
            func_0038CF68(vars + 0x30, G_00323368(0x25C0, u8 *) + 0xC0, 20.0f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(*(V_00323368 *)vars) : "m"(*(V_00323368 *)(vars + 0x30)), "m"(sp0) : "vf1", "vf2");
        }
        G_00323368(0x16D8, s32) = 0;
        G_00323368(0x16D4, s32) = 0;
    }
    P = (u8 *)D_001D52FC;
    if (!(G_00323368(0x25ED, u8) == 0 && D_001D6694 == 0 && G_00323368(0x1220, s32) >= 0x13 && m[0x42] < 2
          && (*(s32 *)(P + 0x1A0) & G_00323368(0x1210, s32)))) {
        if (!((*(s32 *)(P + 0x1A0) & 8) && G_00323368(0x25C4, s32) == 0x1D)) {
            func_L01_004EAA80();
            D_L01_001E1830 = 0;
            if (*(s32 *)(vars + 0x54) <= 0) D_L01_001E1834 = 0;
            goto after;
        }
    }
    D_L01_001E1834 = D_L01_001E1834 + 1;
    *(s32 *)(vars + 0x54) = 0x11;
    if (func_0038CAD0(&D_L01_001E1830)) {
        if (func_L01_005118D0(-1, 1)) {
            f20 = 3.0f;
            func_L01_004EA7D8(-1, (u8 *)D_001D52FC);
            *(f32 *)(m + 0x48) = f20;
            if (m[0x43] != 2) func_003C3A10(m, 2, 0, 0);
            *(f32 *)(m + 0x48) = f20;
            D_L01_001E1850 = 1;
            *(s16 *)(vars + 0x58) = (s16)func_L01_003F2058(D_L01_002AE990, 0);
            func_0038CF68(&sp20, vars + 0x30, func_003824E0(60.0f, 80.0f) * 0.02f);
            func_003A52A0(3, 0, m);
            if (D_L01_001DCA00) {
                func_L01_00385228(vars + 0x20, m, obj);
                D_L01_001DCA00 = 0;
            } else {
                func_L01_00385228(vars + 0x10, m, obj);
                D_L01_001DCA00 = 1;
            }
            D_L01_001E1830 = 8;
            func_L01_00404A10(func_00323F38, m);
            func_L01_00323A18(m);
        } else {
            if ((*(s32 *)((u8 *)D_001D52FC + 0x1A4) & G_00323368(0x1210, s32)) || D_L01_001E1850 == 1) {
                func_003A52A0(4, 0, m);
                D_L01_001E1850 = 0;
            }
        }
    }
after:
    P = (u8 *)D_001D52FC;
    if ((*(s32 *)(P + 0x1A0) & G_00323368(0x1210, s32)) == 0 || func_L01_005119E0(-1) == 0
        || G_00323368(0x25E9, u8) == 0) {
        if (*(s16 *)(vars + 0x58) >= 0) {
            func_L01_003F2278(*(s16 *)(vars + 0x58), 0);
            *(s16 *)(vars + 0x58) = -1;
        }
    } else {
        s32 h = *(s16 *)(vars + 0x58);
        if (h > 0) {
            if (func_L01_003F1FC0(h - 1, 0) == 0) *(s16 *)(vars + 0x58) = -1;
        }
    }
}
