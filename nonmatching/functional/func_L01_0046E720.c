/* functional: high. Per-frame update of a fading, homing sparkle: ramps the radius and alpha by the remaining life, integrates its velocity, and, when it has a target within 2 units, steers the velocity toward the target (gentle pull when close, speed-scaled pull otherwise); frees it when life ends. */
typedef struct {
    f32 fpos;
    f32 fbase;
    f32 f8;
    f32 vx;
    f32 vy;
    f32 vz;
    u8 *target;
} Sub_46E720;

typedef struct {
    u8 pad0[4];
    u32 w4;
    u8 b8;
    u8 pad9;
    s16 hA;
    f32 fC;
    vu0_v4 pos;
    f32 fa;
    f32 fb;
    s16 h28;
    u8 b2A;
    u8 b2B;
} Hdr_46E720;

__asm__(".extern D_L01_001D7F74, 4");
extern f32 D_L01_001D7F74;
extern vu0_v4 D_001A4EC0;
extern void func_L01_004CAB30(void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_0046E720(u8 *obj) {
    u8 *q = obj + 0x20;
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    f32 r;
    f32 a;
    f32 b;
    f32 f;
    s32 t;
    s32 h;
    s32 c;
    s32 v3;
    u32 w4;
    u8 *target;

    obj[8] = obj[8] + q[0xA];
    h = *(s16 *)(obj + 0xA);
    t = *(s16 *)(q + 8) - h;
    a = *(f32 *)(obj + 0x20);
    b = *(f32 *)(q + 4);
    c = q[0xB];
    if (t < 6) {
        r = (f32)t / 5.0f;
        f = b + ((a + b) * 0.5f - b) * r;
        *(f32 *)(obj + 0xC) = f;
        v3 = (s32)((f32)c + (f32)((c >> 1) - c) * r);
    } else {
        r = (f32)h / (f32)(*(s16 *)(q + 8) - 6);
        f = a + ((a + b) * 0.5f - a) * r;
        *(f32 *)(obj + 0xC) = f;
        v3 = (s32)((f32)(c >> 1) * r + 0.0f);
    }
    w4 = *(u32 *)(obj + 4);
    *(u32 *)(obj + 4) = ((u32)v3 << 24) | (w4 & 0xFFFFFF);

    v0.x = *(f32 *)(q + 0xC);
    v0.y = *(f32 *)(q + 0x10);
    v0.z = *(f32 *)(q + 0x14);
    v0.w = 0.0f;
    vec_add_ab(obj + 0x10, obj + 0x10, &v0);
    func_L01_004CAB30(obj + 0x10, obj + 0x10);

    target = *(u8 **)(q + 0x18);
    if (target != 0) {
        vec_sub_ab(&v10, target + 0x10, obj + 0x10);
        if (fabs_asm(v10.x) <= 2.0f && fabs_asm(v10.y) <= 2.0f) {
            func_0038CE90(&v20, &v10, &D_001A4EC0);
            func_0038CF68(&v20, &v20, D_L01_001D7F74);
            vec_add_ab(obj + 0x10, obj + 0x10, &v20);
            if (v10.x <= 0.5f && v10.y <= 0.5f) {
                func_0038CF68(&v0, &v10, 0.03f);
            } else {
                func_0038CF68(&v0, &v10, func_0038CEA8(&v0));
            }
            *(f32 *)(q + 0xC) = v0.x;
            *(f32 *)(q + 0x10) = v0.y;
            *(f32 *)(q + 0x14) = v0.z + 0.02f;
        }
    }
    if (func_0038CB00((s16 *)(obj + 0xA)) != 0) {
        func_003CD250((Obj *)obj);
    }
}
