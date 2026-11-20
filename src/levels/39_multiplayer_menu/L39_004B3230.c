#include "common.h"
#include "dnas.h"

/* the first library's driver: driver(block, k1, k2, k3) (include/dnas.h) */
extern void func_L39_004BD350(s32, s32, s32, u32);

/* localdecomp:start func_L39_004B3230 */
typedef struct {
    u16 flags;             /* 0x00 */
    u16 pad2;
    u8 *unk4;              /* 0x04 */
    s32 unk8;
    u8 *unkC;              /* 0x0C */
    s32 version;           /* 0x10 */
} S_004B3230_arg;

typedef struct {
    u32 unk0;
    s32 unk4;
} S_004B3230_opt;

typedef struct {
    u8 host[0x200];        /* 0x000 */
    u8 pad200[0x404 - 0x200];
    s32 unk404;            /* 0x404 */
    u8 pad408[0x410 - 0x408];
    long unk410;           /* 0x410 */
    s32 unk418;            /* 0x418 */
    s32 unk41C;            /* 0x41C */
    s32 unk420;            /* 0x420 */
    s32 unk424;            /* 0x424 */
    s32 unk428;            /* 0x428 */
    u8 pad42C[0x434 - 0x42C];
    u8 unk434[0x10688 - 0x434];
    unsigned long flags;   /* 0x10688 */
    u8 pad10690[0x1069C - 0x10690];
    void *unk1069C;        /* 0x1069C */
    u8 pad106A0[4];
    void *unk106A4;        /* 0x106A4 */
    u8 pad106A8[4];
    void *unk106AC;        /* 0x106AC */
    u8 pad106B0[0x106BC - 0x106B0];
    s32 sema[8];           /* 0x106BC */
    s32 unk106DC;          /* 0x106DC */
    u8 pad106E0[0x10710 - 0x106E0];
    void *unk10710[9];     /* 0x10710 */
    s32 unk10734;          /* 0x10734 */
    s32 unk10738;          /* 0x10738 */
} S_004B3230;

extern s32 D_L39_00453FAC;
extern S_004B3230 D_L39_00453FB0_004B3230;
extern u8 D_L39_003D2B00[];
extern u8 D_L39_003D2F00[];
extern u8 D_L39_003DAF38[];
extern u8 D_L39_003E3370[];
extern char D_L39_004749F0[];
extern char D_L39_00474A08[];
extern char D_L39_00474A20[];
extern char D_L39_00474A38[];
extern char D_L39_00474A50[];
extern char D_L39_00474A68[];
extern char D_L39_00474A80[];
extern char D_L39_00474A98[];
extern char D_L39_00474AB0[];
extern char D_L39_00474AC8[];
extern s32 func_L39_004B7418(void);
extern s32 func_L39_004B4208(u8 *);
extern s32 func_L39_004B4310(u8 *);
extern long func_0012E188(u32, s32);
extern s32 func_L39_004CCD18(void *);
extern s32 func_L39_004CCBD8(s32);
extern s32 func_L39_004B8190(void **);
extern s32 func_L39_004B3100(s32, s32, s32);
extern void func_00120D28(void *, void *, s32);
extern s32 func_L39_004D5488(s32, s32, s32);
extern s32 func_L39_004B3160(s32, s32, s32, s32, s32, s32);
extern void func_L39_004D5B50(void);
extern void func_L39_004D5BE8(void);
extern s32 func_L39_004B7FF0(u32, u32);
extern s32 func_001262A0(s32);
extern void func_001260B0(s32);
extern void func_00126070(s32);
extern s32 func_00126270(s32);
extern void func_L39_004B7A80(s32);
extern void func_L39_004B76F8(void);

