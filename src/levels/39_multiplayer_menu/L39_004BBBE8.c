#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 (*D_L39_004433C8[])(void);
extern s32 (*D_L39_004433D0[])(void);
extern s32 (*D_L39_004433D4[])(void);

/* localdecomp:start func_L39_004BBBE8 */
__asm__(".extern D_L39_004433C8, 16");
extern s32 (*D_L39_004433C8[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F79E8 */
s32 func_L39_004BBBE8(void) {
    if (D_L39_004433C8[0] != 0) {
        return D_L39_004433C8[0]();
    }
    func_L39_004BC6C8(26, 150, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBBE8 */

/* localdecomp:start func_L39_004BBC30 */
__asm__(".extern D_L39_004433D0, 16");
extern s32 (*D_L39_004433D0[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004BBC30(void) {
    if (D_L39_004433D0[0] != 0) {
        return D_L39_004433D0[0]();
    }
    func_L39_004BC6C8(26, 106, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBC30 */

/* localdecomp:start func_L39_004BBC78 */
__asm__(".extern D_L39_004433D4, 16");
extern s32 (*D_L39_004433D4[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7A78 */
s32 func_L39_004BBC78(void) {
 if (D_L39_004433D4[0] != 0) { return D_L39_004433D4[0](); }
 func_L39_004BC6C8(26, 105, 14, 0, 0);
 return 0;
}
/* localdecomp:end func_L39_004BBC78 */
