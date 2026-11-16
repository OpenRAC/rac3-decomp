/* Near miss: target_search_level. Same code as retail except gcc hoists the five id constants (0x1A17..) into $s5/$fp (9 registers) where retail hoists only 0xFE, 0xFD, 5 and no $fp. */
#include "common.h"
typedef struct {
    u8 pad0[0x20];
    u8 type;
    u8 pad21[0x24 - 0x21];
    u8 *cls;
    u8 pad28[0x31 - 0x28];
    u8 b31;
    u8 pad32[0x34 - 0x32];
    u16 flags;
    u8 pad36[0xAA - 0x36];
    s16 id;
} M_450010;
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_450010;

extern M_450010 *D_L01_0021E860[];
extern f32 *func_00382348(M_450010 *);
extern f32 func_L01_0044FE98(f32 *, void *, s32 *, f32, f32, f32, f32);

/* target_search_level: of the mobys it may look at, the closest to `ref_yaw` within range
 * (the score func_L01_0044FE98 gives); `enemies_only` skips the ones that aren't enemy targets. */
M_450010 *func_L01_00450010(Vec4_450010 *pos, s32 enemies_only, f32 ref_yaw, f32 range, f32 max_yaw, f32 max_elev) {
    Vec4_450010 from = *pos;
    f32 *from_p = (f32 *)&from;
    M_450010 **p = D_L01_0021E860;
    M_450010 *moby = *p;
    M_450010 *best = 0;
    f32 best_score = 1e8f;
    f32 score;
    s32 out;

    for (; moby != 0; moby = *++p) {
        f32 *scale = func_00382348(moby);
        if (scale == 0 || *scale == 0.0f) {
            continue;
        }
        if (enemies_only != 0) {
            if (moby->flags & 2) continue;
            if (moby == 0) continue;
            if (moby->type == 0xFE) continue;
            if (moby->type == 0xFD) continue;
            if (moby->b31 == 0) continue;
            if (moby->cls == 0) continue;
            if (moby->cls[0x46] != 5) continue;
            if (moby->id == 0x1A17 || moby->id == 0x1B27 || moby->id == 0x1AE6 || moby->id == 0x107E || moby->id == 0x1D87) continue;
        }
        score = func_L01_0044FE98(from_p, moby, &out, ref_yaw, range, max_yaw, max_elev);
        if (out == 0 && score < best_score) {
            best_score = score;
            best = moby;
        }
    }
    return best;
}
