#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef int s128_3D41E8 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x3C4];
    s16 x3C4;
    s16 x3C6;
    u8 p3C8[8];
    u8 x3D0;
    u8 x3D1;
    u8 x3D2;
    u8 p3D3;
    f32 x3D4;
    f32 x3D8;
    f32 x3DC;
    u8 p3E0[0xC];
    s32 x3EC;
} V_3D41E8;
typedef struct {
    u8 p0[0x10];
    s128_3D41E8 x10;
    u8 p20[3];
    u8 x23;
    u8 p24[0xC];
    u8 x30;
    u8 x31;
    u16 x32;
    u16 x34;
    u8 p36[0x32];
    V_3D41E8 *x68;
    u8 p6C[0x10];
    u16 x7C;
    u8 p7E[0x42];
    u8 xC0[1];
} M_3D41E8;
typedef struct {
    u8 pad0[0x40];
    u8 mtx[0x15];
    u8 alpha;
    u8 pad56[0x60 - 0x56];
} Elem_003D4478;
typedef struct {
    Elem_003D4478 elem[10];
    u8 pad[0x3C4 - 0x3C0];
    s16 h3C4;
    s16 h3C6;
    u8 pad3C8[0x3D0 - 0x3C8];
    u8 mode;
    u8 pad3D1;
    u8 count;
    u8 pad3D3[0x3D8 - 0x3D3];
    f32 w;
    f32 h;
    u8 pad3E0[0x3EC - 0x3E0];
    u32 color;
} Hdr_003D4478;
typedef struct {
    f32 v[4][4];
    u32 color[4];
    f32 uv[8];
    u8 pad[0x20];
} Quad_003D4478;
typedef struct {
    u8 pad[0x68];
    Hdr_003D4478 *data;
} Moby_003D4478;
typedef int u128_3D6FB0 __attribute__((mode(TI)));
struct M_3D6FB0;
typedef struct { struct M_3D6FB0 *arr[15]; s16 h3C; u8 p3E[2]; f32 f40; f32 f44; u8 b48; u8 b49; u8 b4A; u8 b4B; } V_3D6FB0;
typedef struct M_3D6FB0 {
    u8 p0[0x10]; u128_3D6FB0 pos; u8 p20[0x10];
    u8 b30; u8 b31; s16 h32; u8 p34[0x34]; V_3D6FB0 *w68;
} M_3D6FB0;

extern u8 *func_003C24B0(s32,s32);

/* localdecomp:start func_L01_003D7168 */
extern s32 D_L01_001D545C;
void func_L01_003D7168(s32 *kind, u32 *first, u32 *second, s32 *flag) {
    switch (*kind) {
    case 0:
        *first = 0x325C66;
        *second = 0x4C6C74;
        break;
    case 1:
        *first = 0x325C66;
        *second = 0x4C6C74;
        *flag = 0;
        break;
    case 2:
        *first = 0x325C66;
        *second = 0x4C6C74;
        *flag = 1;
        break;
    case 3:
        if (D_L01_001D545C == 41 || D_L01_001D545C == 51 || D_L01_001D545C == 48) {
            *first = 0xF0EBEE;
            *second = 0xF0EBEE;
        } else {
            *first = 0x5786AE;
            *second = 0x2E475C;
        }
        *flag = 0;
        break;
    case 4:
        if (D_L01_001D545C == 41 || D_L01_001D545C == 51 || D_L01_001D545C == 48) {
            *first = 0x312B2A;
            *second = 0x312B2A;
        } else {
            *first = 0x15212B;
            *second = 0x192834;
        }
        *flag = 0;
        break;
    }
}
/* localdecomp:end func_L01_003D7168 */

