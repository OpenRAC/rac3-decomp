#include "common.h"

/* localdecomp:start func_L39_006899D8 */
typedef struct {
    u8 p0[0x2B8];
    u8 f2B8;
    u8 p2B9[0x338 - 0x2B9];
    s32 f338;
} Menu_L39_006899D8;
typedef struct {
    u8 p0[0x50];
    s32 f50;
} G_L39_006899D8;

extern G_L39_006899D8 *D_L39_0024D860;
__asm__(".extern D_L39_0024D860, 16");
extern char *func_0037DF98(s32);
extern void func_L39_00686F20(void *, char *);
extern s32 func_L39_006D9F70(s32, s32);

s32 func_L39_006899D8(Menu_L39_006899D8 *obj) {
    s32 r;

    func_L39_00686F20(obj, func_0037DF98(0xF6D));
    obj->f338++;
    r = func_L39_006D9F70(D_L39_0024D860->f50, 0);
    if (r != 0) {
        func_L39_00686F20(obj, func_0037DF98(0xF6E));
    } else {
        func_L39_00686F20(obj, func_0037DF98(0xF6F));
    }
    obj->f2B8 = 0;
    obj->f338--;
    return r;
}
/* localdecomp:end func_L39_006899D8 */
