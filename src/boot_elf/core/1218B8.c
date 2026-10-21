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
extern int D_0013DBF4;
extern char D_153000[];
extern s32 func_00120010();
extern void func_001205B8(s32);
extern void func_00120668(s32);
extern s32 func_00120908_00121718(void *, void *, s32, s32, void *);
extern void func_00121620(void);
extern s32 func_00121678();
extern s32 func_00120908();
extern s32 func_00124920();
extern s32 func_00124970();
extern s32 func_001216A0();
extern s32 func_00120908();
extern s32 func_00124920();
extern s32 func_00124970();
typedef struct { u8 pad[0x10]; s32 x10; s32 x14; } A_121860;
typedef struct { u8 pad[0x1C]; s32 *x1C; } B_121860;
typedef struct { u8 pad[0x10]; s32 x10; } A_121880;
typedef struct { u8 pad[0x8]; s32 x8; } B_121880;
extern s32 D_153300[];

/* localdecomp:start func_001218B8 */
typedef struct {
    void *f0;
    void *f4;
    s32 f8;
    void *fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 *f1C;
} S_1218B8;
typedef struct {
    void (*fn)(void *, void *);
    void *arg;
    s32 pad;
} H_1218B8;
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    void *f10;
} P_1218B8;
extern s32 D_0013DBF8[];
extern s32 D_153300[];
extern s32 D_153154[];
extern u8 D_153080[];
extern u8 D_153100[];
extern S_1218B8 D_153158;
extern H_1218B8 D_153180[];
extern P_1218B8 D_153140;
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern void func_0011F0A0(s32);
extern void func_0011F200(void);
extern s32 func_0011EB30(s32, void *, s32);
extern s32 func_0011F9A8(s32);
extern u32 func_0011F230();
extern s32 func_0011F220(s32, s32);
extern s32 func_00121D70(s32, s32, s32, s32, s32, s32);
extern void func_00121880();
extern void func_00121860();
extern void func_00121DF0();

void func_001218B8(void)
{
    s32 i;
    s32 r;

    func_00124920();
    if (D_0013DBF8[0] != 0) {
        func_00124970();
        return;
    }
    D_0013DBF8[0] = 1;
    D_153158.f0 = (void *)((u32)D_153080 | 0x20000000);
    D_153158.f4 = (void *)((u32)D_153100 | 0x20000000);
    D_153158.f8 = 0;
    D_153158.fC = D_153180;
    D_153158.f10 = 0x20;
    D_153158.f14 = 0;
    D_153158.f18 = 0;
    D_153158.f1C = D_153300;
    for (i = 0; i < 0x20; i++) {
        D_153180[i].fn = 0;
        D_153180[i].arg = 0;
    }
    for (i = 0; i < 0x20; i++) {
        D_153300[i] = 0;
    }
    D_153180[0].fn = func_00121880;
    D_153180[1].fn = func_00121860;
    D_153180[0].arg = &D_153158;
    D_153180[1].arg = &D_153158;
    func_00124970();
    func_0011F0A0(0);
    if (*(volatile u32 *)0x1000E010 & 0x20) {
        *(volatile u32 *)0x1000E010 = 0x20;
    }
    if (!(*(volatile u32 *)0x1000C000 & 0x100)) {
        func_0011F200();
    }
    D_153154[0] = func_0011EB30(5, func_00121DF0, 0);
    func_0011F9A8(5);
    r = func_0011F230(0x80000000);
    D_153158.f8 = r;
    if (r != 0) {
        D_153140.f10 = D_153080;
        func_00121D70(0x80000000, (s32)&D_153140, 0x14, 0, 0, 0);
        return;
    }
    while (!(func_0011F230(4) & 0x20000)) {
    }
    r = func_0011F230(2);
    D_153158.f8 = r;
    func_0011F220(0x80000000, r);
    func_0011F220(0x80000001, (s32)&D_153158);
    D_153140.f10 = D_153080;
    D_153140.fC = 0;
    func_00121D70(0x80000002, (s32)&D_153140, 0x14, 0, 0, 0);
}
/* localdecomp:end func_001218B8 */
