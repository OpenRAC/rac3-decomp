/* functional: high. Signature: (o,id,idx,n,x,k,h,lo,hi,mid) with floats in f12..f17. */
typedef int Q_003CD7E0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003CD7E0;
typedef struct {
    u8 pad0[0x10];
    V4_003CD7E0 pos;
    u8 pad20[0x22];
    u8 b42;
    u8 pad43[0x7D];
    V4_003CD7E0 v[1];
} S_003CD7E0;

extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_L01_0045AA30(void *, void *);

void func_L07_003CD7E0(S_003CD7E0 *o, s32 id, s32 idx, s32 n, f32 x, f32 k, f32 h, f32 lo,
                       f32 hi, f32 mid) {
    V4_003CD7E0 a;
    V4_003CD7E0 b;
    V4_003CD7E0 d;
    f32 t;
    f32 g;

    if (o->b42 == id && lo <= x && x < hi) {
        *(Q_003CD7E0 *)&a = *(Q_003CD7E0 *)&o->pos;
        func_0038CF68(&b, &o->v[idx], (f32)n * k / (hi - lo));
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(a) : "m"(a), "m"(b) : "vf1", "vf2");
        if (x < 16.0f) {
            t = (x - lo) / (mid - lo);
        } else {
            t = 1.0f - (x - mid) / (hi - mid);
        }
        g = func_003C3D30(&a, 0, 0, 0.5f);
        a.z = func_003C3BE8(g, g + h, t);
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(d) : "m"(a), "m"(o->pos) : "vf1", "vf2");
        func_L01_0045AA30(o, &d);
    }
}
