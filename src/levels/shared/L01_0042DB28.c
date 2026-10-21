#include "common.h"

/* localdecomp:start func_L01_0042DB28 */
extern u8 D_001426E0[];

s32 func_L01_0042DB28(s32 bit) {
    s32 i = bit / 8;
    s32 b = bit % 8;
    s32 r;
    if ((u32)b < 8) { r = (D_001426E0[0x40 + i] >> b) & 1; } else { r = 0; }
    return r;
}
/* localdecomp:end func_L01_0042DB28 */

/* localdecomp:start func_L01_0042DB70 */
extern void func_L01_0042FEB0(s32 *out, s32 a1, s32 a2);
extern void func_L01_0042E768(s32 a);
typedef struct {
    s32 a;
    s32 b;
    s32 p;
    s32 pad;
} E_42AD60;

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
    s32 w16;
    s32 w20;
    u8 pad18[40 - 24];
    s32 w40;
    u8 pad2c[48 - 44];
    E_42AD60 e[8];
    u8 padB0[180 - 176];
    f32 f180[61];
    s32 a424[61];
    s32 a668[61];
    u8 pad390[1040 - 912];
    s32 idx;
    u8 pad414[1048 - 1044];
    s32 w1048;
    s32 w1052;
    s32 w1056;
} G_42AD60;

typedef struct {
    s32 off;
    s32 size;
} P_42AD60;

typedef struct {
    u8 pad0[18772];
    s32 base;
    u8 pad4958[24008 - 18776];
    P_42AD60 a[60];
    P_42AD60 b[60];
} T_42AD60;

extern G_42AD60 D_L01_001F3FA0;
extern P_42AD60 D_L01_002E71F8[];
extern s32 D_001D545C;
extern T_42AD60 D_00160C40;
extern u8 D_00142CA0[];
extern s32 *D_L01_001EA950[];
extern char D_L01_001D7120[];
extern char D_L01_001D7138[];
extern u8 D_001A9318[];
extern u8 D_L01_001F4330[];

extern s32 func_003A26F0(s32 *, s32, s32);
extern s32 func_003A8678(s32 *, s32, s32, char *);
extern s32 func_003A0760(s32 *, s32 *);
extern s32 func_003932C0(s32, s32, char *, s32);
extern void func_0038CD28(s32, void *, s32);
extern s32 func_L01_0042DB28(s32);
extern void func_L01_00430A80(s32, u8 *, s32);

