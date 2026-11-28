/* PAL near miss (wave 13b r32, 2026-11-28), first draft, written from retail (decrypted with tools/dnas_blocks.py
 * --show). With the file's line (-O2 -G0 -fno-strict-aliasing @ee296 @eeas) check.py gives 310 diff, but almost all
 * of it is one shift: DNAS block 0 comes out 0xB4 bytes, 0xC4 in retail. Retail loads all three block texts into
 * $s0 (la s0, text; move a1, s0): one variable holds them and the last one (CR LF) feeds two strncat calls, so it
 * lives across a call. Through DNAS_STRING's statement-expression temporary the first two addresses go straight to
 * $a1 (la a1), 2 words short each. Forms tried for that (one shared local, three locals, register, DNAS_STRING
 * passed directly) all give the same block. Aligned (difflib, build/codex/wr32/shiftcmp.py) the rest differs in 144
 * rows: register choice (lock in s5 where retail has s4, the 0x440000 high part in s3 where retail has s5, the
 * 0x80000000 wipe constant) and the wipe loop's i++ scheduled before the float conversion (retail: after it, with
 * the byte in v1; wipe-body forms tried: temp u32, temp f32, (u8) cast, q[i++]). Callees and globals are named
 * from the retail calls; the BIO/SSL calls are OpenSSL-shaped (SSL_new, info callback, BIO_new_socket, SSL_set_bio,
 * then an SSL_connect/SSL_get_error loop with a switch: 0 done, 6 retry, others the errno 0x71 check).
 */
#include "common.h"

/* localdecomp:start func_L39_004B8A30 */
#include "dnas.h"

typedef struct {
    u8 pad0[0x204];
    char host[0x200];
    s32 proxy;
    u16 port;
} S_004B8A30_cfg;

/* the first library's driver: driver(block, k1, k2, k3) (include/dnas.h) */
extern void func_L39_004BD350(s32, s32, s32, u32);
extern s32 func_L39_004B80D8(void);
extern s32 func_L39_004B8150(void);
extern s32 func_L39_004B87B0(char *host, u16 port);
extern void func_00120D28(void *, void *, s32);
extern void func_001209C0(void *, void *, s32);
extern s32 func_00128BA8(char *, s32, char *, ...);
extern s32 func_00120884(char *);
extern long func_L01_0047C518(s32, u8 *, s32, s32);
extern s32 func_L39_004B9720(s32);
extern s32 func_L39_004C3F68(void *, s32, s32, void *);
extern void *func_L39_004C37E0(void *);
extern void func_L39_004C4EC0(void *, void *);
extern void func_L39_004C4EC8(void *, void *, s32);
extern void func_L39_004C4BD0(void *);
extern void *func_L39_004BB4C0(s32, s32);
extern void func_L39_004BB490(void *, void *);
extern void func_L39_004C3BB8(void *, void *, void *);
extern s32 func_L39_004C4B30(void *);
extern s32 func_L39_004C4998(void *, s32);
extern s32 *func_L01_003E4008(void);
extern s32 func_L39_004B95C0(s32);
extern s32 func_L39_004B9350(void);
extern s32 func_L39_004D0C78(void);
extern void func_L39_004B9C88(void *);
extern s32 func_L39_004BA208();
extern long func_L39_004BB1E8(void *, s32, u8 *, s32, long, long);
extern s32 D_L39_00464778;
extern s32 D_L39_00464774;
extern s32 D_L39_00464788;
extern void *D_L39_0046478C;
extern void *D_L39_00464790;
extern S_004B8A30_cfg D_L39_00453FB0;
extern char D_L39_00442C50[];
extern u16 D_L39_00442E50;
extern char D_L39_00442E58[];
extern char D_L39_00474B18[];

static __inline__ void wipe_004B8A30(void *buf, u32 n) {
    u8 *q = buf;
    u32 i;

    for (i = 0; i < n; i++) {
        q[i] = (u32)((f32)func_L39_004D0C78() / 2147483520.0f * 256.0f);
    }
}

s32 func_L39_004B8A30(void) {
    char req[9];
    char tail[0x12];
    char *s;
    s32 lock;
    s32 ret;
    s32 done;
    void *bio;

    done = 0;
    if (D_L39_00464778 != 0) {
        return -1;
    }
    lock = func_L39_004B80D8();
    if (D_L39_00453FB0.proxy != 0) {
        ret = func_L39_004B87B0(D_L39_00453FB0.host, D_L39_00453FB0.port);
        if (ret < 0) {
            if (lock >= 0) {
                func_L39_004B8150();
            }
            return ret;
        }
        DNAS_BEGIN(func_L39_004B8A30, 0, func_L39_004BD350);
        s = DNAS_STRING("CONNECT ");
        func_00120D28(req, s, 9);
        s = DNAS_STRING(":443 HTTP/1.0");
        func_00120D28(tail, s, 0x12);
        s = DNAS_STRING("\r\n");
        func_001209C0(tail, s, 0x12);
        func_001209C0(tail, s, 0x12);
        DNAS_END(func_L39_004B8A30, 0, func_L39_004BD350);
        func_00128BA8(D_L39_00442E58, 0x21A, D_L39_00474B18, req, D_L39_00442C50, tail);
        wipe_004B8A30(req, sizeof(req));
        wipe_004B8A30(tail, sizeof(tail));
        if (func_L01_0047C518(D_L39_00464774, (u8 *)D_L39_00442E58, func_00120884(D_L39_00442E58), 0) < 0) {
            wipe_004B8A30(D_L39_00442E58, 0x21A);
            goto err;
        }
        wipe_004B8A30(D_L39_00442E58, 0x21A);
        ret = func_L39_004B9720(D_L39_00464774);
        if (ret != 200) {
            if (ret > 0) {
                ret = -0x25A;
            }
            goto fail;
        }
    } else {
        ret = func_L39_004B87B0(D_L39_00442C50, D_L39_00442E50);
        if (ret < 0) {
            if (lock >= 0) {
                func_L39_004B8150();
            }
            return ret;
        }
    }
    D_L39_00464778 = 1;
    if (D_L39_00464788 != 0) {
        ret = -0x262;
        func_L39_004C3F68(D_L39_0046478C, 0x20, 0x40000, 0);
        D_L39_00464790 = func_L39_004C37E0(D_L39_0046478C);
        if (D_L39_00464790 == 0) {
            goto fail;
        }
        func_L39_004C4EC0(D_L39_00464790, func_L39_004B9C88);
        func_L39_004C4EC8(D_L39_00464790, func_L39_004BA208, 0);
        func_L39_004C4BD0(D_L39_00464790);
        bio = func_L39_004BB4C0(D_L39_00464774, 0);
        if (bio == 0) {
            goto fail;
        }
        func_L39_004BB490(bio, func_L39_004BB1E8);
        func_L39_004C3BB8(D_L39_00464790, bio, bio);
        do {
            switch (func_L39_004C4998(D_L39_00464790, func_L39_004C4B30(D_L39_00464790))) {
            case 0:
                done = 1;
                break;
            case 6:
                break;
            default:
                if (*func_L01_003E4008() == 0x71) {
                    goto err;
                }
                ret = -0x262;
                goto fail;
            }
        } while (!done);
    }
    if (lock >= 0) {
        func_L39_004B8150();
    }
    return 0;
err:
    ret = func_L39_004B95C0(*func_L01_003E4008());
fail:
    if (lock > 0) {
        func_L39_004B8150();
    }
    func_L39_004B9350();
    return ret;
}
/* localdecomp:end func_L39_004B8A30 */
