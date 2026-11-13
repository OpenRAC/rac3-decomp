#include "common.h"
#include "vu0.h"

typedef struct {
    char pad[0x410];
    int level;
} Unk1F3FA0_0042E3A8;

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

/* localdecomp:start func_L01_0042DF90 */
extern G_42AD60 D_L01_001F3FA0;
extern T_42AD60 D_00160C40;
extern u8 D_00142CA0[];
extern s32 D_001D545C;
typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0x410 - 0x28];
    s32 idx;
    s32 w414;
    s32 w418;
    s32 w41C;
    s32 w420;
    u8 pad424[0x428 - 0x424];
    s32 w428;
    u8 pad42C[0x468 - 0x42C];
    s32 w468;
    s32 w46C;
    s32 w470;
    s32 w474;
    s32 w478;
    s32 w47C;
    s32 w480;
    s32 w484;
    s32 w488;
    s32 w48C;
    s32 w490;
    u8 pad494[0x498 - 0x494];
    s32 w498;
} G_42DF90;
extern void func_L01_00431808_0042DF90(void);
extern void func_L01_00438028(s32, s32);
extern s32 func_003A26F0(s32 *, s32, s32);
extern void func_003A2750(s32);
extern void func_L01_004B1160(s32, s32, s32, s32);
extern void func_L01_004B11E0(s32, s32, s32, s32, s32);
extern void func_003A5348(s32, s32, s32);

void func_L01_0042DF90(s32 *a, s32 *b) {
    s32 n;
    s32 r;

    func_L01_00431808_0042DF90();
    func_L01_00438028((*(G_42DF90 *)&D_L01_001F3FA0).idx, 1);
    (*(G_42DF90 *)&D_L01_001F3FA0).w428 = *a;
    *a += 0x9A800;
    (*(G_42DF90 *)&D_L01_001F3FA0).w468 = 0;
    (*(G_42DF90 *)&D_L01_001F3FA0).w46C = *a;
    *a += 0x48000;
    (*(G_42DF90 *)&D_L01_001F3FA0).w470 = *b;
    *b += 0x48000;
    (*(G_42DF90 *)&D_L01_001F3FA0).w474 = 0;
    (*(G_42DF90 *)&D_L01_001F3FA0).w478 = 0;
    (*(G_42DF90 *)&D_L01_001F3FA0).w47C = -1;
    (*(G_42DF90 *)&D_L01_001F3FA0).w480 = -1;
    (*(G_42DF90 *)&D_L01_001F3FA0).w484 = -1;
    (*(G_42DF90 *)&D_L01_001F3FA0).w488 = -1;
    (*(G_42DF90 *)&D_L01_001F3FA0).w48C = -1;
    (*(G_42DF90 *)&D_L01_001F3FA0).w490 = -1;
    if ((*(G_42DF90 *)&D_L01_001F3FA0).w418 != -1 && (*(G_42DF90 *)&D_L01_001F3FA0).w41C == 0 && D_00142CA0[5] != 0) {
        n = D_00160C40.b[(*(G_42DF90 *)&D_L01_001F3FA0).idx].size << 7;
        func_003A26F0((s32 *)(*(G_42DF90 *)&D_L01_001F3FA0).w46C, D_00160C40.b[(*(G_42DF90 *)&D_L01_001F3FA0).idx].off + D_00160C40.base, D_00160C40.b[(*(G_42DF90 *)&D_L01_001F3FA0).idx].size);
        func_003A2750(1);
        (*(G_42DF90 *)&D_L01_001F3FA0).w41C = 1;
        (*(G_42DF90 *)&D_L01_001F3FA0).w420 = n;
        (*(G_42DF90 *)&D_L01_001F3FA0).w498 = n;
        func_L01_004B1160((*(G_42DF90 *)&D_L01_001F3FA0).w46C, (*(G_42DF90 *)&D_L01_001F3FA0).w418, 0, n);
        (*(G_42DF90 *)&D_L01_001F3FA0).w414 = -2;
        (*(G_42DF90 *)&D_L01_001F3FA0).w24 = 1;
        (*(G_42DF90 *)&D_L01_001F3FA0).w480 = D_001D545C + 0x100;
    } else if ((*(G_42DF90 *)&D_L01_001F3FA0).w418 != -1) {
        (*(G_42DF90 *)&D_L01_001F3FA0).w498 = (*(G_42DF90 *)&D_L01_001F3FA0).w420;
        func_L01_004B11E0((*(G_42DF90 *)&D_L01_001F3FA0).w46C, (*(G_42DF90 *)&D_L01_001F3FA0).w418, 0, (*(G_42DF90 *)&D_L01_001F3FA0).w420, 0);
        r = D_001D545C;
        if (D_00142CA0[5] != 0) {
            r += 0x100;
        }
        (*(G_42DF90 *)&D_L01_001F3FA0).w480 = r;
        (*(G_42DF90 *)&D_L01_001F3FA0).w24 = 1;
        (*(G_42DF90 *)&D_L01_001F3FA0).w414 = -2;
    } else {
        (*(G_42DF90 *)&D_L01_001F3FA0).w24 = 0;
    }
    func_003A5348(0x11, 0, 0);
}
/* localdecomp:end func_L01_0042DF90 */

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

