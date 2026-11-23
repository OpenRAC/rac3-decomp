#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_00121D70(s32, s32, s32, s32, s32, s32);
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

/* localdecomp:start func_00121D70 */
extern s32 func_00121C38();
s32 func_00121D70(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    r = func_00121C38(a, 0, b, c, d, e, f);
    do {
    } while (0);
    return r;
}
/* localdecomp:end func_00121D70 */

/* localdecomp:start func_00121DB0 */
extern s32 func_00121C38();
s32 func_00121DB0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 r;
    r = func_00121C38(a, 1, b, c, d, e, f);
    do {
    } while (0);
    return r;
}
/* localdecomp:end func_00121DB0 */

ASM_FUNC("asm/boot_elf/handwritten", func_00121DF0);

ASM_FUNC("asm/boot_elf/handwritten", func_00121F38);

LINKER_REMNANT("asm/boot_elf/remnants", func_00121FE4);

/* localdecomp:start func_00121FE8 */
typedef struct {
    s32 pid;
    void *pkt_table;
    s32 pkt_table_len;
    s32 unk0C;
    s32 unk10;
    void *rdata_table;
    s32 rdata_table_len;
    void *client_table;
    s32 client_table_len;
    s32 rdata_table_idx;
} SifRpcData_121FE8;
extern s32 D_0013DBFC[];
extern u8 D_153380[];
extern u8 D_153B80[];
extern u8 D_154380[];
extern SifRpcData_121FE8 D_154B80;

void func_00121FE8(s32 mode) {
    extern s32 func_00124920(void);
    extern s32 func_00124970(void);
    extern void func_001218B8(void);
    extern void func_00121B70();
    extern s32 func_00121890(s32);
    extern void func_001222E8();
    extern void func_00122560();
    extern void func_00122780();
    extern void func_001223F8();
    s32 *packet;

    func_00124920();
    if (D_0013DBFC[0]) {
        func_00124970();
        return;
    }
    D_0013DBFC[0] = 1;
    func_00124970();
    func_001218B8();
    func_00124920();
    D_154B80.pkt_table = (void *)((u32)D_153380 | 0x20000000);
    D_154B80.pkt_table_len = 32;
    D_154B80.unk0C = 0;
    D_154B80.unk10 = 0;
    D_154B80.rdata_table = (void *)((u32)D_153B80 | 0x20000000);
    D_154B80.rdata_table_len = 32;
    D_154B80.client_table = (void *)((u32)D_154380 | 0x20000000);
    D_154B80.client_table_len = 32;
    D_154B80.rdata_table_idx = 0;
    D_154B80.pid = 1;
    func_00121B70(0x80000008, func_001222E8, &D_154B80);
    func_00121B70(0x80000009, func_00122560, &D_154B80);
    func_00121B70(0x8000000A, func_00122780, &D_154B80);
    func_00121B70(0x8000000C, func_001223F8, &D_154B80);
    func_00124970();
    if (func_0011F230(0x80000002)) {
        return;
    }
    packet = (s32 *)(D_153380 + 64);
    packet[3] = 1;
    func_00121D70(0x80000002, (s32)packet, 16, 0, 0, 0);
    while (func_00121890(0) == 0) {
    }
    func_0011F220(0x80000002, 1);
}
/* localdecomp:end func_00121FE8 */

/* localdecomp:start func_00122188 */
extern void func_00121B38(void);
extern s32 D_0013DBFC[];
void func_00122188(void) {
    func_00121B38();
    D_0013DBFC[0] = 0;
}
/* localdecomp:end func_00122188 */

/* localdecomp:start func_001221B0 */
typedef struct {
    u8 pad0[0x10];
    u32 x10;
    void *x14;
    s32 x18;
    u8 pad1C[0x40 - 0x1C];
} E_001221B0;
typedef struct {
    s32 x0;
    E_001221B0 *x4;
    s32 x8;
} P_001221B0;
E_001221B0 *func_001221B0(P_001221B0 *p) {
    E_001221B0 *e;
    s32 i;
    s32 n;
    s32 id;
    s32 t;
    func_00124920();
    n = p->x8;
    e = p->x4;
    for (i = 0; i < n; i++, e++) {
        if (e->x10 & 1) {
            continue;
        }
        e->x10 = (i << 16) | 5;
        if (++p->x0 == 1) {
            p->x0++;
            id = 1;
        } else {
            id = p->x0;
        }
        e->x14 = e;
        e->x18 = id;
        func_00124970();
        return e;
    }
    func_00124970();
    return 0;
}
/* localdecomp:end func_001221B0 */

/* localdecomp:start func_00122258 */
typedef struct { u8 pad[0x10]; u32 x10; s32 x14; s32 x18; } S_122258;
void func_00122258(S_122258 *p) {
    p->x18 = 0;
    p->x10 &= ~1;
}
/* localdecomp:end func_00122258 */

typedef struct { u8 pad[0x14]; s32 x14; s32 x18; u8 pad2[8]; s32 x24; } S_122278;
/* localdecomp:start func_00122278 */
/* Ported from rac4-decomp/src/core/0012A020.c. */
s32 func_00122278(S_122278 *arg0) {
    s32 v = arg0->x24 % arg0->x18;
    s32 next = arg0->x14 + (v << 6);
    arg0->x24 = v + 1;
    return next;
}
/* localdecomp:end func_00122278 */

/* localdecomp:start func_001222A8 */
typedef struct { u8 pad[0x1C]; u8 *x1C; s32 x20; } S_1222A8;
s32 func_001222A8(S_1222A8 *p, s32 i) {
    if (i < 0 || i >= p->x20) {
        return func_00122278((S_122278 *)p);
    }
    return (s32)(p->x1C + (i << 6));
}
/* localdecomp:end func_001222A8 */

/* localdecomp:start func_001222E8 */
#include "cpu.h"
typedef struct {
    S_122258 *x0;
    s32 x4;
    s32 x8;
    u8 padC[8];
    s32 x14;
    s32 x18;
    s32 (*x1C)(s32);
    s32 x20;
    s32 x24;
} Q_1222E8;
typedef struct {
    u8 pad[0x1C];
    Q_1222E8 *x1C;
    u32 x20;
    s32 x24;
    s32 x28;
} P_1222E8;
extern void func_0011EE50(s32);
void func_001222E8(P_1222E8 *p) {
    Q_1222E8 *q;
    switch (p->x20) {
    case 0x8000000B:
    case 0x8000000C:
        break;
    case 0x8000000A:
        q = p->x1C;
        if (q->x1C != 0) {
            void *old = CpuSwapGp((void *)q->x18);
            q->x1C(q->x20);
            CpuSwapGp(old);
        }
        break;
    case 0x80000009:
        p->x1C->x24 = p->x24;
        p->x1C->x14 = p->x28;
        break;
    }
    q = p->x1C;
    if (q->x8 >= 0) {
        func_0011EE50(q->x8);
    }
    func_00122258(q->x0);
    q->x0 = 0;
}
/* localdecomp:end func_001222E8 */

/* localdecomp:start func_001223B8 */
typedef struct { u8 pad[0x24]; s32 x24; s32 x28; s32 x2C; } S_1223B8;
extern s32 func_00121DB0(s32, s32, s32, s32, s32, s32);
s32 func_001223B8(s32 a, s32 b, s32 c, S_1223B8 *d) {
    s32 r;
    if (func_00121DB0(0x80000008, (s32)d, 0x40, d->x24, d->x28, d->x2C) != 0) {
        r = 0;
    } else {
        r = 0x800;
    }
    return r;
}
/* localdecomp:end func_001223B8 */