s32 func_L39_004B3230(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6) {
    S_004B3230_arg *arg = (S_004B3230_arg *)a0;
    S_004B3230_opt *opt = (S_004B3230_opt *)a6;
    u8 *b;
    u32 i;
    s32 ret;
    char *gate;
    char *ts;

    if (a3 > 0 || a3 < -0x41F) {
        return -9;
    }
    if (D_L39_00453FAC > 0) {
        return -7;
    }
    if (arg->version != 0x10000) {
        return -5;
    }
    if (func_L39_004B7418() < 0) {
        ret = -1;
        goto fail;
    }
    b = (u8 *)&D_L39_00453FB0_004B3230;
    for (i = 0; i <= 0x1073F; i++) {
        b[i] = 0;
    }
    func_L39_004B4208(arg->unk4);
    func_L39_004B4310(arg->unkC);
    if (opt != 0) {
        if (opt->unk0 > 0xE10) {
            ret = -10;
            goto fail;
        }
        D_L39_00453FB0_004B3230.unk410 = func_0012E188(opt->unk0, 0);
    }
    D_L39_00453FB0_004B3230.unk428 = a4;
    if (a4 > 0) {
        ret = func_L39_004CCD18(D_L39_00453FB0_004B3230.unk434);
        if (ret < 0) {
            goto fail;
        }
    } else {
        ret = func_L39_004CCBD8((s32)D_L39_00453FB0_004B3230.unk434);
        if (ret < 0) {
            goto fail;
        }
    }
    D_L39_00453FB0_004B3230.flags = (D_L39_00453FB0_004B3230.flags & ~1) | (arg->flags & 1);
    func_L39_004B8190(D_L39_00453FB0_004B3230.unk10710);
    D_L39_00453FB0_004B3230.sema[0] = func_L39_004B3100(0, 0xFF, (s32)D_L39_004749F0);
    if (D_L39_00453FB0_004B3230.sema[0] < 0) {
        ret = D_L39_00453FB0_004B3230.sema[0];
        goto fail;
    }
    D_L39_00453FB0_004B3230.sema[1] = func_L39_004B3100(0, 0xFF, (s32)D_L39_00474A08);
    if (D_L39_00453FB0_004B3230.sema[1] < 0) {
        ret = D_L39_00453FB0_004B3230.sema[1];
        goto fail;
    }
    D_L39_00453FB0_004B3230.sema[2] = func_L39_004B3100(0, 0xFF, (s32)D_L39_00474A20);
    if (D_L39_00453FB0_004B3230.sema[2] < 0) {
        ret = D_L39_00453FB0_004B3230.sema[2];
        goto fail;
    }
    D_L39_00453FB0_004B3230.sema[3] = func_L39_004B3100(1, 0xFF, (s32)D_L39_00474A38);
    if (D_L39_00453FB0_004B3230.sema[3] < 0) {
        ret = D_L39_00453FB0_004B3230.sema[3];
        goto fail;
    }
    D_L39_00453FB0_004B3230.sema[4] = func_L39_004B3100(0, 0xFF, (s32)D_L39_00474A50);
    if (D_L39_00453FB0_004B3230.sema[4] < 0) {
        ret = D_L39_00453FB0_004B3230.sema[4];
        goto fail;
    }
    D_L39_00453FB0_004B3230.sema[5] = func_L39_004B3100(0, 0xFF, (s32)D_L39_00474A68);
    if (D_L39_00453FB0_004B3230.sema[5] < 0) {
        ret = D_L39_00453FB0_004B3230.sema[5];
        goto fail;
    }
    D_L39_00453FB0_004B3230.sema[6] = func_L39_004B3100(0, 0xFF, (s32)D_L39_00474A80);
    if (D_L39_00453FB0_004B3230.sema[6] < 0) {
        ret = D_L39_00453FB0_004B3230.sema[6];
        goto fail;
    }
    if (opt != 0) {
        D_L39_00453FB0_004B3230.sema[7] = func_L39_004B3100(0, 0xFF, (s32)D_L39_00474A98);
    if (D_L39_00453FB0_004B3230.sema[7] < 0) {
        ret = D_L39_00453FB0_004B3230.sema[7];
        goto fail;
    }
    }
    if (a2 > 0) {
        D_L39_00453FB0_004B3230.unk10734 = a2;
    }
    if (a3 != 0) {
        D_L39_00453FB0_004B3230.unk10738 = a3;
    }
    D_L39_00453FB0_004B3230.unk404 = 0;
    DNAS_BEGIN(func_L39_004B3230, 0, func_L39_004BD350);
    gate = DNAS_STRING("gate1.eu.dnas.playstation.org");
    ts = DNAS_STRING("ts01.eu.dnas.playstation.org");
    if (D_L39_00453FB0_004B3230.unk10734 > 0) {
        func_00120D28(D_L39_00453FB0_004B3230.host, ts, 0x200);
    } else {
        func_00120D28(D_L39_00453FB0_004B3230.host, gate, 0x200);
    }
    DNAS_END(func_L39_004B3230, 0, func_L39_004BD350);
    ret = -107;
    D_L39_00453FB0_004B3230.unk1069C = D_L39_003D2B00;
    D_L39_00453FB0_004B3230.unk106A4 = D_L39_003D2F00;
    D_L39_00453FB0_004B3230.unk106AC = D_L39_003DAF38;
    if (func_L39_004D5488(0, -1, 0) < 0) {
        goto fail;
    }
    if (opt != 0) {
        D_L39_00453FB0_004B3230.unk424 = (s32)D_L39_003E3370;
        D_L39_00453FB0_004B3230.unk41C = func_L39_004B3160((s32)func_L39_004D5B50, (s32)D_L39_003E3370, 0x1000, opt->unk4, 0, (s32)D_L39_00474AB0);
    if (D_L39_00453FB0_004B3230.unk41C < 0) {
        ret = D_L39_00453FB0_004B3230.unk41C;
        goto fail;
    }
    }
    if ((D_L39_00453FB0_004B3230.unk420 = func_L39_004B7FF0(0x10, 0x10000)) == 0) {
        ret = -2;
        goto fail;
    }
    D_L39_00453FB0_004B3230.unk418 = func_L39_004B3160((s32)func_L39_004D5BE8, D_L39_00453FB0_004B3230.unk420, 0x10000, a1, 0, (s32)D_L39_00474AC8);
    if (D_L39_00453FB0_004B3230.unk418 < 0) {
        ret = D_L39_00453FB0_004B3230.unk418;
        goto fail;
    }
    func_001262A0(D_L39_00453FB0_004B3230.sema[0]);
    if (D_L39_00453FB0_004B3230.unk106DC < 0) {
        ret = D_L39_00453FB0_004B3230.unk106DC;
        goto fail;
    }
    D_L39_00453FAC = 1;
    return 0;

fail:
    if (D_L39_00453FB0_004B3230.unk418 > 0) {
        func_001260B0(D_L39_00453FB0_004B3230.unk418);
        func_00126070(D_L39_00453FB0_004B3230.unk418);
    }
    if (D_L39_00453FB0_004B3230.unk420 != 0) {
        func_L39_004B7A80(D_L39_00453FB0_004B3230.unk420);
    }
    if (D_L39_00453FB0_004B3230.sema[0] > 0) func_00126270(D_L39_00453FB0_004B3230.sema[0]);
    if (D_L39_00453FB0_004B3230.sema[1] > 0) func_00126270(D_L39_00453FB0_004B3230.sema[1]);
    if (D_L39_00453FB0_004B3230.sema[2] > 0) func_00126270(D_L39_00453FB0_004B3230.sema[2]);
    if (D_L39_00453FB0_004B3230.sema[3] > 0) func_00126270(D_L39_00453FB0_004B3230.sema[3]);
    if (D_L39_00453FB0_004B3230.sema[4] > 0) func_00126270(D_L39_00453FB0_004B3230.sema[4]);
    if (D_L39_00453FB0_004B3230.sema[5] > 0) func_00126270(D_L39_00453FB0_004B3230.sema[5]);
    if (D_L39_00453FB0_004B3230.sema[6] > 0) func_00126270(D_L39_00453FB0_004B3230.sema[6]);
    if (opt != 0) {
        if (D_L39_00453FB0_004B3230.unk41C > 0) {
            func_001260B0(D_L39_00453FB0_004B3230.unk41C);
            func_00126070(D_L39_00453FB0_004B3230.unk41C);
        }
        if (D_L39_00453FB0_004B3230.sema[7] > 0) func_00126270(D_L39_00453FB0_004B3230.sema[7]);
    }
    func_L39_004B76F8();
    return ret;
}
/* localdecomp:end func_L39_004B3230 */

