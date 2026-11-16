/* PAL near miss (Codex wave 6): near miss: 146 words differ with the file's flags.
 * Worker's note: 151 instruction diff; best log build/codex/w291/func_003BD3E8.03.log; three distinct C wordings produce identical .text (stagnation.log); full declaration contract conflicts: later void declaration versus retail s32 return (contract-fail.log)
 */
#include "common.h"
/* localdecomp:start func_003BD3E8 */
#include "vu0.h"
typedef struct { s16 from, to; s32 row, arg0, arg1; } Rule_003BD3E8;
typedef struct {
    u32 value;
    void (*init)(s32,s32);
    s32 (*step)();
    void (*event)(s32);
    void (*render)(void);
    void (*finish)(void);
} Callbacks_003BD3E8;
typedef struct {
    u8 pad[0x20]; s16 mode, index;
    u8 pad24[8]; s16 zero, value;
    u8 pad30[0x34]; s32 slot;
} State_003BD3E8;
extern Rule_003BD3E8 D_0037FCB8[];
extern Callbacks_003BD3E8 D_0037FBE0[];
extern State_003BD3E8 D_0016C580;
extern s32 D_001D8CC8, D_001D8CCC;
extern s32 D_001D6E90, D_001D4B48;
extern void (*D_001D8CC4)(void);
extern void (*D_001D8CB4)(s32,s32);
extern s32 D_001D8CE8, D_001D8CEC;
extern u8 D_00225900[];
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern vu0_v4 D_00222650;
extern u8 D_002D2100[];
__asm__(".extern D_001D8CC8, 4");
__asm__(".extern D_001D8CCC, 4");
__asm__(".extern D_001D8CB4, 4");
__asm__(".extern D_001D8CC0, 4");
__asm__(".extern D_001D8CE8, 4");
__asm__(".extern D_001D8CEC, 4");
s32 func_003BD3E8(void) {
    extern void func_0038CF58();
    extern void func_003C3140();
    extern void func_11F0A0(s32);
    extern void func_13CF80(s32,s32,s32,s32,s32);
    extern void func_0013CA28(void);
    extern s32 func_0013B620(void);
    extern void func_003A5830(void);
    extern void func_003A2028(void);
    extern void func_0013BF00(s32);
    extern void func_0013BED0(void);
    extern void func_003BCEB0(void);
    extern void func_00392640(s32,long,long);
    extern void func_0013D310(s32,void *);
    extern void func_003BE478(void);
    extern void func_003BD338(void);
    Rule_003BD3E8 *rule;
    Callbacks_003BD3E8 *cb;
    s32 *handles;
    s32 i, from, to, index;
    u8 *display;
    func_0038CF58(D_00227480,-1,128);
    D_001D5B94=6;
    D_00227640.f10|=0x80000000;
    func_003C3140();
    func_11F0A0(0);
    func_13CF80(2,0,0,0,0);
    func_0013CA28();
    func_0013B620();
    func_003A5830();
    func_003A2028();
    D_001CCFD0[0].f7=1;
    handles=(s32 *)((u8 *)&D_001A30B0+0x90);
    for(i=5;i>=0;i--,handles++) {
        if(*handles) {
            func_0013BF00(*handles);
            func_0013BED0();
            D_001D9D2C=0;
            *handles=0;
        }
    }
    from=D_001D545C;
    to=D_001D9D04;
    D_0016C580.mode=2;
    D_0016C580.slot=-1;
    D_0016C580.index=-1;
    D_0016C580.value=-1;
    D_0016C580.zero=0;
    D_001D6E90=0;
    D_001D8CE8=from;
    D_001D8CEC=to;
    rule=D_0037FCB8;
    i=0;
    do {
        if(rule->from==-1 && rule->to==to) break;
        if(rule->from==from && (rule->to==-1 || rule->to==to)) break;
        i++;
        rule++;
    } while(i<51);
    D_001D8CCC=0;
    D_001D8CC8=0;
    index=8;
    if(i<51) {
        D_001D8CCC=rule->arg1;
        D_001D8CC8=rule->arg0;
        index=rule->row;
    }
    cb=&D_0037FBE0[index];
    D_001D8CC0=func_003BCEB0;
    D_001D8CB4=0;
    D_001D8CB8=0;
    D_001D8CBC=0;
    D_001D8CC4=0;
    if(cb->init) D_001D8CB4=cb->init;
    if(cb->step) D_001D8CB8=cb->step;
    if(cb->event) D_001D8CBC=cb->event;
    if(cb->render) D_001D8CC0=cb->render;
    if(cb->finish) D_001D8CC4=cb->finish;
    display=D_00225900;
    *(s32 *)(display+0x258)=16;
    *(s32 *)(display+0x250)=0;
    *(s32 *)(display+0x254)=0;
    *(s32 *)(display+0x228)=0;
    { u32 value=cb->value; D_0016C580.value=value; }
    D_001D9C46=display[0x258];
    D_001D9C48=*(f32 *)(display+0x228);
    D_001D9C50=255.0f;
    D_001D9C54=128.0f;
    D_001D9C44=display[0x250];
    D_001D9C45=display[0x254];
    (&D_001D9C48)[1]=524288.0f;
    *(f32 *)(display+0x238)=255.0f;
    *(f32 *)(display+0x23C)=128.0f;
    *(f32 *)(display+0x22C)=524288.0f;
    func_00392640(0,0,0);
    D_00227640.f10|=0x80000000;
    qzero(&D_00222650);
    D_00222650.z=-1.0f;
    D_001D4B4C[0]=1;
    D_001D545C=D_001D9D04;
    D_001D4B48=0;
    func_0013D310(D_001D9D04,D_002D2100);
    func_003BE478();
    func_003BD338();
    if(D_001D8CB4) D_001D8CB4(D_001D8CC8,D_001D8CCC);
    return 1;
}
/* localdecomp:end func_003BD3E8 */
