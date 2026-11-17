/* NTSC-U draft (2026-11-14, Claude worker): C of func_L35_003A3920, the NTSC-U twin of func_L35_003A5238, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 8 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L35_003A3920 */
typedef struct V_003A3920 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A3920;

extern u8 *D_L35_0021F444;
extern u8 *D_L35_0021F3AC;
extern u8 D_L35_001D66B0[];

extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L35_003A3920(u8 *o) {
    V_003A3920 a;
    V_003A3920 b;
    u8 *q;
    s32 col;

    func_0037E2F0(&a, 0.0f, 0.25f);
    col = 0x00FFE69B;
    vec_add_ab(&a, &a, o + 0x10);
    func_0037E2F0(&b, 0.0f, 0.0041666667f);
    if (func_0037E1D8(3) != 0) {
        col = 0x00FFCD36;
    }
    q = func_L01_00472438(&a, &b, 0x19, func_0037E208(-2, 2), col | 0x7F000000, col, 0, 210000.0f, 104000.0f, 0.0f);
    if (q != 0) {
        q[2] = D_L35_0021F444[1];
        q[3] = (func_0037E1D8(2) != 0) ? 0x44 : 0x48;
    }
    q = func_L01_00472438(o + 0x10, D_L35_001D66B0, 2, 1, 0x7FFFCD36, 0x7FFFCD36, 0, 628432.0f, 628432.0f, 0.0f);
    if (q != 0) {
        q[2] = D_L35_0021F3AC[0];
        q[3] = (func_0037E1D8(2) != 0) ? 0x44 : 0x48;
    }
}
/* localdecomp:end func_L35_003A3920 */