/* localdecomp:start func_L39_004B3910 */
extern s32 func_L39_004B3230(s32, s32, s32, s32, s32, s32, s32);

s32 func_L39_004B3910(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    if (a0 == 0) {
        return -11;
    }
    return func_L39_004B3230(a0, a1, a2, a3, 1, 0, a4);
}
/* localdecomp:end func_L39_004B3910 */

LINKER_REMNANT("asm/levels", func_L39_004B3948);

/* localdecomp:start func_L39_004B3950 */
typedef struct {
    u8 pad0[0x10688];
    unsigned long flags;
    u8 pad1[0x4];
    s32 unk10694;
    u8 pad2[0x20];
    s32 unk106B8;
    u8 pad3[0xC];
    s32 unk106C8;
    u8 pad4[0x14];
    s32 unk106E0;
    u8 pad5[0x1C];
    s32 unk10700[3];
} S_004B3950;

extern s32 D_L39_00453FAC;
extern S_004B3950 D_L39_00453FB0_004B3950;
extern s32 func_L39_004CDC00(void);
extern s32 func_L39_004CDDD8(void);
extern s32 func_L39_004D58E0(void);
extern void func_L39_004D5900(void);
extern void func_L39_004D5928(void);
extern s32 func_001262A0(s32);
extern void func_00126280(s32);

