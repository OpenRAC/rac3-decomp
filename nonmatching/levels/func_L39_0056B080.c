/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_0056A3A8, the NTSC-U twin of func_L39_0056B080, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (src/levels/shared/L39_0056B080.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_0056A3A8 */
typedef struct { u8 bytes[0x460]; } Rec_56A3A8;
extern Rec_56A3A8 D_L39_0024DF80[];
extern s32 D_L39_0024B958[], D_L39_00242B3C[], D_001DFF2C_sda;
extern f32 D_001DFF10_sda, D_L39_00242508[];
extern void *D_L39_002638C0[];
extern s32 func_L01_003F09E0(s32);
extern void func_00388398(s32 *);
extern s32 func_003883C8(s16 *);
extern f32 func_00389380(f32,f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00389468(f32,f32);
extern void func_L01_003E6F90(s32,f32,f32);
extern void func_L01_003E73D0(s32,void *,f32,f32);
extern void func_L01_003E7028(s32);
extern void func_L01_003E6DA8(s32,f32,f32);
extern void func_L01_003E7068(s32,s32);
extern void func_L01_003E6D50(s32,s32,f32,f32);
extern void func_L01_003E7430(s32,void *,f32,f32);
extern void func_L01_003E6F38(s32,f32,f32);
extern void func_L01_003E6FF0(s32);
extern void func_L01_003E70A0(s32,f32,f32,f32);
extern void func_L01_003E6F00(s32,s32);
extern s32 func_003CF790(void *,s32,void *,s32,f32);
extern u8 *func_0037E0B8(void *);
void func_L39_0056A3A8(u8 *m) {
    f32 v[4];
    s32 special=0;
    s32 id=*(s32 *)(m+0x94);
    u8 *base=*(u8 **)(m+0x70);
    u8 *move=base+0x60, *s=base+0x210, *flags=base+0x260;
    u8 *rec=D_L39_0024DF80[id].bytes;
    u8 *state=rec+0x150;
    s32 result=func_L01_003F09E0(id);
    if (*(s32 *)(state+0x100)==0x7E || *(s32 *)(state+0x100)==0x7A || *(s32 *)(state+0x100)==0x90) *(s16 *)(s+0x4E)=1;
    if (!*(s32 *)(state+0x11C) || *(s32 *)(move+0x114)) {
        f32 limit=*(f32 *)(move+0x110);
        if (limit>2.0f) limit=2.0f;
        *(f32 *)(move+0x104)=(D_001DFF10_sda-0.00200000009499f)*(limit*0.5f)+0.00200000009499f;
        if (*(s32 *)(state+0x11C)) func_00388398((s32 *)(move+0x114));
        else *(s32 *)(move+0x114)=15;
    }
    if (*(s32 *)(state+0x104)==30) {
        *(f32 *)(*(u8 **)(m+0x70)+0x130)=0.75f;
        func_L01_003E6F90(id,0.04f,0.2f);
    }
    if (*(s32 *)(state+0xFC)==13 && *(s32 *)(state+0x144)) {
        f32 angle=func_00389380(*(f32 *)(state+0x148),3.14159274101f);
        v[0]=func_00388960(angle);
        v[1]=func_00388978(angle);
        v[2]=0;
        func_L01_003E73D0(id,v,0.209439516068f,v[2]);
        func_L01_003E7028(id);
    }
    if (*(s32 *)(state+0x104)==17) {
        *(f32 *)(move+0xD0)=0.25f;
        func_L01_003E6DA8(id,0.5f,0.00300000002608f);
        D_L39_0024B958[id]=180;
    } else {
        func_L01_003E7068(id,20);
        D_L39_0024B958[id]=148;
    }
    if (*(s32 *)(state+0x104)==5 && !D_L39_00242B3C[0]) {
        *(f32 *)(*(u8 **)(m+0x70)+0x130)=0.25f;
        special=1;
        func_L01_003E6DA8(id,2.5f,0.00300000002608f);
    }
    if (*(s32 *)(state+0x104)==16) *(f32 *)(move+0xD0)=0.25f;
    if (state[0x12C] && state[0x133] && !*(s32 *)flags && result==-1) {
        func_L01_003E6D50(id,1,6.75f,0.00300000002608f);
        if (!special) {
            *(f32 *)(move+0xD0)=2.0f;
            func_L01_003E6DA8(id,2.75f,0.00300000002608f);
        }
    }
    if (*(void (**)(s32))(rec+0x400)) (*(void (**)(s32))(rec+0x400))(id);
    {
        u8 *r=D_L39_0024DF80[id].bytes;
        u8 *obj=*(u8 **)(r+0x144);
        if (obj && *(s32 *)(flags+0x10)<2) {
            if (obj[0x20]==0xFE || obj[0x20]==0xFD) *(s32 *)(r+0x144)=0;
            else {
                u8 *control=*(u8 **)(state+0x134);
                if (fabs_asm(*(f32 *)(control+0x100))>=0.3f || fabs_asm(*(f32 *)(control+0x104))>=0.3f) *(s32 *)(r+0x148)=640;
                r=D_L39_0024DF80[id].bytes;
                if (*(s32 *)(r+0x148)>400) {
                    func_00388398((s32 *)(r+0x148));
                    if (*(s32 *)(r+0x148)<401) *(s32 *)(r+0x148)=0;
                } else {
                    if (++*(s32 *)(r+0x148)>400) *(s32 *)(r+0x148)=400;
                    func_L01_003E7430(id,*(u8 **)(r+0x144)+0x10,((f32)*(s32 *)(r+0x148)/400.0f)*1.57079637051f,0.0f);
                    func_L01_003E7028(id);
                    func_L01_003E6F38(id,0.03f,0.2f);
                }
            }
        }
    }
    if (*(s32 *)(state+0x100)==0x83) {
        func_L01_003E7028(id);
        func_L01_003E6F38(id,1.0f,1.0f);
        func_L01_003E6F90(id,0.06f,0.2f);
        func_L01_003E6FF0(id);
    }
    if (*(s32 *)(state+0x100)==0x7D) {
        func_L01_003E6F38(id,0.04f,0.2f);
        func_L01_003E73D0(id,*(u8 **)(state+0xF0)+0xC0,0.785398185253f,0.0174532923847f);
        func_L01_003E6D50(id,0,3.0f,0.00300000002608f);
        func_L01_003E70A0(id,-1.0f,-1.0f,0.18f);
        func_L01_003E6FF0(id);
    }
    if (*(s32 *)(flags+0x10)<2 && *(s32 *)(state+0x100)!=0x83 && *(s32 *)(state+0x100)!=0x7D &&
        (*(s16 *)(state+0x126) || ((*(s32 *)(state+0x100)==0x80 || *(s32 *)(state+0x100)==0x84) && (*(s32 *)(*(u8 **)(state+0x134)+0x1A0)&3)))) {
        u8 *b;
        func_L01_003E6F00(id,0);
        func_L01_003E7028(id);
        func_L01_003E6F38(id,0.04f,0.2f);
        b=*(u8 **)(m+0x70);
        *(s16 *)(b+0x14)=0; *(s16 *)(b+0x16)=0; *(s16 *)(b+0x12)=0;
    } else if (D_001DFF2C_sda) {
        u8 *b=*(u8 **)(m+0x70);
        s32 i;
        f32 average=0.0f, weight;
        for(i=0;i<4;i++) { v[i]=func_00389468(*(f32 *)(rec+0x10C+i*4),*(f32 *)(rec+0x110+i*4)); average+=v[i]; }
        average*=0.25f;
        weight=average*5.0f;
        if (weight>1.0f) weight=1.0f;
        weight=1.0f-weight;
        if (weight<0.3f) *(s16 *)(b+0x12)=32;
        if (*(s16 *)(b+0x12)) {
            if (func_003883C8((s16 *)(b+0x12))) *(s16 *)(b+0x14)=45;
            func_L01_003E7028(id);
            if (++*(s16 *)(b+0x16)>30) *(s16 *)(b+0x16)=30;
            func_L01_003E6F38(id,((f32)*(s16 *)(b+0x16)/30.0f)*0.0249999985099f+0.015f,0.2f);
            D_L39_00242508[id]=0;
        } else if (*(s16 *)(b+0x14)) {
            func_003883C8((s16 *)(b+0x14));
            D_L39_00242508[id]=((f32)*(s16 *)(b+0x14)/45.0f)*-0.85f+0.85f;
            *(s16 *)(b+0x16)=0;
        } else {
            *(s16 *)(b+0x16)=0;
            D_L39_00242508[id]=0.85f;
        }
    }
    *(s32 *)(flags+0x10)=0;
    {
        s32 n=func_003CF790(state+0x40,1,*(void **)(state+0xF0),0,15.0f);
        s32 i=0;
        while(i<n) {
            u8 *o=func_0037E0B8(D_L39_002638C0[i]);
            if (o && (f32)o[0xD]!=0.0f) *(s32 *)(flags+0x10)=1;
            i++;
        }
    }
}
/* localdecomp:end func_L39_0056A3A8 */
