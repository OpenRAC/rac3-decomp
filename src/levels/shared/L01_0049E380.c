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

/* localdecomp:start func_L01_0049E380 */

extern s32 D_L01_001D94C8;
extern s32 D_L01_001D94CC;
extern Ent_0049AB20 D_L01_002EC758[];
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516D60(s32, s32);

void func_L01_0049E380(void)
{
    if (D_L01_001D94C8 >= 0) {
        func_L01_00516FD8(0x500008, func_00381FF0(D_L01_002EC758[D_L01_001D94C8].f4));
        func_L01_00517190(0x500003, D_L01_002EC758[D_L01_001D94C8].f8 + 1);
        func_L01_00516D60(D_L01_001D94CC, 1);
    }
}
/* localdecomp:end func_L01_0049E380 */
