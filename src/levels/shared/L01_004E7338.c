#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad[9668];
    s32 a;
    s32 pad2;
    s32 b;
} S_004E5540;
typedef struct {
    u8 pad0[9836];
    f32 arr[32];
    s32 f26EC;
    s32 f26F0;
} G_4E5630;
typedef struct S_4E56A8vec {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} S_4E56A8vec __attribute__((aligned(16)));
typedef struct S_4E56A8c {
    u8 pad0[0x46];
    u8 x46;
} S_4E56A8c;
typedef struct S_4E56A8m {
    u8 pad0[0x10];
    S_4E56A8vec x10;
    u8 pad20[4];
    S_4E56A8c *x24;
} S_4E56A8m;
typedef struct S_4E56A8g {
    u8 pad0[0x80];
    S_4E56A8vec x80;
    u8 pad90[0x2A8];
    f32 x338;
    u8 pad33c[0x2288];
    s32 x25C4;
} S_4E56A8g;
typedef struct S_4E56A8q {
    S_4E56A8vec x0;
    f32 x10;
    f32 x14;
    f32 x18;
} S_4E56A8q;
typedef struct {
    u8 pad0[0x20];
    u8 b20;
    u8 pad21[0x64 - 0x21];
    void (*fn64)(void);
} S_4E8698o;
typedef struct {
    u8 pad0[0x1200];
    S_4E8698o *p0;
    S_4E8698o *p4;
    u8 pad8[0x14 - 0x8];
    s32 w14;
    u8 pad18[0x24 - 0x18];
    s32 w24;
    s32 w28;
} S_4E8698e;
typedef struct {
    u8 pad0[9664];
    s32 unk25C0;
    s32 unk25C4;
    s32 pad25C8;
    s32 unk25CC;
    u8 pad25D0[24];
    u8 unk25E8;
    u8 pad25E9[4];
    u8 unk25ED;
    u8 pad25EE;
    u8 unk25EF;
} S_001A4BE0;
typedef struct M004E9888 {
    u8 pad0[16];
    s128 pos;
    u8 pad20[52 - 32];
    u16 h52;
    u8 pad36[64 - 54];
    u8 b64;
    u8 b65;
    u8 b66;
    u8 b67;
    u8 pad44[88 - 68];
    s32 w88;
    s32 w92;
    u8 pad60[156 - 96];
    s32 w156;
} M004E9888;
typedef struct {
    u8 pad0[128];
    s128 q128;
    u8 pad90[3060 - 144];
    M004E9888 *m3060;
    M004E9888 *m3064;
    M004E9888 *m3068;
    u8 padC00[3076 - 3072];
    f32 f3076;
    u8 padC08[6672 - 3080];
    s32 w6672;
    u8 pad1A14[6688 - 6676];
    M004E9888 *m6688;
    M004E9888 *m6692;
    u8 pad1A28[6736 - 6696];
    M004E9888 *m6736;
    u8 pad1A54[6744 - 6740];
    M004E9888 *m6744;
    u8 pad1A5C[9664 - 6748];
    M004E9888 *m9664;
    s32 w9668;
    u8 pad25C8[9700 - 9672];
    u8 b9700;
    u8 pad25E5[10320 - 9701];
    s32 w10320;
    s32 w10324;
    s16 h10328;
} P004E9888;
typedef struct { u8 pad[0xAA]; s16 t; } S4EA;
typedef struct {
    /* 0x0000 */ u8 pad0[64];
    /* 0x0040 */ u8 v64[64];
    /* 0x0080 */ s128 v128;
    /* 0x0090 */ u8 v144[8];
    /* 0x0098 */ f32 f152;
    /* 0x009C */ u8 pad9c[656 - 156];
    /* 0x0290 */ s32 w656;
    /* 0x0294 */ u8 pad294[5172 - 660];
    /* 0x1434 */ s16 h5172;
    /* 0x1436 */ u8 pad1436[8256 - 5174];
    /* 0x2040 */ s128 hist[32];
    /* 0x2240 */ u8 pad2240[8800 - 8768];
    /* 0x2260 */ f32 f8800;
    /* 0x2264 */ f32 f8804;
    /* 0x2268 */ u8 pad2268[9668 - 8808];
    /* 0x25C4 */ s32 w9668;
    /* 0x25C8 */ u8 pad25c8[9716 - 9672];
    /* 0x25F4 */ u8 b9716;
    /* 0x25F5 */ u8 pad25f5[9836 - 9717];
    /* 0x266C */ f32 fhist[32];
    /* 0x26EC */ s32 w9964;
    /* 0x26F0 */ s32 w9968;
    /* 0x26F4 */ s32 w9972;
    /* 0x26F8 */ s32 w9976;
    /* 0x26FC */ u8 pad26fc[10296 - 9980];
    /* 0x2838 */ f32 f10296;
    /* 0x283C */ f32 f10300;
    /* 0x2840 */ f32 f10304;
} func_004EA708_P;
typedef struct { u8 pad[432]; s32 a; s32 b; } S_004EAA60;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad0[152];
    u8 f98[264];
    f32 f1A0;
    u8 f1A4[4];
    f32 f1A8;
    u8 pad1AC[5380];
    s32 f16B0;
    u8 pad16B4[3893];
    u8 f25E9;
    u8 pad25EA[10];
    u8 f25F4;
} G_004EAFF8;

typedef union {
    s128 q;
    f32 f[4];
} Vec_004E5300;
typedef struct {
    u8 pad0[516];
    s16 f516;
    u8 pad518[616];
    u8 f1134;
    u8 pad1135[545];
    s32 f1680;
    s32 f1684;
    f32 f1688;
    s32 f1692;
    u8 pad1696[12];
    s32 f1708;
    u8 pad1712[7964];
    s32 f9676;
} Game_004E5300;

