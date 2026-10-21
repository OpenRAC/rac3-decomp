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
typedef struct U_1224D0 { s32 x0; u8 pad[0x34]; struct U_1224D0 *x38; } U_1224D0;
typedef struct T_1224D0 { u8 pad[8]; U_1224D0 *x8; u8 pad2[8]; struct T_1224D0 *x14; } T_1224D0;
typedef struct { u8 pad[0x28]; T_1224D0 *x28; } S_1224D0;
extern s32 func_00121DB0(s32, s32, s32, s32, s32, s32);
typedef struct { u8 pad[0x14]; s32 x14; u8 pad18[4]; s32 x1C; s32 x20; } R_122560;
typedef struct { u8 pad[0x14]; s32 x14; u8 pad18[4]; s32 x1C; s32 x20; s32 x24; s32 x28; } K_122560;
extern void func_00125E48_00122560(s32, void *, void *);
extern s32 func_00122278(S_122278 *);
extern U_1224D0 *func_001224D0(s32, S_1224D0 *);
extern s32 func_00122520(s32, s32, s32, s32);
typedef struct {
    void *pkt;
    s32 rpc_id;
    s32 sema;
    s32 xC;
    s32 x10;
    s32 buff;
    s32 gp;
    void *end_func;
    void *end_param;
    s32 server;
} Cd_122630;
typedef struct {
    u8 pad[0x14];
    void *paddr;
    s32 rpc_id;
    void *client;
    s32 rno;
} Pkt_122630;
typedef struct {
    s32 attr;
    s32 option;
    s32 init_count;
    s32 max_count;
    s32 numWaitThreads;
    void *name;
} Sema_122630;
extern u8 D_154B80[];
extern char D_00150A28[];
extern Pkt_122630 *func_001221B0_00122630(void *);
extern s32 func_0011EE20_00122630(Sema_122630 *);
extern s32 func_0011EE30(s32);
extern void func_0011EE60(s32);
typedef struct {
    void *pkt;
    s32 rpc_id;
    s32 sema;
    u8 pad[0x8];
    s32 buff;
    s32 gp;
    void *end_func;
    void *end_param;
    s32 server;
} Cd_122810;
typedef struct {
    u8 pad[0x14];
    void *paddr;
    s32 rpc_id;
    void *client;
    s32 fno;
    s32 ssize;
    s32 recv;
    s32 rsize;
    s32 rmode;
    s32 server;
} Pkt_122810;
typedef struct {
    s32 attr;
    s32 option;
    s32 init_count;
    s32 max_count;
    s32 numWaitThreads;
    void *name;
} Sema_122810;
extern u8 D_154B80[];
extern char D_00150A38[];
extern Pkt_122810 *func_001221B0(void *);
extern void func_00121F38(void *, s32);
extern s32 func_0011EE20_00122810(Sema_122810 *);
extern s32 func_0011EE30(s32);
extern void func_0011EE60(s32);
typedef struct { u8 pad[0x10]; s32 x10; u8 pad2[4]; s32 x18; } T_122A10;
typedef struct { T_122A10 *x0; s32 x4; } S_122A10;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fc; s32 f10; s32 f14; } S_122A68;
extern s32 D_0013DC90_00122A68[];
extern s32 D_0013DC94_00122A68[];
extern char D_00150A50_00122A68[];
extern char D_00150A60_00122A68[];
extern int func_0011EE20();
extern s32 func_0011FC78(s32);
extern void func_00122A68(void);
extern s32 func_0011EE60_00122C58(s32);
extern s32 func_0011EE40(s32);
extern s32 D_0013DC90;
extern u8 D_156100[];
typedef struct { s32 pad0; s32 f4; s32 f8; s32 fc; s32 f10; void *f14; } S_00123080;
extern s32 D_0013DC8C[];
extern u8 D_00150AD8[];
extern s32 func_0011EE20(void *);
extern void func_00123080(void);
extern void func_0011EE60(s32);
extern s32 D_0013DC8C[];
extern u8 D_156328[];
extern u8 D_0013DBE4[];
extern s32 D_0013DC98[];
extern s32 func_0011A01C();
extern s32 func_0011A264(s32, s32, s32);
extern s32 D_0013DC84[];
extern u8 D_156328[];

/* localdecomp:start func_00123430 */
typedef struct {
    s32 sema;
    void *res;
    s32 x8;
    s32 flags;
    s32 mode;
    char name[0x400];
    s32 fd;
} OpenArg_123430;

typedef struct {
    s32 res;
    s32 flags;
} Fd_123430;

typedef struct {
    s32 attr;
    s32 option;
    s32 init_count;
    s32 max_count;
    s32 numWaitThreads;
    void *name;
} Sema_123430;