/* localdecomp:start func_L01_003D7288 */
#include "vu0.h"
extern u8 *D_L01_00221098_003D7288[];
void func_L01_003D7288(u8 *m,void *parent,s32 kind,s32 count,s32 mode,vu0_v4 *direction,f32 speed,f32 lo,f32 hi,f32 rotation,f32 spread) {
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CF68(vu0_v4 *,vu0_v4 *,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_L01_003D7168(s32 *,u32 *,u32 *,s32 *);
    extern u8 *func_L01_00475C60(void *,void *,s32,s32,s32,s32,f32,f32,f32,s32);
    vu0_v4 velocity,axis,temp;
    s32 color1,color2,unused;
    s32 alpha=127;
    s32 cheap;
    s32 color;
    u8 *p=*(u8 **)(m+0x68);
    s32 mask=p[0xBD];
    cheap=func_00382468(3)==0;
    if(cheap) {mode=4;lo*=0.7f;hi*=0.7f;alpha=48;}
    func_L01_003D7168(&mode,(u32 *)&color1,(u32 *)&color2,&unused);
    if(p[0xBE]==0) func_0038CF68(&velocity,direction,speed*0.020000001f);
    else {rotation=0.0f;qzero(&velocity);}
    *(vu0_q *)&axis=0;
    axis.x=1.0f;
    if(count>0) do {
        u8 *particle;
        if(p[0xBE]==0) {
            func_0038CE20(&temp,&axis,func_003824E0(0.2f,spread)*0.020000001f);
            vec_add_ab(&velocity,&temp,&velocity);
        }
        color=func_00382468(2)?color2:color1;
        if(cheap) color|=alpha<<24;
        else color|=p[0xBC]<<24;
        if(m[0x20]==2) mask=0;
        particle=func_L01_00475C60(parent,&velocity,kind,func_00382498(-2,2),color,color&((mask<<24)|0xFFFFFF),lo**(f32 *)(p+0xB8)*210000.0f,hi**(f32 *)(p+0xB8)*210000.0f,rotation,0);
        if(particle) {
            particle[2]=cheap?D_L01_00221098_003D7288[0x61][4]:D_L01_00221098_003D7288[4][0];
            particle[3]=68;
        }
        --count;
    } while(count);
}
/* localdecomp:end func_L01_003D7288 */

/* localdecomp:start func_L01_003D7510 */
#include "vu0.h"
void func_L01_003D7510(u8 *obj,vu0_v4 *point,s32 a,s32 b,s32 c,vu0_v4 *direction,
                       f32 x,f32 y,f32 z,f32 spread,f32 distance,f32 d,f32 e) {
    extern f32 func_003824E0(f32,f32);
    extern void func_00382580(void *,f32,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_L01_003D7288(u8 *,void *,s32,s32,s32,vu0_v4 *,f32,f32,f32,f32,f32);
    vu0_v4 offset,tmp;
    u8 *data=*(u8 **)(obj+0x68);
    qzero(&offset);
    if(data[0xBE]==0) {
        offset.x=func_003824E0(-spread,spread);
        offset.y=func_003824E0(-spread,spread);
        offset.z=func_003824E0(0.0f,distance);
        if(*(u32 *)(data+0xB4)&0x80)offset.y*=0.26249998807907104f;
    } else {
        func_00382580(&offset,-spread,spread);
        func_0038CE20(&tmp,direction,func_003824E0(0.0f,distance));
        vec_add_ab(&offset,&tmp,&offset);
    }
    vec_add_ba(&offset,&offset,point);
    func_L01_003D7288(obj,&offset,a,b,c,direction,x,y,z,d,e);
}
/* localdecomp:end func_L01_003D7510 */

/* localdecomp:start func_L01_003D76C0 */
#include "vu0.h"
typedef struct { s32 a, b, c, d; } Params_003D76C0;
extern f32 D_L01_001DF438, D_L01_001DF43C, D_L01_001DF440, D_L01_001DFB50;
extern s32 D_L01_001DF444, D_L01_001DF448, D_L01_001DF44C, D_L01_001DF450;
extern s32 D_L01_001D545C;
__asm__(".extern D_L01_001DF438,4");
__asm__(".extern D_L01_001DF43C,4");
__asm__(".extern D_L01_001DF440,4");

__asm__(".extern D_L01_001DF444,4");
__asm__(".extern D_L01_001DF448,4");
__asm__(".extern D_L01_001DF44C,4");
__asm__(".extern D_L01_001DF450,4");
void func_L01_003D76C0(u8 *obj, vu0_q *point) {
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_003298C8(void *,void *,s32,s32,s32,u32,void *,s32,s32,s32,f32,f32);
    vu0_v4 velocity;
    vu0_v4 position;
    union {vu0_v4 temp; Params_003D76C0 params;} work;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *particle;
    f32 speed, yaw, tilt, scale;
    u32 color;
    s32 low, cheap;
    *(vu0_q *)&position = *point;
    speed = func_003824E0(3.0f, 5.0f) * 0.020000001415610313f * D_L01_001DF438;
    yaw = func_00382538();
    tilt = func_003824E0(0.4363323152065277f, 0.7853981852531433f);
    func_00382760(&velocity, speed, yaw, tilt);
    if (state[0xBE] == 0) {
        velocity.z = fabs_asm(velocity.z) + func_003824E0(*(f32 *)(state + 0xA4) * 2.75f, *(f32 *)(state + 0xA4) * 3.75f) * 0.020000001415610313f;
    } else {
        func_0038CE20(&work.temp, state, func_003824E0(*(f32 *)(state + 0xA4) * 2.75f, *(f32 *)(state + 0xA4) * 3.75f) * 0.020000001415610313f);
        vec_add_ab(&velocity, &work.temp, &velocity);
    }
    if (*(u32 *)(state + 0xB4) & 0x40) velocity.y *= 0.35f;
    scale = 14.600000381469727f;
    color = 0;
    switch (D_L01_001D545C) {
    case 32:
        color = func_00382468(3) ? 0x96B3B4 : 0x699A9C;
        scale = *(f32 *)(state + 0xA8);
        break;
    case 41: color = func_00382468(3) ? 0x605129 : 0x5A523E; break;
    case 42: color = func_00382468(3) ? 0x263438 : 0x273538; break;
    }
    low = 0;
    work.params = (Params_003D76C0){D_L01_001DF444,D_L01_001DF448,D_L01_001DF44C,D_L01_001DF450};
    cheap = 0;
    if (D_L01_001DFB50 < 0.8f) {
        low = 1;
        if (!(*(u32 *)(state + 0xB4) & 4) && func_00382468(3)) cheap = 1;
    }
    particle = func_L01_003298C8(&position, &velocity, func_00382498(100,125), cheap, low, color, &work.params, 0, 40, 60, 1.0f, scale);
    if (particle) {
        f32 r = func_003824E0(D_L01_001DF43C, D_L01_001DF440);
        *(f32 *)(particle + 0x2C) = *(f32 *)(*(u8 **)(particle + 0x24) + 0x24) * r;
    }
}
/* localdecomp:end func_L01_003D76C0 */

/* localdecomp:start func_L01_003D79D0 */
#include "vu0.h"
extern s32 D_L01_001DF454;
extern s32 D_L01_001DF458;
extern s32 D_L01_001D545C_003D79D0;
extern u8 *D_L01_00221098_003D79D0[];
__asm__(".extern D_L01_001DF454, 4");
__asm__(".extern D_L01_001DF458, 4");
__asm__(".extern D_L01_001D545C_003D79D0, 16");
void func_L01_003D79D0(u8 *obj, void *parent) {
    extern void func_L01_00443B88(void *,f32,f32);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32,s32);
    extern u8 *func_L01_004713C8(void *,void *,s32,s32,s32,s32,s32,f32,f32,f32,s32);
    vu0_v4 velocity, extra;
    s32 i;
    s32 color;
    f32 size, rotation;
    u8 *particle;
    u8 *data=*(u8 **)(obj+0x68);
    for(i=1;i>=0;i--) {
        func_L01_00443B88(&velocity,0.020000001f,0.050000004f);
        if(data[0xBE]==0) {
            velocity.z=fabs_asm(velocity.z)+func_003824E0(*(f32 *)(data+0xA4)*3.5f,*(f32 *)(data+0xA4)*5.25f)*0.020000001f;
        } else {
            func_0038CE20(&extra,data,func_003824E0(*(f32 *)(data+0xA4)*3.5f,*(f32 *)(data+0xA4)*5.25f)*0.020000001f);
            vec_add_ab(&velocity,&extra,&velocity);
        }
        rotation=15.6f;
        size=func_003824E0(0.06f,0.22f);
        color=func_00382468(3)?D_L01_001DF458:D_L01_001DF454;
        switch(D_L01_001D545C_003D79D0) {
        case 32:
            color=func_00382468(3)?0x364E4E:0x688383;
            rotation=*(f32 *)(data+0xA8);
            break;
        case 41: color=func_00382468(3)?0x605129:0x5A523E;break;
        case 42: color=func_00382468(3)?0x263438:0x273538;break;
        }
        particle=func_L01_004713C8(parent,&velocity,(func_00382498(90,150)*5+2)/6,color,-2,127,127,size*210000.0f,size*210000.0f,rotation*0.00040000002f,0);
        if(particle) {
            particle[2]=D_L01_00221098_003D79D0[0x61][func_00382468(3)+10];
            particle[3]=68;
        }
    }
}
/* localdecomp:end func_L01_003D79D0 */

/* localdecomp:start func_L01_003D7C60 */
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
    extern void func_L01_003D7510(u8 *,vu0_v4 *,s32,s32,s32,vu0_v4 *,f32,f32,f32,f32,f32,f32,f32);
    extern s32 func_0038CAD0(void *);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_003C48A8(void *,void *);
    extern f32 func_003824E0(f32,f32);
    extern u8 *func_L01_00301558(void *,void *,f32,f32,s32);
    extern void func_L01_0043B9E8(void *,s32,s32,s32);
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

/* localdecomp:start func_L01_003D80D0 */
typedef int s128_3D80D0 __attribute__((mode(TI)));
typedef struct {
    s128_3D80D0 dir;
    s32 x10;
    s32 x14;
    s32 x18;
    s32 x1C;
    u8 p20[4];
    s32 x24;
    u8 p28[4];
    s32 x2C;
    u8 p30[0x110];
    f32 x140;
    f32 x144;
    f32 x148;
    f32 x14C;
    f32 x150;
    f32 x154;
    f32 x158;
    f32 x15C;
} V_3D80D0;
typedef struct {
    u8 p0[0x10];
    s128_3D80D0 pos;
    u8 p20;
    u8 pad21[2];
    u8 x23;
    u8 p24[8];
    f32 x2C;
    u8 x30;
    u8 x31;
    u16 x32;
    u16 x34;
    u8 p36[0x32];
    V_3D80D0 *x68;
    u8 p6C[0x54];
    u8 xC0[0x10];
    u8 xD0[0x20];
    f32 xF0;
    f32 xF4;
    f32 xF8;
} M_3D80D0;
extern void func_003C5180(void *, void *, s32);
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038DAB8(f32 a, f32 b);
extern void func_0038D308(void *a, void *b);
extern void func_L01_0043B9E8(void *, s32, s32, s32);

/* quantum_whip_wave_spawn: spawns the Quantum Whip cutting wave (class 0x1CB8, 0.5 u/frame, 40 frames) at pos, flying along dir. */
M_3D80D0 *func_L01_003D80D0(void *unused_a0, s128_3D80D0 *pos, f32 *dir) {
    extern void func_0038CF68(void *dst, void *src, f32 s);
    extern f32 func_0038CED8(void *);
    extern s32 func_L01_004C85C8(void *, f32, f32, f32, s32);
    f32 tmp[4];
    f32 scaled[4];
    f32 hdg;
    M_3D80D0 *m;
    V_3D80D0 *v;
    func_003C5180(pos, tmp, 1);
    m = (M_3D80D0 *)func_003C24B0(0x1CB8, 0x200);
    if (m) {
        m->x30 = 0xFF;
        m->x32 = 0xFF;
        m->x31 = 1;
        m->p20 = 0;
        v = m->x68;
        m->pos = *pos;
        *(s128_3D80D0 *)v = *(s128_3D80D0 *)dir;
        m->x2C = 0.1f;
        v->x10 = 0;
        v->x14 = 0x21;
        func_0038CF68(scaled, dir, 1.0f);
        v->x150 = -2.25f;
        v->x2C = -1;
        v->x140 = 2.25f;
        v->x144 = 0;
        v->x148 = 0;
        v->x14C = 1.0f;
        v->x154 = 0;
        v->x158 = 0;
        v->x15C = 1.0f;
        v->x24 = 0;
        hdg = func_0038D160(dir[0], dir[1]);
        m->xF8 = func_0038DAB8(hdg, 1.5707964f);
        m->xF0 = -func_0038D160(func_0038CED8(dir), dir[2]);
        func_0038D308(m->xC0, &m->xF0);
        func_0038CF68(v, v, 0.5f);
        func_0038CF68(m->xD0, m->xD0, 3.0f);
        m->x34 = (m->x34 | 0x100) & 0xFDFF;
        m->x23 = 0x40;
        func_L01_0043B9E8(m, 0, 0, 0);
        v->x1C = func_L01_004C85C8(m, 1.0f, 1.0f, 1.0f, 0);
    }
    return m;
}
/* localdecomp:end func_L01_003D80D0 */

/* localdecomp:start func_L01_003D8298 */
extern f32 D_L01_001DF4AC, D_L01_001DF4B0;
__asm__(".extern D_L01_001DF4AC, 4");
__asm__(".extern D_L01_001DF4B0, 4");
extern u8 *D_L01_00221098[];
extern u8 D_001425C0[];
extern u8 D_001A30B0[];

typedef struct {
    u8 pad0[0x6C];
    f32 damage;
    u8 pad70[0x80];
} Weapon_003D8298;
extern Weapon_003D8298 D_L01_002C5600[];

typedef struct {
    u8 pad0[0xD0];
    u8 active;
    u8 padD1[11];
    u8 *owner;
} SoundRecord_003D8298;

typedef struct {
    vu0_v4 velocity;
    s32 pad10;
    s32 time;
    s32 pad18;
    s32 attachment;
    u8 pad20[12];
    s32 sound;
} State_003D8298;

void func_L01_003D8298(u8 *obj) {
    extern void func_L01_004C8688(s32, void *, void *);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_0038CDF8(void *, void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
    extern void func_L01_00446760(void *, u8 *, s32, void *, f32);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, void *);
    extern s32 func_003A52A0(s32, s32, u8 *);
    extern void func_003A4F28(s32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_004C8668(s32);
    extern void func_003C2880(u8 *);
    extern void func_L01_00404A10(void *, s32);
    extern void func_L01_003D8780();
    f32 previous[4] __attribute__((aligned(16)));
    f32 start[4] __attribute__((aligned(16)));
    f32 end[4] __attribute__((aligned(16)));
    f32 point[4] __attribute__((aligned(16)));
    f32 velocity[4] __attribute__((aligned(16)));
    u8 hit[0x30];
    State_003D8298 *state = *(State_003D8298 **)(obj + 0x68);
    u8 *particle;
    s32 joint, count, next;
    SoundRecord_003D8298 *record;

    *(u128_t *)previous = *(u128_t *)(obj + 0x10);
    func_L01_004C8688(state->attachment, state, 0);
    vec_add_ab(obj + 0x10, state, obj + 0x10);
    if (func_L01_004CB2D8()) {
        func_L01_004CAB30(obj + 0x10, obj + 0x10);
    }

    if (state->time < 25) {
        for (joint = 0; joint < 6; joint++) {
            func_003C2F58(obj, joint, start);
            next = joint + 1;
            func_003C2F58(obj, next, end);
            count = 0;
            do {
                func_0038CDF8(point, start, end, func_003824E0(0.0f, 1.0f));
                func_0038CE20(velocity, state, -0.0400000028f);
                func_003C4C18(velocity, D_L01_001DF4B0 * 0.0200000014f);
                velocity[2] += D_L01_001DF4AC * 0.0200000014f;

                particle = func_L01_004713C8(point, velocity, (func_00382498(3, 6) * 5 + 2) / 6, 0,
                                            (s32)func_L01_00443A18(2.0f, 3.0f), 127, 127,
                                            func_003824E0(0.8f, 0.4f) * 210000.0f, 21000.0f, 0.0f, 6);
                if (particle) {
                    particle[3] = 0x44;
                    particle[2] = D_L01_00221098[0x35][0];
                }
                particle = func_L01_004713C8(point, velocity, (func_00382498(3, 6) * 5 + 2) / 6, 0x7C0030,
                                            (s32)func_L01_00443A18(2.0f, 3.0f), 48, 48,
                                            func_003824E0(0.8f, 0.4f) * 210000.0f * 1.35f, 21000.0f, 0.0f, 0);
                if (particle) {
                    particle[3] = 0x44;
                    particle[2] = D_L01_00221098[0x35][0];
                }
                count--;
            } while (count >= 0);
        }
    }

    *(u128_t *)start = *(u128_t *)state;
    func_0038CE20(start, start, 1.75f);
    start[3] = 5627.9248046875f;
    func_L01_00446760(hit, obj, 0x210000, start, (D_001425C0[0x7F] + D_L01_002C5600)->damage);
    hit[0x19] = 1;
    *(u16 *)(hit + 0x1A) = *(u16 *)(obj + 0xAA);
    hit[0x18] = 0;
    func_003C2F58(obj, 0, end);
    func_003C2F58(obj, 6, point);
    func_003D3CB0(end, point, 0, obj, hit);

    if (state->sound == -1 ||
        (record = (SoundRecord_003D8298 *)(D_001A30B0 + (state->sound << 7)),
         record->owner != obj || !record->active)) {
        state->sound = func_003A52A0(0, 4, obj);
    }
    if (func_0038CAD0(&state->time)) {
        if (state->sound != -1) {
            record = (SoundRecord_003D8298 *)(D_001A30B0 + (state->sound << 7));
            if (record->owner == obj && record->active) {
                func_003A4F28(state->sound);
            }
        }
        state->sound = -1;
        func_L01_004C8668(state->attachment);
        func_003C2880(obj);
    } else if (obj && obj[0x20] != 254 && obj[0x20] != 253) {
        if (!(*(u16 *)(obj + 0x34) & 2)) {
            func_L01_00404A10(func_L01_003D8780, (s32)obj);
        }
    }
}
/* localdecomp:end func_L01_003D8298 */

/* localdecomp:start func_L01_003D8780 */
typedef int s128_3D8780 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x20];
    f32 x20;
    s32 x24;
    s32 x28;
    u8 p2C[4];
    s128_3D8780 x30[8];
    s128_3D8780 xB0[9];
    u8 x140[0x10];
} V_3D8780;
typedef struct {
    u8 p0[0x10];
    s128_3D8780 pos;
    u8 p20[0x48];
    V_3D8780 *x68;
    u8 p6C[0x84];
    u8 xF0[0x10];
} M_3D8780;
typedef struct { f32 x, y, z, w; } P_3D8780;
extern s32 D_L01_001DFB40;
extern P_3D8780 D_L01_001E23A0[4] __attribute__((section(".sdata")));
extern P_3D8780 D_L01_001E23E0[4] __attribute__((section(".sdata")));
extern s32 D_L01_001DF4B4;
extern s32 D_L01_001DF4B8;
extern s32 D_L01_001DF4BC;
__asm__(".extern D_L01_001DF4B4, 4");
__asm__(".extern D_L01_001DF4B8, 4");
__asm__(".extern D_L01_001DF4BC, 4");
extern void func_L01_00447110(void *, void *);
extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, s32, s32, s32, f32);
extern f32 func_L01_004439C0(f32, f32);
extern void func_L01_0043A778(void *, s32, void *);
extern void func_L01_0040E398(void *, void *, void *, f32);
extern void func_L01_0035A218(void *, s32, s32, s32, s32, f32, f32, s32);

