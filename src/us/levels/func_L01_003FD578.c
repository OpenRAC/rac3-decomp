#include "common.h"

/* localdecomp:start func_L01_003FD578 */
typedef struct {
    s32 values[10];
} State_L01_003FD578;

extern State_L01_003FD578 D_L01_001E68D0[];

/* Stores ten values into slot `index` (ignored when index is 32 or more) of a table of ten-word
 * records; the tenth value is stored as tenth * 45 + 240. */
void func_L01_003FD578(s32 first, s32 second, s32 third, s32 fourth, s32 fifth,
                        s32 sixth, s32 seventh, s32 eighth, s32 ninth, s32 tenth, u32 index) {
    if (index >= 32u) {
        return;
    }
    D_L01_001E68D0[index].values[0] = first;
    D_L01_001E68D0[index].values[1] = second;
    D_L01_001E68D0[index].values[2] = third;
    D_L01_001E68D0[index].values[3] = fourth;
    D_L01_001E68D0[index].values[4] = fifth;
    D_L01_001E68D0[index].values[5] = sixth;
    D_L01_001E68D0[index].values[6] = seventh;
    D_L01_001E68D0[index].values[7] = eighth;
    D_L01_001E68D0[index].values[8] = ninth;
    D_L01_001E68D0[index].values[9] = tenth * 45 + 240;
}
/* localdecomp:end func_L01_003FD578 */