typedef struct {
    u8 pad0[0xE78];
    u8 *objects[2];
    u32 padp;
    u32 pending;
    u8 pad1[0x25C0 - 0xE88];
    void *resource;
    u8 pad2[0x25E4 - 0x25C4];
    u8 disabled;
    u8 pad3[4];
    u8 enabled;
    u8 pad4;
    u8 active;
    u8 mode;
} S_004EA638;

typedef struct Cap_004EE068 {
    /* 0x000 */ u8 pad0[0x80];
    /* 0x080 */ S_4E56A8vec v80;
    /* 0x090 */ u8 pad90[0x1B8 - 0x90];
    /* 0x1B8 */ s32 f1B8;
    /* 0x1BC */ u8 pad1BC[0x260 - 0x1BC];
    /* 0x260 */ S_4E56A8vec v260;
    /* 0x270 */ f32 top;
    /* 0x274 */ f32 bottom;
    /* 0x278 */ f32 top_target;
    /* 0x27C */ f32 bottom_target;
    /* 0x280 */ f32 radius_target;
    /* 0x284 */ f32 radius;
    /* 0x288 */ f32 radius_vel;
    /* 0x28C */ u8 pad28C[0x2A7 - 0x28C];
    /* 0x2A7 */ u8 wall_hit;
    /* 0x2A8 */ u8 pad2A8[0x360 - 0x2A8];
    /* 0x360 */ s32 f360;
    /* 0x364 */ u8 pad364[0x46E - 0x364];
    /* 0x46E */ u8 f46E;
    /* 0x46F */ u8 pad46F[0x47C - 0x46F];
    /* 0x47C */ s16 f47C;
    /* 0x47E */ u8 pad47E[0x488 - 0x47E];
    /* 0x488 */ f32 f488;
    /* 0x48C */ u8 pad48C[0x1474 - 0x48C];
    /* 0x1474 */ u8 f1474;
    /* 0x1475 */ u8 pad1475;
    /* 0x1476 */ u8 f1476;
    /* 0x1477 */ u8 pad1477[0x25C4 - 0x1477];
    /* 0x25C4 */ s32 move_state;
    /* 0x25C8 */ s32 pad25C8;
    /* 0x25CC */ s32 control_mode;
    /* 0x25D0 */ s32 pad25D0;
    /* 0x25D4 */ s32 prev_control_mode;
    /* 0x25D8 */ u8 pad25D8[0x25E0 - 0x25D8];
    /* 0x25E0 */ s32 f25E0;
    /* 0x25E4 */ u8 vehicle_mode;
} Cap_004EE068;

typedef struct {
    u8 pad0[0xC18];
    f32 plane;
    f32 depth;
} Interval_004EE7F8;

typedef struct MovementView_004EEEC0 {
    u8 pad0[0x3EF];
    u8 alternate;
    u8 pad1[0x25E9 - 0x3F0];
    u8 special;
    u8 pad2[0x2838 - 0x25EA];
    f32 speed;
} MovementView_004EEEC0;

typedef struct {
    u8 pad0[0x1FC];
    s16 h1FC;
    u8 pad1FE[0xC0C - 0x1FE];
    s32 wC0C;
    u8 padC10[0xE80 - 0xC10];
    u8 *overlayE80;
    u8 padE84[0x25C0 - 0xE84];
    u8 *res25C0;
    u8 pad25C4[0x25CC - 0x25C4];
    s32 w25CC;
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 b25E9;
    u8 pad25EA[0x27FC - 0x25EA];
    void *obj27FC;
    u8 pad2800[0x287C - 0x2800];
    s16 h287C;
} G_004E9D40;

typedef struct {
    u8 pad0[0x18];
    s32 category;
    u8 pad1C[0x24 - 0x1C];
    s32 primary;
    s32 held;
    s32 alternate;
    s32 flags;
    u8 pad34[0xF0 - 0x34];
    /* size 0xF0 */
} Def_004EA7D8;
typedef struct {
    u8 first[0x600];
    u8 second[0x600];
} Buf_004EA7D8;

typedef struct {
    u8 pad0[0xE78];
    s32 slots[2];
    s32 padE80;
    s32 cancel;
    u8 padE88[0x1180 - 0xE88];
    s32 idleTimer;
    u8 pad1184[0x15A0 - 0x1184];
    f32 stick;
    u8 pad15A4[0x25C0 - 0x15A4];
    s32 moby;
    s32 pad25C4;
    s32 pad25C8;
    s32 controlMode;
    u8 pad25D0[0x25E9 - 0x25D0];
    u8 active;
    u8 pad25EA;
    u8 flags;
    u8 dual;
    u8 pad25ED[0x2830 - 0x25ED];
    s32 animation;
    s32 item;
    u8 pad2838[0x2874 - 0x2838];
    s16 suppressed;
} Anim_004EA7D8;
typedef struct {
    u8 pad0[8];
    f32 weight;
    u8 pad0C[0x38 - 0xC];
    u8 *first;
    u8 *second;
} Slot_004EA7D8;

