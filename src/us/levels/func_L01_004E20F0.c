#include "common.h"

/* NTSC-U counterpart of func_L01_004E5EB8 (src/levels/shared/L01_004E2988.c): 0.06 -> 0.05; 0.16 -> 0.133333 */
typedef struct {
    u8 pad0[4688];
    s32 f1250;
    u8 pad1254[36];
    s32 f1278;
    u8 pad127C[4932];
    s32 f25C0;
} G_4DD4B0;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x80];
    f32 x;
    f32 y;
    u8 pad88[0x10];
    f32 angle;
    u8 pad9C[0x350 - 0x9C];
    f32 z;
    u8 pad354[0x9C8 - 0x354];
    u16 counter;
} G_004E5840;
extern G_4DD4B0 D_001A4BE0;
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
#include "vu0.h"
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
#include "vu0.h"
extern G_4DD4B0 D_001A4BE0;
#include "vu0.h"
extern G_4DD4B0 D_001A4BE0;
extern G_4DD4B0 D_001A4BE0;
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00465410(f32 *, f32 *, s32, s32);

/* localdecomp:start func_L01_004E20F0 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_004E5EB8;
extern G_4DD4B0 D_001A4BE0;
void func_L01_004E20F0(s32 first, s32 second, s32 flash) {
    extern void func_L01_00301508(void *, s32, f32, f32);
    extern f32 func_0037E250(f32, f32);
    extern f32 func_0037E2A8(void);
    extern f32 func_00388960(f32);
    extern f32 func_00388978(f32);
    extern s32 func_0037E1D8(s32);
    extern s32 func_0037E208(s32, s32);
    extern void func_L01_00467288(f32 *, f32 *, s32, f32, f32);
    extern void func_L01_00465410(f32 *, f32 *, s32, s32);
    f32 v[4] __attribute__((aligned(16)));
    Vec_004E5EB8 position;
    f32 angle, radius, random;
    s32 kind, life;
    s32 n;
    if(flash) {
        f32 *p=(f32 *)((u8 *)&D_001A4BE0+0x80);
        *(u128_t *)v=*(u128_t *)p;
        v[2]=p[0x2D0/4];
        func_L01_00301508(v,3,2.25f,1.025f);
    }
    if(first>0) {
        G_004E5840 *h=(G_004E5840 *)&D_001A4BE0;
        do {
            v[0]=h->x+func_0037E250(-0.3f,0.3f);
            v[1]=h->y+func_0037E250(-0.3f,0.3f);
            v[2]=h->z;
            random=func_0037E250(0.3f,0.6f);
            func_L01_00467288(v,&h->z,-1,random,5250.0f);
            first--;
        } while(first);
    }
    {
        for(n=0;n<second;n++) {
            G_004E5840 *h=(G_004E5840 *)&D_001A4BE0;
            angle=func_0037E2A8();
            radius=func_0037E250(0.0f,0.0500000045f);
            v[0]=func_00388960(angle)*radius;
            v[1]=func_00388978(angle)*radius;
            v[2]=func_0037E250(0.0500000045f,0.13333334f);
            position.x=h->x+v[0]*8.0f;
            position.y=h->y+v[0]*8.0f;
            position.z=h->z-func_0037E250(0.0f,0.2f);
            kind=func_0037E1D8(2);
            life=func_0037E208(90,120);
            func_L01_00465410((f32 *)&position,v,kind,life);
        }
    }
}
/* localdecomp:end func_L01_004E20F0 */
