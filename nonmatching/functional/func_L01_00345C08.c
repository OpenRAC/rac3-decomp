/* functional: high. Diff is addressing/scheduling only; every branch, loop count (10/10/10/12/14) and colour constant transcribed from asm. */
/* localdecomp:start func_L01_00345C08 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_00345C08;
extern u8 D_001425C0[];
extern S_00341C10 D_L01_002C5600[];
extern u8 D_001A4BE0[];
extern u8 D_L01_001E2DC0[];
extern u8 D_L01_001E2A40[];
extern u8 D_001A57B8[];
extern u8 D_L01_001D66B0[];
__asm__(".extern D_L01_001DAFEC, 4");
extern s32 D_L01_001DAFEC;
void func_L01_00345C08(u8 *self) {
    extern void func_003C2F58(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern s32 func_L01_00424B88(f32, f32, void *, s32);
    extern void func_L01_004CAC78(void *, void *, f32, f32, f32);
    extern void func_L01_00457588(u8 *, void *, void *, f32);
    extern void func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern u8 *func_L01_00346CC8(u8 *, u8 *, s32, s32);
    extern void func_L01_0037D920(u8 *, void *, void *, void *, s32, s32, s32, f32);
    extern void func_00382580(void *, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
    extern u8 *func_L01_0046B458(f32 *, f32, s32, f32, f32, s32, s32, s32, f32 *, s32);
    extern u8 *func_L01_00470C78(u8 *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
    Vec_00345C08 q10, q20, q30, q40, q50;
    u8 *v = *(u8 **)(self + 0x68);
    u8 *fp, *t, *r;
    f32 f20, f;
    s32 mode, w, tier;
    s32 c16, c17;

    f20 = *(f32 *)(((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0) + 0x4C) * 0.020000001415610313f;
    if (*(s16 *)(D_001A4BE0 + 0x2874) == 1) {
        func_003C2F58(self, 1, &q10);
        func_0038CF68(&q20, self + 0xD0, -f20);
    } else if (*(s32 *)(D_001A4BE0 + 0x16B0) != 0) {
        func_003C2F58(self, 1, &q10);
        func_0038CF68(&q20, D_L01_001E2DC0, f20);
    } else {
        func_003C2F58(self, 1, &q10);
        func_0038CF68(&q20, D_001A4BE0 + 0x6F0, f20);
    }
    fp = (u8 *)&q20;
    mode = 0;
    *(s32 *)(v + 0x10) = func_L01_00424B88(10.0f, 0.0f, &q10, 0xFF0000FF);
    *(s32 *)(v + 0x14) = 0x19;
    w = *(s32 *)(D_001A4BE0 + 0x25C4);
    if (w == 1 || w == 0x1D) {
        if (D_001A4BE0[0x25E5] != 0) {
            mode = 2;
            func_L01_004CAC78(fp, &q10, f20, 128.0f, 0.3490658402442932f);
            goto have_flag;
        }
    }
    if (*(s32 *)(D_001A4BE0 + 0xBD8) != 0) func_L01_00457588(*(u8 **)(D_001A4BE0 + 0xBD8), &q10, fp, f20);
have_flag:
    if (D_L01_001DAFEC != 0) {
        t = *(u8 **)(v + 0x2C);
        if ((t != 0 && *(s32 *)(D_001A4BE0 + 0x16B0) != 0) ||
            (*(s32 *)(D_001A4BE0 + 0xBD8) != 0 && *(s32 *)(D_001A4BE0 + 0x16B0) == 0)) {
            if (t != 0) q30 = *(Vec_00345C08 *)(t + 0x10);
            else q30 = *(Vec_00345C08 *)D_001A57B8;
            __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                    : "=m"(q40) : "m"(q10), "m"(q30) : "vf1", "vf2");
            func_0038CF68(&q50, fp, 1.0f);
            mode = 2;
            f = func_0038CE68(&q50, &q40);
            func_0038CE20(fp, &q50, f + 3.0f);
        }
    }
    func_0038CE20(&q30, self + 0xD0, -1.5f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(q30) : "m"(q30), "m"(*(Vec_00345C08 *)(self + 0x10)) : "vf1", "vf2");
    func_0038CE20(&q40, self + 0xC0, 0.2750000059604645f);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(q30) : "m"(q30), "m"(q40) : "vf1", "vf2");
    func_L01_00446780(self, &q10, 0x10000, 0, 1, 0, 1.5f, *(f32 *)(((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0) + 0x6C), 1.0f);
    r = func_L01_00346CC8((u8 *)&q10, fp, *(s32 *)(v + 0x18), mode);
    if (r != 0) *(u8 **)(r + 0xB8) = self;

    w = *(s32 *)(D_001A4BE0 + 0x25C4);
    if ((w == 1 || w == 0x1D) && D_001A4BE0[0x25E5] != 0) {
        if (*(s32 *)(D_001A4BE0 + 0x16B0) != 0 || *(s32 *)(D_001A4BE0 + 0x25C4) == 0x1D) {
            func_L01_0037D920(self, D_L01_001E2A40, fp, D_L01_001E2A40 + 0x380,
                              (((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0)[1] < 3) ? 0x10000 : 0x110000, 0, 1, *(f32 *)(((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0) + 0x6C));
        }
        return;
    }
    c16 = 0xBF204080;
    c17 = 0xBF2040A0;
    tier = ((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0)[1];
    if (tier == 0) {
        {
            s32 cnt = 9;
            do {
                func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0x80408020, 0xFF00, 0, 0);
            } while (--cnt >= 0);
        }
        c16 = 0xBF408020;
        c17 = 0xBF406020;
    }
    if (((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0)[1] == 1) {
        {
            s32 cnt = 9;
            do {
                func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0x80804020, 0xFF0000, 0, 0);
            } while (--cnt >= 0);
        }
        c16 = 0xBF804020;
        c17 = 0xBF604020;
    }
    if (((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0)[1] == 2) {
        c16 = 0xBF804020;
        c17 = 0xBF204080;
        {
            s32 cnt = 9;
            do {
                func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0xBF1432A0, 0xFF, 0, 0);
            } while (--cnt >= 0);
        }
    }
    if (((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0)[1] == 3) {
        c16 = 0xBF204080;
        c17 = 0xBF2040A0;
        {
            s32 cnt = 11;
            do {
                func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0xBF1414A0, 0xFF, 0, 0);
            } while (--cnt >= 0);
        }
    }
    if (((u8 *)D_L01_002C5600 + D_001425C0[0x6F] * 0xF0)[1] >= 4) {
        c16 = 0xBF804020;
        c17 = 0xBF604020;
        {
            s32 cnt = 13;
            do {
                func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0xBF1414A0, 0xFF, 0, 0);
            } while (--cnt >= 0);
        }
    }
    func_L01_0046B458((f32 *)&q10, 5.25f, 0xE, 0.10000000149011612f, 0.0f, c16, 2, 1, (f32 *)D_L01_001D66B0, 1);
    func_L01_0046B458((f32 *)&q10, 3.75f, 0xE, 0.10000000149011612f, 0.0f, c17, 2, -1, (f32 *)D_L01_001D66B0, 1);
    func_L01_0046B458((f32 *)&q10, 2.625f, 0xE, 0.10000000149011612f, 0.0f, 0xC0FFFFFF, 2, 1, (f32 *)D_L01_001D66B0, 1);
    func_L01_0046B458((f32 *)&q10, 1.875f, 0xE, 0.10000000149011612f, 0.0f, 0xB0FFFFFF, 2, -1, (f32 *)D_L01_001D66B0, 1);
    func_L01_00470C78((u8 *)&q10, 0x11, 1.0800000429153442f, 0.8400000333786011f, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1);
    func_L01_00470C78((u8 *)&q10, 0x11, 2.0400002002716064f, 0.8400000333786011f, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1);
    func_L01_00470C78((u8 *)&q10, 0x11, 2.4000000953674316f, 1.8000000715255737f, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1);
}
/* localdecomp:end func_L01_00345C08 */
