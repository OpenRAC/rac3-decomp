#include "common.h"

/* localdecomp:start func_L39_006A3AB0 */
typedef struct S_006A3AB0_Obj S_006A3AB0_Obj;
typedef struct S_006A3AB0_Vt {
    u8 pad0[0x20];
    void (*f20)(S_006A3AB0_Obj *, s32, s32);
    void (*f24)(S_006A3AB0_Obj *, void *);
    u8 pad28[0x18];
    void (*f40)(S_006A3AB0_Obj *, s32);
    u8 pad44[0x34];
    s32 (*f78)(S_006A3AB0_Obj *);
    u8 pad7C[4];
    void (*f80)(S_006A3AB0_Obj *, s32);
    void (*f84)(S_006A3AB0_Obj *, s32);
    void (*f88)(S_006A3AB0_Obj *, s32);
    s32 (*f8C)(S_006A3AB0_Obj *);
    u8 pad90[0xC];
    s32 (*f9C)(S_006A3AB0_Obj *, f32 *, f32 *);
    void (*fA0)(S_006A3AB0_Obj *, f32 *, f32 *);
    u8 padA4[4];
    void (*fA8)(S_006A3AB0_Obj *, s32);
    s32 (*fAC)(S_006A3AB0_Obj *);
} S_006A3AB0_Vt;
struct S_006A3AB0_Obj { u8 pad[0x60]; S_006A3AB0_Vt *vt; };
typedef struct S_006A3AB0_Cfg { u8 pad[0x30]; s32 unk30; } S_006A3AB0_Cfg;
typedef struct S_006A3AB0 {
    u8 pad0[0x110];
    S_006A3AB0_Obj *items[21];
    S_006A3AB0_Obj *unk164;
    S_006A3AB0_Obj *unk168;
    S_006A3AB0_Obj *unk16C;
    u8 pad170[0x290 - 0x170];
    s32 state;
    u8 pad294[0x2A8 - 0x294];
    s32 unk2A8;
    s32 unk2AC;
    s32 unk2B0;
    s32 unk2B4;
    S_006A3AB0_Cfg *unk2B8;
    s32 unk2BC;
    s32 unk2C0;
    u8 pad2C4[0xC];
    s32 unk2D0[8];
    u8 pad2F0[0x24];
    s32 unk314;
    u8 unk318[8];
    s32 unk320;
    s32 unk324;
    s32 unk328;
    s32 unk32C;
    u8 unk330;
    u8 pad331[3];
    s32 unk334;
    s32 unk338;
    u8 unk33C;
    u8 unk33D;
    u8 unk33E;
    u8 unk33F;
} S_006A3AB0;
typedef struct S_006A3AB0_G { u8 pad[0xD0]; void *unkD0; u8 padD4[0x284 - 0xD4]; s32 unk284; } S_006A3AB0_G;
typedef struct S_006A3AB0_Ply { s32 unk0; } S_006A3AB0_Ply;
typedef struct S_006A3AB0_Ctx { u8 data[0x1E0]; } S_006A3AB0_Ctx;
typedef struct S_006A3AB0_Mgr { u8 pad[0x38]; S_006A3AB0_Ply *unk38; void *unk3C; u8 pad40[0xC]; S_006A3AB0_Ply *unk4C; } S_006A3AB0_Mgr;

