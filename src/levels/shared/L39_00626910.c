#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b0;
    u8 b1;
    u8 b2;
} S_00627EF8;

/* declared by functions of L39_00622990.c, which this file was cut from */
extern u8 D_L39_004997E0[];
extern void func_L39_00623FB8(void *);
extern void func_L39_006244E0(u8 *);

/* localdecomp:start func_L39_00626910 */
extern void func_L39_006323B8(void *, void *, void *, f32);
extern void func_L39_00632328(void *, void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00632558(void *, void *, void *, f32);

void func_L39_00626910(void *arg0, void *arg1, s32 arg2, f32 arg3, f32 arg4)
{
    if (arg2 != 0) {
        func_L39_006323B8(arg0, arg1, arg1, arg3);
        func_L39_00632328(arg0, arg1, arg1, arg4);
    } else {
        func_L39_00632298(arg0, arg1, arg1, arg3);
        func_L39_00632558(arg0, arg1, arg1, arg4);
    }
}
/* localdecomp:end func_L39_00626910 */

/* localdecomp:start func_L39_00626998 */
typedef struct Vt_00626998 {
    u8 pad0[0x1C];
    s32 (*f1C)(void *, s32);
} Vt_00626998;

typedef struct Ob_00626998 {
    s32 f0;
    u8 pad4[0x10];
    Vt_00626998 *f14;
    u8 pad18[0x18];
    struct Ob_00626998 *f30;
} Ob_00626998;

typedef struct Pn_00626998 {
    u8 pad0[0x68];
    Ob_00626998 *f68;
    u8 pad6C[0x3E];
    s16 hAA;
    u8 padAC[0xC];
    struct Pn_00626998 *fB8;
} Pn_00626998;

extern Ob_00626998 *func_L39_0061CF40(Pn_00626998 *);
extern Ob_00626998 *func_L39_0061D7B0(Pn_00626998 *);

s32 func_L39_00626998(u8 *g, Pn_00626998 *p, s32 flag) {
    s32 found;
    Ob_00626998 *obj;
    Ob_00626998 *a;
    Ob_00626998 *o2;

    found = 0;
    if (p != 0) {
        obj = func_L39_0061CF40(p);
    } else {
        obj = 0;
    }
    if (obj != 0) {
        if (obj->f14->f1C(obj, *(s32 *)(g + 0x2548)) != 0) {
            if (flag != 0) {
                *(s32 *)(g + 0x24CC) = obj->f0;
            }
            return 0;
        }
        switch (p->hAA) {
        case 0x1095:
            *(s32 *)(g + 0x24D0) = 1;
            break;
        case 0x1087:
            *(s32 *)(g + 0x24D0) = 2;
            break;
        case 0x1096:
        case 0x1097:
            *(s32 *)(g + 0x24D0) = 3;
            break;
        case 0x108C:
            *(s32 *)(g + 0x24D0) = 4;
            break;
        case 0x18AB:
            *(s32 *)(g + 0x24D0) = 10;
            break;
        case 0x1099:
            *(s32 *)(g + 0x24D0) = 6;
            break;
        case 0x10A4:
            *(s32 *)(g + 0x24D0) = 7;
            break;
        case 0x108F:
            *(s32 *)(g + 0x24D0) = 5;
            break;
        default:
            *(s32 *)(g + 0x24D0) = -1;
            break;
        }
        *(s32 *)(g + 0x24CC) = obj->f0;
    } else {
        while (p != 0 && p->fB8 != 0 && p->fB8 != p) {
            switch (p->hAA) {
            case 0x1094:
                *(s32 *)(g + 0x24D0) = 1;
                break;
            case 0x1087:
                *(s32 *)(g + 0x24D0) = 2;
                break;
            case 0x1096:
                *(s32 *)(g + 0x24D0) = 3;
                break;
            case 0x108A:
                *(s32 *)(g + 0x24D0) = 5;
                break;
            case 0x1089:
                *(s32 *)(g + 0x24D0) = 4;
                break;
            case 0x18AB:
                *(s32 *)(g + 0x24D0) = 10;
                break;
            case 0x1098:
                *(s32 *)(g + 0x24D0) = 6;
                break;
            case 0x10A4:
                *(s32 *)(g + 0x24D0) = 7;
                break;
            case 0x108F:
                *(s32 *)(g + 0x24D0) = 5;
                o2 = p->f68;
                if (o2 != 0) {
                    a = o2->f30;
                    if (a != 0) {
                        found = 1;
                        if (a->f14->f1C(a, *(s32 *)(g + 0x2548)) != 0) {
                            *(s32 *)(g + 0x24D0) = -1;
                            return 0;
                        }
                        *(s32 *)(g + 0x24CC) = o2->f30->f0;
                    }
                }
                break;
            case 0x16DB:
            case 0x1700:
            case 0x1900:
            case 0x1902:
            case 0x1904:
            case 0x1ADC:
            case 0x1B00:
            case 0x1CF0 ... 0x1CFE:
            case 0x1D00:
            case 0x1D02:
            case 0x1D04:
            case 0x1E59:
            case 0x1E5B:
            case 0x1E5D:
            case 0x1E5F:
            case 0x1E77:
            case 0x1E78:
            case 0x1E7A:
            case 0x1E7C:
                break;
            }
            if (found != 0) {
                return 1;
            }
            p = p->fB8;
        }
        if (found != 0) {
            return 1;
        }
        obj = func_L39_0061D7B0(p);
        if (obj != 0) {
            if (obj->f14->f1C(obj, *(s32 *)(g + 0x2548)) != 0) {
                if (flag != 0) {
                    *(s32 *)(g + 0x24CC) = obj->f0;
                }
                return 0;
            }
            *(s32 *)(g + 0x24CC) = obj->f0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00626998 */

/* localdecomp:start func_L39_00626D18 */
void func_L39_00626D18(u8 *p) {
    *(s32 *)(p + 9424) = -1;
    *(u32 *)(p + 9420) = 0xFFFFFFFFU;
    *(s32 *)(p + 9308) = 0;
}
/* localdecomp:end func_L39_00626D18 */
