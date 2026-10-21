#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003D1768();
/* --- end of declarations from other files --- */

/* declarations of 3D1050.c's earlier functions (tools/port_from_us.py) */
extern void func_003D0DC0(s32, s32, s32);
extern s32 func_003DEDB0(s32, s32, s32);
extern s32 func_003E15F0(s32, s32, s32);
extern u8 D_002FF700[];
typedef int u128_3CB958 __attribute__((mode(TI)));
extern u8 D_001DA6B0[8];
extern f32 D_001DA6C0;
extern f32 D_001DA6C4;
extern volatile f32 D_001DA6C8;
extern u8 D_001DA6D0[];
extern void func_0038D1C8(void *, void *);
extern void func_0038D200(f32 *, void *, f32);
extern void func_0038D270(void *, void *, void *);
extern void func_0038D348(s32, s32, f32);
void func_003D1DD8(s16 *);
void func_003D1F20(s16 *);

/* localdecomp:start func_003D13E8 */
typedef struct { u8 pad0[0x150]; s16 x; s16 y; } S_3CBAC0;
extern S_3CBAC0 D_001CFEC0;
extern u32 *D_001DA050_003D13E8;
extern void func_003A97F8(s32, unsigned long);
void func_003D13E8(void) {
    S_3CBAC0 *s = &D_001CFEC0;
    s32 x = s->x;
    s32 y = s->y;
    s32 n = x / 32;
    s32 i;
    unsigned long *q;
    s32 k;
    func_003A97F8(0x42, 0x64);
    D_001DA050_003D13E8[0] = (n + 5) | 0x10000000;
    D_001DA050_003D13E8[1] = 0;
    D_001DA050_003D13E8[2] = 0;
    D_001DA050_003D13E8[3] = (n + 5) | 0x50000000;
    D_001DA050_003D13E8 += 4;
    q = (unsigned long *)D_001DA050_003D13E8;
    q[0] = 0x1000000000000001UL;
    q[1] = 0xE;
    q[2] = 0x35001;
    q[3] = 0x47;
    q[4] = 0x2400000000008001UL;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = 0x80808080;
    q[8] = (n | 0x8000) | 0x2400000000000000UL;
    q[9] = 0x44;
    i = 0;
    if (i < n) {
        k = 10;
        do {
            q[k++] = (0x8000 - x * 8 + i * 0x200) | ((unsigned long)(0x8000 - y * 8) << 16);
            q[k++] = (0x8200 - x * 8 + i * 0x200) | ((unsigned long)(y * 8 + 0x7FF0) << 16);
            i++;
        } while (i < n);
    }
    D_001DA050_003D13E8 += n * 4 + 20;
}
/* localdecomp:end func_003D13E8 */

/* localdecomp:start func_003D1598 */
typedef struct { u8 pad0[0x150]; s16 x; s16 y; } S_3CBC70;
extern S_3CBC70 D_001CFEC0_003D1598;
extern u32 *D_001DA050_003D1598;
void func_003D1598(s32 rgba) {
    S_3CBC70 *s = &D_001CFEC0_003D1598;
    s32 x = s->x;
    s32 y = s->y;
    s32 n = x / 32;
    s32 i;
    unsigned long *q;
    s32 k;
    D_001DA050_003D1598[0] = (n + 5) | 0x10000000;
    D_001DA050_003D1598[1] = 0;
    D_001DA050_003D1598[2] = 0;
    D_001DA050_003D1598[3] = (n + 5) | 0x50000000;
    D_001DA050_003D1598 += 4;
    q = (unsigned long *)D_001DA050_003D1598;
    q[0] = 0x1000000000000001UL;
    q[1] = 0xE;
    q[2] = 0x35801;
    q[3] = 0x47;
    q[4] = 0x2400000000000001UL;
    q[5] = 0x10;
    q[6] = 0x146;
    q[7] = rgba;
    q[8] = (n | 0x8000) | 0x2400000000000000UL;
    q[9] = 0x44;
    i = 0;
    if (i < n) {
        k = 10;
        do {
            q[k++] = (0x8000 - x * 8 + i * 0x200) | ((unsigned long)(0x8000 - y * 8) << 16);
            q[k++] = (0x8200 - x * 8 + i * 0x200) | ((unsigned long)(y * 8 + 0x7FF0) << 16);
            i++;
        } while (i < n);
    }
    D_001DA050_003D1598 += n * 4 + 20;
    D_001DA050_003D1598[0] = 0x10000000;
    D_001DA050_003D1598[1] = 0;
    D_001DA050_003D1598[2] = 0x13000000;
    D_001DA050_003D1598[3] = 0;
    D_001DA050_003D1598 += 4;
}
/* localdecomp:end func_003D1598 */

typedef struct { s32 x0; void *x4; s32 x8; s32 xC; } Q_003CBE40;
typedef struct {
    s32 x0;
    s32 x4;
    f32 x8;
    f32 xC;
    f32 x10;
    f32 x14;
    f32 x18;
    u8 pad1C[4];
    u8 x20[0x10];
} R_003CBE40;
typedef struct { u8 pad[0x150]; s16 x150; s16 x152; } V_003CBE40;
extern Q_003CBE40 *D_001DA050[1];
extern s32 D_001DA6F0;
extern s32 D_001D9340;
extern volatile s32 D_001D9344;
extern f32 D_001DA6E0;
extern f32 D_001DA6E4;
extern u8 D_001D5477;
extern u8 D_1420B0[];
extern u8 D_003801F0[];
extern V_003CBE40 D_1CFEC0;
extern s32 D_1A1ED0[];
extern void func_003D1280(void *, f32);
extern void func_003D21E0(f32 *, f32 *);
extern void func_003D2738(s32, s32);
extern void func_003A97F8(s32, unsigned long);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003D1768);
