#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* localdecomp:start func_L39_004FCD58 */
typedef struct O_004FCD58 O_004FCD58;
typedef struct {
    u8 pad0[0x18];
    void (*f18)(O_004FCD58 *, s32, s32, s32, s32);
} V_004FCD58;
struct O_004FCD58 { V_004FCD58 *f0; };
typedef struct { u8 pad0[0xC]; V_004FCD58 *(*fC)(void); } D_004FCD58;
extern D_004FCD58 *func_L39_004DBA08(void);
extern s32 func_L39_004FC158(s32);
extern V_004FCD58 *(*func_L39_004FE608(s32, s32))(void);

void func_L39_004FCD58(O_004FCD58 *obj, s32 a1, s32 a2, s32 a3, s32 a4) {
    V_004FCD58 *(*def)(void) = func_L39_004DBA08()->fC;
    V_004FCD58 *(*f)(void);

    if (a2 == 1 && obj->f0 != 0 && !(a3 & 1)) {
        f = func_L39_004FE608(func_L39_004FC158(a1), 2);
        if (f != 0) {
            obj->f0 = f();
        } else {
            obj->f0 = def();
        }
    }
    obj->f0->f18(obj, a1, a2, a3, a4);
}
/* localdecomp:end func_L39_004FCD58 */
