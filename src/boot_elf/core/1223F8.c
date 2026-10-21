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
extern s32 func_0011F940(s32);
extern s32 func_0011EB50(s32, s32);
extern s32 D_153154[];
extern s32 D_0013DBF8[];
typedef struct { s32 a; s32 b; s32 c; } E_121BE8;
extern E_121BE8 *D_153164[];
extern E_121BE8 *D_15316C[];
typedef struct {
    u32 psize : 8;
    u32 dsize : 24;
    void *dest;
    s32 cid;
    u32 opt;
} Hdr_121C38;
typedef struct {
    u32 src;
    u32 dest;
    s32 size;
    s32 attr;
} Dma_121C38;
extern void *D_153160;
extern void func_00121F38(void *, s32);
extern s32 func_0011F1F0(Dma_121C38 *, s32);
extern s32 func_0011F1E0(Dma_121C38 *, s32);
extern s32 func_00121C38();
extern s32 func_00121C38();
extern void func_00121B38(void);
extern s32 D_0013DBFC[];
typedef struct { u8 pad[0x10]; u32 x10; s32 x14; s32 x18; } S_122258;
typedef struct { u8 pad[0x14]; s32 x14; s32 x18; u8 pad2[8]; s32 x24; } S_122278;
typedef struct { u8 pad[0x1C]; u8 *x1C; s32 x20; } S_1222A8;
typedef struct { u8 pad[0x24]; s32 x24; s32 x28; s32 x2C; } S_1223B8;
extern s32 func_00121DB0(s32, s32, s32, s32, s32, s32);

/* localdecomp:start func_001223F8 */
typedef struct {
    u8 pad0[0x10];
    u32 f10;
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
} Req_1223F8;
typedef struct {
    u8 pad0[0x14];
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    int f2C;
} Pkt_1223F8;
s32 func_00122278(S_122278 *p);
s32 func_001222A8(S_1222A8 *p, s32 i);
s32 func_00121DB0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern void func_00125E48_001223F8();
extern int func_001223B8();

void func_001223F8(Req_1223F8 *s, void *q)
{
    Pkt_1223F8 *p;
    int t;

    if (s->f10 & 4) {
        p = (Pkt_1223F8 *)func_001222A8(q, s->f10 >> 16);
    } else {
        p = (Pkt_1223F8 *)func_00122278(q);
    }
    t = s->f14;
    p->f1C = s->f1C;
    p->f14 = t;
    p->f20 = 0x8000000C;
    p->f24 = s->f20;
    p->f28 = s->f24;
    p->f2C = s->f28;
    if (func_00121DB0(0x80000008, (s32)p, 0x40, s->f20, s->f24, s->f28) == 0) {
        func_00125E48_001223F8(0x800, func_001223B8, p);
    }
}
/* localdecomp:end func_001223F8 */