/* localdecomp:start func_L01_004E7338 */
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
extern Motion_004E7338 D_L01_002F4540;
void func_L01_004E7338(void)
{
    extern s32 func_L01_004E9308(void);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DB00(f32,f32);
    extern void func_L01_00510CA0(f32,s32,f32,s32,s32,s32);
    extern void func_003C2F58(void *,s32,void *);
    extern f32 func_003824E0(f32,f32);
    extern void func_L01_00467688(void *,void *,f32);
    vu0_q pos;
    f32 x,y;
    void *orient;
    s32 i;
    u8 *m;
    if((*(Hero_004E7338 *)&D_001A4BE0).hand0) {
        D_L01_002F4540.time0=0.01f;
        D_L01_002F4540.time1=0.01f;
    }
    m=(*(Hero_004E7338 *)&D_001A4BE0).hand0;
    if(m && *(s16 *)(m+0xAA)==0xAD) *(f32 *)(m+0x2C)=*(f32 *)(*(u8 **)(m+0x24)+0x24)*0.9f;
    m=(*(Hero_004E7338 *)&D_001A4BE0).hand1;
    if(m && *(s16 *)(m+0xAA)==0xAD) *(f32 *)(m+0x2C)=*(f32 *)(*(u8 **)(m+0x24)+0x24)*0.9f;
    if(func_L01_004E9308()) return;
    if(fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).x)>0.015f || fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).y)>0.015f || fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).rx)>0.017453292f ||
       fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).ry)>0.017453292f || fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).vx)>0.017453292f || fabs_asm((*(Hero_004E7338 *)&D_001A4BE0).vy)>0.017453292f) {
        if((*(Hero_004E7338 *)&D_001A4BE0).mode!=1) {
            Motion_004E7338 *d=&D_L01_002F4540;
            d->outy=-(*(Hero_004E7338 *)&D_001A4BE0).rx;
            d->outy1=-(*(Hero_004E7338 *)&D_001A4BE0).ry;
            x=func_0038D160(0.2f,(*(Hero_004E7338 *)&D_001A4BE0).x)*1.2f;
            y=-func_0038D160(0.2f,(*(Hero_004E7338 *)&D_001A4BE0).y)*1.2f;
            if(x>0.7853982f)x=0.7853982f;
            if(x<-0.17453292f)x=-0.17453292f;
            if(y>0.17453292f)y=0.17453292f;
            if(y<-0.7853982f)y=-0.7853982f;
            d->target0=x;
            d->target1=y;
            d->outx=-func_0038DB00((*(Hero_004E7338 *)&D_001A4BE0).vx,-x);
            d->outx1=-func_0038DB00((*(Hero_004E7338 *)&D_001A4BE0).vy,-y);
        }
    }
    if(!((*(Hero_004E7338 *)&D_001A4BE0).flags&0x80)) {
    if((*(Hero_004E7338 *)&D_001A4BE0).state==3) func_L01_00510CA0(0.021f,1,0.002f,2,1,0);
    if((*(Hero_004E7338 *)&D_001A4BE0).control==4 && (*(Hero_004E7338 *)&D_001A4BE0).phase && (*(Hero_004E7338 *)&D_001A4BE0).phase<10) func_L01_00510CA0(0.016f,1,0.002f,2,0,1);
    if((*(Hero_004E7338 *)&D_001A4BE0).bursts>0 && (*(Hero_004E7338 *)&D_001A4BE0).count) {
        orient=0;
        if((*(Hero_004E7338 *)&D_001A4BE0).flags&1)orient=(*(Hero_004E7338 *)&D_001A4BE0).body+0xC0;
        (*(Hero_004E7338 *)&D_001A4BE0).bursts--;
        func_003C2F58((*(Hero_004E7338 *)&D_001A4BE0).body,22,&pos);
        for(i=0;i<(*(Hero_004E7338 *)&D_001A4BE0).count;i++) {
            f32 r=func_003824E0(-(*(Hero_004E7338 *)&D_001A4BE0).random,(*(Hero_004E7338 *)&D_001A4BE0).random);
            func_L01_00467688(&pos,orient,(*(Hero_004E7338 *)&D_001A4BE0).spread+r);
        }
        func_003C2F58((*(Hero_004E7338 *)&D_001A4BE0).body,23,&pos);
        for(i=0;i<(*(Hero_004E7338 *)&D_001A4BE0).count;i++) {
            f32 r=func_003824E0(-(*(Hero_004E7338 *)&D_001A4BE0).random,(*(Hero_004E7338 *)&D_001A4BE0).random);
            func_L01_00467688(&pos,orient,(*(Hero_004E7338 *)&D_001A4BE0).spread+r);
        }
    }
    } else {(*(Hero_004E7338 *)&D_001A4BE0).bursts=0;}
}
/* localdecomp:end func_L01_004E7338 */

/* localdecomp:start func_L01_004E7780 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern s32 D_001D545C;
typedef struct {
    u8 p0[0x40]; u8 matrix[0x40]; vu0_v4 position; vu0_v4 rotation;
    u8 pA0[0xF0-0xA0]; vu0_v4 velocity;
    u8 p100[0x110-0x100]; vu0_v4 motion;
    u8 p120[0x1D4-0x120]; s32 next_state;
    u8 p1D8[0x210-0x1D8]; s16 timer;
    u8 p212[0x260-0x212]; vu0_v4 capsule;
    u8 p270[0x284-0x270]; f32 radius;
    u8 p288[0x2A4-0x288]; u8 contactA,contactB;
    u8 p2A6[0x2B4-0x2A6]; void *hit_moby;
    u8 p2B8[0x33C-0x2B8]; f32 f33C;
    u8 p340[0x4B0-0x340]; vu0_v4 normal;
    u8 p4C0[0x4CC-0x4C0]; f32 old_heading;
    u8 p4D0[0x4F0-0x4D0]; f32 gravity;
    u8 p4F4[0x528-0x4F4]; s32 disabled;
    u8 p52C[0x25C4-0x52C]; s32 state;
    u8 p25C8[4]; s32 mode;
    u8 p25D0[4]; s32 previous_mode;
    u8 p25D8[8]; s32 third_mode;
    u8 p25E4[0x25F4-0x25E4]; u8 special;
    u8 p25F5[0x285C-0x25F5]; s16 attached;
    u8 kind, blocked; f32 reach;
} Hero_004E7780;
typedef struct { u8 p0[0x18]; void *moby; s32 count; S_4E56A8vec position; u8 p30[16]; S_4E56A8vec normal; } Hit_004E7780;
extern Hit_004E7780 D_L01_001EAA00;
/* hero_detect_wall: opens the wall window: probes along the facing at 3.0 u (1.7 in a wall jump,
 * 0.5 on a material with flag 0x20) and 0.2 u above the feet for a wall steeper than 75 degrees
 * facing the hero within 50 degrees, at most 0.72 u (0.95 in state 17) from the axis; material 15
 * marks wall-jump surfaces. */
