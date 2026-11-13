#include "common.h"

/* declared by functions of L39_005DA870.c, which this file was cut from */
extern s32 *D_L39_00241120;
extern void func_L01_005169C8(s32, f32);

/* localdecomp:start func_L39_005DB370 */
extern s32 *D_L39_00241120;
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern void func_L39_005DB618(void);
extern void func_L39_005DB700(void);

void func_L39_005DB370(void)
{
    func_L01_00516470(0x20006, 0.076f, 0.08885f);
    func_L01_00516470(0x20007, 0.074f, 0.189f);
    func_L01_00516470(0x20008, 0.074f, 0.258f);
    func_L01_00517538(0x20006, 0.057749998f, 0.07107692f);
    func_L01_00517538(0x20007, 0.040599998f, 0.04996923f);
    func_L01_00517538(0x20008, 0.040599998f, 0.04996923f);
    func_L01_00516470(0x20005, 0.3235f, 0.058f);
    func_L01_00517538(0x20005, 1.1f, 1.1f);
    if (*D_L39_00241120 != 1)
        func_L01_00517538(0x20005, 0.5f, 0.5f);
    func_L01_00516470(0x20011, 0.412f, 0.422f);
    func_L01_00516470(0x20010, 0.412f, 0.422f);
    func_L01_00517538(0x20011, 0.8f, 0.78f);
    func_L01_00517538(0x20010, 0.8f, 0.78f);
    func_L01_00516470(0x20012, 0.074f, 0.224f);
    func_L01_00517538(0x20012, 0.05f, 0.005f);
    func_L01_00516470(0x2000B, 0.124f, 0.073f);
    func_L01_00517538(0x2000B, 0.0f, 0.0f);
    if (*D_L39_00241120 == 1)
        func_L39_005DB618();
    else
        func_L39_005DB700();
}
/* localdecomp:end func_L39_005DB370 */

INCLUDE_ASM("asm/levels", func_L39_005DB618);

INCLUDE_ASM("asm/levels", func_L39_005DB700);

/* localdecomp:start func_L39_005DB800 */
__asm__(".extern D_001D80A4_sda, 4");
__asm__(".extern D_001D80A8_sda, 4");
__asm__(".extern D_001D80AC_sda, 4");
__asm__(".extern D_001D80B0_sda, 4");
__asm__(".extern D_001D80B4_sda, 4");
__asm__(".extern D_001D80B8_sda, 4");
__asm__(".extern D_001D80BC_sda, 4");
__asm__(".extern D_001D80C0_sda, 4");
__asm__(".extern D_001D80C4_sda, 4");
__asm__(".extern D_001D80C8_sda, 4");
__asm__(".extern D_001D80CC_sda, 4");
__asm__(".extern D_001D80D0_sda, 4");
__asm__(".extern D_001D80D4_sda, 4");
__asm__(".extern D_001D80D8_sda, 4");
__asm__(".extern D_001D80DC_sda, 4");
__asm__(".extern D_001D80E0_sda, 4");
__asm__(".extern D_001D80E4_sda, 4");
__asm__(".extern D_001D80E8_sda, 4");
__asm__(".extern D_001D80EC_sda, 4");
__asm__(".extern D_001D80F0_sda, 4");
__asm__(".extern D_001D80F4_sda, 4");
__asm__(".extern D_001D80F8_sda, 4");
__asm__(".extern D_001D80FC_sda, 4");
__asm__(".extern D_001D8100_sda, 4");
__asm__(".extern D_001D8104_sda, 4");
__asm__(".extern D_001D8108_sda, 4");
__asm__(".extern D_001D810C_sda, 4");
__asm__(".extern D_001D8110_sda, 4");
__asm__(".extern D_001D8114_sda, 4");
__asm__(".extern D_001D8118_sda, 4");
__asm__(".extern D_001D811C_sda, 4");
__asm__(".extern D_001D8120_sda, 4");
__asm__(".extern D_001D8124_sda, 4");
__asm__(".extern D_001D8128_sda, 4");
__asm__(".extern D_001D812C_sda, 4");
__asm__(".extern D_001D8130_sda, 4");
__asm__(".extern D_001D8134_sda, 4");
__asm__(".extern D_001D8138_sda, 4");
extern f32 D_001D80A4_sda;
extern f32 D_001D80A8_sda;
extern f32 D_001D80AC_sda;
extern f32 D_001D80B0_sda;
extern f32 D_001D80B4_sda;
extern f32 D_001D80B8_sda;
extern f32 D_001D80BC_sda;
extern f32 D_001D80C0_sda;
extern f32 D_001D80C4_sda;
extern f32 D_001D80C8_sda;
extern f32 D_001D80CC_sda;
extern f32 D_001D80D0_sda;
extern f32 D_001D80D4_sda;
extern f32 D_001D80D8_sda;
extern f32 D_001D80DC_sda;
extern f32 D_001D80E0_sda;
extern f32 D_001D80E4_sda;
extern f32 D_001D80E8_sda;
extern f32 D_001D80EC_sda;
extern f32 D_001D80F0_sda;
extern f32 D_001D80F4_sda;
extern f32 D_001D80F8_sda;
extern f32 D_001D80FC_sda;
extern f32 D_001D8100_sda;
extern f32 D_001D8104_sda;
extern f32 D_001D8108_sda;
extern f32 D_001D810C_sda;
extern f32 D_001D8110_sda;
extern f32 D_001D8114_sda;
extern f32 D_001D8118_sda;
extern f32 D_001D811C_sda;
extern f32 D_001D8120_sda;
extern f32 D_001D8124_sda;
extern f32 D_001D8128_sda;
extern f32 D_001D812C_sda;
extern f32 D_001D8130_sda;
extern f32 D_001D8134_sda;
extern f32 D_001D8138_sda;
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);

