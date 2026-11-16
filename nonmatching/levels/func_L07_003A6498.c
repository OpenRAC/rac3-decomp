/* PAL near miss (Codex wave 6): near miss: 81 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -fno-sched-interblock @ps2as").
 * Worker's note: 30 instruction differences: 64-bit constant expansion, hoisted vertex count and loop setup; build/codex/w285/func_L07_003A6498.07.log; best tested with injected --divs 1 (not exact)
 */
#include "common.h"
/* localdecomp:start func_L07_003A6498 */
extern f32 D_L07_001E1650[];
typedef struct { f32 x, y, z, u, v, w; } Row_003A6498;
extern Row_003A6498 D_L07_002A2100[];
typedef struct { u32 a, b; } Color_003A6498;
extern Color_003A6498 D_L07_002A21F0[];
extern f32 D_L07_002A2240[][4];
void func_L07_003A6498(u8 *positions, u8 *ends, s32 count, s32 start, s32 color) {
    extern void func_0038C750(void);
    extern unsigned long func_00389598(s32);
    extern void func_003A9440(s32, unsigned long);
    extern f32 func_0038CF00(void *, void *);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    s32 i, j, index, next;
    struct { s32 count; } vertices;
    Row_003A6498 *row;
    f32 total, t;
    f32 (*p)[4] = (f32 (*)[4])positions;
    f32 (*q)[4] = (f32 (*)[4])ends;
    if (count < 2) return;
    i = 0;
    func_0038C750();
    total = 0.0f;
    func_003A9440(6, func_00389598(color));
    func_003A9440(20, 0xFF9000000260UL);
    func_003A9440(8, 0);
    vertices.count = count * 2;
    func_003A9440(66, 0x4000000044UL);
    for (; i < count; i++) {
        row = &D_L07_002A2100[i];
        index = (i + start) % count;
        next = (index + 1) % count;
        if (i != count - 1) {
            f32 distance = func_0038CF00(p[index], p[next]);
            total += distance;
            D_L07_001E1650[i] = distance;
        }
        row->x = p[index][0];
        row->y = p[index][1];
        row->z = p[index][2];
        row->u = q[index][0];
        row->v = q[index][1];
        row->w = q[index][2];
    }
    total = 1.0f / total;
    t = 0.0f;
    for (j = 0; j < count; j++) {
        u32 shade = func_0038DBD8(0x408020, 0x30802020, t);
        D_L07_002A21F0[j].b = shade;
        D_L07_002A2240[j][0] = t;
        D_L07_002A2240[j][2] = t;
        D_L07_002A21F0[j].a = shade;
        D_L07_002A2240[j][1] = 0.0f;
        t += D_L07_001E1650[j] * total;
        D_L07_002A2240[j][3] = 1.0f;
    }
    func_003D3A24(vertices.count, D_L07_002A2100, D_L07_002A21F0, D_L07_002A2240, 1);
    func_003A9440(71, 0x5360B);
}
/* localdecomp:end func_L07_003A6498 */
