/* PAL near miss (Codex wave 10): near miss: 3 words differ with the file's flags.
 * Worker's note: 3 diff (second 005110E8 argument scheduling), log build/codex/w509/func_L01_004EF3A8.v4.log; exact existing CE20 typedef/prototype supplied by source_contract include; expose owner typedefs before first block for integration; no incompatible callee aliases
 */
#include "common.h"
/* localdecomp:start func_L01_004EF3A8 */
#include "vu0.h"
#include "build/codex/wave10/contracts/5d70187d1e948cac.h"
extern u8 D_001A4CD0[];
extern s32 D_L01_001EAA1C[];
typedef struct {
    u8 p0[0xF0]; vu0_v4 velocity;
    u8 p100[0x290 - 0x100]; s32 ground;
    u8 p294[0x25C0 - 0x294]; void *moby;
} Hero_004EF3A8;
extern Hero_004EF3A8 D_001A4BE0_004EF3A8;
void func_L01_004EF3A8(s32 force) {
    extern f32 func_L01_00511408(void *);
    extern void func_L01_005110E8(void *, s32, f32, f32, f32);
    extern f32 func_0038CED8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00511508(void *, void *, f32);
    extern void func_0038CE20(Vec4ED3B8 *, Vec4ED3B8 *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern s32 func_003D5630(void);
    extern f32 func_L01_00511848(void *);
    extern f32 func_0038CE68(void *, void *);
    vu0_v4 origin, end, low, low_end;
    Hero_004EF3A8 *h;
    u8 *early;
    f32 height, distance;
    f32 slope;
    f32 zero = 0.0f;
    s32 kind;
    if (func_L01_00511408(D_001A4CD0) < 0.002f) return;
    early = D_001A4CD0 - 0xF0;
    height = 0.395f;
    distance = 0.5f;
    if ((u32)(*(s32 *)(early + 0x25CC) - 17) < 2) {
        height = 0.0f;
        distance = 0.7f;
    } else if (early[0x25E4] == 1) {
        height = 0.35f;
        distance = 0.27f;
    }
    func_L01_005110E8(&origin, 1, 0.0f, 0.0f, height);
    func_L01_005110E8(&low, 1, zero, zero, height * 0.3f);
    if (force || func_0038CED8(D_001A4CD0) < 0.01f) {
        func_0038CF68(&end, &D_001A4BE0_004EF3A8, distance);
        func_0038CF68(&low_end, &D_001A4BE0_004EF3A8, distance * 1.4f);
    } else {
        func_L01_00511508(&end, D_001A4CD0, 0.0f);
        func_0038CF68(&end, &end, distance);
        func_0038CE20((Vec4ED3B8 *)&low_end, (Vec4ED3B8 *)&end, 1.4f);
    }
    vec_add_ba(&end, &end, &origin);
    vec_add_ab(&low_end, &low_end, &low);
    kind = -1;
    if (func_003D3CB0(&low, &low_end, 2, D_001A4BE0_004EF3A8.moby, 0) && D_L01_001EAA1C[0] > 0)
        kind = func_003D5630();
    slope = 0.0f;
    if (func_003D3CB0(&origin, &end, 2, D_001A4BE0_004EF3A8.moby, 0) && D_L01_001EAA00[0].count > 0)
        slope = func_L01_00511848(&D_L01_001EAA00[0].normal);
    if (slope >= 0.87266463f || kind == 8 || kind == 12) {
        f32 dot;
        u8 *hit = (u8 *)D_L01_001EAA00;
        h = &D_001A4BE0_004EF3A8;
        h->ground = *(s32 *)(hit + 0x18);
        func_L01_00511508(hit + 0x40, hit + 0x40, 0.0f);
        func_0038CF68(hit + 0x40, hit + 0x40, 1.0f);
        dot = func_0038CE68(hit + 0x40, &h->velocity);
        if (dot < 0.0f) {
            func_0038CE20((Vec4ED3B8 *)(hit + 0x40), (Vec4ED3B8 *)(hit + 0x40), -dot);
            vec_add_ba(&h->velocity, &h->velocity, hit + 0x40);
        }
    }
}
/* localdecomp:end func_L01_004EF3A8 */
