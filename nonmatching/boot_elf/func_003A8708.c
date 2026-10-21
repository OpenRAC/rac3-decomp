/* US draft of func_003A8708 (rac3-uya-decomp func_003A85C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003A8708 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A2EE0;
typedef struct {
    V4_3A2EE0 v0; V4_3A2EE0 v10;
    f32 f20; f32 f24; f32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C;
    s32 f40; s32 f44; s32 f48; s32 f4C;
} E_3A2EE0;
__asm__(".extern D_001D6EEC, 4");
extern u8 *D_001D6EEC;
extern s32 func_0038DFB8(s32, s32, f32);
extern f32 func_0038DE98(f32, f32);
extern f32 func_003828C0(f32, f32);
extern void func_0038D200(f32 *, void *, f32);
extern s32 func_0038CEB0(void *);
void func_003A8708(s32 id, s32 arg) {
    s32 i, off;
    if (D_001D6EEC == 0) return;
    off = 0;
    for (i = 0x1FF; i >= 0; i--) {
        E_3A2EE0 *e = (E_3A2EE0 *)(off + (s32)D_001D6EEC);
        if (e->f48 == id) {
            f32 b;
            u128_t va, vb;
            b = (f32)e->f40 / (f32)e->f44;
            e->f30 = e->f2C;
            e->f38 = (s32)((f32)e->f34 * b);
            e->f30 = func_0038DFB8(arg, e->f30, b * b * b);
            e->f24 = func_0038DE98(e->f24, e->f20);
            if (e->f3C) e->f28 += func_003828C0(0.001f, 0.003f);
            __asm__("lqc2 %0, %1" : "=j"(va) : "m"(e->v0));
            __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(e->v10));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
            __asm__("sqc2 %1, %0" : "=m"(e->v0) : "j"(va));
            func_0038D200(&e->v10.x, &e->v10, 0.99f);
            if (func_0038CEB0(&e->f40)) e->f48 = 0;
        }
        off += 0x50;
    }
}
/* localdecomp:end func_003A8708 */
