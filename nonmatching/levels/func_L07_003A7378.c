/* PAL near miss (Codex wave 8): near miss: 44 words differ with the file's flags.
 * Worker's note: 44 diff; w446/func_L07_003A7378.a5.log; fixed non-ps2as flags load 0.3f from lit4 while retail materializes inline; remaining load/store scheduling; no metadata involved
 */
#include "common.h"
/* localdecomp:start func_L07_003A7378 */
typedef int TI_003A7378 __attribute__((mode(TI)));
typedef struct { TI_003A7378 v; } Q_003A7378;
void *func_L07_003A7378(u8 *parent, u8 kind, Q_003A7378 *pos, u8 mode, f32 value) {
    extern void *func_003C24B0(s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_0044FD88(void *, void *, s32, s32);
    extern void func_003C7C38(void *);
    extern void func_L07_003A7558(void *);
    f32 copy[4] __attribute__((aligned(16)));
    u8 *obj;
    u8 *state;
    *(TI_003A7378 *)copy = *(TI_003A7378 *)pos;
    obj = func_003C24B0(0x1980, 0x2C0);
    if (obj) {
        obj[0x30] = 255;
        *(u16 *)(obj + 0x32) = *(u16 *)(parent + 0x32);
        *(u16 *)(obj + 0x34) |= 0x100;
        state = *(u8 **)(obj + 0x68);
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.3f;
        func_L01_004450F0(obj, 0, 0);
        *(u8 **)(obj + 0xB8) = parent;
        func_L01_0044FD88(parent, obj, kind, 0);
        *(u16 *)(obj + 0x34) &= ~2;
        state[0x2BB] = mode;
        state[0x2BA] = kind;
        state[0x2BC] = 0;
        *(TI_003A7378 *)(state + 0x280) = *(TI_003A7378 *)copy;
        *(f32 *)(state + 0x298) = value;
        func_003C7C38(obj);
        func_L07_003A7558(obj);
    }
    return obj;
}
/* localdecomp:end func_L07_003A7378 */