void func_L01_004E7780(void) {
    extern f32 func_L01_005114B0(void *);
    extern void func_L01_00511508(Vec4 *, Vec4 *, f32);
    extern void func_L01_00511588(f32 *, f32 *, f32);
    extern void func_L01_00511158(void *,void *,f32);
    /* levels 02 and 09 call their own variant of func_L01_004E8318 here */
    extern s32 func_L01_004E8318_004E7780(void *,void *,s32);
    extern s32 func_L01_004E63F0(s32,f32,f32);
    extern u8 *func_003C4D58(void *);
    extern void func_L01_00511038_004E7780(char *target, f32 magnitude, f32 angle, f32 height, s32 add_position);
    extern s32 func_003D3CB0(void *,void *,s32,s32,s32);
    extern s32 func_003D5630(void);
    extern f32 func_L01_00511848(void *);
    extern void func_0038D028(Vec4 *,void *,void *);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DBA0(f32,f32);
    extern f32 func_0038CF38(S_4E56A8vec *,S_4E56A8vec *);
    extern void func_0038CF68(void *,s32,float);
    vu0_v4 pos;
    vu0_v4 delta;
    Vec4 local_normal;
    u8 *material;
    f32 distance, limit;
    s32 type;
    f32 k17;
    if ((*(Hero_004E7780 *)D_001A4BE0).f33C < 0.4f) return;
    if (func_L01_005114B0(&(*(Hero_004E7780 *)D_001A4BE0).velocity) < -0.40000004f) return;
    if ((*(Hero_004E7780 *)D_001A4BE0).special || D_001D545C == 28) return;
    if ((*(Hero_004E7780 *)D_001A4BE0).disabled) { (*(Hero_004E7780 *)D_001A4BE0).next_state=0; return; }
    *(vu0_q *)&pos=*(vu0_q *)&(*(Hero_004E7780 *)D_001A4BE0).position;
    *(vu0_q *)&delta=*(vu0_q *)&(*(Hero_004E7780 *)D_001A4BE0).motion;
    k17 = 17.0f;
    func_L01_00511508((Vec4 *)&delta,(Vec4 *)&delta,0.0f);
    func_L01_00511588((f32 *)&delta,(f32 *)&delta,k17);
    vec_add_ab(&pos, &pos, &delta);
    func_L01_00511158(&pos,&pos,func_L01_005114B0(&(*(Hero_004E7780 *)D_001A4BE0).velocity)*k17-(*(Hero_004E7780 *)D_001A4BE0).gravity*k17*k17*0.5f);
    if (func_L01_004E8318_004E7780(&pos,&(*(Hero_004E7780 *)D_001A4BE0).rotation,0)) { (*(Hero_004E7780 *)D_001A4BE0).next_state=0;(*(Hero_004E7780 *)D_001A4BE0).timer=19;return; }
    if (!func_L01_004E63F0(0,0.3f,1.0f)) return;
    material=0;
    if (D_L01_001EAA00.moby) material=func_003C4D58(D_L01_001EAA00.moby);
    distance=1.7f;
    if (material && (*(s32 *)(material+0x3C)&0x20)) distance=0.5f;
    else if ((*(Hero_004E7780 *)D_001A4BE0).state!=17 && (!(*(Hero_004E7780 *)D_001A4BE0).contactB || (*(Hero_004E7780 *)D_001A4BE0).contactA)) distance=3.0f;
    func_L01_00511038_004E7780((char *)&pos,0.0f,0.0f,distance,1);
    func_L01_00511038_004E7780((char *)&delta,(*(Hero_004E7780 *)D_001A4BE0).radius+1.4f,0.0f,distance,1);
    if (!func_003D3CB0(&pos,&delta,2,0,0)) return;
    type=func_003D5630();
    if (type==10 || type==12) return;
    (*(Hero_004E7780 *)D_001A4BE0).hit_moby=D_L01_001EAA00.moby;
    if (func_L01_00511848(&D_L01_001EAA00.normal)<1.3089969f /* 75 degrees */) return;
    func_0038D028(&local_normal,&D_L01_001EAA00.normal,(*(Hero_004E7780 *)D_001A4BE0).matrix);
    if (func_0038DBA0(func_0038D160(local_normal.f[0],local_normal.f[1]),3.1415927f)>0.87266463f /* 50 degrees */) return;
    limit=0.72f;
    if ((*(Hero_004E7780 *)D_001A4BE0).state==17) limit=0.95f;
    func_L01_00511038_004E7780((char *)&pos,0.0f,0.0f,0.2f,1);
    func_L01_00511038_004E7780((char *)&delta,(*(Hero_004E7780 *)D_001A4BE0).radius+1.4f,0.0f,0.2f,1);
    if (!func_003D3CB0(&pos,&delta,2,0,0)) return;
    if (func_0038CF38(&D_L01_001EAA00.position,(S_4E56A8vec *)&pos)>limit) return;
    *(vu0_q *)&(*(Hero_004E7780 *)D_001A4BE0).normal=*(vu0_q *)&D_L01_001EAA00.normal;
    (*(Hero_004E7780 *)D_001A4BE0).normal.w=func_0038D160(D_L01_001EAA00.normal.x,D_L01_001EAA00.normal.y);
    (*(Hero_004E7780 *)D_001A4BE0).reach=5.0f;
    *(vu0_q *)&pos=*(vu0_q *)&(*(Hero_004E7780 *)D_001A4BE0).capsule;
    func_0038CF68(&delta,(s32)&D_L01_001EAA00.normal,10.0f);
    vec_add_ab(&delta, &delta, &pos);
    if (func_003D3CB0(&pos,&delta,2,0,0)) (*(Hero_004E7780 *)D_001A4BE0).reach=func_0038CF38((S_4E56A8vec *)&pos,(S_4E56A8vec *)&delta);
    if ((*(Hero_004E7780 *)D_001A4BE0).mode==4 || (*(Hero_004E7780 *)D_001A4BE0).previous_mode==4 || (*(Hero_004E7780 *)D_001A4BE0).third_mode==4) {
        if ((*(Hero_004E7780 *)D_001A4BE0).attached && func_0038DBA0((*(Hero_004E7780 *)D_001A4BE0).old_heading,(*(Hero_004E7780 *)D_001A4BE0).normal.w)<2.9670596f /* 170 degrees */) return;
        (*(Hero_004E7780 *)D_001A4BE0).kind=0;
        if(type==15) (*(Hero_004E7780 *)D_001A4BE0).kind=1;
        else if((*(Hero_004E7780 *)D_001A4BE0).blocked) return;
        if ((*(Hero_004E7780 *)D_001A4BE0).state==17) (*(Hero_004E7780 *)D_001A4BE0).next_state=6;
        else (*(Hero_004E7780 *)D_001A4BE0).next_state=5;
    }
}
/* localdecomp:end func_L01_004E7780 */

