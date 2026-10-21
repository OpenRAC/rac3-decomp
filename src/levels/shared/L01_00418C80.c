#include "common.h"

typedef struct {
    u8 pad[0x46];
    s16 h46;
    s16 h48;
    u8 pad4A[0xF0 - 0x4A];
} E_416790;
typedef struct {
    s32 v[12];
} T416878;
typedef struct {
    u8 pad[6];
    s16 f6;
    u8 pad8[2];
} S_00416920;
typedef struct {
    u8 b0;
    u8 pad[239];
} E_00416968;
typedef struct {
    u8 pad0[8];
    s32 w8;
    u8 padC[0xF0 - 0xC];
} S_416A10;
typedef struct {
    u8 pad0[0x84];
    u16 field_84;
    u8 pad86[8];
    u16 field_8E;
    u8 pad90[0x60];
} Entry;
typedef struct {
    u8 b0;
    u8 b1;
    u8 pad[122];
    s32 f124;
    u8 pad2[4];
    u16 h132;
    u8 pad3[106];
} Ent_00416BF8;
typedef struct {
    s32 key;
    s32 val;
} Pair_00417670;
typedef struct { s32 a[5]; } S5_004176B0;
typedef struct {
    u8 b0;
    u8 pad1[71];
    s16 h72;
    u8 pad2[58];
    u16 h132;
    u8 pad3[4];
    u16 h138;
    u8 pad4[100];
} S_004176F8;
typedef int s128_417810 __attribute__((mode(TI)));
typedef struct {
    union {
        s128_417810 q[15];
        struct {
            u8 b0;
            u8 depth;
            u8 pad2[68];
            s16 child;
            s16 parent;
        } f;
    } u;
} S_417810;
typedef struct { unsigned char a; unsigned char b; char pad[238]; } S_00417920;

/* localdecomp:start func_L01_00418C80 */
extern void func_L01_00418C80(void);

extern s16 D_L01_001EA744[];
 
void func_L01_00418C80(void) {
    D_L01_001EA744[0] = 0;
}
/* localdecomp:end func_L01_00418C80 */

INCLUDE_ASM("asm/levels", func_L01_00418C90);

LINKER_REMNANT("asm/levels", func_L01_00418D40);

INCLUDE_ASM("asm/levels", func_L01_00418D48);

