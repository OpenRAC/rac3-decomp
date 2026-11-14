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

extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern f32 func_00388800(S_4E56A8vec *a, S_4E56A8vec *b);
extern u8 D_001A4BE0[];
extern f32 func_003BEBF8(f32 *, f32, f32);
typedef struct { u8 *m; s32 keep; f32 target; f32 out; } E_4E9C08;
extern u8 D_001A4BE0[];
extern f32 func_003BEBF8(f32 *, f32, f32);
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
extern u8 D_001A4BE0[];
/* localdecomp:start func_L01_004EA298 */
extern u8 D_001A4BE0[];
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_00445168(f32 *, f32 *, f32, f32, f32, f32);

/* Sets the hero collision capsule's target top, bottom and radius from the vehicle mode and move
 * state, then eases the current values toward them (or snaps to them when a0 is nonzero). */
void func_L01_004EA298(s32 a0) {
    switch ((*(Cap_004EE068 *)&D_001A4BE0).vehicle_mode) {
    case 0:
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.8f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.7f;
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.45f;
        break;
    case 1:
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.55f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.45f;
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.25f;
        break;
    case 3:
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.8f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.6f;
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.45f;
        break;
    }
    if ((*(Cap_004EE068 *)&D_001A4BE0).control_mode == 4) {
        if ((*(Cap_004EE068 *)&D_001A4BE0).f47C < (*(Cap_004EE068 *)&D_001A4BE0).f1B8 &&
            !(*(Cap_004EE068 *)&D_001A4BE0).f46E)
            (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = (*(Cap_004EE068 *)&D_001A4BE0).f488;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).move_state == 6) {
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.5f;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).move_state == 4) {
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.3500000238418579f;
    } else if ((u32)((*(Cap_004EE068 *)&D_001A4BE0).control_mode - 17) < 2) {
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.0f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.0f;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).f1474 && (*(Cap_004EE068 *)&D_001A4BE0).f360) {
        (*(Cap_004EE068 *)&D_001A4BE0).top_target = 0.8f;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom_target = 0.9f;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).move_state == 129) {
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.8f;
    } else if ((*(Cap_004EE068 *)&D_001A4BE0).move_state == 80) {
        (*(Cap_004EE068 *)&D_001A4BE0).radius_target = 0.5f;
    }
    if (a0 != 0) {
        (*(Cap_004EE068 *)&D_001A4BE0).top = (*(Cap_004EE068 *)&D_001A4BE0).top_target;
        (*(Cap_004EE068 *)&D_001A4BE0).bottom = (*(Cap_004EE068 *)&D_001A4BE0).bottom_target;
        (*(Cap_004EE068 *)&D_001A4BE0).radius = (*(Cap_004EE068 *)&D_001A4BE0).radius_target;
    }
    if (!(*(Cap_004EE068 *)&D_001A4BE0).wall_hit ||
        (*(Cap_004EE068 *)&D_001A4BE0).prev_control_mode == 18 ||
        (*(Cap_004EE068 *)&D_001A4BE0).f25E0 == 18 ||
        ((*(Cap_004EE068 *)&D_001A4BE0).vehicle_mode == 0 && (*(Cap_004EE068 *)&D_001A4BE0).bottom < 0.53f) ||
        (*(Cap_004EE068 *)&D_001A4BE0).control_mode == 17 ||
        (*(Cap_004EE068 *)&D_001A4BE0).f1476 ||
        func_00388800(&(*(Cap_004EE068 *)&D_001A4BE0).v260, &(*(Cap_004EE068 *)&D_001A4BE0).v80) >
            (*(Cap_004EE068 *)&D_001A4BE0).radius * 0.5f) {
        func_003BEBF8(&(*(Cap_004EE068 *)&D_001A4BE0).top, (*(Cap_004EE068 *)&D_001A4BE0).top_target, 0.02f);
        func_003BEBF8(&(*(Cap_004EE068 *)&D_001A4BE0).bottom, (*(Cap_004EE068 *)&D_001A4BE0).bottom_target, 0.02f);
        func_L01_00445168(&(*(Cap_004EE068 *)&D_001A4BE0).radius, &(*(Cap_004EE068 *)&D_001A4BE0).radius_vel,
                          (*(Cap_004EE068 *)&D_001A4BE0).radius_target, 0.02f, 0.3f, 0.0666666701f);
    }
}
/* localdecomp:end func_L01_004EA298 */
