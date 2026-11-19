#include "common.h"

typedef struct { u8 pad0[0xF4]; u8 *p; } O_A;

/* localdecomp:start func_L39_006879E0 */
typedef struct S_006879E0_obj {
    u8 pad0[0xE0];
    s32 fE0;
    u8 padE4[0x1C0 - 0xE4];
    s32 kinds[44];
    s32 f270;
    u8 pad274[0x284 - 0x274];
    s32 f284;
} S_006879E0_obj;

typedef struct S_006879E0_slot {
    u8 pad0[0xA4];
    u8 *fA4;
    u8 padA8[0x284 - 0xA8];
    s32 f284;
} S_006879E0_slot;

extern s32 D_L39_003D2880[];
__asm__(".extern D_L39_0024D760, 16");
extern s32 *D_L39_0024D760;
extern s32 D_L39_0024D770;
extern s32 D_001E2060_sda;
extern u8 *D_001E2050_sda;
__asm__(".extern D_001DC204_sda, 4");
extern S_006879E0_slot *D_001DC204_sda;
extern char D_L39_002479B0[];
extern char D_L39_002479B8[];
extern char D_L39_002479C0[];
extern void func_L01_00516AA0(int, int, int);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_003825F8(s32, s32, s32, s32, s32, s32);
extern s32 func_L39_0067F7B0(void);
extern void func_L39_0067F6E8(s32 *, u8 *);
extern s32 func_L39_006CEA18(void *, s32);
extern s32 func_00381FF0(s32);
extern s32 func_00120048();
extern s32 func_001200E0();
extern void func_00120D28(char *, char *, s32);
extern s32 func_00120884(s32);
extern void func_L39_006D2EF0(void *arg0, s32 arg1, s32 arg2);
extern s32 func_L39_006DC228(s32, s32, s32, s32 *);
extern void func_L39_006BD408(s32, s32);
extern u8 *func_L39_006D4380(s32, s32);
extern u8 *func_L39_006DE380(s32, s32, s32);
extern void *func_L39_006CC120(void *object);
extern void func_L39_006CC4F8(void *, void *);
extern s32 func_L39_006CC350(s32 *a0, s32 a1);
extern void func_L39_006CC158(void *, s32);
extern s32 func_L39_006876A0(void *a0, s32 a1, void *a2, void *a3, void *a4);
extern void func_L39_006D9E68(s32, s32, char *, s32);


