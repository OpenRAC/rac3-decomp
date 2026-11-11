#include "common.h"

/* localdecomp:start func_L01_004C5D68 */
extern s32 D_L01_001E1068;
extern u8 D_L01_001DA2B0[];

void func_L01_004C5D68(void) {
    *(s32 *)(D_L01_001E1068 + 0) = 0x30000003;
    *(s32 *)(D_L01_001E1068 + 4) = (s32)D_L01_001DA2B0;
    *(s32 *)(D_L01_001E1068 + 8) = 0;
    *(s32 *)(D_L01_001E1068 + 0xC) = 0x50000003;
    D_L01_001E1068 = D_L01_001E1068 + 0x10;
}
/* localdecomp:end func_L01_004C5D68 */

/* localdecomp:start func_L01_004C5DC8 */
extern s32 D_L01_001E1068;
extern u8 D_L01_001D9D80[];

void func_L01_004C5DC8(void) {
    *(s32 *)(D_L01_001E1068 + 0) = 0x30000003;
    *(s32 *)(D_L01_001E1068 + 4) = (s32)D_L01_001D9D80;
    *(s32 *)(D_L01_001E1068 + 8) = 0;
    *(s32 *)(D_L01_001E1068 + 0xC) = 0x50000003;
    D_L01_001E1068 = D_L01_001E1068 + 0x10;
}
/* localdecomp:end func_L01_004C5DC8 */

/* localdecomp:start func_L01_004C5E28 */
extern s32 D_L01_001E1068;
extern u8 D_L01_001D9DB0[];

void func_L01_004C5E28(void) {
    *(s32 *)(D_L01_001E1068 + 0) = 0x30000004;
    *(s32 *)(D_L01_001E1068 + 4) = (s32)D_L01_001D9DB0;
    *(s32 *)(D_L01_001E1068 + 8) = 0;
    *(s32 *)(D_L01_001E1068 + 0xC) = 0x50000004;
    D_L01_001E1068 = D_L01_001E1068 + 0x10;
}
/* localdecomp:end func_L01_004C5E28 */

LINKER_REMNANT("asm/levels", func_L01_004C5E88);
