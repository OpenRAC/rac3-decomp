#include "common.h"

/* localdecomp:start func_L01_004E8BC8 */
#include "vu0.h"
typedef int u128_4E8BC8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_4E8BC8;
/* A rail of the level's list (open-rac-engine docs/research/hero-controller.md, "Grinding"):
   a bounding sphere, its spline (a point count, then 16-byte points from +0x10) and its kind. */
typedef struct {
    Vec_4E8BC8 center;             /* 0x00: w is the radius */
    u8 *spline;                    /* 0x10 */
    s32 kind;                      /* 0x14 */
    u8 pad_18[0x20 - 0x18];
} Rail_4E8BC8;
extern Rail_4E8BC8 *D_L01_001DFC90;
extern s32 D_L01_001DFC94;
/* rail_nearest: the nearest point of any rail in the level's list to `from`, within 0.9 u
   horizontally (0.3 while standing or walking, 0.5 more and 10 u vertically while +0x1F6 is set)
   and 1.5 u vertically, with something solid under it unless no_probe; `ignored` skips one rail,
   `required` takes only that one, and as the disguise (body kind 5) rails whose two ends are level
   in x are skipped. Returns 1 with the rail, the point, its segment, parameter and kind. */
s32 func_L01_004E8BC8(u128_4E8BC8 *from, s32 *out_spline, u128_4E8BC8 *out_point, s32 *out_segment, f32 *out_t, s32 *out_kind, s32 ignored, s32 required, s32 no_probe)
{
    extern s32 func_L01_00476B98(void *, void *, void *, s32 *, f32 *, s32, f32, f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
    extern f32 func_0038CF00(Vec_4E8BC8 *, Vec_4E8BC8 *);
    extern f32 func_0038CF38(Vec_4E8BC8 *, Vec_4E8BC8 *);
    extern u8 D_001A4BE0[];
    Vec_4E8BC8 position, top, bottom;
    Vec_4E8BC8 *pos = &position;
    s32 segment;
    f32 t;
    s32 i;
    *(u128_4E8BC8 *)&position = *from;
    for (i = 0; i < D_L01_001DFC94; i++) {
        f32 horizontal;
        f32 vertical;
        s32 solid;
        u8 *spline;
        if (ignored && (s32)D_L01_001DFC90[i].spline == ignored) continue;
        if (D_001A4BE0[0x25E4] == 5) {
            spline = D_L01_001DFC90[i].spline;
            if (spline && fabs_asm(*(f32 *)(spline + 0x10) - *(f32 *)(spline + ((*(s32 *)spline - 1) << 4) + 0x10)) < 0.1f) continue;
        }
        if (required && (s32)D_L01_001DFC90[i].spline != required) continue;
        if (*(s32 *)D_L01_001DFC90[i].spline == 0) continue;
        if (func_0038CF00(&D_L01_001DFC90[i].center, pos) > D_L01_001DFC90[i].center.w) continue;
        if (!func_L01_00476B98(D_L01_001DFC90[i].spline, pos, out_point, &segment, &t, D_L01_001DFC90[i].kind, 12.0f, 10.0f, 0.0f)) continue;
        {
            u8 *hero = D_001A4BE0;
            horizontal = 0.9f;
            vertical = 1.5f;
            if ((u32)*(s32 *)(hero + 0x25CC) < 2) horizontal = 0.3f; /* state type: standing or walking */
            if (*(s16 *)(hero + 0x1F6) != 0) {
                horizontal += 0.5f;
                vertical = 10.0f;
            }
        }
        solid = 1;
        if (!no_probe) {
            *(u128_4E8BC8 *)&top = *out_point;
            *(u128_4E8BC8 *)&bottom = *out_point;
            top.z += 0.25f;
            bottom.z -= 1.0f;
            if (func_003D3CB0(&top, &bottom, 2, 0, 0) == 0) solid = 0;
        }
        {
            f32 distance = func_0038CF38(pos, (Vec_4E8BC8 *)out_point);
            f32 dz = fabs_asm(pos->z - ((Vec_4E8BC8 *)out_point)->z);
            if (distance < horizontal && dz < vertical && solid) {
                *out_spline = (s32)D_L01_001DFC90[i].spline;
                *out_segment = segment;
                *out_t = t;
                *out_kind = D_L01_001DFC90[i].kind;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_004E8BC8 */
