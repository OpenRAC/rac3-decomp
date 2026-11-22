#include "common.h"
#include "vu0.h"

typedef struct { u8 pad0[0x80]; vu0_v4 pos; } H_003C9768;
extern H_003C9768 D_001A4BE0;
extern s32 D_L16_001DFC40;
extern u8 *D_L16_001E015C;
extern void func_003888C8(void *, void *, void *);
extern f32 func_L01_0040C040(void *, void *);

/* NTSC-U counterpart of func_L16_003CB420 (src/levels/16_kerwan/L16_003C9768.c). */
/* localdecomp:start func_L16_003C9AA0 */
extern u8 D_001DE9B0_sda;
__asm__(".extern D_001DE9B0_sda, 1");
extern s32 D_001DE9AC_sda;
__asm__(".extern D_001DE9AC_sda, 4");
extern u8 *D_001E015C_sda;
__asm__(".extern D_001E015C_sda, 4");
typedef struct { u8 pad[0x144]; void *owner; s32 timer; } Manager_003CB420;
extern Manager_003CB420 D_L16_001E2B80;
typedef struct {u8 pad[0x20]; void *source; u8 pad28[8]; f32 damage;} Hit_003CB420;
typedef struct {u8 pad0[0x35C]; void *node; u8 pad1[0x25C0-0x360]; s32 clock; u8 pad2[0x2850-0x25C4]; s32 count;} Hero_003CB420;
typedef struct {
    u8 pad30[48];
    s16 f30;
    u8 pad37[5];
    u8 f37;
    u8 pad40[8];
    f32 f40;
    s16 f44;
    u8 pad57[17];
    u8 f57;
    u8 pad108[176];
    void *f108;
    u8 pad180[116];
    s32 f180;
    s16 f184;
    u8 pad190[10];
    s32 f190;
    u8 pad19c[8];
    s32 f19c;
    f32 f1a0;
    void * f1a4;
    void * f1a8;
    s32 f1ac;
    u8 pad1bc[12];
    s32 f1bc;
    u8 pad1e4[36];
    s32 f1e4;
    u8 pad1f0[8];
    s32 f1f0[3];
    s32 f1fc[3];
    u8 pad20c[4];
    s32 f20c;
    s16 f210;
    s16 f212;
    s16 f214;
    s16 f216;
    s16 f218;
    s16 f21a;
    u8 pad220[4];
    s32 f220;
    s32 f224;
} State_003CB420;
s32 func_L16_003C9AA0(void *arg) {
    extern void func_L16_003CA0A8(void *);
    extern Hit_003CB420 *func_L01_00444358(void *, s32, s32);
    extern s32 func_L01_00449C10(void *);
    extern void func_003BF4F8(void *, void *);
    extern s32 func_L01_00441FB8(void *, s32, s32);
    extern s32 func_L01_004412D0(void *, s32, s32);
    extern void func_L02_003F84F0(s32, s32, f32);
    extern void func_L01_004479A8(void *, void *);
    extern void func_L01_0044B598(void *, s32);
    extern void func_L01_004026A0(void *, s32);
    extern u8 *func_003BF7E8(void *);
    u8 *a = arg;
    State_003CB420 *st = *(State_003CB420 **)(a+0x68);
    u8 *e, *e2;
    s32 i, j, side, index, state, node;
    s32 *path, *path2, *path3, *path4;
    f32 d, best, health;
    if (a[0x20] == 0) func_L16_003CA0A8(a);
    if (!D_001DE9B0_sda && a[0x95]) { D_001DE9B0_sda=1; D_001DE9AC_sda++; }
    e=(u8 *)func_L01_00444358(a,-1,0);
    if (e) {
        if (D_L16_001DFC40 >= st->f19c && a[0x20]!=11 && a[0x95]!=3 && a[0x95]!=0) {
            if (((Hit_003CB420 *)e)->source) st->f57=func_L01_00449C10(((Hit_003CB420 *)e)->source);
            st->f40-=((Hit_003CB420 *)e)->damage;
            st->f19c=D_L16_001DFC40+10;
            st->f37=255;
            func_003BF4F8(a,(u8 *)st+0x30);
            st->f1a0+=((Hit_003CB420 *)e)->damage;
            if (st->f1a0 >= (f32)st->f44/10.0f) {
                func_L01_00441FB8(a,11,-1);
                st->f1a0=-1000.0f;
            }
        }
        a[0xA8]=255;
    }
    if ((D_L16_001DFC40&31)==(((s32)a>>8)&31) && a[0x20]!=8 && a[0x20]!=9) {
        side=-1; index=-1; best=1000000.0f;
        for(i=0;i<3;i++) {
            d=func_L01_0040C040(a+0x10,D_L16_001E015C+(st->f1f0[i]<<8)+0x10);
            if(d<best) {best=d;side=0;index=i;}
            d=func_L01_0040C040(a+0x10,D_L16_001E015C+(st->f1fc[i]<<8)+0x10);
            if(d<best) {best=d;side=1;index=i;}
        }
        if(best>400.0f) {st->f218=side;st->f21a=index;func_L01_00441FB8(a,6,-1);}
    }
    health=st->f40/(f32)st->f44;
    if(health<=0.0f) {
        if(st->f1bc==0) {
            if(a[0x95]!=3) func_L01_004412D0(a,0x200,3);
            func_L01_00441FB8(a,12,3);
        } else func_L01_00441FB8(a,4,-1);
    }
    if(health>0.666f) st->f190=1; else if(health>0.333f) st->f190=2; else st->f190=3;
    if(st->f1bc==2) {
        if(st->f218) e=D_001E015C_sda+(st->f1fc[st->f21a]<<8);
        else e=D_001E015C_sda+(st->f1f0[st->f21a]<<8);
        func_003888C8((u8 *)st+0x260,(u8 *)st+0x250,e+0xC0);
        vec_add_ba((u8 *)st+0x260,(u8 *)st+0x260,e+0x10);
    }
    if(((Hero_003CB420 *)&D_001A4BE0)->count<st->f220 && st->f1e4<=0) st->f224=1;
    st->f220=((Hero_003CB420 *)&D_001A4BE0)->count;
    if(a[0x95] && a[0x95]!=3) {
        func_L02_003F84F0(4,0,health<0.0f?0.0f:health);
        if(!D_L16_001E2B80.owner) {D_L16_001E2B80.owner=a;D_L16_001E2B80.timer=0;}
    } else if(D_L16_001E2B80.owner==a) D_L16_001E2B80.owner=0;
    func_L01_004479A8(a,(u8 *)st+0x30);
    if(!st->f30) func_L01_0044B598(a,st->f20c);
    func_L01_004026A0(a,3);
    qzero((u8 *)st+0x2D0);qzero((u8 *)st+0x350);
    st->f180=((Hero_003CB420 *)&D_001A4BE0)->clock;
    st->f184=1;
    if(st->f108) st->f1a4=st->f108;
    if(st->f1a4) {
        for(j=0;j<3;j++) {
            if(((Hero_003CB420 *)&D_001A4BE0)->node==D_L16_001E015C+(st->f1f0[j]<<8)) {st->f214=0;st->f216=j;}
            else if(((Hero_003CB420 *)&D_001A4BE0)->node==D_L16_001E015C+(st->f1fc[j]<<8)) {st->f214=1;st->f216=j;}
            if(st->f1a4==D_L16_001E015C+(st->f1f0[j]<<8)) {st->f210=0;st->f212=j;}
            else if(st->f1a4==D_L16_001E015C+(st->f1fc[j]<<8)) {st->f210=1;st->f212=j;}
        }
        if(st->f21a==-1) st->f21a=st->f212;
        if(st->f218==-1) st->f218=st->f210;
        e2=func_003BF7E8(st->f1a4);
        if(e2) *(vu0_q *)((u8 *)st+0x240)=*(vu0_q *)(e2+0x10);
        if(st->f1a8!=st->f1a4) {st->f1a8=st->f1a4;st->f1ac=0;}
    }
}
/* localdecomp:end func_L16_003C9AA0 */
