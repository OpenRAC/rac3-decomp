#include "common.h"

/* declared by functions of L39_0068A8F8.c, which this file was cut from */
s32 func_L39_0068B3C0();

/* localdecomp:start func_L39_0068AF68 */
/* defined later in this file with S0_68B3C0 * parameters; declared without prototypes here so the types agree */
s32 func_L39_0068B3C0();
s32 func_L39_0068B1E0();
s32 func_L39_0068B260();
s32 func_L39_0068B2F8();
void func_L39_00688340(s32, s32, s32);
typedef struct { u8 pad[0x284]; s32 unk284; } S_0068AF68;
extern S_0068AF68 *D_L39_00247914[];

s32 func_L39_0068AF68(void *arg0, s32 arg1) {
    s32 idx;

    func_L39_0068B3C0(arg0);
    if (arg1 == 2) {
        idx = func_L39_0068B1E0(arg0, -1);
        if (idx != -1) {
            func_L39_00688340(3, 0, 0);
        }
        func_L39_0068B2F8(arg0, idx, 2);
    } else if (arg1 == 1) {
        idx = func_L39_0068B260(arg0, -1);
        if (idx != -1) {
            func_L39_00688340(3, 0, 0);
        }
        func_L39_0068B2F8(arg0, idx, 1);
    } else if (arg1 == 5) {
        D_L39_00247914[0]->unk284 = 0x2C;
        func_L39_00688340(0x17, 0, 0);
    } else {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_0068AF68 */
