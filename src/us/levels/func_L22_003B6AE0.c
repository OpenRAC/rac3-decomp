#include "common.h"

/* localdecomp:start func_L22_003B6AE0 */
typedef struct {
    u8 p0[4];
    s32 n[16];
    s32 b[16];
    s32 a[16];
    u8 p1[0x188 - 0xC4];
} Rec188;

extern void func_L01_00433628(void *, s32, s32);
extern void func_L01_00445110(void *, s32, s32);
extern void func_L22_003B6360(s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00512AB0(s32, s32, s32);
extern u8 D_L22_002A21B0[];
extern Rec188 D_L22_002BA430[];
extern s32 D_L22_001E1FB8;
__asm__(".extern D_L22_001E1FB8, 16");
extern s32 D_L22_001E1FC0[2];
__asm__(".extern D_L22_001E1FC0, 64");
extern s32 D_L22_001E2000[2];
__asm__(".extern D_L22_001E2000, 64");
extern s32 D_L22_001E2040[2];
__asm__(".extern D_L22_001E2040, 64");
extern s32 D_L22_001E2080;
__asm__(".extern D_L22_001E2080, 16");
extern s32 D_L22_001E2084;
__asm__(".extern D_L22_001E2084, 16");
extern f32 D_L22_001DE530;
__asm__(".extern D_L22_001DE530, 4");
extern f32 D_L22_001DE534;
__asm__(".extern D_L22_001DE534, 4");

void func_L22_003B6AE0(u8 *obj) {
    u8 *p;
    Rec188 *rec;
    s32 i;

    p = *(u8 **)(obj + 0x68);
    if (obj[0x20] == 0x16 || obj[0x20] == 0x17 || obj[0x20] == 0x1A || obj[0x20] == 0x14 || obj[0x20] == 0x19) {
        func_L01_00433628(D_L22_002A21B0, 2, 0);
    }
    if (obj[0x20] == 0x18 && *(u16 *)(obj + 0x96) >= 0x78) {
        func_L01_00433628(D_L22_002A21B0, 2, 0);
    }
    if (obj[0x20] == 0x15 || obj[0x20] == 0x16 || obj[0x20] == 0x1A || obj[0x20] == 0x17) {
        rec = &D_L22_002BA430[*(s32 *)(p + (*(s32 *)(p + 0x498) << 2) + 0x4C0)];
        for (i = 0; rec->n[i] > 0; i++) {
            if (rec->a[i] == 0 && D_L22_001E2084 < 0 && D_L22_001E1FB8 >= i && (D_L22_001E2080 == 0 || i < D_L22_001E1FB8)) {
                func_L01_00445110(&D_L22_001E1FC0[i], rec->b[i], 1);
                func_L01_00445110(&D_L22_001E2000[i], rec->b[i], 1);
            }
            func_L22_003B6360(i + 0x120044, rec->n[i], i == D_L22_001E2084,
                              (f32)(rec->b[i] - *(s32 *)(p + 0x49C)) / 270.0f + 0.5f,
                              (f32)(rec->b[i] + rec->a[i] - *(s32 *)(p + 0x49C)) / 270.0f + 0.5f, D_L22_001DE534);
            if (D_L22_001E1FB8 >= i) {
                func_L22_003B6360(i + 0x120000, D_L22_001E2040[i], i == D_L22_001E2084,
                                  (f32)(D_L22_001E1FC0[i] - *(s32 *)(p + 0x49C)) / 270.0f + 0.5f,
                                  (f32)(D_L22_001E2000[i] - *(s32 *)(p + 0x49C)) / 270.0f + 0.5f, D_L22_001DE530);
            } else {
                func_L01_00512AB0(i + 0x120000, 1, 0);
                func_L01_00512AB0(i + 0x120011, 1, 0);
                func_L01_00512AB0(i + 0x120022, 1, 0);
                func_L01_00512AB0(i + 0x120033, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_L22_003B6AE0 */
