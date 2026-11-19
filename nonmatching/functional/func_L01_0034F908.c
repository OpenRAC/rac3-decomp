/* functional: high. Near-miss draft (compiles under file flags); 7 diff words, scheduling; VU0 vsub via inline asm */
/* localdecomp:start func_L01_0034F908 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_0034F908;
extern Vec_0034F908 D_L01_001E29C0[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC0_0034F908[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001E1A08, 4");
extern f32 D_L01_001E1A08;
f32 func_L01_0034F908(u8 *m)
{
    extern f32 func_0038CE68(void *, void *);
    extern void func_L01_0044FBC8(void *, s32 *, s32 *);
    extern s32 func_L01_00407808(s32, u16, u16, s32, s32, s32, f32 *);
    Vec_0034F908 v;
    s32 x, y;
    s32 t;
    u8 *p = *(u8 **)(m + 0x68);
    f32 d;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(v) : "m"(*(Vec_0034F908 *)p), "m"(D_L01_001E29C0[0]) : "vf1", "vf2");
    d = func_0038CE68(&v, &D_L01_001E29C0[2]);
    func_L01_0044FBC8(p, &x, &y);
    t = x;
    if (t < 0 || t >= D_001D4BC0 - 16) goto invalid;
    t = y;
    if (t < 0 || t >= D_001D4BC0_0034F908[1] - 8 || !(d > 0.0f)) goto invalid;
    if (func_L01_00407808(-1, x, y, 16, 8, 0, &D_L01_001E1A08) == -1) {
invalid:
        D_L01_001E1A08 = -1.0f;
    }
    return D_L01_001E1A08;
}
/* localdecomp:end func_L01_0034F908 */