void func_L01_0042DB70(void) {
    s32 i;
    s32 j;
    s32 x;
    s32 y;
    s32 n;
    s32 *data;
    s32 *dst;
    s32 sz;
    char *str;
    s32 sz2;
    f32 dy;
    f32 dx;
    f32 r2;
    f32 c;

    D_L01_001F3FA0.w16 = 1;
    for (i = 0; i < 61; i++) {
        D_L01_001F3FA0.a424[i] = D_L01_002E71F8[i].off;
        D_L01_001F3FA0.f180[i] = 0.65f;
        D_L01_001F3FA0.a668[i] = D_L01_002E71F8[i].size;
    }
    D_L01_001F3FA0.w1048 = -1;
    ((s32 (*)(s32))func_L01_0042E768)(D_001D545C);
    if ((D_00160C40.a[D_L01_001F3FA0.idx].size != 0 && D_00142CA0[5] == 0) || (D_00160C40.b[D_L01_001F3FA0.idx].size != 0 && D_00142CA0[5] != 0)) {
        D_L01_001F3FA0.w40 = 1;
        n = (D_00142CA0[5] != 0 ? D_00160C40.b[D_L01_001F3FA0.idx].size : D_00160C40.a[D_L01_001F3FA0.idx].size) << 7;
        data = D_L01_001EA950[0];
        dst = (s32 *)((u8 *)data + 0x9A800);
        if (D_00142CA0[5] != 0) {
            func_003A26F0(dst, D_00160C40.b[D_L01_001F3FA0.idx].off + D_00160C40.base, D_00160C40.b[D_L01_001F3FA0.idx].size);
            D_L01_001F3FA0.w1052 = 1;
        } else {
            func_003A26F0(dst, D_00160C40.a[D_L01_001F3FA0.idx].off + D_00160C40.base, D_00160C40.a[D_L01_001F3FA0.idx].size);
            D_L01_001F3FA0.w1052 = 0;
        }
        D_L01_001F3FA0.w1048 = func_003A8678(dst, n, 16640, D_L01_001D7120);
        str = D_L01_001D7138;
        D_L01_001F3FA0.w1056 = n;
        func_003A0760(dst, data);
        sz = data[1] - data[0];
        D_L01_001F3FA0.w0 = func_003932C0(sz, 0, str, 876);
        func_0038CD28(D_L01_001F3FA0.w0, (u8 *)data + data[0], sz);
        D_L01_001F3FA0.w0 += 8;
        D_L01_001F3FA0.w4 = D_L01_001F3FA0.w0;
        sz2 = data[2] - data[1];
        D_L01_001F3FA0.w20 = func_003932C0(sz2, 0, str, 893);
        func_0038CD28(D_L01_001F3FA0.w20, (u8 *)data + data[1], sz2);
        D_L01_001F3FA0.w8 = func_003932C0(4096, 0, str, 900);
        for (j = 0; j < 8; j++) {
            D_L01_001F3FA0.e[j].a = -1;
            D_L01_001F3FA0.e[j].b = -1;
            D_L01_001F3FA0.e[j].p = D_L01_001F3FA0.w8 + (j << 9);
        }
        D_L01_001F3FA0.w12 = func_003932C0(0x8000, 0, D_L01_001D7138, 909);
        if (func_L01_0042DB28(D_L01_001F3FA0.idx)) {
            func_L01_00430A80(D_L01_001F3FA0.w12, D_001A9318 + (D_L01_001F3FA0.idx << 11), D_L01_001F3FA0.w20);
        } else {
            ((void (*)(s32, s32, s32))func_L01_0042FEB0)(D_L01_001F3FA0.w12, D_L01_001F3FA0.w0, D_L01_001F3FA0.w4);
        }
        r2 = 256.0f;
        c = 15.5f;
        for (y = 0; y < 32; y++) {
            dy = c - y;
            for (x = 0; x < 32; x++) {
                dx = c - x;
                if (r2 < dx * dx + dy * dy) {
                    D_L01_001F4330[x / 8 + y * 4] |= 1 << (x % 8);
                }
            }
        }
    } else {
        D_L01_001F3FA0.w0 = 0;
        D_L01_001F3FA0.w8 = 0;
        D_L01_001F3FA0.w12 = 0;
        D_L01_001F3FA0.w4 = 0;
        D_L01_001F3FA0.w40 = 0;
    }
}
/* localdecomp:end func_L01_0042DB70 */

INCLUDE_ASM("asm/levels", func_L01_0042DF90);

/* localdecomp:start func_L01_0042E170 */
typedef struct {
    s32 a[5];
    s32 b[5];
} Slots_42B360;

extern Slots_42B360 D_L01_001F4408;

