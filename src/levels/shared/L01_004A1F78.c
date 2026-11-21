#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

/* declared by functions of L01_004A1910.c, which this file was cut from */
extern E_49E5B8 D_L01_002ED850[];
extern s32 *func_003B9BD0(s32);
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L01_004A1F78 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_004A1F78;
extern E_49E5B8 D_L01_002ED850[];
extern char D_L01_001D96B8[];
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C68();
extern void func_003BABB0(void *, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_L01_00498948(void *, s32, s32);
extern s32 func_003B9E30(void *, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_11B2E8();

void func_L01_004A1F78(void) {
    S_004A1F78 s;
    s32 n;
    s32 i;

    for (n = 0; D_L01_002ED850[n].x0 > 0; n++);
    s.f0 = func_L01_0047DAE0();
    s.f4 = func_003BB118(0);
    s.f8 = 0x14;
    s.fC = n;
    s.f10 = n < 6 ? n : 5;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.f20 = 0.09534f;
    s.f1C = 0.722955f;
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
    func_003B9C68(func_003B9BD0(0), &s);
    func_003BABB0(func_003B9BD0(0), 0.5f, 0.816536f, 0.045f, 0.0425f, 0.35f, 0);
    func_003BABD0(func_003B9BD0(0), 0.500369f, 0.764263f, 0.816536f, 0.165586f);
    func_003BA4E0(func_003B9BD0(0), 1, 0.04767f, 0.00666f, 0.03f);
    for (i = 0; i < n; i++) {
        if (D_L01_002ED850[i].x14) {
            func_L01_00498948(func_003B9BD0(0), i, 0);
            func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D96B8, func_00381FF0(D_L01_002ED850[i].x0));
        } else {
            func_L01_00498948(func_003B9BD0(0), i, 1);
            func_11B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D96B8, func_00381FF0(0x1C8));
        }
    }
}
/* localdecomp:end func_L01_004A1F78 */
