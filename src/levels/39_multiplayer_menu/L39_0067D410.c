#include "common.h"

typedef struct { int a, b, c; } T;

/* declared by functions of L39_0067A788.c, which this file was cut from */
extern void func_L39_00595628(u8 *, u8 *);

/* localdecomp:start func_L39_0067D410 */
__asm__(".extern D_L39_00247A80, 16");
__asm__(".extern D_L39_00247A84, 16");
__asm__(".extern D_L39_00247A88, 16");
__asm__(".extern D_L39_00247A8C, 16");
extern f32 D_L39_00247A80;
extern f32 D_L39_00247A84;
extern f32 D_L39_00247A88;
extern f32 D_L39_00247A8C;
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_005169C8(s32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);

void func_L39_0067D410(f32 x, f32 y, f32 w, f32 h, f32 dy) {
    s32 color;
    f32 t;

    func_L01_00516AA0(0x450023, 1, 1);
    func_L01_00516AA0(0x450024, 1, 0);
    func_L01_00516AA0(0x450025, 1, 0);
    func_L01_00516470(0x450023, x, y);
    func_L01_00517538(0x450023, w, h);
    func_L01_00516470(0x450024, x + D_L39_00247A80, (y - dy) + D_L39_00247A84);
    func_L01_00516470(0x450025, x + D_L39_00247A80, (y + dy) + D_L39_00247A84);
    func_L01_00517538(0x450024, 0.5f, 0.5f);
    func_L01_00517538(0x450025, 0.5f, -0.5f);
    t = (w + D_L39_00247A8C) * D_L39_00247A88;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    func_L01_005169C8(0x450024, t);
    func_L01_005169C8(0x450025, t);
    color = func_0038DBD8(0x332299DE, 0x2299DE, 0.5f);
    func_L01_005170B8(0x450024, color);
    func_L01_005170B8(0x450023, 0x332299DE);
    func_L01_005170B8(0x450025, color);
    func_L01_00516C78(0x450023, 3, 3);
    func_L01_00516C78(0x450024, 3, 3);
    func_L01_00516C78(0x450025, 3, 3);
}
/* localdecomp:end func_L39_0067D410 */

/* localdecomp:start func_L39_0067D658 */
void func_L39_006121B0(s32);
void func_L39_00681470();

void func_L39_0067D658(void) {
    func_L39_006121B0(0);
    func_L39_006121B0(1);
    func_L39_00681470();
}
/* localdecomp:end func_L39_0067D658 */

/* localdecomp:start func_L39_0067D688 */
typedef struct { s32 f0; u8 pad[0x84]; s32 f88; } S_0067D688;
extern S_0067D688 *func_00137008(void *, s32);
extern s32 func_L01_00516FD8(s32, s32);
__asm__(".extern D_L39_0024D110, 16");
extern s32 D_L39_0024D110;
extern u8 D_L39_00370D00[];
extern f32 D_001DB1C8_sda;
__asm__(".extern D_L39_002468DC, 16");
extern f32 D_L39_002468DC;

void func_L39_0067D688(void) {
    S_0067D688 *p = func_00137008(D_L39_00370D00, D_L39_0024D110);

    func_L01_00516470(0x450010, D_001DB1C8_sda, D_L39_002468DC);
    func_L01_00516C78(0x450010, 3, 3);
    func_L01_005170B8(0x450010, 0x8066CCFF);
    if (p->f0 >= 0) {
        func_L01_00516FD8(0x450010, (s32)&p->f88);
        func_L01_00516AA0(0x450010, 1, 1);
    } else {
        func_L01_00516FD8(0x450010, 0);
        func_L01_00516AA0(0x450010, 1, 0);
    }
}
/* localdecomp:end func_L39_0067D688 */

INCLUDE_ASM("asm/levels", func_L39_0067D758);

