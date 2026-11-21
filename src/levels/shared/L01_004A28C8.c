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

/* localdecomp:start func_L01_004A28C8 */
typedef struct {
    u8 pad0[0xE];
    s16 fE;
} Row_004A28C8;
extern s32 D_L01_001D96C0;
__asm__(".extern D_L01_001D96C0, 4");
extern s32 D_L01_001D96C4;
__asm__(".extern D_L01_001D96C4, 4");
extern s32 D_L01_001D96C8;
__asm__(".extern D_L01_001D96C8, 4");
extern char D_L01_001D96D8[4];
__asm__(".extern D_L01_001D96D8, 4");
extern char D_L01_001D9710[8];
__asm__(".extern D_L01_001D9710, 8");
extern s32 D_L01_001E0D28;
__asm__(".extern D_L01_001E0D28, 4");
extern f32 D_L01_001E0D24;
__asm__(".extern D_L01_001E0D24, 4");
extern f32 D_L01_001DC0E8;
extern u16 D_001A8EC8[];
extern Row_004A28C8 *D_L01_001DFCC0;
extern void func_0038E150(s32);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_00381F80(s32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516FD8(s32, s32);

void func_L01_004A28C8(void) {
    s32 t;
    s32 d0;
    s32 d1;
    s32 d2;

    func_0038E150(1);
    if (D_L01_001D96C0 != 0) {
        t = D_L01_001D96C0 - func_003B9C58(func_003B9BD0(0));
        D_L01_001D96C4 = t - 1;
        d0 = t % 10;
        d1 = t / 10 % 10;
        d2 = t / 100 % 10;
        if (d2 != 0) {
            D_L01_001D96D8[0] = d2 + '0';
            D_L01_001D96D8[1] = d1 + '0';
            D_L01_001D96D8[2] = d0 + '0';
            D_L01_001D96D8[3] = 0;
        } else if (d1 != 0) {
            D_L01_001D96D8[2] = 0;
            D_L01_001D96D8[0] = d1 + '0';
            D_L01_001D96D8[1] = d0 + '0';
        } else {
            D_L01_001D96D8[1] = 0;
            D_L01_001D96D8[0] = d0 + '0';
        }
        if (D_L01_001D96C4 >= 0) {
            if (D_L01_001D96C8 != D_L01_001D96C4) {
                if (D_L01_001E0D28 == 0) {
                    D_L01_001E0D28 = 1;
                    D_L01_001E0D24 = 65.0f / D_L01_001DC0E8;
                }
                if (D_L01_001DFCC0[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0x1DC
                    || D_L01_001DFCC0[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0xB0E
                    || D_L01_001DFCC0[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0x150E
                    || D_L01_001DFCC0[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0x166A
                    || D_L01_001DFCC0[func_00381F80(D_001A8EC8[D_L01_001D96C4])].fE == 0x1736) {
                    func_L01_00516470(0x580003, D_L01_001E0D24 * 0.5f + 0.500369f, 0.337772f);
                    func_L01_00517538(0x580003, 0.775758f - D_L01_001E0D24, 0.356964f);
                } else {
                    func_L01_00516470(0x580003, 0.500369f, 0.337772f);
                    func_L01_00517538(0x580003, 0.775758f, 0.356964f);
                }
                func_L01_00516FD8(0x580003, func_00381FF0(D_001A8EC8[D_L01_001D96C4]));
            }
            D_L01_001D96C8 = D_L01_001D96C4;
        }
    } else {
        D_L01_001D96D8[0] = 0;
        func_L01_00516FD8(0x580003, (s32)D_L01_001D9710);
    }
}
/* localdecomp:end func_L01_004A28C8 */

INCLUDE_ASM("asm/levels", func_L01_004A2BE0);

INCLUDE_ASM("asm/levels", func_L01_004A2E88);

INCLUDE_ASM("asm/levels", func_L01_004A2FC0);
