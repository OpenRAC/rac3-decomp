#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* localdecomp:start func_L07_003C0BE8 */
typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 padC[0x10];
    s32 f1C;
} P_003C0BE8;

extern u8 *D_001DE550_sda;
__asm__(".extern D_001DE550_sda, 4");
extern char *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern u8 D_001426E0[];
extern u8 D_00142CBE[];
extern s32 D_00142C30[];
extern u8 D_001D5530[] __attribute__((section(".sdata")));

extern void func_L01_0042B068(s32, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_L01_00456230(char *, s32);
extern void func_L01_004450F0(s32, s32, s32);
extern void func_L07_003C1E48(char *);
extern void func_L07_003C1E80(char *);

void func_L07_003C0BE8(u8 *obj) {
    P_003C0BE8 *p68;
    char *p;

    func_L01_0042B068(1, 0);
    p68 = *(P_003C0BE8 **)(obj + 0x68);
    D_001DE550_sda = obj;
    func_L01_0045F1E8(p68->f1C, -1);

    if ((D_00142C30[0] & 0x10000) == 0) {
        p = D_L07_001DF41C + (p68->f8 << 8);
        func_L01_00456230(p, 1);
        (*(void (**)(char *))(p + 0x64))(p);
        func_L01_004450F0((s32)obj, 0xA, -1);
        return;
    }
    if (D_001426E0[0x8F] != 0 && D_00142CBE[0] == 0) {
        func_L07_003C1E48((char *)obj);
        func_L01_004450F0((s32)obj, 1, -1);
        return;
    }
    if (D_001426E0[0x91] != 0 && D_001D5530[0xD] == 0) {
        func_L07_003C1E80((char *)obj);
        func_L01_004450F0((s32)obj, 1, -1);
        return;
    }
    func_L01_004450F0((s32)obj, 2, -1);
}
/* localdecomp:end func_L07_003C0BE8 */

/* localdecomp:start func_L07_003C0D00 */
void func_L01_003EB5E0(s32, s32);
void func_L01_004450F0(s32, s32, s32);
void func_L01_005003D0(s32, s32);

void func_L07_003C0D00(s32 arg0) {
    func_L01_005003D0(0, 1);
    func_L01_003EB5E0(0, 2);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003C0D00 */

/* localdecomp:start func_L07_003C0D48 */
extern u8 *D_001DE550_sda;
__asm__(".extern D_001DE550_sda, 4");
extern u8 D_L07_001E1710_003C0D48 __asm__("D_L07_001E1710");
__asm__(".extern D_L07_001E1710, 16");
extern u8 D_L07_001E1708_003C0D48 __asm__("D_L07_001E1708");
__asm__(".extern D_L07_001E1708, 16");
extern void func_L01_00516FD8(s32, void *);
extern s32 func_00381FF0(s32);
extern void func_L07_003C0FC8(void *, void *, void *, void *);
extern void func_L07_003C17C0(void *);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_004450F0(s32, s32, s32);

void func_L07_003C0D48(void) {
    u8 *obj = D_001DE550_sda;
    u8 *d = *(u8 **)(obj + 0x68);

    func_L01_00516FD8(0x47001E, &D_L07_001E1710_003C0D48);
    func_L01_00516FD8(0x470019, (void *)func_00381FF0(0xC45));
    func_L01_00516FD8(0x47001A, &D_L07_001E1708_003C0D48);
    func_L01_00516FD8(0x470007, (void *)func_00381FF0(0xC44));
    func_L07_003C0FC8(d + 0x20, d + 0x24, d + 0x39, d + 0x3A);
    func_L07_003C17C0(obj);
    func_L01_005003D0(0x74, 1);
    func_L01_004450F0((s32)obj, 4, -1);
}
/* localdecomp:end func_L07_003C0D48 */

/* localdecomp:start func_L07_003C0E08 */
extern char *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");

extern void func_L07_00330748(s32 a);
void func_L01_004450F0(s32, s32, s32);
void func_L07_003C0E08(O_B *a0, s32 kind) {
    func_L07_00330748((s32)(D_L07_001DF41C + (a0->p68->idx << 8)));
    func_L01_004450F0((s32)a0, 6, -1);
}
/* localdecomp:end func_L07_003C0E08 */

/* localdecomp:start func_L07_003C0E58 */
extern char *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern void func_L01_004F50C8(void *a, void *b, s32 c, s32 d);
extern void func_L07_003BA500(void *p, s32 flag);

void func_L07_003C0E58(char *obj, s32 flag) {
    char *p = D_L07_001DF41C + (**(s32 **)(obj + 0x68) << 8);
    func_L01_004F50C8(p + 0x10, p + 0xF0, 0x74, 1);
    func_L07_003BA500(p, flag & 0xFF);
    func_L01_004450F0(obj, 5, -1);
}
/* localdecomp:end func_L07_003C0E58 */

/* localdecomp:start func_L07_003C0ED8 */
typedef struct { u8 pad0[4]; s16 h4; u8 pad6[0x1E]; } E_003C0ED8;
extern E_003C0ED8 D_L07_002BC920[];
extern void func_L07_003C0F40(u8 *);
void func_L07_003C0ED8(u8 *arg0, s32 i) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    E_003C0ED8 *e = &D_L07_002BC920[i];
    if (e->h4 == -1) {
        func_L01_004450F0(arg0, 8, -1);
    } else {
        p[0x38] = e->h4;
        func_L07_003C0F40(arg0);
    }
}
/* localdecomp:end func_L07_003C0ED8 */

/* localdecomp:start func_L07_003C0F40 */
typedef struct {
    u8 pad0[0x30];
    s32 f30;
    u8 pad34[4];
    u8 b38;
    u8 pad39[2];
    u8 b3B;
} S_003C0F40;

typedef struct {
    u8 b0;
    u8 pad1;
    s16 h2;
    u8 pad4[0x20];
} E_003C0F40;

extern E_003C0F40 D_L07_002BC920_003C0F40[];
extern void func_L07_003C0E08(O_B *, s32);
extern void func_L07_003C0E58(char *, s32);
extern void func_L01_004596E8(s32, s32);
extern void func_L01_00459AF8(void);
extern void func_L01_005003D0(s32, s32);

void func_L07_003C0F40(u8 *arg0) {
    S_003C0F40 *p = *(S_003C0F40 **)(arg0 + 0x68);
    E_003C0F40 *e = &D_L07_002BC920_003C0F40[p->b38];

    if (e->b0 == 0) {
        func_L07_003C0E08((O_B *)arg0, e->h2);
    } else {
        func_L07_003C0E58((char *)arg0, e->h2);
    }
    func_L01_004596E8(0, 0);
    func_L01_00459AF8();
    p->f30 = 0;
    p->b3B = 0;
    func_L01_005003D0(0, 1);
}
/* localdecomp:end func_L07_003C0F40 */

/* localdecomp:start func_L07_003C0FC8 */
extern u8 D_001426E0[];

typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
    s32 f20;
} E_003C0FC8;

