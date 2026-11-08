/* func_L19_00335748: NEAR 4 (prep by Sonnet worker w7, p2w4). Retail epilogue loads $s1 before the sqc2 and orders ld s1/ra/s0;
   non-volatile asm with =m output gives ra/s0/s1. Needs the VU0 split into separate statements (j-form), but file flags lack -mvu0-use-vf0-vf2.
   rac2 twin func_L03_004197C8, 76 bytes, 3 places. */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_54DD90;
extern f32 D_L39_001DB098;
extern f32 D_L39_001DB090;
extern f32 D_L39_001DB094;
__asm__(".extern D_L39_001DB098, 4");
__asm__(".extern D_L39_001DB090, 4");
__asm__(".extern D_L39_001DB094, 4");
extern f32 func_0038D160(f32, f32);
extern s32 func_L39_005BE900(V4_54DD90 *, V4_54DD90 *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(V4_54DD90 *, f32, f32, f32);
extern void func_L01_0046A610(V4_54DD90 *, V4_54DD90 *, s32, s32, u32, s32, f32, f32, f32, f32, f32);

void func_L39_0054DD90(f32 *a0, u8 *a1) {
    V4_54DD90 v, q, dir, out, w;
    f32 ang;
    s32 n;
    s32 i;
    s32 id;
    f32 f20;
    f32 f21;
    f32 r, t0, sz;
    n = 15;
    __asm__(
        "lqc2    $vf1, 0x23A0(%1)\n"
        "lqc2    $vf2, 0x0(%2)\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2    $vf1, %0\n"
        : "=m"(v) : "r"(a1), "r"(a0));
    ang = func_0038D160(v.x, v.y);
    *(u128_t *)&q = *(u128_t *)a0;
    q.w = 0.5f;
    if (func_L39_005BE900(&q, &w, D_L39_001DB098) > 0) {
        if (w.x < D_L39_001DB090 * D_L39_001DB090) {
        } else if (w.x < D_L39_001DB094 * D_L39_001DB094) {
            n = 10;
        } else {
            n = 5;
        }
    } else {
        n = 0;
    }
    i = n;
    if (n != 0) {
        do {
            i--;
            f21 = func_L39_005B4410(0.5f, 1.0f);
            id = (s32)func_L39_005B4468(1.0f, 2.0f);
            func_L39_005B4410(0.05f, 0.2f);
            f20 = func_L39_005B4410(0.0f, 1.3962634f);
            r = func_0038DAB8(ang, func_L39_005B4468(0.0f, 1.3962634f));
            func_00382760(&dir, f21 * 0.020000001f, r, f20);
            t0 = func_L39_005B4468(0.0f, 0.1f);
            out.x = a0[0] + t0;
            t0 = func_L39_005B4468(0.0f, 0.1f);
            out.y = a0[1] + t0;
            t0 = func_L39_005B4468(0.0f, 0.1f);
            out.z = a0[2] + t0;
            sz = func_L39_005B4410(0.05f, 0.2f) * 210000.0f;
            func_L01_0046A610(&out, &dir, 25, 127, 0x7F7F7F, id, sz, 500.0f, 1.0f, 0.0f, 0.0f);
        } while (i != 0);
    }
}
