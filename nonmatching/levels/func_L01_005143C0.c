/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Context COMPILE ERROR: earlier void func_L01_005143C0(s32) conflicts with retail boolean return; needs s32 return declaration in func_L01_005143A0. Real draft and decoded six-case PAL table retained (005143C0-switch.txt); 005143C0-01.log and ...
 */
#include "common.h"
/* localdecomp:start func_L01_005143C0 */
typedef struct {
    u8 pad0[0x35C];
    u8 *other;
    u8 pad360[0x19E0-0x360];
    u8 *vehicle;
    u8 pad19E4[0x25C4-0x19E4];
    s32 state;
} Hero_005143C0;
extern D_001A4BE0_t D_001A4BE0;
extern s32 D_001D545C;
s32 func_L01_005143C0(s32 kind)
{
    Hero_005143C0 *hero=(Hero_005143C0 *)&D_001A4BE0;
    u8 *vehicle=hero->vehicle;
    u8 *other=hero->other;
    s32 result=0;
    if(hero->state==0x31) {
        if(vehicle!=0) {
            /* PAL table evidence: build/codex/w438/005143C0-switch.txt. */
            switch(kind) {
            case 0: result=*(s16 *)(vehicle+0xAA)==0xFBF; break;
            case 1: result=*(s16 *)(vehicle+0xAA)==0x905; break;
            case 2: result=*(s16 *)(vehicle+0xAA)==0xEEF; break;
            case 3: result=*(s16 *)(vehicle+0xAA)==0x1AD5; break;
            case 4: result=*(s16 *)(vehicle+0xAA)==0x1A17 && D_001D545C==9; break;
            case 5: result=*(s16 *)(vehicle+0xAA)==0x107E; break;
            }
        } else if(other!=0 && kind==3) {
            result=*(s16 *)(other+0xAA)==0xC20;
        }
    }
    return result;
}
/* localdecomp:end func_L01_005143C0 */
