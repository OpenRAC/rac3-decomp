#include "common.h"

/* NTSC-U counterpart of func_003A7CB8 (src/boot_elf/text/3A6C90.c): func_U_0038A5C0(6); the last frame loop waits on D_00142430 instead of running once */
/* localdecomp:start func_U_003A7B40 */
extern s32 D_U_001D9D84;
extern s32 D_001D4B48;
extern s32 D_U_001D9DAC;
extern s32 D_001D545C;
extern u8 D_001CCFD0_003A7B40[];
extern u8 D_U_00225980[];
extern u8 D_U_002D2180[];
typedef struct { u8 pad[0x90]; s32 slot[6]; } S_003A7B40;
extern S_003A7B40 D_001A30B0_003A7B40;
__asm__(".extern D_001A30B0_003A7B40, 16");

extern u8 D_U_001D9CC4, D_U_001D9CC5, D_U_001D9CC6;
extern f32 D_U_001D9CC8, D_U_001D9CCC, D_U_001D9CD0, D_U_001D9CD4;
extern s32 func_U_003BD798(void);
extern void func_U_0038A5C0(s32);
extern void func_11F0A0(s32);
extern void func_13CF80(s32,s32,s32,s32,s32);
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_U_003A56F0(void);
extern void func_U_003A1EE8(void);
extern void func_0013BF00(s32);
extern void func_0013BED0(void);
extern void func_U_00392580(s32,long,long);
extern void func_0013D310(s32,void *);
extern s32 func_12C908(s32);
extern void func_U_0039C6D8();
extern void func_U_0039B0A8(void);
extern s32 func_U_0039A4A8(void);
extern void func_0013CF40(s32);
extern long func_13CDF0_003A7B40(s32);
extern void func_U_003A9D40(void);
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_003A7B40;
extern S_142430_003A7B40 D_00142430_003A7B40;
void func_U_003A7B40(void)
{
    s32 i;
    u8 *settings;
    if (func_U_003BD798()) return;
    func_U_0038A5C0(6);
    D_001D4B48=0;
    D_001D545C=D_U_001D9D84;
    func_11F0A0(0);
    func_13CF80(2,0,0,0,0);
    func_13CA28();
    func_13B620();
    func_U_003A56F0();
    func_U_003A1EE8();
    D_001CCFD0_003A7B40[7]=1;
    for(i=0;i<6;i++) {
        if (D_001A30B0_003A7B40.slot[i]) {
            func_0013BF00(D_001A30B0_003A7B40.slot[i]);
            func_0013BED0();
            D_U_001D9DAC=0;
            D_001A30B0_003A7B40.slot[i]=0;
        }
    }
    settings=D_U_00225980;
    *(s32 *)(settings+0x258)=16;
    *(s32 *)(settings+0x250)=0;
    *(s32 *)(settings+0x254)=0;
    *(s32 *)(settings+0x228)=0;
    *(f32 *)(settings+0x22c)=524288.0f;
    *(f32 *)(settings+0x238)=255.0f;
    *(f32 *)(settings+0x23c)=128.0f;
    D_U_001D9CC4=settings[0x250];
    D_U_001D9CC5=settings[0x254];
    D_U_001D9CC6=settings[0x258];
    D_U_001D9CC8=*(f32 *)(settings+0x228);
    D_U_001D9CCC=524288.0f;
    D_U_001D9CD0=255.0f;
    D_U_001D9CD4=128.0f;
    func_U_00392580(0,0,0);
    func_0013D310(D_001D545C,D_U_002D2180);
    D_001CCFD0_003A7B40[7]=1;
    do {
        func_11F0A0(0);
        func_12C908(0);
        func_U_0039C6D8();
        func_U_0039B0A8();
    } while(!func_U_0039A4A8());
    while (D_00142430_003A7B40.f15C != 2 || D_00142430_003A7B40.f164 >= 0) {
        func_11F0A0(0);
        func_12C908(0);
        func_U_0039C6D8();
        func_U_0039B0A8();
    }
    while(func_13B620()) {}
    func_0013BED0();
    func_0013CF40(0);
    func_13CDF0_003A7B40(0);
    func_13CDF0_003A7B40(0);
    D_001CCFD0_003A7B40[7]=0;
    func_U_003A9D40();
}
/* localdecomp:end func_U_003A7B40 */