/* localdecomp:start func_L01_0042E3A8 */
extern G_42AD60 D_L01_001F3FA0;
extern s32 *D_L01_001D8D50;
extern u8 D_00142CA0[];
extern int func_L01_0042E318(int id);
extern int func_L01_0042E360(int id);

int func_L01_0042E3A8(void)
{
    int level;
    int flag;
    unsigned int id;
    int *p;
    int index;
    unsigned int delta;
    int notfound;
    int limit;
    int one;
    int offset;
    int entry;

    flag = D_00142CA0[5] ? 0x100 : 0;
    id = (*(Unk1F3FA0_0042E3A8 *)&D_L01_001F3FA0).level + flag;
    if (func_L01_0042E318(id) == -1) {
        if (func_L01_0042E360(id) != 0)
            return id;
    }
    level = (*(Unk1F3FA0_0042E3A8 *)&D_L01_001F3FA0).level;
    index = 0;
    if (level < 0x3C) {
        p = D_L01_001D8D50;
        while (*p != level) {
            p++;
            index++;
        }
    }
    delta = 1;
    notfound = -1;
    one = 1;
    limit = 4;
    do {
        offset = index + delta;
        if (offset < 0) goto update;
        if (offset >= 0x3C) goto update;
        {
            entry = D_L01_001D8D50[offset];
            if (entry != 0) {
                id = entry + flag;
                if (func_L01_0042E318(id) == notfound && func_L01_0042E360(id) != 0)
                    return id;
            }
        }
update:
        delta = ((int)delta > 0) ? -(int)delta : (one - delta);
    } while (delta != limit);
    return -1;
}
/* localdecomp:end func_L01_0042E3A8 */

/* localdecomp:start func_L01_0042E500 */
extern s32 *D_L01_001D8D50;

s32 func_L01_0042E500(s32 p) {
    s32 index = -1;
    s32 i = 0;
    for (i = 0; i < 60; i++) {
        if (D_L01_001D8D50[i] == p) {
            index = i;
            break;
        }
    }
    if (D_L01_001D8D50[index] == 1) {
        if (D_001D545C != 1) {
            index = -1;
        }
    }
    return (D_L01_001D8D50[index] != 0xB) ? index : -1;
}
/* localdecomp:end func_L01_0042E500 */

/* localdecomp:start func_L01_0042E598 */
extern G_42AD60 D_L01_001F3FA0;
typedef struct {
    u8 pad0[0x410];
    s32 level;
    u8 pad414[0x468 - 0x414];
    s32 active[5];
    s32 id[5];
    s32 cur;
} S_0042E598;
extern s32 func_L01_0042E500(s32 p);

