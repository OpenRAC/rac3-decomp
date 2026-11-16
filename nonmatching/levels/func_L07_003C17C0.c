/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: 3 diff: build/codex/w400/func_L07_003C17C0.05.log and func_L07_003C17C0.contract.log; prologue counter zero store precedes s3 save/load. Three formulations same bytes. Exact callee type W_003C19C8 currently declared after target: Claude must move its existing ...
 */
#include "common.h"
/* localdecomp:start func_L07_003C17C0 */
extern E_003C0ED8 D_L07_002BC920[];
extern u8 D_001426E0[];
extern u8 D_L07_001DE590[];
extern u8 D_L07_001E1708_003C0D48 __asm__("D_L07_001E1708") __attribute__((section(".data")));
extern u8 D_L07_001E1710_003C0D48 __asm__("D_L07_001E1710") __attribute__((section(".data")));
void func_L07_003C17C0(void *obj) {
    extern void func_L07_003C19C8(W_003C19C8 *,s32,s32 *,s32);
    extern s32 func_L07_003C1B88(s32);
    extern s32 func_L07_003C1C08(s32);
    extern s32 func_L07_003C1360(s32);
    extern s32 func_00381FF0(s32);
    extern void func_L01_00516FD8(s32,void *);
    extern s32 func_0011B2E8(void *,void *,...);
    extern void func_L07_00334878(s32,s32 *,s32 *,s32 *);
    extern void func_L01_00516AA0(s32,s32,s32);
    extern void func_L01_00517190(s32,s32);
    s32 costs[3];
    s32 counter=0;
    u8 *d;
    u8 *e;
    s32 id,slot,i;
    s32 *p;
    d=((W_003C19C8 *)obj)->p68;
    func_L07_003C19C8((W_003C19C8 *)obj,*(s32 *)(d+0x24),&counter,0x8066ccff);
    func_L07_003C19C8((W_003C19C8 *)obj,*(s32 *)(d+0x20),&counter,0x80808080);
    e=(u8 *)&D_L07_002BC920[d[0x38]];
    id=func_L07_003C1B88(d[0x38]);
    if(id==-1) func_L01_00516FD8(0x47000f,(void *)func_00381FF0(*(s32 *)(e+0x14)));
    else func_L01_00516FD8(0x47000f,(void *)func_00381FF0(id));
    id=func_L07_003C1C08(d[0x38]);
    if(id==-1) func_L01_00516FD8(0x470012,(void *)func_00381FF0(*(s32 *)(e+0x18)));
    else func_L01_00516FD8(0x470012,(void *)func_00381FF0(id));
    func_0011B2E8(&D_L07_001E1708_003C0D48,D_L07_001DE590,D_001426E0[d[0x38]+0x8e]);
    func_0011B2E8(&D_L07_001E1710_003C0D48,D_L07_001DE590,func_L07_003C1360(d[0x38]));
    if(e[0]==0) func_L07_00334878(*(s16 *)(e+2),&costs[0],&costs[1],&costs[2]);
    else { costs[2]=0;costs[1]=0;costs[0]=0; }
    slot=0x470014;
    p=costs;
    i=2;
    do {
        if(*p==0) func_L01_00516AA0(slot,1,0);
        else {
            func_L01_00516AA0(slot,1,1);
            func_L01_00517190(slot,*p);
        }
        slot++;p++;i--;
    } while(i>=0);
    func_L01_00517190(0x47001c,d[0x38]+10);
}
/* localdecomp:end func_L07_003C17C0 */
