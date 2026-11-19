#include "common.h"

/* localdecomp:start func_L04_004C1158 */
typedef struct O_004C1158 { u8 p0[0x20]; u8 f20; u8 p21[0x74]; u8 f95; } O_004C1158;
typedef s32 (*F_004C1158)(O_004C1158 *);
typedef struct { u8 p0[4]; F_004C1158 *f4; u8 p8[4]; F_004C1158 *fC; s32 f10; } T_004C1158;

s32 func_L04_004C1158(O_004C1158 *o, T_004C1158 *t) {
    s32 i = 0;
    s32 r = 0;

    while (i < t->f10) {
        if (t->f4 != 0 && t->f4[o->f95] != 0) {
            while (i < t->f10) {
                r = t->f4[o->f95](o);
                switch (r) {
                case 4:
                    return 1;
                case 5:
                    return 0;
                case 2:
                    i++;
                    continue;
                }
                break;
            }
            if (r == 3) {
                i++;
                continue;
            }
        }
        if (t->fC == 0 || t->fC[o->f20] == 0) {
            return 1;
        }
        while (i < t->f10) {
            r = t->fC[o->f20](o);
            switch (r) {
            case 4:
                return 1;
            case 5:
                return 0;
            case 2:
                i++;
                continue;
            }
            break;
        }
        if (r != 3) {
            break;
        }
        i++;
    }
    return 1;
}
/* localdecomp:end func_L04_004C1158 */
