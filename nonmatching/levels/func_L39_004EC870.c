/* PAL near miss (k6 a5, 2026-11-26): OpenSSL 0.9.6's ssl_set_pkey (ssl/ssl_rsa.c), written as its source.
 * Sony's library code: it needs Sony's 2.9-ee (`@ee29 @eeas -O2 -G8 -fno-strict-aliasing`, the line of the
 * other OpenSSL files of level 39), not the SN line of L39_004EC830.c, which gives 99-100 differences.
 * With that line (tried by cutting L39_004EC830.c into L39_004EC830.c / L39_004EC870.c (@ee29) /
 * L39_004ECA10.c (SN), all of whose other functions still matched): 12 differences, only $s4/$s5 swapped
 * between `c` and &c->pkeys[i]. tools/regalloc.py: `c` (refs 6, live 67, priority 0.179) is allocated
 * just ahead of the pkeys[i] address (refs 3, live 17, 0.176); retail has them the other way round.
 * Tried without effect: pktmp at function scope or inline, ok/bad assigned late, int return, the
 * valid/key store order, -G0. Without `ok` (dead code) it is 99. */
#include "common.h"
/* localdecomp:start func_L39_004EC870 */
/* OpenSSL's ssl_set_pkey (ssl/ssl_rsa.c, 0.9.6) */
typedef struct {
    s32 type;
    s32 save_type;
    s32 references;
    void *rsa;
} PKEY_004EC870;
typedef struct {
    void *x509;
    PKEY_004EC870 *privatekey;
} CPK_004EC870;
typedef struct {
    s32 pad0;
    CPK_004EC870 *key;
    s32 valid;
    u8 padC[0x40 - 0xC];
    CPK_004EC870 pkeys[5];
} CERT_004EC870;

extern void *func_L39_004BBDE0(void *);
extern s32 func_L39_004EB798(void *, void *);
extern s32 func_L39_004CBFC8(void *, void *);
extern void func_L39_004DE0C8(void);
extern s32 func_L39_004EABF0(void *);
extern s32 func_L39_004BC3D8(void *, void *);
extern void func_L39_004BBBA0(void *);
extern void func_L39_004BC420(void *);
extern s32 func_L39_004BECF0(s32 *, s32, s32, const char *, s32);
extern void func_L39_004BC6C8(s32, s32, s32, const char *, s32);
extern char D_L39_00477860[];

s32 func_L39_004EC870(CERT_004EC870 *c, PKEY_004EC870 *pkey)
{
    s32 i, ok = 0, bad = 0;

    i = func_L39_004EB798(0, pkey);
    if (i < 0) {
        func_L39_004BC6C8(0x14, 0xC2, 0xF7, 0, 0);
        return 0;
    }

    if (c->pkeys[i].x509 != 0) {
        PKEY_004EC870 *pktmp;
        pktmp = func_L39_004BBDE0(c->pkeys[i].x509);
        func_L39_004CBFC8(pktmp, pkey);
        func_L39_004DE0C8();

        if ((pkey->type == 6) && (func_L39_004EABF0(pkey->rsa) & 1))
            ok = 1;
        else if (!func_L39_004BC3D8(c->pkeys[i].x509, pkey)) {
            if ((i == 3) || (i == 4)) {
                i = (i == 3) ? 4 : 3;
                if (c->pkeys[i].x509 == 0)
                    ok = 1;
                else {
                    if (!func_L39_004BC3D8(c->pkeys[i].x509, pkey))
                        bad = 1;
                    else
                        ok = 1;
                }
            } else
                bad = 1;
        } else
            ok = 1;
    } else
        ok = 1;

    if (bad) {
        func_L39_004BBBA0(c->pkeys[i].x509);
        c->pkeys[i].x509 = 0;
        return 0;
    }

    if (c->pkeys[i].privatekey != 0)
        func_L39_004BC420(c->pkeys[i].privatekey);
    func_L39_004BECF0(&pkey->references, 1, 10, D_L39_00477860, 0x11A);
    c->pkeys[i].privatekey = pkey;
    c->key = &(c->pkeys[i]);

    c->valid = 0;
    return 1;
}
/* localdecomp:end func_L39_004EC870 */
