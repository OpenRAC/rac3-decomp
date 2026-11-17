/* Level 06 shared (src/levels/shared/L06_00351930.c) draft, 2026-11-15. 71 differences with the file's flags (-mvu0-use-vf0-vf2 @ps2as): logic and block order right; retail swaps $t2/$t3 (the object and the count/index variable) and reloads tbl[0] for the loop bound and after the loop where gcc keeps one copy. Struct table, while/do-while loops, a separate found index and declaration orders gave 71-74. func_L06_00352FB0 is the same search with an index out-parameter and will likely need the same fix. */
#include "vu0.h"
#include "common.h"
typedef struct {
    s32 key;
    f32 val;
} E_00353160;
typedef struct {
    u8 pad0[0x274];
    s32 n;
    u8 pad1[0x280 - 0x278];
    E_00353160 e[1];
} O_00353160;
typedef int u128_t __attribute__((mode(TI)));
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