void func_L01_003D8780(M_3D8780 *m) {
    V_3D8780 *v = m->x68;
    P_3D8780 a;
    P_3D8780 b;
    P_3D8780 c;
    f32 s0;
    f32 s1;
    s32 i;
    s32 j;
    f32 r;
    P_3D8780 *p;
    P_3D8780 *q;

    v->x20 = (D_L01_001DFB40 % 8) * 0.125f;
    if (v->x20 == 0.0f) {
        v->x24 = (v->x24 + 1) % 8;
        if (v->x28 < 8) {
            v->x28++;
        }
    }
    r = 0.175f;
    func_L01_00447110(&((s128_3D8780 *)v)[v->x24 + 11], m->xF0);
    ((s128_3D8780 *)v)[v->x24 + 3] = m->pos;
    func_L01_00408C98(v->x140, 2, v->x30, v->xB0, v->x24, v->x28, D_L01_001DF4B4, D_L01_001DF4B8, D_L01_001DF4BC, v->x20);
    s0 = func_L01_004439C0(0.03f, 0.05f);
    s1 = func_L01_004439C0(3.0f, 5.0f);
    func_L01_0043A778(m, 0, &a);
    func_L01_0043A778(m, 3, &b);
    func_L01_0043A778(m, 6, &c);
    for (i = 0, p = D_L01_001E23A0; i < 4; i++, p++) {
        func_L01_0040E398(p, &b, &c, i * 0.25f);
        p->x += func_L01_004439C0(-r, r);
        p->y += func_L01_004439C0(-r, r);
        p->z += func_L01_004439C0(-r, r);
    }
    func_L01_0035A218(D_L01_001E23A0, 4, 0x4F, 0x7F7F7F, 0xFF8040, s0, s1, 0);
    for (j = 0; j < 4; j++) {
        q = &D_L01_001E23E0[j];
        func_L01_0040E398(q, &b, &a, j * 0.25f);
        q->x += func_L01_004439C0(-r, r);
        q->y += func_L01_004439C0(-r, r);
        q->z += func_L01_004439C0(-r, r);
    }
    func_L01_0035A218(D_L01_001E23E0, 4, 0x4F, 0x7F7F7F, 0xFF8040, s0, s1, 0);
}
/* localdecomp:end func_L01_003D8780 */

