/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_006DE168, the NTSC-U twin of func_L39_006E0CC8, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/39_multiplayer_menu/L39_006E0730.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_006E0CC8 (src/levels/39_multiplayer_menu/L39_006E0730.c) */

/* localdecomp:start func_L39_006DE168 */
extern f32 D_001A6BC4[];

f32 func_L39_006DE168(void) {
    return 2.30258512f / D_001A6BC4[0];
}
/* localdecomp:end func_L39_006DE168 */
