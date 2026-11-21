#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C5810(void *, s32, f32, f32);
/* --- end of declarations from other files --- */

/* declarations of 3C5608.c's earlier functions */
extern void func_0038D348(s32 a, s32 b, f32 x);
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D348(s32, s32, f32);
extern void func_0038D270(f32 *, f32 *, s32);

/* localdecomp:start func_003C5810 */
#include "vu0.h"
typedef int Q_003C5810 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003C5810;
typedef struct { V_003C5810 corners[4]; s32 color[4]; f32 uv[8]; long regs[4]; } Packet_003C5810;
extern V_003C5810 D_00222400_003C5810;
__asm__(".extern D_001D9180, 4");
extern V_003C5810 D_001D9180[] __attribute__((section(".sdata")));
extern long func_00389978(s32);
extern void func_0038D408();
extern void func_003D3158();

void func_003C5810(void *arg, s32 color, f32 scale, f32 distance) {
    Packet_003C5810 packet;
    V_003C5810 axis, delta, right, up, pos, offset;
    V_003C5810 *source = D_001D9180;
    V_003C5810 *dest;
    s32 i;

    *(Q_003C5810 *)&axis = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    packet.regs[1] = func_00389978(11);
    packet.regs[3] = 0x8000000048L;
    packet.regs[2] = 0xFF9000000260L;
    packet.regs[0] = 5;
    *(Q_003C5810 *)&pos = *(Q_003C5810 *)arg;
    packet.uv[0] = 0;
    packet.uv[1] = 0;
    packet.uv[2] = 0;
    packet.uv[3] = 1.0f;
    packet.uv[4] = 1.0f;
    packet.uv[5] = 0;
    packet.uv[6] = 1.0f;
    packet.uv[7] = 1.0f;
    vec_sub_ab(&delta, &D_00222400_003C5810, &pos);
    func_0038D348((s32)&delta, (s32)&delta, 1.0f);
    func_0038D270(&right.x, &delta.x, (s32)&axis);
    func_0038D348((s32)&right, (s32)&right, 1.0f);
    func_0038D270(&up.x, &right.x, (s32)&delta);
    func_0038D200(&offset.x, &delta, distance);
    vec_add_ab(&pos, &pos, &offset);
    packet.color[0] = packet.color[1] = packet.color[2] = packet.color[3] = color;
    dest = packet.corners;
    for (i = 3; i >= 0; i--) {
        func_0038D200(&dest->x, source, scale);
        source++;
        func_0038D408(dest, dest, &delta);
        dest++;
    }
    func_003D3158(&packet, 0, 0);
}
/* localdecomp:end func_003C5810 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003C59D8);
