#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00130210 */
typedef struct {
    u8 pad0[0x184];
    int f184;
    int f188;
} S_130210;

void func_00130210(S_130210 *s, int *dmv, int *dmvector, int mvx, int mvy)
{
    if (s->f184 == 3) {
        if (s->f188) {
            dmv[0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
            dmv[1] = ((mvy + (mvy > 0)) >> 1) + dmvector[1] - 1;
            dmv[2] = ((3 * mvx + (mvx > 0)) >> 1) + dmvector[0];
            dmv[3] = ((3 * mvy + (mvy > 0)) >> 1) + dmvector[1] + 1;
        } else {
            dmv[0] = ((3 * mvx + (mvx > 0)) >> 1) + dmvector[0];
            dmv[1] = ((3 * mvy + (mvy > 0)) >> 1) + dmvector[1] - 1;
            dmv[2] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
            dmv[3] = ((mvy + (mvy > 0)) >> 1) + dmvector[1] + 1;
        }
    } else {
        dmv[0] = ((mvx + (mvx > 0)) >> 1) + dmvector[0];
        dmv[1] = ((mvy + (mvy > 0)) >> 1) + dmvector[1];
        if (s->f184 == 1) {
            dmv[1]--;
        } else {
            dmv[1]++;
        }
    }
}
/* localdecomp:end func_00130210 */
