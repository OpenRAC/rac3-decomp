#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern int func_0012E2E0();
/* --- end of declarations from other files --- */

/* declarations of 12A948.c's earlier functions (tools/port_from_us.py) */
extern s32 func_0012B098(s32);
extern s32 func_00124920(void);
extern s32 func_00124970(void);
extern s32 D_15A140;
extern void *D_15A144;
extern volatile int D_0013F914;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F934;
extern volatile int D_0013F960;
extern volatile int D_0013F964;
extern int D_15A140;
extern void func_0011EE50(s32);
typedef struct {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
} SemaParam_12AC40;
extern volatile int D_0013F920;
extern volatile int D_0013F928;
extern volatile int D_0013F92C;
extern volatile int D_0013F930;
extern volatile int D_0013F934;
extern char D_00151300[];
extern char D_00151310[];
extern char D_00151320[];
extern char D_00151330[];
extern int func_0011EE20();
extern s32 D_0013F924_0012AE20[];
extern s32 D_0013F948_0012AE20[];
extern void func_0012ADC8(void);
extern void func_00121B70();
extern s32 func_00124920(void);
extern s32 func_00124970(void);
typedef struct { u8 pad[0x24]; s32 x24; } S_12AEA8;
extern void func_0012AC40_0012AEA8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121760_0012AEA8();
extern s32 func_0012B098(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern volatile s32 D_0013F928;
extern s32 D_0013F910;
extern s32 D_0013F91C;
extern s32 D_0013F93C;
extern S_12AEA8 D_00140AD0;
extern char D_001513B8[];
extern char D_001513E0[];
extern u8 D_0013F980[];
extern s32 D_0013F910_0012B138[];
extern u8 D_00141480_0012B138[];
extern char D_00151408_0012B138[];
extern s32 func_00122A10(void *);
extern s32 func_0011FC78(s32);
extern void func_00121760_0012B1A8(const char *, ...);
typedef struct {
    u8 pad[0x24];
    s32 serve;
} Cd_12B1A8;
extern volatile s32 D_0013F92C;
extern s32 D_0013F910;
extern s32 D_0013F918;
extern s32 D_0013F954;
extern Cd_12B1A8 D_00141480_0012B1A8;
extern char D_00151418[];
extern char D_00151440[];
extern void func_0012AC40_0012B1A8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121760_0012B1A8(const char *, ...);
extern s32 func_0012B138(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630_0012B1A8(Cd_12B1A8 *, u32, s32);
typedef struct { u8 pad[0x24]; s32 x24; } S_12B5E8;
extern s32 func_0012B138(s32);
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern void func_00121760_0012B5E8();
extern void func_00121F38();
extern s32 func_00122810();
extern s32 func_00124920(void);
extern void func_00124970_0012B5E8(void);
extern void func_0012AC40_0012B5E8(void);
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern s32 D_0013F910;
extern volatile s32 D_0013F92C;
extern s32 D_0013F940;
extern s32 D_0013F950;
extern S_12B5E8 D_15A390;
extern s32 D_15A3D0;
extern s32 D_00140B00_0012B5E8[];
extern char D_00151488[];
extern char D_001514A0[];
extern char D_001514C0[];
typedef struct {
    u8 pad0[0x24];
    int serve;
    u8 pad28[0x40 - 0x28];
} Cd_12B800;
extern int D_0013F910;
extern volatile int D_0013F930;
extern int D_0013F940;
extern int D_0013F950;
extern char D_001514A0[];
extern char D_001514C0[];
extern char D_001514D8[];
extern Cd_12B800 D_15A390_0012B800;
extern int D_15A3D0;
extern int D_00141380[];
extern int func_00121760();
extern int func_0011EE40();
extern int func_0011EE70();
extern int func_00121FE8_0012B800();
extern void func_00121F38();
extern int func_0012AC40();
extern int func_0012B5E8();
extern int func_00124920();
extern int func_00124970_0012B800();
extern s32 func_00122630(void *, s32, s32);
extern s32 func_00122810();
extern s32 D_00140B00_0012BC00[];
extern u8 D_00141480_0012BC00[];
extern s32 D_0013F92C_0012BC00[];
extern volatile int D_0013F960;
extern u8 D_00141480[];
extern int D_00140B00_0012BC98[];
extern int func_0012B1A8(int n);
extern s32 D_00140F40;
extern s32 D_001414A8;
extern s32 D_001414AC;
extern s32 D_001414B0;
extern u8 D_00140B00[];
extern u8 D_00141480[];
extern s32 D_0013F92C_0012BD50;
extern s32 func_0012B1A8(s32);
extern void func_00121F38(void *, s32);
extern s32 func_00122810();
extern s32 func_0011EE40(s32);
typedef struct {
    u8 b[8];
} Clock_12BE28;
extern u8 D_00140B00[];
extern s32 D_0013F92C_0012BE28;
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);
typedef struct {
    s16 inter;
    s16 omode;
    s16 ffmode;
    u16 version;
    int vsc;
    int vscid;
} GParam_12BEE8;
GParam_12BEE8 *func_0012C078_0012BEE8(void);
u64 func_0011F160(u64 imr);
void func_0011F870(int n);
void func_0011EB20(int n, int id);
void func_0011EA20(int inter, int omode, int ffmode);
extern u8 D_001414D0[];
extern s32 func_00123430(void *, s32);
extern s32 func_00123840(s32, void *, s32);
extern void func_001236C0(s32);
extern s32 func_00117070(void *);
extern u8 D_00151540[];
typedef struct {
    u64 pmode;
    u64 smode2;
    u64 dispfb;
    u64 display;
    u64 bgcolor;
} Disp_12C4B0;
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
} Gs_12C4B0;
extern void *func_0012C078(void);
extern void *func_0012C078(void);
typedef struct {
    u64 ATE : 1;
    u64 pad : 63;
} Bit_12C638;
typedef struct {
    u64 frame1;
    u64 frame1addr;
    u64 zbuf1;
    u64 zbuf1addr;
    u64 xyoffset1;
    u64 xyoffset1addr;
    u64 scissor1;
    u64 scissor1addr;
    Bit_12C638 prmodecont;
    u64 prmodecontaddr;
    Bit_12C638 colclamp;
    u64 colclampaddr;
    Bit_12C638 dthe;
    u64 dtheaddr;
    u64 test1;
    u64 test1addr;
} DrawEnv_12C638;
short func_0012C570(short psm, short w, short h);
extern char D_00151588[];
extern s32 func_00121760_0012C820(char *, ...);
extern long func_0011F340();
extern void func_0011F2B0();
extern int func_00121760();
extern char D_001516E0[];
extern void *func_0012C078(void);
extern void func_0011F870(int n);
extern void func_0011EB20(int n, int id);
extern s32 func_0011EB00();
extern void func_0011F8D8();
extern s32 D_00141500[];
typedef struct { u8 b[0x14]; } E_12D678;
extern void func_0012D618(void *, s32);
extern s32 func_0012D758_0012D678(void *);
extern s32 D_00151908[];
typedef struct {
    u8 sts;
    u8 std;
    u8 mfd;
    u8 rcyc;
    u16 express;
    u16 notify;
    u16 sqwc;
    u16 tqwc;
    void *rbadr;
    u32 rbmsk;
} Env_12D758;
extern u8 D_00151930[];
extern u8 D_00151940[];
extern u8 D_00151950[];
extern Env_12D758 D_15A3D8;
typedef struct {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
} SemaParam_12DA60;
typedef struct {
    u8 pad0[0x24];
    int serve;
    u8 pad28[0x80 - 0x28];
} Cd_12DA60;
extern int D_0014153C;
extern int D_00141540;
extern char D_00151960[];
extern char D_00151970[];
extern char D_00151988[];
extern char D_001519A0[];
extern char D_001519C8[];
extern Cd_12DA60 D_15A400;
extern u8 D_15A480[];
extern int D_15B9C0_0012DA60[];
extern int func_0011EE20();
extern int func_0011EE30();
extern int func_0011EE40();
extern int func_0011EE60();
extern int func_00121FE8_0012DA60();
extern s32 func_00122630(void *, s32, s32);
extern s32 func_00122810();
extern int func_00121760();
typedef struct {
    u8 pad0[0x24];
    s32 server;
} Cd_12DCA0;
typedef struct {
    s32 port;
    s32 slot;
    s32 mode;
    u8 padC[0x14 - 0xC];
    char name[0x400];
} Rpc_12DCA0;
extern Cd_12DCA0 D_15A400_12DCA0;
extern Rpc_12DCA0 D_15A4B0;
extern u8 D_15B9C0[];
extern s32 D_0014153C;
extern s32 D_00141538[];
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern char *func_0011BB58(char *, char *, s32);
extern s32 func_00122810();
extern void func_0012DC88();
extern s32 func_0012DCA0();
extern s32 D_00141538[];
extern void func_0012DC88();
typedef struct {
    s32 x0;
    u8 pad4[0xC];
    s32 x10;
    s32 x14;
    u8 pad18[0x18];
} McCmd_12DEC0;
extern Cd_12B1A8 D_15A400_0012DEC0;
extern McCmd_12DEC0 D_15A480_0012DEC0;
extern s32 D_0014153C;
extern u8 D_15B9C0[];
extern void func_0012DC88(void);
extern s32 func_00122810(void *, s32, s32, void *, s32, void *, s32, void *, void *);

