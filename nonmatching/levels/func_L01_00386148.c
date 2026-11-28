/* func_L01_00386148 (Claude wave 14 retry r85, 2026-11-28). Replaces the earlier draft of this function (Codex wave 8 near miss). */
#include "common.h"
/* PAL near miss (wave 14 retry r85): 41 diffs at level 01 with the file's flags and an injected divs row
 * 'func_L01_00386148 2' (r67's draft: 42). Changed against r67: packet.col[3] = colour_start written right after the
 * alpha shift, before the first VU copy (a decomp-permuter find), which moves one store into retail's slot.
 * Still differs (r67's analysis, confirmed with -dg/-dS dumps): retail's 0x100 is a reload spill of a VU0 value
 * where this draft has the memory temp at 0xF0 (the unused 16 bytes after it are a reload-time slot, vars=272 with no
 * references), so sched1 moves the D load above the temp store and vf1/vf2 swap roles in the pre-loop and the loop.
 * vu0_q value forms that make the temp a pseudo give the spill, but sched1 then hoists the p[i-1] copy above the vsub
 * (equal priority, more dependents) and spills the wrong value, or loop.c hoists 1.0f (143-168 diffs). */

/* localdecomp:start func_L01_00386148 */
#include "vu0.h"
typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    f32 uv[4][2];
    long a;
    long tex;
    long c;
    long d;
} S_00386148;
extern vu0_v4 D_L01_001E29C0_00386148;

void func_L01_00386148(void *points, s32 a1, s32 a2, s32 count, s32 colour_end, s32 colour_start, f32 f0, f32 f1, f32 scroll) {
    extern void func_003D93B0(void *, s32, s32, s32);
    S_00386148 packet;
    vu0_v4 cross;
    vu0_v4 scaled;
    vu0_v4 camera;
    vu0_v4 tangent;
    vu0_v4 delta;
    vu0_v4 prev;
    vu0_v4 temp;
    vu0_v4 *p = points;
    s32 i;
    s32 alpha;
    f32 end;
    f32 t;
    s32 a;
    s32 c;

    func_003D93B0(&packet, a2, 1, 128);
    alpha = (u32)colour_start >> 24;
    packet.col[3] = colour_start;
    packet.uv[0][0] = 0.0f;
    vec_copy(&temp, p);
    vec_sub_ba(&delta, &temp, &D_L01_001E29C0_00386148);
    end = scroll + 1.0f;
    packet.uv[2][0] = end;
    scroll += packet.uv[0][0];
    packet.uv[0][0] = scroll;
    packet.col[2] = colour_start;
    packet.col[1] = colour_start;
    packet.col[0] = colour_start;
    packet.uv[0][1] = 0.0f;
    packet.uv[1][1] = 1.0f;
    packet.uv[2][1] = 0.0f;
    packet.uv[3][1] = 1.0f;
    packet.uv[1][0] = scroll;
    packet.uv[3][0] = end;
    vec_sub_ab(&tangent, &p[1], &p[0]);
    vec_copy(&camera, &delta);
    func_0038CE90(&cross, &tangent, &camera);
    func_0038CF68(&scaled, &cross, p->w);
    func_0038CE20((u128_384E68 *)&scaled, (u128_384E68 *)&scaled, f1);
    vec_add_ba(&packet.pos[0], p, &scaled);
    vec_sub_ab(&packet.pos[1], p, &scaled);
    for (i = 1; i < count; i++) {
        vec_sub_ab(&temp, &p[i], &D_L01_001E29C0_00386148);
        vec_copy(&prev, &p[i - 1]);
        vec_copy(&camera, &temp);
        vec_sub_ab(&tangent, &p[i], &prev);
        func_0038CE90(&cross, &tangent, &camera);
        func_0038CF68(&scaled, &cross, p[i].w);
        func_0038CE20((u128_384E68 *)&scaled, (u128_384E68 *)&scaled, f1);
        t = 1.0f - (f32)i / (f32)count;
        a = (s32)((f32)alpha * t);
        vec_add_ba(&packet.pos[2], &p[i], &scaled);
        vec_sub_ab(&packet.pos[3], &p[i], &scaled);
        c = colour_start & 0x2F2FAF;
        c = func_0038DBD8(0x2020FF, c, t) | (a << 24);
        packet.col[3] = c;
        packet.col[2] = c;
        func_003D2DA0(&packet, 0, 0);
        *(u128_384E68 *)&packet.pos[0] = *(u128_384E68 *)&packet.pos[2];
        *(u128_384E68 *)&packet.pos[1] = *(u128_384E68 *)&packet.pos[3];
        packet.col[0] = packet.col[2];
        packet.col[1] = packet.col[3];
    }
}
/* localdecomp:end func_L01_00386148 */
