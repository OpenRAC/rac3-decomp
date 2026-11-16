/* PAL near miss, P01 wave 2 (2026-11-16), reconstructed from retail.
 * File flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock checker: 298 positional differences. Remaining differences include
 * hero-base lifetime, block placement, scheduling and saved-register allocation.
 * Not a full-program match; retain the source INCLUDE_ASM.
 */
#include "common.h"
typedef struct { u8 f0,f1,f2,f3; s32 time,weapon; } Row_32FDC8;
typedef struct {
    u8 pad[0x9E]; u8 mode,index; u8 gapA0[4]; s16 time; u8 gapA6[2];
    u8 failure,gapA9,special,count; f32 score; u8 row, gapB1; s16 ammo, remaining, timer;
    f32 phase; s16 delay; u8 flags; u8 gapBF[0x1D]; u8 total, restore, peak, previous;
    s32 said;
} V_32FDC8;
typedef struct { s32 weapon; u8 count; u8 gap[3]; } Weapon_32FDC8;
extern Weapon_32FDC8 D_L07_002B0EB0[];
typedef struct {
    u8 pad[0x1200]; s32 active; u8 gap1204[0x24]; s32 weapon;
    u8 gap122C[0x1398]; s32 id; u8 gap25C8[0x25]; u8 firing;
    u8 gap25EE[0x262]; s32 health; u8 gap2854[0x75]; u8 locked, request;
} Hero_32FDC8;
extern Hero_32FDC8 D_001A4BE0_0032FDC8;
extern s32 D_00142668;
extern s32 D_001427F0_0032FDC8[];
extern u8 D_L07_001DD104;
__asm__(".extern D_L07_001DD104, 1");
extern s32 D_001D4C38;
extern s32 D_L07_001D7B20;
extern s32 D_L07_001DF518;
extern void func_L07_003303B0(void *);
extern s32 func_L07_00333460(s32,s32);
extern void func_L07_00330F30(u8 *);
extern void func_003A52A0(s32,s32,void *);
extern void func_L07_003354A0(void *);
extern s32 func_0038CB00(s16 *);
extern void func_L07_003A2380(u8,void *,s32,s32);
extern s32 func_00382468(s32);
extern void func_003E4D10();
extern f32 func_0038DAB8(f32,f32);
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(u32,u32,f32);
extern void func_L01_005170B8(s32,u32);
extern s32 func_L01_0040E020(u8 *);
extern void func_L01_00452560(s32,s32,s32,s32,s32,s32,s32);
extern void func_L07_00335558(void *);
extern s32 func_L07_00332958(void *);
extern void func_L07_003352B8(void *,s32);
extern void func_L01_0044CD60(s32);
extern s32 func_L07_003334A8(u8 *,s32);
extern void func_L07_003304C0(u8 *);
void func_L07_0032FDC8(u8 *self) {
    V_32FDC8 *v=*(V_32FDC8 **)(self+0x68);
    Row_32FDC8 *row;
    func_L07_003303B0(self);
    if((u32)(self[0x20]-4)>=4) return;
    row=(Row_32FDC8 *)func_L07_00333460(v->mode,v->index);
    if(D_001A4BE0_0032FDC8.id==57) {
        if(row->f3) D_L07_001DD104=1;
        func_L07_00330F30(self);
    }
    if(D_001A4BE0_0032FDC8.id!=116) {
        if(v->time!=-1) {
            if(v->time%50==0) {
                if(v->time<=500) func_003A52A0(3,0,self);
                func_L07_003354A0(self);
            }
            if(func_0038CB00(&v->time)) {
                func_L07_003A2380(44,self,0,100);
                v->failure=1;
                func_L07_00330F30(self);
            }
        }
        if(row->f2) {
            v->score+=0.00600000052f;
            if(v->score>=1.0f && D_001A4BE0_0032FDC8.health>0) {
                s32 spoke=0;
                if(D_001A4BE0_0032FDC8.health<=(D_00142668>>2) && !(v->said&0x800)) {
                    func_L07_003A2380(57,self,0,100);
                    v->said|=0x800; spoke=1;
                }
                if(!spoke && !(v->said&0x400) && !func_00382468(8)) {
                    func_L07_003A2380(56,self,0,100);
                    v->said|=0x400;
                }
                D_001A4BE0_0032FDC8.health--;
                v->score-=1.0f;
                v->count++;
            }
            func_003E4D10(3);
        }
        if(v->flags) {
            s32 color,i;
            v->phase=func_0038DAB8(v->phase,0.2513274252f);
            color=func_0038DBD8(0x8066CCFF,0x80FFFFFF,(1.0f-func_0038D098(v->phase))*0.5f);
            for(i=0;i<8;i++) if((v->flags>>i)&1) func_L01_005170B8(0x150008+i,color);
            if(func_0038CB00(&v->delay)) v->flags=0;
        }
        if(v->total && func_L01_0040E020(&v->restore)) {
            if(D_001A4BE0_0032FDC8.health<D_00142668) D_001A4BE0_0032FDC8.health++;
            v->restore=3;
            v->total--;
            func_003E4D10(30);
        }
    }
    if(row->f3) {
        s32 weapon,amount,threshold;
        Weapon_32FDC8 *w;
        func_L01_00452560(0,5,0,1,0,0,0);
        func_L07_00335558(self);
        w=&D_L07_002B0EB0[v->row];
        weapon=w->weapon;
        amount=D_001427F0_0032FDC8[weapon];
        if(v->ammo<amount) v->ammo=amount;
        else {
            v->remaining-=v->ammo-amount;
            D_001427F0_0032FDC8[weapon]=v->ammo;
            threshold=w->count>>3;
            if((threshold && v->remaining==threshold) || (!threshold && v->remaining==1)) {
                if(!(v->said&0x8000) && !func_00382468(4)) {
                    func_L07_003A2380(49,self,0,100);
                    v->said|=0x10000;
                }
                v->said|=0x8000;
            }
            if(v->remaining>0) v->timer=0;
            else {
                v->timer++;
                D_001A4BE0_0032FDC8.firing=1;
                if(v->timer>25) {
                    weapon=func_L07_00332958(self);
                    D_001A4BE0_0032FDC8.firing=0;
                    func_L07_003352B8(self,weapon);
                }
            }
        }
        if(!D_001A4BE0_0032FDC8.active || D_001A4BE0_0032FDC8.weapon!=weapon) {
            D_001A4BE0_0032FDC8.request=1; D_001A4BE0_0032FDC8.locked=0;
            func_L01_0044CD60(weapon);
        } else D_001A4BE0_0032FDC8.locked=1;
    } else if(row->weapon!=-1) {
        func_L01_00452560(0,5,0,1,0,0,0);
        if(!D_001A4BE0_0032FDC8.active || D_001A4BE0_0032FDC8.weapon!=row->weapon) {
            D_001A4BE0_0032FDC8.locked=0;
            func_L01_0044CD60(row->weapon);
        } else D_001A4BE0_0032FDC8.locked=1;
        if(func_L07_003334A8(self,row->weapon)) {
            v->failure=2;
            func_L07_00330F30(self);
        }
    } else D_001A4BE0_0032FDC8.locked=0;
    if(!row->f0) {
        if(v->peak<D_001A4BE0_0032FDC8.health) v->peak=D_001A4BE0_0032FDC8.health;
        if(D_001A4BE0_0032FDC8.health<v->peak) {
            v->failure=3;
            func_L07_00330F30(self);
        }
    }
    func_L07_003304C0(self);
    D_L07_001D7B20=v->mode+10;
    D_L07_001DF518=D_001D4C38;
}
