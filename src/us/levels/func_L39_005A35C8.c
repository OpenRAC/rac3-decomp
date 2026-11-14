#include "common.h"

/* localdecomp:start func_L39_005A35C8 */
typedef struct {
    u8 reserved0[0x164];
    s32 previous;
    s32 current;
} State_L39_005A35C8;

extern State_L39_005A35C8 D_001A4560;

/* Resets the two state values (previous and current) in D_001A4560 to -1 and sets a global mode
 * value to 6. */
void func_L39_005A35C8(void) {
    D_001A4560.previous = -1;
    *(s32 *)0x00240578 = 6;
    D_001A4560.current = -1;
}
/* localdecomp:end func_L39_005A35C8 */
