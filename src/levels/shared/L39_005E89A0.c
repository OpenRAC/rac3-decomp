#include "common.h"

/* localdecomp:start func_L39_005E89A0 */
extern u8 *func_L39_005E7FF8(u8 *a0, s32 a1, s32 a2);
extern s32 func_L39_005F3548(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern void func_003BB590(s32);
typedef struct { u8 p0[4]; s32 f4; s32 f8; s32 fC; s32 f10; u8 p14[8]; s32 f1C; u8 p20[0x30]; f32 f50; f32 f54; u8 p58[4]; f32 f5C; u8 p60[0x18]; f32 f78; } O_005E89A0;
void func_L39_005E89A0(O_005E89A0 *o, s32 buttons) {
    f32 base = o->f50;
    f32 scale = o->f54;
    if (buttons & 0x1000) {
        s32 a = o->f4 + o->f8;
        if (a > 0) {
            s32 b = a - 1;
            while (b > 0 && *(s32 *)(func_L39_005E7FF8((u8 *)o, 0, b) + 0x20) == 4) b--;
            if (*(s32 *)(func_L39_005E7FF8((u8 *)o, 0, b) + 0x20) != 4) {
                if (o->f8 + 1 >= a - b) {
                    o->f8 = b - o->f4;
                } else {
                    o->f4 += 1 - ((a - b) - o->f8);
                    o->f8 = -1;
                }
            }
        }
        func_L39_005F3548(3, 0, 0);
        if (o->f8 < 0) {
            o->f8 = 0;
            if (o->f4 - 1 >= 0) o->f1C = 2;
        }
    } else if (buttons & 0x4000) {
        s32 c = o->f4 + o->f8;
        if (c < o->fC - 1) {
            s32 b = c + 1;
            while (b < o->fC - 1 && *(s32 *)(func_L39_005E7FF8((u8 *)o, 0, b) + 0x20) == 4) b++;
            if (*(s32 *)(func_L39_005E7FF8((u8 *)o, 0, b) + 0x20) != 4) {
                if (o->f10 - o->f8 >= b - c) {
                    o->f8 = b - o->f4;
                } else {
                    o->f8 = o->f10;
                    o->f4 = b - o->f10;
                }
            }
        }
        func_L39_005F3548(3, 0, 0);
        if (o->f10 - 1 < o->f8) {
            o->f8 = o->f10 - 1;
            if (o->f4 + 1 <= o->fC - o->f10) o->f1C = 1;
        }
    }
    func_L01_00516470(0x4F00AF, o->f5C, base + (f32)o->f8 * scale - o->f78);
    func_003BB590(0x4F00AF);
}
/* localdecomp:end func_L39_005E89A0 */