/* localdecomp:start func_L01_00418DE0 */
extern E_416790 D_L01_002C5600[];
extern u8 D_001425C0[];
extern s32 func_L01_00418D48(s32);
s32 func_L01_00418DE0(s32 root, s32 n) {
    s32 cur = root;
    s32 r = 0;
    s32 i;
    if (func_L01_00418D48(cur) >= n) {
        while (((E_416790 *)(cur * 240 + (s32)D_L01_002C5600))->h48 != 0) {
            cur = ((E_416790 *)(cur * 240 + (s32)D_L01_002C5600))->h48;
            root = cur;
        }
        for (i = 0; i < n; i++) {
            cur = ((E_416790 *)(cur * 240 + (s32)D_L01_002C5600))->h46;
        }
        D_001425C0[root] = cur;
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_00418DE0 */

/* localdecomp:start func_L01_00418EC8 */

extern T416878 D_L01_001D6620;

s32 func_L01_00418EC8(s32 x) {
    T416878 t = D_L01_001D6620;
    s32 *p;

    if (t.v[0] != 0) {
        p = t.v;
        do {
            if (x == *p) {
                return 1;
            }
            p++;
        } while (*p != 0);
    }
    return 0;
}
/* localdecomp:end func_L01_00418EC8 */

/* localdecomp:start func_L01_00418F70 */
extern S_00416920 D_L01_002E9F38[];
s32 func_L01_00418F70(s32 id) {
    s32 i;
    for (i = 0; D_L01_002E9F38[i].f6 != -1; i++) {
        if (id == D_L01_002E9F38[i].f6) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00418F70 */

/* localdecomp:start func_L01_00418FB8 */
extern E_416790 D_L01_002C5600[];
extern u8 D_001425C0[];
extern s32 func_L01_00418EC8(s32);
extern s32 func_L01_00418F70(s32);
s32 func_L01_00418FB8(s32 a0) {
    if (a0 == 9) {
        return 0;
    }
    if (a0 == 3) {
        return 0;
    }
    if (a0 == 2) {
        return 0;
    }
    if ((u32)(a0 - 36) < 3) {
        return 1;
    }
    if (func_L01_00418EC8(a0)) {
        return 0;
    }
    if (((E_00416968 *)&D_L01_002C5600)[D_001425C0[a0]].b0) {
        return 1;
    }
    return func_L01_00418F70(a0) != 0;
}
/* localdecomp:end func_L01_00418FB8 */

/* localdecomp:start func_L01_00419060 */
extern E_416790 D_L01_002C5600[];

extern s32 func_L01_00418FB8(s32);
extern u8 D_001425C0[];
extern s32 D_001D4C60;
extern s32 D_001D4C80;

void func_L01_00419060(s32 id) {
    s32 i;

    if (func_L01_00418FB8(id) == 0) {
        return;
    }
    if ((((S_416A10 *)&D_L01_002C5600) + D_001425C0[id])->w8 != 0 && id != 30) {
        return;
    }
    for (i = 0; i < 8 && (&D_001D4C60)[i] != 0; i++) {
        if ((&D_001D4C60)[i] == id || (&D_001D4C80)[i] == id) {
            return;
        }
    }
    if (i < 8) {
        (&D_001D4C60)[i] = id;
        return;
    }
    for (i = 0; i < 8 && (&D_001D4C80)[i] != 0; i++) {
    }
    if (i < 8) {
        (&D_001D4C80)[i] = id;
    }
}
/* localdecomp:end func_L01_00419060 */

/* localdecomp:start func_L01_00419188 */
extern s32 func_L01_00419248(s32 idx);
extern E_416790 D_L01_002C5600[];

extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern u8 D_00142D40[];
extern s32 D_001427F0[];
extern s32 func_0039EF28(void);
extern void func_L01_00419060(s32);

void func_L01_00419188(s32 idx) {
    Entry *e;

    if (D_00142CA0[idx] == 0) {
        D_00142CA0[idx] = 1;
        D_00142D40[idx] = 1;
        e = &((Entry *)&D_L01_002C5600)[D_001425C0[idx]];
        func_0039EF28();
        if (e->field_84 != 0 && D_001427F0[idx] == 0) {
            D_001427F0[idx] = e->field_8E;
        }
        ((void (*)(s32))func_L01_00419248)(idx);
        func_L01_00419060(idx);
    }
}
/* localdecomp:end func_L01_00419188 */

/* localdecomp:start func_L01_00419248 */
extern E_416790 D_L01_002C5600[];

extern u8 D_001425C0[];
extern u8 D_00142CA0[];
/* Real table holds 32 slots; declared small so the address is one la. */
extern u16 D_001D54D8[4];

s32 func_L01_00419248(s32 idx) {
    Ent_00416BF8 *e = &((Ent_00416BF8 *)&D_L01_002C5600)[D_001425C0[idx]];
    s32 r = 0;
    s32 i;
    u16 v;
    s32 f;

    if (e->b0 != 0 && e->b1 == 0 && (e->f124 != 0 || e->h132 != 0)) {
        for (i = 0; i < 32; i++) {
            v = D_001D54D8[i];
            if (((v & 0x3FFF) == idx && !(v & 0x4000)) || v == 0xFFFF) {
                f = D_00142CA0[idx] ? 0x8000 : 0;
                D_001D54D8[i] = idx | f;
                r = 1;
                break;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L01_00419248 */

LINKER_REMNANT("asm/levels", func_L01_00419310);

INCLUDE_ASM("asm/levels", func_L01_00419318);

INCLUDE_ASM("asm/levels", func_L01_00419C18);

/* localdecomp:start func_L01_00419CC0 */
extern Pair_00417670 D_L01_002D1540[];
s32 func_L01_00419CC0(s32 a0) {
    s32 i;
    for (i = 0; D_L01_002D1540[i].key != 0; i++) {
        if (a0 == D_L01_002D1540[i].key) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00419CC0 */

/* localdecomp:start func_L01_00419D00 */
extern S5_004176B0 D_L01_001D6650;
s32 func_L01_00419D00(s32 i) {
    S5_004176B0 t = D_L01_001D6650;
    return t.a[i];
}
/* localdecomp:end func_L01_00419D00 */

/* localdecomp:start func_L01_00419D48 */
extern E_416790 D_L01_002C5600[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern s32 D_00142DE0[];
extern s32 func_L01_00418DE0(s32, s32);
extern s32 func_L01_0044CD60(s32);
s32 func_L01_00419D48(s32 a0) {
    s32 r = 0;
    S_004176F8 *t;
    if ((((S_004176F8 *)&D_L01_002C5600) + D_001425C0[a0])->b0 != 0) {
        while ((((S_004176F8 *)&D_L01_002C5600) + a0)->h72 != 0) {
            a0 = (((S_004176F8 *)&D_L01_002C5600) + a0)->h72;
        }
        r = func_L01_00418DE0(a0, 5);
        if (r != 0) {
            t = ((S_004176F8 *)&D_L01_002C5600) + D_001425C0[a0];
            if (t->h132 != 0) {
                D_001427F0[a0] = t->h138;
            }
            func_L01_0044CD60(a0);
            D_00142DE0[a0] = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L01_00419D48 */

/* localdecomp:start func_L01_00419E60 */
extern E_416790 D_L01_002C5600[];



s32 func_L01_00419E60(S_417810 *out, s32 idx, s32 depth) {
    s32 ok = 0;
    s32 i;

    if (depth < 255) {
        while (((S_417810 *)&D_L01_002C5600)[idx].u.f.parent != 0) {
            idx = ((S_417810 *)&D_L01_002C5600)[idx].u.f.parent;
        }
        for (i = 0; i < depth && ((S_417810 *)&D_L01_002C5600)[idx].u.f.child != 0; i++) {
            idx = ((S_417810 *)&D_L01_002C5600)[idx].u.f.child;
        }
        if (((S_417810 *)&D_L01_002C5600)[idx].u.f.depth == depth) {
            ok = 1;
            *out = ((S_417810 *)&D_L01_002C5600)[idx];
        }
    }
    return ok;
}
/* localdecomp:end func_L01_00419E60 */

LINKER_REMNANT("asm/levels", func_L01_00419F68);

/* localdecomp:start func_L01_00419F70 */
extern E_416790 D_L01_002C5600[];
extern unsigned char D_001425C9[];
int func_L01_00419F70(void)
{
    int r = 1;
    int v = (((S_00417920 *)&D_L01_002C5600) + D_001425C9[0])->b;
    if (v >= 4) {
        return 2;
    }
    return r < v;
}
/* localdecomp:end func_L01_00419F70 */
