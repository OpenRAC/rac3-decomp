/* PAL near miss (Codex wave 6): near miss: 12 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: 4 instruction diffs with injected --divs 1: constant 0x4000000044 expansion and UV/color address init order; no byte MATCH; best build/codex/w324/func_L07_003CE618.02.log (12 diffs without metadata in .01.log)
 */
#include "common.h"
/* localdecomp:start func_L07_003CE618 */
typedef struct { f32 xyz[3]; f32 other[3]; } Vertex_003CE618;
typedef struct { f32 x, y, z, w; } UV_003CE618;
extern Vertex_003CE618 D_L07_002A2BD0[];
extern u32 D_L07_002A2CC0[][2];
extern UV_003CE618 D_L07_002A2D10[];
extern f32 D_L07_001E17A0[] __attribute__((section(".sdata")));
void func_L07_003CE618(u8 *a0, u8 *a1, s32 count, s32 start, s32 texture, s32 color1, s32 color2) {
    extern void func_0038C750(void);
    extern s32 func_00389598(s32);
    extern s32 func_003A9440(long, unsigned long);
    extern f32 func_0038CF00(void *, void *);
    extern void *func_0038CC88(void *, void *, s32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern s32 func_003D3A24(s32, void *, void *, void *, s32);
    s32 i;
    s32 index;
    s32 next;
    s32 remaining;
    f32 total;
    f32 t;
    s32 color;
    if (count < 2) return;
    func_0038C750();
    total = 0.0f;
    func_003A9440(6, func_00389598(texture));
    func_003A9440(20, 0x0000FF9000000260UL);
    func_003A9440(8, 0);
    func_003A9440(0x42, 0x4000000044UL);
    for (i = 0; i < count; i++) {
        index = (i + start) % count;
        next = (index + 1) % count;
        if (i != count - 1) {
            f32 distance = func_0038CF00(a0 + index * 16, a0 + next * 16);
            total += distance;
            D_L07_001E17A0[i] = distance;
        }
        func_0038CC88(D_L07_002A2BD0[i].xyz, a0 + index * 16, 12);
        func_0038CC88(D_L07_002A2BD0[i].other, a1 + index * 16, 12);
    }
    total = 1.0f / total;
    t = 0.0f;
    remaining = count;
    i = 0;
    if (remaining > 0) do {
        color = func_0038DBD8(color2, color1, t);
        D_L07_002A2D10[i].x = t;
        D_L07_002A2CC0[i][1] = color;
        D_L07_002A2D10[i].z = t;
        D_L07_002A2CC0[i][0] = color;
        D_L07_002A2D10[i].y = 0.0f;
        t += D_L07_001E17A0[i] * total;
        D_L07_002A2D10[i].w = 1.0f;
        i++;
    } while (--remaining != 0);
    func_003D3A24(count * 2, D_L07_002A2BD0, D_L07_002A2CC0, D_L07_002A2D10, 1);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L07_003CE618 */
