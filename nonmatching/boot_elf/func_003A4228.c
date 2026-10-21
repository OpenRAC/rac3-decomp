/* US draft of func_003A4228 (rac3-uya-decomp func_003A40E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A4228 */
extern f32 func_0038D2B8(f32 *);
extern f32 func_0038D540(f32, f32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A40E8;
typedef struct { u8 pad[0x50]; f32 f50; } O_3A40E8;
extern u8 D_222800[];
extern void func_0038D990(void *, void *);
extern void func_0038D408_003A4228(V4_3A40E8 *, V4_3A40E8 *, V4_3A40E8 *);
extern f32 func_0038DE98_003A4228(f32, f32);
extern f32 func_0038DEE0(f32, f32);
s32 func_003A4228(O_3A40E8 *o, u128_t *pt) {
    V4_3A40E8 m[4];
    V4_3A40E8 v[1];
    V4_3A40E8 w[1];
    V4_3A40E8 p[1];
    f32 a, d;
    func_0038D990(m, D_222800);
    *(u128_t *)v = *(u128_t *)(D_222800 - 0x380);
    {
        u128_t x;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(v[0]));
        __asm__("vsub.xyz %0, $vf0, %1" : "=j"(x) : "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(v[0]) : "j"(x));
    }
    v[0].w = 1.0f;
    func_0038D408_003A4228(&m[3], v, m);
    *(u128_t *)p = *pt;
    p[0].w = 1.0f;
    func_0038D408_003A4228(p, p, m);
    a = -func_0038D540(p[0].x, p[0].y);
    if (a < 0.0f) a += 6.2831855f;
    if (func_0038D2B8((f32 *)w) < 2.0f) {
        if (o->f50 >= 0.0f) {
            d = func_0038DEE0(a, o->f50);
            if (d > 0.2f) a = func_0038DE98_003A4228(o->f50, 0.2f);
            else if (d < -0.2f) a = func_0038DEE0(o->f50, 0.2f);
        }
        o->f50 = a;
    } else {
        o->f50 = -1.0f;
    }
    return a * 180.0f * 0.31830987f;
}
/* localdecomp:end func_003A4228 */
