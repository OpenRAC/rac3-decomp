/* PAL near miss (Codex wave 8): near miss: 85 words differ with the file's flags.
 * Worker's note: 85 positional word differences; 464 vs 468 bytes; loop setup, point pointer allocation, hoisted 0x1A17 and call scheduling. Nine compiles, best log build/codex/w453/func_L01_00450010.check01.log
 */
#include "common.h"
/* localdecomp:start func_L01_00450010 */
typedef int Q_00450010 __attribute__((mode(TI)));
extern u8 *D_L01_0021E860[];
u8 *func_L01_00450010(Q_00450010 *pos, s32 filter, f32 yaw, f32 range, f32 horizontal, f32 vertical) {
    extern f32 *func_00382348(u8 *);
    extern f32 func_L01_0044FE98(f32 *, f32 *, s32 *, f32, f32, f32, f32);
    Q_00450010 point;
    s32 rejected;
    u8 *best = 0;
    f32 distance = 100000000.0f;
    u8 **it;
    u8 *m;
    point = *pos;
    for (it = D_L01_0021E860; (m = *it) != 0; it++) {
        f32 *data = func_00382348(m);
        f32 d;
        if (!data || data[0] == 0.0f) continue;
        if (filter) {
            s16 type;
            if (*(u16 *)(m + 0x34) & 2) continue;
            if (!m || m[0x20] == 0xFE || m[0x20] == 0xFD || !m[0x31] ||
                !*(u8 **)(m + 0x24) || (*(u8 **)(m + 0x24))[0x46] != 5) continue;
            type = *(s16 *)(m + 0xAA);
            if (type == 0x1A17 || type == 0x1B27 || type == 0x1AE6 || type == 0x107E || type == 0x1D87) continue;
        }
        d = func_L01_0044FE98((f32 *)&point, (f32 *)m, &rejected, yaw, range, horizontal, vertical);
        if (!rejected && d < distance) {
            distance = d;
            best = m;
        }
    }
    return best;
}
/* localdecomp:end func_L01_00450010 */