s32 func_L39_004B3950(s32 arg) {
    S_004B3950 *p = &D_L39_00453FB0_004B3950;
    s32 *q = p->unk10700;
    s32 r;

    if (arg == 0) {
        return -11;
    }
    if (D_L39_00453FAC == 0) {
        return -8;
    }
    r = func_L39_004CDC00();
    if (r > 0) {
        r = func_L39_004CDDD8();
        if (r < 0) {
            return r;
        }
        if (r == 0) {
            return -0x194;
        }
    } else if (r < 0) {
        return r;
    }
    if (func_L39_004D58E0() == 0) {
        return -3;
    }
    p->unk10694 = arg;
    p->flags = (((p->flags & ~0x3800) | 0x800) & ~0x700);
    r = func_L39_004CDC00();
    if (r > 0) {
        if (!(D_L39_00453FB0_004B3950.unk106B8 & 1)) {
            p->flags = (p->flags & ~0xC000) | 0x8000;
        } else {
            p->flags = p->flags & ~0xC000;
        }
    } else if (r != 0) {
        return r;
    } else {
        p->flags = p->flags & ~0xC000;
    }
    p->unk106E0 = 1;
    func_001262A0(D_L39_00453FB0_004B3950.unk106C8);
    q[0] = 9;
    q[2] = 1;
    func_00126280(D_L39_00453FB0_004B3950.unk106C8);
    func_L39_004D5900();
    func_L39_004D5928();
    return 0;
}
/* localdecomp:end func_L39_004B3950 */

/* localdecomp:start func_L39_004B3B18 */
typedef struct {
    u8 pad0[0x410];
    long unk410;           /* 0x410 */
    s32 unk418;            /* 0x418 */
    s32 unk41C;            /* 0x41C */
    s32 unk420;            /* 0x420 */
    u8 pad424[0x106BC - 0x424];
    s32 sema[8];           /* 0x106BC */
    u8 pad106DC[0x106F0 - 0x106DC];
    s32 unk106F0;          /* 0x106F0 */
} S_004B3B18;

extern s32 D_L39_00453FAC;
extern S_004B3B18 D_L39_00453FB0_004B3B18;
extern s32 func_L39_004CCE58(void);
extern s32 func_L39_004D58E0(void);
extern s32 func_L39_004D58F0(void);
extern void func_L39_004D5900(void);
extern void func_L39_004D5928(void);
extern void func_L01_004126A8(s32);
extern void func_L39_004B7A80(s32);
extern s32 func_L39_004D0C78(void);
extern void func_L39_004B76F8(void);
extern s32 func_001262A0(s32);
extern void func_00126280(s32);
extern void func_001260B0(s32);
extern void func_00126070(s32);
extern s32 func_00126270(s32);

s32 func_L39_004B3B18(void) {
    u8 *b;
    u32 i;
    s32 r;

    func_L39_004CCE58();
    if (D_L39_00453FAC != 0 && D_L39_00453FB0_004B3B18.unk106F0 <= 0) {
        func_001262A0(D_L39_00453FB0_004B3B18.sema[6]);
        func_00126280(D_L39_00453FB0_004B3B18.sema[6]);
        if (func_L39_004D58E0() == 0) {
            return -3;
        }
        D_L39_00453FB0_004B3B18.unk106F0 = 1;
        if (func_L39_004D58E0() > 0) {
            func_L39_004D5900();
        } else if (func_L39_004D58F0() > 0) {
            func_L39_004D5928();
        }
        func_001262A0(D_L39_00453FB0_004B3B18.sema[4]);
        if (D_L39_00453FB0_004B3B18.unk410 != 0) {
            func_001260B0(D_L39_00453FB0_004B3B18.unk41C);
            func_L01_004126A8(D_L39_00453FB0_004B3B18.unk41C);
            func_00126070(D_L39_00453FB0_004B3B18.unk41C);
            if (D_L39_00453FB0_004B3B18.sema[7] > 0) {
                func_00126270(D_L39_00453FB0_004B3B18.sema[7]);
            }
        }
        func_001260B0(D_L39_00453FB0_004B3B18.unk418);
        func_00126070(D_L39_00453FB0_004B3B18.unk418);
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[0])) != D_L39_00453FB0_004B3B18.sema[0]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[1])) != D_L39_00453FB0_004B3B18.sema[1]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[2])) != D_L39_00453FB0_004B3B18.sema[2]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[3])) != D_L39_00453FB0_004B3B18.sema[3]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[4])) != D_L39_00453FB0_004B3B18.sema[4]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[5])) != D_L39_00453FB0_004B3B18.sema[5]) return r;
        if ((r = func_00126270(D_L39_00453FB0_004B3B18.sema[6])) != D_L39_00453FB0_004B3B18.sema[6]) return r;
        if (D_L39_00453FB0_004B3B18.unk420 != 0) {
            func_L39_004B7A80(D_L39_00453FB0_004B3B18.unk420);
        }
        b = (u8 *)&D_L39_00453FB0_004B3B18;
        for (i = 0; i <= 0x1073F; i++) {
            b[i] = (u32)((f32)func_L39_004D0C78() / 2147483647.0f * 256.0f);
        }
        func_L39_004B76F8();
        D_L39_00453FAC = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004B3B18 */

