#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern int func_0011FD40();
/* --- end of declarations from other files --- */

/* declarations of 11FA10.c's earlier functions (tools/port_from_us.py) */
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
extern int func_0011ED10();
extern int func_0011ECB0();
extern void func_0011FA10();

/* localdecomp:start func_0011FD40 */
typedef struct {
    s32 status;
    void *entry;
    u8 *stack;
    s32 stackSize;
    s32 pad[8];
} ThreadInfo_11FD40;

extern s32 func_0011F860(void);
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 func_0011ED20(s32, ThreadInfo_11FD40 *);
extern s32 func_0011EC40(s32, s32);

s32 func_0011FD40(s32 tid, s32 arg) {
    ThreadInfo_11FD40 info;
    s32 r;
    u8 *p;

    if (func_0011F860() != 0) {
        return -1;
    }
    if (func_00124920() == 0) {
        return -1;
    }
    r = func_0011ED20(tid, &info);
    if (r < 0) {
        func_00124970();
        return r;
    }
    if (info.status != 0x10) {
        func_00124970();
        return -1;
    }
    p = info.stack + info.stackSize - 0x2A0;
    __asm__ __volatile__(
        "sq $0, 0x0(%0)\n"
        "sq $0, 0x10(%0)\n"
        "sq $0, 0x20(%0)\n"
        "sq $0, 0x30(%0)\n"
        "sq $0, 0x40(%0)\n"
        "sq $0, 0x50(%0)\n"
        "sq $0, 0x60(%0)\n"
        "sq $0, 0x70(%0)\n"
        "sq $0, 0x80(%0)\n"
        "sq $0, 0x90(%0)\n"
        "sq $0, 0xA0(%0)\n"
        "sq $0, 0xB0(%0)\n"
        "sq $0, 0xC0(%0)\n"
        "sq $0, 0xD0(%0)\n"
        "sq $0, 0xE0(%0)\n"
        "sq $0, 0xF0(%0)\n"
        "sq $0, 0x100(%0)\n"
        "sq $0, 0x110(%0)\n"
        "sq $0, 0x120(%0)\n"
        "sq $0, 0x130(%0)\n"
        "sq $0, 0x140(%0)\n"
        "sq $0, 0x150(%0)\n"
        "sq $0, 0x160(%0)\n"
        "sq $0, 0x170(%0)\n"
        "sq $0, 0x180(%0)\n"
        "sq $0, 0x190(%0)\n"
        "sq $0, 0x1A0(%0)\n"
        "sq $0, 0x1B0(%0)\n"
        "sq $0, 0x200(%0)\n"
        "sq $0, 0x210(%0)\n"
        "sq $0, 0x220(%0)\n"
        "sq $0, 0x230(%0)\n"
        "sq $0, 0x240(%0)\n"
        "sq $0, 0x250(%0)\n"
        "sq $0, 0x260(%0)\n"
        "sq $0, 0x270(%0)\n"
        "sll $8, %1, 0\n"
        "sd $8, 0x40(%0)\n"
        "lw $8, 0x1C0(%0)\n"
        "sd $8, 0x1C0(%0)\n"
        "sd $0, 0x1C8(%0)\n"
        "lw $8, 0x1D0(%0)\n"
        "sd $8, 0x1D0(%0)\n"
        "sd $0, 0x1D8(%0)\n"
        "lw $8, 0x1E0(%0)\n"
        "sd $8, 0x1E0(%0)\n"
        "sd $0, 0x1E8(%0)\n"
        "lw $8, 0x1F0(%0)\n"
        "sd $8, 0x1F0(%0)\n"
        "sd $0, 0x1F8(%0)\n"
        : : "r"(p), "r"(arg) : "$8", "memory");
    func_00124970();
    return func_0011EC40(tid, arg);
}
/* localdecomp:end func_0011FD40 */