s32 func_L01_0042E598(void) {
    s32 best = 0;
    s32 bi = -1;
    s32 i;
    s32 j;
    s32 ref;
    s32 d;

    if ((*(S_0042E598 *)&D_L01_001F3FA0).level == 0) {
        for (j = 4; j >= 0; j--) {
            if ((*(S_0042E598 *)&D_L01_001F3FA0).active[j] == 0) {
                continue;
            }
            if (j == (*(S_0042E598 *)&D_L01_001F3FA0).cur) {
                continue;
            }
            if ((*(S_0042E598 *)&D_L01_001F3FA0).id[j] == -1) {
                return j;
            }
        }
    }
    ref = func_L01_0042E500((*(S_0042E598 *)&D_L01_001F3FA0).level);
    if (ref == -1) {
        return 1;
    }
    for (i = 0; i < 5; i++) {
        if ((*(S_0042E598 *)&D_L01_001F3FA0).active[i] == 0) {
            continue;
        }
        if (i == (*(S_0042E598 *)&D_L01_001F3FA0).cur) {
            continue;
        }
        if ((*(S_0042E598 *)&D_L01_001F3FA0).id[i] == -1) {
            return i;
        }
        d = abs_asm(func_L01_0042E500((*(S_0042E598 *)&D_L01_001F3FA0).id[i] & 0xFF) - ref);
        if (best < d) {
            best = d;
            bi = i;
        }
    }
    if (bi == -1) {
        bi = 0;
    }
    (*(S_0042E598 *)&D_L01_001F3FA0).id[bi] = -1;
    return bi;
}
/* localdecomp:end func_L01_0042E598 */

LINKER_REMNANT("asm/levels", func_L01_0042E6F8);

/* localdecomp:start func_L01_0042E700 */
extern void (*D_002560D0[])(void);

/* from rac2-decomp's func_00295BE8, renamed */
void func_L01_0042E700(u8 *a0,u8 *a1,u8 *a2,u8 *a3) {
 s32 i=0;
 do {
  s32 next=i+1;
  u32 mask=1;
  u8 *nextp=a3+1;
  s32 j=7;
  do {
   u8 value;
   j--;
   if(*a3&mask) value=*a1; else value=*a2;
   mask<<=1;
   *a0=value;
   a1++;a2++;a0++;
  } while(j>=0);
  i=next;
  a3=nextp;
 } while(i<0x8000);
}
/* localdecomp:end func_L01_0042E700 */

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

/* localdecomp:start func_L01_0042E818 */
extern G_42AD60 D_L01_001F3FA0;
typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[0xB4 - 0x28];
    f32 scale[61];
    s32 x[61];
    s32 y[61];
    u8 pad390[0x414 - 0x390];
    s32 cur;
} S_0042E818;
extern u8 *D_001D52FC;
extern s32 D_L01_001D7140;
extern s32 D_L01_001D7144;
__asm__(".extern D_L01_001D7140, 4");
__asm__(".extern D_L01_001D7144, 4");
extern void func_L01_00431808_0042E818(void);
extern s32 func_L01_0042E788(void);
extern void func_003A5348(s32, s32, s32);

