#include "common.h"

/* NTSC-U counterpart of func_L39_006879E0 (src/levels/39_multiplayer_menu/L39_006879E0.c) */
/* localdecomp:start func_L39_00684EC0 */
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

extern s32 D_L39_003D2980[];
__asm__(".extern D_L39_0024D860, 16");
extern s32 *D_L39_0024D860;
extern s32 D_L39_0024D870_00684EC0;
extern s32 D_001E1FE0_sda;
extern u8 *D_001E1FD0_sda;
__asm__(".extern D_001DC1E4_sda, 4");
extern S_006879E0_slot *D_001DC1E4_sda;
extern char D_L39_00247B10_00684EC0[];
extern char D_L39_00247B18_00684EC0[];
extern char D_L39_00247B20[];
extern void func_L01_00512AB0(int, int, int);
extern s32 func_L01_005130C8(s32, s32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_0037E368(s32, s32, s32, s32, s32, s32);
extern s32 func_L39_0067CC90(void);
extern void func_L39_0067CBC8(s32 *, u8 *);
extern s32 func_L39_006CC290(void *, s32);
extern s32 func_0037DF98(s32);
extern s32 func_00120048();
extern s32 func_001200E0();
extern void func_00120D28(char *, char *, s32);
extern s32 func_00120884(s32);
extern void func_L39_006D0768(void *arg0, s32 arg1, s32 arg2);
extern s32 func_L39_006D96D0(s32, s32, s32, s32 *);
extern void func_L39_006BA8F0(s32, s32);
extern u8 *func_L39_006D1BF8_00684EC0(s32, s32);
extern u8 *func_L39_006DB820(s32, s32, s32);
extern void *func_L39_006C9630(void *object);
extern void func_L39_006C9A08(void *, void *);
extern s32 func_L39_006C9860(s32 *a0, s32 a1);
extern void func_L39_006C9668(void *, s32);
extern s32 func_L39_00684B80(void *a0, s32 a1, void *a2, void *a3, void *a4);
extern void func_L39_006D7310(s32, s32, char *, s32);


s32 func_L39_00684EC0(S_006879E0_obj *arg0, s32 arg1) {
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
        func_L01_00512AB0(D_L39_003D2980[0x44 / 4], 1, 0);
        func_L01_00512AB0(D_L39_003D2980[0x4C / 4], 1, 0);
        func_L01_00512AB0(D_L39_003D2980[0x48 / 4], 1, 0);
    }
    if (flag == 1) {
        func_L39_0067CC90();
        ok = D_L39_0024D870_00684EC0;
    } else {
        ok = D_001E1FE0_sda;
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

        color = func_0037E368(0x8066CCFF, 0x80FFFFFF, 0x32, 0, 0, 0);
        func_L01_005130C8(D_L39_003D2980[0x44 / 4], color);
        func_L01_00512AB0(D_L39_003D2980[0x44 / 4], 1, 1);
        func_L01_00512AB0(D_L39_003D2980[0x4C / 4], 1, 1);
        func_L01_00512AB0(D_L39_003D2980[0x48 / 4], 1, 1);
        func_L01_00513548(D_L39_003D2980[0x34 / 4], 0.85f, 1.0f);
        func_L01_00513548(D_L39_003D2980[0x38 / 4], 0.85f, 1.0f);
        if (arg1 == 9) {
        func_L39_0067CBC8(&slot, line);
        if (line[0] == 'C') {
            {
                u8 *o;
                s32 owner;

                o = (u8 *)D_L39_0024D860[0x38 / 4];
                func_L39_006CC290(o, 0);
                func_001200E0(line + 1, D_L39_00247B10_00684EC0, &id);
                owner = *(s32 *)o;
                if (owner >= 0 && id >= 0) {
                    if (((s32 (*)(void *, s32, char *, s32, char *))func_L39_00684B80)(arg0, func_0037DF98(0xFE0), line + 9, 0x18, 0) == 8) {
                        if (o[0x34] != 0) {
                            func_L39_006D0768(o, id, slot);
                        }
                        if (func_L39_006D96D0(D_L39_0024D860[0x4C / 4], id, owner, &v498) != 0) {
                            if (arg0->fE0 != 0) {
                                func_L39_006BA8F0(arg0->fE0, v498);
                                arg0->f284 = 0x1F;
                            }
                            return 1;
                        }
                    } else if (o[0x34] != 0) {
                        func_00120048(msg, D_L39_00247B18_00684EC0, 0x4D, func_0037DF98(0x1699));
                        func_L39_006D7310(D_L39_0024D860[0x48 / 4], slot, msg, 0);
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

                func_001200E0(line + 1, D_L39_00247B10_00684EC0, &v49C);
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
                func_00120048(text, func_0037DF98(0x1331), title);
                if (name[0] != 0) {
                    s32 n = func_00120884((s32)text);
                    text[n] = 1;
                    text[n + 1] = 1;
                    func_00120048(&text[n + 2], func_0037DF98(0x16DA), name);
                }
                if (((s32 (*)(void *, s32, char *, s32, char *))func_L39_00684B80)(arg0, func_0037DF98(0xFE0), text, 0x18, 0) == 8) {
                    o = func_L39_006D1BF8_00684EC0(D_L39_0024D860[0x3C / 4], v49C);
                    if (o != 0) {
                        t = 0;
                        q = func_L39_006DB820(*(s32 *)(D_001E1FD0_sda + 0x54), 0, v49C);
                        if (q != 0) {
                            t = *(s32 *)(q + 0x24);
                        }
                        dst = D_001DC1E4_sda->fA4;
                        func_L39_006C9630(state);
                        func_L39_006C9A08(state, o);
                        r = func_L39_006C9860(state, 2);
                        {
                            s32 a = *(s32 *)(o + 0x188);
                            s32 id = v49C;
                            S_006879E0_slot *s = D_001DC1E4_sda;
                            *(s32 *)(dst + 0x2A8) = id;
                            *(s32 *)(dst + 0x2AC) = t;
                            *(s32 *)(dst + 0x2B0) = r;
                            *(s32 *)(dst + 0x2B4) = a;
                            s->f284 = 0x10;
                        }
                        func_L39_006C9668(state, 2);
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
                func_00120048(text, D_L39_00247B20, name, func_0037DF98(0x1170));
                ((s32 (*)(void *, s32, char *, s32, char *))func_L39_00684B80)(arg0, func_0037DF98(0xFE0), text, 5, 0);
            }
        } else {
            msg[1] = 0;
            msg[0] = 'M';
            if (((s32 (*)(void *, s32, char *, s32, char *))func_L39_00684B80)(arg0, func_0037DF98(0xFE0), line + 1, 5, msg + 1) == 4) {
                func_L39_006D7310(D_L39_0024D860[0x48 / 4], slot, msg, 0);
            }
        }
        ret = 1;
        }
    } else {
    func_L01_00512AB0(D_L39_003D2980[0x44 / 4], 1, 0);
    func_L01_00512AB0(D_L39_003D2980[0x4C / 4], 1, 0);
    func_L01_00512AB0(D_L39_003D2980[0x48 / 4], 1, 0);
    func_L01_00513548(D_L39_003D2980[0x34 / 4], 1.0f, 1.0f);
    func_L01_00513548(D_L39_003D2980[0x38 / 4], 1.0f, 1.0f);
    }
    }
    return ret;
}
/* localdecomp:end func_L39_00684EC0 */
