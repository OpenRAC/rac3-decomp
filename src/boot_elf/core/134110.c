#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 133BB8.c's earlier functions (tools/port_from_us.py) */
extern s32 func_00124920(void);
extern void func_00124970_00133BB8(void);
typedef struct {
    u8 pad0[0x12C];
    int f12C;
    u8 pad130[0x13C - 0x130];
    int f13C;
    u8 pad140[0x1C0 - 0x140];
    int f1C0;
    int f1C4;
    u8 pad1C8[0x878 - 0x1C8];
    int f878;
} S_133C58;
void func_00134D68(void *s);
void func_00134D60(void *s);
int func_00132970(void *s, int n);
int func_00132888_00133C58(void *s, int n);
void func_00134C00_00133C58(void *s, int n);
int func_00132428(void *s);
void func_0013A150(void *s, char *fmt, int x);
extern s32 func_0013A0F8();
extern char D_00151DF8[];
extern char D_00151E20[];
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x68 - 0x14];
} Fb_133DF8;
typedef struct {
    u8 pad0[0x10C];
    u32 f10C;
    u32 f110;
    u32 f114;
    s32 f118[3];
    s32 f124;
    u8 pad128[0x134 - 0x128];
    s32 f134;
    s32 f138;
    s32 f13C;
    s32 f140;
    u8 pad144[0x14C - 0x144];
    s32 f14C;
    s32 f150;
    s32 f154;
    u8 pad158[0x184 - 0x158];
    s32 f184;
    s32 f188;
    s32 f18C;
    u8 pad190[0x198 - 0x190];
    s32 f198;
    u8 pad19C[0x1F8 - 0x19C];
    Fb_133DF8 fb[9];
    u8 pad5A0[0x858 - 0x5A0];
    s32 f858;
    u8 pad85C[0x87C - 0x85C];
    s32 f87C;
} S_133DF8;
typedef struct {
    s32 w;
    s32 h;
    u8 pad8[0x40 - 8];
    S_133DF8 *q;
} H_133DF8;
extern void func_00136000();
extern u32 func_00136010();

/* localdecomp:start func_00134110 */
/* libmpeg: sequence header (sizes, bit rate, the two quantiser matrices); 2.9-ee-991111 */
typedef struct {
    u8 pad0[0xE8];
    s32 xE8;            /* 0xE8 */
    u8 padEC[0x134 - 0xEC];
    u32 x134;           /* 0x134 horizontal size */
    s32 x138;           /* 0x138 vertical size */
    u8 pad13C[0x144 - 0x13C];
    u32 x144;           /* 0x144 bit rate */
    u32 x148;           /* 0x148 vbv buffer size */
    u8 pad14C[0x828 - 0x14C];
    s32 x828;           /* 0x828 */
    u32 x82C;           /* 0x82C */
    u8 pad830[0x850 - 0x830];
    u32 x850;           /* 0x850 load intra matrix */
    u32 x854;           /* 0x854 load non-intra matrix */
    u8 pad858[0x868 - 0x858];
    void *x868;         /* 0x868 */
} S_134110;

typedef struct {
    s32 type;
    s32 pad4;
    long f8;
    long f10;
} Cb_134110;

static __inline__ void cmd_134110(S_134110 *p, u32 cmd) {
    *(volatile u32 *)0x10002000 = cmd;
    p->x82C = cmd & 0xF0000000;
    if (p->x82C == 0x20000000 || p->x82C == 0x30000000 || p->x82C == 0x40000000) {
        p->x828 = 0;
    } else {
        p->x828 = 1;
    }
}

static __inline__ void defmat_134110(S_134110 *p, u8 *mat, u32 cmd) {
    extern s32 func_00135D50();
    extern void func_00134BC8();
    Cb_134110 cb;
    s32 r;

    cb.type = 2;
    func_00135D50(p->x868, &cb);
    func_00134BC8(p);
    *(volatile u32 *)0x10002000 = 0;
    func_00134BC8(p);
    r = func_00124920();
    *(volatile u32 *)0x1000B410 = (u32)mat & 0x0FFFFFFF;
    *(volatile u32 *)0x1000B420 = 4;
    *(volatile u32 *)0x1000B400 = 0x101;
    if (r) {
        func_00124970_00133BB8();
    }
    cmd_134110(p, cmd);
    func_00134BC8(p);
    cb.type = 3;
    func_00135D50(p->x868, &cb);
}

void func_00134110(S_134110 *p) {
    extern u32 func_00132888();
    extern void func_00134BC8();
    extern void func_001349F8();
    extern void func_00133DF8();
    extern char D_00151E48[];
    extern u8 D_00141640[];
    extern u8 D_00141680[];
    u32 v;

    p->xE8 = 0;
    v = func_00132888(p, 32);
    p->x134 = v >> 20;
    p->x138 = (v >> 8) & 0xFFF;
    if (p->x138 > 2800) {
        func_0013A0F8(p, D_00151E48);
    }
    v = func_00132888(p, 30);
    p->x144 = v >> 12;
    p->x148 = (v >> 1) & 0x3FF;
    if ((p->x850 = func_00132888(p, 1)) != 0) {
        func_00134BC8(p);
        cmd_134110(p, 0x50000000);
        func_00134BC8(p);
    } else {
        defmat_134110(p, D_00141640, 0x50000000);
    }
    if ((p->x854 = func_00132888(p, 1)) != 0) {
        func_00134BC8(p);
        cmd_134110(p, 0x58000000);
        func_00134BC8(p);
    } else {
        defmat_134110(p, D_00141680, 0x58000000);
    }
    func_001349F8(p);
    func_00133DF8(p->x868);
}
/* localdecomp:end func_00134110 */
