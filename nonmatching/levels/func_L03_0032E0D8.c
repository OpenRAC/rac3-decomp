/* near miss (level 3, Starship Phoenix): 308 differences, register allocation (not VU0: the lq/sq are caller-save spills of $7 around the call; the jump table covers cases 0x10..0x97 and best.c has all blocks in retail order: 27, 77, 2F, 7F, 37, 47 sharing the tail at E404 by goto, 57, 6F, 3F, 4F, 5F, 97, 15, 11, 13, 10): retail keeps hi(D_001425C0) in $fp and hi(D_L03_002C49C0) in caller-saved $a3/$7 with a 0x80 frame, the C keeps both in callee-saved registers and the frame comes out 0x70 or 0xA0; the case 0x37 loop does not reproduce retail's q/offset/base trio (i counter, q pointer plus i, local base pointer all about 308) */
#include "common.h"

/* localdecomp:start func_L03_0032E0D8 */
typedef struct R_0032E0D8 {
    char pad0[1];
    unsigned char b1;
    char pad2[0x84 - 2];
    unsigned short h84;
    char pad86[0xF0 - 0x86];
} R_0032E0D8;
typedef struct T_0032E0D8 {
    int a, b, c;
} T_0032E0D8;
typedef struct P_0032E0D8 {
    char pad0[0xA8];
    int arr[3];
    char pad1[0x10C - 0xB4];
    short cnt;
} P_0032E0D8;
typedef struct W_0032E0D8 {
    T_0032E0D8 t;
    int d;
    P_0032E0D8 *p;
    int lim;
} W_0032E0D8;
typedef struct E_0032E0D8 {
    char pad0[0x20];
    unsigned char f20;
    char pad1[0x2F - 0x21];
    unsigned char f2F;
} E_0032E0D8;
extern unsigned char D_001425C0[];
extern R_0032E0D8 D_L03_002C49C0[];
extern int D_001427F0[];
extern T_0032E0D8 D_L03_001DD130;
extern int D_L03_0021C620[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_001DF9D8_sda;
__asm__(".extern D_001DF9D8_sda, 4");
E_0032E0D8 *func_00382348_func_L03_0032E0D8();
int func_L03_0032E640();

int func_L03_0032E0D8(void *arg0, int idx) {
    W_0032E0D8 w;
    int m;
    int *a;
    int n;
    int i;
    int b;
    w.p = *(P_0032E0D8 **)((char *)arg0 + 0x68);
    if (idx == -1) return 0;
    if (D_L03_002C49C0[D_001425C0[idx]].h84 == 0) return 0;
    if (D_001427F0[idx] > 0) {
        w.p->cnt = 0;
        return 0;
    }
    w.lim = 8;
    w.t = D_L03_001DD130;
    m = 0;
    switch (idx) {
    case 0x27:
        n = 0x10;
        goto tail;
    case 0x77:
        w.t.a = 0x185A;
        m = 2;
        if (D_L03_002C49C0[D_001425C0[0x77]].b1 < 4) {
            w.t.b = 0x1858;
        } else {
            w.t.b = 0x1888;
            w.t.c = 0x1855;
        }
        break;
    case 0x2F:
        m = 2;
        if (D_L03_002C49C0[D_001425C0[0x2F]].b1 < 4) {
            w.t.a = 0x1851;
        } else {
            w.t.a = 0x1881;
        }
        break;
    case 0x7F:
        w.lim = 0x3A;
        b = D_L03_002C49C0[D_001425C0[0x7F]].b1;
        m = 1;
        if (b >= 3) {
            w.t.a = 0x307;
            m = 2;
            if (b >= 4) w.t.b = 0x1CB8;
        }
        break;
    case 0x37:
        a = w.p->arr;
        for (i = 0; i < 3; i++) {
            int k = a[i];
            short *cur = (short *)D_L03_0021C620[k];
            for (; (k & 0xFF) != 0xFF && D_001DF9D8_sda >= k && cur != 0 &&
                   (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[a[i]]); cur++) {
                E_0032E0D8 *e = (E_0032E0D8 *)(D_L03_001DF99C + ((*(unsigned short *)cur & 0x7FFF) << 8));
                if (e == 0) break;
                if (e->f20 != 1) {
                    if (func_00382348_func_L03_0032E0D8(e, a)->f2F != 0) return 0;
                }
                k = a[i];
            }
        }
        w.t.a = 0x1E05;
        m = 2;
        if (D_L03_002C49C0[D_001425C0[0x37]].b1 >= 4) w.t.b = 0x188A;
        break;
    case 0x47:
        n = 0x2D;
    tail:
        m = 1;
        w.lim = n;
        break;
    case 0x57:
        w.t.a = 0x1ADA;
        m = 2;
        b = D_L03_002C49C0[D_001425C0[0x57]].b1;
        if (b >= 4) {
            w.t.b = 0xA82;
            w.t.c = 0x188F;
        } else if (b > 0) {
            w.t.b = 0x1851;
        }
        break;
    case 0x6F:
        m = 1;
        w.lim = 0x21;
        break;
    case 0x3F:
        w.t.a = 0x1894;
        m = 2;
        b = D_L03_002C49C0[D_001425C0[0x57]].b1;
        if (b >= 4) {
            w.t.b = 0xA82;
        } else if (b > 0) {
            w.t.b = 0x1897;
        }
        break;
    case 0x4F:
        w.t.a = 0x1867;
        m = 2;
        break;
    case 0x5F:
        w.t.a = 0x186B;
        m = 2;
        break;
    case 0x97:
        m = 1;
        w.lim = 0xAF;
        break;
    case 0x15:
        m = 2;
        if (D_L03_002C49C0[D_001425C0[0x15]].b1 >= 4) {
            w.t.a = 0x1B37;
            w.t.b = 0xA82;
        } else {
            w.t.a = 0x1B36;
        }
        break;
    case 0x11:
        m = 1;
        w.lim = 0x4B;
        break;
    case 0x13:
        w.t.a = 0xE64;
        w.t.b = 0xECE;
        m = 2;
        break;
    case 0x10:
        m = 2;
        if (D_L03_002C49C0[D_001425C0[0x10]].b1 < 4) {
            w.t.a = 0xA9B;
        } else {
            w.t.a = 0x9A9;
        }
        break;
    case 0x87:
    case 0x8F:
        return 0;
    }
    switch (m) {
    case 0:
        return 1;
    case 1:
        break;
    case 2:
        if (func_L03_0032E640(&w) != 0) return 0;
        break;
    default:
        return 0;
    }
    w.p->cnt++;
    return w.lim < w.p->cnt;
}
/* localdecomp:end func_L03_0032E0D8 */
