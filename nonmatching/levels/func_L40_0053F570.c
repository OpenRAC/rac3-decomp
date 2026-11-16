/* NTSC-U draft (Codex wave 3): C of func_L40_0053CCC0, the NTSC-U twin of func_L40_0053F570, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 56 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L40_0053CCC0", whose code is not the PAL one).
 * Worker's note: 56 diff after 10 native checks (improved from 60); s1/s2 allocation, repeated table-address copies and store scheduling remain; tried store permutations, table wrapper, entry pointer/index form and nested error checks; retained best SHA256 ...
 */
#include "common.h"
/* localdecomp:start func_L40_0053CCC0 */
typedef struct {
    s32 value;
    u8 pad04[0x10];
    void *callback;
    s32 unused18;
    u8 *moby;
    s32 time,unused24,a,b;
    u8 kind,state;
    u8 pad32[6];
    s32 zero,value2,time2;
} Entry_53CCC0;
typedef struct { s32 unused,a,b,c; } Params_53CCC0;
extern s32 func_L40_0053CBE8(void),func_L39_00669B20(s32);
extern u8 *func_003BCFB0(s32,s32);
extern u8 *D_001DCD4C_sda;
extern u8 *D_L40_002485DC[];
extern s32 func_L40_0053CC58(void *);
extern Entry_53CCC0 D_L40_0033F460[];
extern Params_53CCC0 D_L40_003401B0[];
extern u8 D_L40_002463D0[];
extern s32 D_001A5F78[];
extern void func_L39_0067CF88(void);
u8 *func_L40_0053CCC0(s32 type,s32 value,s32 value2,s32 kind,u8 *obj) {
    s32 i,j;
    Entry_53CCC0 *entry;
    i=func_L40_0053CBE8();
    if(i<0) return 0;
    j=func_L39_00669B20(type);
    if(j<0) return 0;
    if((s32)obj==-1) {
        obj=func_003BCFB0(type,0x400);
        if(!obj) return 0;
    } else {
        obj=(u8 *)((s32)obj<<8);
        func_L40_0053CC58(D_001DCD4C_sda+(s32)obj);
        obj=(s32)obj+D_L40_002485DC[0];
        obj[0x20]=0;
    }
    entry = D_L40_0033F460 + i;
    entry->callback=D_L40_002463D0;
    entry->kind=kind;
    D_L40_0033F460[i].moby=obj;
    entry->state=1;
    D_L40_0033F460[i].time=D_001A5F78[0];
    D_L40_0033F460[i].a=D_L40_003401B0[j].a;
    entry->value=value;
    D_L40_0033F460[i].b=D_L40_003401B0[j].b;
    D_L40_0033F460[i].value2=value2;
    D_L40_0033F460[i].time2=D_001A5F78[0];
    D_L40_0033F460[i].zero=0;
    *(Entry_53CCC0 **)(obj+0x90)=entry;
    func_L39_0067CF88();
    return obj;
}
/* localdecomp:end func_L40_0053CCC0 */
