#include "common.h"

typedef struct S_004E56D0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B24 - 0x1B08];
    u8 *x1B24;
    u8 pad2[0x25C0 - 0x1B28];
    u8 *x25C0;
} S_004E56D0;

typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;

extern S_004E6988 D_001A4BE0;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_L30_004CF4B0(s32, s32);

typedef struct {
    u8 pad0[0x43];
    u8 b43;
} P_004E6D08;
typedef struct {
    u8 pad0[0xC08];
    s32 w_C08;
    u8 pad1[0x1AC0 - 0xC0C];
    s32 w_1AC0;
    u8 pad2[0x25C0 - 0x1AC4];
    P_004E6D08 *p_25C0;
    s32 w_25C4;
    u8 pad3[0x25CC - 0x25C8];
    s32 w_25CC;
    u8 pad4[0x25E9 - 0x25D0];
    u8 b_25E9;
    u8 pad5[0x25EB - 0x25EA];
    u8 b_25EB;
} S_004E6D08;

/* localdecomp:start func_L30_004E6A48 */
#include "vu0.h"
extern f32 D_L30_001DBFC8;
__asm__(".extern D_L30_001DBFC8, 4");
extern f32 D_L30_001DBFCC;
__asm__(".extern D_L30_001DBFCC, 4");
extern f32 D_L30_001DBFD0;
__asm__(".extern D_L30_001DBFD0, 4");
extern s32 D_001A71A0[];
extern u8 D_001A4C60[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L30_004E6A48(void *out, f32 angle) {
    vu0_v4 v;

    v.x = func_0038D098(angle) * D_L30_001DBFD0;
    v.z = func_0038D0B0(angle) * D_L30_001DBFD0;
    v.z += D_001A71A0[1] == 0xA3 ? D_L30_001DBFCC : D_L30_001DBFC8;
    vec_add_ab(out, D_001A4C60, &v);
}
/* localdecomp:end func_L30_004E6A48 */
