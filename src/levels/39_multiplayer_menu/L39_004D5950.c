#include "common.h"

/* localdecomp:start func_L39_004D5950 */
extern void func_L39_004B4AA0(void *);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004D5950(s32 arg) {
    u8 buf[16];
    u8 *p;
    u32 i;
    s32 ok;
    func_L39_004B4AA0(buf);
    ok = ((*(u16 *)buf >> 11) & 7) == arg;
    p = buf;
    for (i = 0; i < 2; i++) {
        p[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    return ok;
}
/* localdecomp:end func_L39_004D5950 */

/* localdecomp:start func_L39_004D5A40 */
extern void func_L39_004B4AA0(void *);
extern s32 func_L39_004D0C78(void);

s32 func_L39_004D5A40(s32 arg) {
    u8 buf[16];
    u8 *p;
    u32 i;
    s32 ok;
    func_L39_004B4AA0(buf);
    ok = ((*(u16 *)buf >> 8) & 7) == arg;
    p = buf;
    for (i = 0; i < 2; i++) {
        p[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
    return ok;
}
/* localdecomp:end func_L39_004D5A40 */
