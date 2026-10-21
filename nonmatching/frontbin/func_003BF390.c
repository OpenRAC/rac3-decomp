/* US draft of func_003BF390 (rac3-uya-decomp func_003B9E98, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003BF390 */
typedef int Q_3B9E98 __attribute__((mode(TI)));
typedef struct { V4_3B9C50 a; V4_3B9C50 b; } E_3B9E98;
extern s32 func_003C2B88_003BF390(void *, s32);
extern S_3B9C50 *func_003BF148(V4_3B9C50 *, V4_3B9C50 *);
extern void func_00382580(V4_3B9C50 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
void func_003BF390(void *a) {
    V4_3B9C50 v;
    V4_3B9C50 w;
    V4_3B9C50 t;
    Q_3B9E98 x, y;
    E_3B9E98 *e;
    s32 n;
    s32 i;
    e = (E_3B9E98 *)0x70000000;
    n = func_003C2B88_003BF390(a, 0);
    *(Q_3B9E98 *)&v = 0;
    v.z = 0.2f;
    *(f32 *)((u8 *)e + 0x1D4) += 1.32f;
    *(f32 *)((u8 *)e + 0x204) += -1.32f;
    func_003BF148((V4_3B9C50 *)0x700001D0, &v);
    func_003BF148((V4_3B9C50 *)0x70000200, &v);
    *(f32 *)((u8 *)e + 0x180) += -0.2f;
    *(f32 *)((u8 *)e + 0x188) += -0.15f;
    *(f32 *)((u8 *)e + 0x120) += -0.2f;
    *(f32 *)((u8 *)e + 0x128) += -0.15f;
    func_003BF148((V4_3B9C50 *)0x70000180, &v);
    func_003BF148((V4_3B9C50 *)0x70000120, &v);
    for (i = 0; i < n; i++, e++) {
        if (e->b.w == 0.0f) {
            *(Q_3B9E98 *)&w = *(Q_3B9E98 *)&e->a;
            w.w = 1.0f;
            func_00382580(&t, 0.0f, e->a.w);
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(w));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(t));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(w) : "j"(x));
        } else {
            func_0038CDF8(&w, &e->a, &e->b, func_003824E0(0.0f, 0.9f));
            w.x += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
            w.y += func_003824E0(-e->a.w * 0.4f, e->a.w * 0.4f);
            w.w = 1.0f;
        }
        func_003BF148(&w, &v);
    }
}
/* localdecomp:end func_003BF390 */
