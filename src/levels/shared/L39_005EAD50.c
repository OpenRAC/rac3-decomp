#include "common.h"

/* localdecomp:start func_L39_005EAD50 */
typedef struct S_005EAD50 {
    u8 pad[0x5C0];
} S_005EAD50;

typedef struct A_005EAD50 {
    u8 pad0[0x14];
    s32 a14[3][4];
    s32 a44[3][4];
    s32 a74[3][4];
    u8 padA4[0xAE - 0xA4];
    u8 bAE[16];
} A_005EAD50;
extern s32 D_001D8584_sda;
extern A_005EAD50 D_001A5810;
extern s32 D_L39_0024C890[] __attribute__((section(".sdata")));
extern S_005EAD50 D_L39_00225780[];
extern s32 func_L01_00517688(void);
typedef struct { u8 pad[0x2534]; S_005EAD50 *m; } P_005EAD50;
extern P_005EAD50 *func_L39_0061BF38(s32);
typedef struct { s32 f0; s32 f4; s32 f8; } E_005EAD50;
extern E_005EAD50 D_L39_0049A498_005EAD50[][4];
void func_L39_005EAD50(void) {
    s32 n;
    s32 i;
    P_005EAD50 *q;

    D_001D8584_sda = 0;
    n = func_L01_00517688();
    q = func_L39_0061BF38(n);
    i = D_L39_0024C890[n];
    D_001D8584_sda = q->m - D_L39_00225780;
    D_L39_0049A498_005EAD50[1][n].f0 = D_001A5810.a14[i][n];
    D_L39_0049A498_005EAD50[2][n].f0 = D_001A5810.a44[i][n];
    if (D_001A5810.a74[i][n] < 0x32) {
        D_L39_0049A498_005EAD50[3][n].f0 = 0;
    } else if (D_001A5810.a74[i][n] < 0x58) {
        D_L39_0049A498_005EAD50[3][n].f0 = 1;
    } else {
        D_L39_0049A498_005EAD50[3][n].f0 = 2;
    }
    D_L39_0049A498_005EAD50[4][n].f0 = D_001A5810.bAE[D_001D8584_sda];
    D_L39_0049A498_005EAD50[5][n].f0 = D_001A5810.bAE[8];
}
/* localdecomp:end func_L39_005EAD50 */

/* localdecomp:start func_L39_005EAE70 */
typedef struct { u8 pad[0x2544]; s32 idx; } P_005EAE70;
extern s32 func_L01_00517688(void);
extern s32 D_L39_0024C880[] __attribute__((section(".sdata")));
extern s32 D_L39_0024C890[] __attribute__((section(".sdata")));
extern s32 D_L39_002410F8[] __attribute__((section(".sdata")));

void func_L39_005EAE70(void) {
    s32 i = func_L01_00517688();
    P_005EAE70 *p = (P_005EAE70 *)func_L39_0061BF38(i);
    s32 cur = D_L39_0024C890[i];
    s32 r;
    if (cur != D_L39_0024C880[i]) {
        r = 0;
        switch (cur) {
        case 2: r = 2; break;
        case 1: r = 1; break;
        case 0: r = 0; break;
        }
        D_L39_002410F8[p->idx] = r;
    }
}
/* localdecomp:end func_L39_005EAE70 */

/* localdecomp:start func_L39_005EAF10 */
extern s32 func_L01_00517688(void);
extern s32 func_L39_005EBDA0(void);
extern void func_L39_005EBAF0(s32);
extern void func_L39_005E9FA0(s32);
extern void func_L39_005F3548(s32, s32, s32);
extern void func_L39_0061C0E0(s32, s32);
extern void func_L39_005D6468(s32, s32);
extern void func_L01_00353C80(s32);
extern s32 func_L01_0049F168(s32);
extern void func_L01_00517748(s32);