/* localdecomp:start func_L01_004E7C88 */
extern void func_L01_004ED658(void);
extern u8 D_001A71C4[];

void func_L01_004E7C88(void) {
    if (D_001A71C4[0] == 3) {
        ((void (*)(s32))func_L01_004ED658)(0);
    }
}
/* localdecomp:end func_L01_004E7C88 */

/* localdecomp:start func_L01_004E7CB8 */
extern u8 D_001A4BE0[];
extern s32 D_00142668[];
extern u8 D_00142CAD[];
extern void func_0038CBA0(void *p, s32 n);
extern void func_L01_004E7C88(void);
extern void func_L01_004DFEA0(s32 damage);
extern void func_L01_005003D0(s32 state, s32 flag);

/* hero_floor_material: reacts to the ground's collision material (the ground probe's
   s16 at hero+0x1470): 1 lava, 3 quicksand, 4 slide, 7, 11, 13, 14 puddle, 0 water, 17
   hazard; sets the surface flags the hero's states read, and changes state when the
   material says so. */
void func_L01_004E7CB8(void) {
    u8 *hero = D_001A4BE0;
    s32 material = *(s16 *)(hero + 0x1470);
    u8 keep = hero[0x147F];
    s32 landed;
    s32 state;
    f32 pz;
    f32 water;
    f32 depth;

    /* clear the material's flags; the material and the byte at 0x147F are kept */
    func_0038CBA0(hero + 0x1470, 16);
    hero[0x147F] = keep;
    *(s16 *)(hero + 0x1470) = material;
    hero[0x25EA] = 0; /* wading */
    *(s16 *)(hero + 0x368) = 0;
    if (hero[0x25EE] != 0) {
        return;
    }
    /* landed: on the ground this frame, or a landing from state 128 */
    landed = 0;
    if (*(s32 *)(hero + 0x360) != 0 || (*(s32 *)(hero + 0x25C4) == 0x80 && *(f32 *)(hero + 0x33C) < 0.4f)) {
        landed = 1;
    }
    if (material == -1) {
        return;
    }

    /* materials 2, 0x11, 0x12: walking slow in some cases */
    if (material == 2 || material == 0x11 || material == 0x12) {
        u8 *h = D_001A4BE0;
        if (*(s16 *)(h + 0x1DE) == 0 && (*(s16 *)(h + 0x36C) == 0 || *(f32 *)(h + 0x33C) < 2.5f)) {
            h[0x1479] = 1;
            if (h[0x25E4] == 0 && D_00142CAD[0] != 0) {
                *(s16 *)(h + 0x368) = 1;
            }
        }
    }

    /* material 17: a hazard hurts him, once per 75 frames, and holds him (state 177) */
    if (material == 0x11) {
        u8 *h = D_001A4BE0;
        if (*(s16 *)(h + 0x1DC) == 0 && *(s16 *)(h + 0x36C) == 0 && *(s32 *)(h + 0x25CC) != 7) {
            func_L01_004DFEA0(D_00142668[0] / 8);
            *(s16 *)(h + 0x1DC) = 75;
            func_L01_005003D0(0xB1, 1);
        }
    }

    /* material 14: a puddle, 0.2 u deep */
    if (material == 0xE) {
        u8 *h = D_001A4BE0;
        h[0x1476] = 1;
        *(f32 *)(h + 0x2848) = 0.2f;
        *(f32 *)(h + 0x350) = *(f32 *)(h + 0x338) + 0.2f;
    }

    /* material 0: water; wading when it is 0.25 to 0.85 u deep */
    if (material == 0) {
        u8 *h = D_001A4BE0;
        depth = *(f32 *)(h + 0x350) - *(f32 *)(h + 0x338);
        *(f32 *)(h + 0x2848) = depth;
        if (depth < 0.85f && 0.25f < depth) {
            h[0x25EA] = 1;
        }
        D_001A4BE0[0x1476] = 1;
    }

    if (material == 3) {
        u8 *h = D_001A4BE0;
        h[0x1478] = 1;
    }
    if (material == 0xB) {
        u8 *h = D_001A4BE0;
        h[0x147D] = 1;
    }
    if (material == 4) {
        u8 *h = D_001A4BE0;
        h[0x1475] = 1;
    }
    if (material == 7) {
        u8 *h = D_001A4BE0;
        h[0x1474] = 1;
    }
    if (material == 0xD) {
        u8 *h = D_001A4BE0;
        h[0x147E] = 1;
    }
    if (material == 1) {
        u8 *h = D_001A4BE0;
        h[0x1477] = material;
    }
    if (material == 8 || material == 0x12) {
        u8 *h = D_001A4BE0;
        h[0x147C] = 1;
    }
    if (material == 0xC) {
        u8 *h = D_001A4BE0;
        h[0x147C] = 1;
    }

    /* material 4: the slide, unless he is in a state that can't slide */
    if (D_001A4BE0[0x1475] != 0 && landed) {
        s32 type = *(s32 *)(D_001A4BE0 + 0x25CC);
        if (type != 0x10 && type != 0x14 && type != 7) {
            func_L01_005003D0(0x30, 1);
            return;
        }
    }

    /* lava */
    if (D_001A4BE0[0x1477] != 0 && landed) {
        u8 *h = D_001A4BE0;
        if (h[0x25E4] == 1 && *(s32 *)(h + 0x25C4) != 0x7F) {
            func_L01_005003D0(0x7F, 1);
            return;
        }
    }
    if (D_001A4BE0[0x1477] != 0 && landed) {
        u8 *h = D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) != 0x38 || h[0x46E] != 0) {
            func_L01_004E7C88();
            if (*(s32 *)(h + 0x2850) != 0) {
                func_L01_005003D0(0x38, 1);
                return;
            }
            if (*(s32 *)(*(u8 **)(*(u8 **)(h + 0x25C0) + 0x24) + 0x1A8) != 0) {
                func_L01_005003D0(0x7E, 1);
                return;
            }
            func_L01_005003D0(0x39, 1);
            return;
        }
    }

    if (D_001A4BE0[0x25E4] == 1) {
        /* critter mode: 0x50 */
        u8 *h = D_001A4BE0;
        if (h[0x147E] != 0 && *(s32 *)(h + 0x25C4) != 0x50) {
            pz = *(f32 *)(h + 0x88);
            water = *(f32 *)(h + 0x350);
            if (fabs_asm(water - (pz + 0.15f)) < 0.5f && 0.0f < water - pz) {
                if (*(f32 *)(h + 0x118) < 0.0f || *(s32 *)(h + 0x25C4) == 0x80) {
                    func_L01_005003D0(0x50, 1);
                    return;
                }
            }
        }
    } else {
        /* other: 0x81 */
        u8 *h = D_001A4BE0;
        if (h[0x147E] != 0 && *(s32 *)(h + 0x25C4) != 0x81) {
            pz = *(f32 *)(h + 0x88);
            water = *(f32 *)(h + 0x350);
            if (fabs_asm(water - (pz + 0.25f)) < 1.0f && 0.0f < water - pz) {
                if (*(f32 *)(h + 0x118) < 0.0f || *(s32 *)(h + 0x25C4) == 0x80) {
                    func_L01_004E7C88();
                    func_L01_005003D0(0x81, 1);
                    return;
                }
            }
        }
    }

    /* quicksand: state 106, or 125 when health is gone (two whole calls: retail merges their
       tails and keeps one `jal`) */
    if (D_001A4BE0[0x1478] != 0 && *(s32 *)(D_001A4BE0 + 0x25C4) != 0x6A && *(s32 *)(D_001A4BE0 + 0x25C4) != 0x7D) {
        u8 *h = D_001A4BE0;
        pz = *(f32 *)(h + 0x88);
        water = *(f32 *)(h + 0x354);
        if (fabs_asm(water - (pz + 0.25f)) < 1.0f && 0.0f < water - pz) {
            if (*(s32 *)(h + 0x25C4) != 0x6B || h[0x46E] != 0) {
                if (*(f32 *)(h + 0x118) < 0.0f || *(s32 *)(h + 0x25C4) == 0x80) {
                    func_L01_004E7C88();
                    if (*(s32 *)(h + 0x2850) == 0) {
                        func_L01_005003D0(0x7D, 1);
                    } else {
                        func_L01_005003D0(0x6A, 1);
                    }
                    return;
                }
            }
        }
    }

    /* material 11: sink in quicksand */
    if (D_001A4BE0[0x147D] != 0) {
        u8 *h = D_001A4BE0;
        state = *(s32 *)(h + 0x25C4);
        if (state != 0x7D && state != 0x79) {
            pz = *(f32 *)(h + 0x88);
            water = *(f32 *)(h + 0x354);
            if (fabs_asm(water - (pz + 0.25f)) < 1.0f && 0.0f < water - pz) {
                if (*(f32 *)(h + 0x118) < 0.0f || state == 0x80) {
                    func_L01_004E7C88();
                    func_L01_005003D0(0x7D, 1);
                }
            }
        }
    }
}
/* localdecomp:end func_L01_004E7CB8 */

