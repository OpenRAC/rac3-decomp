#include "common.h"

/* localdecomp:start func_L39_005E8108 */
typedef struct O_005E8108 {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    f32 a20[4];
    u8 pad30[0x20];
    f32 f50;
    f32 f54;
    u8 pad58[0x44];
    s32 f9C;
    u8 padA0[0xC];
    f32 fAC;
} O_005E8108;

extern s32 func_003B9E90(u8 *);
extern void func_L01_00484A80(s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern void func_003E8E18_005E8108(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00498938(s32, s32);
extern s32 func_003B9E50(void *, s32, s32);
extern s32 func_L39_005E7FF8(void *, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8348(s32, s32);

void func_L39_005E8108(O_005E8108 *o) {
    s32 i;
    s32 j;

    func_003B9E90((u8 *)o);
    func_L01_00484A80(0x4F00A8);
    func_L01_00517538(0x4F00A8, 0.5f, 0.5f);
    func_003E8E18_005E8108(0x4F00A8, 1);
    func_L01_00516AA0(0x4F00A8, 0x2000, 1);
    func_L01_00484A80(0x4F00AE);
    func_003E8630(0x4F00A8, 0x4F00AE);
    func_L01_00516AA0(0x4F00AE, 0x2000, 1);
    for (i = 0; i < o->f14; i++) {
        func_L01_00484A80(func_L01_00498938((s32)o, i));
        func_003E8630(0x4F00A8, func_L01_00498938((s32)o, i));
        for (j = 0; j < o->f10 + 2; j++) {
            func_003E8FE8(func_003B9E50(o, i, j), func_L39_005E7FF8(o, i, j), 0x8066CCFF, o->a20[i],
                          o->f50 + (f32)j * o->f54, o->fAC, o->fAC);
            func_L01_00516AA0(func_003B9E50(o, i, j), 0x2000, 1);
            func_003E7AC8(func_003B9E50(o, i, j), 1);
            func_003E8630(func_L01_00498938((s32)o, i), func_003B9E50(o, i, j));
        }
    }
    o->f9C = 0;
    func_003E9138(0x4F00AF, 0x706EC8FF, 0, 0.5f, 0.5f, 1.0f, 0.1f);
    func_003E8630(0x4F00AE, 0x4F00AF);
    func_L01_00516AA0(0x4F00AF, 0x2000, 1);
    func_003E8348(o->f18, 0x4F00A8);
}
/* localdecomp:end func_L39_005E8108 */
