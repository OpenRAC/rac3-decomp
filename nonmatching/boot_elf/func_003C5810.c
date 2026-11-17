/* PAL near miss (Codex wave 6): near miss: 23 words differ with the file's flags.
 * Worker's note: 23 diff in func_003C5810.wrap1.log: fixed default assembler expands the 64-bit constant differently and fills VU store delay slot; global VU load needs pointer addressing under -mno-split-addresses (direct memory form fails assembly). Same 23 diff for ...
 */
#include "common.h"
/* localdecomp:start func_003C5810 */
#include "vu0.h"
typedef int Q_003C5810 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003C5810;
typedef struct { V_003C5810 corners[4]; s32 color[4]; f32 uv[8]; long regs[4]; } Packet_003C5810;
extern V_003C5810 D_222400;
extern V_003C5810 D_001D9180[];
__asm__(".extern D_001D9180,4");
void func_003C5810(void *arg,s32 color,f32 scale,f32 distance) {
    extern long func_00389978(s32);
    extern void func_0038D408(void*,void*,void*);
    extern void func_003D3158(void*,s32,s32);
    Packet_003C5810 packet;
    V_003C5810 axis,delta,right,up,pos,offset;
    V_003C5810 *source=D_001D9180;
    V_003C5810 *dest;
    s32 i;
    *(Q_003C5810*)&axis=0;
    axis.z=1.0f;axis.w=1.0f;
    packet.regs[1]=func_00389978(11);
    *(Q_003C5810*)&pos=*(Q_003C5810*)arg;
    packet.regs[0]=5;
    packet.regs[2]=0xFF9000000260L;
    packet.regs[3]=549755813960L;
    packet.uv[0]=0;packet.uv[1]=0;packet.uv[2]=0;packet.uv[3]=1;
    packet.uv[4]=1;packet.uv[5]=0;packet.uv[6]=1;packet.uv[7]=1;
    __asm__("lqc2 $vf2,0(%1)\n\tlqc2 $vf1,%2\n\tvsub.xyz $vf2,$vf2,$vf1\n\tsqc2 $vf2,%0" : "=m"(delta) : "r"(&D_222400),"m"(pos) : "vf1","vf2");
    func_0038D348((s32)&delta,(s32)&delta,1.0f);
    func_0038D270(&right.x,&delta.x,(s32)&axis);
    func_0038D348((s32)&right,(s32)&right,1.0f);
    func_0038D270(&up.x,&right.x,(s32)&delta);
    func_0038D200(&offset.x,&delta,distance);
    vec_add_ab(&pos,&pos,&offset);
    packet.color[0]=packet.color[1]=packet.color[2]=packet.color[3]=color;
    dest=packet.corners;
    for(i=3;i>=0;i--) {
        func_0038D200(&dest->x,source,scale);
        source++;
        func_0038D408(dest,dest,&delta);
        dest++;
    }
    func_003D3158(&packet,0,0);
}
/* localdecomp:end func_003C5810 */
