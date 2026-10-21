#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0039AE18(s32);
/* --- end of declarations from other files --- */

/* declarations of 39A9A8.c's earlier functions (tools/port_from_us.py) */
extern void func_0038CF58(void *, s32, s32);
extern u8 D_0016C690[];
extern s32 D_001D600C;
typedef struct { u8 pad[0x34]; s32 arr[8]; } T_00395958;
extern T_00395958 D_0016C690_0039AB28;
typedef struct { s32 f0; s32 f4; } S_00395958;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_003959A8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_003959A8 el[0x30]; } S_003959A8;
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; } L_003959A8;
typedef struct { s32 f0; s32 f4; u8 *f8; } A_003959A8;
extern S_003959A8 D_160C40_0039AB78;
extern void func_0039AB28();
extern void func_11F0A0();
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_003A2A30();
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_00395AC8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_00395AC8 el[0x30]; } S_00395AC8;
extern S_00395AC8 D_160C40_0039AC98;
typedef struct { u8 pad[0x34]; s32 f34[3]; } T_00395AC8;
extern T_00395AC8 D_16C690_0039AC98;
extern s32 D_001D6000_0039AC98;
extern u8 D_001D6004_0039AC98;
extern u8 D_001D6008_0039AC98;
extern s32 func_003A2A30();
extern void func_0039AB28();
extern void func_0039AB78();

/* localdecomp:start func_0039AD90 */
typedef struct { s32 k; u8 pad[0x10]; } E_395BC0;
typedef struct { u8 pad[0x4590]; E_395BC0 e[0x30]; } S_395BC0;
typedef struct { u8 d[0xC800]; } B_395BC0;
typedef struct { u8 pad[0x34]; s32 f34[3]; B_395BC0 blk[1]; } S_395BC0b;
extern S_395BC0 D_160C40_0039AD90;
extern S_395BC0b D_16C690_0039AD90;
void func_0039AD90(s32 a, s32 b) {
    s32 i;
    for (i = 0; i < 0x30; i++) {
        if (D_160C40_0039AD90.e[i].k == a) break;
    }
    if (i == 0x30) return;
    if (D_16C690_0039AD90.f34[b] == i) return;
    func_0039AC98(i, b, &D_16C690_0039AD90.blk[b], 0);
}
/* localdecomp:end func_0039AD90 */

/* localdecomp:start func_0039AE18 */
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[0xDC]; } E_395C48;
typedef struct { s32 id; s32 pad[4]; } F_395C48;
typedef struct { u8 pad[0x4590]; F_395C48 e[0x30]; } S_395C48;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395C48;
typedef struct { u8 pad[0x25F8]; s32 f25F8; u8 pad2[0x18]; s32 f2614; } A_395C48;
extern A_395C48 D_1A4BE0;
extern u8 D_001425C0[];
extern s32 D_00142674[];
extern s16 D_001CCFD4[];
extern E_395C48 D_001DAA40[];
extern S_395C48 D_160C40_0039AE18;
extern T_395C48 D_16C690_0039AE18;
extern s32 func_0039AFE8(s32);
static __inline__ s32 get_395C48(s32 n) {
    E_395C48 *e = &D_001DAA40[D_001425C0[n]];
    return e->f10;
}
void func_0039AE18(s32 id) {
    s32 a, b, x, y, i, t, k;
    if (func_0039AFE8(id) != 0) return;
    if (D_001CCFD4[0] != 0) return;
    i = 0;
    a = get_395C48(D_1A4BE0.f2614);
    b = get_395C48(*(s32 *)0x1D4C40); /* an extern symbol here schedules differently */
    if (b == a) {
        b = get_395C48(D_00142674[0]);
    }
    y = -1;
    if (a == id) a = -1;
    if (b == id) b = -1;
    x = -1;
    for (; i < 3; i++) {
        s32 e = D_160C40_0039AE18.e[D_16C690_0039AE18.v[i]].id;
        if (a == e) x = i;
        if (b == e) y = i;
    }
    for (i = 0; i == x || i == y; i++);
    t = D_1A4BE0.f25F8;
    if (t != 0) {
        k = D_16C690_0039AE18.v[i];
        if (k != -1) {
            if (get_395C48(t) == D_160C40_0039AE18.e[k].id) {
                D_1A4BE0.f25F8 = 0;
            }
        }
    }
    func_0039AD90(id, i);
}
/* localdecomp:end func_0039AE18 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0039AFE0);

/* localdecomp:start func_0039AFE8 */
typedef struct { s32 id; s32 pad[4]; } E_395E18;
typedef struct { u8 pad[0x4590]; E_395E18 e[0x30]; } S_395E18;
typedef struct { u8 pad[0x34]; s32 v[3]; } T_395E18;
extern S_395E18 D_160C40[];
extern T_395E18 D_16C690[];
s32 func_0039AFE8(s32 id) {
    s32 i, j;
    for (i = 0; i < 0x30; i++) if (D_160C40[0].e[i].id == id) break;
    if (i == 0x30) return 1;
    for (j = 0; j < 3; j++) if (D_16C690[0].v[j] == i) break;
    return j != 3;
}
/* localdecomp:end func_0039AFE8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0039B078);

typedef struct { u8 *data; u8 *clut; u8 pad8[0xC]; s32 f14; u8 pad18[0x34]; s32 tw; s32 th; u8 pad54[4]; } T_395EB8;
typedef struct { u8 *data; s16 f4; s16 f6; u8 *clut; u8 tw; u8 th; s16 fE; } E_395EB8;
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern E_395EB8 D_00225C00[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_0039B088);

LINKER_REMNANT("asm/boot_elf/remnants", func_0039B1B0);

/* localdecomp:start func_0039B1B8 */
void func_0039B1B8(void) {
}
/* localdecomp:end func_0039B1B8 */