s32 func_L39_006879E0(S_006879E0_obj *arg0, s32 arg1) {
    s32 slot;
    s32 id;
    s32 v498;
    s32 v49C;
    s32 flag;
    s32 show;
    s32 ret;
    s32 k;
    s32 ok;

    flag = 0;
    ret = 0;
    k = arg0->kinds[arg0->f270];
    if (k == 0 || k == 2 || k == 0x12 || k == 0x14 || k == 0x15 || k == 0x16 || k == 0x18 ||
        k == 0x1D || k == 0x21) {
        flag = 1;
        func_L01_00516AA0(D_L39_003D2880[0x44 / 4], 1, 0);
        func_L01_00516AA0(D_L39_003D2880[0x4C / 4], 1, 0);
        func_L01_00516AA0(D_L39_003D2880[0x48 / 4], 1, 0);
    }
    if (flag == 1) {
        func_L39_0067F7B0();
        ok = D_L39_0024D770;
    } else {
        ok = D_001E2060_sda;
    }
    if (ok != 0) {
    show = 0;
    k = arg0->kinds[arg0->f270];
    if (k == 3 || k == 4 || k == 0xC || k == 5 || k == 6 || k == 7 || k == 8 || k == 9 ||
        k == 0xA || k == 0xF || k == 0x10 || k == 0x19 || k == 0x1B || k == 0x1E || k == 0x1F ||
        k == 0x20 || k == 0x23) {
        show = 1;
    }
    if (show == 1) {
        u8 line[0x70];
        char msg[0x70];
        s32 color;

        color = func_003825F8(0x8066CCFF, 0x80FFFFFF, 0x32, 0, 0, 0);
        func_L01_005170B8(D_L39_003D2880[0x44 / 4], color);
        func_L01_00516AA0(D_L39_003D2880[0x44 / 4], 1, 1);
        func_L01_00516AA0(D_L39_003D2880[0x4C / 4], 1, 1);
        func_L01_00516AA0(D_L39_003D2880[0x48 / 4], 1, 1);
        func_L01_00517538(D_L39_003D2880[0x34 / 4], 0.85f, 1.0f);
        func_L01_00517538(D_L39_003D2880[0x38 / 4], 0.85f, 1.0f);
        if (arg1 == 9) {
        func_L39_0067F6E8(&slot, line);
        if (line[0] == 'C') {
            {
                char name[0x100];
                u8 *o;
                s32 owner;

                o = (u8 *)D_L39_0024D760[0x38 / 4];
                func_L39_006CEA18(o, 0);
                func_001200E0(line + 1, D_L39_002479B0, &id);
                owner = *(s32 *)o;
                func_00120048(name, func_00381FF0(0x1696), line + 9);
                if (owner >= 0 && id >= 0) {
                    if (((s32 (*)(void *, s32, char *, s32, char *))func_L39_006876A0)(arg0, func_00381FF0(0xFE0), name, 0x18, 0) == 8) {
                        if (o[0x34] != 0) {
                            func_L39_006D2EF0(o, id, slot);
                        }
                        if (func_L39_006DC228(D_L39_0024D760[0x4C / 4], id, owner, &v498) != 0) {
                            if (arg0->fE0 != 0) {
                                func_L39_006BD408(arg0->fE0, v498);
                                arg0->f284 = 0x1F;
                            }
                            return 1;
                        }
                    } else if (o[0x34] != 0) {
                        func_00120048(msg, D_L39_002479B8, 0x4D, func_00381FF0(0x1699));
                        func_L39_006D9E68(D_L39_0024D760[0x48 / 4], slot, msg, 0);
                    }
                }
                ret = 1;
            }
        } else if (line[0] == 'V') {
            {
                u8 name[0x11];
                u8 title[0x21];
                char text[0xD0];
                s32 state[0x78];
                u8 *p;
                u8 *o;
                u8 *q;
                s32 t;
                s32 r;
                u8 *dst;

                func_001200E0(line + 1, D_L39_002479B0, &v49C);
                func_00120D28(name, line + 9, 0x10);
                name[0x10] = 0;
                func_00120D28(title, line + 0x19, 0x20);
                title[0x20] = 0;
                for (p = &name[0x10]; p >= name && *p <= ' '; p--) {
                    *p = 0;
                }
                for (p = &title[0x20]; p >= title && *p <= ' '; p--) {
                    *p = 0;
                }
                func_00120048(text, func_00381FF0(0x1331), title);
                if (name[0] != 0) {
                    s32 n = func_00120884((s32)text);
                    text[n] = 1;
                    text[n + 1] = 1;
                    func_00120048(&text[n + 2], func_00381FF0(0x16DA), name);
                }
                if (((s32 (*)(void *, s32, char *, s32, char *))func_L39_006876A0)(arg0, func_00381FF0(0xFE0), text, 0x18, 0) == 8) {
                    o = func_L39_006D4380(D_L39_0024D760[0x3C / 4], v49C);
                    if (o != 0) {
                        t = 0;
                        q = func_L39_006DE380(*(s32 *)(D_001E2050_sda + 0x54), 0, v49C);
                        if (q != 0) {
                            t = *(s32 *)(q + 0x24);
                        }
                        dst = D_001DC204_sda->fA4;
                        func_L39_006CC120(state);
                        func_L39_006CC4F8(state, o);
                        r = func_L39_006CC350(state, 2);
                        {
                            s32 a = *(s32 *)(o + 0x188);
                            s32 id = v49C;
                            S_006879E0_slot *s = D_001DC204_sda;
                            *(s32 *)(dst + 0x2A8) = id;
                            *(s32 *)(dst + 0x2AC) = t;
                            *(s32 *)(dst + 0x2B0) = r;
                            *(s32 *)(dst + 0x2B4) = a;
                            s->f284 = 0x10;
                        }
                        func_L39_006CC158(state, 2);
                    }
                }
            }
        } else if (line[0] == 'I') {
            {
                u8 name[0x21];
                char text[0x70];
                u8 *p;

                func_00120D28(name, line + 1, 0x20);
                name[0x20] = 0;
                for (p = &name[0x20]; p >= name && *p <= ' '; p--) {
                    *p = 0;
                }
                func_00120048(text, D_L39_002479C0, name, func_00381FF0(0x1170));
                ((s32 (*)(void *, s32, char *, s32, char *))func_L39_006876A0)(arg0, func_00381FF0(0xFE0), text, 5, 0);
            }
        } else {
            msg[1] = 0;
            msg[0] = 'M';
            if (((s32 (*)(void *, s32, char *, s32, char *))func_L39_006876A0)(arg0, func_00381FF0(0xFE0), line + 1, 5, msg + 1) == 4) {
                func_L39_006D9E68(D_L39_0024D760[0x48 / 4], slot, msg, 0);
            }
        }
        ret = 1;
        }
    } else {
    func_L01_00516AA0(D_L39_003D2880[0x44 / 4], 1, 0);
    func_L01_00516AA0(D_L39_003D2880[0x4C / 4], 1, 0);
    func_L01_00516AA0(D_L39_003D2880[0x48 / 4], 1, 0);
    func_L01_00517538(D_L39_003D2880[0x34 / 4], 1.0f, 1.0f);
    func_L01_00517538(D_L39_003D2880[0x38 / 4], 1.0f, 1.0f);
    }
    }
    return ret;
}
/* localdecomp:end func_L39_006879E0 */

