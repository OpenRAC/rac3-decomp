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

/* localdecomp:start func_L39_004BC120 */
__asm__(".extern D_L39_0044343C, 16");
extern s32 (*D_L39_0044343C[])(void);

s32 func_L39_004BC120(void) {
    if (D_L39_0044343C[0] != 0) {
        return D_L39_0044343C[0]();
    }
    return 0;
}
/* localdecomp:end func_L39_004BC120 */

/* localdecomp:start func_L39_004BC150 */
__asm__(".extern D_L39_00443428, 16");
extern s32 (*D_L39_00443428[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7F50 */
s32 func_L39_004BC150(void) {
    if (D_L39_00443428[0] != 0) {
        return D_L39_00443428[0]();
    }
    func_L39_004BC6C8(26, 147, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BC150 */

/* localdecomp:start func_L39_004BC198 */
__asm__(".extern D_L39_00443440, 16");
extern s32 (*D_L39_00443440[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7F98 */
s32 func_L39_004BC198(void) {
 if (D_L39_00443440[0] != 0) { return D_L39_00443440[0](); }
 func_L39_004BC6C8(26, 153, 14, 0, 0);
 return 0;
}
/* localdecomp:end func_L39_004BC198 */
