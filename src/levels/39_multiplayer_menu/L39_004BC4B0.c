#include "common.h"

/* declared by functions of L39_004BB4C0.c, which this file was cut from */
extern s32 D_L39_00443498[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* localdecomp:start func_L39_004BC4B0 */
extern s32 D_L39_00443498[];
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

void func_L39_004BC4B0(void *a) {
    if (D_L39_00443498[0] != 0) {
        ((void (*)(void *))D_L39_00443498[0])(a);
    } else {
        func_L39_004BC6C8(26, 136, 14, 0, 0);
    }
}
/* localdecomp:end func_L39_004BC4B0 */

/* localdecomp:start func_L39_004BC4F8 */
/* the name of an X.520 attribute (2.5.4.n, DER 55 04 n): flag != 0 gives the short name, 0 the long one */
extern char D_L39_004751C0[];
extern char D_L39_004751D0[];
extern char D_L39_004751D8[];
extern char D_L39_004751E0[];
extern char D_L39_004751E8[];
extern char D_L39_004751F8[];
extern char D_L39_00475200[];
extern char D_L39_00475210[];
extern char D_L39_00475218[];
extern char D_L39_00475228[];
extern char D_L39_00475230[];
extern char D_L39_00475248[];
extern char D_L39_00475250[];
extern char D_L39_00475268[];
extern char D_L39_00475270[];
extern char D_L39_00475288[];
extern char D_L39_00475290[];
extern char D_L39_00475298[];
extern char D_L39_004752A0[];
extern char D_L39_004752B0[];
extern char D_L39_004752B8[];
extern char D_L39_004752C8[];
extern char D_L39_004752D0[];
extern char D_L39_004752E0[];
extern char D_L39_004752E8[];
extern char D_L39_00475300[];

char *func_L39_004BC4F8(u8 *p, s32 len, s32 flag) {
    if (len != 3) {
        return 0;
    }
    if (p[0] != 0x55 || p[1] != 4) {
        return 0;
    }
    switch (p[2]) {
    case 3:
        return flag == 0 ? D_L39_004751C0 : D_L39_004751D0;
    case 4:
        return flag == 0 ? D_L39_004751D8 : D_L39_004751E0;
    case 5:
        return flag == 0 ? D_L39_004751E8 : D_L39_004751F8;
    case 6:
        return flag == 0 ? D_L39_00475200 : D_L39_00475210;
    case 7:
        return flag == 0 ? D_L39_00475218 : D_L39_00475228;
    case 8:
        return flag == 0 ? D_L39_00475230 : D_L39_00475248;
    case 10:
        return flag == 0 ? D_L39_00475250 : D_L39_00475268;
    case 11:
        return flag == 0 ? D_L39_00475270 : D_L39_00475288;
    case 12:
        return flag == 0 ? D_L39_00475290 : D_L39_00475298;
    case 13:
        return flag == 0 ? D_L39_004752A0 : D_L39_004752B0;
    case 42:
        return flag == 0 ? D_L39_004752B8 : D_L39_004752C8;
    case 43:
        return flag == 0 ? D_L39_004752D0 : D_L39_004752E0;
    case 45:
        return flag == 0 ? D_L39_004752E8 : D_L39_00475300;
    }
    return 0;
}
/* localdecomp:end func_L39_004BC4F8 */

INCLUDE_ASM("asm/levels", func_L39_004BC6C8);

/* localdecomp:start func_L39_004BC880 */
s64 func_L39_004BC880(s64 *arg0) {
    return *arg0 * 13;
}
/* localdecomp:end func_L39_004BC880 */

/* localdecomp:start func_L39_004BC898 */
s32 func_L39_004BC898(s64 *arg0, s64 *arg1) {
    return *arg0 - *arg1;
}
/* localdecomp:end func_L39_004BC898 */

/* localdecomp:start func_L39_004BC8B0 */
/* OpenSSL's ERR_get_state (err.c): CRYPTO_thread_id, CRYPTO_lock, lh_new, lh_retrieve, Malloc, lh_insert, ERR_STATE_free */
typedef struct ERR_STATE_004BC8B0 {
    unsigned long pid;
    unsigned long err_buffer[16];
    char *err_data[16];
    s32 err_data_flags[16];
    const char *err_file[16];
    s32 err_line[16];
    s32 top;
    s32 bottom;
} ERR_STATE_004BC8B0;

typedef struct G_004BC8B0 {
    u8 pad0[8];
    void *thread_hash;
} G_004BC8B0;

extern G_004BC8B0 *func_L39_004DBA08(void);
extern s64 func_L39_004BEDB0(void);
extern s32 func_L39_004BECC0(s32, s32, char *, s32);
extern void *func_L39_004BCA88(void *, void *);
extern void *func_L39_004BCDE0(void *, void *);
extern void *func_L39_004BEED8(s32);
extern void *func_L39_004BCC38(void *, void *);
extern void func_L39_004DDFC8(void *);
extern s64 func_L39_004BC880(s64 *);
extern s32 func_L39_004BC898(s64 *, s64 *);
extern char D_L39_004753C0[];
extern ERR_STATE_004BC8B0 D_L39_004434A0;

void *func_L39_004BC8B0(void) {
    ERR_STATE_004BC8B0 *ret = 0;
    ERR_STATE_004BC8B0 tmp;
    ERR_STATE_004BC8B0 *tmpp;
    G_004BC8B0 *g;
    s32 i;
    unsigned long pid;

    g = func_L39_004DBA08();
    pid = func_L39_004BEDB0();

    func_L39_004BECC0(5, 1, D_L39_004753C0, 0x2AE);
    if (g->thread_hash == 0) {
        func_L39_004BECC0(6, 1, D_L39_004753C0, 0x2B5);
        func_L39_004BECC0(9, 1, D_L39_004753C0, 0x2B6);
        if (g->thread_hash == 0) {
            g->thread_hash = func_L39_004BCA88(func_L39_004BC880, func_L39_004BC898);
            func_L39_004BECC0(10, 1, D_L39_004753C0, 0x2BC);
            if (g->thread_hash == 0) {
                return &D_L39_004434A0;
            }
        } else {
            func_L39_004BECC0(10, 1, D_L39_004753C0, 0x2C9);
        }
    } else {
        tmp.pid = pid;
        ret = func_L39_004BCDE0(g->thread_hash, &tmp);
        func_L39_004BECC0(6, 1, D_L39_004753C0, 0x2D4);
    }

    if (ret == 0) {
        ret = func_L39_004BEED8(sizeof(ERR_STATE_004BC8B0));
        if (ret == 0) {
            return &D_L39_004434A0;
        }
        ret->pid = pid;
        ret->top = 0;
        ret->bottom = 0;
        for (i = 0; i < 16; i++) {
            ret->err_data[i] = 0;
            ret->err_data_flags[i] = 0;
        }
        func_L39_004BECC0(9, 1, D_L39_004753C0, 0x2EA);
        tmpp = func_L39_004BCC38(g->thread_hash, ret);
        func_L39_004BECC0(10, 1, D_L39_004753C0, 0x2F1);
        if (tmpp != 0) {
            func_L39_004DDFC8(tmpp);
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004BC8B0 */
