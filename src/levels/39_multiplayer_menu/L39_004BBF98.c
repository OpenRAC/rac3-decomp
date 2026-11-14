#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 (*D_L39_0044340C[])(void);
extern s32 (*D_L39_0044341C[])(void);
extern s32 (*D_L39_00443420[])(void);
extern s32 (*D_L39_0044342C[])(void);
extern s32 (*D_L39_00443428[])(void);
extern s32 (*D_L39_00443440[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* declared by functions of L39_004BBE70.c, which this file was cut from */
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004BBF98 */
typedef struct {
    s32 a;
    s32 pad04;
    long b;
    s32 c;
    s32 pad14[3];
} S_004BBF98;

__asm__(".extern D_L39_00443424, 16");
extern s32 (*D_L39_00443424[])(s32, S_004BBF98 *, S_004BBF98 *);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004BBF98(s32 arg0, s32 *a1, s32 *a2, long *a3, s32 *a4, s32 *a5, long *a6) {
    S_004BBF98 x;
    S_004BBF98 y;
    s32 ret;

    if (D_L39_00443424[0] == 0) {
        func_L39_004BC6C8(26, 123, 14, 0, 0);
        return 0;
    }
    ret = D_L39_00443424[0](arg0, &x, &y);
    if (ret == 1) {
        if (a1 != 0) *a1 = x.a;
        if (a2 != 0) *a2 = x.c;
        if (a3 != 0) *a3 = x.b;
        if (a4 != 0) *a4 = y.a;
        if (a5 != 0) *a5 = y.c;
        if (a6 != 0) *a6 = y.b;
    }
    return ret;
}
/* localdecomp:end func_L39_004BBF98 */

LINKER_REMNANT("asm/levels", func_L39_004BC088);
