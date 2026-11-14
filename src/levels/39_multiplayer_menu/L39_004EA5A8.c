#include "common.h"

/* localdecomp:start func_L39_004EA5A8 */
typedef struct S_004EA5A8 {
    char _p0[0x4];
    s32 f4;
} S_004EA5A8;
typedef struct R_004EA5A8 {
    char _p0[0xC];
    u8 *fC;
    s32 f10;
} R_004EA5A8;
extern s32 func_L39_004E4AE8(s32, s32, s32, s32 *, void *, s32);

s32 func_L39_004EA5A8(S_004EA5A8 *a0) {
    s32 n = 0;
    R_004EA5A8 *r = 0;
    s32 t = 0;

    func_L39_004E4AE8(a0->f4, 0x10, 0x10, &t, &r, 0);
    if (r != 0) {
        n = r->f10;
        if (r->fC[0] == 0) {
            n--;
        }
    }
    return n;
}
/* localdecomp:end func_L39_004EA5A8 */

/* localdecomp:start func_L39_004EA610 */
typedef struct S_004EA610 {
    char _p0[0x4];
    s32 f4;
} S_004EA610;
typedef struct R_004EA610 {
    char _p0[0x10];
    u32 f10;
} R_004EA610;
extern void *func_L39_004EAC08(void *);
extern s32 func_L39_004E4AE8(s32, s32, s32, s32 *, void *, s32);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_004E2E50(void *, s32, s32, u32, s32, s32, s32);
extern s32 func_0011D2EC(void *, void *, s32);

s32 func_L39_004EA610(s32 a0, u8 *a1, u32 a2, s32 a3, s32 a4, S_004EA610 *a5) {
    s32 ret = 0;
    u8 *buf = 0;
    void *p;
    R_004EA610 *r = 0;
    s32 t = 0;
    u32 len;

    p = func_L39_004EAC08(a5);
    if (p != 0 && func_L39_004E4AE8(a5->f4, 0x10, 0x10, &t, &r, 0) == 0 && r != 0) {
        len = r->f10;
        buf = func_L39_004BEED8(len);
        if (buf != 0 && func_L39_004E2E50(p, (s32)buf, (s32)&len, len, a3, a4, 0) == 0) {
            if (a2 != 0 && a2 < len && func_0011D2EC(a1, buf + (len - a2), a2) == 0) {
                ret = 1;
            } else {
                ret = 0;
            }
        }
    }
    if (buf != 0) {
        func_L39_004BEF28(buf);
    }
    return ret;
}
/* localdecomp:end func_L39_004EA610 */

/* localdecomp:start func_L39_004EA748 */
extern void *func_L39_004EAC08(void *);
extern s32 func_L39_004E3028(void *, s32, s32, s32 *);
extern s32 func_L39_00505620(u8 *, s32 *, s32, u8 *, void *, s32);
extern s32 func_L39_00505360(void *, s32, s32, s32, s32, s32, s32);
extern u8 D_L39_00477560[];
extern u8 D_L39_00477570[];
extern u8 D_L39_00477578[];
extern u8 D_L39_00477580[];
extern u8 D_L39_00477590[];

s32 func_L39_004EA748(s32 type, void *data, s32 len, u8 *buf, s32 a4, void *a5) {
    s32 ret = -1;
    void *p;
    u8 *name;
    s32 ctx;
    s32 size;

    p = func_L39_004EAC08(a5);
    if (p != 0 && func_L39_004E3028(p, 0x103, 0, &ctx) == 0) {
        switch (type) {
        case 4:
            name = D_L39_00477560;
            break;
        case 0x29:
            name = D_L39_00477570;
            break;
        case 0x40:
            name = D_L39_00477578;
            break;
        case 3:
            name = D_L39_00477580;
            break;
        case 0x75:
            name = D_L39_00477590;
            break;
        default:
            goto end;
        }
        func_L39_00505620(buf, &size, 10000, name, data, len);
        if (func_L39_00505360(p, (s32)buf, a4, ctx, (s32)buf, size, 0) == 0) {
            ret = ctx;
        }
    }
end:
    return ret;
}
/* localdecomp:end func_L39_004EA748 */

/* localdecomp:start func_L39_004EA8A0 */
extern void *func_L39_004EAC08(void *);
extern s32 func_L39_004E2EA0(void *, s32, s32, u32, s32, s32, s32);

s32 func_L39_004EA8A0(s32 a0, s32 a1, s32 a2, void *a3, s32 a4) {
    s32 flag = 0x800;
    s32 ret = 0;
    void *p;
    s32 buf[1];

    if (a4 != 2) {
        flag = 0;
    }
    p = func_L39_004EAC08(a3);
    if (p != 0) {
        if (func_L39_004E2EA0(p, a2, (s32)buf, 0xFFFFFFFF, a1, a0, flag) == 0) {
            ret = buf[0];
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004EA8A0 */

/* localdecomp:start func_L39_004EA938 */
extern void *func_L39_004EAC08(void *);
extern s32 func_L39_004E2E00(void *, s32, s32, u32, s32, s32, s32);

s32 func_L39_004EA938(s32 arg0, u8 *arg1, u8 *arg2, s32 *arg3, s32 arg4) {
    s32 buf[2];
    s32 flags;
    void *obj;
    s32 ret;

    flags = 0x800;
    if (arg4 != 2) {
        flags = 0;
    }
    ret = 0;
    obj = func_L39_004EAC08(arg3);
    if (obj != 0) {
        if (func_L39_004E2E00(obj, (s32)arg2, (s32)buf, 0xFFFFFFFF, (s32)arg1, arg0, flags) == 0) {
            ret = buf[0];
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004EA938 */

/* localdecomp:start func_L39_004EA9D0 */
extern void *func_L39_004EAC08(void *);
extern s32 func_L39_004E2E50(void *, s32, s32, u32, s32, s32, s32);

s32 func_L39_004EA9D0(s32 a0, s32 a1, s32 a2, void *a3, s32 a4) {
    s32 flag = 0x800;
    s32 ret = 0;
    void *p;
    s32 buf[1];

    if (a4 != 2) {
        flag = 0;
    }
    p = func_L39_004EAC08(a3);
    if (p != 0) {
        if (func_L39_004E2E50(p, a2, (s32)buf, 0xFFFFFFFF, a1, a0, flag) == 0) {
            ret = buf[0];
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004EA9D0 */

/* localdecomp:start func_L39_004EAA68 */
typedef struct S_004EAA68 {
    char _p0[0x4];
    void *f4;
} S_004EAA68;
extern void *func_L39_004EA4A8(void);
extern void func_L39_004EA410(void *);
extern s32 func_L39_00505718(void *, s32, s32, s32 *);
extern s32 func_L39_00505838(void *, s32);

S_004EAA68 *func_L39_004EAA68(S_004EAA68 **a, s32 *pp, s32 length) {
    S_004EAA68 *ret = 0;
    s32 buf[1];

    if (a != 0) {
        ret = *a;
    }
    if (ret == 0) {
        ret = func_L39_004EA4A8();
    }
    if (ret != 0) {
        if (func_L39_00505718(ret->f4, *pp, length, buf) != 0 || func_L39_00505838(ret->f4, 0) != 0) {
            if (a == 0 || *a != ret) {
                func_L39_004EA410(ret);
            }
            ret = 0;
        }
        if (ret != 0 && a != 0) {
            *a = ret;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004EAA68 */
