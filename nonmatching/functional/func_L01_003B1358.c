/* functional: high. rewritten from PAL asm (the repo draft is the NTSC-U twin with different callees); the two retail copies of the bounce block unified in a helper (phase 2 passes obj instead of obj+0xB8 as 4th arg of func_003D3CB0, kept); 242 diff lines (regalloc/frame) */
extern f32 func_00382538(void);
extern void func_L01_0046A610(void *, void *, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(void *, s32);
extern void func_L01_003B1D10(void *, s32, s32);
extern void func_L01_003B1DB8(void *);
extern void func_L01_00404A10(void *, u8 *);
extern void func_L01_003B1848(void);
extern void func_003C2880(void *);
extern u8 D_L01_001D66B0[];
extern u8 D_L01_001EAA00[];

static void bounce_3B1358(u8 *o, u8 *p, f32 *a, f32 f20, s32 id, f32 miss, s32 owner_arg) {
    f32 b[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 s60[4] __attribute__((aligned(16)));
    u8 c[0x30] __attribute__((aligned(16)));
    u8 *g;
    s32 hit;
    s32 take;

    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x34) + 0.4f;
    func_0038CF68(p + 0x10, p + 0x20, *(f32 *)(p + 0x34));
    func_0038CF68(b, p + 0x20, 0.08f);
    func_L01_00446760(c, o, 0x10000, b, f20);
    *(u16 *)(c + 0x1A) = *(u16 *)(o + 0xAA);
    vec_add_ab(p + 0x10, p, p + 0x10);
    func_0038CF68(d, p + 0x20, -0.4f);
    vec_add_ab(d, d, p + 0x10);
    hit = func_003D3CB0(p + 0x10, a, 0x10, owner_arg ? (s32)o : *(s32 *)(o + 0xB8), (s32)c);
    take = 0;
    if (hit != 0) {
        g = D_L01_001EAA00;
        if (*(s32 *)(g + 0x18) != *(s32 *)(o + 0xB8)) {
            if (*(s32 *)(g + 0x18) == 0 || *(s16 *)(*(u8 **)(g + 0x18) + 0xAA) != id) {
                take = 1;
            }
        }
    }
    if (take) {
        vec_copy(p + 0x10, g + 0x20);
        if (func_L01_00456250(o) == 0) {
            func_L01_003B1D10(g + 0x20, 0x14, *(s32 *)(p + 0x4C));
            func_L01_00456230(o, 1);
        }
        func_003C2880(o);
        return;
    }
    func_0038CF68(s60, p + 0x20, miss);
    vec_add_ab(p, p, s60);
    func_L01_00404A10(func_L01_003B1848, o);
}

void func_L01_003B1358(u8 *o) {
    u8 *p = *(u8 **)(o + 0x68);
    f32 a[4] __attribute__((aligned(16)));
    f32 f20;
    f32 age;

    f20 = *(f32 *)(p + 0x3C);
    age = *(f32 *)(p + 0x38) + 1.0f;
    *(f32 *)(p + 0x38) = age;
    if (84.0f < age) {
        f20 = f20 * (1.0f - (age - 84.0f) / 6.0f);
    }
    if (2.0f < age) {
        vec_copy(a, p + 0x10);
    } else {
        vec_copy(a, p);
    }
    func_L01_0046A610(p + 0x10, D_L01_001D66B0, 210000.0f, 200.0f, 0.95f, 0.0f, 0.0f,
                      3, 0x60, *(s32 *)(p + 0x50), (s32)func_00382538());
    age = *(f32 *)(p + 0x38);
    if (age < 15.0f) {
        bounce_3B1358(o, p, a, f20, 0x1C7F, 0.4f, 0);
    } else if (age < 90.0f) {
        if (0.4f < func_0038CF38(p, p + 0x10)) {
            bounce_3B1358(o, p, a, f20, 0x1625, 1.0000001f, 1);
        }
    } else {
        func_L01_003B1DB8(p + 0x10);
        func_003C2880(o);
    }
}
