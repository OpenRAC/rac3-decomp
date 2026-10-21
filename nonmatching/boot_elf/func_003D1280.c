/* US draft of func_003D1280 (rac3-uya-decomp func_003D1118, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` `@ps2as` (a single-function override). */


/* localdecomp:start func_003D1280 */
typedef int u128_3CB958 __attribute__((mode(TI)));
extern u8 D_001DA6B0[8];
extern f32 D_001DA6C0;
extern f32 D_001DA6C4;
extern volatile f32 D_001DA6C8;
extern u8 D_001DA6D0[];
extern void func_0038D1C8(void *, void *);
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D270(void *, void *, void *);
extern void func_0038D348(s32, s32, f32);
void func_003D1280(void *a, f32 t) {
    f32 v[4];
    f32 x, y, z;
    *(u128_3CB958 *)D_001DA6B0 = *(u128_3CB958 *)a;
    func_0038D1C8(v, a);
    func_0038D200((f32 *)D_001DA6D0, D_001DA6B0, t);
    x = v[0]; y = v[1]; z = v[2];
    if (x < y) {
        if (x < z) {
            D_001DA6C0 = x;
            D_001DA6C4 = z;
            D_001DA6C8 = y;
        } else {
            goto A;
        }
    } else if (y < z) {
        D_001DA6C0 = z;
        D_001DA6C4 = y;
        D_001DA6C8 = x;
    } else {
A:
        D_001DA6C0 = y;
        D_001DA6C4 = x;
        D_001DA6C8 = z;
    }
    func_0038D270(&D_001DA6C0, &D_001DA6C0, D_001DA6B0);
    func_0038D348((s32)&D_001DA6C0, (s32)&D_001DA6C0, 1.0f);
}
/* localdecomp:end func_003D1280 */
