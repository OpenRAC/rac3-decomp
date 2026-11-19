/* functional: high. 67 diff = register/scheduling only; verified arg order (pos,color,alpha,texture,settings,size,roll,length), packet offsets and matrix translation w=1.0 */
#include "common.h"
typedef unsigned int U64_00392130 __attribute__((mode(DI)));
typedef struct { f32 vertices[16]; u32 color[4]; f32 uv[8]; U64_00392130 mode, texture, flags, settings; } Packet_00392130;
typedef struct { u8 pad[0x140]; f32 pos[4]; } Camera_00392130;
typedef struct { f32 f[4]; } __attribute__((aligned(16))) Vector_00392130;
extern Camera_00392130 D_L01_001E2880;
void func_L01_00392130(f32 *pos,s32 color,s32 alpha,s32 texture,U64_00392130 settings,f32 size,f32 roll,f32 length) {
    extern void func_L01_00392040(u8 *p);
    extern U64_00392130 func_00389598(s32);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038CF38(f32 *,f32 *);
    extern void func_0038D328(f32 *,f32 *);
    extern void func_0038CF68(void *out,void *in,f32 length);
    extern void func_L01_003920C8(f32 *m,f32 s);
    extern void func_003D2DA0(void *,void *,s32);
    Packet_00392130 packet;
    f32 matrix[16];
    Vector_00392130 angles;
    Vector_00392130 delta;
    U64_00392130 tex;
    func_L01_00392040((u8 *)&packet);
    tex=func_00389598(texture);
    packet.settings=((U64_00392130)settings<<2)|(((U64_00392130)0x8000<<24)|0x40);
    packet.flags=(((U64_00392130)0xFF90<<32)|0x260);
    packet.color[0]=color+(alpha<<24);
    packet.color[3]=color+(alpha<<24);
    packet.color[2]=color+(alpha<<24);
    packet.color[1]=color+(alpha<<24);
    packet.texture=tex;
    packet.mode=0;
    angles.f[3]=0;
    angles.f[2]=func_0038D160(D_L01_001E2880.pos[0]-pos[0],D_L01_001E2880.pos[1]-pos[1]);
    angles.f[1]=-func_0038D160(func_0038CF38(pos,D_L01_001E2880.pos),D_L01_001E2880.pos[2]-pos[2]);
    angles.f[0]=roll;
    func_0038D328(matrix,angles.f);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "m"(*(Vector_00392130 *)D_L01_001E2880.pos), "m"(*(Vector_00392130 *)pos) : "vf1","vf2");
    func_0038CF68(&delta,&delta,length);
    matrix[12]=pos[0]+delta.f[0];
    matrix[13]=pos[1]+delta.f[1];
    matrix[14]=pos[2]+delta.f[2];
    matrix[15]=1.0f;
    func_L01_003920C8((f32 *)&packet,size);
    func_003D2DA0(&packet,matrix,0);
}
