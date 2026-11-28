#include "common.h"

/* declared by functions of L39_005E6B08.c, which this file was cut from */
typedef struct { s32 f0; u8 f4; u8 pad5[3]; void (*f8)(void); s32 fC; } S_005E6B08;
extern S_005E6B08 D_001D8478_sda[] __attribute__((section(".sdata")));
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);

/* localdecomp:start func_L39_005E6D80 */
typedef struct {
    s32 f0;
    void *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 a24[4];
    f32 a34[4];
    f32 a44[4];
} S_005E6D80;

__asm__(".extern D_001D8478_sda, 4");
__asm__(".extern D_001D846C_sda, 4");
__asm__(".extern D_001D8468_sda, 4");
__asm__(".extern D_001D84BC_sda, 4");
__asm__(".extern D_001D84C0_sda, 4");
extern s32 D_001D846C_sda;
extern s32 D_001D8468_sda;
extern f32 D_001D84BC_sda;
extern f32 D_001D84C0_sda;
extern s32 *D_L39_00241120;
extern char D_L39_00243BD8[];

void func_L39_005E6D80(void) {
    extern void *func_L39_005E3A40(s32);
    extern s32 func_L39_005E7E30(void *, void *);
    extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
    extern void func_003BABD0(void *, f32, f32, f32, f32);
    extern void func_003BA4E0(void *, s32, f32, f32, f32);
    extern void func_L01_00498F18(void *, s32, s32);
    extern char *func_L39_005E7FF8(void *, s32, s32);
    extern s32 func_00381FF0(s32);
    extern s32 func_00120048(char *, char *, ...);
    extern void func_L39_005E8058(void *, s32, s32);
    extern void func_L39_005E8F98(void *, s32, s32, f32, f32);
    S_005E6D80 s;
    s32 idx = 0;
    s32 count = 0;
    s32 row = 0;
    s32 mode;
    s32 i;
    s32 on;
    f32 a;
    f32 c;
    f32 r;
    f32 b;
    char *buf;

    switch (func_L01_00517688()) {
    case 0:
        idx = 0;
        break;
    case 1:
        idx = 1;
        break;
    case 2:
        idx = 2;
        break;
    case 3:
        idx = 3;
        break;
    }
    D_001D8468_sda = -1;
    D_001D846C_sda = -1;
    while (D_001D8478_sda[count].f0 > 0) {
        switch (D_001D8478_sda[count].f0) {
        case 0x18E:
            D_001D8468_sda = count;
            break;
        case 0x148:
            D_001D846C_sda = count;
            break;
        }
        count++;
    }
    mode = func_L01_00517688();
    a = 0.500369f;
    c = 0.499706f;
    r = 0.814818f;
    b = 0.709469f;
    if (*D_L39_00241120 >= 3) {
        c = 0.0f;
        r = 0.804818f;
        b = 10.0f;
        switch (mode) {
        case 0:
        case 2:
            a = 0.5f;
            break;
        case 1:
        case 3:
            a = 1.5f;
            break;
        }
    } else if (*D_L39_00241120 >= 2) {
        c = 0.0f;
        r = 0.804818f;
        b = 10.0f;
        switch (mode) {
        case 0:
            a = 0.5f;
            break;
        case 1:
            a = 1.0f;
            break;
        }
    }
    D_001D84C0_sda = 0.139494f;
    s.f0 = 0x200;
    D_001D84BC_sda = 0.5f - (f32)(count - 1) * D_001D84C0_sda * 0.5f;
    s.f4 = func_L39_005E3A40(mode);
    s.f10 = count > 6 ? 6 : count;
    s.f1C = D_001D84BC_sda;
    s.f20 = D_001D84C0_sda;
    s.f8 = 0x14;
    s.fC = count;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.a24[0] = 0.5f;
    s.a24[1] = 1.0f;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = 0.795206f;
    s.a34[1] = 0.0f;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_L39_005E7E30((void *)func_003B9BD0(idx), &s);
    func_003BABB0((void *)func_003B9BD0(idx), a, r, 0.045f, 0.0425f, 0.35f, 0);
    func_003BABD0((void *)func_003B9BD0(idx), a, c, r, b);
    func_003BA4E0((void *)func_003B9BD0(idx), 1, 0.033f, 0.00666f, 0.03f);
    func_L01_00498F18((void *)func_003B9BD0(idx), 0, 1);
    for (i = 0; i < count; i++) {
        buf = func_L39_005E7FF8((void *)func_003B9BD0(idx), 0, row);
        func_00120048(buf, D_L39_00243BD8, func_00381FF0(D_001D8478_sda[i].f0));
        on = D_001D8478_sda[i].f4 == 0;
        func_L39_005E8058((void *)func_003B9BD0(0), i, on);
        if (*D_L39_00241120 >= 2) {
            func_L39_005E8F98((void *)func_003B9BD0(idx), 0, row + 1, 1.0f, 2.0f);
        }
        func_003BABB0((void *)func_003B9BD0(idx), 0.5f, r, 0.09f, 0.0425f, 0.35f, 0);
        row++;
    }
}
/* localdecomp:end func_L39_005E6D80 */
