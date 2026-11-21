#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x5628 - 0x4958];
    u8 fX[1];
} S_func_00496AB0;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} E_496DC0;
typedef struct {
    s32 id;
    s32 pad[3];
} Ent_497BC8;
typedef struct { s32 a; s32 b; s32 c; s32 d; } Ent_00497C30;

/* declared by functions of L01_00499C80.c, which this file was cut from */
extern void *func_003B42F8(s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern void func_L01_0049B5A8();

/* localdecomp:start func_L01_0049B5A8 */
typedef struct { s32 f0; s32 p4; s32 f8; s32 pC; s32 p10; u8 flag; u8 pad[3]; } E_0049B5A8;
extern E_0049B5A8 D_L01_002EBED8[];
extern u8 D_L01_002EBF38[];
extern s32 D_L01_001D940C;
__asm__(".extern D_L01_001D940C, 4");
extern s32 D_L01_001D9408;
__asm__(".extern D_L01_001D9408, 4");
extern s32 D_L01_001D9404;
__asm__(".extern D_L01_001D9404, 4");
extern void func_L01_0049C0C8(void);
extern void func_0038E150(s32);
extern void func_L01_00499B20(s32, f32 *, f32 *);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_00516818(s32, f32);
extern void func_L01_0049B8F8(void *);
extern void func_003E8348(s32, s32);
extern s32 func_003E7F20(s32, s32);
extern void func_003E8710(s32, void *);
extern void func_003E87B8(s32, s32, s32);
extern void func_L01_0049BBD8(void);
extern void func_L01_0049C338(void);
extern void func_L01_0049C1D8(void);

void func_L01_0049B5A8(void) {
    f32 a;
    f32 b;
    s32 i;
    s32 n;
    E_0049B5A8 *p;

    i = 0;
    b = 0.0f;
    a = 1.2f;
    func_L01_0049C0C8();
    func_0038E150(0);
    func_L01_00499B20(0x1C2, &a, &b);
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_00381FF0(0x1C2), 0xD0006, 0x124, 0xD0007, 0xCD5, b);
    func_L01_00516818(0xD0005, a);
    func_L01_0049B8F8(D_L01_002EBF38);
    func_003E8348(0x11, 0x4E0000);
    func_003E7F20(0x4E0005, 1);
    func_003E7F20(0x4E0006, 1);
    func_003E8710(0x4E0009, func_003B42F8(0));
    func_L01_00517190(0x4E0009, 0);
    func_L01_00516D60(0x4E0009, 0);
    func_003E87B8(0x4E0009, 1, 8);
    func_L01_0049BBD8();
    func_L01_0049C338();
    D_L01_001D940C = -1;
    if (D_L01_002EBED8[0].f0 != 0) {
        n = -1;
        do {
            if (D_L01_002EBED8[i].flag) n = i;
            i++;
        } while (D_L01_002EBED8[i].f0 != 0 && n < 0);
        D_L01_001D940C = n;
    }
    if (D_L01_001D940C < 0) {
        if (D_L01_001D9408 != 0) D_L01_001D940C = 0;
    }
    if (D_L01_001D940C >= 0) {
        func_L01_00517190(0x4E0009, D_L01_002EBED8[D_L01_001D940C].f8 + 1);
        func_L01_00516D60(0x4E0009, 1);
    }
    func_L01_00516D60(0x4E0009, 0);
    D_L01_001D9404 = -1;
    func_L01_0049C1D8();
}
/* localdecomp:end func_L01_0049B5A8 */
