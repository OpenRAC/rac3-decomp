/* functional: high. 35 diff vs retail, scheduling only (multiset identical except one move/nop); 22 jals identical; renamed draft's D_L01_00221098_00388AC8 to the catalogue name D_L01_00221098 (same check result); uses fabs_asm and qzero from the shared vu0 header */
#include "common.h"
#include "vu0.h"
typedef struct { u8 pad[0x360]; s32 moving; u8 rest[0x6C0-0x364]; S_38C110v axes[2]; } Hero_00388AC8;
extern Hero_00388AC8 D_001A4BE0;
extern u8 *D_L01_00221098[];
void func_L01_00388AC8(void *unused, s128 *position) {
    extern void func_0038D890(void *,void *,void *,f32);
    extern void func_0038CE20(s128 *,s128 *,f32);
    extern f32 func_003824E0(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_L01_00443A18(f32,f32);
    extern u8 *func_L01_004669B0(void *,s32,void *,f32,f32,f32,f32,s32,s32);
    extern u8 *func_L01_0046A610(void *,void *,s32,s32,s32,s32,f32,f32,f32,f32,f32);
    extern void func_003C4840(void *,void *,f32);
    extern void func_0038D850(void *,void *,void *);
    S_38C110v temp, direction, base, origin, velocity, point, inherited, offset;
    s32 i, kind;
    f32 angle=0.0f;
    u8 *particle;
    *(s128 *)&base=0;
    base.x=0.3f;
    base.y=-1.0f;
    base.w=1.0f;
    *(s128 *)&origin=*position;
    func_0038D890(&base,&D_001A4BE0.axes[0],&D_001A4BE0.axes[1],0.34906584f);
    direction=base;
    qzero(&inherited);
    if(D_001A4BE0.moving)
        func_0038CE20((s128 *)&inherited,(s128 *)((u8 *)&D_001A4BE0+0x110),1.7f);
    func_0038CE20((s128 *)&offset,(s128 *)(&D_001A4BE0.axes[0]),0.4f);
    __asm__("lqc2 $vf1,%1\nlqc2 $vf2,%2\nvadd.xyz $vf1,$vf1,$vf2\nsqc2 $vf1,%0"
      : "=m"(origin) : "m"(origin),"m"(offset) : "vf1","vf2");
    for(i=19;i>=0;i--) {
        angle=func_0038DAB8(angle,func_003824E0(0.0f,0.62831855f));
        func_0038CE20((s128 *)&velocity,(s128 *)&direction,func_003824E0(0.24000001f,0.32000002f));
        __asm__("lqc2 $vf2,%1\nlqc2 $vf1,%2\nvadd.xyz $vf2,$vf2,$vf1\nsqc2 $vf2,%0"
          : "=m"(velocity) : "m"(velocity),"m"(inherited) : "vf1","vf2");
        point.x=origin.x+func_L01_00443A18(0.0f,0.3f);
        point.y=origin.y+func_L01_00443A18(0.0f,0.3f);
        point.z=origin.z+func_L01_00443A18(0.0f,0.3f);
        kind=(s32)func_L01_00443A18(1.0f,2.0f);
        particle=func_L01_004669B0(&point,kind,(u8 *)&D_001A4BE0+0x110,0.0f,1.0f,1.01f,func_003824E0(0.2f,0.75f)*210000.0f,0x7FFFFFFF,0);
        if(particle) {
            u8 *p;
            particle[3]=72;
            *(s16 *)(particle+10)=50;
            p=particle+0x20;
            particle[9]=68;
            *(f32 *)(p+0x1C)=4.0f;
            *(s32 *)(p+4)=3;
            p[10]=48;
            p[11]=particle[10];
        }
        point.x=origin.x+func_L01_00443A18(0.0f,0.6f);
        point.y=origin.y+func_L01_00443A18(0.0f,0.6f);
        point.z=origin.z+func_L01_00443A18(0.0f,0.6f);
        {
            f32 size=func_003824E0(0.2f,1.75f);
            __asm__("lqc2 $vf1,%1\nlqc2 $vf2,%2\nvsub.xyz $vf1,$vf1,$vf2\nsqc2 $vf1,%0"
              : "=m"(point) : "m"(point),"m"(velocity) : "vf1","vf2");
            particle=func_L01_0046A610(&point,&velocity,5,127,0x404040,kind,size*210000.0f,500.0f,0.95f,0.0f,0.0f);
        }
        if(particle) particle[2]=D_L01_00221098[0x5B][1];
        if(fabs_asm(angle)>0.00001f) {
            func_003C4840(&temp,&D_001A4BE0.axes[0],angle);
            func_0038D850(&direction,&base,&temp);
        }
    }
    func_0038CE20((s128 *)&base,(s128 *)(&D_001A4BE0.axes[0]),func_003824E0(8.0f,12.0f)*0.020000001f);
}