s32 func_L01_0042E818(void) {
    f32 s;
    s32 w;
    s32 h;
    s32 dx;
    s32 dy;
    s32 mx;
    s32 my;

    func_L01_00431808_0042E818();
    func_L01_0042E788();
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x510) {
        func_003A5348(0x13, 0, 0);
        return 1;
    }
    if ((*(S_0042E818 *)&D_L01_001F3FA0).w24 == 0) {
        return 0;
    }
    if ((*(S_0042E818 *)&D_L01_001F3FA0).cur < 0) {
        return 0;
    }
    (*(S_0042E818 *)&D_L01_001F3FA0).scale[(*(S_0042E818 *)&D_L01_001F3FA0).cur] *= 1.0f - *(f32 *)(D_001D52FC + 0x144) * 0.02f;
    if (1.0f < (*(S_0042E818 *)&D_L01_001F3FA0).scale[(*(S_0042E818 *)&D_L01_001F3FA0).cur]) {
        (*(S_0042E818 *)&D_L01_001F3FA0).scale[(*(S_0042E818 *)&D_L01_001F3FA0).cur] = 1.0f;
    }
    if ((*(S_0042E818 *)&D_L01_001F3FA0).scale[(*(S_0042E818 *)&D_L01_001F3FA0).cur] < 0.65f) {
        (*(S_0042E818 *)&D_L01_001F3FA0).scale[(*(S_0042E818 *)&D_L01_001F3FA0).cur] = 0.65f;
    }
    s = 3000000.0f / (*(S_0042E818 *)&D_L01_001F3FA0).scale[(*(S_0042E818 *)&D_L01_001F3FA0).cur];
    w = 0x1000 - (D_L01_001D7140 << 4);
    h = 0xD00 - (D_L01_001D7144 << 4);
    (*(S_0042E818 *)&D_L01_001F3FA0).x[(*(S_0042E818 *)&D_L01_001F3FA0).cur] += (s32)(*(f32 *)(D_001D52FC + 0x148) * s);
    (*(S_0042E818 *)&D_L01_001F3FA0).y[(*(S_0042E818 *)&D_L01_001F3FA0).cur] += (s32)(*(f32 *)(D_001D52FC + 0x14C) * s);
    dx = (s32)((f32)w / (*(S_0042E818 *)&D_L01_001F3FA0).scale[(*(S_0042E818 *)&D_L01_001F3FA0).cur]) << 15;
    dy = (s32)((f32)h / (*(S_0042E818 *)&D_L01_001F3FA0).scale[(*(S_0042E818 *)&D_L01_001F3FA0).cur]) << 15;
    mx = 0x10000000 - dx;
    my = 0x10000000 - dy;
    if ((*(S_0042E818 *)&D_L01_001F3FA0).x[(*(S_0042E818 *)&D_L01_001F3FA0).cur] < dx) {
        (*(S_0042E818 *)&D_L01_001F3FA0).x[(*(S_0042E818 *)&D_L01_001F3FA0).cur] = dx;
    }
    if (mx < (*(S_0042E818 *)&D_L01_001F3FA0).x[(*(S_0042E818 *)&D_L01_001F3FA0).cur]) {
        (*(S_0042E818 *)&D_L01_001F3FA0).x[(*(S_0042E818 *)&D_L01_001F3FA0).cur] = mx;
    }
    if ((*(S_0042E818 *)&D_L01_001F3FA0).y[(*(S_0042E818 *)&D_L01_001F3FA0).cur] < dy) {
        (*(S_0042E818 *)&D_L01_001F3FA0).y[(*(S_0042E818 *)&D_L01_001F3FA0).cur] = dy;
    }
    if (my < (*(S_0042E818 *)&D_L01_001F3FA0).y[(*(S_0042E818 *)&D_L01_001F3FA0).cur]) {
        (*(S_0042E818 *)&D_L01_001F3FA0).y[(*(S_0042E818 *)&D_L01_001F3FA0).cur] = my;
    }
    return 0;
}
/* localdecomp:end func_L01_0042E818 */

/* localdecomp:start func_L01_0042EA78 */
extern f32 D_L01_001D7148;
extern f32 D_L01_001D714C;
extern s32 D_L01_001D7150;
__asm__(".extern D_L01_001D7148, 4");
__asm__(".extern D_L01_001D714C, 4");
__asm__(".extern D_L01_001D7150, 4");
extern f32 func_L01_004451A8(f32 f12);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L01_0042EA78(void) {
    f32 d;

    D_L01_001D7148 += D_L01_001D714C * 0.0249999985f;
    d = D_L01_001D714C;
    if (D_L01_001D7148 < 0.0f || 1.0f < D_L01_001D7148) {
        d = -d;
    }
    D_L01_001D714C = d;
    D_L01_001D7150 = func_0038DBD8(0x20, 0x2020FF, func_L01_004451A8(D_L01_001D7148));
}
/* localdecomp:end func_L01_0042EA78 */

