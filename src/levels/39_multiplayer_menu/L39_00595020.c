#include "common.h"

/* localdecomp:start func_L39_00595020 */
extern u8 D_L39_004AD9C0[];
extern u8 D_001D714C_sda;
extern u8 D_001D714D_sda;
extern u8 *D_001D7150_sda;
extern s32 D_001D7148_sda;
extern s32 func_0038E1C8(void);

void func_L39_00595020(void) {
    if (D_L39_004AD9C0[0] == 0xFF) {
        D_L39_004AD9C0[1] = 0xFE;
        D_001D714C_sda = 1;
        D_001D714D_sda = 0;
    } else if (D_L39_004AD9C0[1] == 0xFF) {
        D_L39_004AD9C0[0] = 0xFE;
        D_001D714C_sda = 1;
        D_001D714D_sda = 1;
    }
    D_001D7150_sda = &D_L39_004AD9C0[2];
    D_001D7148_sda = func_0038E1C8();
}
/* localdecomp:end func_L39_00595020 */

/* localdecomp:start func_L39_00595098 */
void func_L39_00595098(u8 *src, u8 *dst) {
    u32 c = ((src[0] << 8) | src[1]) & 0xFFFF;

    if (c < 0x80) {
        dst[0] = c & 0x7F;
        dst[1] = 0;
    } else if (c >= 0x80 && c < 0x800) {
        dst[0] = 0xC0 | ((c >> 6) & 0x1F);
        dst[1] = 0x80 | (c & 0x3F);
        dst[2] = 0;
    } else if (c >= 0x800 && c < 0x10000) {
        dst[0] = 0xE0 | ((c >> 12) & 0x0F);
        dst[1] = 0x80 | ((c >> 6) & 0x3F);
        dst[2] = 0x80 | (c & 0x3F);
        dst[3] = 0;
    } else if (c >= 0x10000 && c < 0x200000) {
        dst[0] = 0xF0 | ((c >> 18) & 0x07);
        dst[1] = 0x80 | ((c >> 12) & 0x3F);
        dst[2] = 0x80 | ((c >> 6) & 0x3F);
        dst[3] = 0x80 | (c & 0x3F);
        dst[4] = 0;
    } else if (c >= 0x200000 && c < 0x4000000) {
        dst[0] = 0xF8 | ((c >> 24) & 0x03);
        dst[1] = 0x80 | ((c >> 18) & 0x3F);
        dst[2] = 0x80 | ((c >> 12) & 0x3F);
        dst[3] = 0x80 | ((c >> 6) & 0x3F);
        dst[4] = 0x80 | (c & 0x3F);
        dst[5] = 0;
    } else if (c >= 0x4000000 && c < 0x80000000) {
        dst[0] = 0xFC | ((c >> 30) & 0x01);
        dst[1] = 0x80 | ((c >> 24) & 0x3F);
        dst[2] = 0x80 | ((c >> 18) & 0x3F);
        dst[3] = 0x80 | ((c >> 12) & 0x3F);
        dst[4] = 0x80 | ((c >> 6) & 0x3F);
        dst[5] = 0x80 | (c & 0x3F);
        dst[6] = 0;
    }
}
/* localdecomp:end func_L39_00595098 */
