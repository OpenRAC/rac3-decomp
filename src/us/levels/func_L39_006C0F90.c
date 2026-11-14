#include "common.h"

/* NTSC-U counterpart of func_L39_006C3AA8 (src/levels/39_multiplayer_menu/L39_006C20B0.c) */
typedef struct {
    char pad0[0xE0];
    s16 hE0[8];
    s16 hF0[1];
} S_241640_006C2C40;
extern S_241640_006C2C40 *D_001D5F30_sda_006C0F90;
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_0037DF98(s32);

/* localdecomp:start func_L39_006C0F90 */
/* best: 112 diff with --mode N --as ps2as (file flags: ~320 diff, float consts come from $gp
 * literals instead of lui/ori/mtc1, so this function wants ps2as / other flags).
 * Frame layout, names-array copy, switch, vtable calls now match. Still differs:
 * e lives in $s3 not $s4; trim loop: retail keeps a second copy of e->name ($s3) and puts
 * (e->name < q) into $s0; the D_L39_001FD7B0 loop (retail walks &f0 and loads 4($s0)).
 */
__asm__(".extern D_L39_0024D860, 16");
__asm__(".extern D_L39_002496C0, 16");
__asm__(".extern D_L39_002496A0, 16");

typedef struct VT_006C3AA8 {
    u8 pad0[0x24];
    void (*fn24)(void *, void *);
    u8 pad28[0xDC - 0x28];
    void (*fnDC)(void *, s32);
} VT_006C3AA8;

typedef struct Obj_006C3AA8 {
    u8 pad0[0x60];
    VT_006C3AA8 *vt;
} Obj_006C3AA8;

typedef struct E_006C3AA8 {
    u8 pad0[0x134];
    u8 name[0x13];
} E_006C3AA8;

typedef struct S_006C3AA8 {
    s32 f0;
    s32 f4;
    u8 pad8[0x20];
} S_006C3AA8;

extern u8 *D_001E1FD0_sda;
extern u8 *D_L39_0024D860;
extern u8 D_L39_002496C0[];
extern u8 D_L39_002496A0[];
extern u8 D_001A5F0E[];
extern S_006C3AA8 D_L39_001FD7B0[];

