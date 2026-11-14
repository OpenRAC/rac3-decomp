#include "common.h"

/* localdecomp:start func_L39_004CB258 */
/* OpenSSL's SSL_CIPHER_description (ssl_ciph.c), a variant that takes the key lengths from algorithm2 */
typedef struct {
    s32 valid;
    char *name;
    unsigned long id;
    unsigned long algorithms;
    unsigned long algorithm2;
} C_004CB258;

extern char D_L39_00475E30[];
extern char D_L39_00475E38[];
extern char D_L39_00475C98[];
extern char D_L39_00475C90[];
extern char D_L39_00475E40[];
extern char D_L39_00475E48[];
extern char D_L39_00475CC0[];
extern char D_L39_00475E50[];
extern char D_L39_00475E58[];
extern char D_L39_00475E60[];
extern char D_L39_00475E70[];
extern char D_L39_00475D58[];
extern char D_L39_00475D20[];
extern char D_L39_00475E78[];
extern char D_L39_00475D18[];
extern char D_L39_00475D10[];
extern char D_L39_00475D08[];
extern char D_L39_00475D00[];
extern char D_L39_00475CF8[];
extern char D_L39_00475CE0[];
extern char D_L39_00475CD8[];
extern char D_L39_00475E80[];
extern char *D_L39_004656FC __attribute__((section(".data")));

extern s32 func_00120048(void *, char *, ...);
extern char *func_001206F4(char *, char *);
extern void *func_L39_004BEED8(s32);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

char *func_L39_004CB258(C_004CB258 *cipher, char *buf, s32 len) {
    s32 is_export, kl;
    char *ver, *exp;
    char *kx, *au, *enc, *mac;
    unsigned long alg, alg2;
    char encbuf[16];
    char kxbuf[32];

    alg = cipher->algorithms;
    alg2 = cipher->algorithm2;

    is_export = (s32)(alg >> 20) & 1;
    exp = is_export ? D_L39_00475E30 : D_L39_00475E38;

    if (alg & 0x400000)
        ver = D_L39_00475C98;
    else if (alg & 0x800000)
        ver = D_L39_00475C90;
    else
        ver = D_L39_00475E40;

    switch (alg & 0x1F) {
    case 0x1:
        if (is_export) {
            func_00120048(kxbuf, D_L39_00475E48, (s32)(alg2 & 0xFF00));
            kx = kxbuf;
        } else {
            kx = D_L39_00475CC0;
        }
        break;
    case 0x2:
        kx = D_L39_00475E50;
        break;
    case 0x4:
        kx = D_L39_00475E58;
        break;
    case 0x8:
        kx = D_L39_00475E60;
        break;
    case 0x10:
        if (is_export) {
            func_00120048(kxbuf, D_L39_00475E70, (s32)(alg2 & 0xFF00));
            kx = kxbuf;
        } else {
            kx = D_L39_00475D58;
        }
        break;
    default:
        kx = D_L39_00475E40;
        break;
    }

    switch (alg & 0x3E0) {
    case 0x20:
        au = D_L39_00475CC0;
        break;
    case 0x40:
        au = D_L39_00475D20;
        break;
    case 0x200:
        au = D_L39_00475D58;
        break;
    case 0x80:
    case 0x100:
        au = D_L39_00475E78;
        break;
    default:
        au = D_L39_00475E40;
        break;
    }

    kl = (s32)(alg2 & 0xFF) * 8;
    switch (alg & 0x1FC00) {
    case 0x400:
        if (kl == 0 || kl > 56)
            kl = 56;
        enc = D_L39_00475D18;
        break;
    case 0x800:
        if (kl == 0)
            kl = 168;
        enc = D_L39_00475D10;
        break;
    case 0x1000:
        if (kl == 0)
            kl = 128;
        enc = D_L39_00475D08;
        break;
    case 0x2000:
        if (kl == 0)
            kl = 128;
        enc = D_L39_00475D00;
        break;
    case 0x4000:
        if (kl == 0)
            kl = 128;
        enc = D_L39_00475CF8;
        break;
    case 0x8000:
        kl = -1;
        enc = D_L39_00475E60;
        break;
    case 0x10000:
        kl = -1;
        enc = D_L39_00475E78;
        break;
    default:
        kl = -1;
        enc = D_L39_00475E40;
        break;
    }

    switch (alg & 0x60000) {
    case 0x20000:
        mac = D_L39_00475CE0;
        break;
    case 0x40000:
        mac = D_L39_00475CD8;
        break;
    default:
        mac = D_L39_00475E40;
        break;
    }

    if (buf == 0) {
        buf = func_L39_004BEED8(128);
        if (buf == 0) {
            func_L39_004BC6C8(20, 0xD8, 0x21, 0, 0);
            return 0;
        }
    } else if (len < 128) {
        func_L39_004BC6C8(20, 0xD8, 0x10, 0, 0);
        return 0;
    }

    if (kl <= 0)
        func_001206F4(encbuf, enc);
    else
        func_00120048(encbuf, D_L39_00475E80, enc, kl);

    func_00120048(buf, D_L39_004656FC, cipher->name, ver, kx, au, encbuf, mac, exp);
    return buf;
}
/* localdecomp:end func_L39_004CB258 */

LINKER_REMNANT("asm/levels", func_L39_004CB678);
