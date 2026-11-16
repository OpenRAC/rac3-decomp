/* PAL near miss (Codex wave 8): near miss: 6 words differ with the file's flags.
 * Worker's note: 6 instruction diffs, no size delta; build/codex/w436/func_L01_00392F08.04.log. Retail interleaves EE call arguments between vadd and sqc2; required single VU sequence is opaque, shared j helpers require unavailable fixed-file vf flag; volatile variants worsen ...
 */
#include "common.h"
/* localdecomp:start func_L01_00392F08 */
#include "vu0.h"
typedef struct { f32 p[4][4]; s32 color[4]; f32 uv[4][2]; unsigned long zero, texture, fixed, flags; } Packet_00392F08;
extern s32 D_001DE018_sda, D_001DE008_sda, D_001DE004_sda, D_001DE00C_sda, D_001DE010_sda, D_001DE014_sda, D_001DE01C_sda;
extern f32 D_001DE020_sda;
typedef struct { s16 vertex, uv; } Index_00392F08;
extern Index_00392F08 D_L01_002B7070[][4];
extern f32 D_L01_002B6B70[][4], D_L01_002B7470[][2];
__asm__(".extern D_001DE018_sda, 4");
__asm__(".extern D_001DE008_sda, 4");
__asm__(".extern D_001DE004_sda, 4");
__asm__(".extern D_001DE00C_sda, 4");
__asm__(".extern D_001DE010_sda, 4");
__asm__(".extern D_001DE014_sda, 4");
__asm__(".extern D_001DE01C_sda, 4");
__asm__(".extern D_001DE020_sda, 4");
void func_L01_00392F08(u8 *m) {
    extern unsigned long func_00389598(s32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_003D2DA0(void *, s32, s32);
    Packet_00392F08 packet;
    vu0_v4 matrix[3];
    vu0_v4 normal;
    u8 *vars = *(u8 **)(m + 0x68);
    void *rotation = m + 0xC0;
    s32 i,j;
    packet.texture = func_00389598(D_001DE018_sda);
    packet.flags = (unsigned long)D_001DE004_sda | ((unsigned long)D_001DE008_sda << 2) | ((unsigned long)D_001DE00C_sda << 4) | ((unsigned long)D_001DE010_sda << 6) | ((unsigned long)D_001DE014_sda << 32);
    packet.fixed = 0xFF9000000260;
    packet.zero = 0;
    qzero(&matrix[0]); qzero(&matrix[1]); qzero(&matrix[2]);
    matrix[0].x = *(f32 *)(vars+0x10) * 2.0f;
    matrix[1].y = *(f32 *)(vars+0x10) * 2.0f;
    matrix[2].z = *(f32 *)(vars+0x10) * 0.25f;
    packet.color[0] = packet.color[1] = packet.color[2] = packet.color[3] = D_001DE01C_sda + (*(s32 *)(vars+0x24) << 24);
    func_003C5180(m+0x10, &normal, 1);
    for (i=0; i<64; i++) {
        for (j=0; j<4; j++) {
            s32 uv = D_L01_002B7070[i][j].uv;
            func_0038CE20(packet.p[j],D_L01_002B6B70[D_L01_002B7070[i][j].vertex],D_001DE020_sda);
            packet.uv[j][0] = D_L01_002B7470[uv][0];
            packet.uv[j][1] = D_L01_002B7470[uv][1];
            func_0038D000(packet.p[j],packet.p[j],matrix);
            func_0038D000(packet.p[j],packet.p[j],rotation);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_v4 *)packet.p[j]) : "m"(*(vu0_v4 *)packet.p[j]), "m"(*(vu0_v4 *)(m+0x10)) : "vf1", "vf2");
            func_0038CF68(&normal,&normal,0.5f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)packet.p[j]) : "m"(*(vu0_v4 *)packet.p[j]), "m"(normal) : "vf1", "vf2");
        }
        func_003D2DA0(&packet,0,0);
    }
}
/* localdecomp:end func_L01_00392F08 */
