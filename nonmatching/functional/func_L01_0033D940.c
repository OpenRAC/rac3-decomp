/* functional: high. Compiles at the file's @ps2as flags; near miss (instruction order only: constant stores before the call chain, quadword zero via por/sq). The three-slot scan, call order (6 angle rands, 6 small rands, 6 scaled rands), field offsets and the else branch quad copy checked. */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
extern u8 D_L01_00278BC0[];
extern u8 D_L01_001E18B0;
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_00382348(u8 *);
extern void func_L01_00451290(u8 *, void *, s32);
extern void func_0038CE20(void *, void *, f32);

void func_L01_0033D940(s32 a0, u8 *a1, s32 a2) {
    V4 v;
    V4 *src;
    u8 *e;
    u8 *o;
    s32 i;

    for (i = 0; i < 3; i++) {
        e = D_L01_00278BC0 + i * 0xA0;
        if (*(s32 *)(e + 0x8C) != 0) {
            continue;
        }
        *(s32 *)(e + 0x8C) = a0;
        *(Q16 *)(e + 0x20) = *(Q16 *)&D_L01_001E18B0;
        *(f32 *)(e + 0x40) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(e + 0x44) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(e + 0x48) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(e + 0x64) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(e + 0x68) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(e + 0x6C) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(e + 0x4C) = func_L01_00443A18(0.001f, 0.005f);
        *(f32 *)(e + 0x50) = func_L01_00443A18(0.001f, 0.005f);
        *(f32 *)(e + 0x54) = func_L01_00443A18(0.001f, 0.005f);
        *(f32 *)(e + 0x70) = func_L01_00443A18(0.001f, 0.005f);
        *(f32 *)(e + 0x74) = func_L01_00443A18(0.001f, 0.005f);
        *(f32 *)(e + 0x78) = func_L01_00443A18(0.001f, 0.005f);
        *(f32 *)(e + 0x58) = func_003824E0(3.25f, 4.75f) * 0.5f;
        *(f32 *)(e + 0x5C) = func_003824E0(3.25f, 4.75f) * 0.5f;
        *(f32 *)(e + 0x60) = func_003824E0(3.25f, 4.75f) * 0.5f;
        *(f32 *)(e + 0x7C) = func_003824E0(3.25f, 4.75f) * 0.5f;
        *(f32 *)(e + 0x80) = func_003824E0(3.25f, 4.75f) * 0.5f;
        *(f32 *)(e + 0x84) = func_003824E0(3.25f, 4.75f) * 0.5f;
        *(s32 *)(e + 0x98) = a2;
        *(Q16 *)(e) = 0;
        *(s32 *)(e + 0x94) = a2;
        *(Q16 *)(e + 0x10) = 0;
        *(s32 *)(e + 0x88) = 12;
        *(u8 **)(e + 0x90) = a1;
        *(s32 *)(e + 0x9C) = 0;
        o = func_00382348(a1);
        if (o != 0) {
            func_L01_00451290(a1, &v, 1);
            func_0038CE20(&v, &v, *(f32 *)(o + 0x10));
            src = (V4 *)(a1 + 0x10);
            ((V4 *)(e + 0x30))->x = v.x + src->x;
            ((V4 *)(e + 0x30))->y = v.y + src->y;
            ((V4 *)(e + 0x30))->z = v.z + src->z;
            ((V4 *)(e + 0x30))->w = v.w;
        } else {
            *(Q16 *)(e + 0x30) = *(Q16 *)(a1 + 0x10);
        }
        return;
    }
}