/* localdecomp:start func_L01_004E8318 */
/* func_L02_004BDFD8 with the second hero mode (0x25E4 == 1) */

typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    u8 pad20[4];
    f32 f24;
    s32 f28;
    u8 pad2C[8];
    s32 f34;
    void *f38;
} Out_004E8318;

typedef struct {
    vu0_v4 v0;
    u8 pad10[0x10];
    vu0_v4 v20;
    u8 pad30[0xF0 - 0x30];
    vu0_v4 vF0;
    u8 pad100[0x1D0 - 0x100];
    s16 h1D0;
    u8 pad1D2[0x284 - 0x1D2];
    f32 f284;
    u8 pad288[0x2E0 - 0x288];
    vu0_v4 v2E0;
    u8 pad2F0[0x33C - 0x2F0];
    f32 f33C;
    u8 pad340[0x46E - 0x340];
    u8 b46E;
    u8 pad46F[0x500 - 0x46F];
    Out_004E8318 out500;
    u8 pad540[0xC18 - 0x540];
    f32 fC18;
    u8 padC1C[0x25C0 - 0xC1C];
    void *p25C0;
    s32 w25C4;
    u8 pad25C8[4];
    s32 w25CC;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 b25E4;
} G_004E8318;

typedef struct {
    u8 pad0[0x18];
    void *f18;
    u8 pad1C[4];
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
} H_004E8318;

