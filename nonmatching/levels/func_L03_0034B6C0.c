/* NTSC-U draft (2026-11-14, Codex worker): C of func_L03_0034AB00, the NTSC-U twin of func_L03_0034B6C0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L03_0034B440.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* localdecomp:start func_L03_0034AB00 */
typedef int Q_0034AB00 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_0034AB00;
extern s32 func_L01_00448E90(void *);
extern f32 func_003BE7F0(void *,s32,s32,f32);
extern void func_L01_004367A0(void *,u16 *,s32 *);
extern s32 func_003CE740(void *,void *,s32,void *,s32);
extern void func_L01_00441FB8(void *,s32,s32);
extern s32 func_L01_0044FC98(void *,s32,s32,s32);
extern void func_0039FE80(s32,s32,void *);
extern void func_00388830(void *,void *,f32);
extern void func_L01_0044ED60(void *,s32,void *,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32,f32,f32,f32,f32);
extern void func_L03_0034AFE0(void *);
extern void func_003BD360(void *);
extern s32 func_L03_0034B0C0(void *,void *);
extern f32 func_0037E250(f32,f32);
extern u8 D_L03_001FC450[];
extern u8 D_L03_001E9280[];
extern u8 D_L03_001E2540[];
void func_L03_0034AB00(u8 *m) {
    V_0034AB00 bottom,top;
    u16 result;
    s32 result2;
    u8 *v;
    s32 i;
    u16 old;
    f32 height;
    if(!func_L01_00448E90(m+0x10)) return;
    v=*(u8 **)(m+0x68);
    switch(m[0x20]) {
    case 0:
        *(u16 *)(m+0x34)|=0x100;
        *(u16 *)(v+0x152)=0;
        for(i=0;i<2;i++) {
            if(((s32 *)(v+0x154))[i]!=-1) (*(u16 *)(v+0x152))++;
        }
        for(i=0;i<2;i++) {
            if(D_L03_001FC450[((s32 *)(v+0x154))[i]]==255) *(u16 *)(v+0x152)=0;
        }
        *(f32 *)(m+0x18)=func_003BE7F0(m+0x10,0,0,0.5f);
        func_L01_004367A0(m,&result,&result2);
        *(Q_0034AB00 *)&top=*(Q_0034AB00 *)(m+0x10);
        *(Q_0034AB00 *)&bottom=*(Q_0034AB00 *)(m+0x10);
        top.z+=0.5f;
        bottom.z-=1.0f;
        *(u16 *)(m+0x7C)=result;
        if(func_003CE740(&top,&bottom,0,m,0)) {
            if(*(u8 **)(D_L03_001E9280+0x18)) {
                u8 *other;
                *(u16 *)(v+0x152)=0;
                other=*(u8 **)(D_L03_001E9280+0x18);
                *(u8 **)(v+0x15C)=other;
                *(Q_0034AB00 *)(m+0xF0)=*(Q_0034AB00 *)(other+0x10);
            }
        }
        *(u16 *)(v+0x152)|=0x80;
        if(*(f32 *)(v+0x30)<=0.0f) *(f32 *)(v+0x30)=30.0f;
        if(*(s16 *)(v+0x34)<=0) *(f32 *)(v+0x30)=30.0f;
        func_L01_00441FB8(m,1,-1);
    case 1:
        old=*(u16 *)(m+0x7C);
        if(func_L01_0044FC98(m,0,0,0)) *(u16 *)(v+0x36)=*(u16 *)(v+0x150);
        if(old!=*(u16 *)(m+0x7C) && !m[0xBC]) {
            func_0039FE80(0,0,m);
            m[0xBC]=20;
        }
        if(m[0xBC]) m[0xBC]--;
        if(*(f32 *)(v+0x30)<=0.0f) {
            *(Q_0034AB00 *)&bottom=*(Q_0034AB00 *)(m+0xE0);
            func_00388830(&bottom,&bottom,0.0333333351f);
            func_L01_0044ED60(m,65535,&bottom,255,180,0,0,35,0,3,3.0f,6.0f,3.0f,6.0f,-1.0f,-1.0f,1.0f,1.0f);
            func_0039FE80(0,0,m);
            func_L03_0034AFE0(m);
            func_003BD360(m);
            return;
        }
        if(*(u8 **)(v+0x15C)) {
            u8 *other=*(u8 **)(v+0x15C);
            if(other[0x20]==254 || other[0x20]==253) {
                *(u8 **)(v+0x15C)=0;
                *(u16 *)(v+0x152)&=0xFF7F;
            }
            if(*(u8 **)(v+0x15C) && !func_L03_0034B0C0(*(u8 **)(v+0x15C)+0x10,m+0xF0)) goto lower;
        }
        if(*(u16 *)(v+0x152)&0x80) return;
lower:
        *(u16 *)(v+0x152)&=0xFF7F;
        height=func_003BE7F0(m+0x10,0,0,0.5f);
        if(height<*(f32 *)(m+0x18)) {
            *(f32 *)(m+0x18)-=0.0816666707f;
            if(*(f32 *)(m+0x18)<height) {
                *(f32 *)(D_L03_001E2540+0x20)=func_0037E250(0.0f,0.25f);
                *(s32 *)(D_L03_001E2540+0x28)=20;
                *(s32 *)(D_L03_001E2540+0x2C)=0;
                *(f32 *)(m+0x18)=height;
                *(u16 *)(v+0x152)|=0x80;
            }
        }
        break;
    }
}
/* localdecomp:end func_L03_0034AB00 */
