#include "common.h"

/* localdecomp:start func_L39_004D6488 */
#include "dnas.h"

typedef struct S_004D6488 {
    /* 0x00000 */ u8 pad0[0x10688];
    /* 0x10688 */ u64 f10688;
    /* 0x10690 */ u8 pad10690[0xA8];
    /* 0x10738 */ s32 f10738;
} S_004D6488;

extern S_004D6488 D_L39_00453FB0;
extern char D_L39_00476110[];
extern void func_L39_004BD350(s32, s32, s32, u32);
extern s32 func_L39_004D5950(s32);
extern s32 func_L39_004D0C78(void);
extern char *func_001206F4(char *, char *);
extern s32 func_00120884(char *);
extern s32 func_00128BA8(char *, s32, char *, s32);

static __inline__ void wipe_004D6488(void *buf, u32 n) {
    u8 *q = buf;
    u32 i;

    for (i = 0; i < n; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004D6488(s32 mode, char *buf) {
    char *msg;
    s32 err = 0;

    DNAS_BEGIN(func_L39_004D6488, 0, func_L39_004BD350);
    switch (D_L39_00453FB0.f10738) {
    case -101:
        msg = DNAS_STRING("debug_fermat/ng/busy");
        break;
    case -102:
        msg = DNAS_STRING("debug_fermat/ng/before_dnas_service");
        break;
    case -103:
        msg = DNAS_STRING("debug_fermat/ng/after_dnas_service");
        break;
    case -104:
        msg = DNAS_STRING("debug_fermat/ng/dnas_service_finished");
        break;
    case -105:
        msg = DNAS_STRING("debug_fermat/ng/timeout");
        break;
    case -108:
        msg = DNAS_STRING("debug_fermat/ng/external_error");
        break;
    case -109:
        msg = DNAS_STRING("debug_fermat/ng/different_hdd");
        break;
    case -110:
        msg = DNAS_STRING("debug_fermat/ng/all_ok");
        break;
    case -106:
    case -107:
        msg = DNAS_STRING("debug_fermat/ng/busy");
        break;
    case -201:
    case -202:
    case -203:
    case -204:
        if ((D_L39_00453FB0.f10688 & 0x3F00) != 0x2200) {
            goto connect;
        }
        switch (D_L39_00453FB0.f10738) {
        case -201:
            msg = DNAS_STRING("debug_fermat/down_result/not_exist");
            goto print;
        case -202:
            msg = DNAS_STRING("debug_fermat/down_result/before_service");
            goto print;
        case -203:
            msg = DNAS_STRING("debug_fermat/down_result/service_finished");
            goto print;
        case -204:
            msg = DNAS_STRING("debug_fermat/down_result/not_modified");
            goto print;
        }
    case -701:
    case -702:
    case -703:
        if ((D_L39_00453FB0.f10688 & 0x3800) != 0x800) {
            goto connect;
        }
        switch (D_L39_00453FB0.f10738) {
        case -701:
            msg = DNAS_STRING("debug_fermat/id_result/not_registered");
            goto print;
        case -702:
            msg = DNAS_STRING("debug_fermat/id_result/invalid_category");
            goto print;
        case -703:
            msg = DNAS_STRING("debug_fermat/id_result/not_join_in_this_category");
            goto print;
        }
    default:
        if (D_L39_00453FB0.f10738 < -805 && D_L39_00453FB0.f10738 != -896) {
            msg = DNAS_STRING("debug_fermat/ng/unknown_ng/");
            err = 1;
            break;
        }
        D_L39_00453FB0.f10738 = 0;
    case 0:
    connect:
        if (mode == 0) {
            if (func_L39_004D5950(4) == 0) {
                msg = DNAS_STRING("eu-gw/v2.5_i-connect");
            } else {
                msg = DNAS_STRING("eu-gw/v2.5_d-connect");
            }
        } else {
            msg = DNAS_STRING("eu-gw/v2.5_others");
        }
        break;
    }
print:
    func_001206F4(buf, msg);
    if (err > 0) {
        s32 len = func_00120884(buf);
        s32 n = -800 - D_L39_00453FB0.f10738;
        func_00128BA8(buf + len, 3, D_L39_00476110, n);
    }
    DNAS_END(func_L39_004D6488, 0, func_L39_004BD350);
    wipe_004D6488(&msg, 4);
    wipe_004D6488(&err, 4);
    return func_00120884(buf);
}
/* localdecomp:end func_L39_004D6488 */

INCLUDE_ASM("asm/levels", func_L39_004D6E78);

/* localdecomp:start func_L39_004D73E0 */
#include "dnas.h"

extern void func_L39_004BD350(s32, s32, s32, u32);

void func_L39_004D73E0(void *a0, void *a1, void *a2) {
    u8 *p = (u8 *)a2;
    u16 *h = (u16 *)(p + 2);

    DNAS_BEGIN(func_L39_004D73E0, 0, func_L39_004BD350);
    p[2] = 0;
    p[3] = 0;
    if (a1 != 0) {
        *h |= 0x80;
    }
    *h = (*h & 0xF0FF) | (((s32)a0 & 0xF) << 8);
    do { DNAS_END(func_L39_004D73E0, 0, func_L39_004BD350); } while (0);
}
/* localdecomp:end func_L39_004D73E0 */
