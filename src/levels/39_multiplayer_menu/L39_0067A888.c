#include "common.h"

typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_0067A888 */
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_0067A888;
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad4958[0x6A30 - 0x4958];
    s32 f6A30;
    s32 f6A34;
} G_0067A888;
typedef struct {
    u8 pad[0x50];
    s32 f50;
} O_0067A888;

extern s32 D_L39_00245D00;
extern u8 D_L39_00247A34;
extern S_0067A888 D_L39_0024CD50;
extern G_0067A888 D_L39_001F0A00;
extern u8 D_L39_003533A0[];
extern u8 D_L39_003573A0[];
extern s32 D_001E19B0_sda;
extern s32 D_001E19E4_sda;
extern void func_L39_005C2960(void);
extern void func_L39_005C1E10(void);
extern int func_00126150(void);
extern int func_001260F0(int arg0, int arg1);
extern void func_L39_006813F8(void);
extern s32 func_00381FF0(s32);
extern void func_L39_0067BE08(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_005170B8(s32, s32);
extern void func_003EA778(s32);
extern s32 func_003E8630(s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 func_003A26F0(void *, s32, s32);
extern s32 func_003B43B0(s32);
extern void func_L39_005DBEE8(s32, s32, s32);
extern void func_L01_00517190(s32, s32);
extern s32 func_L01_003EC898_0067A888(s32);

void func_L39_0067A888(void) {
    s32 *base;
    O_0067A888 *p;
    O_0067A888 *obj;
    G_0067A888 *g;
    s32 id;
    s32 h;

    func_L39_005C2960();
    func_L39_005C1E10();
    h = func_00126150();
    D_001E19B0_sda = 0;
    D_001E19E4_sda = func_001260F0(h, 0x60);
    func_L01_003EC898_0067A888(h);
    func_L39_006813F8();
    func_L39_0067BE08(1, 0x460001, 0x460002, 0x460003, 0x460000, 0x460009, 0x46000A, 0x46000B, 9.0f,
                      0x46000C, 0x46000D, 0x46000E, func_00381FF0(0x1000), 0x46000F, 0x125D, 0x460010, 0x177);
    func_L01_005170B8(0x460003, 0x80000000);
    id = 0x460004;
    do {
        func_003EA778(id);
        func_003E8630(0x460000, id);
        func_L01_00516AA0(id, 1, 0);
        func_L01_00516C78(id, 3, 3);
        func_L01_005170B8(id, 0x8066CCFF);
        id++;
    } while (id < 0x460008);
    func_003E9138(0x460008, 0xAFAFAFAF, 0.5f, 0.4655f, 0.4f, 0.4f, 0);
    if (D_L39_0024CD50.f4 != 0) {
        base = (s32 *)&D_L39_0024CD50;
    } else {
        base = (s32 *)func_003E6C08(&D_L39_0024CD50);
    }
    obj = (O_0067A888 *)func_003E6378(func_003E6DE8(base), 0x460008);
    if (obj != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)obj + 8)) + 0x10))(obj, D_L39_00245D00) != 0) {
        p = obj;
    } else {
        p = 0;
    }
    g = &D_L39_001F0A00;
    if (g->f6A34 != 0) {
        func_003A26F0(D_L39_003533A0, g->f6A30 + g->f4954, g->f6A34);
        func_L39_005DBEE8(func_003B43B0(1), (s32)D_L39_003533A0, (s32)D_L39_003573A0);
    } else {
        func_L39_005DBEE8(func_003B43B0(1), 0, 0);
    }
    p->f50 = func_003B43B0(1);
    func_L01_00517190(0x460008, 1);
    func_003E8630(0x460000, 0x460008);
    D_L39_00247A34 = 0;
}
/* localdecomp:end func_L39_0067A888 */
