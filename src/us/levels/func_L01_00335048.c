#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[148];
    u8 *(*fn)(u8 *);
} Vt00335B98;
typedef void (*Fn_335C70)(u8 *);
typedef struct {
    u8 pad[0x1E];
    u16 flags;
} Obj_003378A0;


/* localdecomp:start func_L01_00335048 */
s32 func_L01_00335048(u8 *a, u8 *b, u8 *m, u8 *d, s32 value, u8 *cfg, u8 *vt)
{
    extern s32 func_L01_00458AE0(u8 *, s32);
    extern s32 func_L01_00334B28(u8 *, s32, u8 *, u8 *, s32, u8 *);
    extern void func_L01_00455C88(u8 *, void *, s32, s32);
    extern void func_L01_00457440(u8 *, void *);
    if (*(s32 *)(cfg + 0x6C) != -1 && cfg[0x99] == 0 && b[0x5E] == 0) {
        if (func_L01_00458AE0(m, *(s32 *)(cfg + 0x6C))) {
            func_L01_00334B28(a, (s32)b, m, d, value, cfg);
            b[0x5E] = 1;
        }
    } else if (cfg[0x10] != 2 && cfg[0x11] != 2) {
        if (*(s32 *)(cfg + 0x64) != -1 || *(s32 *)(cfg + 0x60) != -1) {
            u8 *position = d + 0x3F0;
            func_L01_00455C88(m, position, 0, 0);
            func_L01_00457440(m, position);
        }
    }
    if (cfg[0x97] == 0) {
        (*(void (**)(u8 *, s32, s32))(vt + 0x24))(m, 0, 10);
    } else {
        (*(void (**)(u8 *, s32, s32))(vt + 0x20))(m, 0, 10);
    }
    return 0;
}
/* localdecomp:end func_L01_00335048 */
