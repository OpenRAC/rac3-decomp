#include "common.h"

/* localdecomp:start func_L20_003F53A8 */
#include "vu0.h"

typedef struct {
    s16 h30;
    s16 h32;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
    s32 i44;
    s32 i48;
    s32 n4C;
} S_003F53A8;

extern vu0_q D_L20_001DF500 __attribute__((section(".sdata")));
__asm__(".extern D_L20_001DF500, 8");
extern f32 D_L20_001DF50C __attribute__((section(".sdata")));
extern S_003F53A8 D_L20_001DF510;
typedef struct { u8 pad[0x188]; u8 *p188; } G_003F53A8;
extern G_003F53A8 D_L20_00220258;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_00404808(void *, void *);
extern void func_L10_00407268(void);

void func_L20_003F53A8(u8 *o, s32 arg1, f32 scale) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    S_003F53A8 s;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    vu0_v4 m[4];
    u8 *p;
    s32 i;

    if (o == 0) {
        return;
    }
    if (D_L20_001DF50C == 9999.0f) {
        D_L20_001DF500 = *(vu0_q *)(o + 0x10);
        D_L20_001DF50C = 0.0f;
    }
    *(vu0_q *)&a = 0;
    a.y = -2.0f;
    *(vu0_q *)&c = 0;
    c.y = 1.0f;
    *(vu0_q *)&b = 0;
    s = D_L20_001DF510;
    func_003C2EC0(o, 0, m);
    func_0038D028(&g, &a, m);
    vec_add_ab(&f, &g, &m[3]);
    func_0038D028(&g, &b, m);
    qzero(&d);
    func_0038D028(&d, &c, m);
    func_0038CF68(&d, &d, func_003824E0(s.f40, s.f3C));
    for (i = 0; i < s.n4C; i++) {
        func_003C4098(&e, &D_L20_001DF500, &f, (f32)i / (f32)s.n4C);
        p = func_L01_00475C60(&e, &d, func_00382498(s.h32, s.h30), 0, s.i44, s.i48,
                              (s32)(scale * (s.f34 + func_003824E0(0.0f, 0.1f)) * 210000.0f),
                              (s32)(scale * s.f38 * 210000.0f), 0.0f, 1);
        if (p != 0) {
            p[9] = 0xF2;
            p[2] = D_L20_00220258.p188[4];
        }
    }
    D_L20_001DF500 = *(vu0_q *)&f;
    if (arg1 != 0) {
        func_L01_00404808(func_L10_00407268, o);
    }
}
/* localdecomp:end func_L20_003F53A8 */

/* localdecomp:start func_L20_003F5688 */
#include "vu0.h"
extern s32 D_L20_001DEBF0;
extern u8 *D_L20_0021E880[];
extern f32 D_001DF4F0_sda;
extern f32 D_001DF4F8_sda;
__asm__(".extern D_001DF4F0_sda, 4");
__asm__(".extern D_001DF4F8_sda, 4");
void func_L20_003F5688(u8 *obj) {
    extern void func_L01_0045BD78(void *,f32,f32,f32,f32);
    extern void func_L01_004450F0(void *,s32,s32);
    extern void func_L01_004AA7E8(void *,s32);
    extern void func_L20_003F53A8(u8 *,s32,f32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_L01_0045A748(void *,void *);
    extern f32 func_0038CF38(void *,void *);
    extern f32 func_0038D160(f32,f32);
    extern void func_L01_0045BD10(void *,f32);
    extern f32 func_0038CE68(void *,void *);
    vu0_v4 point;
    vu0_v4 velocity;
    u8 *p=*(u8 **)(obj+0x68);
    u8 *path;
    u8 *owner;
    u8 *node;
    f32 speed, desired;
    if(obj[0x20]==0) {
        *(s32 *)(p+0x70)=0;
        *(f32 *)(p+0x74)=0.5f;
        *(f32 *)(p+0x78)=0.5f;
        *(f32 *)(p+0x7C)=1.0f;
        *(f32 *)(p+0x80)=0.7853981852531433f;
        *(f32 *)(p+0xA0)=0.3490658402442932f;
        *(f32 *)(p+0x9C)=0.003920000046491623f;
        func_L01_0045BD78(obj,0.01600000075995922f,1.2f,0.0025132743176072836f,0.06283185631036758f);
        *(u32 *)(p+0xA8)|=0x15;
        obj[0x30]=255;
        *(s16 *)(obj+0x32)=500;
        func_L01_004450F0(obj,1,-1);
    }
    if(D_L20_001DEBF0==0) {
        *(s32 *)(obj+0x98)=0;
        *(u16 *)(obj+0x34)=(*(u16 *)(obj+0x34)|0x41)&~0x1000;
        func_L01_004AA7E8(obj,1);
        return;
    }
    *(u16 *)(obj+0x34)&=~0x41;
    owner=*(u8 **)(obj+0x24);
    *(u16 *)(obj+0x34)|=*(u16 *)(owner+0x44)&0x1000;
    *(s32 *)(obj+0x98)=*(s32 *)(owner+0x10);
    if(obj[0x20]==1) {
        func_L20_003F53A8(obj,1,1.0f);
        path=D_L20_0021E880[*(s32 *)(p+0x240)];
        func_0038CF68(&point,obj+0xC0,17.0f);
        vec_add_ab(&point,&point,obj+0x10);
        func_L01_0045A748(obj,&point);
        if(func_0038CF38(obj+0x10,path+((*(s32 *)(p+0x244)<<4)+0x10))<7.0f) {
            ++*(s32 *)(p+0x244);
            if(*(s32 *)(p+0x244)>=*(s32 *)path) *(s32 *)(p+0x244)=0;
        }
        node=path+(*(s32 *)(p+0x244)<<4);
        func_L01_0045BD10(obj,func_0038D160(*(f32 *)(node+0x10)-*(f32 *)(obj+0x10),*(f32 *)(node+0x14)-*(f32 *)(obj+0x14)));
        speed=D_001DF4F0_sda*0.01745329238474369f;
        *(vu0_q *)&velocity=*(vu0_q *)(p+0x110);
        if(func_0038CE68(&velocity,obj+0xD0)/0.6f<1.0f) desired=speed*(func_0038CE68(&velocity,obj+0xD0)/0.6f);
        else desired=speed;
        *(f32 *)(obj+0xF0)=*(f32 *)(obj+0xF0)*(1.0f-D_001DF4F8_sda)+desired*D_001DF4F8_sda;
    }
}
/* localdecomp:end func_L20_003F5688 */