extern OpenArg_123430 D_154C00;
extern u8 D_156100[];
extern u8 D_156300[];
extern u8 D_155840[];
extern char D_00150AF0[];
extern s32 D_0013DC90;
extern s32 func_001230D8(void);
extern void func_00123160(void);
extern s32 func_00123368(void);
extern void func_00123108(void);
extern Fd_123430 *func_00122AE0(void);
extern s32 func_0011EE20_00123430(Sema_123430 *);
extern s32 func_0011EE30(s32);
extern s32 func_0011EE40(s32);
extern s32 func_0011EE60_00123430(s32);
extern s32 func_00122B68(void *, s32, s32, void *, s32, void *, s32, void *, void *, s32);

s32 func_00123430(const char *name, s32 flags, ...) {
    char *ap;
    OpenArg_123430 *arg;
    Fd_123430 *fd;
    s32 idx;
    s32 i;
    s32 s;
    s32 ok;
    s32 mode;
    Sema_123430 sp;
    s32 res[4];

    arg = &D_154C00;
    ((s32 (*)(s32))func_001230D8)(0);
    if (D_0013DC84[0] == 0) {
        func_00123160();
    }
    if (func_00123368() != 0) {
        func_00123108();
        return 0xFFFEFFFC;
    }
    fd = func_00122AE0();
    if (fd == 0) {
        func_00123108();
        return -0x13;
    }
    ap = (char *)__builtin_next_arg(flags)
         - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8);
    mode = *(s32 *)ap;
    i = 0;
    if ((arg->name[0] = name[0]) != 0) {
        while (++i < 0x400) {
            if ((arg->name[i] = name[i]) == 0) break;
        }
    }
    if (i == 0x400) {
        arg->name[0x3FF] = 0;
    }
    idx = ((u8 *)fd - D_156100) >> 4;
    arg->flags = flags & 0x7FFFFFFF;
    arg->mode = mode;
    sp.option = 1;
    sp.name = D_00150AF0;
    arg->fd = idx;
    sp.init_count = 0;
    s = func_0011EE20_00123430(&sp);
    arg->res = res;
    arg->sema = s;
    arg->x8 = 4;
    if (func_00122B68(D_156300, 0, 0, &D_154C00, 0x418, D_155840, 4, 0, 0, 0) < 0) {
        func_0011EE30(s);
        func_00123108();
        return -0xB;
    }
    ok = *(s32 *)((u32)D_155840 | 0x20000000);
    func_00123108();
    if (ok == 0) {
        func_0011EE30(s);
        return -0xB;
    }
    func_0011EE60_00123430(s);
    func_0011EE30(s);
    if (res[0] < 0) {
        func_0011EE60_00123430(D_0013DC90);
        fd->flags = 0;
        func_0011EE40(D_0013DC90);
        return res[0];
    }
    ok = idx;
    func_0011EE60_00123430(D_0013DC90);
    fd->res = res[0];
    fd->flags |= flags;
    func_0011EE40(D_0013DC90);
    return ok;
}
/* localdecomp:end func_00123430 */

/* localdecomp:start func_001236C0 */
/* libkernl: file I/O RPC close; 2.9-ee-991111. func_001230D8 takes an argument here, the file declares it (void). */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } F_1236C0;
typedef struct { s32 x0; void *x4; s32 x8; s32 xC; s32 x10; } P_1236C0;
typedef struct { s32 count; s32 max; s32 init; s32 wait; u32 attr; void *option; } Q_1236C0;

extern F_1236C0 *func_00122C58(s32);
extern s32 func_001230D8_001236C0(s32);
extern void func_00123108(void);
extern s32 func_0011EE20_001236C0(Q_1236C0 *);
extern s32 func_0011EE30(s32);
extern s32 func_00122B68();
extern F_1236C0 D_156100_001236C0[];
extern P_1236C0 D_154C00_001236C0;
extern u8 D_156300[];
extern s32 D_155840_001236C0[];
extern char D_00150B08[];

s32 func_001236C0(s32 fd) {
    F_1236C0 *f;
    Q_1236C0 q;
    s32 res;
    s32 s;
    s32 r;
    P_1236C0 *p = &D_154C00_001236C0;

    f = func_00122C58(fd);
    func_001230D8_001236C0(1);
    if (D_0013DC84[0] == 0 || f == 0 || f->x4 == 0) {
        func_00123108();
        return -9;
    }
    p->xC = f->x0;
    p->x10 = f - D_156100_001236C0;
    q.max = 1;
    q.init = 0;
    q.option = D_00150B08;
    s = func_0011EE20_001236C0(&q);
    p->x0 = s;
    p->x4 = &res;
    p->x8 = 4;
    if (func_00122B68(D_156300, 1, 0, p, 0x14, D_155840_001236C0, 4, 0, 0, 0) < 0) {
        func_0011EE30(s);
        func_00123108();
        return -11;
    }
    f->x4 = 0;
    r = *(s32 *)((u32)D_155840_001236C0 | 0x20000000);
    func_00123108();
    if (r == 0) {
        func_0011EE30(s);
        return -11;
    }
    func_0011EE60(s);
    func_0011EE30(s);
    if (res < 0) {
        return res;
    }
    return 0;
}
/* localdecomp:end func_001236C0 */
