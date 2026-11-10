#include "common.h"

/* localdecomp:start func_L39_00517780 */
typedef struct { char _p0[0x10]; s32 f10; u8 f14; } S_00517780;
s32 func_L39_00517780(S_00517780 *p, s32 a1) {
    s32 v = p->f10;
    u8 f;
    if (v != a1) {
        return 7;
    }
    f = p->f14;
    if (f & 0xC0) {
        return 7;
    }
    if (((u32)(v - 0x10) < 2) != ((f >> 5) & 1)) {
        return 7;
    }
    return 0;
}
/* localdecomp:end func_L39_00517780 */

/* localdecomp:start func_L39_005177C0 */
/* The file defines S_00517868 and func_L39_00517868 further down: when landing, hoist that typedef
   up to here and drop this copy (the prototype below must agree with that definition). */
typedef struct {
    unsigned long f0;
    s32 f8;
    u8 padC[0xA];
    u8 flags;
} S_00517868;
extern void func_L39_00517828(S_00517868 *descriptor, u32 flags, u32 type, u32 properties);
extern void func_L39_00517868(S_00517868 *p, s32 a, u32 b);

/* from rac4-decomp's func_L00_005535D0 */
void func_L39_005177C0(S_00517868 *descriptor, u32 flags, u32 type, s32 data, u32 length, u32 properties, u32 extraFlags) {
    func_L39_00517828(descriptor, flags, type, properties);
    func_L39_00517868(descriptor, data, length);
    descriptor->flags |= extraFlags;
}
/* localdecomp:end func_L39_005177C0 */
