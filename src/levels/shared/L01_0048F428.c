#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
} E_488750;
typedef struct VT_00489FA8 { u8 p0[12]; void (*f12)(void *); } VT_00489FA8;
typedef struct O_00489FA8 { u8 p0[4]; VT_00489FA8 *vt; } O_00489FA8;
typedef struct Obj_0048B530 Obj_0048B530;
typedef struct {
    void *pad0[3];
    void (*fn)(Obj_0048B530 *);
} ObjVtbl_0048B530;
struct Obj_0048B530 {
    s32 pad0;
    ObjVtbl_0048B530 *vtbl;
};
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_48D030;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct {
    s32 w0;
    void (*fn)(u32);
    s32 w8;
} E_0048D0C8;
typedef struct { u8 b[16]; } V16_48DCD8;

/* declared by functions of L01_0048B738.c, which this file was cut from */
extern char *func_00381FF0(s32 id);
extern void func_L01_00516FD8(s32 id, char *s);
extern void func_L01_00517190(s32 id, s32 v);
extern void func_L01_00516D60(s32 id, s32 v);
extern s32 func_003A5348(s32, s32, s32);
extern void func_003BB468(s32);
extern O_00489FA8 *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_L01_00517918(s32);
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_0039EF28(void);
extern s32 func_L01_0048FB98(void);

/* localdecomp:start func_L01_0048F428 */
extern s32 D_L01_001D8D08;
extern s32 D_L01_001F43B0[];
extern s32 D_001D545C[] __attribute__((section(".sdata")));
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);

void func_L01_0048F428(void)
{
    Obj_0048B530 *obj;

    func_L01_00517918(16);
    func_L01_00517918(17);
    obj = ((Obj_0048B530 * (*)(s32))func_003B42F8)(0);
    obj->vtbl->fn(obj);
    func_003A2750(1);
    func_003BB468(D_L01_001D8D08);
    D_L01_001D8D08 = 0;
    D_L01_001F43B0[0] = D_001D545C[0];
}
/* localdecomp:end func_L01_0048F428 */

/* localdecomp:start func_L01_0048F490 */
extern void func_L01_0047E4B8_0048F490(void);
extern void func_003A9440(s32, s32);
extern void func_L01_0042EBF0(s32);
extern void func_L01_0047E520(void);
void func_L01_0048F490(void) {
    func_L01_0047E4B8_0048F490();
    func_003A9440(66, 68);
    func_003A9440(71, 11);
    func_L01_0042EBF0(1);
    func_L01_0047E520();
}
/* localdecomp:end func_L01_0048F490 */

/* localdecomp:start func_L01_0048F4D8 */
void func_L01_0048F4D8(void) {

}
/* localdecomp:end func_L01_0048F4D8 */

/* localdecomp:start func_L01_0048F4E0 */
/* map screen update; follows rac2-decomp's func_002D6F38 (nonmatching draft) */
typedef struct {
    s32 offset;
    s32 size;
} MapEntry_0048F4E0;

typedef struct {
    u8 pad0[0x4954];
    s32 base;
    u8 pad4958[0x5DC8 - 0x4958];
    MapEntry_0048F4E0 maps[60];
    MapEntry_0048F4E0 alt_maps[60];
} MapDisc_0048F4E0;

typedef struct {
    s32 mask;
    s32 chunks;
    s32 pixels;
    s32 palette;
    s32 texture;
    s32 layer1;
    s32 layer2;
} MapHeader_0048F4E0;

typedef struct {
    u8 pad0[0xC];
    void *mask;
    u8 pad10[0x28 - 0x10];
    s32 stream;
    u8 pad2C[0x410 - 0x2C];
    s32 level;
    s32 loaded;
    void *source;
    s32 source_level;
    s32 source_size;
    s32 pad424;
    MapHeader_0048F4E0 *header;
    s32 image_vram;
    s32 clut_vram;
    s32 texture_vram[3];
    u8 pad440[0x448 - 0x440];
    unsigned long texture[3];
    u8 pad460[0x468 - 0x460];
    s32 slots[5];
    s32 ids[5];
    s32 selected;
    s32 sizes[5];
} Map_0048F4E0;

typedef struct {
    s32 w0;
    s32 w4;
} Name_0048F4E0;

