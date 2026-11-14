#include "common.h"

/* NTSC-U counterpart of func_L14_0040EA78 (src/levels/14_koros/L14_0040E918.c) */
#include "vu0.h"

extern int D_L14_001EEC50_0040BBC0[];
extern u8 D_L14_001EF150_0040BBC0[];

/* localdecomp:start func_L14_0040BBC0 */
typedef struct {
    u8 pad[0x34];
    s32 f34;
} S_40EA78;
extern S_40EA78 D_L14_001E6480_0040BBC0;
extern vu0_v4 D_L14_001D66B0_0040BBC0 __attribute__((section(".sdata")));
extern vu0_v4 D_L14_001E20E0_0040BBC0;
__asm__(".extern D_L14_001D6BC0_0040BBC0, 4");
__asm__(".extern D_L14_001D6BC4_0040BBC0, 4");
__asm__(".extern D_L14_001D6BC8_0040BBC0, 4");
__asm__(".extern D_L14_001D6BD0_0040BBC0, 4");
__asm__(".extern D_L14_001D6C18_0040BBC0, 4");
extern s32 D_L14_001D6BC0_0040BBC0;
extern s32 D_L14_001D6BC4_0040BBC0;
extern s32 D_L14_001D6BC8_0040BBC0;
extern f32 D_L14_001D6BD0_0040BBC0;
extern s32 D_L14_001D6C18_0040BBC0;
extern void func_00388E38(void *, void *);
extern void func_L14_003F73B0(void *, void *, f32);
extern void func_003D41E0(void *, s32, s32, s32, s32, f32);
extern void func_L01_004084B0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
void func_L14_0040BBC0(void) {
    vu0_v4 m[4];
    vu0_v4 a;
    vu0_v4 b;
    u8 *p;
    u8 *q;
    u8 *end;
    s32 i;
    s32 c;
    f32 t;
    p = (u8 *)D_L14_001EEC50_0040BBC0;
    for (i = 39; i >= 0; i--) {
        if (*(s32 *)(p + 0x10) >= 0) {
            func_00388E38(m, &D_L14_001E20E0_0040BBC0);
            m[3] = D_L14_001D66B0_0040BBC0;
            func_L14_003F73B0(m, m, *(f32 *)(p + 0xC));
            c = D_L14_001D6BC4_0040BBC0;
            t = (f32)*(s32 *)(p + 0x10) / (f32)D_L14_001D6BC8_0040BBC0;
            m[3] = *(vu0_v4 *)p;
            func_003D41E0(m, D_L14_001D6BC0_0040BBC0, ((s32)(t * 0.6f * (f32)c) << 24) | (c << 16) | (c << 8) | c, 10, 1, 0.0f);
            *(f32 *)(p + 0xC) += t * D_L14_001D6BD0_0040BBC0;
            *(s32 *)(p + 0x10) -= 1;
        }
        p += 0x20;
    }
    if (D_L14_001E6480_0040BBC0.f34 < 0x547) {
        for (i = 0; i < 14; i++) {
            q = D_L14_001EF150_0040BBC0 + i * 0x30;
            if (*(s32 *)(q + 0x24) >= 0) {
                a = *(vu0_v4 *)q;
                b = *(vu0_v4 *)(q + 0x10);
                func_L01_004084B0(&a, &b, 0x16, 1, D_L14_001D6C18_0040BBC0, D_L14_001D6C18_0040BBC0, 0, 0, *(f32 *)(q + 0x20), 2.0f, 0.0f);
                *(f32 *)(q + 0x20) += 0.008f;
            }
        }
    }
}
/* localdecomp:end func_L14_0040BBC0 */
