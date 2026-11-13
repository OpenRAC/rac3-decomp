#include "common.h"

/* localdecomp:start func_L39_006C40A8 */
__asm__(".extern D_L39_0024D760, 16");
extern u8 *D_L39_0024D760;
extern s32 func_0038CAD0(void *);
extern void func_L39_006CEA18(void *, s32);
extern s32 func_L39_006D2F18(void *, void *, void *);
extern void func_L39_006C3778(void *, s32, s32, s32);

s32 func_L39_006C40A8(u8 *obj) {
    s32 buf[2];
    void *h = *(void **)(D_L39_0024D760 + 0x38);
    func_0038CAD0(obj + 0x2C4);
    if (*(s32 *)(obj + 0x2C4) <= 0) {
        s32 r;
        func_L39_006CEA18(h, 0);
        if (*(s32 *)(obj + 0x2CC) == 2) {
            if (func_L39_006D2F18(h, &buf[0], &buf[1]) == 0) {
                func_L39_006C3778(obj, 1, 0, -1);
                return 1;
            }
            r = 0x2EE;
        } else {
            r = 0x7530;
        }
        *(s32 *)(obj + 0x2C4) = r;
    }
    return 0;
}
/* localdecomp:end func_L39_006C40A8 */
