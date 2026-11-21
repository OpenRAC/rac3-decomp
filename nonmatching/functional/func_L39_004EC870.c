/* functional: high. Same blocks, calls and stores as retail (OpenSSL ssl_set_pkey); only register allocation and frame size differ. */
/* OpenSSL ssl_set_pkey(CERT *c, EVP_PKEY *pkey) */
typedef struct {
    s32 type;
    char _p4[0x4];
    s32 references;
    void *rsa;
} PKEY_004EC870;
typedef struct {
    void *x509;
    PKEY_004EC870 *privatekey;
} CPK_004EC870;
typedef struct {
    char _p0[0x4];
    CPK_004EC870 *key;
    s32 valid;
    char _pC[0x40 - 0xC];
    CPK_004EC870 pkeys[5];
} CERT_004EC870;

extern void *func_L39_004BBDE0(void *);
extern s32 func_L39_004EB798(void *, void *);
extern void func_L39_004CBFC8(void *, void *);
extern void func_L39_004DE0C8(void);
extern s32 func_L39_004EABF0(void *);
extern s32 func_L39_004BC3D8(void *, void *);
extern void func_L39_004BBBA0(void *);
extern void func_L39_004BC420(void *);
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern char D_L39_00477860[];

s32 func_L39_004EC870(CERT_004EC870 *c, PKEY_004EC870 *pkey) {
    s32 i;
    s32 bad = 0;

    i = func_L39_004EB798(0, pkey);
    if (i < 0) {
        func_L39_004BC6C8(0x14, 0xC2, 0xF7, 0, 0);
        return 0;
    }
    if (c->pkeys[i].x509 != 0) {
        void *pk = func_L39_004BBDE0(c->pkeys[i].x509);
        func_L39_004CBFC8(pk, pkey);
        func_L39_004DE0C8();
        if (pkey->type == 6 && (func_L39_004EABF0(pkey->rsa) & 1)) {
        } else if (!func_L39_004BC3D8(c->pkeys[i].x509, pkey)) {
            if (i == 3 || i == 4) {
                i = (i == 3) ? 4 : 3;
                if (c->pkeys[i].x509 != 0) {
                    if (!func_L39_004BC3D8(c->pkeys[i].x509, pkey))
                        bad = 1;
                }
            } else {
                bad = 1;
            }
        }
    }
    if (bad) {
        func_L39_004BBBA0(c->pkeys[i].x509);
        c->pkeys[i].x509 = 0;
        return 0;
    }
    if (c->pkeys[i].privatekey != 0)
        func_L39_004BC420(c->pkeys[i].privatekey);
    func_L39_004BECF0(&pkey->references, 1, 10, D_L39_00477860, 0x11A);
    c->pkeys[i].privatekey = pkey;
    c->valid = 0;
    c->key = &c->pkeys[i];
    return 1;
}
