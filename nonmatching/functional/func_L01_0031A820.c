/* functional: high. 89 words differ with --no-context (scheduling/stack spills); all 50 quads x 4 verts, uv/color rules, matrix build and call order verified vs retail. Integration: the file's earlier 'extern u8 func_L01_0031A820[]' (before func_L01_0031A7D8) must become a function declaration or the definition is rejected. */
/* PAL near miss (Codex wave 6): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: 89 instruction diff isolated (--no-context), best log build/codex/w291/func_L01_0031A820.04.log; context blocked: earlier extern u8 func_L01_0031A820[] conflicts with function definition (01.log); stack pointer spills and inner loop scheduling remain
 */
#include "common.h"
/* localdecomp:start func_L01_0031A820 */
#include "vu0.h"
typedef struct {
    vu0_v4 vert[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long zero, texture, prim, flags;
} Packet_0031A820;
extern vu0_v4 D_L01_002AD250[];
typedef struct { s16 a, b; } Index_0031A820;
extern Index_0031A820 D_L01_002AC8E0[][4];
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_L01_002ACF30[];
extern vu0_v4 D_L01_002AC2A0[];
extern f32 D_L01_002ACC00[][2];
extern f32 D_L01_002ACC04[][2];
void func_L01_0031A820(u8 *obj) {
    extern unsigned long func_00389598(s32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CE68(void *, void *);
    extern void func_003D2DA0(void *, void *, s32);
    Packet_0031A820 packet;
    vu0_v4 mat[4];
    vu0_v4 dir, pos;
    s32 i,j;
    s32 *vars=*(s32 **)(obj+0x68);
    packet.texture=func_00389598(5);
    packet.prim=0xFF9000000260;
    packet.flags=0x8000000048;
    *(vu0_q *)&mat[0]=*(vu0_q *)(obj+0xC0);
    *(vu0_q *)&mat[1]=*(vu0_q *)(obj+0xD0);
    *(vu0_q *)&mat[2]=*(vu0_q *)(obj+0xE0);
    mat[3].x=*(f32 *)(obj+0x10);
    mat[3].y=*(f32 *)(obj+0x14);
    mat[3].z=*(f32 *)(obj+0x18);
    packet.zero=0;
    mat[3].w=1.0f;
    packet.color[0]=packet.color[1]=packet.color[2]=packet.color[3]=(*vars<<24)|0xFF0000;
    for(i=0;i<50;i++) {
        Index_0031A820 *indices;
        func_0038CE20((f32 *)&pos,(f32 *)&D_L01_002AD250[i],1.0f);
        indices=D_L01_002AC8E0[i];
        func_0038D028(&pos,&pos,mat);
        vec_sub_ab(&dir,&pos,&D_L01_001E29C0);
        func_0038CF68(&dir,&dir,1.0f);
        func_0038D000(&pos,&D_L01_002ACF30[i],mat);
        func_0038CE68(&dir,&pos);
        for(j=0;j<4;j++) {
            s32 a=indices[j].a;
            s32 b=indices[j].b;
            vu0_v4 *v=&D_L01_002AC2A0[a];
            func_0038CE20((f32 *)&packet.vert[j],(f32 *)v,1.0f);
            packet.uv[j][0]=D_L01_002ACC00[b][0];
            packet.uv[j][1]=D_L01_002ACC04[b][0];
            if(v->z==-0.002112f) packet.color[j]=0xFF0000;
        }
        func_003D2DA0(&packet,mat,0);
    }
}
/* localdecomp:end func_L01_0031A820 */
