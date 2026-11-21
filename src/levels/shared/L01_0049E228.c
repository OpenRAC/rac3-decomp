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

/* localdecomp:start func_L01_0049E228 */
extern s32 D_L01_001D94C4;
extern s32 D_L01_001D94C8;
__asm__(".extern D_L01_001D94C4, 4");
__asm__(".extern D_L01_001D94C8, 4");
extern E_49E5B8 D_L01_002EC758[];
extern u8 *D_001D52FC;
extern void func_L01_0049E000(void *);
extern void *func_L01_0049B550(void);
extern void func_L01_00517748(void *);
extern void func_L01_00516090_0049E228(void *);

void func_L01_0049E228(void *a0) {
    s32 cont = 1;
    s32 old = D_L01_001D94C8;

    if (old >= 0) {
        if (*(unsigned long *)(D_001D52FC + 0x1C0) & 0x800400000000UL) {
            do {
                D_L01_001D94C8--;
                if (D_L01_001D94C8 < 0) {
                    D_L01_001D94C8 = old;
                    cont = 0;
                } else if (D_L01_002EC758[D_L01_001D94C8].x14 != 0 || D_L01_001D94C4 != 0) {
                    cont = 0;
                }
            } while (cont);
        } else if (*(unsigned long *)(D_001D52FC + 0x1C0) & 0x200800000000UL) {
            do {
                D_L01_001D94C8++;
                if (D_L01_002EC758[D_L01_001D94C8].x0 == 0) {
                    D_L01_001D94C8 = old;
                    cont = 0;
                } else if (D_L01_002EC758[D_L01_001D94C8].x14 != 0 || D_L01_001D94C4 != 0) {
                    cont = 0;
                }
            } while (cont);
        } else if (*(s32 *)(D_001D52FC + 0x1C4) & 0x40) {
            func_L01_0049E000(a0);
        }
    }
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x910) {
        func_L01_00517748(func_L01_0049B550());
        func_L01_00516090_0049E228(a0);
    }
}
/* localdecomp:end func_L01_0049E228 */