void func_L39_005DB800(void)
{
    func_L01_00516470(0x20004, D_001D80A4_sda, D_001D80A8_sda);
    func_L01_00517538(0x20003, D_001D80AC_sda, D_001D80B0_sda);
    func_L01_00516470(0x20003, D_001D80A4_sda, D_001D80A8_sda);
    func_L01_00517538(0x20004, D_001D80AC_sda, D_001D80B0_sda);
    func_L01_00516470(0x20006, D_001D80B4_sda, D_001D80B8_sda);
    func_L01_00516470(0x20007, D_001D80BC_sda, D_001D80C0_sda);
    func_L01_00516470(0x20008, D_001D80C4_sda, D_001D80C8_sda);
    func_L01_00517538(0x20006, D_001D80D4_sda, D_001D80D8_sda);
    func_L01_00517538(0x20007, D_001D80D4_sda, D_001D80D8_sda);
    func_L01_00517538(0x20008, D_001D80D4_sda, D_001D80D8_sda);
    func_L01_00516470(0x20005, D_001D80CC_sda, D_001D80D0_sda);
    func_L01_00517538(0x20005, D_001D80DC_sda, D_001D80E0_sda);
    func_L01_00516470(0x2000A, D_001D80E4_sda, D_001D80E8_sda);
    func_L01_00517538(0x2000A, D_001D80EC_sda, D_001D80F0_sda);
    func_L01_00516470(0x20009, D_001D80F4_sda, D_001D80F8_sda);
    func_L01_00517538(0x20009, D_001D80FC_sda, D_001D8100_sda);
    func_L01_00516470(0x2000B, D_001D8104_sda, D_001D8108_sda);
    func_L01_00517538(0x2000B, 0.0f, 0.0f);
    func_L01_00516470(0x20011, D_001D8114_sda, D_001D8118_sda);
    func_L01_00517538(0x20011, D_001D810C_sda, D_001D8110_sda);
    func_L01_00516470(0x20010, D_001D8114_sda, D_001D8118_sda);
    func_L01_00517538(0x20010, D_001D810C_sda, D_001D8110_sda);
    func_L01_00516470(0x20012, D_001D811C_sda, D_001D8120_sda);
    func_L01_00517538(0x20012, D_001D8124_sda, D_001D8128_sda);
    func_L01_00516470(0x2000E, D_001D812C_sda, D_001D8130_sda);
    func_L01_00516470(0x2000D, D_001D812C_sda, D_001D8130_sda);
    func_L01_00517538(0x2000E, D_001D8134_sda, D_001D8138_sda);
    func_L01_00517538(0x2000D, D_001D8134_sda, D_001D8138_sda);
    func_L01_00516470(0x2000F, 0.929f, 0.56f);
}
/* localdecomp:end func_L39_005DB800 */
