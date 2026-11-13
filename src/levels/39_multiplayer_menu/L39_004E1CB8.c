#include "common.h"

/* localdecomp:start func_L39_004E1CB8 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004E1CB8(u8 **arg0, u8 *arg1, s32 arg2) {
    u8 *p;
    s32 i;
    s32 v;
    u8 *q;
    s32 len;
    u8 t;

    p = *arg0;
    for (i = 0; i < arg2; i++) {
        arg1[i] = 0;
    }
    len = arg2 * 2;
    for (i = 0; i < len; i++) {
        if ((u8)(*p - '0') < 10) {
            v = *p - '0';
        } else if ((u8)(*p - 'A') < 6) {
            v = *p - 'A' + 10;
        } else if ((u8)(*p - 'a') < 6) {
            v = *p - 'a' + 10;
        } else {
            func_L39_004BC6C8(9, 0x65, 0x67, 0, 0);
            return 0;
        }
        p++;
        q = &arg1[i / 2];
        t = *q;
        if (i % 2 == 0) {
            *q = t | (v << 4);
        } else {
            *q = t | v;
        }
    }
    *arg0 = p;
    return 1;
}
/* localdecomp:end func_L39_004E1CB8 */

/* localdecomp:start func_L39_004E1DC8 */
extern void *func_L39_004DB110(void);
extern void *func_L39_00504528(void);
extern s32 func_L39_004FB898(void *, char *, s32);
extern s32 func_L39_004DB1C0(void *, s32);
extern s32 func_L39_005045C0(void *, u8 *, s32 *, u8 *, s32);
extern void func_L39_005045A8(void *);
extern s32 func_L39_00504970(void *, u8 *, s32 *);
extern void func_L39_004BEF28(void *);
extern void func_L39_004DB168(void *);
extern void func_L39_00504588(void *);
extern s32 func_00120B70(char *, char *, s32);
extern s32 func_00120884(char *);
extern void *func_00120D28(void *, void *, s32);
extern char D_L39_00477358[];
extern char D_L39_00477368[];
extern char D_L39_00477370[];

typedef struct S_004E1DC8 {
    s32 f0;
    char *f4;
    s32 f8;
} S_004E1DC8;

