/* PAL near miss (Codex wave 10): near miss: 3 words differ with the file's flags.
 * Worker's note: 3 differing words/95, zero size delta: func_L01_004E2C48.baseline.log and .ordinary.log; type compilation exit 0 (.type.log). Existing earlier void func_L01_004E27A0(void) prevents retail a0 attachment/a1 moby call. Context needs two pointer arguments for ...
 */
#include "common.h"
/* localdecomp:start func_L01_004E2C48 */
typedef struct {
    u8 pad0[0x1B8]; s32 timer;
    u8 pad1BC[0x1200-0x1BC]; u8 *attachment;
    u8 pad1204[0x1228-0x1204]; s32 weapon;
    u8 pad122C[0x25C0-0x122C]; u8 *moby; s32 state;
    u8 pad25C8[0x2818-0x25C8]; unsigned long saved_color; s32 flashing;
} Hero_004E2C48;
typedef struct { u8 b0; u8 active; u8 pad2[0xF0-2]; } Gun_004E2C48;
extern G_4DD4B0 D_001A4BE0;
void func_L01_004E2C48(void) {
    extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);
    extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
    extern void func_L01_004E2720(void);
    extern void func_L01_004E27A0(void);
    s32 r,g,b;
    s32 flash=0;
    if ((*(Hero_004E2C48 *)&D_001A4BE0).state==0x82 || (*(Hero_004E2C48 *)&D_001A4BE0).state==0xB1 || (*(Hero_004E2C48 *)&D_001A4BE0).state==0x84) flash=(*(Hero_004E2C48 *)&D_001A4BE0).timer<25;
    if(flash) {
        if(!(*(Hero_004E2C48 *)&D_001A4BE0).flashing) {
            (*(Hero_004E2C48 *)&D_001A4BE0).saved_color=*(unsigned long *)((*(Hero_004E2C48 *)&D_001A4BE0).moby+0x38);
            (*(Hero_004E2C48 *)&D_001A4BE0).flashing=1;
        }
        func_003C6FB0((*(Hero_004E2C48 *)&D_001A4BE0).moby,&r,&g,&b);
        if((*(Hero_004E2C48 *)&D_001A4BE0).timer%4<3) { r=0;g=0;b=0; }
        else { r=0x90;g=0x90;b=0xF0; }
        func_L01_0043B9E8((*(Hero_004E2C48 *)&D_001A4BE0).moby,r,g,b);
        func_L01_004E2720();
    } else if((*(Hero_004E2C48 *)&D_001A4BE0).flashing) {
        *(unsigned long *)((*(Hero_004E2C48 *)&D_001A4BE0).moby+0x38)=(*(Hero_004E2C48 *)&D_001A4BE0).saved_color;
        (*(Hero_004E2C48 *)&D_001A4BE0).flashing=0;
    }
    if((*(Hero_004E2C48 *)&D_001A4BE0).weapon>=0 && ((Gun_004E2C48 *)D_L01_002C5600)[D_001425C0[(*(Hero_004E2C48 *)&D_001A4BE0).weapon]].active && (*(Hero_004E2C48 *)&D_001A4BE0).attachment) {
        func_L01_004E27A0();
    }
}
/* localdecomp:end func_L01_004E2C48 */
