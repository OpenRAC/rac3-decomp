/* functional: high. Same object calls (vtable-like struct at +0x58/+0x5C/+0x60/+0x64), descriptor writes and UI calls as retail; clamp of d->w10 to min(w, D_L01_001D8FC8); byte diff from literals/regalloc */
typedef struct {
    u8 p0[0x58];
    s32 (*f58)(void);
    void (*f5C)(void);
    s32 (*f60)(void);
    void (*f64)(void);
} O_00494748;
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} S_00494748;
extern S_00494748 D_L01_002EB8E8;
extern s32 D_L01_001D8FC8 __attribute__((section(".sdata")));
extern f32 D_L01_001D8FA8 __attribute__((section(".sdata")));
extern f32 D_L01_001D8FB8 __attribute__((section(".sdata")));
extern f32 D_L01_001D8FB0[];
extern f32 D_L01_001D8FB4[];
extern f32 D_L01_001D8FBC[];
extern f32 D_L01_001D8FC0[];
extern f32 D_L01_001D8FC4[];
extern O_00494748 *func_L01_0043B548(s32, s32);
extern void func_L01_0047DE68(void);
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C68(s32, void *);
extern void func_003BA340(s32, s32, s32, s32, s32);
extern void func_003BABB0(s32, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern void func_L01_004986A8(s32, s32);

void func_L01_00494748(void) {
    O_00494748 *o;
    S_00494748 *d = &D_L01_002EB8E8;
    s32 w, h;
    f32 c1 = 0.0035f;

    o = func_L01_0043B548(0x19E1, 0x6C);
    w = o->f58();
    d->wC = w;
    d->w10 = D_L01_001D8FC8;
    if (w < D_L01_001D8FC8) d->w10 = w;
    func_L01_0047DE68();
    d->w0 = func_L01_0047DAE0();
    d->w4 = func_003BB118(0);
    func_003B9C68(func_003B9BD0(0), d);
    func_003BA340(func_003B9BD0(0), 0x8066CCFF, 0x805F5F5F, 0x666690CC, 0x80FFFFFF);
    func_003BABB0(func_003B9BD0(0), 0, D_L01_001D8FA8, D_L01_001D8FB0[0] - c1, D_L01_001D8FB4[0], 0.0425f, 0.35f);
    func_003BABD0(func_003B9BD0(0), D_L01_001D8FB8, D_L01_001D8FBC[0], D_L01_001D8FC0[0] - c1, D_L01_001D8FC4[0] - 0.006f);
    o->f5C();
    h = func_003B9BD0(0);
    func_L01_004986A8(h, o->f60());
    o->f64();
}
