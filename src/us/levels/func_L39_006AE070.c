#include "common.h"

/* NTSC-U counterpart of func_L39_006B09C0 (src/levels/39_multiplayer_menu/L39_006B09C0.c) */
/* localdecomp:start func_L39_006AE070 */
typedef struct S_006B09C0_Obj S_006B09C0_Obj;
typedef struct S_006B09C0_VT {
    u8 pad0[0x1C];
    void (*f1C)(S_006B09C0_Obj *, s32, s32);
    u8 pad20[0x44 - 0x20];
    void (*f44)(S_006B09C0_Obj *, s32, f32, f32);
    void (*f48)(S_006B09C0_Obj *, s32, s32);
    void (*f4C)(S_006B09C0_Obj *, s32, s32);
    u8 pad50[0xB8 - 0x50];
    void (*fB8)(S_006B09C0_Obj *, s32);
} S_006B09C0_VT;
struct S_006B09C0_Obj {
    u8 pad[0x60];
    S_006B09C0_VT *vt;
};

typedef struct S_006B09C0_This {
    u8 pad0[0x110];
    S_006B09C0_Obj *f110[4];
    S_006B09C0_Obj *f120;
    u8 pad124[0x2A8 - 0x124];
    u8 f2A8;
    u8 pad2A9[3];
    s32 f2AC;
} S_006B09C0_This;

typedef struct { u8 pad0[0x280]; u8 f280; } S_006B09C0_G2;
__asm__(".extern D_L39_00247A74, 16");
extern S_006B09C0_G2 *D_L39_00247A74;
typedef struct {
    u8 pad0[0x120];
    s32 f120;
    s32 pad124;
    s32 f128;
    u8 pad12C[0x2C9 - 0x12C];
    u8 f2C9;
    u8 pad2CA[0x63C - 0x2CA];
    s32 f63C;
} S_006B09C0_G;
extern S_006B09C0_G D_001A5E50;
extern s32 D_L39_003D2980[];
s32 func_L39_0067C5E0(s32);
void func_L39_00687E10(s32);
void func_L39_00687900(void *, s32, s32, f32, f32, f32, f32, s32);
void func_L39_00687358(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
void func_L39_00686FD8(void *);
void func_L39_00687F10(void *);
s32 func_L01_005129D8(s32, f32);
s32 func_0037DF98(s32);
void func_L39_00688750(void *, s32, s32);

void func_L39_006AE070(S_006B09C0_This *this)
{
    s32 i;
    S_006B09C0_G2 *g = D_L39_00247A74;
    u8 old = g->f280;

    g->f280 = 1;
    this->f2AC = 0;
    this->f2A8 = old;
    func_L39_0067C5E0(0x380000);
    func_L39_00687E10(1);
    func_L39_00687900(this, 0, 3, 0.501f, 0.4257500171661377f, 0.07825002074241638f, 0.432f, 0x332299DE);
    func_L39_00687358(this, 0, 3, 3, 1.5f, 1.5f, 0.432f, 0.057f, 0.057f, 0.1f);
    func_L39_00686FD8(this);
    func_L39_00687F10(this);
    func_L01_005129D8(D_L39_003D2980[0], 0.5f);
    func_L01_005129D8(D_L39_003D2980[1], 0.5f);
    func_L01_005129D8(D_L39_003D2980[2], 0.5f);
    func_L01_005129D8(D_L39_003D2980[3], 0.5f);
    for (i = 0; i < 4; i++) {
        this->f110[i]->vt->f4C(this->f110[i], 0x40, 1);
        this->f110[i]->vt->f44(this->f110[i], 1, 0.432f, 0.0f);
    }
    if (D_001A5E50.f2C9 != 0) {
        this->f120->vt->f1C(this->f120, 0, 0);
    } else {
        this->f120->vt->f1C(this->f120, 1, 0);
        this->f120->vt->fB8(this->f120, func_0037DF98(0x1A5F));
        this->f120->vt->f48(this->f120, 3, 3);
    }
    if (D_001A5E50.f2C9 == 0) {
        this->f110[0]->vt->f1C(this->f110[0], 2, 0);
        func_L39_00688750(this, 1, 0);
    } else {
        func_L39_00688750(this, 0, 0);
    }
}
/* localdecomp:end func_L39_006AE070 */