/* localdecomp:start func_L39_004B3E10 */
typedef struct {
    u8 pad0[0x418];
    s32 sock;             /* 0x418 */
    u8 pad41c[0x106C8 - 0x41C];
    s32 h106C8;           /* 0x106C8 */
    s32 pad106CC;
    s32 h106D0;           /* 0x106D0 */
    u8 pad106D4[0x106F4 - 0x106D4];
    s32 f106F4;           /* 0x106F4 */
    u8 pad106F8[0x10728 - 0x106F8];
    s32 (*cb)(void);      /* 0x10728 */
} S_004B3E10;
extern s32 D_L39_00453FAC;
extern S_004B3E10 D_L39_00453FB0_004B3E10;
extern s32 func_L39_004D58E0(void);
extern s32 func_L39_004D58F0(void);
extern s32 func_00126160(s32, s32 *);
extern s32 func_001262A0(s32 a0);
extern void func_00126280(s32 a0);
extern s32 func_001262B0(s32);

s32 func_L39_004B3E10(void) {
    s32 buf[12];
    s32 r;

    if (D_L39_00453FAC == 0) {
        return -8;
    }
    if (func_L39_004D58E0() > 0 || func_L39_004D58F0() > 0) {
        r = func_00126160(D_L39_00453FB0_004B3E10.sock, buf);
        if (r < 0) {
            return r;
        }
        if (buf[0] != 2) {
            return -6;
        }
        func_001262A0(D_L39_00453FB0_004B3E10.h106C8);
        D_L39_00453FB0_004B3E10.f106F4 = 1;
        func_00126280(D_L39_00453FB0_004B3E10.h106C8);
        return 0;
    }
    func_001262A0(D_L39_00453FB0_004B3E10.h106C8);
    D_L39_00453FB0_004B3E10.f106F4 = 1;
    func_00126280(D_L39_00453FB0_004B3E10.h106C8);
    if (func_001262B0(D_L39_00453FB0_004B3E10.h106D0) >= 0 && D_L39_00453FB0_004B3E10.cb() < 0) {
        return -6;
    }
    return 0;
}
/* localdecomp:end func_L39_004B3E10 */

/* localdecomp:start func_L39_004B3F28 */
extern s32 D_L39_00453FAC;
extern u8 D_L39_004646B0[];

s32 func_L39_004B3F28(u8 *p)
{
    s32 saved = *(s32 *)(p + 0xC);
    u8 *src;
    u32 i;

    if (p == 0) {
        return -11;
    }
    if (D_L39_00453FAC == 0) {
        return -8;
    }
    src = D_L39_004646B0;
    for (i = 0; i < 16; i++) {
        p[i] = src[i];
    }
    *(s32 *)(p + 0xC) = saved;
    return 0;
}
/* localdecomp:end func_L39_004B3F28 */

/* localdecomp:start func_L39_004B3F88 */
typedef struct {
    u8 pad0[0x204];
    s8 buf[0x200];
    s32 mode;
    u16 len;
} S_004B3F88;

extern s32 D_L39_00453FAC;
extern S_004B3F88 D_L39_00453FB0;
extern void func_00120D28(void *, void *, s32);

