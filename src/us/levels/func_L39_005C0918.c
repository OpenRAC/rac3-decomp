#include "common.h"

typedef struct {
    u8 pad0[4];
    s16 active;
    u8 flag;
    u8 pad7[2];
} Global_L39_005C0918;

/* localdecomp:start func_L39_005C0918 */
extern Global_L39_005C0918 D_002257E0;
extern s32 func_00194BE8(void);

/* Calls func_00194BE8 and sets a flag byte to 1 when the global record's active field is non-zero. */
void func_L39_005C0918(void) {
    if (D_002257E0.active != 0) {
        func_00194BE8();
        D_002257E0.flag = 1;
    }
}
/* localdecomp:end func_L39_005C0918 */
