/* functional: high. Zeroes object fields, runs func_0038D308 on a local vec, copies the input vec, clamps pitch at +0x60 to [+0xB8,+0xB4], then builds direction at +0xF0; unaligned 16-byte copies are struct copies. */
typedef struct {
    s32 w[4];
} V4_00412FE0;

extern void func_0038D308(void *out, void *in);
extern void func_L01_00413B68(void *a, void *b, void *c);
extern void func_00382760(void *out, f32 r, f32 a, f32 b);

void func_L01_00412FE0(u8 *a0, V4_00412FE0 *a1, f32 f12, f32 f13) {
    f32 tmp[4];
    V4_00412FE0 v1, v2;
    f32 f;

    tmp[0] = 0.0f;
    tmp[1] = 0.0f;
    tmp[2] = 0.0f;
    tmp[3] = 0.0f;
    *(s32 *)(a0 + 0x44) = 0;
    ((s32 *)(a0 + 0xA0))[0] = 0;
    ((s32 *)(a0 + 0xA0))[1] = 0;
    ((s32 *)(a0 + 0xA0))[2] = 0;
    ((s32 *)(a0 + 0xA0))[3] = 0;
    *(s32 *)(a0 + 0x64) = 0;
    *(s32 *)(a0 + 0x80) = 0;
    *(s32 *)(a0 + 0x8C) = 0;
    *(s32 *)(a0 + 0xB0) = 0;
    tmp[1] = f13;
    tmp[2] = f12;
    *(f32 *)(a0 + 0x40) = f12;
    *(f32 *)(a0 + 0x60) = f13;
    func_0038D308(a0, tmp);
    *(V4_00412FE0 *)(a0 + 0x30) = *a1;
    *(V4_00412FE0 *)(a0 + 0x140) = *a1;
    v2 = *a1;
    v1 = *a1;
    func_L01_00413B68(a0, &v1, &v2);
    f = *(f32 *)(a0 + 0x60);
    if (*(f32 *)(a0 + 0xB4) < f) {
        *(f32 *)(a0 + 0x60) = *(f32 *)(a0 + 0xB4);
    } else if (f < *(f32 *)(a0 + 0xB8)) {
        *(f32 *)(a0 + 0x60) = *(f32 *)(a0 + 0xB8);
    }
    func_00382760(a0 + 0xF0, 1.0f, *(f32 *)(a0 + 0x40), -*(f32 *)(a0 + 0x60));
}