/* localdecomp:start func_L01_003D8B10 */
extern s32 D_L01_001DF4C0;
__asm__(".extern D_L01_001DF4C0, 4");

s32 *func_L01_003D8B10(void *self, s32 a1, s32 *out) {
    if (a1 == 0) {
        *out = 4;
        return &D_L01_001DF4C0;
    }
    return 0;
}
/* localdecomp:end func_L01_003D8B10 */

/* localdecomp:start func_L01_003D8B30 */
extern void func_L01_004450F0(u8 *, int, int);
extern u8 *func_003C24B0(s32, s32);
extern s32 func_00382468(s32);

M_3D6FB0 *func_L01_003D8B30(s32 n, M_3D6FB0 **list, s32 chance, s32 a, s32 b, f32 x, f32 y) {
    M_3D6FB0 *m;
    V_3D6FB0 *v;
    s32 i;
    m = ((M_3D6FB0 * (*)(s32, s32))func_003C24B0)(7383, 80);
    if (m == 0) return 0;
    if (n == 0 || list == 0) return 0;
    if (list[0] == 0) return 0;
    v = m->w68;
    m->h32 = 0xFF;
    m->b30 = 0xFF;
    m->pos = list[0]->pos;
    v->f40 = x;
    v->b48 = a;
    v->b49 = b;
    v->f44 = y;
    v->b4A = 0;
    v->b4B = 0;
    for (i = 0; i < n; i++) {
        if (list[i] != 0 && func_00382468(100) < chance) {
            v->arr[v->h3C] = list[i];
            v->h3C++;
        }
    }
    ((void (*)(M_3D6FB0 *, s32, s32))func_L01_004450F0)(m, 0, -1);
    return m;
}
/* localdecomp:end func_L01_003D8B30 */

LINKER_REMNANT("asm/levels", func_L01_003D8C78);

/* localdecomp:start func_L01_003D8C80 */
#include "vu0.h"
extern f32 D_L01_001DF4C8;
__asm__(".extern D_L01_001DF4C8, 4");
void func_L01_003D8C80(vu0_v4 *pos) {
    extern void func_00382580(void *, f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_L01_00448D88(s32, s32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
    vu0_v4 p, velocity;
    f32 scale;
    s32 first, second, life;
    func_00382580(&p, 0.25f, 0.75f);
    vec_add_ab(&p, &p, pos);
    vec_sub_ba(&velocity, &p, pos);
    func_0038CE20(&velocity, &velocity, func_003824E0(1.0f, 3.0f) * 0.020000001f);
    scale = D_L01_001DF4C8;
    first = func_L01_00448D88(0x4F007FFF, 0);
    second = func_L01_00448D88(0x1F00007F, 0);
    life = func_00382498(17, 29);
    func_L01_00465738(pos, &velocity, first, second, life, 1, -1, -1, 0, scale * 40000.0f);
}
/* localdecomp:end func_L01_003D8C80 */