s32 func_L01_0042E170(s32 rev)
{
    s32 *a = D_L01_001F4408.a;
    s32 *b = D_L01_001F4408.b;
    s32 j;
    s32 k;

    for (j = 0; j < 5; j++) {
        k = rev ? 4 - j : j;
        if (a[k] != 0 && b[k] == -1) {
            return k;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_0042E170 */

/* localdecomp:start func_L01_0042E1D8 */
extern G_42AD60 D_L01_001F3FA0;
typedef struct {
    u8 pad[1128];
    s32 b[5];
    s32 a[5];
} S42B3C8;

extern s32 func_L01_0042E170(s32);
extern void func_L01_0042E278(s32, s32);

s32 func_L01_0042E1D8(void) {
    s32 i = func_L01_0042E170(1);

    if (i != 0) {
        return i;
    }
    for (i = 1; i < 5; i++) {
        if (!((*(S42B3C8 *)&D_L01_001F3FA0).a[i] & 0x1000) && (*(S42B3C8 *)&D_L01_001F3FA0).b[i] != 0) {
            break;
        }
    }
    func_L01_0042E278(0, i);
    return i;
}
/* localdecomp:end func_L01_0042E1D8 */

/* localdecomp:start func_L01_0042E278 */
extern G_42AD60 D_L01_001F3FA0;
extern void func_0038CD28(s32, void *, s32);
typedef struct {
    u8 pad[1128];
    s32 a[5];
    s32 b[6];
    s32 c[1];
} S_42B468;


void func_L01_0042E278(s32 i, s32 j) {
    ((void (*)(s32, s32, s32))func_0038CD28)((*(S_42B468 *)&D_L01_001F3FA0).a[i], (*(S_42B468 *)&D_L01_001F3FA0).a[j], (*(S_42B468 *)&D_L01_001F3FA0).c[j] << 4);
    (*(S_42B468 *)&D_L01_001F3FA0).b[i] = (*(S_42B468 *)&D_L01_001F3FA0).b[j];
    (*(S_42B468 *)&D_L01_001F3FA0).c[i] = (*(S_42B468 *)&D_L01_001F3FA0).c[j];
    (*(S_42B468 *)&D_L01_001F3FA0).b[j] = -1;
}
/* localdecomp:end func_L01_0042E278 */

/* localdecomp:start func_L01_0042E318 */
extern G_42AD60 D_L01_001F3FA0;
typedef struct {
    char pad[1128];
    int active[5];
    int id[5];
} Unk1F4020;


int func_L01_0042E318(int id)
{
    int i;

    for (i = 0; i < 5; i++) {
        if ((*(Unk1F4020 *)&D_L01_001F3FA0).active[i] != 0 && (*(Unk1F4020 *)&D_L01_001F3FA0).id[i] == id) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L01_0042E318 */

INCLUDE_ASM("asm/levels", func_L01_0042E360);

INCLUDE_ASM("asm/levels", func_L01_0042E3A8);

INCLUDE_ASM("asm/levels", func_L01_0042E500);

INCLUDE_ASM("asm/levels", func_L01_0042E598);

LINKER_REMNANT("asm/levels", func_L01_0042E6F8);

INCLUDE_ASM("asm/levels", func_L01_0042E700);

/* localdecomp:start func_L01_0042E768 */
extern s32 func_L01_0042E788(void);
extern s32 D_L01_001F43B0[];
void func_L01_0042E768(s32 a) {
    D_L01_001F43B0[0] = a;
    ((void (*)(void))func_L01_0042E788)();
}
/* localdecomp:end func_L01_0042E768 */

/* localdecomp:start func_L01_0042E788 */
extern G_42AD60 D_L01_001F3FA0;
typedef struct {
    u8 pad0[36];
    s32 flag;
    u8 pad1[1000];
    s32 val;
} St0042B978;
extern s32 D_001D545C;
extern s32 func_L01_0042E360(s32);
s32 func_L01_0042E788(void) {
    if ((*(St0042B978 *)&D_L01_001F3FA0).val >= 60) {
        (*(St0042B978 *)&D_L01_001F3FA0).val = 59;
    }
    if (func_L01_0042E360((*(St0042B978 *)&D_L01_001F3FA0).val)) {
        (*(St0042B978 *)&D_L01_001F3FA0).flag = 1;
    } else {
        (*(St0042B978 *)&D_L01_001F3FA0).flag = 0;
    }
    if ((*(St0042B978 *)&D_L01_001F3FA0).val == 0 && D_001D545C != 0) {
        (*(St0042B978 *)&D_L01_001F3FA0).flag = 0;
    }
    return (*(St0042B978 *)&D_L01_001F3FA0).flag != 0;
}
/* localdecomp:end func_L01_0042E788 */

INCLUDE_ASM("asm/levels", func_L01_0042E818);

INCLUDE_ASM("asm/levels", func_L01_0042EA78);

INCLUDE_ASM("asm/levels", func_L01_0042EB08);

INCLUDE_ASM("asm/levels", func_L01_0042EBF0);

INCLUDE_ASM("asm/levels", func_L01_0042FE48);

/* localdecomp:start func_L01_0042FEB0 */
extern void func_L01_00430000(u8 *, s32, s32, s32);

void func_L01_0042FEB0(s32 *out, s32 a1, s32 a2) {
    s32 i;
    s32 j;
    s32 k;
    s32 *p;
    s32 bits;
    u8 b;
    u8 *spr;
    s32 x;
    s32 y;

    spr = (u8 *)0x70000000;
    for (i = 0; i < 256; i++) {
        func_L01_00430000((u8 *)0x70000000, i, a1, a2);
        x = i % 16;
        y = i / 16;
        p = &out[x + y * 512];
        for (j = 0; j < 32; j++) {
            bits = 0;
            for (k = 0; k < 32; k++) {
                b = spr[j * 16 + (k >> 1)];
                if (k & 1) {
                    b >>= 4;
                } else {
                    b &= 0xF;
                }
                if (b != 0) {
                    bits |= 1 << k;
                }
                if ((k & 31) == 31) {
                    *p++ = bits;
                    bits = 0;
                }
            }
            p += 15;
        }
    }
}
/* localdecomp:end func_L01_0042FEB0 */

INCLUDE_ASM("asm/levels", func_L01_00430000);

/* localdecomp:start func_L01_00430110 */
extern u8 D_L01_001D71E8;
void func_L01_00430110(u8 a) { D_L01_001D71E8 = a; }
/* localdecomp:end func_L01_00430110 */

INCLUDE_ASM("asm/levels", func_L01_00430118);

INCLUDE_ASM("asm/levels", func_L01_00430460);

/* localdecomp:start func_L01_00430660 */
extern G_42AD60 D_L01_001F3FA0;
typedef struct {
    u8 pad[12];
    u8 *bits;
} S_0042D7D0;
extern s32 func_L01_004308B0(s32);
void func_L01_00430660(s32 x0, s32 y0, s32 w, s32 h) {
    s32 x, y;
    u8 *p;
    s32 m;
    s32 row;
    for (y = y0; y < y0 + h; y++) {
        row = (y >> 5) << 4;
        for (x = x0; x < x0 + w; x++) {
            p = (*(S_0042D7D0 *)&D_L01_001F3FA0).bits + (y << 6) + x / 8;
            m = 1 << (x & 7);
            func_L01_004308B0((x >> 5) + row);
            *p |= m;
        }
    }
}
/* localdecomp:end func_L01_00430660 */

INCLUDE_ASM("asm/levels", func_L01_00430778);

/* localdecomp:start func_L01_004308B0 */
extern void func_L01_00430000(u8 *, s32, s32, s32);
extern G_42AD60 D_L01_001F3FA0;
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    s32 id;
    s32 val;
    s32 w8;
    s32 wC;
} S_42DA20e;

typedef struct {
    s32 w0;
    s32 w4;
    u8 pad8[0x20];
    s32 w28;
    u8 pad2C[4];
    S_42DA20e e[8];
} S_42DA20;

extern s128 D_L01_001F3FD0[];
extern s32 D_L01_001DF948;

s32 func_L01_004308B0(s32 id) {

    s32 ret;
    s32 best;
    s32 i;
    s128 t;


    if ((*(S_42DA20 *)&D_L01_001F3FA0).w28 == 0) {
        return 0;
    }
    ret = 0;
    best = 0;
    for (i = 0; i < 8 && (*(S_42DA20 *)&D_L01_001F3FA0).e[i].id != id; i++) {
        if ((*(S_42DA20 *)&D_L01_001F3FA0).e[i].val < (*(S_42DA20 *)&D_L01_001F3FA0).e[best].val) {
            best = i;
        }
    }
    if (i == 8) {
        ((void (*)(s32, s32, s32, s32))func_L01_00430000)((*(S_42DA20 *)&D_L01_001F3FA0).e[best].w8, id, (*(S_42DA20 *)&D_L01_001F3FA0).w0, (*(S_42DA20 *)&D_L01_001F3FA0).w4);
        (*(S_42DA20 *)&D_L01_001F3FA0).e[best].id = id;
        i = best;
        ret = 1;
    }
    if (i != 0) {
        t = D_L01_001F3FD0[0];
        D_L01_001F3FD0[0] = D_L01_001F3FD0[i];
        D_L01_001F3FD0[i] = t;
    }
    (*(S_42DA20 *)&D_L01_001F3FA0).e[0].val = D_L01_001DF948;
    return ret;
}
/* localdecomp:end func_L01_004308B0 */
