#include "common.h"

/* localdecomp:start func_L39_006D6228 */
extern u8 D_00198168[];
extern u8 D_00198190[];
extern u8 D_001981B8[];
extern u8 D_001A5E50[];
extern s32 func_0017DE30(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_0019B818(s32);
extern void func_0019B6F8(s32);

s32 func_L39_006D6228(void *object) {
    s32 local[16];
    u8 *global;
    s32 value;
    local[0] = (s32)D_00198168;
    local[4] = 0;
    local[6] = (s32)D_00198190;
    local[8] = (s32)D_001981B8;
    func_001962D8(func_0017DE30(local, &local[12]));
    if (func_001962E8() != 0) {
        value = *(s32 *)((u8 *)object + 0x14);
        *(s32 *)((u8 *)object + 0x10) = 5;
        if (value == 0) {
            *(s32 *)((u8 *)object + 0x14) = 5;
        }
        return 0;
    }
    global = D_001A5E50;
    global[0x2E6] = 0;
    *(s32 *)(global + 0x2E8) = 0;
    global[0x2E4] = 1;
    func_0019B818(1);
    func_0019B6F8(-1);
    return 1;
}
/* localdecomp:end func_L39_006D6228 */
