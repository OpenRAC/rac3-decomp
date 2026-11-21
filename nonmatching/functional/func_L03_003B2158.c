/* functional: high. Ported from NTSC draft but constants checked against PAL asm (timer 100, yaw clamp 1.2217, k scale 1.44). vsub.xyz/vadd.xyz as plain float math keeping w of the first operand (the file's flags lack vu0 asm class). */
/* localdecomp:start func_L03_003B2158 */
static void vec_sub_ab(f32 *d, f32 *a, f32 *b) { d[0] = a[0] - b[0]; d[1] = a[1] - b[1]; d[2] = a[2] - b[2]; d[3] = a[3]; }
static void vec_add_ab(f32 *d, f32 *a, f32 *b) { d[0] = a[0] + b[0]; d[1] = a[1] + b[1]; d[2] = a[2] + b[2]; d[3] = a[3]; }
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_001A4C60[];
extern u8 D_001A4CC0[];
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(void *);
extern s32 func_0038CAD0(s32 *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L03_003B2158(u8 *s) {
    u8 *t = *(u8 **)(s + 0x68);
    f32 k1 = 0.02f;
    f32 k2 = 0.3f;
    f32 tgt[4];
    f32 pos[4];
    f32 dir[4];
    u8 *h;
    f32 ang;
    f32 yaw;
    f32 pitch;
    if (s[0x42] == 2) {
        pitch = 0.0f;
        yaw = 0.0f;
    } else {
        if (*(s32 *)(t + 0x128) != 0) {
            vec_sub_ab(dir, (f32 *)(t + 0x100), (f32 *)(s + 0x10));
        } else {
            if (func_0038CF38(s + 0x10, D_001A4C60) < 8.0f) {
                h = D_001A4C60 - 0x80;
                ang = func_0038D160(*(f32 *)(h + 0xE0) - *(f32 *)(s + 0x10), *(f32 *)(h + 0xE4) - *(f32 *)(s + 0x14));
                if (func_0038DBA0(*(f32 *)(s + 0xF8), ang) < 1.5707964f) {
                    if (func_0038CEA8(D_001A4C60 + 0x90) > 0.01f) {
                        *(s32 *)(t + 0x114) = 100;
                    } else {
                        func_0038CAD0((s32 *)(t + 0x114));
                    }
                    goto timer;
                }
            }
            if (*(s32 *)(t + 0x114) != 0) {
                *(s32 *)(t + 0x114) = 0;
                *(u128_t *)(t + 0x100) = *(u128_t *)D_001A4CC0;
            }
        timer:
            if (func_0038CAD0((s32 *)(t + 0x118))) {
                vec_add_ab((f32 *)(t + 0x100), (f32 *)(s + 0x10), (f32 *)(s + 0xC0));
            }
            if (*(s32 *)(t + 0x114) != 0) {
                k1 = 0.04f;
                *(u128_t *)tgt = *(u128_t *)D_001A4CC0;
            } else {
                *(u128_t *)tgt = *(u128_t *)(t + 0x100);
            }
            *(u128_t *)pos = *(u128_t *)(s + 0x10);
            pos[2] += 2.0f;
            vec_sub_ab(dir, tgt, pos);
        }
        yaw = func_0038DB00(func_0038D160(dir[0], dir[1]), *(f32 *)(s + 0xF8));
        pitch = -func_0038D160(func_0038CED8(dir), dir[2]);
    }
    if (1.2217305f < yaw) yaw = 1.2217305f;
    else if (yaw < -1.2217305f) yaw = -1.2217305f;
    if (0.5235988f < pitch) pitch = 0.5235988f;
    else if (pitch < -0.5235988f) pitch = -0.5235988f;
    *(f32 *)(t + 0x64) = pitch;
    *(f32 *)(t + 0xE8) = yaw * 0.2f;
    *(f32 *)(t + 0x68) = yaw * 0.8f;
    func_L01_0044E850(s, t, 0, k1 * 1.44f, k2 * 1.44f);
    func_L01_0044E850(s, t + 0x80, 1, k1 * 1.44f, k2 * 1.44f);
}
/* localdecomp:end func_L03_003B2158 */
