/* PAL near miss (Codex wave 6): near miss: 64 words differ with the file's flags.
 * Worker's note: 64 diff; func_L01_004784C0.try3.log and .final2.log; exact earlier callee func_L01_004783E0(s32,s32,s32,f32) cannot forward retail second float f13; no incompatible prototype used
 */
#include "common.h"
/* localdecomp:start func_L01_004784C0 */
typedef struct {
    u8 kind;
    u8 level;
    u8 pad[0x66];
    s32 xp;
    u8 tail[0xF0-0x6C];
} Row_004784C0;
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern s32 D_00142DE0[];
void func_L01_004784C0(s32 item,s32 display,f32 a,f32 b) {
    extern s32 func_L01_00418DE0(s32,s32);
    extern void func_L01_004783E0(s32,s32,s32,f32);
    u8 *index = D_001425C0+item;
    Row_004784C0 *rows=(Row_004784C0 *)D_L01_002C5600;
    s32 previous;
    s32 level;
    if (rows[*index].xp>0) {
        previous=0;
        if (rows[*index].level) {
            previous=rows[*index].level;
            func_L01_00418DE0(item,previous-1);
            level=previous;
            previous=rows[*index].xp;
            func_L01_00418DE0(item,level);
        }
        func_L01_004783E0(display,(D_00142DE0[item]>>5)-previous,rows[*index].xp-previous,a);
    } else {
        func_L01_004783E0(display,1,1,a);
    }
}
/* localdecomp:end func_L01_004784C0 */
