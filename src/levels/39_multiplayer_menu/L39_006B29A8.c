#include "common.h"

/* localdecomp:start func_L39_006B29A8 */
typedef struct O_006B29A8 O_006B29A8;
typedef struct {
    u8 pad0[0x20];
    s32 (*f20)(O_006B29A8 *, s32, s32);
    u8 pad24[0x6C - 0x24];
    void (*f6C)(O_006B29A8 *, s32, u8 **);
    u8 pad70[0x88 - 0x70];
    void (*f88)(O_006B29A8 *, s32);
    s32 (*f8C)(O_006B29A8 *);
} V_006B29A8;
struct O_006B29A8 {
    u8 pad0[0x60];
    V_006B29A8 *vt;
};
typedef struct {
    s32 f0[0x8C / 4];
} I_006B29A8;
typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
    u8 f20[0x20];
    I_006B29A8 f40;
} P_006B29A8;
typedef struct {
    s32 f0;
    s32 f4;
    P_006B29A8 **f8;
} E_006B29A8;
typedef struct {
    u8 f0;
    s32 f4;
    u8 f8;
    s32 fC;
    s32 f10;
    u8 pad14[0x28 - 0x14];
    E_006B29A8 f28[1];
} A_006B29A8;
typedef struct {
    u8 pad0[0x34];
    A_006B29A8 *f34;
} G_006B29A8;
typedef struct {
    u8 pad0[0x138];
    O_006B29A8 *f138;
    u8 pad13C[0x48C - 0x13C];
    u8 f48C;
    s32 f490;
    s32 f494;
    s32 f498[0x40];
    I_006B29A8 f598[0x40];
} S_006B29A8;

__asm__(".extern D_L39_0024D760_006B29A8, 16");
extern G_006B29A8 *D_L39_0024D760_006B29A8;
extern u8 D_L39_00248EA0[];
extern s32 func_L39_006CD768(A_006B29A8 *);
extern u8 *func_00381FF0(s32);
void func_L39_0068A4A8(void *, s32, s32, f32, f32, f32, f32, s32);

void func_L39_006B29A8(S_006B29A8 *this) {
    u8 *names[0x40];
    A_006B29A8 *a = D_L39_0024D760_006B29A8->f34;
    E_006B29A8 *e = 0;

    if (a->f0 != 0 && a->f4 >= 0) {
        e = &a->f28[a->f4];
    }
    if (this->f48C == 1 && a->f8 == 0) {
        func_L39_006CD768(a);
        this->f490 = a->f10;
        this->f48C = 0;
    }
    if (e != 0 && a->f10 != this->f490) {
        s32 cur;
        s32 sel;
        s32 n;
        s32 i;
        s32 idx;

        this->f490 = a->f10;
        this->f494 = e->f4;
        if (this->f494 > 0x40) {
            this->f494 = 0x40;
        }
        cur = this->f138->vt->f8C(this->f138);
        sel = -1;
        if (cur != -1) {
            sel = this->f498[cur];
        }
        n = 0;
        idx = 0;
        for (i = 0; i < this->f494; i++) {
            P_006B29A8 *p = e->f8[i];
            if (p->f40.f0[0] != 0) {
                names[n] = p->f20;
                this->f498[n] = p->f1C;
                this->f598[n] = p->f40;
                if (sel == p->f1C) {
                    idx = n;
                }
                n++;
            }
        }
        this->f494 = n;
        if (n > 0) {
            this->f138->vt->f6C(this->f138, n, names);
            this->f138->vt->f88(this->f138, idx);
            this->f138->vt->f20(this->f138, 3, 0);
        } else {
            u8 *two[2] = { D_L39_00248EA0, func_00381FF0(0x101A) };
            this->f138->vt->f20(this->f138, 2, 0);
            this->f138->vt->f6C(this->f138, 2, two);
        }
    }
    func_L39_0068A4A8(this, 1, (this->f494 > 5 ? 5 : this->f494) + 1, 0.728f, 0.6093333f, 0.048f, 0.32700002f, 0x332299DE);
}
/* localdecomp:end func_L39_006B29A8 */
