#include "common.h"

/* NTSC-U counterpart of func_L01_004E7338 (src/levels/shared/L01_004E7338.c): the control-4 phase limit is 12, not 10; NTSC-U addresses */
/* localdecomp:start func_L01_004E3570 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x320];
    f32 x,y,rx,ry,vx,vy;
    u8 pad338[0x368-0x338]; s16 mode;
    u8 pad36A[0x46C-0x36A]; u8 phase;
    u8 pad46D[0x1250-0x46D]; u8 *hand0,*hand1;
    u8 pad1258[0x1410-0x1258];
    f32 spread,random;
    s32 bursts; s16 count; u16 flags;
    u8 pad1420[0x25C0-0x1420]; u8 *body;
    s32 state,pad25C8,control;
} Hero_004E7338;
typedef struct { u8 pad[0x320]; f32 outx,outy; u8 p328[0x36C-0x328]; f32 time0;
    u8 p370[0x3D0-0x370]; f32 outx1,outy1; u8 p3D8[0x41C-0x3D8]; f32 time1;
    u8 p420[0x480-0x420]; f32 target0; u8 p484[0x530-0x484]; f32 target1;
} Motion_004E7338;
extern u8 D_001A4BE0[];
extern Motion_004E7338 D_L01_002F4580;
extern s32 func_L01_004E5540(void);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern void func_L01_0050CCC8(f32, s32, f32, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00464068(void *, void *, f32);
void func_L01_004E3570(void)
{
    vu0_q pos;
    f32 x,y;
    void *orient;
    s32 i;
    u8 *m;
    if((*(Hero_004E7338 *)&D_001A4BE0).hand0) {
        D_L01_002F4580.time0=0.01f;
        D_L01_002F4580.time1=0.01f;
    }
    m=(*(Hero_004E7338 *)&D_001A4BE0).hand0;
    if(m && *(s16 *)(m+0xAA)==0xAD) *(f32 *)(m+0x2C)=*(f32 *)(*(u8 **)(m+0x24)+0x24)*0.9f;
    m=(*(Hero_004E7338 *)&D_001A4BE0).hand1;
    if(m && *(s16 *)(m+0xAA)==0xAD) *(f32 *)(m+0x2C)=*(f32 *)(*(u8 **)(m+0x24)+0x24)*0.9f;
    if(func_L01_004E5540()) return;
    if(fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).x)>0.015f || fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).y)>0.015f || fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).rx)>0.017453292f ||
       fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).ry)>0.017453292f || fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).vx)>0.017453292f || fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).vy)>0.017453292f) {
        if((*(Hero_004E7338 *)&D_001A4BE0).mode!=1) {
            Motion_004E7338 *d=&D_L01_002F4580;
            d->outy=-(*(Hero_004E7338 *)&D_001A4BE0).rx;
            d->outy1=-(*(Hero_004E7338 *)&D_001A4BE0).ry;
            x=func_00388A28(0.2f,(*(Hero_004E7338 *)&D_001A4BE0).x)*1.2f;
            y=-func_00388A28(0.2f,(*(Hero_004E7338 *)&D_001A4BE0).y)*1.2f;
            if(x>0.7853982f)x=0.7853982f;
            if(x<-0.17453292f)x=-0.17453292f;
            if(y>0.17453292f)y=0.17453292f;
            if(y<-0.7853982f)y=-0.7853982f;
            d->target0=x;
            d->target1=y;
            d->outx=-func_003893C8((*(Hero_004E7338 *)&D_001A4BE0).vx,-x);
            d->outx1=-func_003893C8((*(Hero_004E7338 *)&D_001A4BE0).vy,-y);
        }
    }
    if(!((*(Hero_004E7338 *)&D_001A4BE0).flags&0x80)) {
    if((*(Hero_004E7338 *)&D_001A4BE0).state==3) func_L01_0050CCC8(0.021f,1,0.002f,2,1,0);
    if((*(Hero_004E7338 *)&D_001A4BE0).control==4 && (*(Hero_004E7338 *)&D_001A4BE0).phase && (*(Hero_004E7338 *)&D_001A4BE0).phase<12) func_L01_0050CCC8(0.016f,1,0.002f,2,0,1);
    if((*(Hero_004E7338 *)&D_001A4BE0).bursts>0 && (*(Hero_004E7338 *)&D_001A4BE0).count) {
        orient=0;
        if((*(Hero_004E7338 *)&D_001A4BE0).flags&1)orient=(*(Hero_004E7338 *)&D_001A4BE0).body+0xC0;
        (*(Hero_004E7338 *)&D_001A4BE0).bursts--;
        func_003BDA38((*(Hero_004E7338 *)&D_001A4BE0).body,22,&pos);
        for(i=0;i<(*(Hero_004E7338 *)&D_001A4BE0).count;i++) {
            f32 r=func_0037E250(-(*(Hero_004E7338 *)&D_001A4BE0).random,(*(Hero_004E7338 *)&D_001A4BE0).random);
            func_L01_00464068(&pos,orient,(*(Hero_004E7338 *)&D_001A4BE0).spread+r);
        }
        func_003BDA38((*(Hero_004E7338 *)&D_001A4BE0).body,23,&pos);
        for(i=0;i<(*(Hero_004E7338 *)&D_001A4BE0).count;i++) {
            f32 r=func_0037E250(-(*(Hero_004E7338 *)&D_001A4BE0).random,(*(Hero_004E7338 *)&D_001A4BE0).random);
            func_L01_00464068(&pos,orient,(*(Hero_004E7338 *)&D_001A4BE0).spread+r);
        }
    }
    } else {(*(Hero_004E7338 *)&D_001A4BE0).bursts=0;}
}
/* localdecomp:end func_L01_004E3570 */
