/* NTSC-U draft (Codex wave 3): C of func_L39_00600B30, the NTSC-U twin of func_L39_00603230, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 61 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_00600B30", whose code is not the PAL one).
 * Worker's note: 61 diff; best log func_L39_00600B30.check5.log; s16-index trial adds non-retail sign extension; full s32-index candidate 68 diff check10 log retained as .full-index.near.c; product CSE across call versus retail recompute, float load schedule and div nops ...
 */
#include "common.h"

/* localdecomp:start func_L39_00600B30 */
typedef struct { u8 data[0x230]; } Slot_00600B30;
extern s32 *D_L39_002412A0;
__asm__(".extern D_L39_002412A0, 16");
extern f32 D_L39_002412C0[];
extern f32 D_L39_002412C0_00600B30;
__asm__(".extern D_L39_002412C0_00600B30, 16");
extern f32 D_L39_002412D0[];
extern f32 D_L39_002412D0_00600B30;
__asm__(".extern D_L39_002412D0_00600B30, 16");
extern void *func_00120D28(void *, void *, s32);
extern void func_L39_005FFF20(void *, s32, s32, f32, f32);
void func_L39_00600B30(u8 *self, s16 index, void *text, s32 alpha) {
    f32 x=255.0f;
    f32 y=135.0f;
    s32 a=180;
    s32 enabled;
    s32 n;
    if (alpha!=-1) a=alpha;
    func_00120D28((u8 *)&((Slot_00600B30 *)self)[index]+0x4668,text,254);
    enabled=1;
    n=D_L39_002412A0[0];
    if (n>=2) {
        n--;
        x=(s32)((x/D_L39_002412C0_00600B30)*D_L39_002412C0[n]);
        y=(s32)((y/D_L39_002412D0_00600B30)*D_L39_002412D0[n]);
        enabled=0;
    }
    func_L39_005FFF20(self+(index*0x230+0x45E0),enabled,a,x,y);
}
/* localdecomp:end func_L39_00600B30 */
