#include "common.h"

/* localdecomp:start func_L39_005A35F0 */
typedef struct {
    u8 reserved0[0x164];
    s32 previous;
    s32 current;
} State_L39_005A35F0;

extern State_L39_005A35F0 D_001A4560;

/* Sets the previous and current values of the global state record D_001A4560 to -1 and sets the
 * global at 0x240578 to 6. */
void func_L39_005A35F0(void) {
    D_001A4560.previous = -1;
    *(s32 *)0x00240578 = 6;
    D_001A4560.current = -1;
}
/* localdecomp:end func_L39_005A35F0 */
