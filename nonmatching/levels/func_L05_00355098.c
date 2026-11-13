/* near miss (level 5, Daxx), opus pass 2026-11-13: 19 differences, with @ps2as on its file (not set yet: retail builds the float arguments with lui/ori/mtc1). Every instruction is right; left is the order of the argument moves before the two calls: retail moves $a0 (the moby) first, ours after $a1 (first call) or after the floats (second call). Parameter orders of both callees, a u8/s16 second parameter and a later v load gave nothing. qzero is the vector clear (retail sq $zero); 0.120000005f is retail's 0x3DF5C290. */
#include "common.h"

/* localdecomp:start func_L05_00355098 */
#include "vu0.h"
extern s32 D_L05_001DF6C0;
extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DFB9C, 4");
extern u8 D_L05_001D9AE0[];
extern u8 D_001A4C60[];
extern s32 func_L01_00456250(void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_0044AF78(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00456230(u8 *, s32);
extern void func_003C2880(void *);
extern f32 func_0038CF38(void *, void *);

void func_L05_00355098(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    vu0_v4 p;

    if (o[0x20] == 0) {
        *(s32 *)(v + 0x6C) |= 1;
        o[0x20] = 1;
    }
    if (func_L01_00456250(o) != 0) {
        qzero(&p);
        p.z = 0.120000005f;
        func_L01_00451FE0(o, 0x3F, &p, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_0044AF78(o, D_L05_001D9AE0, 0, 10, 3, 16, -1, 1, 0.5f, 1.0f, 5.0f, 2.5f, 9.0f, 1.5f, 15.0f, 1, -1, 0, 0x1010001);
        func_003A52A0(0, 0, o);
        if (*(s32 *)(v + 0x70) != -1) {
            func_L01_00456230(D_L05_001DFB9C + (*(s32 *)(v + 0x70) << 8), 1);
        }
        func_003C2880(o);
    } else if (*(f32 *)(v + 0x74) != 0.0f && o[0xBC] == 0 && (D_L05_001DF6C0 & 7) == (((s32)o >> 8) & 7)) {
        if (func_0038CF38(D_001A4C60, o + 0x10) < *(f32 *)(v + 0x74)) {
            o[0xBC] = v[0x78];
        }
    }
}
/* localdecomp:end func_L05_00355098 */
