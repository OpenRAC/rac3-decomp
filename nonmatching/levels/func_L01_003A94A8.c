/* func_L01_003A94A8 (Claude wave 14 r73, 2026-11-28). Replaces the earlier draft of this function (Codex wave 8 near miss). */
/* PAL near miss (wr73, wave 14): 204 words differ (wave10/p10/check.py, level 01, the file's flags); the
 * Codex wave 8 draft before it did not compile (literal newlines in its asm strings) and used one asm block
 * per vector op. This version is plain C with the vu0.h helpers (vec_add_ab/vec_sub_ab/vec_sub_ba/vec_copy),
 * which lets gcc interleave the scalar code with the VU loads as retail does, and the file's own
 * func_003D9508/func_0038CF68/func_00382538 declarations. Aligned (difflib) the object differs in about 110
 * lines: (1) retail keeps scale's copy `mov.s $f20,$f0` and adds 0.75 in place later, here combine merges the
 * copy into the add (one instruction fewer), which shifts the first VU block's schedule; (2) the callee-saved
 * registers of the values gcse carries into the second half are assigned in another order (retail: dst1
 * s0, a s3, dst0 s4, &packet s5, diff s6, D_L01_001E29C0's high part s7). Writing the uv loops with index
 * sources and pointer destinations (`*dst0 = D_L01_001DE378[i * 2]; dst0 += 2;`) removes the extra $fp this
 * version needs and is closer aligned (103-105 lines) but counts 233-235 positionally. */
#include "common.h"

/* localdecomp:start func_L01_003A94A8 */
#include "vu0.h"
typedef struct {
    Vec4 v[4];
    s32 color[4];
    f32 uv[8];
    long state[4];
} Packet_003A94A8;
extern Vec4 D_L01_001E29C0;
extern f32 D_L01_001DE378[];
extern f32 D_L01_001DE37C[];
void func_L01_003A94A8(u8 *obj) {
    extern void func_0038CE90(u8 *, u8 *, u8 *);
    extern f32 func_L01_00443A18(f32, f32);
    extern long func_00389598(s32);
    extern void func_003D2DA0(void *, s32, s32);
    Vec4 pos;
    Packet_003A94A8 packet;
    Vec4 a, b, diff, offset, copy, tmp, cam0, cam1, cam2;
    u8 *vars;
    f32 scale;
    s32 i;

    pos = *(Vec4 *)(obj + 0x10);
    vars = *(u8 **)(obj + 0x68);
    func_003D9508(&pos, 0x41, 0x40206080, 1, 0.75f, 0.01f, func_00382538());
    func_0038CF68((u8 *)&offset, (Vec4 *)vars, -3.0f);
    vec_add_ab(&offset, &pos, &offset);
    scale = func_L01_00443A18(0.0f, 0.2f);
    vec_sub_ba(&diff, &pos, &offset);
    vec_copy(&cam2, &D_L01_001E29C0);
    scale += 0.75f;
    vec_copy(&cam0, &D_L01_001E29C0);
    vec_sub_ab(&a, &pos, &cam2);
    vec_sub_ab(&b, &offset, &cam0);
    func_0038CE90((u8 *)&a, (u8 *)&a, (u8 *)&diff);
    func_0038CF68((u8 *)&a, &a, scale);
    func_0038CE90((u8 *)&b, (u8 *)&b, (u8 *)&diff);
    func_0038CF68((u8 *)&b, &b, scale);
    packet.state[1] = func_00389598(0x3F);
    packet.state[2] = 0xFF9000000260L;
    packet.state[3] = 0x8000000048L;
    packet.state[0] = 0;
    packet.color[0] = 0x50206080;
    packet.color[3] = 0x50206080;
    packet.color[2] = 0x50206080;
    packet.color[1] = 0x50206080;
    {
        f32 *src0 = D_L01_001DE378, *dst0 = &packet.uv[0], *src1 = D_L01_001DE37C, *dst1 = &packet.uv[1];
        for (i = 0; i < 4; i++) {
            f32 u = *src0;
            f32 v = *src1;
            *dst0 = u;
            *dst1 = v;
            src0 += 2;
            src1 += 2;
            dst0 += 2;
            dst1 += 2;
        }
    }
    vec_sub_ab(&tmp, &offset, &a);
    copy = tmp;
    packet.v[0] = copy;
    vec_add_ab(&tmp, &offset, &a);
    copy = tmp;
    packet.v[1] = copy;
    vec_sub_ab(&tmp, &pos, &b);
    copy = tmp;
    packet.v[2] = copy;
    vec_add_ab(&tmp, &pos, &b);
    copy = tmp;
    packet.v[3] = copy;
    func_003D2DA0(&packet, 0, 0);
    *(f32 *)(vars + 0x1C) += 0.15f;
    if (*(f32 *)(vars + 0x1C) >= 4.0f)
        *(f32 *)(vars + 0x1C) -= 4.0f;
    vec_sub_ba(&diff, &pos, &offset);
    vec_copy(&cam1, &D_L01_001E29C0);
    vec_sub_ab(&a, &pos, &D_L01_001E29C0);
    vec_sub_ab(&b, &offset, &cam1);
    func_0038CE90((u8 *)&a, (u8 *)&a, (u8 *)&diff);
    func_0038CF68((u8 *)&a, &a, 0.15f);
    func_0038CE90((u8 *)&b, (u8 *)&b, (u8 *)&diff);
    func_0038CF68((u8 *)&b, &b, 0.4f);
    packet.state[1] = func_00389598(0x3D);
    packet.state[2] = 0xFF9000000260L;
    packet.state[3] = 0x8000000048L;
    packet.state[0] = 0;
    packet.color[0] = 0x80202080;
    packet.color[3] = 0x80202080;
    packet.color[2] = 0x80202080;
    packet.color[1] = 0x80202080;
    {
        f32 *src0 = D_L01_001DE378, *dst0 = &packet.uv[0], *src1 = D_L01_001DE37C, *dst1 = &packet.uv[1];
        for (i = 0; i < 4; i++) {
            f32 scroll = *(f32 *)(vars + 0x1C);
            f32 u = *src0;
            f32 v = *src1;
            *dst0 = u + scroll;
            *dst1 = v;
            src0 += 2;
            src1 += 2;
            dst0 += 2;
            dst1 += 2;
        }
    }
    vec_sub_ab(&tmp, &offset, &a);
    copy = tmp;
    packet.v[0] = copy;
    vec_add_ab(&tmp, &offset, &a);
    copy = tmp;
    packet.v[1] = copy;
    vec_sub_ab(&tmp, &pos, &b);
    copy = tmp;
    packet.v[2] = copy;
    vec_add_ab(&tmp, &pos, &b);
    copy = tmp;
    packet.v[3] = copy;
    func_003D2DA0(&packet, 0, 0);
}
/* localdecomp:end func_L01_003A94A8 */
