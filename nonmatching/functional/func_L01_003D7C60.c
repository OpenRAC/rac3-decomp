/* exact: byte-identical per tools/check.py at level 01. */
#include "common.h"
/* localdecomp:start func_L01_003D7C60 */
#include "vu0.h"
__asm__(".extern D_L01_001DF4A4, 4");
extern s32 D_L01_001DF45C;
extern s32 D_L01_001DF460;
extern s32 D_L01_001DF464;
extern s32 D_L01_001DF47C;
extern s32 D_L01_001DF4A0;
extern s32 D_L01_001DF4A4;
extern s32 D_L01_001DF4A8;
extern f32 D_L01_001DF468;
extern f32 D_L01_001DF46C;
extern f32 D_L01_001DF470;
extern f32 D_L01_001DF474;
extern f32 D_L01_001DF478;
extern f32 D_L01_001DF480;
extern f32 D_L01_001DF484;
extern f32 D_L01_001DF488;
extern f32 D_L01_001DF48C;
extern f32 D_L01_001DF490;
extern f32 D_L01_001DF494;
extern f32 D_L01_001DF498;
extern u8 D_L01_001DF49C;
__asm__(".extern D_L01_001DF45C, 4");
__asm__(".extern D_L01_001DF460, 4");
__asm__(".extern D_L01_001DF464, 4");
__asm__(".extern D_L01_001DF468, 4");
__asm__(".extern D_L01_001DF46C, 4");
__asm__(".extern D_L01_001DF470, 4");
__asm__(".extern D_L01_001DF474, 4");
__asm__(".extern D_L01_001DF478, 4");
__asm__(".extern D_L01_001DF47C, 4");
__asm__(".extern D_L01_001DF480, 4");
__asm__(".extern D_L01_001DF484, 4");
__asm__(".extern D_L01_001DF488, 4");
__asm__(".extern D_L01_001DF48C, 4");
__asm__(".extern D_L01_001DF490, 4");
__asm__(".extern D_L01_001DF494, 4");
__asm__(".extern D_L01_001DF498, 4");
__asm__(".extern D_L01_001DF49C, 1");
void func_L01_003D7C60(u8 *m) {
    extern void func_L01_003D6F10(u8 *);
    extern void func_L01_003303B8(void *,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,s32,f32,f32,f32,f32);
    extern void func_L01_004450F0(u8 *,int,int);
    extern s32 func_00382468(s32);
    extern void func_L01_003D79D0(u8 *,void *);
    extern void func_L01_003D76C0(u8 *,void *);
    extern void func_L01_003D7510(u8 *,vu0_v4 *,s32,s32,s32,vu0_v4 *,f32,f32,f32,f32,f32,f32,f32);
    extern s32 func_0038CAD0(void *);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_003C48A8(void *,void *);
    extern f32 func_003824E0(f32,f32);
    extern u8 *func_L01_00301558(void *,void *,f32,f32,s32);
    extern void func_L01_0043B9E8(u8 *,s32,s32,s32);
    extern void func_003C2880(u8 *);
    u8 *p = *(u8 **)(m+0x68);

    u128_t a[4],e;
    u8 *timer;

    u8 *obj;
    switch (m[0x20]) {
    case 0:
        func_L01_003D6F10(m);
        if (!(*(s32 *)(p+0xB4)&0x40))
            func_L01_003303B8(m+0x10,0,2,0,5,0,0,2,0,1,0,0,0,0,0x1010000,0,0x388EF7,0x63F7,0x407FFF,0x20FF,0x8FFF,0x3064FF,0x7F60A0FF,0x280000FF,0x3064FF,0,0.45f,0.0f,0.0f,2.0f);
        func_L01_004450F0(m,1,-1);
        *(s32 *)(p+0xB0)=(D_L01_001DF45C*5+2)/6;
        break;
    case 1: {
        s32 j;
        u8 *q;
        f32 rate,scale;
        j=0;
        timer=p+0xB0;
        q=p+0x20;
        for(;j<8;j++,q+=0x10) {
            if(j<3 && !func_00382468(D_L01_001DF464)) {
                if(!(*(s32 *)(p+0xB4)&0x40) || !func_00382468(2)) {
                    func_L01_003D79D0(m,q);
                    func_L01_003D76C0(m,q);
                }
            }
            rate=D_L01_001DF470;
            scale=2.0f;
            if(p[0xBE]) { rate*=0.7f;scale=0.5f; }
            if(!(*(s32 *)(p+0xB4)&8) && !func_00382468(2)) {
                func_L01_003D7510(m,(vu0_v4 *)q,*(s16 *)(p+0xAC),2,3,(vu0_v4 *)p,D_L01_001DF468,D_L01_001DF46C,rate,scale,0.8f,*(f32 *)(p+0xA8)*D_L01_001DF478,D_L01_001DF474);
            }
        }
        if(func_0038CAD0(timer)) {
            func_L01_004450F0(m,2,-1);
            *(s32 *)(p+0xB0)=(D_L01_001DF460*5+2)/6;
        }
        break;
    }
    case 2: {
        s32 i;
        u8 *q;
        u8 *other;
        f32 rate;
        u8 *pos;
        if(*(s32 *)(p+0xB0)>(D_L01_001DF460*5+2)/6-4) {
            q=(u8 *)&a[0];
            pos=m+0x10;

            a[2]=*(u128_t *)p;
            a[0]=*(u128_t *)(p+0x10);
            func_0038CE90(&a[1],q,&a[2]);
            other=(u8 *)&e;
            qzero(&a[3]);
            func_003C48A8(q,other);
            rate=func_003824E0(D_L01_001DF490,D_L01_001DF494);
            obj=func_L01_00301558(pos,other,rate**(f32 *)(p+0xB8),D_L01_001DF498,D_L01_001DF49C);
            if(obj)func_L01_0043B9E8(obj,D_L01_001DF4A0,D_L01_001DF4A4,D_L01_001DF4A8);
        }
        rate=D_L01_001DF488;
        if(p[0xBE])rate*=1.35f;
        timer=p+0xB0;
        for(i=7;i>=0;i--) {
            if(!func_00382468(D_L01_001DF47C)) {
                if(func_00382468(2))
                    func_L01_003D7510(m,(vu0_v4 *)(m+0x10),*(s16 *)(p+0xAE),2,3,(vu0_v4 *)p,D_L01_001DF480,D_L01_001DF484,rate,0.25f,*(f32 *)(p+0xA4),*(f32 *)(p+0xA8),D_L01_001DF48C);
                else
                    func_L01_003D7510(m,(vu0_v4 *)(m+0x10),*(s16 *)(p+0xAE),2,3,(vu0_v4 *)p,D_L01_001DF480,D_L01_001DF484,rate,0.5f,*(f32 *)(p+0xA4)*0.75f,*(f32 *)(p+0xA8),D_L01_001DF48C);
            }
        }
        if(func_0038CAD0(timer))func_L01_004450F0(m,4,-1);
        break;
    }
    case 3: break;
    case 4: func_003C2880(m);break;
    }
}
/* localdecomp:end func_L01_003D7C60 */
