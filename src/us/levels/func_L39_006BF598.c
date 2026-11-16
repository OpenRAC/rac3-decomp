#include "common.h"

/* NTSC-U counterpart of func_L39_006C20B0 (src/levels/39_multiplayer_menu/L39_006C20B0.c) */
/* localdecomp:start func_L39_006BF598 */
typedef struct W_006C20B0 W_006C20B0;
typedef struct {
    char pad0[0x1C];
    void (*f1C)(W_006C20B0 *, s32, s32);
    s32 (*f20)(W_006C20B0 *, s32, s32);
    void (*f24)(W_006C20B0 *, void *);
    void (*f28)(W_006C20B0 *, f32, f32);
    char pad2C[0x24];
    s32 (*f50)(W_006C20B0 *, s32);
} VT_006C20B0;
struct W_006C20B0 {
    char pad0[0x60];
    VT_006C20B0 *vt;
};

typedef struct {
    char name[8][16];
    char pad80[0x40];
    s16 sC0[8];
    s16 sD0[8];
    s16 ids[8];
    s16 sF0[8];
    char pad100[0x10];
    f32 f110[8];
    f32 f130[8];
    char pad150[0x4E];
    u8 b19E;
} G_006C20B0;

typedef struct {
    char pad0[8];
    s32 w8;
    char padC[0x124];
    s32 w130;
    char pad134[4];
    s32 w138;
    s32 w13C;
    char pad140[0x28];
    u8 b168;
} C_006C20B0;

__asm__(".extern D_L39_002417C0, 16");
extern u8 *D_L39_002417C0;
extern C_006C20B0 D_001A5E50_006BF598 __attribute__((section(".data")));
extern u8 D_L39_002496B0[];
extern u8 D_L39_002496A0[];
extern f32 D_L39_002496C8[] __attribute__((section(".sdata")));
extern s32 D_L39_004B1540[];
extern s32 D_001E03B4_sda;

extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_0037DF98(s32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(f32, u32, s32);
extern s32 func_0019CC78(s32);
extern s32 func_L39_006DCA38(f32, f32);
extern void func_L39_00688750(void *, s32, s32);
extern u32 func_L39_00669E80(s32);

typedef struct {
    char pad0[0x110];
    W_006C20B0 *w[0x50];
    char pad250[0x66];
    u8 b2B6;
    char pad2B7[0x11];
    u8 b2C8[2];
    char pad2CA[0x2E];
    s32 w2F8;
} M_006C20B0;

void func_L39_006BF598(void *self) {
    M_006C20B0 *obj = self;
    u8 buf[32];
    s32 i;
    s32 n;
    s32 j;
    s32 k;
    s32 cnt;
    s32 isMe;
    s32 r;
    f32 off;
    f32 y;
    W_006C20B0 *w;

    if (D_L39_002417C0 == 0) {
        return;
    }
    func_00120048(buf, D_L39_002496B0, func_0037DF98(0x1332), D_001A5E50_006BF598.w130, obj->w2F8);
    n = 0;
    cnt = -1;
    w = obj->w[7];
    w->vt->f24(w, buf);
    w = obj->w[0xD];
    w->vt->f1C(w, 0, 0);
    w = obj->w[0xE];
    w->vt->f1C(w, 0, 0);
    for (i = 0; i < 8; i++) {
        isMe = D_001A5E50_006BF598.w8 == ((G_006C20B0 *)D_L39_002417C0)->ids[i];
        cnt += isMe;
        if (((G_006C20B0 *)D_L39_002417C0)->ids[i] == -1) {
            continue;
        }
        obj->w[n + 0xF]->vt->f24(obj->w[n + 0xF], ((G_006C20B0 *)D_L39_002417C0)->name[i]);
        obj->w[n + 0xF]->vt->f20(obj->w[n + 0xF], (D_001A5E50_006BF598.b168 || isMe) ? 3 : 1, 0);
        for (j = 0; j < 8; j++) {
            if (((G_006C20B0 *)D_L39_002417C0)->ids[i] == ((G_006C20B0 *)D_L39_002417C0)->ids[j]) {
                break;
            }
        }
        if (i == j && (((G_006C20B0 *)D_L39_002417C0)->b19E >> ((G_006C20B0 *)D_L39_002417C0)->ids[i]) & 1) {
            obj->w[n + 0x37]->vt->f20(obj->w[n + 0x37], 1, 0);
            if (func_0019CC78(((G_006C20B0 *)D_L39_002417C0)->ids[i])) {
                obj->w[n + 0x37]->vt->f50(obj->w[n + 0x37], 0x706EC8FF);
            } else {
                obj->w[n + 0x37]->vt->f50(obj->w[n + 0x37], 0x386EC8FF);
            }
        } else {
            obj->w[n + 0x37]->vt->f20(obj->w[n + 0x37], 0, 0);
        }
        obj->w[n + 0x47]->vt->f20(obj->w[n + 0x47], 1, 0);
        obj->w[n + 0x3F]->vt->f20(obj->w[n + 0x3F], 1, 0);
        obj->w[n + 0x4F]->vt->f20(obj->w[n + 0x4F], 1, 0);
        obj->w[n + 0x57]->vt->f20(obj->w[n + 0x57], ((G_006C20B0 *)D_L39_002417C0)->sF0[i] >= 6, 0);
        r = func_L39_006DCA38(((G_006C20B0 *)D_L39_002417C0)->f110[i], ((G_006C20B0 *)D_L39_002417C0)->f130[i]);
        if (r & 1) {
            off = (D_L39_002496C8[2] - D_L39_002496C8[1]) * 0.5f;
        } else {
            off = 0.0f;
        }
        obj->w[n + 0x17]->vt->f20(obj->w[n + 0x17], r > 0, 0);
        obj->w[n + 0x1F]->vt->f20(obj->w[n + 0x1F], r >= 2, 0);
        obj->w[n + 0x27]->vt->f20(obj->w[n + 0x27], r >= 3, 0);
        obj->w[n + 0x2F]->vt->f20(obj->w[n + 0x2F], r >= 4, 0);
        y = ((f32)n + 1.0f - 4.0f) * 0.412f / 9.0f + 0.648f;
        obj->w[n + 0x17]->vt->f28(obj->w[n + 0x17], D_L39_002496C8[1] + off, y);
        obj->w[n + 0x1F]->vt->f28(obj->w[n + 0x1F], D_L39_002496C8[2] + off, y);
        obj->w[n + 0x27]->vt->f28(obj->w[n + 0x27], D_L39_002496C8[3] + off, y);
        obj->w[n + 0x2F]->vt->f28(obj->w[n + 0x2F], D_L39_002496C8[4] + off, y);
        if (isMe) {
            obj->w[n + 0xF]->vt->f50(obj->w[n + 0xF], func_003894A0(0.4f, 0x8066CCFF, 0x8000FF00));
            if (obj->b2B6) {
                func_L39_00688750(obj, n + 0xF, 0);
                obj->b2B6 = 0;
            }
            if (obj->b2C8[cnt]) {
                f32 t = func_00388978((f32)(D_001E03B4_sda % 45) / 45.0f * 6.2831855f - 3.1415927f);
                s32 c = func_003894A0(t * 0.5f + 0.5f, 0x706EC8FF, -1);
                obj->w[cnt + 0xD]->vt->f50(obj->w[cnt + 0xD], c);
                obj->w[cnt + 0xD]->vt->f1C(obj->w[cnt + 0xD], 1, 0);
                obj->w[cnt + 0xD]->vt->f28(obj->w[cnt + 0xD], D_L39_002496C8[9], y);
            }
        } else {
            obj->w[n + 0xF]->vt->f50(obj->w[n + 0xF], 0x8066CCFF);
        }
        obj->w[n + 0x47]->vt->f50(obj->w[n + 0x47], func_L39_00669E80(((G_006C20B0 *)D_L39_002417C0)->sD0[i]));
        obj->w[n + 0x3F]->vt->f50(obj->w[n + 0x3F], 0x8066CCFF);
        obj->w[n + 0x4F]->vt->f24(obj->w[n + 0x4F], (void *)func_0037DF98(D_L39_004B1540[((G_006C20B0 *)D_L39_002417C0)->sC0[i]]));
        n++;
    }
    if (n >= 8) {
        return;
    }
    if (D_001A5E50_006BF598.b168 == 1) {
        for (k = 0; k < D_001A5E50_006BF598.w138 && n < 8; k++, n++) {
            obj->w[n + 0xF]->vt->f20(obj->w[n + 0xF], 3, 0);
            obj->w[n + 0xF]->vt->f24(obj->w[n + 0xF], (void *)func_0037DF98(0x1668));
            obj->w[n + 0x37]->vt->f20(obj->w[n + 0x37], 0, 0);
            obj->w[n + 0x47]->vt->f20(obj->w[n + 0x47], 0, 0);
            obj->w[n + 0x3F]->vt->f20(obj->w[n + 0x3F], 0, 0);
            obj->w[n + 0x4F]->vt->f20(obj->w[n + 0x4F], 0, 0);
            obj->w[n + 0x57]->vt->f20(obj->w[n + 0x57], 0, 0);
            obj->w[n + 0x17]->vt->f20(obj->w[n + 0x17], 0, 0);
            obj->w[n + 0x1F]->vt->f20(obj->w[n + 0x1F], 0, 0);
            obj->w[n + 0x27]->vt->f20(obj->w[n + 0x27], 0, 0);
            obj->w[n + 0x2F]->vt->f20(obj->w[n + 0x2F], 0, 0);
        }
        for (k = 0; k < D_001A5E50_006BF598.w13C && n < 8; k++, n++) {
            obj->w[n + 0xF]->vt->f20(obj->w[n + 0xF], 3, 0);
            obj->w[n + 0xF]->vt->f24(obj->w[n + 0xF], (void *)func_0037DF98(0x1667));
            obj->w[n + 0x37]->vt->f20(obj->w[n + 0x37], 0, 0);
            obj->w[n + 0x47]->vt->f20(obj->w[n + 0x47], 0, 0);
            obj->w[n + 0x3F]->vt->f20(obj->w[n + 0x3F], 0, 0);
            obj->w[n + 0x4F]->vt->f20(obj->w[n + 0x4F], 0, 0);
            obj->w[n + 0x57]->vt->f20(obj->w[n + 0x57], 0, 0);
            obj->w[n + 0x17]->vt->f20(obj->w[n + 0x17], 0, 0);
            obj->w[n + 0x1F]->vt->f20(obj->w[n + 0x1F], 0, 0);
            obj->w[n + 0x27]->vt->f20(obj->w[n + 0x27], 0, 0);
            obj->w[n + 0x2F]->vt->f20(obj->w[n + 0x2F], 0, 0);
        }
    }
    for (; n < 8; n++) {
        obj->w[n + 0xF]->vt->f24(obj->w[n + 0xF], D_L39_002496A0);
        obj->w[n + 0xF]->vt->f20(obj->w[n + 0xF], 0, 0);
        obj->w[n + 0x37]->vt->f20(obj->w[n + 0x37], 0, 0);
        obj->w[n + 0x47]->vt->f20(obj->w[n + 0x47], 0, 0);
        obj->w[n + 0x3F]->vt->f20(obj->w[n + 0x3F], 0, 0);
        obj->w[n + 0x4F]->vt->f20(obj->w[n + 0x4F], 0, 0);
        obj->w[n + 0x57]->vt->f20(obj->w[n + 0x57], 0, 0);
        obj->w[n + 0x17]->vt->f20(obj->w[n + 0x17], 0, 0);
        obj->w[n + 0x1F]->vt->f20(obj->w[n + 0x1F], 0, 0);
        obj->w[n + 0x27]->vt->f20(obj->w[n + 0x27], 0, 0);
        obj->w[n + 0x2F]->vt->f20(obj->w[n + 0x2F], 0, 0);
    }
}
/* localdecomp:end func_L39_006BF598 */
