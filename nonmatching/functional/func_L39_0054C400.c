/* functional: high. Spawns the trail puffs of the homing projectile: n = (reload time * 0.02 / 0.1) puffs (x0.6 for LOD 2, x0.3 for LOD 3), spaced along the segment from the previous position q to the object's position; each puff is placed with a random jitter and queued through func_L01_0046FB40. Written from the PAL assembly; the NTSC-U draft was only a map. */
typedef int q128_0054C400 __attribute__((mode(TI)));
extern u8 D_L39_0049C890_0054C400[];
__asm__(".extern D_L39_00242930, 16");
extern u8 D_L39_00242930[];

extern s32 func_L39_00648AE0(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);

void func_L39_0054C400(u8 *o, f32 *pos, s32 mode) {
    u8 *ex = *(u8 **)(o + 0x68);
    f32 q0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    u8 *cfg;
    f32 dur, f20, w;
    s32 n;
    s32 c;

    *(q128_0054C400 *)q0 = *(q128_0054C400 *)pos;
    if (func_L39_00648AE0(*(void **)(ex + 0x58), 4) != 0) {
        cfg = D_L39_0049C890_0054C400 + ((s8)D_L39_0049C890_0054C400[0x221] << 7);
    } else {
        cfg = D_L39_0049C890_0054C400 + 0x200;
    }
    dur = *(f32 *)(cfg + 0x24) * 0.0200000014f;
    n = (s32)(dur / 0.100000001f);
    if (mode == 2) {
        n = (s32)((f32)n * 0.600000024f);
    } else if (mode == 3) {
        n = (s32)((f32)n * 0.300000012f);
    }
    f20 = (f32)n;
    *(q128_0054C400 *)v10 = *(q128_0054C400 *)q0;
    w = *(f32 *)(o + 0x1C);
    v20[0] = *(f32 *)(o + 0x10) - q0[0];
    v20[1] = *(f32 *)(o + 0x14) - q0[1];
    v20[2] = *(f32 *)(o + 0x18) - q0[2];
    v20[3] = w;
    func_0038CF68(v20, v20, dur / f20);
    func_0038CE20((void *)v40, (void *)v20, 1.0f / f20);
    if (n > 0) {
        do {
            f20 = func_L39_005B4410(0.100000001f, 0.300000012f) * *(f32 *)(ex + 0x5C);
            n--;
            c = func_L39_005B4398(0xFF);
            func_L01_00443B88(v30, 0.0f, 0.100000001f);
            v30[0] += v10[0];
            v30[1] += v10[1];
            v30[2] += v10[2];
            func_L01_0046FB40(v30, D_L39_00242930, 0xC, 0x80FFFFFF, c, 0x20, 0, 0, f20 * 210000.0f, (f20 * 0.200000003f) * 210000.0f, 0.0f);
            v10[0] += v40[0];
            v10[1] += v40[1];
            v10[2] += v40[2];
        } while (n != 0);
    }
}
