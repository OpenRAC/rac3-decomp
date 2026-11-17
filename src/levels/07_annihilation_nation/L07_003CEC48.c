#include "common.h"

/* localdecomp:start func_L07_003CEC48 */
extern s32 D_L07_001DF41C;
s32 func_L07_003BAC58(s32);
s32 func_L07_003BADA8(void);

s32 func_L07_003CEC48(void *arg0) {
    void *p;
    s32 a;

    p = *(void **)((u8 *)arg0 + 0x68);
    if (*(s16 *)((u8 *)p + 0x144) != 1) {
        return 0;
    }
    a = *(s32 *)((u8 *)p + 0x420);
    if (a != -1) {
        if (func_L07_003BAC58(D_L07_001DF41C + (a << 8)) == 0) {
            return 0;
        }
    }
    a = *(s32 *)((u8 *)p + 0x424);
    if (a != -1) {
        if (func_L07_003BADA8() == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L07_003CEC48 */

/* localdecomp:start func_L07_003CECD0 */
extern f32 D_L07_001DE720_sda;
__asm__(".extern D_L07_001DE720_sda, 4");

s32 func_L07_003CECD0(u8 a, u8 b) {
    if (a > b) {
        return (s32)((f32)b + D_L07_001DE720_sda * (f32)(a - b)) & 0xFF;
    }
    return (s32)((f32)b - D_L07_001DE720_sda * (f32)(b - a)) & 0xFF;
}
/* localdecomp:end func_L07_003CECD0 */
