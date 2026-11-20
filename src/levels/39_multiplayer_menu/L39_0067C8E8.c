#include "common.h"

typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_0067C8E8 */
typedef struct { u8 pad[0x25C]; T t; } S_0067C8E8;
extern S_0067C8E8 D_L39_0025D6C0;
extern void func_L39_0067ED40(void);
extern void func_L39_00685FF0(void);
extern void func_L39_006D78F8(void);
extern void func_00392260(s32, s32, s32);

void func_L39_0067C8E8(void) {
    func_L39_0067ED40();
    func_00392260(D_L39_0025D6C0.t.a, D_L39_0025D6C0.t.b, D_L39_0025D6C0.t.c);
    func_L39_00681470();
    func_L39_00685FF0();
    func_L39_006D78F8();
    func_001953B8(0);
    func_001953D0(0);
}
/* localdecomp:end func_L39_0067C8E8 */
