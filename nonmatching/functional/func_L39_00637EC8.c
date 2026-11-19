/* functional: medium. PAL port of the NTSC-U draft; callees/globals renamed to PAL names. Multiplayer spawn/teleport: sets the player at a position and rotation, resets state and sends a 0x20-byte network packet. */
#include "vu0.h"
typedef union {
    u8 b[8];
    u32 w[2];
    vu0_q q;
    vu0_v4 v;
} Buffer_00637EC8;
typedef struct {
    u8 player, owner, reset, sequence;
    f32 position[3];
    f32 rotation[3];
    s16 state;
    u8 flag, padding;
} Packet_00637EC8;
typedef struct { u8 pad[0x450]; s32 flag; } Global_00637EC8;
extern Global_00637EC8 D_L39_0024DE80[];
extern u8 D_L39_004997E0[];
typedef struct { u8 pad0[0xA4]; u8 flags[0x100]; } Settings_00637EC8;
extern Settings_00637EC8 D_001A5810;
extern u8 D_001A5CD0[];
extern s32 D_L39_002405D0;
__asm__(".extern D_L39_002405D0, 16");
extern void func_L39_0063D240(u8 *, s32);
extern void func_L01_004606A8(void *);
extern void func_0038D328(void *, void *);
extern void func_0038D308(void *, void *);
extern void func_L39_00632180(u8 *, f32 *, s32, f32, f32, f32);
extern void func_L01_0044E740(void *);
extern void func_L39_00622288(u8 *);
extern void func_L39_0063EC78(u8 *);
extern void func_L39_0062B670(u8 *, s32, s32);
extern void func_L39_00630548(u8 *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00412E70(void *, void *, f32, void *, f32);
extern void func_L01_00412FE0(void *, void *, f32, f32);
extern void func_L39_00646B98(u8 *);
extern void func_L39_0057B4C0(s32, s32);
extern void func_L39_005AC128(void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_00637EC8(u8 *hero, vu0_q *position, vu0_q *rotation, s32 state, s32 notify, s32 reset, s32 flag) {
    Buffer_00637EC8 buf;
    Packet_00637EC8 packet;
    f32 saved;
    u32 decoded;
    s32 eq;
    f32 heading;
    f32 *p=(f32 *)position;
    if (hero[0x1A14] && *(s32 *)(hero+0x251C))
        func_L39_0063D240(hero,1);
    if (reset) func_L01_004606A8(*(void **)(hero+0x2534));
    if (p[0]<2.0f || p[0]>1021.0f || p[1]<2.0f || p[1]>1021.0f || p[2]<2.0f || p[2]>1021.0f) {
        if (p[0]<2.0f) p[0]=2.0f;
        if (p[0]>1021.0f) p[0]=1021.0f;
        if (p[1]<2.0f) p[1]=2.0f;
        if (p[1]>1021.0f) p[1]=1021.0f;
        if (p[2]<2.0f) p[2]=2.0f;
        if (p[2]>1021.0f) p[2]=1021.0f;
    }
    *(vu0_q *)(hero+0xA0)=*position;
    *(vu0_q *)(*(u8 **)(hero+0x2524)+0x10)=*position;
    *(vu0_q *)(hero+0xB0)=*rotation;
    func_0038D328(hero+0x20,hero+0xB0);
    func_0038D308(*(u8 **)(hero+0x2524)+0xC0,hero+0xB0);
    *(vu0_q *)(hero+0x1290)=*(vu0_q *)(hero+0x20);
    *(f32 *)(hero+0x11E0)=*(f32 *)(hero+0xB8);
    *(s32 *)(hero+0x1200)=0;
    if (*(f32 *)(hero+0x48)<0.866f) hero[0x1A06]=1;
    func_L39_00632180(hero,(f32 *)(hero+0xE0),1,0.0f,0.0f,0.7f);
    ((void (*)(u8 *))(*(void ***)(hero+0x14))[0x30/4])(hero);
    func_L01_0044E740(hero+0x1630);
    func_L01_0044E740(hero+0x1780);
    *(s16 *)(hero+0x2DE)=1;
    func_L39_00622288(hero);
    func_L39_0063EC78(hero);
    if (state!=-1)
        ((void (*)(u8 *,s32,s32,s32,s32))(*(void ***)(hero+0x14))[0x34/4])(hero,state,1,1,1);
    func_L39_0062B670(hero,(*(u8 **)(hero+0x2524))[0x43],(*(u8 **)(hero+0x2524))[0x41]);
    {
        u8 *q=hero+0x19E6;
        if (*q==0) decoded=0;
        else {
            u32 x,y;
            s32 n,k,m,i;
            u8 *out;
            n=*q;
            k=((u32)q-n)&7;
            m=n+1;
            out=buf.b;
            for (i=0;i<40;i+=5) *out++=D_L39_004997E0[m+((k+i)&7)*255];
            x=buf.w[0]^(u32)q;
            y=buf.w[1]^x;
            buf.w[0]=x;
            buf.w[1]=y;
            decoded=y;
        }
    }
    eq=(decoded==0x11);
    if (eq) D_L39_0024DE80[0].flag=1;
    else D_L39_0024DE80[0].flag=0;
    func_L39_00630548(hero);
    if (func_0038CF00(hero+0xA0,hero+0x260)<1.0f)
        *(vu0_q *)(hero+0xA0)=*(vu0_q *)(hero+0x260);
    saved=*(f32 *)(hero+0x12C0);
    if (D_001A5810.flags[*(s32 *)(hero+0x2544)]==1)
        *(f32 *)(hero+0x132C)=2.0f;
    else *(f32 *)(hero+0x132C)=1.15f;
    func_0038CF68(&buf,hero+0x40,*(f32 *)(hero+0x132C));
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(buf.v) : "m"(buf.v), "m"(*(vu0_v4 *)(hero+0xA0)) : "vf1", "vf2");
    heading=*(f32 *)(hero+0xB8);
    func_L01_00412E70(hero+0x11A0,&buf,heading,*(void **)(hero+0x424),0.0f);
    if (hero[0x1A14]) *(s32 *)(hero+0x12CC)=hero[0x24C9];
    else *(s32 *)(hero+0x12CC)=0;
    *(s32 *)(hero+0x1334)=0;
    *(s32 *)(hero+0x12D8)=*(s32 *)(hero+0x2544);
    if (*(f32 *)(hero+0x48)>0.99f) *(u16 *)(hero+0x1280)|=2;
    else *(u16 *)(hero+0x1280)&=~2;
    func_L01_00412FE0(hero+0x11A0,&buf,*(f32 *)(hero+0xB8),0.0f);
    func_L39_00646B98(hero);
    *(s32 *)(*(u8 **)(hero+0x2530)+0x458)=1;
    *(f32 *)(hero+0x12C0)=saved;
    if (notify && hero[0x1A14])
        func_L39_0057B4C0(*(s32 *)(*(u8 **)(*(u8 **)(hero+0x2530)+0x50)+0x94),1);
    func_L39_005AC128(*(void **)(hero+0x2524));
    if (hero[0x1A14]) {
        u8 *global;
        packet.player=hero[0x2544];
        func_0038CC88(packet.position,position,12);
        func_0038CC88(packet.rotation,rotation,12);
        global=D_001A5CD0;
        packet.reset=reset;
        packet.state=state;
        packet.flag=flag;
        packet.owner=hero[0x1A15];
        packet.sequence=hero[0x44ED];
        if (*(s32 *)(global+0x170)==0) {
            func_0014AD08(global[0x7D4]|0x40,*(s32 *)(global+4),-1,D_L39_002405D0,32,&packet);
        }
        *(f32 *)(hero+0x2538)=*(f32 *)(hero+0xA0);
        *(f32 *)(hero+0x253C)=*(f32 *)(hero+0xA4);
        *(f32 *)(hero+0x2540)=*(f32 *)(hero+0xA8);
    }
}
