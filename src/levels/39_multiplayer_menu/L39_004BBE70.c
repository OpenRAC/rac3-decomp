#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 (*D_L39_0044340C[])(void);
extern s32 (*D_L39_0044341C[])(void);
extern s32 (*D_L39_00443420[])(void);
extern s32 (*D_L39_0044342C[])(void);
extern s32 (*D_L39_00443428[])(void);
extern s32 (*D_L39_00443440[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004BBE70 */
__asm__(".extern D_L39_0044340C, 16");
extern s32 (*D_L39_0044340C[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7C70 */
s32 func_L39_004BBE70(void) {
 if (D_L39_0044340C[0] != 0) { return D_L39_0044340C[0](); }
 func_L39_004BC6C8(26, 121, 14, 0, 0);
 return 0;
}
/* localdecomp:end func_L39_004BBE70 */

/* localdecomp:start func_L39_004BBEB8 */
__asm__(".extern D_L39_00443410, 16");
extern s32 (*D_L39_00443410[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004BBEB8(void) {
    if (D_L39_00443410[0] != 0) {
        return D_L39_00443410[0]();
    }
    func_L39_004BC6C8(26, 125, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBEB8 */

LINKER_REMNANT("asm/levels", func_L39_004BBF00);

/* localdecomp:start func_L39_004BBF08 */
__asm__(".extern D_L39_0044341C, 16");
extern s32 (*D_L39_0044341C[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7D08 */
s32 func_L39_004BBF08(void) {
    if (D_L39_0044341C[0] != 0) {
        return D_L39_0044341C[0]();
    }
    func_L39_004BC6C8(26, 127, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBF08 */

/* localdecomp:start func_L39_004BBF50 */
__asm__(".extern D_L39_00443420, 16");
extern s32 (*D_L39_00443420[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7D50 */
s32 func_L39_004BBF50(void) {
    if (D_L39_00443420[0] != 0) {
        return D_L39_00443420[0]();
    }
    func_L39_004BC6C8(26, 126, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBF50 */
