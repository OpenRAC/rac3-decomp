/* functional: high. Same loop, calls (func_L01_00316DA0/00316E38/003824E0 noise/00317440) and order as the PAL near-miss draft (4 words differ only in VU0 load/store order); its lqc2/vadd.xyz/sqc2 asm is written here as plain float adds (xyz only, w kept). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_317070;
extern void func_L01_00316DA0(V_317070 *, V_317070 *, V_317070 *, f32);
extern void func_L01_00316E38(V_317070 *, V_317070 *, V_317070 *, V_317070 *, V_317070 *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(f32 *, f32 *, f32);
extern void func_L01_00317440(void *, s32, V_317070 *, s32);
void func_L01_00317070(void *obj, V_317070 *a, V_317070 *b, u8 *shape) {
    V_317070 points[11];
    V_317070 c, d, noise;
    s32 i;
    f32 t;
    for (i = 0; i < 10; i++) {
        t = (f32)i / 9.0f;
        func_L01_00316DA0(&points[i], a, b, t);
        c = *(V_317070 *)(shape + 0x50);
        d = *(V_317070 *)(shape + 0x60);
        c.x = c.x + a->x;
        c.y = c.y + a->y;
        c.z = c.z + a->z;
        d.x = d.x + b->x;
        d.y = d.y + b->y;
        d.z = d.z + b->z;
        func_L01_00316E38(&points[i], a, b, &c, &d, t);
        noise.w = 0.0f;
        noise.x = func_003824E0(-1.0f, 1.0f);
        noise.y = func_003824E0(-1.0f, 1.0f);
        noise.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68(&noise.x, &noise.x, 0.04f);
        points[i].x = points[i].x + noise.x;
        points[i].y = points[i].y + noise.y;
        points[i].z = points[i].z + noise.z;
    }
    func_L01_00317440(obj, 128, points, 11);
}