extern E_003C0ED8 D_L07_002BC920[];
extern s32 func_L07_003C1120(s32);

void func_L07_003C0FC8(void *arg0, void *arg1, void *arg2, void *arg3) {
    s32 *a0 = arg0;
    s32 *a1 = arg1;
    u8 *a2 = arg2;
    u8 *a3 = arg3;
    s32 i;
    s32 j;

    *a0 = 0;
    *a2 = 0;
    *a1 = 0;
    *a3 = 0;
    for (i = 0; i < 0x1F; i++) {
        if (D_001426E0[0x8E + i] != 0) {
            *a0 |= 1 << i;
            (*a2)++;
        }
    }
    for (j = 0; j < 0x1F; j++) {
        E_003C0FC8 *e = &((E_003C0FC8 *)D_L07_002BC920)[j];

        if (e->f1C != -1) {
            if (func_L07_003C1120(e->f1C) == 0) {
                continue;
            }
        }
        if ((e->f20 & *a0) != e->f20) {
            continue;
        }
        *a1 |= 1 << j;
        (*a3)++;
    }
    *a1 &= ~*a0;
    *a3 -= *a2;
}
/* localdecomp:end func_L07_003C0FC8 */

/* localdecomp:start func_L07_003C1120 */
extern u8 D_0014275B[];
s32 func_L07_003C1120(s32 arg0) {
    if (arg0 == 0) {
        return D_0014275B[0];
    }
    return 1;
}
/* localdecomp:end func_L07_003C1120 */

