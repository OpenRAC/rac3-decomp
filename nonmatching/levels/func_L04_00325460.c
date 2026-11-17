/* NTSC-U draft (2026-11-14, Codex worker): C of func_L04_00324BA8, the NTSC-U twin of func_L04_00325460, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L04_00325460.c's current line.
 * Worker's note: 191 diff best log func_L04_00324BA8.check01.log; documented inline-literal assembler mismatch lit4 lwc1 vs retail inline literals; unlisted flags not tried; frame/saved-register width/VU0 scheduling also differ
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00324BA8 */
typedef struct { s16 h0,h2,h4,pad6; f32 f8,fC,f10,f14; s32 w18,w1C,w20,w24,w28,w2C,w30,w34,w38; void *p3C; } P_324BA8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 b20; u8 pad21[0x30-0x21]; u8 b30,pad31; s16 h32; u8 pad34[0x68-0x34]; P_324BA8 *vars; u8 pad6C[0xC0-0x6C]; vu0_v4 vC0,vD0,vE0; } M_324BA8;
typedef struct { vu0_v4 pos; u8 pad10[0x10]; f32 f20; u8 pad24[4]; s32 w28,w2C; u8 pad30[0x380-0x30]; vu0_v4 v380; u8 pad390[0x460-0x390]; } Player_324BA8;
extern M_324BA8 *func_003BCFB0(s32,s32);
extern Player_324BA8 D_L04_001E28C0[];
extern s32 D_001D52F0[];
extern s32 D_001D52F0_sda;
extern void func_00388830(void *,void *,f32);
extern void func_003BFC18(void *,void *,s32);
extern void func_00388758(void *,void *,void *);
extern void func_L01_004495F8(void *,void *,void *,void *);
extern s32 func_003894E8(void *,f32);
extern f32 func_L01_0040C018(void *,void *);
extern f32 func_00388730(void *,void *);
extern f32 func_00388990(f32);
extern void func_L04_00325358(void *,void *,void *,f32);
static __inline__ void sub_ba_324BA8(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "memory");
}
static __inline__ void sub_to_b_324BA8(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "memory");
}
M_324BA8 *func_L04_00324BA8(vu0_v4 *pos,s32 flag,s32 w20,s32 w24,s32 w28,s32 w2C,s32 w30,s32 w18,s32 w34,s32 w1C,s32 w38,void *parent,f32 scale,f32 extra) {
    vu0_v4 dir,basis,shift,box,aim;
    M_324BA8 *m = func_003BCFB0(0x13A0,0x80);
    if (m) {
        P_324BA8 *p;
        m->b30 = 0xFF;
        m->h32 = 0x1FF;
        m->b20 = 0;
        p = m->vars;
        m->pos = *pos;
        m->pos.w = 1.0f;
        sub_ba_324BA8(&dir,&D_L04_001E28C0[D_001D52F0[0]].pos,&m->pos);
        func_00388830(&dir,&dir,1.0f);
        func_003BFC18(&m->pos,&basis,1);
        m->vC0 = dir;
        func_00388758(&m->vD0,&m->vC0,&basis);
        func_00388830(&m->vD0,&m->vD0,1.0f);
        func_00388758(&m->vE0,&m->vD0,&m->vC0);
        m->vC0.w=0.0f;
        m->vE0.w=0.0f;
        m->vD0.w=0.0f;
        p->w20=w20;
        p->w24=w24;
        p->w28=w28;
        p->w2C=w2C;
        p->w30=w30;
        p->h2=60;
        p->f8=scale+scale;
        p->fC=scale*4.0f;
        p->w34=w34;
        p->w1C=w1C;
        p->w38=w38;
        p->f14=scale;
        p->w18=w18;
        p->h0=60;
        p->p3C=parent;
        qzero(&shift);
        if (parent) func_L01_004495F8(m,parent,&m->pos,&shift);
        box=m->pos;
        box.w=scale*3.0f;
        if (func_003894E8(&box,511.0f)==1) {
            p->h4=10;
            p->f10=0.1f;
            if (flag && func_L01_0040C018(pos,&D_L04_001E28C0[D_001D52F0[0]].pos)<2304.0f) {
                D_L04_001E28C0[0].w28=40;
                D_L04_001E28C0[0].f20=0.075f;
                D_L04_001E28C0[0].w2C=0;
            }
            if (p->w18) {
                f32 a;
                sub_to_b_324BA8(&aim,&m->pos,&D_L04_001E28C0[D_001D52F0_sda].pos);
                func_00388830(&aim,&aim,1.0f);
                a=func_00388990(func_00388730(&aim,&D_L04_001E28C0[D_001D52F0[0]].v380));
                if (1.5707963705062866f-a<0.45378559827804565f) p->w18=1;
                else p->w18=0;
            }
        } else {p->h4=0;p->w18=0;}
        func_L04_00325358(m,&basis,&shift,extra);
    }
    return m;
}
/* localdecomp:end func_L04_00324BA8 */
