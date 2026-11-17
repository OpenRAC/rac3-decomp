/* PAL near miss, P01 wave 2 (2026-11-16), reconstructed from retail.
 * File flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock checker: 181 positional differences. Remaining differences include
 * saved-register selection, group-base/index allocation and stack spill slots.
 * Not a full-program match; retain the source INCLUDE_ASM.
 */
#include "common.h"
typedef struct { s32 ids[7]; s32 groups[7]; s32 single[3]; s32 more[3]; s32 doors[8]; void *data; u8 gap[0x4B]; u8 flag; } V_32F988;
extern u8 *D_L07_001DF41C_0032F988;
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458;
extern u8 D_L07_001DD104;
__asm__(".extern D_L07_001DD104, 1");
extern u8 D_001426E0[];
extern s32 D_00142848;
extern s32 *func_L07_00333918(void *);
extern s32 *func_L07_00333B20(u8 *);
extern s32 func_L07_00333B68(void *);
extern void func_L07_003328D0(void *);
extern void func_L07_00332BE0(void *);
extern void func_L01_004450F0(void *,s32,s32);
void func_L07_0032F988(u8 *self) {
    V_32F988 *v=*(V_32F988 **)(self+0x68);
    s32 i, j;
    s32 *q;
    u8 *obj;
    for (i=0;i<7;) {
        s32 next=i+1;
        if ((u32)(i-3)>=2) {
            u16 *p;
            for (p=D_L07_0021C020[v->groups[i]];
                 (v->groups[i]&255)!=255 && v->groups[i]<=D_L07_001DF458 && p;p++) {
                if (((s16 *)p)[-1]<0 && p!=D_L07_0021C020[v->groups[i]]) break;
                obj=D_L07_001DF41C_0032F988+((*p&0x7FFF)<<8);
                if (!obj) break;
                *(s16 *)(obj+0x32)=150;
                obj[0x30]=150;
                *(void **)func_L07_00333918(obj)=self;
                if (i==2 || i==5 || i==6) obj[0x62]=0;
            }
        }
        i=next;
    }
    for(q=v->single,i=2;i>=0;i--) {
        obj=D_L07_001DF41C_0032F988+(*q++<<8);
        *(s16 *)(obj+0x32)=150;
        obj[0x30]=150;
        *(void **)func_L07_00333918(obj)=self;
    }
    for(j=0;j<3;) {
        s32 next=j+1;
        u16 *p;
        for(p=D_L07_0021C020[v->more[j]];
            (v->more[j]&255)!=255 && v->more[j]<=D_L07_001DF458 && p;p++) {
            if (((s16 *)p)[-1]<0 && p!=D_L07_0021C020[v->more[j]]) break;
            obj=D_L07_001DF41C_0032F988+((*p&0x7FFF)<<8);
            if (!obj) break;
            *(s16 *)(obj+0x32)=150;
            obj[0x30]=150;
            *(void **)func_L07_00333B20(obj)=self;
        }
        j=next;
    }
    for(q=v->ids,i=5;i>=0;i--) {
        obj=D_L07_001DF41C_0032F988+(*q++<<8);
        *(s16 *)(obj+0x32)=150;
        obj[0x30]=150;
        *(void **)func_L07_00333B68(obj)=self;
    }
    obj=D_L07_001DF41C_0032F988+(v->ids[6]<<8);
    obj[0x30]=150;
    *(s16 *)(obj+0x32)=150;
    *(void **)func_L07_00333B68(obj)=self;
    for(q=v->doors,i=7;i>=0;i--) {
        obj=D_L07_001DF41C_0032F988+(*q++<<8);
        obj[0x30]=150;
        *(s16 *)(obj+0x32)=150;
    }
    if(D_L07_001DD104) {
        v->flag=1;
        func_L07_003328D0(self);
        D_L07_001DD104=0;
    }
    if(D_001426E0[0xE3]) {
        s32 temp=D_001426E0[0xE3];
        D_001426E0[0xE3]=0;
        D_00142848=temp-1;
    }
    v->data=0;
    func_L07_00332BE0(self);
    *(u16 *)(self+0x34)|=1;
    func_L01_004450F0(self,1,-1);
}
