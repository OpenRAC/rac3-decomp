#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* localdecomp:start func_L13_003AF260 */
extern u8 *D_L13_001DF59C;
extern s32 func_L01_00445AD0(s32, s32, s32);

s32 func_L13_003AF260(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 104);
    u8 *m;

    if (*(s32 *)(p + 996) != 0) {
        *(s32 *)(p + 996) = 0;
        return 1;
    }
    if (*(s16 *)(p + 324) != 1) {
        return 0;
    }
    if (*(s32 *)(p + 924) != -1) {
        m = D_L13_001DF59C + (*(s32 *)(p + 924) << 8);
        if (m != 0 && m[32] != 254 && m[32] != 253) {
            return 0;
        }
    }
    if (*(s32 *)(p + 920) != -1 && func_L01_00445AD0(*(s32 *)(p + 920), -1, 0) != 0) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L13_003AF260 */
