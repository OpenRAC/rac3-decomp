#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 (*D_L39_004433DC[])(void);
extern s32 (*D_L39_004433E4[])(void);
extern s32 (*D_L39_004433E8[])(void);
extern s32 (*D_L39_004433EC[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004BBD08 */
__asm__(".extern D_L39_004433DC, 16");
extern s32 (*D_L39_004433DC[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7B08 */
s32 func_L39_004BBD08(void) {
    if (D_L39_004433DC[0] != 0) {
        return D_L39_004433DC[0]();
    }
    func_L39_004BC6C8(26, 119, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBD08 */

/* localdecomp:start func_L39_004BBD50 */
__asm__(".extern D_L39_004433E4, 16");
extern s32 (*D_L39_004433E4[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7B50 */
s32 func_L39_004BBD50(void) {
    if (D_L39_004433E4[0] != 0) {
        return D_L39_004433E4[0]();
    }
    func_L39_004BC6C8(26, 114, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBD50 */

/* localdecomp:start func_L39_004BBD98 */
__asm__(".extern D_L39_004433E8, 16");
extern s32 (*D_L39_004433E8[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7B98 */
s32 func_L39_004BBD98(void) {
    if (D_L39_004433E8[0] != 0) {
        return D_L39_004433E8[0]();
    }
    func_L39_004BC6C8(26, 120, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBD98 */

/* localdecomp:start func_L39_004BBDE0 */
__asm__(".extern D_L39_004433EC, 16");
extern s32 (*D_L39_004433EC[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7BE0 */
s32 func_L39_004BBDE0(void) {
    if (D_L39_004433EC[0] != 0) {
        return D_L39_004433EC[0]();
    }
    func_L39_004BC6C8(26, 117, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBDE0 */