s32 func_L39_004B3F88(s32 mode, void *src, u16 len)
{
    if (src == 0 || len == 0) {
        return -11;
    }
    if (D_L39_00453FAC == 0) {
        return -8;
    }
    if (mode == 1) {
        func_00120D28(D_L39_00453FB0.buf, src, 0x200);
        D_L39_00453FB0.len = len;
        if (D_L39_00453FB0.buf[0x1FF] != 0) {
            return -5;
        }
        D_L39_00453FB0.mode = mode;
    } else {
        D_L39_00453FB0.mode = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004B3F88 */

/* localdecomp:start func_L39_004B4020 */
s32 func_L39_004B4020(s32 *mode, void *dst, s32 size, u16 *len)
{
    if (dst == 0 || len == 0 || size <= 0) {
        return -11;
    }
    if (D_L39_00453FAC == 0) {
        return -8;
    }
    if (D_L39_00453FB0.mode != 0) {
        *mode = D_L39_00453FB0.mode;
        /* func_00120D28 copies like memcpy and returns a pointer: the void declaration of the file gives $v0 for the lhu below */
        ((void *(*)(void *, void *, s32))func_00120D28)(dst, D_L39_00453FB0.buf, size);
        *len = D_L39_00453FB0.len;
    } else {
        *mode = 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004B4020 */

/* localdecomp:start func_L39_004B40C8 */
extern u32 func_L39_004B5938(u32);

s32 func_L39_004B40C8(u16 *s)
{
    s[0] = func_L39_004B5938(2);
    s[1] = func_L39_004B5938(5);
    return 4;
}
/* localdecomp:end func_L39_004B40C8 */

/* localdecomp:start func_L39_004B4108 */
extern u8 D_L39_004543DC[];

s32 func_L39_004B4108(u8 *a0) {
    u8 *src;
    u32 i;

    DNAS_BEGIN(func_L39_004B4108, 0, func_L39_004BD350);
    src = D_L39_004543DC;
    for (i = 0; i < 8; i++) {
        a0[i] = src[i];
    }
    DNAS_END(func_L39_004B4108, 0, func_L39_004BD350);
    return 8;
}
/* localdecomp:end func_L39_004B4108 */

/* localdecomp:start func_L39_004B4208 */
extern u8 D_L39_004543DC[];

s32 func_L39_004B4208(u8 *a0) {
    u8 *dst = D_L39_004543DC;
    u32 i;

    DNAS_BEGIN(func_L39_004B4208, 0, func_L39_004BD350);
    for (i = 0; i < 8; i++) {
        dst[i] = a0[i];
    }
    DNAS_END(func_L39_004B4208, 0, func_L39_004BD350);
    return 8;
}
/* localdecomp:end func_L39_004B4208 */

/* localdecomp:start func_L39_004B4310 */
extern u8 D_L39_004543E4[];

s32 func_L39_004B4310(u8 *a0) {
    u8 *dst = D_L39_004543E4;
    u32 i;

    DNAS_BEGIN(func_L39_004B4310, 0, func_L39_004BD350);
    for (i = 0; i < 0x10000; i++) {
        dst[i] = a0[i];
    }
    DNAS_END(func_L39_004B4310, 0, func_L39_004BD350);
    return 0x10000;
}
/* localdecomp:end func_L39_004B4310 */

/* localdecomp:start func_L39_004B4420 */
extern u8 D_L39_004644F4[];

s32 func_L39_004B4420(u8 *a0) {
    u8 *src;
    u32 i;

    DNAS_BEGIN(func_L39_004B4420, 0, func_L39_004BD350);
    src = D_L39_004644F4;
    for (i = 0; i < 0x20; i++) {
        a0[i] = src[i];
    }
    DNAS_END(func_L39_004B4420, 0, func_L39_004BD350);
    return 0x20;
}
/* localdecomp:end func_L39_004B4420 */

/* localdecomp:start func_L39_004B4520 */
extern u8 D_L39_004644F4[];

s32 func_L39_004B4520(u8 *a0) {
    u8 *dst;
    u32 i;

    DNAS_BEGIN(func_L39_004B4520, 0, func_L39_004BD350);
    dst = D_L39_004644F4;
    for (i = 0; i < 0x20; i++) {
        dst[i] = a0[i];
    }
    DNAS_END(func_L39_004B4520, 0, func_L39_004BD350);
    return 0x20;
}
/* localdecomp:end func_L39_004B4520 */

/* localdecomp:start func_L39_004B4620 */
extern u8 D_L39_00464634;

s32 func_L39_004B4620(u8 *a0) {
    DNAS_BEGIN(func_L39_004B4620, 0, func_L39_004BD350);
    D_L39_00464634 = *a0;
    DNAS_END(func_L39_004B4620, 0, func_L39_004BD350);
    return 1;
}
/* localdecomp:end func_L39_004B4620 */

/* localdecomp:start func_L39_004B4700 */
extern u8 D_L39_00464514[];

s32 func_L39_004B4700(u8 *a0) {
    u8 *dst;
    u32 i;

    DNAS_BEGIN(func_L39_004B4700, 0, func_L39_004BD350);
    dst = D_L39_00464514;
    for (i = 0; i < 0x120; i++) {
        dst[i] = a0[i];
    }
    DNAS_END(func_L39_004B4700, 0, func_L39_004BD350);
    return 0x120;
}
/* localdecomp:end func_L39_004B4700 */

/* localdecomp:start func_L39_004B4800 */
extern u8 D_L39_00464635;

s32 func_L39_004B4800(u8 *a0) {
    DNAS_BEGIN(func_L39_004B4800, 0, func_L39_004BD350);
    D_L39_00464635 = *a0;
    DNAS_END(func_L39_004B4800, 0, func_L39_004BD350);
    return 1;
}
/* localdecomp:end func_L39_004B4800 */

/* localdecomp:start func_L39_004B48E0 */
/* log: same form as func_L39_004B4620 in this file; first try */
extern u8 D_L39_00464636;

s32 func_L39_004B48E0(u8 *a0) {
    DNAS_BEGIN(func_L39_004B48E0, 0, func_L39_004BD350);
    D_L39_00464636 = *a0;
    DNAS_END(func_L39_004B48E0, 0, func_L39_004BD350);
    return 1;
}
/* localdecomp:end func_L39_004B48E0 */

/* localdecomp:start func_L39_004B49C0 */
extern u8 D_L39_00464649;

s32 func_L39_004B49C0(u8 *a0) {
    DNAS_BEGIN(func_L39_004B49C0, 0, func_L39_004BD350);
    D_L39_00464649 = *a0;
    DNAS_END(func_L39_004B49C0, 0, func_L39_004BD350);
    return 1;
}
/* localdecomp:end func_L39_004B49C0 */

/* localdecomp:start func_L39_004B4AA0 */
extern u8 D_L39_00464638[];

s32 func_L39_004B4AA0(u8 *a0) {
    u8 *src;
    s32 i;

    DNAS_BEGIN(func_L39_004B4AA0, 0, func_L39_004BD350);
    src = D_L39_00464638;
    for (i = 0; i < 2; i++) {
        a0[i] = src[i];
    }
    DNAS_END(func_L39_004B4AA0, 0, func_L39_004BD350);
    return 2;
}
/* localdecomp:end func_L39_004B4AA0 */

/* localdecomp:start func_L39_004B4BA0 */
extern u16 *D_L39_00464640;

s32 func_L39_004B4BA0(u8 *a0) {
    DNAS_BEGIN(func_L39_004B4BA0, 0, func_L39_004BD350);
    *(u16 *)a0 = func_L39_004B5938(*D_L39_00464640);
    DNAS_END(func_L39_004B4BA0, 0, func_L39_004BD350);
    return 2;
}
/* localdecomp:end func_L39_004B4BA0 */

/* localdecomp:start func_L39_004B4C88 */
typedef struct {
    u8 pad0[4];
    u8 b[6];
} S_004B4C88;

s32 func_L39_004B4C88(u8 *a0, u8 *a1) {
    S_004B4C88 *s = (S_004B4C88 *)a1;
    s32 i;

    DNAS_BEGIN(func_L39_004B4C88, 0, func_L39_004BD350);
    for (i = 0; i < 6; i++) {
        a0[i] = s->b[i];
    }
    DNAS_END(func_L39_004B4C88, 0, func_L39_004BD350);
    return 6;
}
/* localdecomp:end func_L39_004B4C88 */

/* localdecomp:start func_L39_004B4D90 */
/* log: struct view of a1 (6-byte field at 4), the copy of func_L39_004B4C88 turned round */
typedef struct {
    u8 pad0[4];
    u8 b[6];
} S_004B4D90;

s32 func_L39_004B4D90(u8 *a0, u8 *a1) {
    S_004B4D90 *s = (S_004B4D90 *)a1;
    s32 i;

    DNAS_BEGIN(func_L39_004B4D90, 0, func_L39_004BD350);
    for (i = 0; i < 6; i++) {
        s->b[i] = a0[i];
    }
    DNAS_END(func_L39_004B4D90, 0, func_L39_004BD350);
    return 6;
}
/* localdecomp:end func_L39_004B4D90 */

/* localdecomp:start func_L39_004B4E98 */
typedef struct {
    u8 pad0[0x10];
    u8 *buf;
} S_004B4E98;

extern u32 func_L39_004B5910(u32);

static __inline__ void copy_004B4E98(u8 *dst, u8 *src, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

/* from func_L39_004B54C8 in this file (the same code with the buffer field at 8) */
s32 func_L39_004B4E98(u8 *src, S_004B4E98 *dst) {
    u32 v;
    s32 ret;
    u32 r;

    DNAS_BEGIN(func_L39_004B4E98, 0, func_L39_004BD350);
    ret = 4;
    copy_004B4E98((u8 *)&v, src, 4);
    r = func_L39_004B5910(v);
    v = r;
    if (r == 0 || v > 0x8000) {
        ret = -106;
    } else {
        copy_004B4E98(dst->buf, (u8 *)&v, 4);
    }
    DNAS_END(func_L39_004B4E98, 0, func_L39_004BD350);
    return ret;
}
/* localdecomp:end func_L39_004B4E98 */

/* localdecomp:start func_L39_004B5000 */
typedef struct {
    u8 pad0[0xC];
    u8 *buf;
    s32 *len;
} S_004B5000;

s32 func_L39_004B5000(u8 *a0, S_004B5000 *a1) {
    u8 *buf;
    s32 n;
    s32 i;

    DNAS_BEGIN(func_L39_004B5000, 0, func_L39_004BD350);
    buf = a1->buf;
    n = *a1->len;
    for (i = 0; i < n; i++) {
        buf[i] = a0[i];
    }
    DNAS_END(func_L39_004B5000, 0, func_L39_004BD350);
    return n;
}
/* localdecomp:end func_L39_004B5000 */

/* localdecomp:start func_L39_004B5118 */
extern u32 func_L39_004B5910(u32);
extern u32 *D_L39_00464644;

s32 func_L39_004B5118(u32 *a0) {
    DNAS_BEGIN(func_L39_004B5118, 0, func_L39_004BD350);
    *a0 = func_L39_004B5910(*D_L39_00464644);
    DNAS_END(func_L39_004B5118, 0, func_L39_004BD350);
    return 4;
}
/* localdecomp:end func_L39_004B5118 */

/* localdecomp:start func_L39_004B5200 */
s32 func_L39_004B5200(u8 *a0, u8 *a1) {
    u32 i;

    DNAS_BEGIN(func_L39_004B5200, 0, func_L39_004BD350);
    for (i = 0; i < 0x80; i++) {
        a0[i] = a1[i];
    }
    DNAS_END(func_L39_004B5200, 0, func_L39_004BD350);
    return 0x80;
}
/* localdecomp:end func_L39_004B5200 */

/* localdecomp:start func_L39_004B5308 */
/* log: same form as func_L39_004B4620 in this file; first try */
extern u8 D_L39_0046464A;

s32 func_L39_004B5308(u8 *a0) {
    DNAS_BEGIN(func_L39_004B5308, 0, func_L39_004BD350);
    D_L39_0046464A = *a0;
    DNAS_END(func_L39_004B5308, 0, func_L39_004BD350);
    return 1;
}
/* localdecomp:end func_L39_004B5308 */

/* localdecomp:start func_L39_004B53E8 */
extern u8 D_L39_00464648;

s32 func_L39_004B53E8(u8 *a0) {
    DNAS_BEGIN(func_L39_004B53E8, 0, func_L39_004BD350);
    D_L39_00464648 = *a0;
    DNAS_END(func_L39_004B53E8, 0, func_L39_004BD350);
    return 1;
}
/* localdecomp:end func_L39_004B53E8 */

/* localdecomp:start func_L39_004B54C8 */
typedef struct {
    u8 pad0[8];
    u8 *buf;
} S_004B54C8;

extern u32 func_L39_004B5910(u32);

static __inline__ void copy_004B54C8(u8 *dst, u8 *src, u32 n) {
    u32 i;
    for (i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

s32 func_L39_004B54C8(u8 *src, S_004B54C8 *dst) {
    u32 v;
    s32 ret;
    u32 r;

    DNAS_BEGIN(func_L39_004B54C8, 0, func_L39_004BD350);
    ret = 4;
    copy_004B54C8((u8 *)&v, src, 4);
    r = func_L39_004B5910(v);
    v = r;
    if (r == 0 || v > 0x8000) {
        ret = -106;
    } else {
        copy_004B54C8(dst->buf, (u8 *)&v, 4);
    }
    DNAS_END(func_L39_004B54C8, 0, func_L39_004BD350);
    return ret;
}
/* localdecomp:end func_L39_004B54C8 */

/* localdecomp:start func_L39_004B5630 */
typedef struct {
    u8 pad0[0x4];
    u8 *buf;
    s32 *len;
} S_004B5630;

s32 func_L39_004B5630(u8 *a0, S_004B5630 *a1) {
    u8 *buf;
    s32 n;
    s32 i;

    DNAS_BEGIN(func_L39_004B5630, 0, func_L39_004BD350);
    buf = a1->buf;
    n = *a1->len;
    for (i = 0; i < n; i++) {
        buf[i] = a0[i];
    }
    DNAS_END(func_L39_004B5630, 0, func_L39_004BD350);
    return n;
}
/* localdecomp:end func_L39_004B5630 */

/* localdecomp:start func_L39_004B5748 */
static __inline__ void bcopy_004B5748(void *src, void *dst, u32 n) {
    u8 *s = src;
    u8 *d = dst;
    u32 k = 0;
    do {
        d[k] = s[k];
        if (++k >= n) {
            break;
        }
    } while (1);
}

s32 func_L39_004B5748(u8 *src, s32 *out) {
    u8 code;

    DNAS_BEGIN(func_L39_004B5748, 0, func_L39_004BD350);
    bcopy_004B5748(src, &code, 1);
    switch (code) {
    case 0:
        *out = -108;
        break;
    case 1:
        *out = -101;
        break;
    case 2:
        *out = -102;
        break;
    case 3:
        *out = -103;
        break;
    case 4:
        *out = -104;
        break;
    case 5:
        *out = -105;
        break;
    case 9:
        *out = -110;
        break;
    case 0x60:
        if (!(D_L39_00453FB0_004B3950.unk106B8 & 1)) {
            *out = -109;
            D_L39_00453FB0_004B3950.unk106B8 |= 1;
            break;
        }
        /* fall through */
    default:
        *out = -800 - code;
        break;
    }
    DNAS_END(func_L39_004B5748, 0, func_L39_004BD350);
    return 1;
}
/* localdecomp:end func_L39_004B5748 */
