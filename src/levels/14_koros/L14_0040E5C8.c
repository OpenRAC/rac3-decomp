#include "common.h"

/* localdecomp:start func_L14_0040E5C8 */
typedef struct {
    u8 pad0[170];
    s16 id;
} Item403490;

typedef struct {
    u8 pad0[68];
    s16 count;
    u8 pad46[416 - 70];
    Item403490 *items[1];
} List403490;

extern List403490 D_L10_001E5F00;

Item403490 *func_L14_0040E5C8(s32 id) {
    s32 i;
    for (i = 0; i < D_L10_001E5F00.count; i++) {
        Item403490 *item = D_L10_001E5F00.items[i];
        if (item != 0 && item->id == id) {
            return item;
        }
    }
    return 0;
}
/* localdecomp:end func_L14_0040E5C8 */

/* localdecomp:start func_L14_0040E620 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_0040E620;
typedef struct { u8 p0[0x38]; s32 f38; s32 f3C; } T_0040E620;
typedef struct { u8 p0[0x30]; s32 f30; s32 f34; } U_0040E620;
extern S_0040E620 D_L14_002E85E0;
extern T_0040E620 D_L14_002E8630;
extern T_0040E620 D_L14_002E8690;
extern T_0040E620 D_L14_002E86F0;
extern T_0040E620 D_L14_002E8750;
extern U_0040E620 D_L14_001E6480;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001D6AB0_sda;
__asm__(".extern D_001D6AB0_sda, 4");
extern u8 D_001D6AA5_sda;
__asm__(".extern D_001D6AA5_sda, 4");
extern f32 D_001D6B44_sda;
__asm__(".extern D_001D6B44_sda, 4");
extern u8 D_001D6B70_sda;
__asm__(".extern D_001D6B70_sda, 4");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);

void func_L14_0040E620(void)
{
    T_0040E620 *q = 0;
    s32 b = 0;
    D_001D6B44_sda = 1.0f;
    D_L14_002E85E0.f20 = &D_001D6AB0_sda;
    D_L14_002E85E0.f30 = 1;
    D_001D6AA5_sda = 0;
    if (D_001D545C == 14 && D_L14_001E6480.f30 == 1) {
        if (D_L14_001E6480.f34 >= (D_L14_002E8750.f38 * 5 + 2) / 6
            && D_L14_001E6480.f34 <= (D_L14_002E8750.f3C * 5 + 2) / 6) {
            b = (s32)&D_001D6B70_sda;
            q = &D_L14_002E8750;
        } else if (D_L14_001E6480.f34 < (D_L14_002E8690.f38 * 5 + 2) / 6) {
            q = &D_L14_002E8630;
        } else if (D_L14_001E6480.f34 < (D_L14_002E86F0.f38 * 5 + 2) / 6) {
            q = &D_L14_002E8690;
        } else {
            q = &D_L14_002E86F0;
        }
    }
    if (q != 0) {
        func_L01_00423068(q, b, 0, 0, 0, 1, 0);
    }
}
/* localdecomp:end func_L14_0040E620 */
