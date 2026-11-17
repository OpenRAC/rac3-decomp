#include "common.h"

/* localdecomp:start func_L39_006C93C8 */
typedef struct W_006C93C8 W_006C93C8;
typedef struct {
    u8 pad0[0x20];
    void (*f20)(W_006C93C8 *, s32, s32);
    u8 pad24[0x30 - 0x24];
    void (*f30)(W_006C93C8 *, f32 *, f32 *);
    u8 pad34[0x80 - 0x34];
    void (*f80)(W_006C93C8 *, s32);
    void (*f84)(W_006C93C8 *, s32);
    void (*f88)(W_006C93C8 *, s32);
    s32 (*f8C)(W_006C93C8 *);
    u8 pad90[0x98 - 0x90];
    s32 (*f98)(W_006C93C8 *);
    s32 (*f9C)(W_006C93C8 *, f32 *, f32 *);
} V_006C93C8;
struct W_006C93C8 {
    u8 pad0[0x60];
    V_006C93C8 *vt;
};
typedef struct {
    u8 pad0[0x110];
    W_006C93C8 *items[0x60];
    s32 sel;
    u8 pad294[0x2B0 - 0x294];
    s32 count0;
    s32 ids0[0x42];
    s32 count1;
    s32 ids1[1];
} S_006C93C8;
typedef struct {
    u8 pad0[0x18];
    s32 id;
} E_006C93C8;

extern void *D_0024D760;
extern s32 D_00247914;
extern u8 D_002498D0[];
extern void func_L39_006C9C48(void *);
extern void func_L39_006C9E50(void *);
extern void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, u32);
extern s32 func_L39_006C9BF0(void *);
extern s32 func_L39_006C99F0(void *, s32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_00688340(s32, s32, s32);
extern u8 *func_00381FF0(s32);
extern void func_120048(u8 *, u8 *, ...);
extern s32 func_L39_006872E8(s32, u8 *, u8 *, s32, s32, f32);
extern s32 func_L39_00687450(s32, u8 *, u8 *, s32, s32, s32, s32);
extern E_006C93C8 *func_L39_006D9C90(s32, u8 *);
extern void func_L39_006CA268(void *, s32);
extern void func_L39_006CA060(void *, s32);
extern void func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

static __inline__ s32 valid_006C93C8(E_006C93C8 *e)
{
    s32 ok = 0;
    if (e) ok = e->id >= 0;
    return ok;
}

s32 func_L39_006C93C8(S_006C93C8 *this, s32 arg)
{
    u8 buf[0x30];
    u8 msg[0xD0];
    f32 x0, y0, x1, y1, x2, y2;
    s32 list = *(s32 *)((u8 *)D_0024D760 + 0x48);
    s32 sel;

    func_L39_006C9C48(this);
    func_L39_006C9E50(this);
    func_L39_0068A4A8(this, 0, this->count0 < 5 ? this->count0 : 4, 0.29100001f, 0.24349999f, 0.049000002f, 0.36200001f, 0x331465B7);
    func_L39_0068A4A8(this, 1, this->count1 < 5 ? this->count1 : 4, 0.29100001f, 0.56950003f, 0.049000002f, 0.36200001f, 0x331465B7);
    if (func_L39_006C9BF0(this) || func_L39_006C99F0(this, arg) || func_L39_0068AEF8(this, arg)) return 1;
    if (arg == 7) {
        func_L39_00688340(4, 0, 0);
        switch (this->sel) {
        case 0: {
            W_006C93C8 *w = this->items[0];
            s32 idx = w->vt->f8C(w);
            s32 id;
            u8 *fmt;
            if (idx < 0) break;
            id = this->ids0[idx];
            if (id < 0) return 1;
            fmt = func_00381FF0(0x1B76);
            w = this->items[0];
            func_120048(buf, fmt, w->vt->f98(w));
            if (func_L39_006872E8(D_00247914, buf, D_002498D0, 3, 0, 0.6f) == 1) {
                func_L39_006CA268(this, id);
            }
            return 1;
        }
        case 1: {
            W_006C93C8 *w = this->items[1];
            s32 idx = w->vt->f8C(w);
            s32 id;
            if (idx < 0) break;
            id = this->ids1[idx];
            if (id < 0) return 1;
            func_L39_006CA060(this, id);
            break;
        }
        case 2:
            if (this->count0 > 0) {
                W_006C93C8 *w;
                w = this->items[0]; w->vt->f80(w, 1);
                w = this->items[0]; w->vt->f20(w, 3, 0);
                w = this->items[0]; w->vt->f84(w, 1);
                w = this->items[0]; w->vt->f88(w, 0);
                func_L39_0068B2F8(this, 0, 0);
            }
            return 1;
        case 3:
            if (this->count1 > 0) {
                W_006C93C8 *w;
                w = this->items[1]; w->vt->f80(w, 1);
                w = this->items[1]; w->vt->f20(w, 3, 0);
                w = this->items[1]; w->vt->f84(w, 1);
                w = this->items[1]; w->vt->f88(w, 0);
                func_L39_0068B2F8(this, 1, 0);
            }
            return 1;
        case 4: {
            u8 *title = D_002498D0;
            buf[0] = 0;
            func_L39_00687450(D_00247914, title, buf, 0, 0x20, 0, 0);
            if (buf[0]) {
                E_006C93C8 *e = func_L39_006D9C90(list, buf);
                s32 id;
                u8 ok;
                if (e) id = e->id;
                ok = valid_006C93C8(e);
                if (ok) {
                    func_L39_006CA060(this, id);
                    break;
                }
                func_120048(msg, func_00381FF0(0x1175), buf);
                func_L39_006872E8(D_00247914, msg, title, 4, 0, 0.6f);
            }
            break;
        }
        default:
            goto draw;
        }
        return 1;
    }
draw:
    sel = this->sel;
    if (sel == 0) {
        W_006C93C8 **items = this->items;
        W_006C93C8 *w = this->items[0];
        s32 idx, flags;
        w->vt->f9C(w, &x0, &y0);
        items += this->sel;
        w = *items;
        idx = w->vt->f8C(w);
        flags = 0;
        if (idx > 0) flags |= 1;
        if (idx < this->count0 - 1) flags |= 2;
        func_L39_00689F00(this, flags, 3, 3, 0.29100001f, y0 + -0.001f, 0.36200001f, 0.032f, 0.04f, 1.0f);
    } else if (sel == 1) {
        W_006C93C8 **items = this->items;
        W_006C93C8 *w = this->items[1];
        s32 idx, flags;
        w->vt->f9C(w, &x1, &y1);
        items += this->sel;
        w = *items;
        idx = w->vt->f8C(w);
        flags = 0;
        if (idx > 0) flags |= 1;
        if (idx < this->count1 - 1) flags |= 2;
        func_L39_00689F00(this, flags, 3, 3, 0.29100001f, y1 + -0.001f, 0.36200001f, 0.032f, 0.04f, 1.0f);
    } else {
        W_006C93C8 *w = this->items[sel];
        w->vt->f30(w, &x2, &y2);
        func_L39_00689F00(this, 0, 3, 3, x2, y2 + (this->sel != 4 ? 0.005f : 0.0f), 0.382f, 0.045f, 0.041f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L39_006C93C8 */
