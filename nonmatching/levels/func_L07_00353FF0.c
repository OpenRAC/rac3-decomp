/* PAL near miss (Codex wave 8): near miss: 43 words differ with the file's flags.
 * Worker's note: 43 diff; best log w407/func_L07_00353FF0.attempt08.log with injected divs 2. Same-sized loops reconstructed; residual allocation (count/destination registers), global address materialization and color store order; pointer-to-array rewrite retained same ...
 */
#include "common.h"
/* localdecomp:start func_L07_00353FF0 */
extern f32 D_L07_001E0EE0[];
extern f32 D_L07_00282920[][6];
extern u32 D_L07_00282A10[][2];
extern f32 D_L07_00282A60[][4];
void func_L07_00353FF0(f32 (*a)[4], f32 (*b)[4], s32 count, s32 start, s32 texture) {
    extern void func_0038C750(void);
    extern unsigned long func_00389598(s32);
    extern void func_003A9440(s32, unsigned long);
    extern f32 func_0038CF00(void *, void *);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    s32 i;
    f32 *dst, *lens;
    f32 *lens2;
    u32 *colors;
    f32 *uv;
    f32 total, t;
    s32 n;
    if (count < 2) return;
    i = 0;
    func_0038C750();
    total = 0.0f;
    func_003A9440(6, func_00389598(texture));
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(8, 0);
    func_003A9440(0x42, 0x4000000044UL);
    if (count > 0) {
    dst = &D_L07_00282920[0][0];
    lens = D_L07_001E0EE0;
    do {
        s32 k = (i + start) % count;
        s32 next = (k + 1) % count;
        if (i != count - 1) {
            f32 len = func_0038CF00(a[k], a[next]);
            total += len;
            *lens = len;
        }
        dst[0] = a[k][0];
        dst[1] = a[k][1];
        dst[2] = a[k][2];
        dst[3] = b[k][0];
        dst[4] = b[k][1];
        dst[5] = b[k][2];
        dst += 6; lens++;
        i++;
    } while (i < count);
    }
    total = 1.0f / total;
    t = 0.0f;
    if (count > 0) {
    s32 j;
    uv = &D_L07_00282A60[0][0];
    colors = &D_L07_00282A10[0][0];
    lens2 = D_L07_001E0EE0;
    j = count;
    do {
        u32 color = func_0038DBD8(0x804020, 0x30202080, t);
        colors[0] = color;
        uv[0] = t;
        uv[2] = t;
        colors[1] = color;
        uv[1] = 0;
        t += *lens2++ * total;
        uv[3] = 1;
        colors += 2; uv += 4;
    } while (--j != 0);
    }
    func_003D3A24(count * 2, D_L07_00282920, D_L07_00282A10, D_L07_00282A60, 1);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L07_00353FF0 */