void func_L39_005EAF10(s32 a0) {
    s32 a;
    s32 b;
    a = func_L01_00517688();
    b = func_L39_005EBDA0();
    func_L39_005EBAF0(b);
    if (b & 0xA040) {
        func_L39_005E9FA0(a0);
    } else if (b & 0x900) {
        func_L39_005F3548(4, 0, 0);
        func_L39_0061C0E0(func_L01_00517688(), 0);
        func_L39_005D6468(func_L01_00517688(), 0);
        func_L01_00353C80(a0);
    } else if (b & 0x910) {
        func_L39_005F3548(4, 0, 0);
        func_L01_00517748(func_L01_0049F168(a));
        func_L01_00353C80(a0);
    }
}
/* localdecomp:end func_L39_005EAF10 */

/* localdecomp:start func_L39_005EAFF0 */
extern s32 D_001D8588_sda;
extern s32 D_L39_0049A498_005EAFF0[][4][3];
extern s32 D_L39_002B6940[][3];
extern s32 D_L39_0024C890[] __attribute__((section(".sdata")));
extern char D_L39_00243D48[];
extern s32 func_L01_00517688(void);
extern u8 *func_003B9BD0(s32);
extern u8 *func_L39_005E7FF8(u8 *a0, s32 a1, s32 a2);
extern s32 func_00120048(void *, char *, ...);

void func_L39_005EAFF0(void) {
    s32 i;
    s32 mode;
    s32 m;
    m = 0;
    mode = func_L01_00517688();
    switch (mode) {
    case 0: m = 0; break;
    case 1: m = 1; break;
    case 2: m = 2; break;
    case 3: m = 3; break;
    }
    for (i = 0; i < D_001D8588_sda; i++) {
        if (i == 2 && D_L39_0024C890 == 0) {
            func_00120048(func_L39_005E7FF8(func_003B9BD0(m), 1, 2), D_L39_00243D48,
                          D_L39_002B6940[i][D_L39_0049A498_005EAFF0[i][mode][0] != 0 ? 0 : 1]);
        } else if (i != 3) {
            func_00120048(func_L39_005E7FF8(func_003B9BD0(m), 1, i), D_L39_00243D48,
                          D_L39_002B6940[i][D_L39_0049A498_005EAFF0[i][mode][0]]);
        }
    }
}
/* localdecomp:end func_L39_005EAFF0 */

/* localdecomp:start func_L39_005EB198 */
typedef struct { s32 f0; s32 f4; s32 f8; } S_005EB198;
extern S_005EB198 D_L39_0049A498[];
extern s32 D_L39_002B6988[][3];
extern s32 func_L01_00517688(void);
extern s32 func_L01_00516FD8(s32, s32);

