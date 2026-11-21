/* PAL near miss (Codex wave 11): near miss: 176 words differ alone (--no-context; in the file's context neither compiles, the file declares it void(void) and retail reads $a0).
 * Replaces the earlier draft (Codex wave 6 near miss: 221 words differ under tools/check.py alone (--no-context; in the file's context neither compiles, the file declares it void(void) and retail reads $a0), measured 2026-11-21;
 * this one: 176).
 * Worker's note: blocked by the file prototype: the 003EEB40 block declares extern void func_L20_003F0088(void) but retail reads $a0 (lw $s0,0x68($a0)); with the context check.py gives conflicting types. Local experiment (--no-context, the file declarations it uses in a prelude, injected divs 2,2) on a new j-form draft (vu0.h vec_sub_ab/vec_add_ba/vec_sub_ba, func_0038AF30 with the frontbin prototype (s32,s32,s32,s32,unsigned long) and (s32)0x80808080): 11 diff (was 195): move $a2 vs mov.s $f15/$f16 order before the second func_L20_003F0418 call, and vf1/vf2 swapped in the last two VU0 sequences (g.pos[2], g.pos[3]); NEEDS divs row 'func_L20_003F0088 2 2' and the prototype corrected to (u8 *)
 */
#include "common.h"
#include "vu0.h"

/* Test prelude only (--no-context): the declarations of L20_003EEB40.c in
   front of this block that the function uses, as the file has them. The
   file's own `extern void func_L20_003F0088(void);` is left out: retail
   reads a0, so that prototype needs correcting to (u8 *). */
typedef struct {
    vu0_v4 pos;
    u8 pad10[0x450];
} C_003EEB40;
extern s32 D_001D52F0;
extern C_003EEB40 D_L20_001E2E80[];
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L20_003F0088 */
typedef struct { f32 x, y; } UV_003F0088;
typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    UV_003F0088 uv[4];
    u8 pad70[0x20];
} G_003F0088;
typedef struct {
    f32 inner;
    f32 outer;
    f32 brightness;
    u8 padC[4];
    s16 frame;
    s16 duration;
    s16 alpha;
    s16 pad16;
    s16 ring;
    s16 flash;
    s16 pad1C;
    s16 beam;
} State_003F0088;
extern s16 D_001CFEC0[];

void func_L20_003F0088(u8 *obj) {
    extern void func_003A9440(long, long);
    extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
    extern void func_L20_003F0418(vu0_v4 *, s32, s32, f32, f32, f32, f32, f32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, s32, s32);
    G_003F0088 g;
    vu0_v4 camera;
    vu0_v4 delta;
    vu0_v4 rotated;
    vu0_v4 center;
    vu0_v4 side;
    vu0_v4 up;
    vu0_v4 temp;
    State_003F0088 *state = *(State_003F0088 **)(obj + 0x68);
    f32 scale;
    u32 color;
    s32 left;

    if (state->flash != 0 && state->duration - state->frame < 2 && state->alpha != 0) {
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_001CFEC0[0xA9], 0, D_001CFEC0[0xA8], (s32)0x80808080);
    }
    if (state->ring != 0) {
        left = state->duration - state->frame;
        if (left < 10) {
            func_L20_003F0418((vu0_v4 *)(obj + 0x10), 0x3B, 0,
                state->inner + (state->outer - state->inner) * ((f32)left / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f);
        } else if ((u16)(state->frame - 46) < 4) {
            func_L20_003F0418((vu0_v4 *)(obj + 0x10), 0x3B, 0,
                state->inner + (state->outer - state->inner) * ((f32)(state->frame - 45) / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f);
        }
    }
    if (state->beam != 0 && state->alpha != 0) {
        func_003C5180(obj + 0x10, &camera, 1);
        scale = (f32)state->alpha * state->brightness;
        func_003D93B0(&g, 11, 4, 0x80);
        color = ((s32)(scale * 255.0f) << 24) | 0xFFFFFF;
        g.col[3] = color;
        g.col[2] = color;
        g.col[1] = color;
        g.col[0] = color;
        g.uv[0].x = 0; g.uv[0].y = 0;
        g.uv[1].x = 0; g.uv[1].y = 1.0f;
        g.uv[2].x = 1.0f; g.uv[2].y = 0;
        g.uv[3].x = 1.0f; g.uv[3].y = 1.0f;
        vec_sub_ab(&delta, obj + 0x10, &D_L20_001E2E80[D_001D52F0].pos);
        func_0038CF68(&rotated, &delta, 0.1f);
        vec_add_ba(&center, &D_L20_001E2E80[D_001D52F0].pos, &rotated);
        func_0038CE90(&side, &delta, &camera);
        func_0038CF68(&side, &side, 0.075f);
        func_0038CE90(&up, &side, &delta);
        func_0038CF68(&up, &up, 0.075f);
        vec_add_ba(&temp, &center, &up);
        vec_add_ba(&g.pos[0], &temp, &side);
        vec_sub_ba(&g.pos[1], &temp, &side);
        vec_sub_ba(&temp, &center, &up);
        vec_add_ba(&g.pos[2], &temp, &side);
        vec_sub_ab(&g.pos[3], &temp, &side);
        func_003D2DA0(&g, 0, 0);
    }
}
/* localdecomp:end func_L20_003F0088 */
