#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003A8668(s32, u8 *);
/* --- end of declarations from other files --- */

/* declarations of 3A83E8.c's earlier functions */
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern void *D_001D7080;

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A8440);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A2C18;
typedef struct { u8 pad0[0x10]; V4_3A2C18 f10; u8 pad20[0x8A]; s16 hAA; } E_3A2C18;
typedef struct { u8 pad[0x20]; V4_3A2C18 *f20; u8 pad2[0x1C]; s32 f40; } S3_3A2C18;
typedef struct {
    u8 pad[0x30]; s32 f30; s32 f34; u8 pad38[0xC]; s16 h44; u8 pad46[0xA];
    S3_3A2C18 *f50; u8 pad54[0x14C]; E_3A2C18 *tbl[4];
} B_3A2C18;
extern B_3A2C18 D_00225700_003A82F8;
extern V4_3A2C18 D_00222400_003A82F8[];
extern void func_0038D3E0(void *, void *, void *);
extern void func_0038D348(void *, void *, f32);
typedef struct { u8 pad[0x48]; s32 f48; s32 f4C; } E_3A2DF8;
extern u8 *D_001D6EEC;
extern f32 D_001D6EF0;
extern s32 D_001DA010[2];
/* localdecomp:start func_003A8620 */
__asm__(".extern D_001D6EEC, 4");
__asm__(".extern D_001D6EF0, 4");
extern u8 D_1DA010[];
void func_003A8620(E_3A2DF8 *a0) {
    s32 i;
    f32 one;
    D_001D6EEC = (u8 *)a0;
    for (i = 0x1FF; i >= 0; i--) {
        a0[i].f48 = 0;
    }
    do { one = 1.0f; } while (0);
    QZERO(D_1DA010);
    D_001D6EF0 = one;
}
/* localdecomp:end func_003A8620 */

/* localdecomp:start func_003A8668 */
extern u8 *D_001D6EEC;
void func_003A8668(s32 a0, u8 *src) {
    u8 *p;
    s32 i;
    if (D_001D6EEC == 0) return;
    p = D_001D6EEC;
    i = 0;
    do {
        i++;
        if (*(s32 *)(p + 0x48) == 0) {
            *(s32 *)(p + 0x38) = *(s32 *)(src + 0x38);
            *(s32 *)(p + 0x3C) = *(s32 *)(src + 0x3C);
            *(s32 *)(p + 0x30) = *(s32 *)(src + 0x30);
            *(s32 *)(p + 0x44) = *(s32 *)(src + 0x44);
            *(f32 *)(p + 0x24) = *(f32 *)(src + 0x24);
            *(f32 *)(p + 0x20) = *(f32 *)(src + 0x20);
            *(f32 *)(p + 0x28) = *(f32 *)(src + 0x28);
            *(s32 *)(p + 0x34) = *(s32 *)(src + 0x34);
            *(s32 *)(p + 0x2C) = *(s32 *)(src + 0x2C);
            *(s32 *)(p + 0x40) = *(s32 *)(src + 0x40);
            *(s32 *)(p + 0x4C) = *(s32 *)(src + 0x4C);
            *(u128_t *)(p + 0) = *(u128_t *)(src + 0);
            *(u128_t *)(p + 0x10) = *(u128_t *)(src + 0x10);
            *(s32 *)(p + 0x48) = a0;
            return;
        }
        p += 0x50;
    } while (i < 0x200);
}
/* localdecomp:end func_003A8668 */
