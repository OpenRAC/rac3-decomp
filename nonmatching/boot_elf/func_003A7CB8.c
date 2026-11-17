/* PAL near miss (Codex wave 10): near miss: 84 words differ with the file's flags.
 * Worker's note: build/codex/w511/func_003A7CB8-02.log: 95 positional differences; 564 versus 572 bytes; table base+0x90 address folding and fog scalar scheduling; attempts 02/07/08 identical checker output; fixed flags; no metadata
 */
#include "common.h"
/* localdecomp:start func_003A7CB8 */
extern s32 D_001D9D04;
extern s32 D_001D4B48;
extern s32 D_001D9D2C;
extern u8 D_001CCFD0_003A7CB8[];
extern u8 D_00225900_003A7CB8[];
extern u8 D_002D2100[];
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
void func_003A7CB8(void)
{
    extern s32 func_003BD870(void);
    extern void func_0038A618(s32);
    extern void func_11F0A0(s32);
    extern void func_13CF80(s32,s32,s32,s32,s32);
    extern void func_13CA28(void);
    extern s32 func_13B620(void);
    extern void func_003A5830(void);
    extern void func_003A2028(void);
    extern void func_0013BF00(s32);
    extern void func_0013BED0(void);
    extern void func_00392640(s32,long,long);
    extern void func_0013D310(s32,void *);
    extern s32 func_12C908(s32);
    extern void func_0039C7F0();
    extern void func_0039B1C0(void);
    extern s32 func_0039A5C0(void);
    extern void func_0013CF40(s32);
    extern long func_13CDF0_003A7A18(s32);
    extern void func_003A9E88(void);
    s32 i;
    s32 *slot;
    u8 *settings;
    if (func_003BD870()) return;
    func_0038A618(5);
    D_001D4B48=0;
    D_001D545C_003A6C90=D_001D9D04;
    func_11F0A0(0);
    func_13CF80(2,0,0,0,0);
    func_13CA28();
    func_13B620();
    func_003A5830();
    func_003A2028();
    D_001CCFD0_003A7CB8[7]=1;
    slot=(s32 *)(D_001A30B0+0x90);
    for(i=5;i>=0;i--,slot++) {
        if (*slot) {
            func_0013BF00(*slot);
            func_0013BED0();
            D_001D9D2C=0;
            *slot=0;
        }
    }
    settings=D_00225900_003A7CB8;
    *(s32 *)(settings+0x258)=16;
    *(s32 *)(settings+0x250)=0;
    *(s32 *)(settings+0x254)=0;
    *(s32 *)(settings+0x228)=0;
    D_001D9C44=settings[0x250];
    D_001D9C45=settings[0x254];
    D_001D9C46=settings[0x258];
    D_001D9C48=*(f32 *)(settings+0x228);
    D_001D9C4C=524288.0f;
    D_001D9C50=255.0f;
    D_001D9C54=128.0f;
    *(f32 *)(settings+0x22c)=524288.0f;
    *(f32 *)(settings+0x238)=255.0f;
    *(f32 *)(settings+0x23c)=128.0f;
    func_00392640(0,0,0);
    func_0013D310(D_001D545C_003A6C90,D_002D2100);
    D_001CCFD0_003A7CB8[7]=1;
    do {
        func_11F0A0(0);
        func_12C908(0);
        func_0039C7F0();
        func_0039B1C0();
    } while(!func_0039A5C0());
    func_11F0A0(0);
    func_12C908(0);
    func_0039C7F0();
    func_0039B1C0();
    while(func_13B620()) {}
    func_0013BED0();
    func_0013CF40(0);
    func_13CDF0_003A7A18(0);
    func_13CDF0_003A7A18(0);
    D_001CCFD0_003A7CB8[7]=0;
    func_003A9E88();
}
/* localdecomp:end func_003A7CB8 */
