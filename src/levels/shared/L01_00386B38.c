#include "common.h"

typedef struct {
    u8 pad0[104];
    u8 *inner;
} Obj3899C0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u128_t q[5];
} S_2BEE10;

INCLUDE_ASM("asm/levels", func_L01_00386B38);

INCLUDE_ASM("asm/levels", func_L01_003882A0);

INCLUDE_ASM("asm/levels", func_L01_003884D8);

INCLUDE_ASM("asm/levels", func_L01_003886E8);

INCLUDE_ASM("asm/levels", func_L01_00388AC8);

INCLUDE_ASM("asm/levels", func_L01_00388EE0);

/* localdecomp:start func_L01_00389798 */
typedef struct {
    u8 pad_0[0x10];
    u8 position[0x10];
} ShotVars_389798;
typedef struct {
    u8 pad_0[0x68];
    ShotVars_389798 *vars;
} Moby_389798;

/* The screen warp's timer: 6 frames for an uncharged shot, 27 charged (0x1E1F20 on NTSC-U) */
extern s32 D_L01_001E1EA0;
extern void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d);

/* shock_cannon_warp: the Shock Cannon's screen warp each frame its timer runs: texture 66 at
   5 x the timer; the four floats (1, 0, 0, 0.9) aren't read */
void func_L01_00389798(Moby_389798 *shot) {
    func_L01_00389810(shot->vars->position, 0x42, D_L01_001E1EA0 * 5, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00389798 */

/* localdecomp:start func_L01_003897E8 */
/* The charged lance's beam state (0x1E1F50 on NTSC-U); declared small so its address is one la,
   as retail builds it. */
extern u8 D_L01_001E1ED0[8];
/* The beam's numbers: fade times, half width, texture spacing (0x2B3C90 on NTSC-U) */
extern u8 D_L01_002B3C10[];
extern void func_L01_0040B858(void *beam, void *numbers);

/* shock_cannon_beam_draw: draws the Shock Cannon's charged lance beam with fx_beam_rings:
   texture 69 from the gun 40 u along the aim */
void func_L01_003897E8(void) {
    func_L01_0040B858(D_L01_001E1ED0, D_L01_002B3C10);
}
/* localdecomp:end func_L01_003897E8 */

/* localdecomp:start func_L01_00389810 */
extern s32 D_001D5520;
extern s16 D_001CFEC0[];
extern s32 D_L01_001DDE38;
__asm__(".extern D_L01_001DDE38, 4");
extern s32 D_L01_001DDE40;
__asm__(".extern D_L01_001DDE40, 4");
extern s32 D_L01_001DDE44;
__asm__(".extern D_L01_001DDE44, 4");
extern s32 D_L01_001DDE48;
__asm__(".extern D_L01_001DDE48, 4");
extern s32 D_L01_001DDE4C;
__asm__(".extern D_L01_001DDE4C, 4");
extern s32 D_L01_001DDE50;
__asm__(".extern D_L01_001DDE50, 4");
extern s32 D_L01_001DDE54;
__asm__(".extern D_L01_001DDE54, 4");
extern s32 D_L01_001DDE58;
__asm__(".extern D_L01_001DDE58, 4");
extern s32 D_L01_001DDE5C;
__asm__(".extern D_L01_001DDE5C, 4");
extern s32 D_L01_001DDE60;
__asm__(".extern D_L01_001DDE60, 4");
extern s32 D_L01_001DDE64;
__asm__(".extern D_L01_001DDE64, 4");
extern s32 D_L01_001DDE68;
__asm__(".extern D_L01_001DDE68, 4");
extern s32 D_L01_001DDE6C;
__asm__(".extern D_L01_001DDE6C, 4");
extern s32 D_L01_001DDE70;
__asm__(".extern D_L01_001DDE70, 4");
extern s32 D_L01_001DDE94;
__asm__(".extern D_L01_001DDE94, 4");
extern void func_L01_004C5E28(void);
/* the file's earlier blocks declare it with a 32-bit value; these calls pass the full 64-bit GS register */
extern void func_003A9440(s32, unsigned long);
extern unsigned long func_00389598(s32 a);
extern void func_0038B4D0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, long i, long j);

/* shock_cannon_warp_draw: the screen warp, texture 66 into the frame's alpha in four mirrored quarters, then the frame's copy mixed in */
void func_L01_00389810(void *position, s32 texture, s32 alpha, f32 a, f32 b, f32 c, f32 d) {
    long tex, col;

    func_L01_004C5E28();
    if (D_001D5520 != 0) {
        D_L01_001DDE94 = -1;
        D_L01_001DDE6C = 0xEC;
        D_L01_001DDE70 = 0xF0;
    }
    ((void (*)(s32, long))func_003A9440)(0x47, 0x513F1);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    tex = func_00389598(D_L01_001DDE38);
    col = (s32)((alpha << 24) | 0x7F7F7F);
    func_0038B4D0(0, 0, (s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], 0, -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), (s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(0, D_001CFEC0[0xA9], (s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    func_0038B4D0(D_001CFEC0[0xA8], D_001CFEC0[0xA9], -(s32)((f32)D_001CFEC0[0xA8] * 0.5f), -(s32)((f32)D_001CFEC0[0xA9] * 0.5f), 0, 0, 0xFF, 0xFF, col, tex);
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE44 | ((long)D_L01_001DDE48 << 2) | ((long)D_L01_001DDE4C << 4) | ((long)D_L01_001DDE50 << 6)) | (0x8000L << 24));
    ((void (*)(s32, long))func_003A9440)(0x42, ((long)D_L01_001DDE54 | ((long)D_L01_001DDE58 << 2) | ((long)D_L01_001DDE5C << 4) | ((long)D_L01_001DDE60 << 6)) | (0x8000L << 24));
    func_0038B4D0(0, 0, D_001CFEC0[0xA8], D_001CFEC0[0xA9], D_L01_001DDE64, D_L01_001DDE68, D_L01_001DDE6C, D_L01_001DDE70, D_L01_001DDE40, func_00389598(D_L01_001DDE94));
}
/* localdecomp:end func_L01_00389810 */

INCLUDE_ASM("asm/levels", func_L01_00389B00);

INCLUDE_ASM("asm/levels", func_L01_00389C28);

INCLUDE_ASM("asm/levels", func_L01_0038A0F8);

INCLUDE_ASM("asm/levels", func_L01_0038A4B8);

/* localdecomp:start func_L01_0038A708 */
typedef struct { s32 words[5]; } ParamsA_0038A708;
typedef struct { s32 words[6]; } ParamsB_0038A708;
extern ParamsA_0038A708 D_L01_001DDEB8;
extern ParamsB_0038A708 D_L01_001DDED0;
typedef struct {
    u8 p0[0x1d8]; s32 field1d8;
    u8 p1dc[0x1210-0x1dc]; s32 flags;
    u8 p1214[0x1220-0x1214]; s32 field1220;
    u8 p1224[0x1430-0x1224]; u8 *target;
    u8 p1434[0x25c0-0x1434]; u8 *moby; s32 state;
    u8 p25c8[0x25e9-0x25c8]; u8 flag25e9;
    u8 p25ea[3]; u8 flag25ed;
    u8 p25ee[0x28bc-0x25ee]; s32 cooldown;
} Hero_0038A708;
extern Hero_0038A708 D_001A4BE0;
extern u8 D_L01_001DAFF0;
extern s32 D_001D545C;
extern s32 D_L01_001D673C;
extern f32 D_L01_001DDEA8;
extern f32 D_L01_001DDEAC;
extern f32 D_L01_001DDEB0;
extern f32 D_L01_001DDEB4;
extern u8 *D_001D52FC;
extern s32 D_L01_001E1F10;
extern u8 D_L01_002B3C60[];
extern u8 D_00142637[];
typedef struct { u8 pad0[0x50]; f32 rate; u8 pad54[0xf0-0x54]; } WeaponRow_0038A708;
extern WeaponRow_0038A708 D_L01_002C5600[];
__asm__(".extern D_L01_001DDEA8, 4");
__asm__(".extern D_L01_001DDEAC, 4");
__asm__(".extern D_L01_001DDEB0, 4");
__asm__(".extern D_L01_001DDEB4, 4");
/* nitro_v5_update: the Nitro Launcher V5 moby (class 0x1885): aims at the lock-on target or the nearest one in reach, and fires */
void func_L01_0038A708(u8 *m)
{
    extern void func_003C2F58(u8 *,s32,void *);
    extern void func_L01_00444F38(u8 *,s32,s32,s32,s32);
    extern u8 *func_00382348(u8 *);
    extern s32 func_0038CAD0(s32 *);
    extern u8 *func_L01_004501E8(void *,void *,s32 *,f32,f32,f32,f32,s32,s32,s32,f32,s32,void *,s32,s32,s32);
    extern void func_L01_0038AD40(void *,void *,u8 *,s32,f32,f32,f32,f32);
    extern s32 func_L01_004C7A18(void *,void *,void *,void *,u8 *,s32,s32,f32);
    extern void func_L01_004EAA80(void);
    extern s32 func_L01_005118D0(s32,s32);
    extern void func_L01_004EA7D8(s32);
    extern s32 func_L01_003F2058(void *,s32);
    extern void func_0038D890(f32 *,f32 *,f32 *,f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(f32 *,f32 *,f32);
    extern void func_L01_00362610(void *,void *,u8 *,s32,s32);
    extern void func_003A52A0(s32,s32,u8 *);
    extern s32 func_L01_005119E0(s32);
    extern void func_L01_003F2278(s32,s32);
    extern void func_L01_0040E050(void *);
    extern void func_L01_0038ACE8(Obj3899C0 *);
    extern void func_L01_00404A10(void (*)(Obj3899C0 *),u8 *);
    S_38C110v pos;
    union {
        ParamsA_0038A708 params;
        S_38C110v dir;
    } aim;
    ParamsB_0038A708 params2;
    s32 out0,out1;
    u8 *vars=*(u8 **)(m+0x68);
    u8 *target;
    u8 *check;
    s32 canfire;
    f32 speed,range;
    func_003C2F58(m,0,&pos);
    if(m[0x42]==m[0x43] && (m[0x60]&2))
        func_L01_00444F38(m,1,0,2,0);
    target=0;
    check=D_001A4BE0.target;
    if(check && check[0x20]!=254 && check[0x20]!=253) {
        u8 *state=func_00382348(check);
        if(state && *(f32 *)state>0.0f)
            target=D_001A4BE0.target;
    }
    canfire=1;
    if(D_001A4BE0.state==29 || D_001A4BE0.state==1) {
        if(!func_0038CAD0(&D_001A4BE0.cooldown)) canfire=0;
    } else {
        D_001A4BE0.cooldown=33;
        if(!target) {
            aim.params=D_L01_001DDEB8;
            target=func_L01_004501E8(&pos,(u8 *)&D_001A4BE0+0x6f0,&out0,0.3926990926f,1.5707963705f,11.1000003815f,0.0f,0,0,0,0.0f,0,&aim.params,1,-1,0);
        }
    }
    if(D_L01_001DAFF0 && D_001D545C==5) {
        params2=D_L01_001DDED0;
        target=func_L01_004501E8(&pos,(u8 *)&D_001A4BE0+0x6f0,&out1,0.8726646304f,1.0471975803f,30.0f,0.0f,0,0,0,0.0f,0,&params2,1,-1,0);
        if(target && *(s16 *)(target+0xaa)==0x1a13) {
            /* a 0x1A13 target: range 10, speed 50 */
            D_L01_001DDEA8=10.0f;
            speed=50.0f;
            D_L01_001DDEB4=speed;
            goto aim;
        }
        range=12.0f;
    } else {
        range=6.0f;
        if(!D_L01_001D673C) range=12.0f;
    }
    speed=12.5f;
    D_L01_001DDEA8=range;
    D_L01_001DDEB4=speed;
aim:
    func_L01_0038AD40(&aim.dir,&pos,target,0,D_L01_001DDEAC,D_L01_001DDEA8,D_L01_001DDEB4*0.0200000014f,D_L01_001DDEB0*0.000400000019f);
    *(s32 *)(vars+0x24)=func_L01_004C7A18(&pos,&aim.dir,vars,vars+0x10,m,0,0,D_L01_001DDEB0*0.000400000019f);
    switch(m[0x20]) {
    case 0:
        m[0x20]=1;
        *(s32 *)(vars+0x2c)=-1;
        *(s32 *)(vars+0x20)=0;
        *(s32 *)(vars+0x28)=0;
    case 1:
        if(D_001A4BE0.field1d8>=18) func_L01_004EAA80();
        if(canfire && *(f32 *)(vars+0x20)==0.0f && !D_001A4BE0.flag25ed &&
            (*(s32 *)(D_001D52FC+0x1a0)&D_001A4BE0.flags) && D_001A4BE0.field1220>=19) {
            if(func_L01_005118D0(-1,1)) {
                D_L01_001E1F10=1;
                func_L01_004EA7D8(-1);
                *(s32 *)(vars+0x2c)=func_L01_003F2058(D_L01_002B3C60,0);
                func_L01_00444F38(m,2,0,2,0);
                if(target) func_0038D890((f32 *)&aim.dir,(f32 *)&aim.dir,(f32 *)(D_001A4BE0.moby+0xd0),-0.1745329201f);
                else func_0038D890((f32 *)&aim.dir,(f32 *)&aim.dir,(f32 *)(D_001A4BE0.moby+0xd0),0.0872664601f);
                if(func_0038CEA8(&aim.dir)>0.6f)
                    func_0038CF68((f32 *)&aim.dir,(f32 *)&aim.dir,0.4400000274f);
                func_L01_00362610(&pos,&aim.dir,m,1,0);
                func_003A52A0(0,0,m);
                *(f32 *)(vars+0x20)=1.0f / ((WeaponRow_0038A708 *)(D_00142637[0] * 0xF0 + (s32)D_L01_002C5600))->rate;
            } else if((*(s32 *)(D_001D52FC+0x1a4)&D_001A4BE0.flags) || D_L01_001E1F10==1) {
                func_003A52A0(1,0,m);
                D_L01_001E1F10=0;
            }
            if(!(*(s32 *)(D_001D52FC+0x1a0)&D_001A4BE0.flags) || !func_L01_005119E0(-1) || !D_001A4BE0.flag25e9) {
                if(*(s32 *)(vars+0x2c)>=0) {
                    func_L01_003F2278(*(s32 *)(vars+0x2c),0);
                    *(s32 *)(vars+0x2c)=-1;
                }
            }
        }
        break;
    }
    func_L01_0040E050(vars+0x20);
    func_L01_00404A10(func_L01_0038ACE8,m);
}
/* localdecomp:end func_L01_0038A708 */

/* localdecomp:start func_L01_0038ACE8 */

extern s32 func_L01_005119E0(s32);
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, f32);

void func_L01_0038ACE8(Obj3899C0 *obj) {
    u8 *p = obj->inner;
    if (*(s32 *)(p + 36) == 0) {
        return;
    }
    if (func_L01_005119E0(-1)) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038ACE8 */

INCLUDE_ASM("asm/levels", func_L01_0038AD40);

INCLUDE_ASM("asm/levels", func_L01_0038B280);

/* localdecomp:start func_L01_0038B950 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);
void func_L01_0038B950(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 104);
    if (*(s32 *)(p + 36) != 0) {
        func_L01_004C70A8(p, p + 16, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_0038B950 */

/* localdecomp:start func_L01_0038B988 */
extern void func_L01_0036E578_0038B988();
 
void func_L01_0038B988(void) {
    func_L01_0036E578_0038B988();
}
/* localdecomp:end func_L01_0038B988 */
