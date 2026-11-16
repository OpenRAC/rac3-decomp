/* PAL near miss, P01 wave 2 (2026-11-16), reconstructed from retail.
 * File flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock checker: 252 positional differences. Remaining differences include
 * HUD/reset block layout, small-data addressing and register allocation.
 * Not a full-program match; retain the source INCLUDE_ASM.
 */
#include "common.h"
typedef struct { u8 f0,f1,f2,f3; s32 time, weapon; } Row_330AA0;
typedef struct { u8 pad[12]; u8 flag; u8 gap[3]; } T_330AA0;
typedef struct {
    u8 pad[0x90]; s16 limits[7]; u8 mode,index; u8 gapA0[4]; s16 time;
    u8 gapA6[4]; u8 special,count; s32 score; u8 gapB0[8]; s32 fB8;
    s16 delay; u8 flags; u8 gapBF[0x1D]; u8 total, timer; u8 gapDE[6]; s32 soundA,soundB;
} V_330AA0;
typedef struct { u8 pad[0x234]; s32 weapon; } Hero_330AA0;
extern T_330AA0 D_L07_002B0D40_00330AA0[];
extern Hero_330AA0 D_001A4BE0_00330AA0;
extern s32 D_00142848_00330AA0;
extern u8 D_001427C3;
extern u8 D_00142CB6;
extern s32 D_L07_001DCE78[];
extern void func_L01_005170B8(s32,u32);
extern s32 func_L07_00333460(s32,s32);
extern void func_L01_00451F60(s32,s32,s32);
extern void func_L01_00517190(s32,s32);
extern void func_L01_004C94B0(void);
extern void func_003E4D10(s32,s32);
extern void func_L07_00332848(void *);
extern void func_L07_003328D0(void *);
extern void func_L07_003A2380(u8,void *,s32,s32);
extern s32 func_00382468(s32);
extern void func_L03_003AF098(s32);
extern void func_L07_003318D8(void *);
extern s32 func_L07_003338C0(s32,s32);
extern void func_L07_00332230(u8 *,s32);
extern void func_L01_0045F1E8(s32,s32);
extern void func_L07_003354A0(void *);
void func_L07_00330AA0(u8 *self) {
    V_330AA0 *v=*(V_330AA0 **)(self+0x68);
    s32 i, slot;
    Row_330AA0 *old=0,*row;
    if(D_L07_002B0D40_00330AA0[v->mode].flag || v->index==255) {
        v->flags=0;
        for(i=0;i<8;i++) func_L01_005170B8(0x150008+i,0x8066CCFF);
        slot=0;
        v->fB8=0;
        if(v->index!=255) old=(Row_330AA0 *)func_L07_00333460(v->mode,v->index);
        v->index++;
        row=(Row_330AA0 *)func_L07_00333460(v->mode,v->index);
        v->time=-1;
        if(row->time!=-1) v->time=(row->time*5+2)/6;
        if(v->time!=-1) {
            func_L01_00451F60(4702,-1,0);
            slot=1;
            func_L01_00517190(0x150008,0xEC5A);
            v->flags|=1;
        }
        if(!row->f0) {
            if(D_00142848_00330AA0) {
                u8 prev=*(u8 *)&D_00142848_00330AA0;
                D_00142848_00330AA0=0;
                D_001427C3=prev+1;
            }
            func_L01_004C94B0();
            func_L01_00517190(0x150008+slot,0xEC56);
            if(!old || old->f0) v->flags|=1<<slot;
            slot++;
        }
        if(row->weapon!=-1) {
            if(D_00142CB6) {
                if(D_00142848_00330AA0) {
                    u8 prev=*(u8 *)&D_00142848_00330AA0;
                    D_00142848_00330AA0=0;
                    D_001427C3=prev+1;
                }
                func_L01_004C94B0();
            }
            func_L01_00517190(0x150008+slot,0xEC58);
            if(!old || old->weapon!=row->weapon) v->flags|=1<<slot;
            slot++;
        }
        if(row->f2) {
            func_L01_00517190(0x150008+slot,0xEC57);
            if(!old || !old->f2) {
                v->count=0; v->score=0;
                func_L01_00451F60(4703,-1,0);
                v->flags|=1<<slot;
            }
            slot++;
        }
        if(old && old->f2 && !row->f2) {
            v->timer=3; v->total+=v->count;
            func_003E4D10(30,v->count);
        }
        if(row->f3) {
            if(!old || !old->f3) {
                if(D_001A4BE0_00330AA0.weapon>=3) D_001A4BE0_00330AA0.weapon=2;
                func_L07_00332848(self);
                func_L01_00451F60(4704,-1,0);
            }
        } else func_L07_003328D0(self);
        if(v->flags) v->delay=200;
        if(v->index) {
            if(v->flags) func_L07_003A2380(59,self,0,100);
            else if(!func_00382468(15)) func_L07_003A2380(42,self,0,100);
        }
        func_L03_003AF098(slot);
    } else {
        v->index++;
        if(!func_00382468(15)) func_L07_003A2380(42,self,0,100);
    }
    func_L07_003318D8(self);
    v->special=func_L07_003338C0(v->mode,v->index);
    if(v->special) {
        if(D_001A4BE0_00330AA0.weapon>=3) D_001A4BE0_00330AA0.weapon=2;
        func_L07_00332230(self,1);
        func_L01_0045F1E8(v->soundB,-1);
    } else func_L01_0045F1E8(v->soundA,-1);
    for(i=0;i<7;i++) v->limits[i]=D_L07_001DCE78[i];
    func_L07_003354A0(self);
}
