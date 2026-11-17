/* PAL near miss (Codex wave 10): near miss: 4 words differ with the file's flags.
 * Worker's note: Improved 5 to 4 word diffs; build/codex/w536/func_L01_002FC910.c03.log (retained v3). Remaining +0x338/+0x340/+0x350/+0x358 constant load order/FP allocation; stores match. Ten compiles, fixed flags; five-case PAL table decoded in func_L01_002FC910.switch.txt.
 */
#include "common.h"
/* localdecomp:start func_L01_002FC910 */
typedef struct {
    u8 pad0[0x1B8]; s32 frame;
    u8 pad1BC[0x36E - 0x1BC]; s16 h36E;
    u8 pad370[0x46E - 0x370]; u8 disabled;
    u8 pad46F[0xC18 - 0x46F]; f32 anim;
    u8 padC1C[0x12F0 - 0xC1C]; void *backpack,*clank;
    u8 pad12F8[0x1318 - 0x12F8]; s32 item;
    u8 pad131C[0x25C0 - 0x131C]; u8 *moby;
    s32 state;
    u8 pad25C8[0x2884 - 0x25C8]; s16 suppressed;
} Hero_002FC910;
typedef struct {
    s32 timer,kind; void *owner; s32 active;
    u8 pad10[0x20 - 0x10];
    f32 a,b,c,d,da,db,dc,dd;
} Vars_002FC910;
extern Hero_002FC910 D_001A4BE0_002FC910;
extern u8 *D_001D52FC;
extern u16 D_001A8EA4[];
void func_L01_002FC910(u8 *self)
{
    extern s32 func_L01_004E9238(s32);
    extern s32 func_003A3BB8(s32,s32);
    extern void func_003C2880(void *);
    extern void func_L01_0041A5B0(s32,s32);
    extern void func_L01_002FBCD0(u8 *);
    extern void func_L01_00404A10(void (*)(u8 *),u8 *);
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_002FC3E8(u8 *);
    s32 active=0;
    Vars_002FC910 *v=*(Vars_002FC910 **)(self+0x68);
    if((D_001A4BE0_002FC910.item==3 || func_L01_004E9238(3)==8) && (self[0x20]==1 || self[0x20]==3)) {
        Hero_002FC910 *h=&D_001A4BE0_002FC910;
        if((u32)(h->state-11)<4 || (h->state==27 && h->moby[0x42]==h->moby[0x43] && h->anim>=6.0f && h->anim<=16.0f)) {if(!h->disabled)active=1;}
        if(D_001A4BE0_002FC910.state==135 && (*(s32 *)(D_001D52FC+0x1A0)&func_003A3BB8(64,0))) active=1;
        if(D_001A4BE0_002FC910.state==16 && D_001A4BE0_002FC910.frame<=36)active=1;
        if(D_001A4BE0_002FC910.state==33 && (D_001A4BE0_002FC910.frame<12 || (D_001A4BE0_002FC910.frame>=28 && D_001A4BE0_002FC910.h36E)))active=1;
        if(D_001A4BE0_002FC910.state==8)active=1;
        if(D_001A4BE0_002FC910.state==135)active=1;
        if(D_001A4BE0_002FC910.suppressed)active=0;
    }
    switch(self[0x20]) {
    case 0:
        self[0x20]=1;
        *(u16 *)(self+0x34)|=1;
        self[0x30]=255;
        *(f32 *)(self+0x18)+=0.5f;
        break;
    case 1:
        if((func_L01_004E9238(3)!=3 && func_L01_004E9238(3)!=8) || !D_001A4BE0_002FC910.clank) {
            func_003C2880(self);
            return;
        }
        if(!D_001A8EA4[0] && D_001A4BE0_002FC910.item==3)func_L01_0041A5B0(0x18CD,0x161);
        if(active) {
            self[0x20]=2;
            v->timer=2;
            v->da=0.00625f;
            v->db=0.1f;
            v->dc=0.025f;
            v->dd=0.0125f;
            v->a=0;
            v->b=0;
            v->c=0;
            v->d=0;
        }
        break;
    case 2:
        v->a+=v->da;
        v->b+=v->db;
        v->c+=v->dc;
        v->d+=v->dd;
        v->owner=D_001A4BE0_002FC910.backpack;
        func_L01_00404A10(func_L01_002FBCD0,self);
        if(func_0038CAD0(&v->timer)) {
            f32 c=0.05f, b=0.2f, a=0.0125f;
            self[0x20]=3;
            v->d=0.025f;
            v->a=a;
            v->b=b;
            v->c=c;
            v->active=0;
        }
        break;
    case 3:
        v->owner=D_001A4BE0_002FC910.backpack;
        func_L01_00404A10(func_L01_002FBCD0,self);
        if(!active) {
            self[0x20]=4;
            v->timer=7;
            v->da=0.0017857142956927419f;
            v->db=0.02857142873108387f;
            v->dc=0.0071428571827709675f;
            v->dd=0.0035714285913854837f;
        } else {
            v->a=0.0125f;
            func_L01_002FC3E8(self);
        }
        break;
    case 4:
        if(func_0038CAD0(&v->timer))self[0x20]=1;
        else {
            v->a-=v->da;
            v->b-=v->db;
            v->c-=v->dc;
            v->d-=v->dd;
            v->owner=D_001A4BE0_002FC910.backpack;
            func_L01_00404A10(func_L01_002FBCD0,self);
        }
        break;
    }
}
/* localdecomp:end func_L01_002FC910 */
