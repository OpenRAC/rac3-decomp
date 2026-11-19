/* functional: high. Draws a 57-vertex/42-quad environment-mapped object (a rotating model drawn through the packet routine): transforms vertices by a matrix built from the object, if the object is within 16 units of camera it computes reflection UVs per vertex, then submits each back-facing-culled quad. COP2 lqc2/vsub.xyz/sqc2 kept as the small vector-library asm (vu0.h); every offset/gp load/loop bound re-read against the asm. */
#include "vu0.h"
typedef struct { u128_t vertices[4]; u32 colors[4]; f32 uv[4][2]; unsigned long zero, texture, prim, mode; } Packet_0030D388;
typedef struct { u8 pad[0x140]; vu0_v4 position; } Camera_0030D388;
extern Camera_0030D388 D_L19_001E1F40[];
extern vu0_v4 D_L19_001E2080[];
extern vu0_v4 D_L19_0026DD40[], D_L19_002AA0F0[], D_L19_002AAB90[], D_L19_002AAF20[], D_L19_002AA8F0[];
extern f32 D_L19_0026DB70[][2], D_L19_002AA720[][2];
extern s16 D_L19_002AA480[][4][2];
extern f32 D_001DC608_sda;
extern s32 D_001DC600_sda, D_001DC5F0_sda, D_001DC5EC_sda, D_001DC5F4_sda, D_001DC5F8_sda, D_001DC5FC_sda;
extern u32 D_001DC604_sda;
void func_L19_0030D388(u8 *object) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern unsigned long func_00389598(s32);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_0030D388 packet;
    vu0_v4 matrix[4];
    vu0_v4 view, face, normal, reflected;
    s32 close = 0;
    s32 i,j;
    f32 scale = *(f32 *)(object+0x2c) / *(f32 *)(*(u8 **)(object+0x24)+0x24);
    func_0038CF68(&matrix[0], object+0xc0, scale);
    func_0038CF68(&matrix[1], object+0xd0, scale);
    func_0038CF68(&matrix[2], object+0xe0, scale);
    matrix[3].x=*(f32 *)(object+0x10);
    matrix[3].y=*(f32 *)(object+0x14);
    matrix[3].z=*(f32 *)(object+0x18);
    matrix[3].w=1.0f;
    if (fabs_asm(D_L19_001E1F40[0].position.x-matrix[3].x)<16.0f && fabs_asm(D_L19_001E1F40[0].position.y-matrix[3].y)<16.0f) close=1;
    if (close) {
        f32 (*uv)[2] = D_L19_0026DB70;
        for(i=0;i<57;i++) {
            f32 denominator, x, y;
            func_0038D028(&D_L19_0026DD40[i],&D_L19_002AA0F0[i],matrix);
            __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(view) : "m"(D_L19_0026DD40[i]),"m"(D_L19_001E2080[0]) : "vf1","vf2");
            func_0038CF68(&view,&view,1.0f);
            func_0038D028(&normal,&D_L19_002AAB90[i],matrix);
            func_0038CF68(&normal,&normal,D_001DC608_sda);
            scale=func_0038CE68(&normal,&view);
            func_0038CE20(&reflected,&normal,scale+scale);
            __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(reflected) : "m"(view),"m"(reflected) : "vf1","vf2");
            func_0038CF68(&reflected,&reflected,1.0f);
            x=reflected.x;
            y=reflected.y;
            reflected.z+=1.0f;
            denominator=sqrt_asm(reflected.z+reflected.z);
            denominator+=denominator;
            (*uv)[1]=y/denominator+0.5f;
            (*uv)[0]=x/denominator+0.5f;
            uv++;
        }
    } else {
        for(i=0;i<57;i++) func_0038D028(&D_L19_0026DD40[i],&D_L19_002AA0F0[i],matrix);
    }
    packet.texture=func_00389598(D_001DC600_sda);
    packet.prim=0xff9000000260UL;
    packet.mode=(unsigned long)(long)D_001DC5EC_sda | ((unsigned long)(long)D_001DC5F0_sda<<2) | ((unsigned long)(long)D_001DC5F4_sda<<4) | ((unsigned long)(long)D_001DC5F8_sda<<6) | ((unsigned long)(long)D_001DC5FC_sda<<32);
    packet.zero=0;
    packet.colors[0]=packet.colors[1]=packet.colors[2]=packet.colors[3]=D_001DC604_sda;
    for(i=0;i<42;i++) {
        func_0038D028(&face,&D_L19_002AAF20[i],matrix);
        __asm__("lqc2 $vf2,%1\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(view) : "m"(face),"m"(D_L19_001E2080[0]) : "vf1","vf2");
        func_0038CF68(&view,&view,1.0f);
        func_0038D000(&face,&D_L19_002AA8F0[i],matrix);
        if (!(func_0038CE68(&view,&face)>0.0f)) {
            for(j=0;j<4;j++) {
                s32 v=D_L19_002AA480[i][j][0];
                packet.vertices[j]=*(u128_t *)&D_L19_0026DD40[v];
                if(close) {
                    packet.uv[j][0]=D_L19_0026DB70[v][0];
                    packet.uv[j][1]=D_L19_0026DB70[v][1];
                } else {
                    s32 uv=D_L19_002AA480[i][j][1];
                    packet.uv[j][0]=D_L19_002AA720[uv][0];
                    packet.uv[j][1]=D_L19_002AA720[uv][1];
                }
            }
            func_003D2DA0(&packet,0,0);
        }
    }
}
