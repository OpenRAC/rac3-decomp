#include "common.h"

/* localdecomp:start func_L07_003E2B80 */
typedef int Q_003E2B80 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003E2B80;
extern V_003E2B80 D_001A4C60;
extern f32 D_L07_001E1ED8[];
extern void func_L01_004450F0(u8 *, s32, s32);
void func_L07_003E2B80(u8 *m) {
    void func_L07_003E2DB0(u8 *);
    extern void func_L07_003E2EC8(u8 *);
    extern void func_L07_003E2F48_003E2B80(u8 *, void *);
    extern void func_L07_003E31F8(u8 *);
    s32 func_00382380(void *, s32, s32);
    f32 func_0038DB00(f32, f32);
    f32 func_0038DAB8(f32, f32);
    f32 func_0038D098(f32);
    f32 func_0038D0B0(f32);
    void func_L07_003E3050(u8 *, void *, f32);
    void func_L07_003E3220(u8 *);
    void func_L01_0044E850(u8 *, void *, s32, f32, f32);
    extern void func_L07_003E3388_003E2B80(u8 *, s32);
    u8 *p;
    V_003E2B80 a, b;
    f32 angle;
    if (m[0x20] == 0) func_L07_003E2DB0(m);
    func_L07_003E2EC8(m);
    if (m[0x31] || (u32)(m[0x20]-3) < 2) {
        p = *(u8 **)(m+0x68);
        switch (m[0x20]) {
        case 1: break;
        case 2:
            func_L07_003E2F48_003E2B80(m,m+0x10);
            func_L07_003E31F8(m);
            if (func_00382380(&D_001A4C60,*(s32 *)(p+0x258),0)) func_L01_004450F0(m,3,-1);
            break;
        case 3:
            angle = func_0038DB00(D_L07_001E1ED8[0],*(f32 *)(p+0x260)*0.017453292f);
            { f32 delta = angle * *(f32 *)(p+0x26C);
            angle = func_0038DAB8(*(f32 *)(p+0x260)*0.017453292f,delta); }
            *(Q_003E2B80 *)&b = 0;
            b.x = *(f32 *)(p+0x264) * func_0038D098(angle);
            b.y = *(f32 *)(p+0x264) * func_0038D0B0(angle);
            b.z = *(f32 *)(p+0x268);
            *(Q_003E2B80 *)&a = *(Q_003E2B80 *)&b;
            { Q_003E2B80 x, y, r;
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(D_001A4C60));
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(y), "j"(x));
            __asm__("sqc2 %1, %0" : "=m"(*(V_003E2B80 *)(p+0x220)) : "j"(r)); }
            func_L07_003E2F48_003E2B80(m,p+0x220);
            func_L07_003E3050(m,p+0xD0,*(f32 *)(p+0xE4));
            if (!func_00382380(&D_001A4C60,*(s32 *)(p+0x258),0)) func_L01_004450F0(m,2,-1);
            break;
        case 4:
            func_L07_003E3220(m);
            break;
        }
        func_L01_0044E850(m,p+0x120,0,0.0432f,0.43200004f);
        func_L01_0044E850(m,p+0x1A0,1,0.0432f,0.43200004f);
        func_L07_003E3388_003E2B80(m,2);
        func_L07_003E3388_003E2B80(m,3);
    }
}
/* localdecomp:end func_L07_003E2B80 */

/* localdecomp:start func_L07_003E2DB0 */
typedef s32 Q_003E2DB0 __attribute__((mode(TI)));
typedef struct { f32 f0,f4,f8,fC,f10,f14,f18,f1C,f20,f24,f28,f2C,f30,f34; u32 flags; } S_003E2DB0;
extern s32 D_L07_001E18B8;
__asm__(".extern D_L07_001E18B8, 16");
void func_L07_003E2DB0(u8 *m) {
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern void func_L07_003E34D8(u8 *);
    u8 *p = *(u8 **)(m+0x68);
    S_003E2DB0 *q;
    *(Q_003E2DB0 *)(p+0x230) = *(Q_003E2DB0 *)(m+0x10);
    *(Q_003E2DB0 *)(p+0x240) = *(Q_003E2DB0 *)(m+0xF0);
    *(Q_003E2DB0 *)(p+0x220) = *(Q_003E2DB0 *)(m+0x10);
    *(f32 *)(p+0x270) = func_00382538();
    *(f32 *)(p+0x278) = func_003824E0(0.041887905448675156f,0.08377581089735031f);
    *(f32 *)(p+0x27C) = func_003824E0(0.35f,0.65f);
    q=(S_003E2DB0 *)(p+0x30);
    D_L07_001E18B8=0;
    q->flags |= 0x414;
    q->f20 = 0.002f;
    q->f24 = 0.002f;
    q->f1C = 0.12566371262073517f;
    q->f14 = 0.0025132743176072836f;
    q->f28 = 0.20000001788139343f;
    q->f18 = 0.0025132743176072836f;
    *(f32 *)(p+0x30) = 2.2f;
    q->f4 = -2.2f;
    func_L07_003E34D8(m);
}
/* localdecomp:end func_L07_003E2DB0 */