/* localdecomp:start func_L39_0067EB98 */
void func_00137520();
s32 func_L39_0067CEA0();
extern s32 D_001A5DF0[];
extern s32 D_001DB168_sda;

s32 func_L39_0067EB98(void) {
    D_001DB168_sda = func_L39_0067CEA0();
    func_00137520();
    D_001A5DF0[0] = 2;
    return 0;
}
/* localdecomp:end func_L39_0067EB98 */

/* localdecomp:start func_L39_0067EBD0 */
int func_L39_0067EBD0(void) { int r = func_L39_0067CEA0(); int g = D_001DB168_sda; return g < 0 ? 3000 : r - g; }
/* localdecomp:end func_L39_0067EBD0 */

/* localdecomp:start func_L39_0067EC00 */
extern int func_00126150(void);
extern int func_001260F0(int arg0, int arg1);
extern void func_001915F0(void);
extern int D_001E1A60_sda;

/* from rac4-decomp's func_L00_00708228 */
void func_L39_0067EC00(void) {
    D_001E1A60_sda = func_001260F0(func_00126150(), 0x3C);
    func_001915F0();
}
/* localdecomp:end func_L39_0067EC00 */

/* localdecomp:start func_L39_0067EC30 */
typedef struct S_0067EC30 {
    u8 pad0[2];
    u16 count;
    u8 pad4[0xAC];
} S_0067EC30;

extern int D_001A5CD0[];
typedef struct S_0067EC30_D { int a; u8 pad[0x14]; } S_0067EC30_D;
__asm__(".extern D_L39_0024D158, 16");
extern int D_L39_0024D158;
extern int D_001E1A48_sda;
extern void *func_0011D534(void *, s32, s32);
extern int func_00191698(int, void *);
extern void func_00190EF0(int, int *);
extern int func_00191010(int, S_0067EC30 *);
extern void func_00191258(int, S_0067EC30 *, int *);
extern void func_00191878(int, void *);
extern int func_001917B8(int);

int func_L39_0067EC30(void) {
    u8 buf[0x20];
    u8 info[0x10];
    S_0067EC30 st;
    int n;

    func_0011D534(&D_L39_0024D158, 0, 0x18);
    if (D_001A5CD0[4] == -1) {
        if (func_00191698(0, info) == 0) {
            func_00190EF0(0, &D_001A5CD0[4]);
        }
    } else if (func_00191010(D_001A5CD0[4], &st) == 0) {
        if (st.count != 0) {
            func_00191258(D_001A5CD0[4], &st, &D_L39_0024D158);
            for (n = 0; n < st.count; n++) {
            }
            func_00191878(D_001A5CD0[4], buf);
        }
    } else {
        func_001917B8(D_001A5CD0[4]);
        D_001A5CD0[4] = -1;
        return D_L39_0024D158;
    }
    return D_001E1A48_sda;
}
/* localdecomp:end func_L39_0067EC30 */

/* localdecomp:start func_L39_0067ED40 */
extern int D_001A5CD0[];
__asm__(".extern D_L39_0024D170, 16");
extern int D_L39_0024D170;
extern int func_001917B8(int);
extern void func_00191640(void);
extern int func_00126150(void);
extern int func_001260F0(int, int);

void func_L39_0067ED40(void) {
    int *p = D_001A5CD0;
    func_001917B8(p[4]);
    p[4] = -1;
    func_00191640();
    func_001260F0(func_00126150(), D_L39_0024D170);
}
/* localdecomp:end func_L39_0067ED40 */

/* localdecomp:start func_L39_0067ED90 */
extern T D_L39_004AE080[];
extern void func_001377D0(int, int, int);
void func_L39_0067ED90(unsigned int i) {
    if (i < 6) func_001377D0(D_L39_004AE080[i].a, D_L39_004AE080[i].b, D_L39_004AE080[i].c);
}
/* localdecomp:end func_L39_0067ED90 */

LINKER_REMNANT("asm/levels", func_L39_0067EDD8);
