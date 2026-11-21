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
extern void func_L01_004A23F8();

/* localdecomp:start func_L01_004A23F8 */
typedef struct {
    char *text;
    s32 id;
    s32 voice;
    s16 fC;
    s16 fE;
} HelpRow_004A23F8;
extern s32 D_L01_001E0D20;
__asm__(".extern D_L01_001E0D20, 4");
extern s32 D_L01_001E0D1C;
__asm__(".extern D_L01_001E0D1C, 4");
extern s32 D_L01_001D96C4;
__asm__(".extern D_L01_001D96C4, 4");
extern s32 D_L01_001D9704;
__asm__(".extern D_L01_001D9704, 4");
extern s32 D_L01_001D9708;
__asm__(".extern D_L01_001D9708, 4");
extern s32 D_L01_001D970C;
__asm__(".extern D_L01_001D970C, 4");
extern u16 D_001A8EC8[];
extern HelpRow_004A23F8 *D_L01_001DFCC0;
extern void func_L01_0047E520(void);
extern s32 func_00381F80(s32);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);

void func_L01_004A23F8() {
    if (D_L01_001E0D20 == 0) {
        D_L01_001E0D20 = 1;
        D_L01_001E0D1C = (f32)D_L01_001D970C * 1.1071428f;
    }
    func_L01_0047E520();
    switch (D_L01_001DFCC0[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE) {
    case 0x1DC:
        func_0038B4D0(D_L01_001D9704, D_L01_001D9708, D_L01_001D970C, D_L01_001E0D1C, 0, 0, 0x40, 0x40, 0x80808080, func_00389598(0x5C));
        break;
    case 0xB0E:
        func_0038B4D0(D_L01_001D9704, D_L01_001D9708, D_L01_001D970C, D_L01_001E0D1C, 0, 0, 0x40, 0x40, 0x80808080, func_00389598(0x61));
        break;
    case 0x150E:
        func_0038B4D0(D_L01_001D9704, D_L01_001D9708, D_L01_001D970C, D_L01_001E0D1C, 0, 0, 0x40, 0x40, 0x80808080, func_00389598(0x5D));
        break;
    case 0x166A:
        func_0038B4D0(D_L01_001D9704, D_L01_001D9708, D_L01_001D970C, D_L01_001E0D1C, 0, 0, 0x40, 0x40, 0x80808080, func_00389598(0x62));
        break;
    case 0x1736:
        func_0038B4D0(D_L01_001D9704, D_L01_001D9708, D_L01_001D970C, D_L01_001E0D1C, 0, 0, 0x40, 0x40, 0x80808080, func_00389598(0x5E));
        break;
    }
}
/* localdecomp:end func_L01_004A23F8 */
