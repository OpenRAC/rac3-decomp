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

/* localdecomp:start func_L39_004BC0D8 */
extern s32 D_L39_00443430[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

void func_L39_004BC0D8(void *a) {
    if (D_L39_00443430[0] != 0) {
        ((void (*)(void *))D_L39_00443430[0])(a);
    } else {
        func_L39_004BC6C8(26, 146, 14, 0, 0);
    }
}
/* localdecomp:end func_L39_004BC0D8 */
