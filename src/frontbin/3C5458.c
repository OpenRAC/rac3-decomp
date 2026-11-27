#include "common.h"

/* localdecomp:start func_003C5458 */
/* the copy of func_003C5810 */
#include "vu0.h"
typedef int Q_003C5458 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003C5458;
typedef struct { V_003C5458 corners[4]; s32 color[4]; f32 uv[8]; long regs[4]; } Packet_003C5458;
extern V_003C5458 D_00222400_003C5458;
__asm__(".extern D_001D9180, 4");
extern V_003C5458 D_001D9180[] __attribute__((section(".sdata")));
extern long func_00389598(s32);
extern void func_0038D028();
extern void func_003D2DA0();

extern void func_0038CE20_a003C5458(f32 *, void *, f32) __asm__("func_0038CE20");
extern void func_0038CE90_a003C5458(f32 *, f32 *, s32) __asm__("func_0038CE90");
extern void func_0038CF68_a003C5458(s32, s32, f32) __asm__("func_0038CF68");
void func_003C5458(void *arg, s32 color, f32 scale, f32 distance) {
    Packet_003C5458 packet;
    V_003C5458 axis, delta, right, up, pos, offset;
    V_003C5458 *source = D_001D9180;
    V_003C5458 *dest;
    s32 i;

    *(Q_003C5458 *)&axis = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    packet.regs[1] = func_00389598(11);
    packet.regs[3] = 0x8000000048L;
    packet.regs[2] = 0xFF9000000260L;
    packet.regs[0] = 5;
    *(Q_003C5458 *)&pos = *(Q_003C5458 *)arg;
    packet.uv[0] = 0;
    packet.uv[1] = 0;
    packet.uv[2] = 0;
    packet.uv[3] = 1.0f;
    packet.uv[4] = 1.0f;
    packet.uv[5] = 0;
    packet.uv[6] = 1.0f;
    packet.uv[7] = 1.0f;
    vec_sub_ab(&delta, &D_00222400_003C5458, &pos);
    func_0038CF68_a003C5458((s32)&delta, (s32)&delta, 1.0f);
    func_0038CE90_a003C5458(&right.x, &delta.x, (s32)&axis);
    func_0038CF68_a003C5458((s32)&right, (s32)&right, 1.0f);
    func_0038CE90_a003C5458(&up.x, &right.x, (s32)&delta);
    func_0038CE20_a003C5458(&offset.x, &delta, distance);
    vec_add_ab(&pos, &pos, &offset);
    packet.color[0] = packet.color[1] = packet.color[2] = packet.color[3] = color;
    dest = packet.corners;
    for (i = 3; i >= 0; i--) {
        func_0038CE20_a003C5458(&dest->x, source, scale);
        source++;
        func_0038D028(dest, dest, &delta);
        dest++;
    }
    func_003D2DA0(&packet, 0, 0);
}
/* localdecomp:end func_003C5458 */

LINKER_REMNANT("asm/remnants", func_003C5620);
