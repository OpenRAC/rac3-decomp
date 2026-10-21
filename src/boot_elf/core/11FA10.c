#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0011FA10 */
typedef struct {
    u8 type;
    u8 id;
} Ent_11FA10;

typedef struct {
    s32 x0;
    s32 x4;
    Ent_11FA10 ent[0x200];
} Q_11FA10;

extern s32 D_152800;
extern char D_00150788[];
extern s32 func_0011EE60_0011FA10(s32);
extern void func_0011ED50(s32);
extern void func_0011ECD0(s32);
extern void func_0011ED90(s32);
extern void func_001217E0(const char *, ...);

void func_0011FA10(Q_11FA10 *q) {
    s32 i;

    while (1) {
        func_0011EE60_0011FA10(D_152800);
        i = q->x0 & 0x1FF;
        q->x0 = i + 1;
        switch (q->ent[i].type) {
        case 0:
            func_0011ED50(q->ent[i].id);
            break;
        case 1:
            func_0011ECD0(q->ent[i].id);
            break;
        case 2:
            func_0011ED90(q->ent[i].id);
            break;
        default:
            func_001217E0(D_00150788);
            break;
        }
    }
}
/* localdecomp:end func_0011FA10 */

/* localdecomp:start func_0011FAE8 */
typedef struct {
    int status;
    void *entry;
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    u32 attr;
    u32 option;
    u8 pad24[0x30 - 0x24];
} ThreadParam_11FAE8;
typedef struct {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
} SemaParam_11FAE8;
extern int D_0013DBF0;
extern int D_152800;
extern int D_152808[];
extern u8 D_152400[];
extern u8 D_1DC8B0[];
extern char D_001507B0[];
extern int func_0011EE20();
extern int func_0011EE30();
extern int func_0011EC20();
extern int func_0011FD40();
extern int func_0011ED10();
extern int func_0011ECB0();
extern void func_0011FA10();

int func_0011FAE8(void)
{
    ThreadParam_11FAE8 tp;
    SemaParam_11FAE8 sp;

    if (D_0013DBF0 > 0) {
        return -1;
    }
    sp.max_count = 0xFF;
    sp.init_count = 0;
    sp.option = (u32)D_001507B0;
    D_152800 = func_0011EE20(&sp);
    if (D_152800 < 0) {
        return -1;
    }
    tp.entry = func_0011FA10;
    tp.stack = D_152400;
    tp.stackSize = 0x400;
    tp.gpReg = D_1DC8B0;
    tp.initPriority = 0;
    tp.option = (u32)D_001507B0;
    D_0013DBF0 = func_0011EC20(&tp);
    if (D_0013DBF0 < 0) {
        func_0011EE30(D_152800);
        return -1;
    }
    D_152808[0] = 0;
    D_152808[1] = 0;
    func_0011FD40(D_0013DBF0, D_152808);
    func_0011ECB0(func_0011ED10(), 1);
    return D_0013DBF0;
}
/* localdecomp:end func_0011FAE8 */
