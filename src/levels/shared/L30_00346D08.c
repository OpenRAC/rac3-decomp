#include "common.h"

/* localdecomp:start func_L30_00346D08 */
extern s32 D_L30_001DCF4C;
extern s32 D_L30_001DCF44;
extern f32 D_L30_001DCF40;
extern u8 D_L30_001E11A8[];

extern int func_L01_004561B8(u8 *);
extern void func_L01_004AAC98(int, int, u8 *, int);
extern void func_L30_0034CB68(u8 *, void *, int, int, int, int, f32, f32);
extern void func_L30_0034C8A8(void *, u8 *);
extern int func_0038CAD0(void *);
extern void func_003C2880(u8 *);

void func_L30_00346D08(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    if (func_L01_004561B8(moby)) {
        *(s32 *)(vars + 164) = D_L30_001DCF4C;
        func_L01_004AAC98(29, 0, moby, 4963);
    }
    func_L30_0034CB68(moby, vars + 144, 0, -1, 0, 0, (f32)D_L30_001DCF44, D_L30_001DCF40);
    func_L30_0034C8A8(D_L30_001E11A8, moby);
    if (func_0038CAD0(vars + 164)) {
        func_003C2880(moby);
    }
}
/* localdecomp:end func_L30_00346D08 */

/* localdecomp:start func_L30_00346DA8 */
typedef int q_00346DA8 __attribute__((mode(TI)));
extern s32 D_L30_001DCF50;
extern s32 D_L30_001DCF54;
extern f32 D_L30_001DCF60;
extern f32 D_L30_001DCF64;
extern f32 D_L30_001DCF68;
extern f32 D_L30_001DCF74;
extern void func_L30_0034C958(u8 *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, f32, s32);
extern s32 func_00382498(s32, s32);

void func_L30_00346DA8(u8 *moby, u8 *a) {
    s32 src;
    u8 *vars;
    f32 k;
    s32 n;
    if (a != 0) {
        src = *(s32 *)a;
        n = *(s32 *)(a + 4);
        vars = *(u8 **)(src + 0x68);
        if (src != 0 && vars != 0 && n != 0) {
        if (*(u16 *)(a + 0xA) & 1) {
            *(q_00346DA8 *)(moby + 0x10) = *(q_00346DA8 *)(src + 0x10);
            func_L30_0034C958(moby + 0x10, D_L30_001DCF60);
            k = D_L30_001DCF74;
            *(f32 *)(a + 0x10) = k * *(f32 *)(vars + 0x90);
            *(f32 *)(a + 0x14) = k * *(f32 *)(vars + 0x98);
            *(s32 *)(moby + 4) = func_0038DBD8(D_L30_001DCF50, func_003824E0(0.0f, 1.0f), D_L30_001DCF54);
            *(u8 *)(moby + 8) = func_00382498(0, 0xFF);
            *(f32 *)(moby + 0xC) = func_003824E0(D_L30_001DCF68, D_L30_001DCF64);
        }
        {
            s16 h = *(s16 *)(moby + 0xA);
            f32 r = (f32)h / (f32)(h + 1);
            *(f32 *)(moby + 0x10) = *(f32 *)(moby + 0x10) + *(f32 *)(a + 0x10);
            *(f32 *)(moby + 0x18) = *(f32 *)(moby + 0x18) + *(f32 *)(a + 0x14);
            *(f32 *)(moby + 0xC) = *(f32 *)(moby + 0xC) * r;
        }
    }
    }
}
/* localdecomp:end func_L30_00346DA8 */
