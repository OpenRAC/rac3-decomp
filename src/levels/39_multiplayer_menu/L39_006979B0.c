#include "common.h"

/* localdecomp:start func_L39_006979B0 */
typedef struct S_006979B0_list S_006979B0_list;
typedef struct {
    char pad[0x88];
    void (*f88)(S_006979B0_list *, s32);
    s32 (*f8C)(S_006979B0_list *);
} S_006979B0_vt;
struct S_006979B0_list {
    char pad[0x60];
    S_006979B0_vt *f60;
};
typedef struct {
    char pad[0x114];
    S_006979B0_list *f114;
    char pad2[0x290 - 0x118];
    s32 f290;
    char pad3[0x2B0 - 0x294];
    s32 f2B0;
    char pad4[0x3B4 - 0x2B4];
    s32 f3B4;
} S_006979B0;

extern void func_L39_00688340(s32, s32, s32);
void func_L39_0068B2F8(s32, s32, s32);

s32 func_L39_006979B0(S_006979B0 *p, s32 event)
{
    s32 t;
    if (event == 3 || event == 4) {
        t = p->f290;
        if (t == 1) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8((s32)p, p->f3B4, 0);
            return 1;
        }
        func_L39_00688340(3, 0, 0);
        t = p->f290;
        p->f3B4 = t;
        func_L39_0068B2F8((s32)p, 1, 0);
        return 1;
    }
    if (event == 2) {
        if (p->f290 == 1 && p->f114->f60->f8C(p->f114) == p->f2B0 - 1) {
            p->f114->f60->f88(p->f114, 0);
            return 1;
        }
        if (p->f290 == 16) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8((s32)p, 9, 0);
            return 1;
        }
    } else if (event == 1) {
        if (p->f290 == 1 && p->f114->f60->f8C(p->f114) == 0) {
            p->f114->f60->f88(p->f114, p->f2B0 - 1);
            return 1;
        }
        if (p->f290 == 9) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8((s32)p, 16, 0);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006979B0 */

/* localdecomp:start func_L39_00697B28 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");

typedef struct {
    s32 f0;
    char pad[0x30];
    u8 f34;
} S_00697B28_inner;

typedef struct {
    char pad[0x38];
    S_00697B28_inner *f38;
} S_00697B28_outer;

typedef struct {
    char pad[0x288];
    s32 f288;
} S_00697B28_slot;

extern S_00697B28_outer *D_L39_0024D760;
extern S_00697B28_slot *D_L39_00247914;
extern S_00697B28_slot *D_001DC204_sda;

s32 func_L39_00697B28(void)
{
    S_00697B28_inner *inner = D_L39_0024D760->f38;

    if (inner->f0 == -1) {
        D_L39_00247914->f288 = 8;
        return 1;
    }
    if (inner->f34 == 0) {
        D_001DC204_sda->f288 = 6;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00697B28 */

/* localdecomp:start func_L39_00697B80 */
typedef struct L_00697B80 L_00697B80;
typedef struct {
    char pad[0x20];
    s32 (*f20)(L_00697B80 *, s32, s32);
    char pad24[0x6C - 0x24];
    void (*f6C)(L_00697B80 *, s32, char **);
    char pad70[0x88 - 0x70];
    void (*f88)(L_00697B80 *, s32);
    s32 (*f8C)(L_00697B80 *);
} V_00697B80;
struct L_00697B80 {
    char pad[0x60];
    V_00697B80 *f60;
};
typedef struct {
    char pad[0x1C];
    s32 f1C;
    char f20[1];
} I_00697B80;
typedef struct {
    s32 f0;
    s32 f4;
    I_00697B80 **f8;
} E_00697B80;
typedef struct {
    char pad[0x38];
    s32 f38;
    char pad3C[0x3B4 - 0x3C];
    u8 f3B4;
    s32 f3B8;
    u8 f3BC;
    char pad3BD[7];
    s32 f3C4;
    char pad3C8[4];
    E_00697B80 f3CC[1];
} Q_00697B80;
typedef struct {
    char pad[0x114];
    L_00697B80 *f114;
    char pad118[0x2A8 - 0x118];
    u8 f2A8;
    s32 f2AC;
    s32 f2B0;
    s32 f2B4[66];
    char *f3BC[64];
} P_00697B80;
typedef struct {
    char s[0x50];
} N_00697B80;

__asm__(".extern D_L39_0024D760, 16");
extern N_00697B80 D_L39_00372EC0[];
extern char D_L39_00248020[];
void func_L39_006D08E8(Q_00697B80 *);
extern s32 func_00120884(void *);
s32 func_00381FF0(s32);
void func_L39_005958F8(N_00697B80 *, char *, s32);

void func_L39_00697B80(P_00697B80 *p)
{
    Q_00697B80 *q = (Q_00697B80 *)D_L39_0024D760->f38;
    E_00697B80 *e = 0;
    I_00697B80 *it;
    s32 sel;
    s32 idx;
    s32 i;
    s32 j;
    s32 k;
    s32 cur;
    s32 n;

    if (q->f3B4 != 0 && q->f3B8 >= 0) {
        e = &q->f3CC[q->f3B8];
    }
    if (p->f2A8 != 0 && q->f3BC == 0) {
        p->f2AC = q->f3C4;
        func_L39_006D08E8(q);
        p->f2A8 = 0;
    }
    if (e == 0 || q->f3C4 == p->f2AC) {
        return;
    }
    p->f2AC = q->f3C4;
    n = 64;
    if (e->f4 < 64) {
        n = e->f4;
    }
    p->f2B0 = n;
    sel = -1;
    idx = p->f114->f60->f8C(p->f114);
    if (idx != -1) {
        sel = p->f2B4[idx];
    }
    p->f2B4[0] = q->f38;
    k = 1;
    cur = 0;
    for (i = 0; i < p->f2B0; i++) {
        it = e->f8[i];
        if (it->f1C == p->f2B4[0]) {
            p->f3BC[0] = it->f20;
        } else {
            p->f3BC[k] = it->f20;
            p->f2B4[k] = it->f1C;
            k++;
        }
        if (sel == it->f1C) {
            cur = k;
        }
    }
    if (p->f2B0 > 0) {
        for (j = 0; j < p->f2B0; j++) {
            func_L39_005958F8(&D_L39_00372EC0[j], p->f3BC[j], func_00120884(p->f3BC[j]));
            p->f3BC[j] = D_L39_00372EC0[j].s;
        }
        p->f114->f60->f20(p->f114, 3, 0);
        p->f114->f60->f6C(p->f114, p->f2B0, p->f3BC);
        p->f114->f60->f88(p->f114, cur);
    } else {
        char *opts[2] = { D_L39_00248020, (char *)func_00381FF0(0x101B) };

        p->f114->f60->f20(p->f114, 2, 0);
        p->f114->f60->f6C(p->f114, 2, opts);
        p->f114->f60->f88(p->f114, cur);
    }
}
/* localdecomp:end func_L39_00697B80 */
