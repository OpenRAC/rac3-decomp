/* PAL near miss (Codex wave 8): near miss: 119 words differ with the file's flags.
 * Worker's note: Best 62 diff/192 words with --divs 3 (not a MATCH; padding unproven); .07.log. Atomic VU sequence scheduling and table scan/allocation differ; .contract-check.log compiles. Fixed flags retained.
 */
#include "common.h"
/* localdecomp:start func_L01_003E2DB8 */
#include "vu0.h"
typedef struct { f32 time, width, scale; s32 color; } Key_003E2DB8;
extern vu0_v4 D_L01_001E29C0;
extern Key_003E2DB8 D_L01_002BB640[];
extern f32 D_L01_001DF5D8, D_L01_001DF5DC, D_L01_001DF5E0, D_L01_001DF5E4;
extern f32 D_L01_001DF5E8, D_L01_001DF5F0;
extern s32 D_L01_001DF5EC;
__asm__(".extern D_L01_001DF5D8, 4");
__asm__(".extern D_L01_001DF5DC, 4");
__asm__(".extern D_L01_001DF5E0, 4");
__asm__(".extern D_L01_001DF5E4, 4");
__asm__(".extern D_L01_001DF5E8, 4");
__asm__(".extern D_L01_001DF5EC, 4");
__asm__(".extern D_L01_001DF5F0, 4");
void func_L01_003E2DB8(u8 *moby) {
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(vu0_q *, vu0_q *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern f32 func_00382538(void);
    extern void func_L01_0040C3C0(void *, s32, f32, f32, s32, s32, s32, s32, s32);
    vu0_v4 p, d, side, axis, center;
    u8 *vars = *(u8 **)(moby + 0x68);
    u8 *parent;
    f32 width, scale;
    s32 color, rim;
    s32 i;
    if (vars == 0) return;
    parent = *(u8 **)(moby + 0xB8);
    *(vu0_q *)&p = *(vu0_q *)(parent + 0x10);
    p.z += *(f32 *)(vars + 0x10) * 0.5f;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(d) : "m"(D_L01_001E29C0), "m"(p) : "vf1", "vf2");
    *(vu0_q *)&axis = *(vu0_q *)(parent + 0xE0);
    func_0038CE90(&side, &d, &axis);
    func_0038CF68((vu0_q *)&d, (vu0_q *)&d, D_L01_001DF5D8);
    func_0038CF68((vu0_q *)&side, (vu0_q *)&side, (*(f32 *)(vars + 0x14) + D_L01_001DF5DC) * D_L01_001DF5E4);
    func_0038CF68((vu0_q *)&axis, (vu0_q *)&axis, (*(f32 *)(vars + 0x10) * 0.5f + D_L01_001DF5E0) * D_L01_001DF5E4);
    func_0038CF68((vu0_q *)&center, (vu0_q *)&d, D_L01_001DF5D8);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(center) : "m"(center), "m"(p) : "vf1", "vf2");
    switch (moby[0x20]) {
    case 1: {
        f32 t = *(f32 *)(vars + 8);
        width = t * D_L01_001DF5E8;
        scale = D_L01_001DF5F0 + t * (1.0f - D_L01_001DF5F0);
        color = func_0038DBD8(0x7F808080, D_L01_001DF5EC, t);
        break;
    }
    case 2: {
        f32 t = *(f32 *)(vars + 8);
        i = 1;
        while (D_L01_002BB640[i].time < t) i++;
        if (D_L01_002BB640[i].time > 1.0f) return;
        { f32 fraction = (t - D_L01_002BB640[i-1].time) / (D_L01_002BB640[i].time - D_L01_002BB640[i-1].time);
        width = D_L01_002BB640[i-1].width + (D_L01_002BB640[i].width - D_L01_002BB640[i-1].width) * fraction;
        scale = D_L01_002BB640[i-1].scale + (D_L01_002BB640[i].scale - D_L01_002BB640[i-1].scale) * fraction;
        color = func_0038DBD8(D_L01_002BB640[i-1].color, D_L01_002BB640[i].color, fraction);
        }
        break;
    }
    default:
        return;
    }
    func_0038CE20(&side, &side, scale);
    func_0038CE20(&axis, &axis, scale);
    rim = (color & 0xFF000000) | 0x808080;
    func_L01_0040C3C0(&d, 16, width, func_00382538(), rim, color, 0x80808080, 77, -1);
}
/* localdecomp:end func_L01_003E2DB8 */
