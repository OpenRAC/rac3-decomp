/* functional: medium. check.py at level_06: 71 diffs (register swap of object/index and reload of tbl[0] vs one copy); the search logic and block order are as retail per the draft. */
#include "vu0.h"
#include "common.h"
s32 func_L06_00352E20(O_00353160 *o, s32 dir, s32 k, void *out) {
    s32 n = o->n;
    s32 i;
    s32 *tbl;

    if (n == 0 || k < o->e[0].key) {
    none:
        qzero(out);
        return 0;
    }
    for (; k >= 0; k--) {
        for (i = n - 1; i >= 0; i--) {
            if (o->e[i].key == k) {
                break;
            }
        }
        if (i >= 0) {
            if (!(0.0f < o->e[i].val)) {
                goto none;
            }
            n = i;
            tbl = *(s32 **)((u8 *)o + 0x358);
            if (dir <= 0) {
                for (k++; k < tbl[0]; k++) {
                    for (i = n + 1; i < o->n; i++) {
                        if (o->e[i].key == k) {
                            break;
                        }
                    }
                    if (i != o->n) {
                        n = i;
                        break;
                    }
                }
                if (k == tbl[0]) {
                    *(u128_t *)out = *(u128_t *)(tbl + k * 4);
                    return 1;
                }
            }
            *(u128_t *)out = *(u128_t *)(tbl + 4 + o->e[n].key * 4);
            return 1;
        }
    }
    return 0;
}
