#include "common.h"

/* NTSC-U counterpart of func_L03_0032E0D8 (src/levels/03_starship_phoenix/L03_0032DB58.c) */
#include "vu0.h"
extern u16 *D_L03_0021C6A0[];
extern u8 *D_L03_001DFA1C;

/* localdecomp:start func_L03_0032DA18 */
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
typedef struct E_0032E0D8 {
    char pad0[0x20];
    unsigned char f20;
    char pad1[0x2F - 0x21];
    unsigned char f2F;
} E_0032E0D8;
extern unsigned char D_001425C0[];
extern R_0032E0D8 D_L03_002C4A00[];
extern int D_001427F0[];
extern T_0032E0D8 D_L03_001DD170_0032DA18;
extern u16 *D_L03_0021C6A0[];
extern u8 *D_L03_001DFA1C;
__asm__(".extern D_L03_001DFA1C, 16");
extern s32 D_L03_001DFA58_0032DA18;
__asm__(".extern D_L03_001DFA58_0032DA18, 16");
extern void *func_0037E0B8(void *);
s32 func_L03_0032DF80(s32 *list);

s32 func_L03_0032DA18(void *arg0, s32 idx) {
    T_0032E0D8 t;
    P_0032E0D8 *p;
    int lim;
    int m;
    int i;
    int b;
    R_0032E0D8 *r;
    p = *(P_0032E0D8 **)((char *)arg0 + 0x68);
    if (idx == -1) return 0;
    r = &D_L03_002C4A00[D_001425C0[idx]];
    if (r->h84 == 0) return 0;
    if (D_001427F0[idx] > 0) {
        p->cnt = 0;
    } else {
        lim = 10;
        t = D_L03_001DD170_0032DA18;
        m = 0;
        switch (idx) {
        case 0x87:
        case 0x8F:
            return 0;
        case 0x27:
            m = 1;
            lim = 0x14;
            break;
        case 0x77:
            t.a = 0x185A;
            m = 2;
            if (D_L03_002C4A00[D_001425C0[0x77]].b1 >= 4) {
                t.b = 0x1888;
                t.c = 0x1855;
            } else {
                t.b = 0x1858;
            }
            break;
        case 0x2F:
            m = 2;
            if (D_L03_002C4A00[D_001425C0[0x2F]].b1 >= 4) {
                t.a = 0x1881;
            } else {
                t.a = 0x1851;
            }
            break;
        case 0x7F:
            lim = 0x46;
            b = D_L03_002C4A00[D_001425C0[0x7F]].b1;
            m = 1;
            if (b >= 3) {
                t.a = 0x307;
                m = 2;
                if (b >= 4) t.b = 0x1CB8;
            }
            break;
        case 0x37:
            for (i = 0; i < 3; i++) {
                short *cur = (short *)D_L03_0021C6A0[p->arr[i]];
                for (; (p->arr[i] & 0xFF) != 0xFF && D_L03_001DFA58_0032DA18 >= p->arr[i] && cur != 0 &&
                       (cur[-1] >= 0 || cur == (short *)D_L03_0021C6A0[p->arr[i]]); cur++) {
                    E_0032E0D8 *e = (E_0032E0D8 *)(D_L03_001DFA1C + ((*(unsigned short *)cur & 0x7FFF) << 8));
                    if (e == 0) break;
                    if (e->f20 != 1) {
                        if (((E_0032E0D8 *)func_0037E0B8(e))->f2F != 0) return 0;
                    }
                }
            }
            t.a = 0x1E05;
            m = 2;
            if (D_L03_002C4A00[D_001425C0[0x37]].b1 >= 4) t.b = 0x188A;
            break;
        case 0x47:
            m = 1;
            lim = 0x37;
            break;
        case 0x57: {
                int b;
                t.a = 0x1ADA;
                m = 2;
                b = D_L03_002C4A00[D_001425C0[0x57]].b1;
                if (b >= 4) {
                    t.b = 0xA82;
                    t.c = 0x188F;
                } else if (b > 0) {
                    t.b = 0x1851;
                }
                break;
            }
        case 0x6F:
            m = 1;
            lim = 0x28;
            break;
        case 0x3F: {
                int b;
                t.a = 0x1894;
                m = 2;
                b = D_L03_002C4A00[D_001425C0[0x57]].b1;
                if (b >= 4) {
                    t.b = 0xA82;
                } else if (b > 0) {
                    t.b = 0x1897;
                }
                break;
            }
        case 0x4F:
            m = 2;
            t.a = 0x1867;
            break;
        case 0x5F:
            m = 2;
            t.a = 0x186B;
            break;
        case 0x97:
            m = 1;
            lim = 0xD2;
            break;
        case 0x15:
            m = 2;
            if (D_L03_002C4A00[D_001425C0[0x15]].b1 >= 4) {
                t.a = 0x1B37;
                t.b = 0xA82;
            } else {
                t.a = 0x1B36;
            }
            break;
        case 0x11:
            m = 1;
            lim = 0x5A;
            break;
        case 0x13:
            t.a = 0xE64;
            t.b = 0xECE;
            m = 2;
            break;
        case 0x10:
            m = 2;
            if (D_L03_002C4A00[D_001425C0[0x10]].b1 >= 4) {
                t.a = 0x9A9;
            } else {
                t.a = 0xA9B;
            }
            break;
        }
        switch (m) {
        case 0:
            return 1;
        case 1:
            break;
        case 2:
            if (func_L03_0032DF80((s32 *)&t) != 0) return 0;
            break;
        default:
            return 0;
        }
        p->cnt++;
        if (lim < p->cnt) return 1;
    }
    return 0;
}
/* localdecomp:end func_L03_0032DA18 */
