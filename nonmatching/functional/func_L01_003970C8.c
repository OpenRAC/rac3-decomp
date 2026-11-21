/* functional: high. 17-word scheduling/colour allocation diff only; Vec4_0039E0C8 typedef is declared later in the owner file, snippet prepends it. */
#include "common.h"
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) Vec4_0039E0C8;
/* localdecomp:start func_L01_003970C8 */
typedef struct { f32 vertices[4][4]; s32 colors[4]; f32 uv[8]; unsigned long zero,texture,alpha,mode; f32 matrix[4][4]; f32 rotation[4]; } Packet_003970C8;
extern f32 D_L01_001E2880[];
void func_L01_003970C8(f32 *position, u32 color, s32 opacity, s32 texture, s32 flags, f32 scale, f32 roll, f32 offset) {
    extern void func_L01_00396FD8(u8 *);
    extern long func_00389598(s32);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038CF38(void *,void *);
    extern void func_0038D328(f32 *,f32 *);
    extern void func_0038CF68(Vec4_0039E0C8 *,Vec4_0039E0C8 *,f32);
    extern void func_L01_00397060(f32 *,f32);
    extern void func_003D2DA0(void *,void *,s32);
    Packet_003970C8 packet;
    vu0_v4 delta;
    func_L01_00396FD8((u8 *)&packet);
    packet.texture=func_00389598(texture);
    packet.mode=((unsigned long)flags<<2)|0x8000000040UL;
    packet.alpha=0xFF9000000260UL;
    color+=opacity<<24;
    packet.colors[0]=packet.colors[1]=packet.colors[2]=packet.colors[3]=color;
    packet.zero=0;
    packet.rotation[3]=0.0f;
    packet.rotation[2]=func_0038D160(D_L01_001E2880[0x140/4]-position[0],D_L01_001E2880[0x144/4]-position[1]);
    packet.rotation[1]=-func_0038D160(func_0038CF38(position,&D_L01_001E2880[0x140/4]),D_L01_001E2880[0x148/4]-position[2]);
    packet.rotation[0]=roll;
    func_0038D328(&packet.matrix[0][0],packet.rotation);
    vec_sub_ba(&delta,&D_L01_001E2880[0x140/4],position);
    func_0038CF68((Vec4_0039E0C8 *)&delta,(Vec4_0039E0C8 *)&delta,offset);
    packet.matrix[3][0]=position[0]+delta.x;
    packet.matrix[3][1]=position[1]+delta.y;
    packet.matrix[3][2]=position[2]+delta.z;
    packet.matrix[3][3]=1.0f;
    func_L01_00397060(&packet.vertices[0][0],scale);
    func_003D2DA0(&packet,&packet.matrix[0][0],0);
}
/* localdecomp:end func_L01_003970C8 */
