/* functional: medium. check.py at level_06: 54 instruction diffs (register allocation of object/index, same as func_L06_00352E20's); structure re-derived block by block from the assembly. Differs from 352E20: early-out returns 1 with the table's first vector, not-found-positive writes -1 to the index out-parameter. */
#include "vu0.h"
#include "common.h"
s32 func_L06_00352FB0(O_00353160 *o, s32 dir, s32 k, void *out, s32 *idx) {
    s32 n = o->n;
    s32 i;
    s32 *tbl;

    if (n == 0 || k < o->e[0].key) {
        tbl = *(s32 **)((u8 *)o + 0x358);
        *(u128_t *)out = *(u128_t *)(tbl + 4);
        return 1;
    }
    for (; k >= 0; k--) {
        for (i = n - 1; i >= 0; i--) {
            if (o->e[i].key == k) {
                break;
            }
        }
        if (i >= 0) {
            if (!(0.0f < o->e[i].val)) {
                qzero(out);
                if (idx != 0) {
                    *idx = -1;
                }
                return 0;
            }
            if (idx != 0) {
                *idx = i;
            }
            tbl = *(s32 **)((u8 *)o + 0x358);
            if (dir <= 0) {
                for (k++; k < tbl[0]; k++) {
                    s32 j;
                    for (j = i + 1; j < o->n; j++) {
                        if (o->e[j].key == k) {
                            break;
                        }
                    }
                    if (j != o->n) {
                        i = j;
                        break;
                    }
                }
                if (k == tbl[0]) {
                    *(u128_t *)out = *(u128_t *)(tbl + k * 4);
                    return 1;
                }
            }
            *(u128_t *)out = *(u128_t *)(tbl + 4 + o->e[i].key * 4);
            return 1;
        }
    }
    return 0;
}