typedef struct {
    u8 pad0[4];
    s16 mode;
    u8 pad6[0x78 - 6];
} Read_0048F4E0;

extern Map_0048F4E0 D_L01_001F3FA0_0048F4E0;
extern Name_0048F4E0 D_L01_002E9DC0_0048F4E0[];
extern Read_0048F4E0 D_001CCFD0_0048F4E0;
extern MapDisc_0048F4E0 D_00160C40_0048F4E0;
extern s32 *D_L01_001D8D50;
__asm__(".extern D_L01_001D8D50, 4");
extern char D_L01_001D8D10[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D8D10, 8");
extern char D_L01_001D8D58[];
extern u8 *D_001D52FC_0048F4E0;
__asm__(".extern D_001D52FC_0048F4E0, 4");
extern s32 D_001D545C_0048F4E0;
__asm__(".extern D_001D545C_0048F4E0, 4");
extern s32 D_001D545C[] __attribute__((section(".sdata")));
extern u8 D_00142CA0[];
extern u8 D_001D5570[];
extern u8 D_001A9318[];

extern s32 func_L01_0042E818(void);
extern s32 func_003BB148(s32);
extern char *func_00381FF0(s32 id);
extern void func_L01_00516FD8(s32 id, char *s);
extern void func_L01_00517190(s32 id, s32 v);
extern void func_L01_00516D60(s32 id, s32 v);
extern void func_0011B2E8_0048F4E0(char *dst, char *fmt, ...);
extern s32 func_L01_0042E500(s32 p);
extern void func_L01_0042E768(s32 a);
extern s32 func_003A5348(s32, s32, s32);
extern void func_0039EF28(void);
extern int func_L01_0042E318(int id);
extern s32 func_L01_0042E598(void);
extern void func_L01_0042E278(s32, s32);
extern void func_003A0760_0048F4E0(s32, void *);
extern void *func_003BB3A8(s32);
extern void func_L01_0042E700(u8 *a0, u8 *a1, u8 *a2, u8 *a3);
extern void func_L01_00430A80(s32, u8 *, s32);
extern void func_L01_0042FEB0(s32 *out, s32 a1, s32 a2);
extern unsigned long func_L01_0042D9C0(int a0, int a1, u32 a2, u32 a3, int arg5, int arg6);
extern void func_003A02E8();
extern void func_003BB468(s32);
extern void func_L01_00438028(s32, s32);
extern s32 func_L01_0042E1D8(void);
extern int func_L01_0042E3A8(void);
extern s32 func_L01_004B11E0(s32, void *, s32, s32, s32);
extern s32 func_003A2598(s32, s32, s32);

void func_L01_0048F4E0(void) {
    s32 prev, idx, id, slot, n, pick, next, k, buf, v;
    s32 a, b;
    MapHeader_0048F4E0 *hdr;
    u8 *pix, *pal, *base, *p, *tex, *l1, *l2, *tbase;

    func_L01_0042E818();
    v = func_003BB148(D_L01_001F3FA0_0048F4E0.level);
    if (v == -1) {
        func_L01_00517190(0x180006, 0);
        func_L01_00516D60(0x180006, 0);
        func_L01_00516D60(0x180007, 0);
    } else {
        func_L01_00517190(0x180006, v);
        func_L01_00516D60(0x180006, 1);
        func_L01_00516D60(0x180007, 1);
        a = D_L01_001F3FA0_0048F4E0.level > 0 ? D_L01_002E9DC0_0048F4E0[D_L01_001F3FA0_0048F4E0.level % 60].w4 : D_L01_002E9DC0_0048F4E0[1].w4;
        b = D_L01_001F3FA0_0048F4E0.level > 0 ? D_L01_002E9DC0_0048F4E0[D_L01_001F3FA0_0048F4E0.level % 60].w0 : D_L01_002E9DC0_0048F4E0[1].w0;
        if (a == 0 || b == 0) {
            func_L01_00516D60(0x180007, 0);
        } else {
            func_0011B2E8_0048F4E0(D_L01_001D8D10, D_L01_001D8D58, func_00381FF0(b), func_00381FF0(a));
            func_L01_00516FD8(0x180007, D_L01_001D8D10);
        }
    }

    prev = D_L01_001F3FA0_0048F4E0.level;
    idx = func_L01_0042E500(prev);
    if (idx >= 0) {
        if ((*(s32 *)(D_001D52FC_0048F4E0 + 0x1C4) & 8) && idx < 59) {
            if (D_L01_001D8D50[idx + 1] == 3 && D_001D545C[0] == 6) {
                func_L01_0042E768(6);
            } else if (D_L01_001D8D50[idx + 1] == 11) {
                if (D_L01_001D8D50[idx + 2] != 0) {
                    func_L01_0042E768(D_L01_001D8D50[idx + 2]);
                }
            } else if ((u32)D_L01_001D8D50[idx + 1] >= 2) {
                func_L01_0042E768(D_L01_001D8D50[idx + 1]);
            }
        } else if ((*(s32 *)(D_001D52FC_0048F4E0 + 0x1C4) & 4) && idx != 0) {
            if (D_L01_001D8D50[idx - 1] == 3 && D_001D545C[0] == 6) {
                func_L01_0042E768(6);
            } else if (D_L01_001D8D50[idx - 1] == 11) {
                if (D_L01_001D8D50[idx - 2] != 0) {
                    func_L01_0042E768(D_L01_001D8D50[idx - 2]);
                }
            } else if ((u32)D_L01_001D8D50[idx - 1] >= 2) {
                func_L01_0042E768(D_L01_001D8D50[idx - 1]);
            }
        }
    }
    if (D_L01_001F3FA0_0048F4E0.level != prev) {
        func_003A5348(3, 0, 0);
        func_0039EF28();
    }

    id = D_L01_001F3FA0_0048F4E0.level;
    if (D_00142CA0[5]) id += 0x100;
    slot = func_L01_0042E318(id);
    if (D_L01_001F3FA0_0048F4E0.level != D_L01_001F3FA0_0048F4E0.loaded && slot != -1) {
        n = func_L01_0042E598();
        if (D_L01_001F3FA0_0048F4E0.slots[0] && n > 0) {
            func_L01_0042E278(n, 0);
            if (!slot) slot = n;
        }
        func_003A0760_0048F4E0(D_L01_001F3FA0_0048F4E0.slots[slot], D_L01_001F3FA0_0048F4E0.header);
        hdr = D_L01_001F3FA0_0048F4E0.header;
        pix = (u8 *)hdr + hdr->pixels;
        pal = (u8 *)hdr + hdr->palette;
        buf = (s32)func_003BB3A8(0);
        if (buf) {
            base = (u8 *)D_L01_001F3FA0_0048F4E0.header;
            p = base + hdr->mask + 8;
            if (D_L01_001F3FA0_0048F4E0.level == D_001D545C_0048F4E0) {
                func_L01_0042E700(pal, pix, pal, D_L01_001F3FA0_0048F4E0.mask);
            } else {
                if (D_001D5570[D_L01_001F3FA0_0048F4E0.level]) {
                    func_L01_00430A80(buf, D_001A9318 + (D_L01_001F3FA0_0048F4E0.level << 11), (s32)(base + hdr->chunks));
                } else {
                    func_L01_0042FEB0((s32 *)buf, (s32)p, (s32)p);
                }
                func_L01_0042E700(pal, pix, pal, (u8 *)buf);
            }
        }
        tbase = (u8 *)D_L01_001F3FA0_0048F4E0.header;
        tex = tbase + hdr->texture;
        l1 = tbase + hdr->layer1 + 0x420;
        l2 = tbase + hdr->layer2 + 0x420;
        D_L01_001F3FA0_0048F4E0.texture[0] = func_L01_0042D9C0(7, 7, (u32)(tex + 32), (u32)(tex + 0x420), D_L01_001F3FA0_0048F4E0.clut_vram, D_L01_001F3FA0_0048F4E0.texture_vram[0]);
        D_L01_001F3FA0_0048F4E0.texture[1] = func_L01_0042D9C0(7, 7, (u32)(tex + 32), (u32)l1, D_L01_001F3FA0_0048F4E0.clut_vram, D_L01_001F3FA0_0048F4E0.texture_vram[1]);
        D_L01_001F3FA0_0048F4E0.texture[2] = func_L01_0042D9C0(7, 7, (u32)(tex + 32), (u32)l2, D_L01_001F3FA0_0048F4E0.clut_vram, D_L01_001F3FA0_0048F4E0.texture_vram[2]);
        if (buf) func_L01_0042D9C0(9, 9, (u32)pal, (u32)pal, 0x3FF000, D_L01_001F3FA0_0048F4E0.image_vram);
        func_003A02E8();
        if (buf) func_003BB468(buf);
        D_L01_001F3FA0_0048F4E0.slots[0] = (s32)pix;
        D_L01_001F3FA0_0048F4E0.loaded = D_L01_001F3FA0_0048F4E0.level;
        func_L01_00438028(D_L01_001F3FA0_0048F4E0.level, 0);
    }

    if (!D_001CCFD0_0048F4E0.mode && D_L01_001F3FA0_0048F4E0.selected != -1) {
        D_L01_001F3FA0_0048F4E0.ids[D_L01_001F3FA0_0048F4E0.selected] ^= 0x1000;
        D_L01_001F3FA0_0048F4E0.selected = -1;
    }
    pick = -1;
    if (D_L01_001F3FA0_0048F4E0.stream && !D_001CCFD0_0048F4E0.mode) {
        pick = func_L01_0042E1D8();
        if (pick != -1) {
            next = func_L01_0042E3A8();
            if (next != -1) {
                k = (D_001D545C_0048F4E0 + D_L01_001F3FA0_0048F4E0.source_level == 0) ? 0 : 0x100;
                if (k == next) {
                    func_L01_004B11E0(D_L01_001F3FA0_0048F4E0.slots[pick], D_L01_001F3FA0_0048F4E0.source, 0, D_L01_001F3FA0_0048F4E0.source_size, 0);
                    D_L01_001F3FA0_0048F4E0.sizes[pick] = D_L01_001F3FA0_0048F4E0.source_size;
                } else {
                    if (next & 0x100) {
                        s32 sector, origin;
                        s32 *size;

                        origin = D_00160C40_0048F4E0.base;
                        sector = D_00160C40_0048F4E0.alt_maps[next ^ 0x100].offset;
                        size = &D_00160C40_0048F4E0.alt_maps[next ^ 0x100].size;
                        func_003A2598(D_L01_001F3FA0_0048F4E0.slots[pick], sector + origin, *size);
                        D_L01_001F3FA0_0048F4E0.sizes[pick] = (*size << 11) >> 4;
                    } else {
                        s32 sector, origin;
                        s32 *size;

                        origin = D_00160C40_0048F4E0.base;
                        sector = D_00160C40_0048F4E0.maps[next].offset;
                        size = &D_00160C40_0048F4E0.maps[next].size;
                        func_003A2598(D_L01_001F3FA0_0048F4E0.slots[pick], sector + origin, *size);
                        D_L01_001F3FA0_0048F4E0.sizes[pick] = (*size << 11) >> 4;
                    }
                }
                D_L01_001F3FA0_0048F4E0.ids[pick] = next | 0x1000;
                D_L01_001F3FA0_0048F4E0.selected = pick;
            }
        }
    }
    slot = func_L01_0042E318(id);
    if (D_L01_001F3FA0_0048F4E0.level != D_L01_001F3FA0_0048F4E0.loaded && !D_001CCFD0_0048F4E0.mode && slot == -1 && pick == slot) {
        func_L01_0042E598();
    }
}
/* localdecomp:end func_L01_0048F4E0 */

/* localdecomp:start func_L01_0048FB98 */
extern s32 func_L01_0048FB98(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0978;
extern s32 D_L01_001E0960[2];
extern void func_L01_0048EEC8();
extern void func_L01_0048F428();
extern void func_L01_0048F390();
extern void func_L01_0048F490(void);
extern void func_L01_0048F4D8_0048FB98();
s32 func_L01_0048FB98(void) {
    if (D_L01_001E0978 == 0) {
        func_003E6FA0(D_L01_001E0960, (s32)func_L01_0048EEC8, (s32)func_L01_0048F428, (s32)func_L01_0048F390, (s32)func_L01_0048F490, (s32)func_L01_0048F4D8_0048FB98);
        D_L01_001E0978 = 1;
    }
    return (s32)D_L01_001E0960;
}
/* localdecomp:end func_L01_0048FB98 */
