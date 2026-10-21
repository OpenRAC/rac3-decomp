#include "common.h"

/* localdecomp:start func_L39_005C1018 */
typedef struct {
    u8 data[36];
} Entry36;

extern s16 D_L39_002723B0[];
extern u8 D_L39_002722C0[];
extern u8 D_L39_00274790[];
extern Entry36 D_L39_004B2920[];

Entry36 *func_L39_005C1018(u8 *a0) {
    u8 i = a0[34];
    if (D_L39_002723B0[i] != *(s16 *)(a0 + 170)) {
        return &D_L39_004B2920[D_L39_00274790[i]];
    }
    return &D_L39_004B2920[D_L39_002722C0[i]];
}
/* localdecomp:end func_L39_005C1018 */