extern s32 func_0019B708(void);
extern u8 *func_L39_006D1BF8_006C0F90(void *, s32);
extern void *func_L39_006C9630(void *object);
extern void func_L39_006C9A08(void *, void *);
extern s32 func_L39_006C9860(s32 *a0, s32 a1);
extern void func_L39_006C9668(void *object, s32 flags);
extern void func_L39_00687900(void *, s32, s32, u32, f32, f32, f32, f32);
extern s32 func_00120884(u8 *);
extern void func_L39_00594648(u8 *, u8 *, s32);
extern void func_00388490(void *, s32);
extern u8 *func_00120D28(void *, void *, s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern void func_L39_006D7310(void *, s32, u8 *, s32);

void func_L39_006C0F90(u8 *obj) {
    s32 buf[0x1E0 / 4];
    u8 *e;
    u8 *q;
    void *s;
    s32 mode;
    s32 i;
    void *h;

    if ((obj[0x2B5] || obj[0x2B4]) && D_001D5F30_sda_006C0F90 != 0) {
        h = *(void **)(D_001E1FD0_sda + 0x3C);
        e = func_L39_006D1BF8_006C0F90(h, func_0019B708());
        if (e != 0 && *(s32 *)(e + 0x18) == 0) {
            func_L39_006C9630(buf);
            func_L39_006C9A08(buf, e);
            obj[0x2B5] = 0;
            func_L39_00687900(obj, 1, func_L39_006C9860(buf, 1), 0x332299DE, 0.5f, 0.48677778f, 0.045777798f, 0.805f);
            *(s32 *)(obj + 0x2CC) = func_L39_006C9860(buf, 0xC);
            *(s32 *)(obj + 0x2D0) = func_L39_006C9860(buf, 3);
            *(s32 *)(obj + 0x2D4) = func_L39_006C9860(buf, 0xF) * 5;
            *(s32 *)(obj + 0x2E0) = func_L39_006C9860(buf, 0x11);
            obj[0x2E4] = func_L39_006C9860(buf, 0x13) == 0;
            obj[0x2E5] = func_L39_006C9860(buf, 0x14) == 1;
            *(s32 *)(obj + 0x2E8) = func_L39_006C9860(buf, 0x15) * 5;
            *(s32 *)(obj + 0x2EC) = func_L39_006C9860(buf, 0x17);
            *(s32 *)(obj + 0x2F0) = func_L39_006C9860(buf, 0x18);
            obj[0x302] = func_L39_006C9860(buf, 0x19) == 1;
            obj[0x300] = func_L39_006C9860(buf, 0x1A) == 1;
            obj[0x301] = func_L39_006C9860(buf, 0x1B) == 1;
            obj[0x303] = func_L39_006C9860(buf, 0x1C) == 1;
            obj[0x2F4] = func_L39_006C9860(buf, 0x16) == 1;
            obj[0x2D8] = func_L39_006C9860(buf, 4) == 0;
            obj[0x2D9] = func_L39_006C9860(buf, 5) == 0;
            obj[0x2DA] = func_L39_006C9860(buf, 6) == 0;
            obj[0x2DB] = func_L39_006C9860(buf, 7) == 0;
            obj[0x2DC] = func_L39_006C9860(buf, 8) == 0;
            obj[0x2DD] = func_L39_006C9860(buf, 9) == 0;
            obj[0x2DE] = func_L39_006C9860(buf, 0xA) == 0;
            obj[0x2DF] = func_L39_006C9860(buf, 0xB) == 0;
            *(s32 *)(obj + 0x2F8) = func_L39_006C9860(buf, 1);
            mode = func_L39_006C9860(buf, 0x10);
            {
                void *names[10] = {
                    (void *)func_0037DF98(0xBB1), (void *)func_0037DF98(0xBB2), (void *)func_0037DF98(0xDA),
                    (void *)func_0037DF98(0xBB4), (void *)func_0037DF98(0xD8), (void *)func_0037DF98(0xD4),
                    (void *)func_0037DF98(0x18C4), (void *)func_0037DF98(0x18C5), (void *)func_0037DF98(0x18C6),
                    (void *)func_0037DF98(0x18C7),
                };
                (*(Obj_006C3AA8 **)(obj + 0x114))->vt->fn24(*(Obj_006C3AA8 **)(obj + 0x114), names[(mode - 1) % 10]);
                {
                    u8 text[0x20];

                    s = (void *)func_0037DF98(0x1328);
                    switch (*(s32 *)(obj + 0x2E0)) {
                    case 0:
                        s = (void *)func_0037DF98(0x1024);
                        break;
                    case 1:
                        s = (void *)func_0037DF98(0x10E2);
                        break;
                    case 2:
                        if (((s8 *)D_001D5F30_sda_006C0F90)[0x19D]) {
                            s = (void *)func_0037DF98(0x162A);
                        } else {
                            s = (void *)func_0037DF98(0x1026);
                        }
                        break;
                    }
                    (*(Obj_006C3AA8 **)(obj + 0x118))->vt->fn24(*(Obj_006C3AA8 **)(obj + 0x118), s);
                    e[0x146] = 0;
                    q = &((E_006C3AA8 *)e)->name[func_00120884(((E_006C3AA8 *)e)->name) - 1];
                    while (((E_006C3AA8 *)e)->name < q && *q == ' ') {
                        q--;
                    }
                    q[1] = 0;
                    func_L39_00594648(text, ((E_006C3AA8 *)e)->name, func_00120884(((E_006C3AA8 *)e)->name));
                    (*(Obj_006C3AA8 **)(obj + 0x110))->vt->fn24(*(Obj_006C3AA8 **)(obj + 0x110), text);
                    func_00388490(D_001A5F0E, 0x40);
                    func_00120D28(D_001A5F0E, ((E_006C3AA8 *)e)->name, 0x11);
                    *(s32 *)(D_001A5F0E + 0x546) = *(s32 *)(e + 0x180);
                    (*(Obj_006C3AA8 **)(obj + 0x128))->vt->fnDC(*(Obj_006C3AA8 **)(obj + 0x128), mode + 0x24);
                    if (obj[0x2B4]) {
                        s32 me = func_0019B708();
                        s32 other = *(s32 *)(e + 0x188);
                        u8 tmp[0x50];

                        for (i = 0; i < 11; i++) {
                            if (D_L39_001FD7B0[i].f4 == 1) {
                                tmp[0] = 'N';
                                func_00120048(tmp + 1, D_L39_002496C0, me);
                                func_00120048(tmp + 9, D_L39_002496C0, other);
                                func_L39_006D7310(*(void **)(D_L39_0024D860 + 0x48), D_L39_001FD7B0[i].f0, tmp, 1);
                            }
                        }
                        obj[0x2B4] = 0;
                    }
                }
            }
            func_L39_006C9668(buf, 2);
        } else {
            (*(Obj_006C3AA8 **)(obj + 0x110))->vt->fn24(*(Obj_006C3AA8 **)(obj + 0x110), D_L39_002496A0);
        }
    }
}
/* localdecomp:end func_L39_006C0F90 */
