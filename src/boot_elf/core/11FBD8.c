#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
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
extern int func_0011FD40();
extern int func_0011ED10();
extern int func_0011ECB0();
extern void func_0011FA10();

ASM_FUNC("asm/boot_elf/handwritten", func_0011FBD8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0011FC70);

ASM_FUNC("asm/boot_elf/handwritten", func_0011FC78);
