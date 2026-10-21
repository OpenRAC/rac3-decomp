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

ASM_FUNC("asm/boot_elf/handwritten", func_0011FEB8);

/* localdecomp:start func_0011FEE0 */
extern s32 func_0011F250(s32, s32 *);
extern u8 D_152C10[];
s32 func_0011FEE0(u16 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = (s32)D_152C10 | 0x20000000;
    return func_0011F250(1, buf);
}
/* localdecomp:end func_0011FEE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011FF28);

/* localdecomp:start func_0011FF30 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FF30(s32 a, s8 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0011F250(3, buf);
}
/* localdecomp:end func_0011FF30 */

/* localdecomp:start func_0011FF60 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FF60(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0011F250(4, buf);
}
/* localdecomp:end func_0011FF60 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0011FF88);

/* localdecomp:start func_0011FF90 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FF90(s32 a, s32 b, u16 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0011F250(-5, buf);
}
/* localdecomp:end func_0011FF90 */

/* localdecomp:start func_0011FFC8 */
extern s32 func_0011F250(s32, s32 *);
s32 func_0011FFC8(s32 a, s32 b, u16 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0011F250(-6, buf);
}
/* localdecomp:end func_0011FFC8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00120000);

LINKER_REMNANT("asm/boot_elf/remnants", func_00120008);

/* localdecomp:start func_00120010 */
extern s32 func_0011F250(s32, s32 *);
s32 func_00120010(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0011F250(0x10, buf);
}
/* localdecomp:end func_00120010 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/core", func_00120034);

/* localdecomp:start func_00120038 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; u8 x10[0x10]; } S_120038;
extern S_120038 D_152C40;
S_120038 *func_00120038(s32 a) {
    D_152C40.x0 = a;
    D_152C40.x4 = 0;
    D_152C40.xC = (s32)D_152C40.x10;
    D_152C40.x8 = (s32)D_152C40.x10;
    return &D_152C40;
}
/* localdecomp:end func_00120038 */

/* localdecomp:start func_00120060 */
typedef struct { s32 size; s32 count; u8 *rd; u8 *wr; u8 buf[1]; } R_120060;
void func_00120060(R_120060 *p) {
    p->count++;
    p->wr++;
    if (p->wr == p->buf + p->size) {
        p->wr = p->buf;
    }
}
/* localdecomp:end func_00120060 */

/* localdecomp:start func_001200A0 */
typedef struct { s32 size; s32 count; u8 *rd; u8 *wr; u8 buf[1]; } R_1200A0;
void func_001200A0(R_1200A0 *p) {
    p->count--;
    p->rd++;
    if (p->rd == p->buf + p->size) {
        p->rd = p->buf;
    }
}
/* localdecomp:end func_001200A0 */
