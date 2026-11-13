#include "common.h"

/* declared by functions of L39_006921B8.c, which this file was cut from */
typedef struct {
    u8 pad[0x34];
    u8 on;
} M_006921E0;
typedef struct {
    u8 pad[0x38];
    M_006921E0 *mgr;
} G_006921E0;
extern G_006921E0 *D_L39_0024D760;

/* localdecomp:start func_L39_00692420 */
extern char D_L39_00247DD8[];
extern char D_L39_00247DE0[];
extern char D_L39_00247DF8[];
extern char D_L39_00247E08[];
extern char D_L39_00247E20[];
extern char D_L39_00247E38[];
extern char D_L39_00247E78[];
extern u8 D_L39_0047C920[];
__asm__(".extern D_L39_00247914, 16");

typedef struct S_00692420_obj S_00692420_obj;

typedef struct S_00692420_vt {
    char pad0[0x1C];
    void (*f1C)(S_00692420_obj *, s32, s32);
    char pad20[0x6C];
    s32 (*f8C)(S_00692420_obj *);
    char pad90[8];
    char *(*f98)(S_00692420_obj *);
    char pad9C[0x18];
    char padB4[4];
    void (*fB8)(S_00692420_obj *, char *);
    char padBC[8];
    s32 (*fC4)(S_00692420_obj *);
} S_00692420_vt;

struct S_00692420_obj {
    s32 f0;
    s32 f4;
    char pad8[0x58];
    S_00692420_vt *f60;
};

typedef struct S_00692420_self {
    char pad0[0x110];
    S_00692420_obj *f110;
    S_00692420_obj *f114;
    S_00692420_obj *f118;
    S_00692420_obj *f11C;
    S_00692420_obj *f120;
    char pad124[0x16C];
    s32 f290;
    char pad294[0x18];
    u8 f2AC;
    char pad2AD[3];
    s32 f2B0;
    s32 f2B4[16];
    char pad2F4[0x204];
    u8 f4F8;
    char pad4F9[7];
    s32 f500[16];
    char pad540[0x20C];
    s32 f74C[16];
    char pad78C[0xC80];
    u8 f140C[16];
    s32 f141C[16];
    s32 f145C[16];
    char f149C[16][0x20];
} S_00692420_self;

typedef struct S_00692420_glob {
    char pad0[0x48];
    void *f48;
} S_00692420_glob;

typedef struct S_00692420_sda204 {
    char pad0[0x94];
    s32 f94;
} S_00692420_sda204;

typedef struct S_00692420_rec {
    char pad0[0x18];
    s32 f18;
    s32 f1C;
} S_00692420_rec;

extern S_00692420_sda204 *D_001DC204_sda;
extern s32 *D_L39_00247914;

extern s32 func_00120048(char *, char *, ...);
extern s32 func_001205B0(s32, char *);
extern s32 func_L39_006928D0(void);
extern void func_L39_00692918(void *);
extern void func_L39_00692C38(void *);
extern void func_L39_00692F20(void *);
extern s32 func_L39_0068AEF8(void *, s32);
extern S_00692420_rec *func_L39_006D2FA0(void *, s32);
extern s32 func_L39_006CF920(void *, s32, char *);
extern void func_L39_006CFAF0(void *, s32, s32, char *);
extern void *func_L39_006D98C8(void *, s32);
extern s32 func_L39_006872E8(s32 *, char *, u8 *, s32, s32, f32);
extern void func_L39_0069B960(s32, s32, s32, s32, s32);
extern void func_L39_006CFCD0(void *, s32);

s32 func_L39_00692420(S_00692420_self *self, s32 msg)
{
    char buf[64];
    M_006921E0 *h;

    if (func_L39_006928D0() != 0) {
        return 1;
    }
    func_L39_00692918(self);
    func_L39_00692C38(self);
    func_L39_00692F20(self);
    h = D_L39_0024D760->mgr;

    if (h->on != 0 && self->f2B0 < 16) {
        if (self->f11C->f4 < 3) {
            self->f11C->f60->f1C(self->f11C, 3, 0);
        }
        if (func_001205B0(self->f11C->f60->fC4(self->f11C), D_L39_00247DD8) != 0) {
            if (self->f120->f4 < 3) {
                self->f120->f60->f1C(self->f120, 3, 0);
            }
        } else {
            if (self->f120->f4 >= 3) {
                self->f120->f60->f1C(self->f120, 2, 0);
            }
        }
    } else {
        self->f11C->f60->fB8(self->f11C, D_L39_00247DD8);
        if (self->f11C->f4 >= 3) {
            self->f11C->f60->f1C(self->f11C, 2, 0);
        }
        if (self->f120->f4 >= 3) {
            self->f120->f60->f1C(self->f120, 2, 0);
        }
    }

    if (func_L39_0068AEF8(self, msg) == 1) {
        return 1;
    }
    if (msg == 7) {
        s32 st = self->f290;
        if (st == 4) {
            s32 s = self->f11C->f60->fC4(self->f11C);
            if (func_001205B0(s, D_L39_00247DD8) != 0) {
                S_00692420_rec *p = func_L39_006D2FA0(h, s);
                if (p != 0 && p->f18 == 0 && func_L39_006CF920(h, p->f1C, D_L39_00247DE0) != 0) {
                    self->f2AC = 1;
                }
            }
            return 1;
        }
        if (st == 1) {
            s32 i;
            s32 v;
            i = self->f114->f60->f8C(self->f114);
            v = -1;
            if (i >= 0) {
                v = self->f500[i];
            }
            if (v >= 0) {
                func_L39_006CFAF0(h, v, 1, D_L39_00247DF8);
            }
            self->f4F8 = 1;
            return 1;
        }
        if (st == 2) {
            s32 i;
            s32 v;
            i = self->f118->f60->f8C(self->f118);
            v = -1;
            if (i >= 0) {
                v = self->f74C[i];
            }
            if (self->f140C[i] == 1) {
                if (v >= 0) {
                    s32 w = self->f145C[i];
                    if (func_L39_006D98C8(((S_00692420_glob *)D_L39_0024D760)->f48, w) == 0) {
                        func_00120048(buf, D_L39_00247E08, self->f149C[i]);
                        func_L39_006872E8(D_L39_00247914, buf, D_L39_0047C920, 4, 0, 0.6f);
                    } else {
                        func_L39_0069B960(D_001DC204_sda->f94, 3, v, self->f141C[i], w);
                        D_L39_00247914[0x284 / 4] = 12;
                    }
                }
            } else {
                func_00120048(buf, D_L39_00247E20, self->f149C[i]);
                func_L39_006872E8(D_L39_00247914, buf, D_L39_00247E38, 4, 0, 0.6f);
            }
            return 1;
        }
        return 0;
    }
    if (msg == 8) {
        s32 st = self->f290;
        if (st == 0) {
            s32 i;
            s32 v;
            i = self->f110->f60->f8C(self->f110);
            v = -1;
            if (i >= 0) {
                v = self->f2B4[i];
            }
            if (v >= 0) {
                func_L39_006CFCD0(h, v);
                self->f11C->f60->fB8(self->f11C, self->f110->f60->f98(self->f110));
            }
            self->f2AC = 1;
            return 1;
        }
        if (st == 1) {
            s32 i;
            s32 v;
            i = self->f114->f60->f8C(self->f114);
            v = -1;
            if (i >= 0) {
                v = self->f500[i];
            }
            if (v >= 0) {
                func_L39_006CFAF0(h, v, 3, D_L39_00247E78);
            }
            self->f4F8 = st;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00692420 */
