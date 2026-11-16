/* PAL near miss (Codex wave 6): near miss: 13 words differ with the file's flags.
 * Worker's note: 13 diff; initial save/load scheduling through first vector subtraction, remaining body identical; 10 compiles; best log build/codex/w251/func_L20_003CFE80.wrap08.log
 */
#include "common.h"
/* localdecomp:start func_L20_003CFE80 */
#include "vu0.h"
extern vu0_v4 D_001A4CB0;
extern s32 D_L20_001DFD40;
__asm__(".extern D_L20_001DFD40, 16");
extern s32 D_L20_001DEBA8;
__asm__(".extern D_L20_001DEBA8, 4");
extern u8 *D_L20_001E9BD8[];
extern vu0_v4 D_L20_001E9BE0;
void func_L20_003CFE80(u8 *self) {
    extern void func_L01_0044C280(void *, void *, void *, s32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_004CB320(void);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L01_004CB358(void);
    extern void func_L01_0040A8C0(u128_t *, u128_t *, s32, s32, u32, u32, u32, u32, f32, f32, f32);
    vu0_v4 origin;
    vu0_v4 hit;
    vu0_v4 dir;
    vu0_v4 toward;
    vu0_v4 target;
    u8 *vars;
    f32 scale;
    s32 collided;
    u8 *other;
    s32 frame;
    vars = *(u8 **)(self + 0x68);
    *(u128_t *)&origin = *(u128_t *)(self + 0x10);
    vec_copy(&target, &D_001A4CB0);
    frame = D_L20_001DFD40;
    vec_sub_ba(&dir, vars + 0xD50, &origin);
    __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvsub.xyz vf1, vf2, vf1\n\tsqc2 vf1, %0"
        : "=m"(toward) : "m"(origin), "m"(target) : "vf1", "vf2");
    if (frame != D_L20_001DEBA8) {
        func_L01_0044C280(&dir, &dir, &toward, 0, 0.06f);
    }
    scale = *(f32 *)(vars + 0xD48) * 60.0f;
    D_L20_001DEBA8 = D_L20_001DFD40;
    func_0038CF68(&dir, &dir, scale);
    vec_add_ab(&dir, &dir, &origin);
    func_L01_004CB320();
    collided = func_003D3CB0(&origin, &dir, 2, self, 0);
    if (collided) {
        other = D_L20_001E9BD8[0];
        if (other && *(s16 *)(other + 0xAA) == 0x186D && other[0x20] != 2 && other[0x20] != 5) {
            other[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (collided) {
        *(u128_t *)&hit = *(u128_t *)&D_L20_001E9BE0;
        *(u128_t *)(vars + 0xD50) = *(u128_t *)&hit;
    } else {
        *(u128_t *)&hit = *(u128_t *)&dir;
        *(u128_t *)(vars + 0xD50) = *(u128_t *)&hit;
    }
    func_L01_0040A8C0((u128_t *)&origin, (u128_t *)&hit, 14, 0, 0x4F802060, 0x4F802060, 0x4F802060, 0x4F802060,
                      *(f32 *)(vars + 0xD4C), 1.0f, *(f32 *)(vars + 0xD40));
    func_L01_0040A8C0((u128_t *)&origin, (u128_t *)&hit, 14, 3, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF,
                      *(f32 *)(vars + 0xD4C) * 0.5f, 1.0f, -*(f32 *)(vars + 0xD40));
    *(u128_t *)(vars + 0xD60) = *(u128_t *)&hit;
}
/* localdecomp:end func_L20_003CFE80 */
