#include "common.h"

/* localdecomp:start func_L08_003A3C90 */
extern u8 *D_L08_001DF21C;
typedef struct { u8 pad0[0x464]; u8 f464[1]; } S_003A3C90;
extern S_003A3C90 D_L08_00235280;
extern u8 D_001BBE90[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 func_L01_00456500(u8 *, s32);
extern s32 func_L01_00456250(void *);
extern f32 func_L01_0040E548(void *, void *);

s32 func_L08_003A3C90(u8 *obj, s32 sel)
{
    u8 *p = *(u8 **)(obj + 0x68);
    s32 a = sel ? *(s32 *)(p + 0x2EC) : *(s32 *)(p + 0x2D4);
    s32 b = sel ? *(s32 *)(p + 0x2F4) : *(s32 *)(p + 0x2DC);
    s32 c = sel ? *(s32 *)(p + 0x2FC) : *(s32 *)(p + 0x2E4);
    u8 *m;

    if (a != -1 && func_L01_00456500(p + 0x220, a) != 0) {
        return 1;
    }
    if (b != -1) {
        s16 cls;
        s32 v;
        u16 raw;
        m = D_L08_001DF21C + (b << 8);
        if (func_L01_00456250(m) != 0) {
            return 1;
        }
        raw = *(u16 *)(m + 0xB2);
        cls = raw;
        if (D_L08_00235280.f464[cls] != 0
            || ((v = D_001BBE90[(cls >> 1) + (D_001D545C << 10)]), ((raw & 1) ? v >> 4 : v) & 7)) {
            if (func_L01_0040E548(p + 0x220, m + 0x10) < 49.0f) {
                return 1;
            }
        }
    }
    if (c != -1) {
        u8 *n = D_L08_001DF21C + (c << 8);
        if (n == 0 || n[0x20] == 0xFE || n[0x20] == 0xFD) {
            if (sel) {
                *(s32 *)(p + 0x2FC) = -1;
            } else {
                *(s32 *)(p + 0x2E4) = -1;
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L08_003A3C90 */

/* localdecomp:start func_L08_003A3E20 */
extern s32 func_L01_00456500(u8 *, s32);

s32 func_L08_003A3E20(u8 *obj, s32 sel) {
    u8 *p = *(u8 **)(obj + 104);
    s32 id;
    if (sel != 0) {
        id = *(s32 *)(p + 752);
    } else {
        id = *(s32 *)(p + 728);
    }
    if (id != -1) {
        if (func_L01_00456500(p + 544, id) != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L08_003A3E20 */
