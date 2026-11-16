/* PAL near miss (Codex wave 7): near miss: 43 words differ with the file's flags.
 * Worker's note: 43 diff in build/codex/w349/logs/func_L01_00507268.wrap2.log; blocked by file void func_L01_005003D0(s32,s32): retail +0x98 tests v0; needs s32 return correction; retained draft omits unavailable result predicate; no signature cast
 */
#include "common.h"
/* localdecomp:start func_L01_00507268 */
typedef struct {
    u8 p0[0x160]; f32 f160; u8 p164[0x1B4-0x164]; f32 f1B4;
    u8 p1B8[0xE78-0x1B8]; s32 fE78; u8 pE7C[8]; s32 fE84;
    u8 pE88[0x25E9-0xE88]; u8 b25E9; u8 p25EA; u8 b25EB;
    u8 p25EC[0x2830-0x25EC]; s32 f2830, f2834; u8 p2838[0x3C]; s16 h2874;
} Hero_00507268;
typedef struct {u8 pad[0x24];s32 handle;u8 tail[0xF0-0x28];} Row_00507268;
extern T_503930 D_L01_002C5600[];
extern u8 D_001425C0[];
s32 func_L01_00507268(void) {
    extern s32 func_L01_004E9238(s32);
    extern void func_L01_004EAA80(s32);
    extern void func_L01_005003D0(s32,s32);
    extern void func_003C4BB0(void *,f32);
    extern void func_L01_0050FB40(s32,s32,f32);
    Hero_00507268 *hero=(Hero_00507268 *)D_001A4BE0;
    s32 item, handle;
    if(!hero->b25E9) return 0;
    if(!hero->b25EB) return 0;
    if(hero->h2874) return 0;
    item=func_L01_004E9238(0);
    if(item!=hero->f2834) {func_L01_004EAA80(item);return 0;}
    handle=((Row_00507268 *)D_L01_002C5600)[D_001425C0[item]].handle;
    /* The file declares this void; retail tests its return value here. */
    func_L01_005003D0(0,0);
    func_003C4BB0(&hero->f160,0.030000001f);
    if(0.030000001f<hero->f1B4) hero->f1B4=0.030000001f;
    func_L01_0050FB40(handle,0,9.0f);
    if(hero->fE78) hero->fE84=1;
    hero->f2830=handle;
    return 1;
}
/* localdecomp:end func_L01_00507268 */
