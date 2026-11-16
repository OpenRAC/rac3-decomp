/* PAL near miss (Codex wave 7): near miss: 36 words differ with the file's flags.
 * Worker's note: 7 diff with injected divs 2; fixed assembler emits literal pool for 0.025f, bit representation draft uses v0/f1 instead of retail at/f0; see w348/func_L01_00444F38.03.log. No alternate flags tried.
 */
#include "common.h"
/* localdecomp:start func_L01_00444F38 */
typedef unsigned int Q_00444F38 __attribute__((mode(TI)));
typedef struct { u8 pad[0x48]; u8 *entries[1]; } Model_00444F38;
extern Q_00444F38 D_L01_001FCB40[];
void func_L01_00444F38(u8 *obj, s32 anim, s32 mode, s32 frames, s32 flags) {
    extern void func_003C3938(u8 *, s32, s32);
    extern void func_003C6EA0(u8 *, s32, u16);
    extern s32 func_003C2D30(u8 *);
    extern void func_003C8B18(u8 *, s32);
    extern void func_003C29B0(u8 *);
    union { u32 bits; f32 value; } threshold;
    s32 slot;
    s32 copyFlags;
    if (frames <= 0) {
        func_003C3938(obj, anim, mode);
        return;
    }
    if ((u32)(mode - 1) < 10 && !(flags & 8)) {
        func_003C6EA0(obj, anim, (u16)(mode - 1));
    }
    threshold.bits = 0x3CCCCCCD;
    if (*(f32 *)(obj + 0x44) > threshold.value || *(s32 *)(obj + 0x50) || *(s32 *)(obj + 0x54) || (flags & 4)) {
        slot = func_003C2D30(obj);
        if (slot >= 0) {
            copyFlags = slot;
            if (flags & 1) copyFlags |= 0x100;
            if (flags & 2) copyFlags |= 0x200;
            func_003C8B18(obj, copyFlags);
            D_L01_001FCB40[slot] = *(Q_00444F38 *)(obj + 0x80);
            if (obj[0x42] != 255) obj[0xA9] = obj[0x42];
            obj[0x42] = 255;
            obj[0x40] = slot;
        }
    }
    obj[0x41] = mode;
    obj[0x43] = anim;
    func_003C29B0(obj);
    obj[0x60] &= ~2;
    *(f32 *)(obj + 0x48) = 1.0f;
    *(f32 *)(obj + 0x44) = 0.0f;
    *(f32 *)(obj + 0x4C) = 1.0f / (f32)frames;
    obj[0x6C] = (*(Model_00444F38 **)(obj + 0x24))->entries[anim][0x11];
    if (flags & 16) obj[0x7E] |= 4;
    else obj[0x7E] &= ~4;
}
/* localdecomp:end func_L01_00444F38 */
