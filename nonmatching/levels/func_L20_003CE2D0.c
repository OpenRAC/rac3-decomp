/* PAL near miss (Codex wave 8): near miss: 16 words differ with the file's flags.
 * Worker's note: 16/137 differing words; w428/func_L20_003CE2D0.try5.log; all remaining differences are frame/saved-register offsets (0x120 vs retail 0x150); no artificial stack padding added
 */
#include "common.h"
/* localdecomp:start func_L20_003CE2D0 */
#include "vu0.h"
typedef struct {
    vu0_v4 points[4];
    u32 colors[4];
    f32 uv[8];
    u8 pad70[0x18];
    unsigned long state;
} Packet_003CE2D0;
extern s32 D_001DEB00_sda;
__asm__(".extern D_001DEB00_sda, 4");
extern f32 D_L20_001E2E80[];
extern vu0_v4 D_001A4EC0;
extern vu0_v4 D_L20_001D7C50[];
void func_L20_003CE2D0(u8 *m, f32 scale) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003A9440(s32, unsigned long);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_00389478(void *, void *, void *);
    Packet_003CE2D0 packet;
    vu0_v4 matrix[4], offset;
    s32 i;
    vu0_v4 *src, *dst;
    func_003D93B0(&packet,D_001DEB00_sda,1,0x80);
    packet.state=0x800000004AUL;
    *(vu0_q *)&matrix[3]=*(vu0_q *)(m+0x10);
    packet.colors[0]=packet.colors[1]=packet.colors[2]=packet.colors[3]=0x80808080;
    packet.uv[0]=0.0f; packet.uv[1]=0.0f;
    packet.uv[2]=0.0f; packet.uv[3]=1.0f;
    packet.uv[4]=1.0f; packet.uv[5]=0.0f;
    packet.uv[6]=1.0f; packet.uv[7]=1.0f;
    vec_sub_ab(&matrix[0],D_L20_001E2E80,&matrix[3]);
    func_0038CF68(&matrix[0],&matrix[0],1.0f);
    func_0038CE90(&matrix[1],&matrix[0],&D_001A4EC0);
    func_0038CF68(&matrix[1],&matrix[1],1.0f);
    func_0038CE90(&matrix[2],&matrix[1],&matrix[0]);
    func_0038CE20(&offset,&matrix[0],0.05f);
    vec_add_ab(&matrix[3],&matrix[3],&offset);
    src=D_L20_001D7C50;
    dst=packet.points;
    for(i=3;i>=0;i--) {
        func_0038CE20(dst,src,scale);
        src++;
        func_0038D028(dst,dst,&matrix[0]);
        dst++;
    }
    func_003A9440(0x47,0x31001);
    func_003D2DA0(&packet,0,0);
    {
        s32 j;
        for(j=0;j<4;j++) {
            func_00389478(&packet.points[j], &packet.uv[2*j], &packet.uv[2*j+1]);
        }
    }
    func_003D93B0(&packet,-1,1,0x80);
    packet.state=0x2000000054UL;
    func_003D2DA0(&packet,0,0);
    func_003A9440(0x47,0x5360B);
}
/* localdecomp:end func_L20_003CE2D0 */