/* localdecomp:start func_L07_003C1138 */
typedef struct { u8 pad0[0x68]; u8 *p68; } W_003C1138;

typedef struct {
    u8 pad0[0xC];
    u8 bC;
    u8 padD[3];
    s32 f10;
    u8 pad14[0x10];
} E_003C1138;

typedef struct {
    u8 pad0[0x30];
    s32 f30;
    u8 pad34[4];
    u8 b38;
    u8 pad39[2];
    u8 b3B;
} S_003C1138;

extern E_003C1138 D_L07_002BC920_003C1138[];
extern u8 D_001426E0[];
extern s32 D_00142660[];
extern u8 D_001D54B9_003C1138;
__asm__(".extern D_001D54B9_003C1138, 16");
extern u8 D_L07_001DE554;
extern u8 D_L07_001DE555;

extern s32 func_L07_003C12A8();
extern s32 func_L07_003C1360(s32);
extern void func_L01_00459C50(s32);
extern void func_0039EC28(s32, s32);
extern void func_L01_004450F0(s32, s32, s32);

void func_L07_003C1138(W_003C1138 *arg0, s32 arg1) {
    E_003C1138 *e = &D_L07_002BC920_003C1138[arg1];
    S_003C1138 *p = (S_003C1138 *)arg0->p68;
    s32 r;
    s32 i;
    s32 ok;

    if (func_L07_003C12A8(arg0, e->f10) == 0 || e->bC != 0) {
        r = func_L07_003C1360(arg1);
        p->f30 = r;
        D_00142660[0] += r;
    } else {
        p->f30 = -1;
    }

    if (D_001426E0[arg1 + 0x8E] < 0xFF) {
        D_001426E0[arg1 + 0x8E]++;
    }

    if (D_001D54B9_003C1138 == 0) {
        if (D_001426E0[0x9C] != 0 && D_001426E0[0xAC] != 0) {
            func_L01_00459C50(9);
        }
    }

    if (D_001426E0[0xBC] == 0) {
        ok = 1;
        i = 0;
        for (;;) {
            if (i >= 0x1F) {
                break;
            }
            if (D_001426E0[i + 0x8E] == 0) {
                ok = 0;
                break;
            }
            i++;
        }
        if (ok) {
            p->b3B = 1;
            D_001426E0[0xBC] = 1;
        }
    }

    func_0039EC28(1, -1);
    D_L07_001DE555 = 0;
    D_L07_001DE554 = 0;
    func_L01_004450F0((s32)arg0, 7, -1);
}
/* localdecomp:end func_L07_003C1138 */

/* localdecomp:start func_L07_003C12A8 */
typedef struct { u8 pad0[0x68]; u8 *p68; } O_003C12A8;

extern u8 D_00142CBE[];
extern u8 D_001426F5[];
extern u8 D_001D553D_003C12A8;
extern u8 D_001D5551_003C12A8;
__asm__(".extern D_001D553D_003C12A8, 16");
__asm__(".extern D_001D5551_003C12A8, 16");
extern void func_0039EF28(void);
extern void func_L07_003C1E48(char *);
extern void func_L07_003C1E80(char *);

s32 func_L07_003C12A8(O_003C12A8 *arg0, s32 arg1) {
    u8 *p = arg0->p68;
    s32 r = 0;

    switch (arg1) {
    case 2:
        if (D_001D5551_003C12A8 != 0) break;
        return 1;
    case 0:
        if (D_00142CBE[0] != 0) break;
        *(void **)(p + 0x2C) = func_L07_003C1E48;
        D_001426F5[0] = 1;
        func_0039EF28();
        r = 1;
        break;
    case 1:
        if (D_001D553D_003C12A8 != 0) break;
        *(void **)(p + 0x2C) = func_L07_003C1E80;
        r = 1;
        break;
    }
    return r;
}
/* localdecomp:end func_L07_003C12A8 */
