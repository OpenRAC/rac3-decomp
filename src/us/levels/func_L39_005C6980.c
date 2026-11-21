#include "common.h"

/* NTSC-U counterpart of func_L39_005C8CA8 (src/levels/shared/L39_005C8CA8.c): 0.000496 -> 0.000344444 */
/* localdecomp:start func_L39_005C6980 */
/* from rac2-decomp's func_002BDBC0 (via the draft in nonmatching/levels) */
typedef int Q_005C8CA8 __attribute__((mode(TI)));
extern void *func_003C7B98(s32);
extern s32 func_0019D650(void);
extern u8 *D_L39_00296970[];

void func_L39_005C6980(void *pos, void *dir, s32 color, s32 flags, s32 frames, f32 size) {
    u8 *e;
    u8 *p;
    f32 d;

    e = func_003C7B98(0x16);
    if (e != 0) {
        *(s32 *)(e + 4) = color;
        *(f32 *)(e + 0xC) = size * 0.2f;
        e[1] = 0;
        e[9] = 0x74;
        e[3] = 0x44;
        e[8] = func_0019D650();
        p = e + 0x20;
        e[2] = *D_L39_00296970[0];
        *(s16 *)(e + 0xA) = frames;
        *(s16 *)(p + 0x18) = frames;
        d = size - *(f32 *)(e + 0xC);
        *(s32 *)(p + 0x10) = color;
        *(s32 *)(p + 0x14) = flags;
        *(f32 *)(p + 0x1C) = d / (f32)frames;
        *(Q_005C8CA8 *)p = *(Q_005C8CA8 *)dir;
        *(Q_005C8CA8 *)(e + 0x10) = *(Q_005C8CA8 *)pos;
        *(f32 *)(p + 0xC) = 0.000344444445f;
    }
}
/* localdecomp:end func_L39_005C6980 */
