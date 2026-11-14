/* NTSC-U draft (2026-11-14, Claude worker): C of func_L02_003A1AB8, the NTSC-U twin of func_L02_003A3898, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L02_003A28A8.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L02_003A3898 (src/levels/shared/L02_003A28A8.c) */
/* localdecomp:start func_L02_003A1AB8 */
extern f32 D_001DDD58_sda;
__asm__(".extern D_001DDD58_sda, 4");
extern f32 D_001DDD5C_sda;
__asm__(".extern D_001DDD5C_sda, 4");
extern f32 D_001DDD60_sda;
__asm__(".extern D_001DDD60_sda, 4");
extern f32 func_00388730(void *, void *);

void func_L02_003A1AB8(u8 *obj, void *other, f32 x) {
    f32 s;
    f32 r;
    f32 t;

    s = D_001DDD58_sda * 0.017453292f;
    *(f32 *)(obj + 0xF0) = *(f32 *)(obj + 0xF0) - x * D_001DDD5C_sda * D_001DDD60_sda;
    r = func_00388730(other, obj + 0xD0) / 0.10000001f;
    if (r < 1.0f) {
        t = s * (func_00388730(other, obj + 0xD0) / 0.10000001f);
    } else {
        t = s;
    }
    *(f32 *)(obj + 0xF0) = *(f32 *)(obj + 0xF0) * (1.0f - D_001DDD60_sda) + t * D_001DDD60_sda;
}
/* localdecomp:end func_L02_003A1AB8 */