/* localdecomp:start func_L01_0042EB08 */
typedef struct {
    s32 id;
    s32 color;
} E_0042EB08;
extern E_0042EB08 D_L01_001D7158[1];
__asm__(".extern D_L01_001D7158, 8");
extern f32 D_L01_001D7148;
extern s32 D_L01_001D7150;
extern f32 func_L01_004451A8(f32 f12);
extern s32 func_0038DBD8(s32, s32, f32);

s32 func_L01_0042EB08(s32 id, s32 type) {
    s32 r = 0x7F7F7F;
    s32 i;

    if (id == 0xE99A) {
        if ((u32)(type - 5) < 4) {
            for (i = 0; D_L01_001D7158[i].id != -1; i++) {
                if (D_L01_001D7158[i].id == type) {
                    break;
                }
            }
            if (D_L01_001D7158[i].id != -1) {
                r = D_L01_001D7158[i].color;
            }
        } else if (type == 1) {
            r = D_L01_001D7150;
        } else if (type == 3) {
            r = func_0038DBD8(0x20, 0xE0FFE0, func_L01_004451A8(D_L01_001D7148));
        } else if (type == 0) {
            r = 0x2020E0;
        }
    }
    return r;
}
/* localdecomp:end func_L01_0042EB08 */

INCLUDE_ASM("asm/levels", func_L01_0042EBF0);

/* localdecomp:start func_L01_0042FE48 */
extern s32 D_001D545C;
extern s32 D_L01_001D7BE0;
extern f32 D_L01_001D71D8[2];
extern f32 D_L01_001D71E0[2];
__asm__(".extern D_L01_001D71D8, 4");
__asm__(".extern D_L01_001D71E0, 4");

s32 func_L01_0042FE48(f32 *x, f32 *y) {
    s32 r = 0;

    if (D_001D545C == 3) {
        if (D_L01_001D7BE0 == 9) {
            *x = D_L01_001D71D8[0];
            *y = D_L01_001D71D8[1];
            r = 1;
        } else if ((u32)D_L01_001D7BE0 < 9) {
            r = 1;
            *x = D_L01_001D71E0[0];
            *y = D_L01_001D71E0[1];
        }
    }
    return r;
}
/* localdecomp:end func_L01_0042FE48 */

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

/* localdecomp:start func_L01_00430000 */
extern void (*D_002560D0[])(void);

void func_L01_00430000(u8 *out,s32 index,s32 ibase,s32 ioffsets) {
    u8 *base=(u8 *)ibase;short *offsets=(short *)ioffsets;
    s32 pending=0;
    u8 *start;
    short *table;
    s32 records,i;
    if (index!=0) start=base+(offsets+index)[-1];
    else start=base+0x200;
    table=(short *)(index*2+(s32)offsets);
    records=((base+*table-start)*2)/3;
    for(i=0;i<records;i++) {
        s32 position=i*2+i;
        u8 *p=start+(position>>1);
        u8 color=p[0],runByte=p[1],fill;
        s32 run;
        if ((position&1)!=0) color>>=4;
        else {
            runByte=(u8)((runByte<<4)|(color>>4));
            color&=15;
        }
        run=256;
        if(runByte!=0) run=runByte;
        fill=(u8)(color|(color<<4));
        if(pending) {
            pending=0;run--;
            *out |= color<<4;
            out++;
        }
        if(run!=0) {
            do {*out++=fill;run-=2;} while(run>0);
            if(run!=0) {out--;pending=1;*out=color;}
        }
    }
}
/* localdecomp:end func_L01_00430000 */

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