extern void *func_00381FF0(s32);
extern void *func_L39_006CC120(void *);
extern s32 func_L39_006CC350(S_006A3AB0_Ctx *, s32);
extern void func_L39_006CC158(S_006A3AB0_Ctx *, s32);
__asm__(".extern D_L39_0024D760, 16");
extern S_006A3AB0_Mgr *D_L39_0024D760;
extern S_006A3AB0_G *D_001DC204_sda;
__asm__(".extern D_L39_00247914, 16");
extern S_006A3AB0_G *D_L39_00247914;
extern u8 D_001A5CD0[];
extern u8 D_L39_00248698[];
extern u8 D_L39_00248788[];
extern void func_L39_006A4510(S_006A3AB0 *, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_005F1718(void);
extern s32 func_L39_006DA680(S_006A3AB0_Ply *, s32, s32);
extern void func_L39_006CC4F8(void *, void *);
extern s32 func_L39_00687450(void *, void *, u8 *, s32, s32, s32, s32);
extern s32 func_L39_006D34D8(void *, s32, u8 *, s32, s32, s32);
extern s32 func_L39_006872E8(void *, void *, void *, s32, s32, f32);
extern void func_L39_006B5288(void *, s32, s32);
extern void func_L39_00687640(void *, s32, s32, s32, u8, s32, s32, u8 *, u8, u8, u8, u8, s32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
extern s32 func_L39_005C4350(void);
extern void func_L39_006A50F8(S_006A3AB0 *);

static __inline__ s32 isPlayer_006A3AB0(S_006A3AB0_Ply *ply, s32 id) {
    return ply->unk0 == id ? 1 : func_L39_006DA680(ply, id, 0);
}

s32 func_L39_006A3AB0(S_006A3AB0 *self, s32 ev) {
    u8 text[16];
    u8 name[16];
    S_006A3AB0_Ctx info;
    f32 v[4];
    s32 st;
    s32 flag = 0;

    if (ev == 6 || (self->state == 0x17 && ev == 7)) {
        flag = 1;
    }
    func_L39_006A4510(self, flag);
    if (self->unk2B8 == 0 || self->unk2B8->unk30 == 0) {
        if (*(s32 *)(D_001A5CD0 + 0x2E0) < 10) {
            S_006A3AB0_G *g0 = D_001DC204_sda;
            func_L39_006872E8(g0, func_00381FF0(0x131F), D_L39_00248698, 4, 0, 0.6f);
        }
        D_L39_00247914->unk284 = 0x2C;
        return 1;
    }
    if (func_L39_0068AEF8(self, ev) == 1) {
        return 1;
    }
    if (ev == 2) {
        func_L39_00688340(3, 0, 0);
        st = self->state;
        if (st == 0x14) {
            func_L39_0068B2F8(self, 0x16, 0);
        } else if (st == 0x16) {
            func_L39_0068B2F8(self, 0x17, 0);
        } else if (st == 0x17) {
            func_L39_0068B2F8(self, 0x14, 0);
        }
        return 1;
    }
    if (ev == 1) {
        func_L39_00688340(3, 0, 0);
        st = self->state;
        if (st == 0x14) {
            func_L39_0068B2F8(self, 0x17, 0);
        } else if (st == 0x16) {
            func_L39_0068B2F8(self, 0x14, 0);
        } else if (st == 0x17) {
            func_L39_0068B2F8(self, 0x16, 0);
        }
        return 1;
    }
    if (ev == 3 || ev == 4) {
        func_L39_00688340(3, 0, 0);
        if (self->state == 0x13) {
            func_L39_0068B2F8(self, self->unk314, 0);
        } else {
            self->unk314 = self->state;
            func_L39_0068B2F8(self, 0x13, 0);
        }
        return 1;
    }
    if (ev == 7) {
        func_L39_00688340(4, 0, 0);
        func_L39_005F1718();
        st = self->state;
        if (st == 0x14 && self->unk2BC != 0) {
            self->unk164->vt->f80(self->unk164, 1);
            self->unk164->vt->f20(self->unk164, 3, 0);
            func_L39_0068B2F8(self, 0x15, 0);
            self->unk164->vt->f84(self->unk164, 1);
            self->unk164->vt->f88(self->unk164, 0);
            return 1;
        }
        if (st == 0x17) {
            S_006A3AB0_Mgr *mgr = D_L39_0024D760;
            void *a = mgr->unk3C;
            S_006A3AB0_Ply *ply = mgr->unk4C;
            s32 n;
            s32 x;
            S_006A3AB0_G *g;

            self->unk16C->vt->f24(self->unk16C, func_00381FF0(0x1184));
            self->unk16C->vt->f40(self->unk16C, 1);
            if (~self->unk2B0 == 0 || isPlayer_006A3AB0(ply, self->unk2B0)) {
            x = 0;
            n = self->unk168->vt->fAC(self->unk168);
            name[0] = 0;
            text[0] = 0;
            if (self->unk2B8 != 0) {
                func_L39_006CC120(&info);
                func_L39_006CC4F8(&info, self->unk2B8);
                if (func_L39_006CC350(&info, 0xC) == 2) {
                    x = mgr->unk38->unk0 != func_L39_006CC350(&info, 0xD);
                }
                func_L39_006CC158(&info, 2);
            }
            if (self->unk2AC == 1) {
                g = D_L39_00247914;
                func_L39_00687450(g, func_00381FF0(0x1183), text, 0, 0x11, 1, 0);
            }
            D_001A5CD0[0xAA] = n >= 2;
            if (func_L39_006D34D8(a, self->unk2A8, text, n, x, self->unk2B4)) {
                D_001DC204_sda->unk284 = 0x21;
            } else {
            if (*(s32 *)(D_001A5CD0 + 0x634) == 1 || self->unk2BC == self->unk2C0) {
                g = *(s32 *)(D_001A5CD0 + 0x634) == 1 ? D_001DC204_sda : D_L39_00247914;
                func_L39_006872E8(g, func_00381FF0(0x12F5), D_L39_00248698, 4, 0, 0.6f);
            } else if (*(s32 *)(D_001A5CD0 + 0x634) == 3) {
                g = D_L39_00247914;
                func_L39_006872E8(g, func_00381FF0(0x12F6), D_L39_00248698, 4, 0, 0.6f);
            } else if (self->unk2AC == 1) {
                g = D_001DC204_sda;
                func_L39_006872E8(g, func_00381FF0(0x18C3), D_L39_00248698, 4, 0, 0.6f);
            } else {
                g = D_001DC204_sda;
                func_L39_006872E8(g, func_00381FF0(0x1FCF), D_L39_00248788, 4, 0, 0.6f);
            }
            self->unk16C->vt->f24(self->unk16C, func_00381FF0(0xF8C));
            self->unk16C->vt->f40(self->unk16C, 0);
            }
            } else {
                g = D_001DC204_sda;
                func_L39_006872E8(g, func_00381FF0(0x1326), D_L39_00248788, 4, 0, 0.6f);
                self->unk16C->vt->f24(self->unk16C, func_00381FF0(0xF8C));
                self->unk16C->vt->f40(self->unk16C, 0);
            }
            return 1;
        } else if (st == 0x15) {
            u32 i = self->unk164->vt->f8C(self->unk164);
            if (i < 8 && D_001DC204_sda->unkD0 != 0) {
                func_L39_006B5288(D_001DC204_sda->unkD0, self->unk2D0[i], 0);
                D_L39_00247914->unk284 = 0x1B;
            }
            return 1;
        } else if (st == 0x13) {
            func_L39_00687640(D_L39_00247914, self->unk320, self->unk324, self->unk328, self->unk330,
                              self->unk32C, self->unk334, self->unk318, self->unk33C, self->unk33D,
                              self->unk33E, self->unk33F, self->unk338 != 0);
            return 1;
        }
    }
    if (ev == 5 && self->state == 0x15) {
        self->unk164->vt->f80(self->unk164, 0);
        self->unk164->vt->f20(self->unk164, 2, 0);
        func_L39_0068B2F8(self, 0x14, 0);
        return 1;
    }
    if (self->state == 0x15) {
        s32 sel = 3;
        s32 k;
        s32 last;

        self->unk164->vt->f9C(self->unk164, &v[0], &v[1]);
        self->items[self->state]->vt->fA0(self->items[self->state], &v[2], &v[3]);
        func_L39_00689F00(self, 0, 3, 3, v[0] + v[2] * 0.5f, v[1], v[2] * 1.228f, v[3], 0.004f, 1.225f);
        k = self->items[self->state]->vt->f8C(self->items[self->state]);
        last = self->items[self->state]->vt->f78(self->items[self->state]) - 1;
        if (k == 0) {
            sel = last ? 2 : 0;
        } else if (k == self->items[self->state]->vt->f78(self->items[self->state]) - 1) {
            sel = 1;
        }
        func_L39_0068A2D0(self, sel, 3, 3, v[0] + v[2] * 0.5f + 0.033f, v[1]);
    } else {
        st = self->state;
        if (st == 0x14) {
            v[0] = 0.489f; v[1] = 0.334f; v[2] = 0.37f; v[3] = 0.04f;
        } else if (st == 0x16) {
            v[2] = 0.37f; v[3] = 0.0378f; v[0] = 0.49f; v[1] = 0.791f;
        } else if (st == 0x17) {
            v[2] = 0.37f; v[3] = 0.035f; v[0] = 0.49f; v[1] = 0.837f;
        } else if (st == 0x13) {
            v[2] = 0.37f; v[3] = 0.0425f; v[0] = 0.076f; v[1] = 0.831f;
        }
        func_L39_00689F00(self, 0, 3, 3, v[0], v[1], v[2], v[3], 0.1f, 0.1f);
        func_L39_0068A2D0(self, 0, 1, 3, v[0] + 0.033f, v[1]);
    }
    if (self->unk168->vt->fAC(self->unk168) == 2 && func_L39_005C4350() == 1) {
        self->unk168->vt->fA8(self->unk168, 1);
    }
    func_L39_006A50F8(self);
    return 0;
}
/* localdecomp:end func_L39_006A3AB0 */
