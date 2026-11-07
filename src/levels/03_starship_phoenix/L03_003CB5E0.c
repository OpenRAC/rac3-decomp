#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0x44];
    s32 w6C;
    u8 pad70[0x24];
    s32 w94;
} S_001CCFD0_003CBB68;

typedef struct {
    u8 p0[0x76];
    s16 f76;
    u8 p78[0x20];
    s16 f98;
    u8 p9A[0x4];
    s16 f9E;
} S_L03_003CBBD8;

INCLUDE_ASM("asm/levels", func_L03_003CB5E0);

INCLUDE_ASM("asm/levels", func_L03_003CB910);

INCLUDE_ASM("asm/levels", func_L03_003CBA20);

/* localdecomp:start func_L03_003CBB68 */
extern S_001CCFD0_003CBB68 D_001CCFD0;
extern s32 func_L01_004BA800(void);
extern void func_003A2B68(s32, s32);

s32 func_L03_003CBB68(s32 a0, s32 a1) {
    if (func_L01_004BA800() != 0) {
        return 0;
    }
    if (D_001CCFD0.w6C != 0) {
        return 0;
    }
    if (D_001CCFD0.w24 != -1) {
        return 0;
    }
    if (D_001CCFD0.w94 != 0) {
        return 0;
    }
    func_003A2B68((a1 & 0x3FFF) + 0x7D0, 0);
    return 1;
}
/* localdecomp:end func_L03_003CBB68 */

/* localdecomp:start func_L03_003CBBD8 */
extern S_L03_003CBBD8 D_001CCFD0_003CBBD8;
extern s32 func_003A1798(void);

void func_L03_003CBBD8(void) {
    if (D_001CCFD0_003CBBD8.f76 == 0 && D_001CCFD0_003CBBD8.f9E == 3 && D_001CCFD0_003CBBD8.f98 < 0x1B58) {
        func_003A1798();
    }
}
/* localdecomp:end func_L03_003CBBD8 */

INCLUDE_ASM("asm/levels", func_L03_003CBC28);

/* localdecomp:start func_L03_003CBD50 */
typedef struct {
    u8 p0[0x228];
    f32 f228;
    f32 f22C;
    u8 p230[8];
    f32 f238;
    f32 f23C;
    u8 p240[0x10];
    s32 f250;
    s32 f254;
    s32 f258;
} S_001E7000_003CBD50;

extern S_001E7000_003CBD50 D_L03_001E7000;
extern u8 D_L03_001DF364;
__asm__(".extern D_L03_001DF364, 16");
extern u8 D_L03_001DF365;
__asm__(".extern D_L03_001DF365, 16");
extern u8 D_L03_001DF366;
__asm__(".extern D_L03_001DF366, 16");
extern f32 D_L03_001DF368;
__asm__(".extern D_L03_001DF368, 16");
extern f32 D_L03_001DF36C;
__asm__(".extern D_L03_001DF36C, 16");
extern f32 D_L03_001DF370;
__asm__(".extern D_L03_001DF370, 16");
extern f32 D_L03_001DF374;
__asm__(".extern D_L03_001DF374, 16");
extern void func_003873C0(void);

void func_L03_003CBD50(void) {
    D_L03_001E7000.f250 = D_L03_001DF364;
    D_L03_001E7000.f254 = D_L03_001DF365;
    D_L03_001E7000.f258 = D_L03_001DF366;
    D_L03_001E7000.f22C = D_L03_001DF36C;
    D_L03_001E7000.f228 = D_L03_001DF368;
    D_L03_001E7000.f23C = D_L03_001DF374;
    D_L03_001E7000.f238 = D_L03_001DF370;
    func_003873C0();
}
/* localdecomp:end func_L03_003CBD50 */
