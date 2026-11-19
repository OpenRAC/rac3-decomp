/* functional: high. 81 words differ: only the order of the lqc2/vadd/vsub vector-asm and a callee-saved register order; same stores, calls, arguments and result as retail. */
/* localdecomp:start func_L30_003B3A30 */
__asm__(".extern D_L30_001DECF4, 4");
__asm__(".extern D_L30_001DECF8, 4");
__asm__(".extern D_L30_001DECFC, 4");
__asm__(".extern D_L30_001DED00, 4");
__asm__(".extern D_L30_001DED04, 4");
extern s32 D_L30_001DECF4;
extern s32 D_L30_001DECF8;
extern f32 D_L30_001DECFC;
extern f32 D_L30_001DED00;
extern f32 D_L30_001DED04;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003B3A30;
extern s32 func_00382498(s32, s32);
extern void func_00382580(void *, f32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern u8 *func_L01_00470C78(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
void func_L30_003B3A30(u8 *pos, s32 count) {
    V_003B3A30 a, b, d, c;
    s32 r;
    f32 len;
    u8 *p;

    if (count <= 0) {
        return;
    }
    do {
        r = func_00382498(D_L30_001DECF4 - 5, D_L30_001DECF4);
        func_00382580(&a, D_L30_001DECFC * 0.7f, D_L30_001DECFC);
        a.y = -fabs_asm(a.y);
        func_00382580(&b, D_L30_001DED00 * 0.7f, D_L30_001DED00);
        vec_copy(&c, pos + 0x10);
        vec_add_ab(&a, &a, pos + 0x10);
        vec_add_ab(&b, &b, &c);
        vec_sub_ab(&d, &b, &a);
        len = func_0038CEA8(&d);
        func_0038CF68(&d, &d, len / (f32)r * 1.3f);
        p = func_L01_00470C78(&a, (r * 5 + 2) / 6, D_L30_001DED04 * 0.25f, D_L30_001DED04, D_L30_001DECF8, 0, 1, &d, 0, 0, 6, 0);
        if (p != 0) {
            p[2] = D_L30_0021F098[0x5C][1];
        }
        count--;
    } while (count != 0);
}
/* localdecomp:end func_L30_003B3A30 */
