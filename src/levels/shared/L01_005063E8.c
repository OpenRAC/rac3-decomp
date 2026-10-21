#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_005063E8);

/* localdecomp:start func_L01_00506820 */
extern u8 D_001A4BE0[];
extern void func_003C2880(s32);
void func_L01_00506820(void) {
    u8 *p = D_001A4BE0;
    u8 *q;
    if (*(s32 *)(p + 6660) != 0) {
        func_003C2880(*(s32 *)(p + 6660));
        *(s32 *)(p + 6660) = 0;
    }
    q = *(u8 **)(p + 4848);
    if (q != 0) {
        *(u16 *)(q + 52) &= 0xffbe;
    }
    q = *(u8 **)(p + 4852);
    if (q != 0) {
        *(u16 *)(q + 52) &= 0xffbe;
    }
}
/* localdecomp:end func_L01_00506820 */

INCLUDE_ASM("asm/levels", func_L01_00506888);

INCLUDE_ASM("asm/levels", func_L01_00506BB0);

INCLUDE_ASM("asm/levels", func_L01_00506E30);

INCLUDE_ASM("asm/levels", func_L01_005070E0);

INCLUDE_ASM("asm/levels", func_L01_00507268);

INCLUDE_ASM("asm/levels", func_L01_00507380);

LINKER_REMNANT("asm/levels", func_L01_005075D0);

INCLUDE_ASM("asm/levels", func_L01_005075D8);

/* localdecomp:start func_L01_005076D8 */
typedef struct {
    u8 pad0[0x10];
    s32 arr[1];
} S_503760;

extern S_503760 D_00142660;

void func_L01_005076D8(s32 n) {
    s32 first = D_00142660.arr[0];
    s32 last = 0;
    s32 i;
    for (i = 1; i < n; i++) {
        if (D_00142660.arr[i] != 0) {
            D_00142660.arr[i - 1] = D_00142660.arr[i];
            last = i;
        }
    }
    D_00142660.arr[last] = first;
}
/* localdecomp:end func_L01_005076D8 */

INCLUDE_ASM("asm/levels", func_L01_00507738);

/* localdecomp:start func_L01_005078C0 */
extern S_503760 D_00142660;
typedef struct {
    u8 p0[0x10];
    s32 x10[8];
} L_503930;
typedef struct {
    u8 x0;
    u8 p1[0x89];
    u16 x8A;
    u8 p8C[0x64];
} T_503930;
extern s32 func_L01_00418F70(s32);
extern u8 D_001425C0[];
extern T_503930 D_L01_002C5600[];
extern s32 D_001427F0[];

void func_L01_005078C0(s32 id) {
    s32 pos;
    s32 i;
    if (id == 9 || id == 30 || id == 22 || id == 35) return;
    if (D_L01_002C5600[D_001425C0[id]].x0 == 0 && !func_L01_00418F70(id)) return;
    pos = -1;
    for (i = 0; i < 8; i++) {
        if ((*(L_503930 *)&D_00142660).x10[i] == id) {
            pos = i;
            break;
        }
    }
    if (pos == 0) return;
    if (pos >= 3 || pos == -1) {
        s32 found = -1;
        s32 j;
        for (j = 2; j >= 0; j--) {
            s32 n = (*(L_503930 *)&D_00142660).x10[j];
            if (n != 0 && D_001427F0[n] == 0 && (D_L01_002C5600 + D_001425C0[n])->x8A != 0) {
                found = j;
                break;
            }
        }
        if (found != -1) {
            for (j = found; j < 7; j++) {
                (*(L_503930 *)&D_00142660).x10[j] = (*(L_503930 *)&D_00142660).x10[j + 1];
                if (pos == j + 1) pos--;
            }
            (*(L_503930 *)&D_00142660).x10[7] = 0;
        }
    }
    if (pos != -1) {
        for (i = pos; i < 7; i++) {
            (*(L_503930 *)&D_00142660).x10[i] = (*(L_503930 *)&D_00142660).x10[i + 1];
        }
        (*(L_503930 *)&D_00142660).x10[7] = 0;
    }
    {
        s32 k;
        for (k = 7; k > 0; k--) {
            (*(L_503930 *)&D_00142660).x10[k] = (*(L_503930 *)&D_00142660).x10[k - 1];
        }
    }
    (*(L_503930 *)&D_00142660).x10[0] = id;
}
/* localdecomp:end func_L01_005078C0 */
