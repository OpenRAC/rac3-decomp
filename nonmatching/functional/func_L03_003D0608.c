/* functional: high. Rewritten from the asm: a do-while of `count` iterations (skipped when count <= 0). The VU0 vadd.xyz (w kept) is three scalar adds and the quad copies are 128-bit copies, since the file has no VU0 flag; not byte-matched. */
typedef int u128_003D0608 __attribute__((mode(TI)));
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void *func_L01_00470668(void *, void *, s32, f32);
void func_L03_003D0608(u8 *self, s32 idx, s32 count, f32 velScale, f32 zOfs, f32 spread, f32 jitter, f32 f16, f32 sizeBase, f32 fadeScale) {
    f32 vel[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 off[4] __attribute__((aligned(16)));
    if (count > 0) {
        do {
            *(u128_003D0608 *)pos = *(u128_003D0608 *)(self + 0x10);
            count--;
            func_003C4C18(pos, spread);
            *(u128_003D0608 *)off = *(u128_003D0608 *)(self + 0xC0 + (s16)idx * 16);
            func_0038CF68(off, off, *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * velScale);
            pos[2] += *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24) * zOfs;
            pos[0] += off[0];
            pos[1] += off[1];
            pos[2] += off[2];
            *(u128_003D0608 *)vel = *(u128_003D0608 *)(self + 0xC0 + (s16)idx * 16);
            func_0038CE20(vel, vel, func_003824E0(sizeBase * 0.5f, sizeBase) * 0.020000001f);
            vel[0] += func_003824E0(-jitter, jitter);
            vel[1] += func_003824E0(-jitter, jitter);
            func_L01_00470668(pos, vel, 50, fadeScale * 0.00040000002f);
        } while (count != 0);
    }
}
