/* functional: medium. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 168 words differ in register allocation and partial VU ordering; not byte-identical, behaviour as retail. */
#include "vu0.h"
typedef struct { u8 pad[0x47]; u8 weapon; } State_00321A80;
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_00321A80;
typedef struct {
    f32 vector[4];
    u8 *owner;
    u32 flags;
    u8 kind, subtype;
    u16 class_id;
    f32 damage;
    s32 enabled;
} Hit_00321A80;
extern State_00321A80 D_001425C0;
extern Hero_00321A80 D_001A4BE0;
extern vu0_v4 D_L01_001E29C0;
extern f32 D_001A4EC0[];
extern u8 *D_L01_00221098[];
__asm__(".extern D_L01_001DC940, 4");
void func_L01_00321A80(u8 *self) {
    extern void func_0038CF68(f32 *, s32, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
    extern s32 func_L01_00446780(u8 *, f32 *, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern u8 *func_L01_004669B0(f32, f32, f32, f32, u8 *, s32, f32 *, u32, s32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_00382760(float *, float, float, float);
    extern u8 *func_L01_0046A610(f32 *, u8 *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
    Hit_00321A80 hit;
    vu0_v4 delta;
    f32 velocity[4] __attribute__((aligned(16)));
    f32 position[4] __attribute__((aligned(16)));
    End_00321608 *end;
    G_31DB28 *weapon;
    u8 *particle;
    u8 *vars;
    s32 i, j, spin;
    f32 angle, size, speed, elevation;
    for (i=0; i<D_L01_001DC940; i++) {
        end=&D_L01_00276A30[i];
        hit.owner=self;
        hit.flags=0x410000;
        weapon=&D_L01_002C5600[D_001425C0.weapon];
        hit.damage=weapon->f6C;
        hit.enabled=1;
        __asm__("lqc2 $vf1, %2\n\tlqc2 $vf2, %1\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
          : "=m"(*(vu0_v4 *)hit.vector) : "m"(*(vu0_v4 *)end), "m"(*(vu0_v4 *)(self+0x10)) : "vf1", "vf2");
        func_0038CF68(hit.vector,(s32)hit.vector,0.7f);
        hit.class_id=*(u16 *)(self+0xAA);
        hit.vector[3]=5627.9248046875f;
        hit.kind=1;
        hit.subtype=1;
        if (func_L01_0040E548(self+0x10,end)<3600.0f && func_003D3CB0(self+0x10,end,0,D_001A4BE0.moby,(s32)&hit)) {
            weapon=&D_L01_002C5600[D_001425C0.weapon];
            if (((u8 *)weapon)[1]>=4) {
                func_L01_00446780(self,end->f,0x410000,0,1,0,2.0f,weapon->f6C,0.0f);
            } else {
                func_L01_00446780(self,end->f,0x410000,0,1,0,1.0f,weapon->f6C,0.0f);
            }
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
              : "=m"(delta) : "m"(D_L01_001E29C0), "m"(*(vu0_v4 *)((u8 *)D_L01_001EAA00+0x20)) : "vf1", "vf2");
            angle=func_0038D160(delta.x,delta.y);
            for (j=19;j>=0;j--) {
                func_0038CE20(velocity,D_001A4EC0,-(func_003824E0(0.2f,3.0f)*0.020000001415610313f));
                spin=(s32)func_L01_00443A18(1.0f,2.0f);
                size=func_003824E0(0.3f,0.75f)*210000.0f;
                position[0]=*(f32 *)((u8 *)D_L01_001EAA00+0x20)+func_L01_00443A18(0.0f,0.2f);
                position[1]=*(f32 *)((u8 *)D_L01_001EAA00+0x24)+func_L01_00443A18(0.0f,0.2f);
                position[2]=*(f32 *)((u8 *)D_L01_001EAA00+0x28)+func_L01_00443A18(0.0f,0.2f);
                particle=func_L01_004669B0(0.0f,1.0f,1.01f,size,(u8 *)position,spin,velocity,0x7F202020,0);
                if (particle) {
                    *(s16 *)(particle+0xA)=75;
                    vars=particle+0x20;
                    particle[3]=0x44;
                    particle[9]=0x44;
                    *(f32 *)(vars+0x1C)=4.0f;
                    *(s32 *)(vars+4)=3;
                    vars[0xA]=0x30;
                    vars[0xB]=particle[0xA];
                }
                speed=func_003824E0(1.0f,2.0f);
                elevation=func_003824E0(0.0f,1.3962633609771729f);
                size=func_L01_00443A18(0.0f,1.3962633609771729f);
                func_00382760(velocity,speed*0.020000001415610313f,func_0038DAB8(angle,size),elevation);
                position[0]=*(f32 *)((u8 *)D_L01_001EAA00+0x20)+func_L01_00443A18(0.0f,0.1f);
                position[1]=*(f32 *)((u8 *)D_L01_001EAA00+0x24)+func_L01_00443A18(0.0f,0.1f);
                position[2]=*(f32 *)((u8 *)D_L01_001EAA00+0x28)+func_L01_00443A18(0.0f,0.1f);
                size=func_003824E0(0.25f,0.7f)*210000.0f;
                particle=func_L01_0046A610(position,(u8 *)velocity,25,127,0x7FFF8040,spin,size,500.0f,1.0f,0.0f,0.0f);
                if (particle) particle[2]=D_L01_00221098[0x61][6];
            }
        }
    }
}
