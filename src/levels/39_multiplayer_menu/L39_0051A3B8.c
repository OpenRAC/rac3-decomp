#include "common.h"

/* localdecomp:start func_L39_0051A3B8 */
typedef struct S_0051A3B8 { char pad[0x14]; char f14[0x40]; s32 f54; } S_0051A3B8;
extern S_0051A3B8 *func_L39_005190E8(s32);
extern void func_L39_005190C8(void);
extern void func_148A68(void *, s32, s32, s32);
extern s32 func_L39_00519058(void);
extern s32 func_L39_005192A8(S_0051A3B8 *, s32);
s32 func_L39_0051A3B8(s32 arg) {
    S_0051A3B8 *p = func_L39_005190E8(0);
    if (p == 0) return -1;
    func_L39_005190C8();
    func_148A68(p->f14, p->f54, 0, 0x52534C56);
    if (func_L39_00519058() < 0) {
        return func_L39_005192A8(p, -1);
    }
    return func_L39_005192A8(p, 0);
}
/* localdecomp:end func_L39_0051A3B8 */
