/* functional: high. Plain float vector adds instead of VU0 vadd.xyz (w taken from the rotated vector, as retail's vadd.xyz leaves it); same calls, args and order. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec4_3F21B8;
extern Vec4_3F21B8 D_L40_0025B9A0;
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

f32 func_L40_003F21B8(Vec4_3F21B8 *p0, Vec4_3F21B8 *p1, s32 a2, u8 *a3, f32 angle) {
    Vec4_3F21B8 d0, d1, e0, e1;
    f32 len;

    d0 = *(Vec4_3F21B8 *)(a3 + 0xD0);
    d1 = d0;
    len = func_0038CF00(p0, p1);
    if (func_003D3CB0(p0, p1, a2, a3, 0) == 0) {
        func_0038CF68(&d0, &d0, angle);
        e0 = d0;
        e0.x = d0.x + p0->x; e0.y = d0.y + p0->y; e0.z = d0.z + p0->z;
        e1 = d0;
        e1.x = d0.x + p1->x; e1.y = d0.y + p1->y; e1.z = d0.z + p1->z;
        if (func_003D3CB0(&e0, &e1, a2, a3, 0) == 0) {
            func_0038CF68(&d1, &d1, -angle);
            e0 = d1;
            e0.x = d1.x + p0->x; e0.y = d1.y + p0->y; e0.z = d1.z + p0->z;
            e1 = d1;
            e1.x = d1.x + p1->x; e1.y = d1.y + p1->y; e1.z = d1.z + p1->z;
            if (func_003D3CB0(&e0, &e1, a2, a3, 0) == 0) {
                return 1.0f;
            }
        }
    }
    return func_0038CF00(p0, &D_L40_0025B9A0) / len;
}