void func_L39_005EB198(void) {
    s32 idx = func_L01_00517688();
    func_L01_00516FD8(0x54000A + 0, D_L39_002B6988[0][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 4, D_L39_002B6988[1][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 8, D_L39_002B6988[2][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 12, D_L39_002B6988[3][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 16, D_L39_002B6988[4][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 20, D_L39_002B6988[5][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 24, D_L39_002B6988[10][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 28, D_L39_002B6988[11][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 32, D_L39_002B6988[8][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 36, D_L39_002B6988[7][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 40, D_L39_002B6988[6][D_L39_0049A498[idx].f0]);
    func_L01_00516FD8(0x54000A + 44, D_L39_002B6988[9][D_L39_0049A498[idx].f0]);
}
/* localdecomp:end func_L39_005EB198 */

/* localdecomp:start func_L39_005EB330 */
extern s32 func_00381FF0(s32);
extern s32 func_00120048(void *, char *, ...);
extern s32 D_L39_002B6940[][3];
extern s32 D_L39_002B6988[][3];
extern char D_L39_00243D60[];
extern char D_001D85B0_sda[] __attribute__((section(".sdata")));
extern char D_001D85D0_sda[] __attribute__((section(".sdata")));
extern char D_001D85F0_sda[] __attribute__((section(".sdata")));
extern char D_001D85A8_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001D85B0_sda, 8");
__asm__(".extern D_001D85D0_sda, 8");
__asm__(".extern D_001D85F0_sda, 8");
__asm__(".extern D_001D85A8_sda, 8");

void func_L39_005EB330(void) {
    D_L39_002B6940[0][0] = func_00381FF0(0x1359);
    D_L39_002B6940[1][0] = func_00381FF0(0x192);
    D_L39_002B6940[2][0] = func_00381FF0(0x192);
    D_L39_002B6940[3][0] = func_00381FF0(0x23B);
    D_L39_002B6940[4][0] = func_00381FF0(0x176);
    D_L39_002B6940[5][0] = func_00381FF0(0x176);
    D_L39_002B6940[0][1] = func_00381FF0(0x1357);
    D_L39_002B6940[1][1] = func_00381FF0(0x193);
    D_L39_002B6940[2][1] = func_00381FF0(0x193);
    D_L39_002B6940[3][1] = func_00381FF0(0x23A);
    D_L39_002B6940[4][1] = func_00381FF0(0x175);
    D_L39_002B6940[5][1] = func_00381FF0(0x175);
    D_L39_002B6940[0][2] = func_00381FF0(0x1358);
    D_L39_002B6940[1][2] = func_00381FF0(0);
    D_L39_002B6940[2][2] = func_00381FF0(0);
    D_L39_002B6940[3][2] = func_00381FF0(0x239);
    D_L39_002B6940[4][2] = func_00381FF0(0);
    D_L39_002B6940[5][2] = func_00381FF0(0);
    func_00120048(D_001D85B0_sda, D_L39_00243D60, 0x16, func_00381FF0(0x1826));
    func_00120048(D_001D85D0_sda, D_L39_00243D60, 0x17, func_00381FF0(0x181D));
    D_L39_002B6988[0][0] = func_00381FF0(0x180D);
    D_L39_002B6988[1][0] = func_00381FF0(0x180A);
    D_L39_002B6988[2][0] = (s32)D_001D85F0_sda;
    D_L39_002B6988[3][0] = func_00381FF0(0x180B);
    D_L39_002B6988[4][0] = func_00381FF0(0x1809);
    D_L39_002B6988[5][0] = func_00381FF0(0x181C);
    D_L39_002B6988[6][0] = func_00381FF0(0x180E);
    D_L39_002B6988[7][0] = func_00381FF0(0x194B);
    D_L39_002B6988[8][0] = func_00381FF0(0x1810);
    D_L39_002B6988[9][0] = func_00381FF0(0x1811);
    D_L39_002B6988[10][0] = func_00381FF0(0x180C);
    D_L39_002B6988[11][0] = func_00381FF0(0x8E6);
    D_L39_002B6988[0][1] = func_00381FF0(0x1816);
    D_L39_002B6988[1][1] = func_00381FF0(0x194B);
    D_L39_002B6988[2][1] = (s32)D_001D85A8_sda;
    D_L39_002B6988[3][1] = func_00381FF0(0x1813);
    D_L39_002B6988[4][1] = func_00381FF0(0x181E);
    D_L39_002B6988[5][1] = func_00381FF0(0x181C);
    D_L39_002B6988[6][1] = func_00381FF0(0x1816);
    D_L39_002B6988[7][1] = func_00381FF0(0x194B);
    D_L39_002B6988[8][1] = func_00381FF0(0x1818);
    D_L39_002B6988[9][1] = func_00381FF0(0x1819);
    D_L39_002B6988[10][1] = func_00381FF0(0x1815);
    D_L39_002B6988[11][1] = func_00381FF0(0x8E6);
    D_L39_002B6988[0][2] = func_00381FF0(0x1820);
    D_L39_002B6988[1][2] = func_00381FF0(0x194B);
    D_L39_002B6988[2][2] = (s32)D_001D85B0_sda;
    D_L39_002B6988[3][2] = (s32)D_001D85D0_sda;
    D_L39_002B6988[4][2] = func_00381FF0(0x181E);
    D_L39_002B6988[5][2] = func_00381FF0(0x1825);
    D_L39_002B6988[6][2] = func_00381FF0(0x1820);
    D_L39_002B6988[7][2] = func_00381FF0(0x194B);
    D_L39_002B6988[8][2] = func_00381FF0(0x1822);
    D_L39_002B6988[9][2] = func_00381FF0(0x1823);
    D_L39_002B6988[10][2] = func_00381FF0(0x181F);
    D_L39_002B6988[11][2] = func_00381FF0(0x8E6);
}
/* localdecomp:end func_L39_005EB330 */
