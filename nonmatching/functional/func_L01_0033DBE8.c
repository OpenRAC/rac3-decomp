/* functional: high. 186 diff words at the file's flags (retail unrolls two copies of the integrate step with 100.0/50.0 in separate registers; and different stack frame); every offset, call order, neg placement and the countdown tail (func_0038CAD0 on +0x94 then +0x88) read against retail. */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
extern u8 D_L01_00278BC0[];
extern u8 D_L01_001E18B0;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_00382348(u8 *);
extern void func_L01_00451290(u8 *, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_0038CAD0(void *);

void func_L01_0033DBE8(s32 a0) {
    V4 v;
    u8 *e;
    u8 *o;
    u8 *t;
    V4 *src;
    f32 k;
    s32 i;

    for (i = 0; i < 3; i++) {
        e = D_L01_00278BC0 + i * 0xA0;
        if (*(s32 *)(e + 0x8C) != a0) {
            continue;
        }
        *(Q16 *)(e + 0x20) = *(Q16 *)&D_L01_001E18B0;
        if (*(s32 *)(e + 0x94) != 0) {
            k = 100.0f;
        } else {
            k = 50.0f;
        }
        *(f32 *)(e + 0x40) = func_0038DAB8(*(f32 *)(e + 0x40), *(f32 *)(e + 0x4C) * k);
        *(f32 *)(e + 0x44) = func_0038DAB8(*(f32 *)(e + 0x44), *(f32 *)(e + 0x50) * k);
        *(f32 *)(e + 0x48) = func_0038DAB8(*(f32 *)(e + 0x48), *(f32 *)(e + 0x54) * k);
        *(f32 *)(e + 0x64) = func_0038DAB8(*(f32 *)(e + 0x64), *(f32 *)(e + 0x70) * k);
        *(f32 *)(e + 0x68) = func_0038DAB8(*(f32 *)(e + 0x68), *(f32 *)(e + 0x74) * k);
        *(f32 *)(e + 0x6C) = func_0038DAB8(*(f32 *)(e + 0x6C), *(f32 *)(e + 0x78) * k);
        *(f32 *)(e + 0x00) = func_0038D098(*(f32 *)(e + 0x40)) * *(f32 *)(e + 0x58);
        *(f32 *)(e + 0x04) = func_0038D0B0(*(f32 *)(e + 0x44)) * *(f32 *)(e + 0x5C);
        *(f32 *)(e + 0x08) = -func_0038D0B0(*(f32 *)(e + 0x48)) * *(f32 *)(e + 0x60);
        *(f32 *)(e + 0x10) = func_0038D098(*(f32 *)(e + 0x64)) * *(f32 *)(e + 0x7C);
        *(f32 *)(e + 0x14) = func_0038D0B0(*(f32 *)(e + 0x68)) * *(f32 *)(e + 0x80);
        *(f32 *)(e + 0x18) = -func_0038D0B0(*(f32 *)(e + 0x6C)) * *(f32 *)(e + 0x84);
        if (*(u8 **)(e + 0x90) != 0) {
            o = func_00382348(*(u8 **)(e + 0x90));
            if (o != 0) {
                func_L01_00451290(*(u8 **)(e + 0x90), &v, 1);
                func_0038CE20(&v, &v, *(f32 *)(o + 0x10));
                t = *(u8 **)(e + 0x90);
                src = (V4 *)(t + 0x10);
                ((V4 *)(e + 0x30))->x = v.x + src->x;
                ((V4 *)(e + 0x30))->y = v.y + src->y;
                ((V4 *)(e + 0x30))->z = v.z + src->z;
                ((V4 *)(e + 0x30))->w = v.w;
            } else {
                t = *(u8 **)(e + 0x90);
                *(Q16 *)(e + 0x30) = *(Q16 *)(t + 0x10);
            }
            func_0038CDF8(e + 0x30, e + 0x20, e + 0x30,
                          1.0f - (f32)*(s32 *)(e + 0x94) / (f32)*(s32 *)(e + 0x98));
        }
        if (func_0038CAD0(e + 0x94) != 0) {
            if (*(s32 *)(e + 0x9C) == 0) {
                *(s32 *)(e + 0x9C) = 1;
            }
            if (func_0038CAD0(e + 0x88) != 0) {
                *(s32 *)(e + 0x8C) = 0;
            }
        }
    }
}