/* localdecomp:start func_L39_00688108 */
typedef struct S_00688108_in {
    s32 w[14];
} S_00688108_in;

typedef struct S_00688108_buf {
    S_00688108_in in;
    s32 w38;
    s32 w3C;
} S_00688108_buf;

typedef struct S_00688108_obj {
    u8 pad0[0x110];
    s32 ids[44];
    s32 kinds[44];
    s32 f270;
    u8 pad274[0x27C - 0x274];
    s32 f27C;
} S_00688108_obj;

typedef struct S_00688108_slot {
    u8 pad0[0x64];
    u8 *f64;
    u8 pad68[0x27C - 0x68];
    s32 f27C;
    u8 f280;
    u8 pad281[3];
    s32 f284;
} S_00688108_slot;

__asm__(".extern D_001DC204_sda, 4");
__asm__(".extern D_L39_0024D760, 16");
extern s32 func_L39_006D40B0(s32);
extern s32 func_L01_003A4720(s32);
extern void func_L39_006DCAD0(s32, s32);
extern void func_L39_006D8E30(void *);
extern void func_198578(void);
extern void *func_1375B0(void *, void *, s32);
extern s32 func_L39_0067EB98(void);
extern void func_195410(void);
extern void func_L39_00689AC8(s32, void *);
extern int func_L39_0067EBD0(void);
extern void func_199050(void);
extern void func_198560(void);

void func_L39_00688108(S_00688108_obj *arg0, S_00688108_in *arg1, void *arg2) {
    S_00688108_buf buf;
    S_00688108_buf *b = &buf;
    s32 saved;
    S_00688108_slot *slot;
    s32 *g;
    u8 *p;
    s32 idx;
    s32 v;
    s32 k;

    slot = (S_00688108_slot *)D_001DC204_sda;
    b->in = *arg1;
    v = slot->f280;
    g = D_L39_0024D760;
    slot->f280 = 1;
    p = slot->f64;
    saved = v;
    v = func_L39_006D40B0(D_L39_0024D760[0x3C / 4]);
    if (p[0x2B9] != 0) {
        func_L01_003A4720(g[0x30 / 4]);
    }
    if (p[0x2B8] != 0) {
        func_L39_006DCAD0(g[0x50 / 4], 0);
    }
    func_L39_006D8E30(D_001E2050_sda);
    func_198578();
    func_1375B0(b, arg2, 0x40);
    if (b->in.w[0x30 / 4] != 5) {
        func_L39_0067EB98();
    }
    do {
        func_195410();
        func_1375B0(b, arg2, 0x40);
        idx = arg0->f270;
        k = arg0->kinds[idx];
        if (k != 0x23 && k != 0x20 && k != 0xA && k != 4 && k != 0x1F && k != 0xF && k != 0xC) {
            func_L39_00689AC8(arg0->ids[idx], arg2);
        }
        if (func_L39_0067EBD0() > 30000) {
            break;
        }
    } while (b->in.w[0x30 / 4] != 5);
    D_001DC204_sda->f284 = 0x18;
    arg0->f27C = 0;
    func_199050();
    func_198560();
    ((S_00688108_slot *)D_001DC204_sda)->f280 = saved;
}
/* localdecomp:end func_L39_00688108 */
