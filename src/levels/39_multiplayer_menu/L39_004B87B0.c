#include "common.h"

/* localdecomp:start func_L39_004B87B0 */
typedef struct {
    u8 sin_len;
    u8 sin_family;
    u16 sin_port;
    u8 sin_addr[4];
    u8 sin_zero[8];
} S_004B87B0_sa;

typedef struct {
    char *h_name;
    char **h_aliases;
    s32 h_addrtype;
    u32 h_length;
    char **h_addr_list;
} S_004B87B0_he;

extern s32 D_L39_00464774;
extern s32 D_L39_00464780;
extern void func_00126280(s32);
extern void func_001262B0(s32);
extern u16 func_L39_00518928(u16);
extern s32 func_L01_004127E8(char *, void *);
extern S_004B87B0_he *func_L01_004127C0(char *);
extern s32 *func_L01_004028B0(void);
extern s32 func_L39_004B9640(s32);
extern s32 *func_L01_003E4008(void);
extern s32 func_L39_004B95C0(s32);
extern s32 func_L01_00422FE0(s32, s32);
extern s32 func_L01_00423000(s32, s32, s32);
extern s32 func_L01_00412E30(s32, void *, s32);

static __inline__ void bzero_004B87B0(void *p, u32 n) {
    u8 *c = p;
    u32 k;
    for (k = 0; k < n; k++) {
        c[k] = 0;
    }
}

static __inline__ void bcopy_004B87B0(void *src, void *dst, u32 n) {
    u8 *s = src;
    u8 *d = dst;
    u32 k;
    for (k = 0; k < n; k++) {
        d[k] = s[k];
    }
}

s32 func_L39_004B87B0(char *host, u16 port) {
    S_004B87B0_sa sa;
    S_004B87B0_he *h;
    s32 numeric;
    s32 i;
    s32 ret;
    s32 giveup;

    h = 0;
    giveup = 0;
    bzero_004B87B0(&sa, 16);
    sa.sin_family = 2;
    sa.sin_port = func_L39_00518928(port);
    numeric = func_L01_004127E8(host, sa.sin_addr);
    i = 0;
    if (!numeric) {
        func_00126280(D_L39_00464780);
        h = func_L01_004127C0(host);
        func_001262B0(D_L39_00464780);
        if (h == 0) {
            ret = func_L39_004B9640(*func_L01_004028B0());
            goto out;
        }
        if (h->h_length > 4) {
            ret = -0x267;
            goto out;
        }
        bcopy_004B87B0(h->h_addr_list[0], sa.sin_addr, 4);
        i = 0;
    }
    for (;;) {
        D_L39_00464774 = -1;
        D_L39_00464774 = func_L01_00423000(2, 1, 0);
        if (D_L39_00464774 < 0) {
            goto fail;
        }
        if (func_L01_00412E30(D_L39_00464774, &sa, 16) == 0) {
            break;
        }
        if (func_L39_004B95C0(*func_L01_003E4008()) == -0x259 || numeric != 0 || h->h_addr_list[++i] == 0) {
            giveup = 1;
            break;
        }
        func_L01_00422FE0(D_L39_00464774, 0);
        bzero_004B87B0(&sa, 16);
        sa.sin_family = 2;
        sa.sin_port = func_L39_00518928(port);
        bcopy_004B87B0(h->h_addr_list[i], sa.sin_addr, 4);
    }
    if (giveup <= 0) {
        return 0;
    }
fail:
    ret = func_L39_004B95C0(*func_L01_003E4008());
out:
    if (D_L39_00464774 >= 0) {
        func_L01_00422FE0(D_L39_00464774, 0);
        D_L39_00464774 = -1;
    }
    return ret;
}
/* localdecomp:end func_L39_004B87B0 */

INCLUDE_ASM("asm/levels", func_L39_004B8A30);

INCLUDE_ASM("asm/levels", func_L39_004B9078);