/* from OpenSSL's PEM_read_bio (crypto/pem/pem_lib.c) */
s32 func_L39_004E1DC8(void *bp, char **out1, char **out2, char **out3, long *out4) {
    long len;
    s32 end = 0, i, k, bl = 0, hl = 0, nohead = 0, m;
    char buf[0x100];
    S_004E1DC8 *nameB;
    S_004E1DC8 *headerB;
    S_004E1DC8 *dataB;
    S_004E1DC8 *tmpB;
    void *ctx;

    nameB = func_L39_004DB110();
    nohead = 0;
    headerB = func_L39_004DB110();
    dataB = func_L39_004DB110();
    ctx = func_L39_00504528();
    if (nameB == 0 || headerB == 0 || dataB == 0 || ctx == 0) {
        func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
        goto err;
    }
    buf[0xFE] = 0;
    for (;;) {
        i = func_L39_004FB898(bp, buf, 0xFE);
        if (i <= 0) {
            func_L39_004BC6C8(9, 0x6D, 0x6C, 0, 0);
            goto err;
        }
        while (i >= 0 && buf[i] <= ' ') i--;
        buf[++i] = '\n';
        buf[++i] = 0;
        if (func_00120B70(buf, D_L39_00477358, 11) == 0) {
            i = func_00120884(&buf[11]);
            if (func_00120B70(&buf[11 + i - 6], D_L39_00477368, 6) != 0) continue;
            if (!func_L39_004DB1C0(nameB, i + 9)) {
                func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
                goto err;
            }
            func_00120D28(nameB->f4, &buf[11], i - 6);
            nameB->f4[i - 6] = 0;
            break;
        }
    }
    hl = 0;
    if (!func_L39_004DB1C0(headerB, 256)) {
        func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
        goto err;
    }
    headerB->f4[0] = 0;
    for (;;) {
        i = func_L39_004FB898(bp, buf, 0xFE);
        if (i <= 0) break;
        while (i >= 0 && buf[i] <= ' ') i--;
        buf[++i] = '\n';
        buf[++i] = 0;
        if (buf[0] == '\n') break;
        m = hl + i;
        if (!func_L39_004DB1C0(headerB, m + 9)) {
            func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
            goto err;
        }
        if (func_00120B70(buf, D_L39_00477370, 9) == 0) {
            nohead = 1;
            break;
        }
        func_00120D28(headerB->f4 + hl, buf, i);
        headerB->f4[m] = 0;
        hl = m;
    }
    bl = 0;
    if (!func_L39_004DB1C0(dataB, 1024)) {
        func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
        goto err;
    }
    dataB->f4[0] = 0;
    if (!nohead) {
        for (;;) {
            i = func_L39_004FB898(bp, buf, 0xFE);
            if (i <= 0) break;
            while (i >= 0 && buf[i] <= ' ') i--;
            buf[++i] = '\n';
            buf[++i] = 0;
            if (i != 65) end = 1;
            if (func_00120B70(buf, D_L39_00477370, 9) == 0) break;
            if (i > 65) break;
            if (!func_L39_004DB1C0(dataB, i + bl + 9)) {
                func_L39_004BC6C8(9, 0x6D, 0x21, 0, 0);
                goto err;
            }
            func_00120D28(dataB->f4 + bl, buf, i);
            dataB->f4[bl + i] = 0;
            bl += i;
            if (end) {
                buf[0] = 0;
                i = func_L39_004FB898(bp, buf, 0xFE);
                if (i <= 0) break;
                while (i >= 0 && buf[i] <= ' ') i--;
                buf[++i] = '\n';
                buf[++i] = 0;
                break;
            }
        }
    } else {
        tmpB = headerB;
        headerB = dataB;
        dataB = tmpB;
        bl = hl;
    }
    i = func_00120884(nameB->f4);
    if (func_00120B70(buf, D_L39_00477370, 9) != 0 ||
        func_00120B70(nameB->f4, &buf[9], i) != 0 ||
        func_00120B70(&buf[9 + i], D_L39_00477368, 6) != 0) {
        func_L39_004BC6C8(9, 0x6D, 0x66, 0, 0);
        goto err;
    }
    func_L39_005045A8(ctx);
    i = func_L39_005045C0(ctx, (u8 *)dataB->f4, &bl, (u8 *)dataB->f4, bl);
    if (i < 0) {
        func_L39_004BC6C8(9, 0x6D, 0x64, 0, 0);
        goto err;
    }
    i = func_L39_00504970(ctx, (u8 *)&dataB->f4[bl], &k);
    if (i < 0) {
        func_L39_004BC6C8(9, 0x6D, 0x64, 0, 0);
        goto err;
    }
    bl += k;
    if (bl == 0) goto err;
    len = bl;
    *out1 = nameB->f4;
    *out2 = headerB->f4;
    *out3 = dataB->f4;
    *out4 = len;
    func_L39_004BEF28(nameB);
    func_L39_004BEF28(headerB);
    func_L39_004BEF28(dataB);
    func_L39_00504588(ctx);
    return 1;
err:
    if (ctx != 0) func_L39_00504588(ctx);
    if (nameB != 0) {
        func_L39_004DB168(nameB);
        func_L39_004DB168(headerB);
    }
    if (dataB != 0) func_L39_004DB168(dataB);
    return 0;
}
/* localdecomp:end func_L39_004E1DC8 */

INCLUDE_ASM("asm/levels", func_L39_004E2398);

INCLUDE_ASM("asm/levels", func_L39_004E23D8);

INCLUDE_ASM("asm/levels", func_L39_004E2440);

INCLUDE_ASM("asm/levels", func_L39_004E2450);
