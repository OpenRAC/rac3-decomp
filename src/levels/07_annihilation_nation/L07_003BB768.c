#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;

/* localdecomp:start func_L07_003BB768 */
s32 func_00382498(s32, s32);
void func_L07_003A2380(s32, s32, s32, s32);

void func_L07_003BB768(s32 arg0) {
    func_L07_003A2380(func_00382498(0x62, 0x69) & 0xFF, arg0, 0, 0x64);
}
/* localdecomp:end func_L07_003BB768 */

/* localdecomp:start func_L07_003BB7A8 */
s32 func_00382468(s32);
void func_L07_003A2380(s32, s32, s32, s32);

void func_L07_003BB7A8(void *arg0) {
    S_003BB7A8 *st = *(S_003BB7A8 **)((u8 *)arg0 + 0x68);

    if (func_00382468(2) != 0) {
        if (st->flags & 0x10) {
            return;
        }
        ((long (*)(s32, s32, s32, s32))func_L07_003A2380)(0x41, (s32)arg0, 0, 0x64);
        st->flags |= 0x10;
    } else {
        if (st->flags & 0x20) {
            return;
        }
        ((long (*)(s32, s32, s32, s32))func_L07_003A2380)(0x42, (s32)arg0, 0, 0x64);
        st->flags |= 0x20;
    }
}
/* localdecomp:end func_L07_003BB7A8 */

/* localdecomp:start func_L07_003BB840 */
/* Adapted from the repository's NTSC-U counterpart func_L07_003B9F50. */
typedef struct Hero_3BB840 {
    u8 pad0[0x2808];
    u8 *target;
    u8 pad280C[0x2850 - 0x280C];
    s32 health;
} Hero_3BB840;
extern Hero_3BB840 D_001A4BE0;
extern s32 D_00142660[];
__asm__(".extern D_00142660, 16");
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
/* Preserve the queue function's real return type without changing earlier callers. */
extern s32 func_L07_003A2380_003BB840(s32, s32, s32, s32) __asm__("func_L07_003A2380");

void func_L07_003BB840(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *target;

    if ((D_00142660[2] >> 3) >= D_001A4BE0.health) {
        switch (func_00382468(3)) {
        case 0:
            if (!(*(u16 *)(vars + 0xA4) & 0x40)) {
                func_L07_003A2380_003BB840(0x59, (s32)obj, 0, 0x64);
                *(u16 *)(vars + 0xA4) |= 0x40;
                return;
            }
        case 1:
            if (!(*(u16 *)(vars + 0xA4) & 0x80)) {
                func_L07_003A2380_003BB840(0x5A, (s32)obj, 0, 0x64);
                *(u16 *)(vars + 0xA4) |= 0x80;
                return;
            }
            break;
        }
    }
    if ((D_00142660[2] >> 2) >= D_001A4BE0.health) {
        switch (func_00382468(3)) {
        case 0:
            if (!(*(u16 *)(vars + 0xA4) & 0x100)) {
                func_L07_003A2380_003BB840(0x57, (s32)obj, 0, 0x64);
                *(u16 *)(vars + 0xA4) |= 0x100;
                return;
            }
        case 1:
            if (!(*(u16 *)(vars + 0xA4) & 0x200)) {
                func_L07_003A2380_003BB840(0x58, (s32)obj, 0, 0x64);
                *(u16 *)(vars + 0xA4) |= 0x200;
                return;
            }
            break;
        }
    }
    target = D_001A4BE0.target;
    if (target != 0) {
        switch (*(s16 *)(target + 0xAA)) {
        case 0x197E:
            if (func_00382468(5) == 0) {
                func_L07_003A2380_003BB840(0x5B, (s32)obj, 0, 0x64);
                return;
            }
        case 0x1A85:
        case 0x1ADB:
        case 0x1B36:
        case 0x1D88:
        case 0x1D89:
        case 0x1D8B:
            func_L07_003A2380_003BB840((u8)func_00382498(0x54, 0x56), (s32)obj, 0, 0x64);
            return;
        }
    }
    func_L07_003A2380_003BB840((u8)func_00382498(0x52, 0x53), (s32)obj, 0, 0x64);
}
/* localdecomp:end func_L07_003BB840 */

/* localdecomp:start func_L07_003BBAC8 */
extern u8 D_L07_001DE4F8;
__asm__(".extern D_L07_001DE4F8, 4");
s32 func_L07_003BBAC8(s16 mask) {
    s32 func_00382468(s32);
    s32 i;
    for (i = 0; i < 16; i++) {
        if ((mask >> i) & 1) {
            switch ((&D_L07_001DE4F8)[i]) {
            case 5: return func_00382468(2) ? 1 : 4;
            case 6: return func_00382468(2) ? 3 : 4;
            case 8: return func_00382468(2) ? 1 : 10;
            case 9: return func_00382468(2) ? 3 : 10;
            case 11: break;
            default: return (&D_L07_001DE4F8)[i];
            }
        }
    }
    return 255;
}
/* localdecomp:end func_L07_003BBAC8 */
