/* functional: high. The vec + pos add is VU0's vadd.xyz (FPU rounding differs); vec.w is never written in retail either (an uninitialised stack word that the spawner copies as a quad), so the frame is padded to retail's layout to read the same word. Ported from the NTSC-U near-miss draft and re-read against PAL's assembly: the two versions differ (PAL's x/y scale is 0.02, its z uses the same scale, spark ids come from func_L01_003F79D8 with the 13-argument list below); everything else (mask scan, -1.0 sentinels, 0.7/1.3 speed spread, life > 180 re-roll, callback tail) matches. */
typedef void (*Callback_00451FE0)(s32, void *, s32, s32, s32, f32, f32);
extern s32 D_L01_001D673C;
extern void func_L01_00439880(void *, s32 *, s32 *);
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038D000(void *, void *, void *);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern Callback_00451FE0 *func_L01_0043B548(s32, s32);
extern void func_L01_003D4C08(s32, void *, s32, s32, s32, f32);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00451FE0;

/* d.xyz = a.xyz + b.xyz, d.w = a.w (lqc2, lqc2, vadd.xyz, sqc2): VU0 rounds differently from the FPU,
 * so the add stays a VU0 op; one asm block with fixed vf1/vf2 (the file's flags have no "j" class) */
static void vadd_00451FE0(void *d, void *a, void *b) {
    __asm__ __volatile__("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                         : : "r"(d), "r"(a), "r"(b) : "memory");
}

void func_L01_00451FE0(u8 *m, s32 mask, f32 *pos, u8 type, s32 life, s32 v, s32 enable, s32 arg, s32 tail, s32 tailarg,
                       f32 x, f32 y, f32 z, f32 w, f32 speed, f32 angle, f32 f, f32 g) {
    s32 ids[15];
    V4_00451FE0 vec;
    s32 unused1, unused2;
    s32 count;
    s32 i;
    f32 a, scale, lo, hi, s;
    Callback_00451FE0 *cb;
    u8 frame_pad[0x50];   /* never used: makes the frame retail's 0x190 (its sq-save area) with vec at sp+0x60, so vec.w, which retail never writes and func_L01_003F7CE0 copies into the spark, is the same stack word */

    count = 0;
    for (i = 0; i < 15; i++) {
        if (((mask >> i) ^ 1) & 1) {
            continue;
        }
        func_L01_00439880(m, &unused1, &unused2);
        a = func_00382538();
        scale = func_003824E0(x, y) * 0.0200000014f;
        vec.x = func_0038D098(a) * scale;
        vec.y = func_0038D0B0(a) * scale;
        vec.z = 0.0f;
        vec.z = func_003824E0(z, w) * 0.0200000014f;
        if (D_L01_001D673C != 0) {
            func_0038D000(&vec, &vec, m + 0xC0);
        }
        vadd_00451FE0(&vec, &vec, pos);
        if (angle == -1.0f) {
            angle = func_003824E0(90.0f, 270.0f);
        }
        if (speed == -1.0f) {
            lo = 10.0f;
            hi = 20.0f;
        } else {
            lo = speed * 0.699999988f;
            hi = speed * 1.29999995f;
        }
        s = func_003824E0(lo, hi);
        speed = s;
        if (life >= 0xB5) {
            life = func_00382498(0xB4, life);
        }
        ids[i] = func_L01_003F79D8(m, 2, *(s16 *)(m + 0xAA), i, m + 0x10, m + 0xF0, &vec, type, life, v, 0x80, angle, s);
        if (ids[i] != 0) {
            count++;
        }
    }
    if (enable != 0) {
        cb = func_L01_0043B548(0x1CD7, 4);
        if (cb != 0) {
            (*cb)(count, ids, arg, 7, 5, f, -100000.0f);
        }
    }
    if (tail != 0) {
        func_L01_003D4C08(count, ids, tail, tailarg, 30, g);
    }
}
