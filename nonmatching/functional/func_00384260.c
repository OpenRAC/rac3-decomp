/* functional: medium. No draft; written from asm. Checked branch structure (obj at e+0x50 with h86==6 -> clear counters; i8==0 -> iC=0; iC=max(iC,i8); func_0038CAD0(&i8); ratio=i8/iC; modes 0/1 use vector e+0x3A0 / e+0x380, mode 2 the 50.333332 / 6.0 / 8.0*deg(D_001D57B4 = gp-0x70FC, gp=0x1DC8B0) curve). Callee signatures (func_0038CF68, func_003C4CE8, func_0038D810, func_0038D5F0 argument kinds) are inferred from registers: a0=out vector, a1 = e+0x380/0x3A0 vector, f12 = scalar; the vadd.xyz is written as 3 float adds (w kept). 136 words differ (scheduling and vadd.xyz). */
typedef struct { f32 pos[4]; u8 pad10[0x40]; u8 *obj50; u8 pad54[0x380 - 0x54]; f32 v380[4]; f32 v390[4]; f32 v3A0[4]; u8 pad3B0[0x460 - 0x3B0]; } E_00384260;
extern E_00384260 D_00222480_00384260[];
extern f32 D_001D57B4;
extern void func_0038CAD0(s32 *);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(f32 *, f32 *, f32);
extern void func_003C4CE8(f32 *, f32 *, f32);
extern void func_0038D810(f32 *, f32 *);
extern void func_0038D5F0(f32 *, f32 *, f32 *);
typedef struct { f32 f0; f32 f4; s32 i8; s32 iC; } S_00384260;
void func_00384260(s32 idx, S_00384260 *p, s32 mode) {
    E_00384260 *e = &D_00222480_00384260[idx];
    f32 a, b, r, k;
    f32 sp[4];
    f32 m[4];
    f32 ratio;
    f32 cube;
    f32 f;
    if (e->obj50 != 0 && *(s16 *)(e->obj50 + 0x86) == 6) {
        p->iC = 0;
        p->i8 = 0;
        return;
    }
    if (p->i8 == 0) {
        p->iC = 0;
        return;
    }
    if (p->iC < p->i8) p->iC = p->i8;
    func_0038CAD0(&p->i8);
    a = (f32)p->i8;
    b = (f32)p->iC;
    ratio = a / b;
    if (mode == 0 || mode == 1) {
        f32 *vec = (mode == 0) ? e->v3A0 : e->v380;
        r = func_0038D098(func_0038DB48(a + a));
        f = p->f0 * r * ratio * ratio;
        p->f4 = f;
        func_0038CF68(sp, vec, f);
        e->pos[0] += sp[0];
        e->pos[1] += sp[1];
        e->pos[2] += sp[2];
    } else if (mode == 2) {
        f32 t = (f32)(p->iC - p->i8) / 50.333332f;
        f32 s = D_001D57B4 * 0.017453292f;
        cube = ratio * ratio * ratio;
        ratio = t * 6.0f;
        if (1.0f < ratio) ratio = 1.0f;
        k = func_0038D0B0(func_0038DB48(t * s - s * 8.0f));
        f = p->f0 * k * cube * ratio;
        p->f4 = f;
        func_003C4CE8(sp, e->v380, f);
        func_0038D810(sp, m);
        func_0038D5F0(e->v380, m, e->v380);
    }
}
