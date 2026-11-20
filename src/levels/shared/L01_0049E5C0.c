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

/* declared by functions of L01_0049E000.c, which this file was cut from */
extern s32 D_L01_001D94C8;
extern Ent_0049AB20 D_L01_002EC758[];
extern void func_L01_00517190(s32, s32);

/* localdecomp:start func_L01_0049E5C0 */
extern Ent_0049AB20 D_L01_002EC758[];

extern s32 D_L01_001D94C8;
extern s32 D_L01_001D94C4;
extern s32 D_L01_001D94D4;
extern void func_L01_00517190(s32, s32);

void func_L01_0049E5C0(void) {
    S_2EC7A8 *p;
    s32 cont;

    p = &((S_2EC7A8 *)&D_L01_002EC758)[D_L01_001D94C8];
    cont = 1;
    do {
        p++;
        if (p->f0 == 0) {
            cont = 0;
        } else if (p->f14 != 0 || D_L01_001D94C4 != 0) {
            cont = 0;
            func_L01_00517190(D_L01_001D94D4, p->f8 + 1);
        }
    } while (cont);
}
/* localdecomp:end func_L01_0049E5C0 */

/* localdecomp:start func_L01_0049E648 */
extern s32 D_L01_001D94C4;
extern s32 D_L01_001D94C8;
extern s32 D_L01_001D94D0;
extern void func_L01_00517190(s32, s32);

extern S_2EC760_0049E648 D_L01_002EC760[];

void func_L01_0049E648(void) {
    s32 cont = 1;
    s32 i = D_L01_001D94C8;
    s32 off = i * 24;

    off -= 24;

    do {
        i--;
        if (i < 0) {
            cont = 0;
        } else {
            if (((S_2EC7A8 *)((u8 *)&D_L01_002EC760 + off - 8))->f14 != 0 || D_L01_001D94C4 != 0) {
                cont = 0;
                func_L01_00517190(D_L01_001D94D0, ((S_2EC760_0049E648 *)((u8 *)&D_L01_002EC760 + off))->f0 + 1);
            }
        }
        off -= 24;
    } while (cont);
}
/* localdecomp:end func_L01_0049E648 */

LINKER_REMNANT("asm/levels", func_L01_0049E6F0);