extern G_004E8318 D_001A4BE0_004E8318;
extern H_004E8318 D_L01_001EAA00_004E8318;
extern f32 func_L01_005114B0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D160(f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_L01_00511508(void *, void *, f32);
extern f32 func_L01_00511848(void *);
extern u8 *func_00382348(void *);
extern u8 *func_003C4D58(void *);

/* a += b through VU0 with the sum in a's register, loading a then b */
static __inline__ void addi_ab_004E8318(void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)a) : "j"(qa));
}

/* d = s, a quadword copy */
static __inline__ void vcopy_004E8318(vu0_v4 *d, vu0_v4 *s) {
    *d = *s;
}

/* a -= b through VU0 with the difference in a's register, loading a then b */
static __inline__ void subi_ab_004E8318(void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)a) : "j"(qa));
}

s32 func_L01_004E8318(vu0_v4 *pos, void *arg1, Out_004E8318 *out) {
    G_004E8318 *g;
    s32 flag;
    s32 i;
    s32 j;
    s32 hit;
    s32 r;
    s32 ok;
    void *obj;
    u8 *m;
    u8 *c;
    f32 lo;
    f32 up;
    f32 h;
    f32 w;
    f32 z;
    f32 step;
    f32 lim;
    f32 sc;
    f32 half;
    f32 ang;

    if (out != 0) {
        out->f28 = 0;
    }
    if (D_001A4BE0_004E8318.h1D0 != 0) {
        return 0;
    }
    flag = 0;
    if (D_001A4BE0_004E8318.b25E4 == 0) {
        if ((D_001A4BE0_004E8318.w25CC == 4 &&
             (D_001A4BE0_004E8318.b46E != 0 || func_L01_005114B0(&D_001A4BE0_004E8318.vF0) < 0.0700000077f)) ||
            D_001A4BE0_004E8318.w25CC == 2 || D_001A4BE0_004E8318.w25C4 == 8 || D_001A4BE0_004E8318.w25C4 == 0x19 ||
            D_001A4BE0_004E8318.w25C4 == 0x1A) {
            flag = 1;
        }
        if (D_001A4BE0_004E8318.w25C4 == 0xE && D_001A4BE0_004E8318.fC18 < 37.0f) {
            flag = 0;
        }
    }
    if (D_001A4BE0_004E8318.b25E4 == 1) {
        if ((D_001A4BE0_004E8318.w25CC == 4 && D_001A4BE0_004E8318.b46E != 0) || D_001A4BE0_004E8318.w25CC == 2 ||
            D_001A4BE0_004E8318.w25C4 == 0x4B || D_001A4BE0_004E8318.w25C4 == 0x49 || D_001A4BE0_004E8318.w25C4 == 0x4A) {
            flag = 1;
        }
    }
    if (out != &D_001A4BE0_004E8318.out500) {
        flag = 1;
    }
    if (flag != 0) {
        g = &D_001A4BE0_004E8318;
        lo = -0.7f;
        sc = 0.3f;
        up = 1.5f;
        h = 1.15f;
        z = -1.43f;
        w = 1.8f;
        half = 0.5f;
        if (g->b25E4 == 1) {
            h = 0.7f;
            lo = -0.4f;
            sc = 0.25f;
            w = h;
            up = 0.725f;
            z = -0.71f;
            half = 0.32f;
        }
        {
            vu0_v4 v0;
            vu0_v4 v10;
            vu0_v4 v20;
            vu0_v4 t30;
            vu0_v4 t40;
            vu0_v4 d50;
            vu0_v4 v60;
            vu0_v4 v70;
            vu0_v4 v80;
            vu0_v4 v90;
            vu0_v4 vA0;

            vcopy_004E8318(&v0, pos);
            func_0038CF68(&t40, &g->v0, g->f284);
            vec_add_ba(&v0, &v0, &t40);
            func_0038CF68(&t40, &g->v20, up + 0.15f);
            vec_add_ba(&v10, &v0, &t40);
            func_0038CF68(&t40, &g->v20, -h);
            vec_add_ab(&v20, &v0, &t40);
            hit = 0;
            func_0038CF68(&t30, &g->v0, sc * 0.25f);
            for (i = 0; i < 4; i++) {
                addi_ab_004E8318(&v10, &t30);
                addi_ab_004E8318(&v20, &t30);
                if (func_003D3CB0(&v10, &v20, 4, D_001A4BE0_004E8318.p25C0, 0) != 0) {
                    r = func_003D5630();
                    if (r != 9 && r != 12 && r != 0 &&
                        func_L01_00511848(&D_L01_001EAA00_004E8318.v40) < 0.349065840f) {
                        hit = 1;
                    }
                }
                if (hit) {
                    break;
                }
            }
            obj = 0;
            if (hit) {
                f32 d;

                if (D_L01_001EAA00_004E8318.f18 != 0) {
                    ok = 0;
                    m = func_00382348(D_L01_001EAA00_004E8318.f18);
                    c = func_003C4D58(D_L01_001EAA00_004E8318.f18);
                    if (m != 0 && (*(u16 *)(m + 0x1E) & 1)) {
                        ok = 1;
                    } else if (c != 0) {
                        ok = *(s32 *)(c + 0x3C) & 1;
                    }
                    if (!ok) {
                        return 0;
                    }
                    obj = D_L01_001EAA00_004E8318.f18;
                }
                if (out != 0) {
                    out->f38 = D_L01_001EAA00_004E8318.f18;
                }
                vcopy_004E8318(&v60, &D_L01_001EAA00_004E8318.v20);
                vec_sub_ba(&d50, &v60, pos);
                if (up < func_L01_005114B0(&d50)) {
                    return 0;
                }
                func_0038CF68(&v70, &D_001A4BE0_004E8318.v20, 0.005f);
                addi_ab_004E8318(&v70, &v60);
                func_0038CF68(&v80, &D_001A4BE0_004E8318.v0, -1.0f);
                addi_ab_004E8318(&v80, &v70);
                if (func_003D3CB0(&v80, &v70, 2, D_001A4BE0_004E8318.p25C0, 0) != 0 &&
                    (D_L01_001EAA00_004E8318.f18 == 0 || D_L01_001EAA00_004E8318.f18 != obj)) {
                    return 0;
                }
                if (out != 0) {
                    func_0038CF68(&v90, &D_001A4BE0_004E8318.v20, 0.6f);
                    addi_ab_004E8318(&v90, &v60);
                    if (func_L01_003FB640(&v90, 4, D_001A4BE0_004E8318.p25C0, 0.45f) != 0) {
                        out->f34 |= 1;
                    } else {
                        out->f34 &= ~1;
                    }
                }
                d = func_L01_005114B0(&d50);
                if (d + D_001A4BE0_004E8318.f33C < w) {
                    return 0;
                }
                if (d < 0.5f) {
                    return 0;
                }
                {
                    vu0_v4 vB0 = {1.0f, 0.0f, lo};
                    vu0_v4 vC0;
                    vu0_v4 vD0;
                    vu0_v4 vE0;
                    vu0_v4 vF0;
                    vu0_v4 v100;
                    vu0_v4 v110;
                    vu0_v4 v120;
                    vu0_v4 v130;
                    s32 found;
                    f32 t;

                    func_0038D000(&vB0, &vB0, &D_001A4BE0_004E8318.v0);
                    found = 0;
                    vec_add_ba(&vB0, &vB0, &v60);
                    vec_sub_ab(&v90, pos, &vB0);
                    func_L01_00511508(&v90, &v90, 0.0f);
                    addi_ab_004E8318(&v90, &vB0);
                    func_0038CF68(&vA0, &D_001A4BE0_004E8318.v20, -lo / 5.0f);
                    for (j = 0; j < 5; j++) {
                        if (func_003D3CB0(&v90, &vB0, 2, 0, 0) != 0) {
                            func_0038CF68(&vC0, &D_L01_001EAA00_004E8318.v40, 1.0f);
                            found = 1;
                            func_L01_00511508(&vC0, &vC0, 0.0f);
                            break;
                        }
                        addi_ab_004E8318(&v90, &vA0);
                        addi_ab_004E8318(&vB0, &vA0);
                    }
                    if (!found) {
                        return 0;
                    }
                    if (!(func_0038CE68(&D_001A4BE0_004E8318.v0, &vC0) < func_0038D098(1.13446403f))) {
                        return 0;
                    }
                    vcopy_004E8318(&v120, &v60);
                    step = 0.03f;
                    func_0038CF68(&v110, &D_001A4BE0_004E8318.v2E0, -0.05f);
                    func_0038CF68(&v100, &vC0, step);
                    lim = 2.4f;
                    t = 0.0f;
                    vec_add_ba(&vF0, &v100, &v110);
                    subi_ab_004E8318(&v100, &v110);
                    vec_add_ab(&vD0, &v120, &v100);
                    vec_add_ab(&vE0, &v120, &vF0);
                    do {
                        if (func_003D3CB0(&vE0, &vD0, 4, D_001A4BE0_004E8318.p25C0, 0) == 0) {
                            if (out != 0) {
                                vcopy_004E8318(&out->v10, &v120);
                                func_0038CF68(&v130, &vC0, half);
                                func_0038CF68(&out->v0, &D_001A4BE0_004E8318.v2E0, -z);
                                vec_add_ba(&out->v0, &v130, &out->v0);
                                vec_add_ab(&out->v0, &out->v10, &out->v0);
                                out->f24 = func_0038D160(vC0.x, vC0.y);
                                out->f28 = 1;
                            }
                            return 1;
                        }
                        t += step;
                        vcopy_004E8318(&v120, &D_L01_001EAA00_004E8318.v20);
                        vec_add_ab(&vE0, &v120, &vF0);
                        vec_add_ab(&vD0, &v120, &v100);
                    } while (t < lim);
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L01_004E8318 */