/* localdecomp:start func_L07_003E2EC8 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_0038CF68(void *, void *, f32);

void func_L07_003E2EC8(u8 *arg0) {
    u8 *p;
    s32 r;

    p = *(u8 **)(arg0 + 0x68);
    if (arg0[0x20] != 4) {
        r = func_L01_00447490(arg0, -1, 0);
        if (r != 0) {
            func_0038CF68(p + 0x220, (void *)(r + 0x10), 0.50000006f);
            *(s16 *)(p + 0x25C) = 0x2A;
            arg0[0x30] = 0xFF;
            func_L01_004450F0(arg0, 4, -1);
        }
    }
}
/* localdecomp:end func_L07_003E2EC8 */

/* localdecomp:start func_L07_003E2F48 */
extern void func_L01_0045A898(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern f32 func_0038CF38(void *, void *);
extern u8 D_001A4BE0[];

void func_L07_003E2F48(u8 *arg0) {
    u8 *p;
    u8 *q;
    u8 *h;
    f32 t;
    f32 y;
    f32 ang;
    f32 d;

    p = *(u8 **)(arg0 + 0x68);
    q = arg0 + 0xF8;

    *(f32 *)(arg0 + 0x18) = *(f32 *)(arg0 + 0x18) - *(f32 *)(p + 0x274);
    func_L01_0045A898(*(f32 *)(arg0 + 0xF8));
    t = func_0038DAB8(*(f32 *)(p + 0x270), *(f32 *)(p + 0x278));
    *(f32 *)(p + 0x270) = t;
    *(f32 *)(p + 0x274) = func_0038D0B0(t) * *(f32 *)(p + 0x27C);
    y = *(f32 *)(arg0 + 0x18) + *(f32 *)(p + 0x274);
    *(f32 *)(arg0 + 0x18) = y;

    h = D_001A4BE0;
    ang = func_0038D160(*(f32 *)(h + 0x80) - *(f32 *)(arg0 + 0x10),
                        *(f32 *)(h + 0x84) - *(f32 *)(arg0 + 0x14));
    func_L01_00448890(q, p + 0xE4, 0, ang, 0.0025132743f, 0.0025132743f,
                  0.12566371f);

    d = func_0038CF38(arg0 + 0x10, h + 0x80);
    *(f32 *)(p + 0x184) = -func_0038D160(d, *(f32 *)(h + 0x88) - *(f32 *)(arg0 + 0x18));
}
/* localdecomp:end func_L07_003E2F48 */

/* localdecomp:start func_L07_003E3050 */
void func_L07_003E3050(u8 *m, void *v, f32 amount) {
    extern f32 func_0038CE68(void *,void *);
    u8 *vars=*(u8 **)(m+0x68);
    f32 a,b;
    *(f32 *)(m+0xf0)-=(amount*6.0f)*0.035999953746795654f;
    if (func_0038CE68(v,m+0xd0)/0.20000001788139343f<1.0f)
        a=(func_0038CE68(v,m+0xd0)/0.20000001788139343f)*-0.3490658402442932f;
    else a=-0.3490658402442932f;
    *(f32 *)(m+0xf0)=*(f32 *)(m+0xf0)*0.9640000462532043f+a*0.035999953746795654f;
    if (func_0038CE68(v,m+0xc0)/0.20000001788139343f<1.0f)
        b=(func_0038CE68(v,m+0xc0)/0.20000001788139343f)*0.3490658402442932f;
    else b=0.3490658402442932f;
    *(f32 *)(m+0xf4)=*(f32 *)(m+0xf4)*0.9640000462532043f+b*0.035999953746795654f;
    *(f32 *)(vars+0x204)=b*1.5f;
}
/* localdecomp:end func_L07_003E3050 */

/* localdecomp:start func_L07_003E31F8 */
void func_L07_003E31F8(u8 *arg0) {
    f32 k = 0.96400005f;
    *(f32 *)(arg0 + 0xF0) *= k;
    *(f32 *)(arg0 + 0xF4) *= k;
}
/* localdecomp:end func_L07_003E31F8 */

/* localdecomp:start func_L07_003E3220 */
#include "vu0.h"
extern s32 D_L07_001E18B8;
__asm__(".extern D_L07_001E18B8, 4");
void func_L07_003E3220(u8 *arg0) {
    extern f32 func_0038DB48(f32);
    extern s32 func_0038CB00(void *);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern void func_L01_00459C50(s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L03_0043FC00(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_00451E78(void *, s32, f32);
    extern void func_003C2880(void *);
    u8 *p = *(u8 **)(arg0 + 0x68);
    vu0_v4 temp;
    vu0_v4 *position = (vu0_v4 *)(arg0 + 0x10);
    vu0_v4 *velocity = (vu0_v4 *)(p + 0x220);
    *(f32 *)(arg0 + 0xF4) = func_0038DB48(*(f32 *)(arg0 + 0xF4) - 0.3f);
    *(f32 *)(p + 0x228) -= 0.006000000052f;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*position) : "m"(*position), "m"(*velocity) : "vf1", "vf2");
    if (func_0038CB00(p + 0x25C) || func_L01_003FB640(position, 0, arg0, *(f32 *)(p + 0x30))) {
        D_L07_001E18B8++;
        if (D_L07_001E18B8 >= 5) func_L01_00459C50(11);
        func_0038CF68(&temp, velocity, 0.100000009f);
        func_L03_0043FC00(arg0, 31, &temp, 5, 2, 255, 180, 0, 5.0f, 8.0f, 4.0f, 7.0f, -1.0f, -1.0f, 1.0f);
        func_003A52A0(0, 0, arg0);
        func_L01_00451E78(arg0, 1, 0.0f);
        func_003C2880(arg0);
    }
}
/* localdecomp:end func_L07_003E3220 */

/* localdecomp:start func_L07_003E3388 */
typedef int Q_003E3388 __attribute__((mode(TI)));
extern Q_003E3388 D_L07_001DE9C0 __attribute__((section(".sdata")));
__asm__(".extern D_L07_001DE9C0,4");
void func_L07_003E3388(void *arg0,void *arg1) {
    extern void func_003C2EC0(void *,void *,void *);
    extern f32 func_003824E0(f32,f32);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_003C4C18(void *,f32);
    extern void func_L01_0046E078(void *,void *,void *,void *,s32);
    Q_003E3388 matrix[4];
    Q_003E3388 velocity;
    Q_003E3388 position;
    Q_003E3388 *color=&D_L07_001DE9C0;
    s32 i;
    f32 speed;
    func_003C2EC0(arg0,arg1,matrix);
    speed=func_003824E0(0.18000000715255737f,0.24000000953674316f);
    func_0038CE20(&velocity,&matrix[2],-speed);
    for(i=2;i>=0;i--) {
        position=matrix[3];
        func_003C4C18(&position,0.02500000037252903f);
        func_L01_0046E078(arg0,&position,&velocity,color,1);
        color++;
    }
}
/* localdecomp:end func_L07_003E3388 */

/* localdecomp:start func_L07_003E3458 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad0[0x250]; u8 f250[16]; } T_003E3458;
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L07_003E3458(u8 *arg0, s32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    if (((T_003E3458 *)p)->f250[(u8)arg1] != 0) {
        u8 *a24;
        s32 t;

        *(u128_t *)(arg0 + 0x10) = *(u128_t *)(p + 0x230);
        t = *(u16 *)(arg0 + 0x34);
        a24 = *(u8 **)(arg0 + 0x24);
        *(u128_t *)(arg0 + 0xF0) = *(u128_t *)(p + 0x240);
        *(u8 *)(arg0 + 0x30) = 0x40;
        t = t & 0xFFBE;
        *(u16 *)(arg0 + 0x34) = t;
        t = t | (*(u16 *)(a24 + 0x44) & 0x1000);
        *(u16 *)(arg0 + 0x34) = t;
        t = t & 0xFFF9;
        *(s32 *)(arg0 + 0x98) = *(s32 *)(a24 + 0x10);
        *(u16 *)(arg0 + 0x34) = t;
        func_L01_004450F0(arg0, 2, -1);
    }
}
/* localdecomp:end func_L07_003E3458 */

/* localdecomp:start func_L07_003E34D8 */
extern void func_L07_003BB148(void *);
extern void func_L01_004AA7E8(void *, s32);

void func_L07_003E34D8(u8 *arg0) {
    func_L07_003BB148(arg0);
    *(s32 *)(arg0 + 0x98) = 0;
    arg0[0xA8] = 0xFF;
    *(u16 *)(arg0 + 0x34) = (*(u16 *)(arg0 + 0x34) | 0x41) & 0xEFFF;
    func_L01_004AA7E8(arg0, 1);
    *(u16 *)(arg0 + 0x34) |= 6;
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003E34D8 */
