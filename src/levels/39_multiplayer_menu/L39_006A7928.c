#include "common.h"

/* localdecomp:start func_L39_006A7928 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");
extern s32 **D_L39_0024D760;
extern s32 *D_L39_00247914;
extern s32 D_001A5CD0[];
extern s32 *D_001DC204_sda;
extern void func_00199050(void);
extern void func_L39_006D40B0(s32);
extern void func_L39_006DA680(s32, s32, s32);
extern void func_L39_006BD408(s32, s32);

void func_L39_006A7928(void)
{
    s32 s;

    func_00199050();
    if (D_001A5CD0[0x174 / 4] != 0) {
        D_001DC204_sda[0x284 / 4] = 0x15;
    } else {
        func_L39_006D40B0(((s32 *)D_L39_0024D760)[0x3C / 4]);
        s = D_L39_00247914[0xE0 / 4];
        func_L39_006DA680(((s32 *)D_L39_0024D760)[0x4C / 4], D_001A5CD0[0x78 / 4], 0);
        func_L39_006BD408(s, D_001A5CD0[0x78 / 4]);
        D_L39_00247914[0x284 / 4] = 0x1F;
    }
}
/* localdecomp:end func_L39_006A7928 */

INCLUDE_ASM("asm/levels", func_L39_006A79C0);

/* localdecomp:start func_L39_006A8138 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct S_006A8138_obj S_006A8138_obj;
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(S_006A8138_obj *, s32, s32);
    u8 pad20[0x4];
    void (*f24)(S_006A8138_obj *, s32);
} S_006A8138_vt;
struct S_006A8138_obj {
    u8 pad0[0x60];
    S_006A8138_vt *vt;
};
typedef struct {
    u8 pad0[0x11C];
    S_006A8138_obj *obj;
    u8 pad120[0x470 - 0x120];
    s32 f470;
    u8 f474;
    u8 pad475[3];
    s32 f478;
} S_006A8138;
extern s32 D_001A5CD0[];
extern s32 **D_L39_0024D760;
extern f32 D_L39_004B0538[];
extern u8 D_L39_002488C0[];
extern void func_L39_00689D28(void *, void *);
extern void *func_00381FF0(s32);
extern void func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_00689F00(void *, s32, f32, f32, s32, s32, f32, f32, f32, f32);

void func_L39_006A8138(void *a0)
{
    S_006A8138 *p = a0;
    S_006A8138_vt *vt;
    s32 w;

    if (D_001A5CD0[0x174 / 4] == 0 &&
        (D_001A5CD0[0x170 / 4] != 0 || ((u8 *)D_001A5CD0)[0x168] != 0)) {
        p->f474 = 1;
    } else {
        p->f474 = 0;
        func_L39_00689D28(p, D_L39_002488C0);
    }
    if (D_001A5CD0[0x174 / 4] != 0) {
        return;
    }
    w = *D_L39_0024D760[0x30 / 4];
    if (((u8 *)D_001A5CD0)[0x168] != 0 && p->f478 < 0) {
        vt = p->obj->vt;
        vt->f24(p->obj, (s32)func_00381FF0(0x1297));
        if (p->f470 == -1 || w == p->f470) {
            p->obj->vt->f1C(p->obj, 3, 0);
            func_L39_0068B2F8(p, 3, 0);
            func_L39_00689F00(p, 0, D_L39_004B0538[0], D_L39_004B0538[1], 3, 3, D_L39_004B0538[2], D_L39_004B0538[3], 0.026f, 0.25f);
            func_L39_00689D28(p, func_00381FF0(0x124));
        } else {
            p->obj->vt->f1C(p->obj, 2, 0);
        }
    } else {
        vt = p->obj->vt;
        vt->f24(p->obj, (s32)func_00381FF0(0xF8C));
        if (p->f478 != -1) {
            p->obj->vt->f1C(p->obj, 3, 0);
            func_L39_0068B2F8(p, 3, 0);
            func_L39_00689F00(p, 0, D_L39_004B0538[0], D_L39_004B0538[1], 3, 3, D_L39_004B0538[2], D_L39_004B0538[3], 0.026f, 0.25f);
        } else {
            p->obj->vt->f1C(p->obj, 2, 0);
            func_L39_00689F00(p, 0, 2.0f, 2.0f, 3, 3, D_L39_004B0538[2], D_L39_004B0538[3], 0.026f, 0.25f);
            func_L39_00689D28(p, D_L39_002488C0);
        }
    }
}
/* localdecomp:end func_L39_006A8138 */

INCLUDE_ASM("asm/levels", func_L39_006A83B8);
