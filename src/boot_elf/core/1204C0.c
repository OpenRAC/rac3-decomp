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
extern s32 func_0011F250(s32, s32 *);
extern u8 D_152C10[];
extern s32 func_0011F250(s32, s32 *);
extern s32 func_0011F250(s32, s32 *);
extern s32 func_0011F250(s32, s32 *);
extern s32 func_0011F250(s32, s32 *);
extern s32 func_0011F250(s32, s32 *);
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; u8 x10[0x10]; } S_120038;
extern S_120038 D_152C40;
typedef struct { s32 size; s32 count; u8 *rd; u8 *wr; u8 buf[1]; } R_120060;
typedef struct { s32 size; s32 count; u8 *rd; u8 *wr; u8 buf[1]; } R_1200A0;
typedef struct {
    s32 fd;
    volatile s32 count;
    volatile u32 len;
    volatile s32 xC;
    u8 *ptr;
    u8 *buf;
    R_120060 *ring;
} S_1200E0;
extern char D_001507E0[];
extern char D_00150808[];
extern char D_00150820[];
extern char D_00150838[];
extern void func_00120060_001200E0();
extern void func_001217E0(const char *, ...);
typedef struct {
    s32 sock;
    volatile s32 len;
    s32 pad8;
    volatile s32 busy;
    s8 *pkt;
} St_120278;
extern volatile St_120278 D_152D50;
extern u8 D_152D80[];
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 func_0011FF30(s32, s8);
extern s32 func_0011FF60(s32);
typedef struct {
    int f0;
    volatile int f4;
    u8 *f8;
} Ring_1203F0;
typedef struct {
    u8 pad0[0x18];
    Ring_1203F0 *f18;
} Sio_1203F0;
extern Sio_1203F0 D_152D50_001203F0;
extern void func_001200A0();

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_001204C0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_0012057C);

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120580);