/* localdecomp:start func_0012E050 */
/* libmc: asynchronous memory card RPC (function 5); 2.9-ee-991111 */
typedef struct { u8 pad[0x24]; s32 x24; } C_12E050;
typedef struct {
    s32 x0;
    u8 pad4[0xC - 4];
    s32 xC;
    u8 pad10[0x18 - 0x10];
    void *x18;
    void *x1C;
} A_12E050;

extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_00121F38();
extern s32 func_00122810();
extern void func_0012DFA0();
extern C_12E050 D_15A400_0012E050;
extern A_12E050 D_15A480_0012E050;
extern u8 D_15A900[];
extern u8 D_15B9C0[];
extern s32 D_0014153C;

s32 func_0012E050(s32 a, void *buf, s32 size) {
    if (D_15A400_0012E050.x24 == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    D_15A480_0012E050.x0 = a;
    D_15A480_0012E050.x18 = buf;
    D_15A480_0012E050.xC = size;
    D_15A480_0012E050.x1C = D_15A900;
    func_00121F38(buf, size);
    func_00121F38(D_15A900, 0xC0);
    if (func_00122810(&D_15A400_0012E050, 5, 1, &D_15A480_0012E050, 0x30, D_15B9C0, 4, func_0012DFA0, D_15A900) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 5;
    return 0;
}
/* localdecomp:end func_0012E050 */

/* localdecomp:start func_0012E168 */
typedef struct {
    u8 pad0[0x24];
    s32 server;
} Cd_12E168;

typedef struct {
    s32 fd;
    u8 pad4[0xC - 4];
    s32 rest;
    u8 pad10[0x14 - 0x10];
    u32 head;
    u8 *tail;
    u8 pad1C[0x20 - 0x1C];
    u8 data[16];
} Rpc_12E168;

extern Cd_12E168 D_15A400_12E168;
extern Rpc_12E168 D_15A480_12E168;
extern u8 D_15B9C0[];
extern s32 D_0014153C;
extern s32 D_00141538[];
extern s32 func_0011EE70(s32);
extern s32 func_0011EE40(s32);
extern void func_0011F0A0(s32);
extern s32 func_00122810();
extern void func_0012DC88();

s32 func_0012E168(s32 fd, u8 *buf, s32 size)
{
    u32 i;
    s32 n;

    if (D_15A400_12E168.server == 0) {
        return -100;
    }
    if (func_0011EE70(D_0014153C) < 0) {
        return -200;
    }
    D_15A480_12E168.fd = fd;
    if (size < 0x11) {
        D_15A480_12E168.head = size;
        D_15A480_12E168.rest = 0;
        D_15A480_12E168.tail = 0;
    } else {
        {
            u8 *p = buf - 0x10;
            n = (u8 *)((u32)(buf - 1) & ~0xF) - p;
        }
        D_15A480_12E168.head = n;
        D_15A480_12E168.rest = size - n;
        D_15A480_12E168.tail = buf + n;
    }
    for (i = 0; i < D_15A480_12E168.head; i++) {
        D_15A480_12E168.data[i] = buf[i];
    }
    func_0011F0A0(0);
    if (func_00122810(&D_15A400_12E168, 6, 1, &D_15A480_12E168, 0x30, D_15B9C0, 4, func_0012DC88, 0) != 0) {
        func_0011EE40(D_0014153C);
        return -91;
    }
    D_00141538[0] = 6;
    return 0;
}
/* localdecomp:end func_0012E168 */

/* localdecomp:start func_0012E2E0 */
/* libmc: wait for or poll the pending memory card command (sceMcSync-style); 2.9-ee-991111 */
extern void func_0011EE60_0012E2E0(s32);
extern s32 D_00141540;

s32 func_0012E2E0(s32 mode, s32 *cmd, s32 *result) {
    s32 busy;

    if (D_00141538[0] == 0) {
        return -1;
    }
    busy = 0;
    if (func_0011EE70(D_00141540) < 0) {
        busy = 1;
    }
    if (mode == 0 && busy) {
        func_0011EE60_0012E2E0(D_00141540);
        busy = 0;
    }
    busy = !busy;
    if (cmd != 0) {
        *cmd = D_00141538[0];
    }
    if (busy != 0) {
        D_00141538[0] = 0;
        if (result != 0) {
            *result = *(s32 *)D_15B9C0;
        }
        func_0011EE40(D_0014153C);
    }
    return busy;
}
/* localdecomp:end func_0012E2E0 */
