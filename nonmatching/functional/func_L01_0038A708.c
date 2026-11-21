/* functional: high. 94 diff, scheduling only (retail multiset equals mine except one lwc1/swc1 pair and a branch form); control flow of the fire/release block and aim constants re-read against the asm; 24 jals identical; the switch falls through from case 0 into case 1 as retail */
#include "common.h"
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
extern f32 D_001DDEA8_sda;
extern f32 D_001DDEAC_sda;
extern f32 D_001DDEB0_sda;
extern f32 D_001DDEB4_sda;
extern u8 *D_001D52FC;
extern s32 D_L01_001E1F10;
extern u8 D_L01_002B3C60[];
extern u8 D_00142637[];
typedef struct { u8 pad0[0x50]; f32 rate; u8 pad54[0xf0-0x54]; } WeaponRow_0038A708;
extern WeaponRow_0038A708 D_L01_002C5600[];
__asm__(".extern D_001DDEA8_sda, 4");
__asm__(".extern D_001DDEAC_sda, 4");
__asm__(".extern D_001DDEB0_sda, 4");
__asm__(".extern D_001DDEB4_sda, 4");
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
    f32 range,speed;
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
            range=10.0f;
            speed=50.0f;
            D_001DDEA8_sda=range;
            goto store_speed;
        }
        goto normal_range;
    }
    range=6.0f;
    if(!D_L01_001D673C) {
normal_range:
        range=12.0f;
    }
    speed=12.5f;
    D_001DDEA8_sda=range;
store_speed:
    D_001DDEB4_sda=speed;
    func_L01_0038AD40(&aim.dir,&pos,target,0,D_001DDEAC_sda,D_001DDEA8_sda,D_001DDEB4_sda*0.0200000014f,D_001DDEB0_sda*0.000400000019f);
    *(s32 *)(vars+0x24)=func_L01_004C7A18(&pos,&aim.dir,vars,vars+0x10,m,0,0,D_001DDEB0_sda*0.000400000019f);
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
                *(f32 *)(vars+0x20)=1.0f / D_L01_002C5600[D_00142637[0]].rate;
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
