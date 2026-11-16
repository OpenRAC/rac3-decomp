/* PAL near miss (Codex wave 8): near miss: 83 words differ with the file's flags.
 * Worker's note: Best 83 diff: w431/func_L01_00456910.04.log; source/check/out/best register allocation and early-return branch layout differ. Three later structurally different forms (05-07) emit identical 119-diff bytes; stopped and restored best04.
 */
#include "common.h"
/* localdecomp:start func_L01_00456910 */
extern s32 D_001DFB40_sda;
typedef struct { u8 pad[0x25C0]; M_453408 *hero; } State_00456910;
extern State_00456910 D_001A4BE0;
M_453408 *func_L01_00456910(M_453408 *source, s32 index, s32 *out, s32 team, s32 c, s32 d, s32 check, s32 g, f32 scale)
{
    extern void func_L01_00456270(s32);
    extern f32 func_L01_004566F8(M_453408 *, M_453408 *, s32, s32, s32, s32, f32);
    u8 *rec;
    s32 count;
    M_453408 *item;
    M_453408 *best = 0;
    void *pos;
    f32 dist;
    if (index < 0) return 0;
    if (index >= *(s32 *)D_L01_001DFC4C || D_001DFB40_sda < 2) return 0;
    pos = 0;
    if (check) pos = &source->x;
    func_L01_00456270(index);
    rec = D_L01_001DFC48 + index * 0xE0;
    count = rec[4];
    if (count == 0) return 0;
    if (count == 1) {
        void *other;
        M_453408 *single = *(M_453408 **)rec;
        if (single == 0) return 0;
        other = &single->x;
        if (!check) other = 0;
        *out = rec[5];
        if (team != 0) {
            if (!check || func_003D3CB0(pos, other, 2, source, 0)) {
                M_453408 *single2 = *(M_453408 **)rec;
                if (*out == team || single2 == D_001A71A0[0]) return single2;
            }
        } else {
            if (!check || func_003D3CB0(pos, other, 2, source, 0)) return *(M_453408 **)rec;
        }
        return 0;
    }
    dist = 9999999.0f;

    if (count != 0) {
    s32 n = count;
    do {
        item = *(M_453408 **)rec;
        if (item != 0) {
            f32 v = func_L01_004566F8(source, item, c, d, check, g, scale);
            if (v < dist && item != source) {
                if (team != 0) {
                    s32 t = rec[5];
                    if (t == team || item == D_001A4BE0.hero) {
                        best = *(M_453408 **)rec;
                        dist = v;
                        *out = t;
                    }
                } else {
                    s32 t = rec[5];
                    dist = v;
                    best = *(M_453408 **)rec;
                    *out = t;
                }
            }
        }
        n--;
        rec += 8;
    } while (n != 0);
    }
    return best;
}
/* localdecomp:end func_L01_00456910 */
